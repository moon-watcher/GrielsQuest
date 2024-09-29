#include "../inc/include.h"




#define _p players[player]

#define IF(x)       if      ( ( ret = object_is_##x ( o ) ) )
#define ELSEIF(x)   else if ( ( ret = object_is_##x ( o ) ) )






PLAYER  players [ PLAYER_MAX_PLAYERS ] = { };

static u16 _prev_x = 0;
static u16 _prev_y = 0;
static u16 _restore_x = 0;
static u16 _restore_y = 0;
static u16 _object = 0;
//static s16 _drifting = 0;
static u8  _player_speed = 0;



////////////////////////////////////////////////////////////////////////////////////////////////////////////




static const u8 array1[16] =
{
	 // 8, 15, 19, 20, 20, 20, 20, 21, 21, 21, 23, 23, 24, 26, 29, 34 // original
	 5, 10, 15, 18, 20, 20, 20, 21, 21, 21, 23, 23, 24, 26, 29, 34 // sugerencia de dani nevado
};

static const Vect2D_s16 desp[4][4] =
{
	{ { -8, -6 }, { -4, -6 }, { -2, -6 }, { -1, -6 } },
	{ {  0, -6 }, { -6, -6 }, { -8, -6 }, { -8, -6 } },
	{ {  0,-14 }, {  0, -5 }, {  0, -6 }, {  0, -6 } },
	{ { -8, -5 }, { -8, -6 }, { -8, -6 }, { -8, -6 } },
};

static const u16 cords[20][14] =
{
	{ 249, 38, 248, 40, 246, 48, 274, 45, 264, 32, 264, 15, 278, 41 },
	{ 259, 32, 246, 39, 244, 48, 253, 43, 259, 34, 258, 14, 252, 18 },
	{ 273, 44, 264, 44, 255, 21, 243, 27, 254, 36, 266, 50, 265, 14 },
	{ 243, 29, 262, 46, 254, 45, 277, 20, 245, 14, 250, 28, 257, 18 },
	{ 247, 31, 275, 47, 245, 47, 266, 35, 275, 37, 251, 46, 276, 19 },
	{ 271, 50, 242, 29, 274, 37, 260, 46, 263, 16, 249, 34, 261, 49 },
	{ 260, 46, 270, 34, 250, 43, 276, 35, 268, 45, 245, 23, 273, 48 },
	{ 274, 23, 275, 34, 254, 45, 271, 39, 244, 41, 271, 42, 249, 19 },
	{ 272, 43, 253, 43, 248, 22, 259, 46, 267, 14, 253, 18, 269, 38 },
	{ 275, 42, 247, 18, 273, 33, 251, 45, 250, 36, 276, 44, 265, 41 },
	{ 260, 33, 249, 18, 271, 47, 259, 32, 249, 30, 263, 16, 261, 17 },
	{ 244, 34, 246, 27, 245, 20, 272, 20, 249, 38, 278, 14, 260, 22 },
	{ 258, 45, 264, 35, 262, 19, 263, 49, 248, 47, 242, 16, 264, 34 },
	{ 243, 18, 268, 16, 249, 45, 273, 48, 265, 31, 274, 17, 276, 39 },
	{ 244, 15, 247, 41, 254, 41, 276, 26, 242, 38, 253, 39, 275, 42 },
	{ 276, 33, 256, 33, 274, 16, 253, 47, 268, 14, 278, 27, 263, 36 },
	{ 252, 47, 243, 35, 262, 49, 248, 17, 264, 33, 264, 48, 272, 15 },
	{ 258, 24, 242, 32, 250, 45, 262, 27, 245, 46, 251, 36, 264, 16 },
	{ 260, 39, 274, 37, 245, 35, 260, 26, 256, 41, 263, 27, 251, 20 },
	{ 267, 29, 242, 25, 276, 41, 260, 18, 275, 15, 245, 17, 266, 34 }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////



bool _can_move ( u8 player )
{
	return (  ( _p.vel_x  ||  _p.vel_y )  &&  ( ! object_is_arrow(_object) )  );
}


bool _does_it_kills ( u16 ret, u8 selected )
{
   return
   (
		( selected == STAFF  &&  object_is_killed_by_staff ( ret ) ) ||
		( selected == CROSS  &&  object_is_killed_by_cross ( ret ) ) ||
		( selected == SWORD  &&  object_is_killed_by_sword ( ret ) )
		// || ( selected == GRIAL  &&  object_is_killed_by_grial ( ret ) )
   );
}


static void _death_animation ( )
{
	u16 player = 0;
	u16 muerte = GRIEL_DEAD;

	s16 x = vdpSpriteCache[splist_griel].x;
	s16 y = vdpSpriteCache[splist_griel].y;

	LEVEL *wl = game_get_wl ( );


	if      ( _object == FIRE     ) muerte = GRIEL_DEAD_FIRE;
	else if ( _object == HOLE21   ) muerte = GRIEL_DEAD_WATER;
	else if ( _object == HOLEPY   ) muerte = GRIEL_DEAD_HOLE;
	else if ( _object == TENTACLE ) muerte = GRIEL_DEAD_TENT_1;
	else if ( _object == PENTACLE ) muerte = GRIEL_DEAD_PENTACLE;

	vobject_animation ( _p.object, muerte );
	toani_delete_explosion();

	if ( muerte == GRIEL_DEAD_TENT_1 )
	{
		vobject_reset ( GRIEL_DEAD_TENT_2 );
		level_draw_animation ( EMPTY, player_get_x(0), player_get_y(0) );
		vsprite_set (splist_weapon, x-128, y-128, GRIEL_DEAD_TENT_2);
	}
	else if ( muerte == GRIEL_DEAD_HOLE   )
	{
		vobject_reset ( HOLEPY );
		vsprite_set (splist_weapon, x, y, GRIEL_DEAD_HOLE);
	}
	else
	{
		splist_hide_sprite ( splist_weapon );
	}



	u16 duracion = animation_duracion ( muerte );

	while ( duracion-- )
	{
		death_frame ( wl );
		toani_update ( );
		chorrada_control ( wl );
		undo_control ( wl );
		level_update ( );

		vobject_update();
		vobject_upload ( );

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}


	// restore tentacle
	if ( muerte == GRIEL_DEAD_TENT_1 )
	{
		level_draw_animation ( TENTACLE, player_get_x(0), player_get_y(0) );
	}
}



static u8 _parado ( u8 player )
{
	return ( _prev_x == _p.x && _prev_y == _p.y );
}



static void _stopPlayerIfNecessary ( u8 player )
{
	if (  ! _p.vel_x  &&  ! _p.vel_y  )
	{
		return;
	}

	const s16 x = player_get_x(player);
	const s16 y = player_get_y(player);

	if
	(
		( x == 0                && _p.vel_x < 0 ) ||
		( y == 0                && _p.vel_y < 0 ) ||
		( x == LEVEL_WIDTH  - 1 && _p.vel_x > 0 ) ||
		( y == LEVEL_HEIGHT - 1 && _p.vel_y > 0 )
	)
	{
		player_stop ( player );
	}
}

static void _change_explosion_link ( s16 x, s16 y )
{
	BIGBOY *b = bigboy_getByPos ( x, y );

	if ( b )
	{
		VDPSprite *bb_parent = splist_get_parent ( b->index );

		int aux = vdpSpriteCache[splist_explosion].link;

		vdpSpriteCache[splist_explosion].link = b->index;
		bb_parent->link                       = vdpSpriteCache[(u8)b->index].link;
		vdpSpriteCache[(u8)b->index].link     = aux;
	}
}


static void _do_slash ( u8 player, LEVEL *level, s8 inc_x, s8 inc_y, s16 x, s16 y  )
{
	u8 anim = 0;
	u8 slash = 0;
	u8 aux = 0;
	u8 i = 0;
	u8 j = 0;

	if ( inc_x == -1 ) { anim = GRIEL_HACK_LEFT;  slash = SLASH_LEFT;  aux = 0; }
	if ( inc_x == +1 ) { anim = GRIEL_HACK_RIGHT; slash = SLASH_RIGHT; aux = 1; }
	if ( inc_y == -1 ) { anim = GRIEL_HACK_UP;    slash = SLASH_UP;    aux = 2; }
	if ( inc_y == +1 ) { anim = GRIEL_HACK_DOWN;  slash = SLASH_DOWN;  aux = 3; _change_explosion_link ( x, y ); }

	wavelist_play(WAVE_GRIEL_IA);

	vobject_swap ( _p.object, anim );
	vsprite_set ( splist_flash, _p.x + desp[0][0].x, _p.y + desp[0][0].y, slash );

	_p.object = anim;

	player_stop ( player );
	splist_hide_sprite ( splist_weapon );
	splist_hide_sprite ( splist_flash );

	DEATH *d = death_add ( level_get_object ( level, x, y ), x, y );
	level_set_object ( level, x, y, d->objeto );

	for ( i = 0; i < 60; i ++ )
	{
		for ( j = 0; j < 16; j ++ )
		{
			if ( array1[j]> 0 && array1[j] == i )
			{
				_p.x += inc_x;
				_p.y += inc_y;
			}
		}

		if ( i == 10 )
		{
			psglist_play ( PSG_KILL );
			toani_set_dead ( x, y );
		}


		player_update(player);

		Vect2D_s16 pos = desp [ aux ] [ vobject_get(slash)->frame ];

		VDP_setSpritePosition ( splist_flash,  _p.x + pos.x,   _p.y + pos.y + 8 );

		death_frame ( level );
		toani_update();

		vobject_update();
		vobject_upload ( );

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}


	vobject_swap ( slash, SLASH_UP );
//	video_reset_cnts ( SLASH_UP );
//	vobject_delete ( slash ) ;
//	vobject_add ( SLASH_UP );


	vobject_delete ( slash ) ;
	vobject_delete ( SLASH_UP ) ;


	splist_hide_sprite ( splist_flash );
	vobject_swap ( anim, GRIEL_STANDS );
//	vobject_delete ( anim ) ;
//	vobject_add ( GRIEL_STANDS );

	_p.object = GRIEL_STANDS;
//	player_update_selected ( player, EMPTY );
	player_update(player);
	player_stop(player);

	vobject_update();
	vobject_upload ( );

	VDP_updateSprites(80,1);
	SYS_doVBlankProcess();
}


void _set_player_x ( u8 object, s8 distance_x, s8 vel_x )
{
	u8 player = 0; // lo necesita la macro, no borrar

	_p.object     = object;
	_p.distance_x = distance_x;
	_p.vel_x      = vel_x;

	toani_draw_dust (  );
}


void _set_player_y ( u8 object, s8 distance_y, s8 vel_y )
{
	u8 player = 0; // lo necesita la macro, no borrar

	_p.object     = object;
	_p.distance_y = distance_y;
	_p.vel_y      = vel_y;

	toani_draw_dust ( );
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////



PLAYER *player ( u8 player )
{
	return (PLAYER*) &players [ player ];
}


void player_init ( u8 player )
{
	u8 px         = level_get()->player_x;
	u8 py         = level_get()->player_y;

	px            = level_flipped_h ( ) ? 15 - px : px;
	py            = level_flipped_v ( ) ? 10 - py : py;


	_p.x          = level_hpos_to_pixel ( px );
	_p.y          = level_vpos_to_pixel ( py );

	_p.key        = 0;
	_p.selected   = 0;
	_p.object     = GRIEL_STANDS;

	_p.distance_x = 0;
	_p.distance_y = 0;

	_p.vel_x      = 0;
	_p.vel_y      = 0;

	_p.on_arrow   = false;
	_p.on_door    = false;

	_player_speed = PLAYER_VEL_NORMAL;

	_prev_x       = _p.x;
	_prev_y       = _p.y;
}




void player_set ( u8 nb, PLAYER ply )
{
	players [ nb ] = (PLAYER) ply;
}



void player_update ( u8 player )
{
	//vsprite_set ( splist_griel, -40, -40, EMPTY_SPRITE );
	vsprite_set ( splist_griel, _p.x, _p.y, _p.object );

	weapon_draw ( );
}



void player_move ( u8 player )
{
	if ( _p.distance_x ) { _p.distance_x -= _p.vel_x; _p.x += _p.vel_x; }
	if ( _p.distance_y ) { _p.distance_y -= _p.vel_y; _p.y += _p.vel_y; }
}



void player_stop ( u8 player )
{
	if ( DEV && joy1_active_mode )
	{
		return;
	}

	_p.vel_x      = 0;
	_p.vel_y      = 0;
	_p.distance_x = 0;
	_p.distance_y = 0;
}


// permite cambiar la direcci�n de Griel en mitad de dos casillas
bool player_changed_dir ( u8 player )
{
	u8 aux = _p.object;

	if      (  ! _p.on_arrow  &&  _p.vel_y == 0  &&  _p.vel_x > 0  &&  joy1_pressed_left  ) _set_player_x ( GRIEL_LEFT,  _p.distance_x - DISTANCE_TO_MOVE, -_p.vel_x );
	else if (  ! _p.on_arrow  &&  _p.vel_y == 0  &&  _p.vel_x < 0  &&  joy1_pressed_right ) _set_player_x ( GRIEL_RIGHT, _p.distance_x + DISTANCE_TO_MOVE, -_p.vel_x );
	else if (  ! _p.on_arrow  &&  _p.vel_x == 0  &&  _p.vel_y < 0  &&  joy1_pressed_down  ) _set_player_y ( GRIEL_DOWN,  _p.distance_y + DISTANCE_TO_MOVE, -_p.vel_y );
	else if (  ! _p.on_arrow  &&  _p.vel_x == 0  &&  _p.vel_y > 0  &&  joy1_pressed_up    ) _set_player_y ( GRIEL_UP,    _p.distance_y - DISTANCE_TO_MOVE, -_p.vel_y );

	if ( aux != _p.object )
	{
		vobject_swap ( aux, _p.object ) ;
		weapon_reset();

		return true;
	}

	return false;
}



u16 player_is_stopped ( u8 player )
{
	if ( !_p.distance_x ) _p.vel_x = 0;
	if ( !_p.distance_y ) _p.vel_y = 0;

	return !_p.distance_x  &&  !_p.distance_y;
}



bool player_is_moving ( u8 player )
{
	if ( !_p.distance_x ) _p.vel_x = 0;
	if ( !_p.distance_y ) _p.vel_y = 0;

	return _p.distance_x || _p.distance_y;
}



void player_action ( u8 player )
{
	if ( player_is_moving ( player ) )
	{
		return;
	}

	u16 aux = _p.object ;

	_p.object = GRIEL_STANDS;

	     if ( joy1_active_left  ) _set_player_x ( GRIEL_LEFT,  -DISTANCE_TO_MOVE, -_player_speed );
	else if ( joy1_active_right ) _set_player_x ( GRIEL_RIGHT, +DISTANCE_TO_MOVE, +_player_speed );
	else if ( joy1_active_down  ) _set_player_y ( GRIEL_DOWN,  +DISTANCE_TO_MOVE, +_player_speed );
	else if ( joy1_active_up    ) _set_player_y ( GRIEL_UP,    -DISTANCE_TO_MOVE, -_player_speed );

	_stopPlayerIfNecessary ( player );

	if ( aux != _p.object )
	{
		vobject_swap ( aux, _p.object ) ;
		weapon_reset();
	}
}




void player_logic_next ( u8 player, LEVEL *level )
{
	u16 ret   = 0;
	s16 inc_x = 0;
	s16 inc_y = 0;

	if ( _p.distance_x < 0 ) inc_x = -1;
	if ( _p.distance_x > 0 ) inc_x = +1;
	if ( _p.distance_y < 0 ) inc_y = -1;
	if ( _p.distance_y > 0 ) inc_y = +1;

	const s16 x = player_get_x(player) + inc_x;
	const s16 y = player_get_y(player) + inc_y;

	u8  o = level_get_object ( level, x, y ) ;

   if
	(
		( x < 0             ) ||
		( y < 0             ) ||
		( x >= LEVEL_WIDTH  ) ||
		( y >= LEVEL_HEIGHT )
	)
	{
		player_stop ( player );
	}


	IF ( enemy )
	{
		if ( _does_it_kills ( ret, _p.selected ) )
		{
			undo_save ( player, o, x, y );
			_do_slash ( player, level, inc_x, inc_y, x, y  );

			//player_update_score    ( player, o2->score );
			player_update_selected ( player, EMPTY );
		}
		else
		{
			player_stop ( player );
		}

		//scoreball_delete ( SCOREBALL_WEAPON );
	}
	ELSEIF ( weapon )
	{
		if ( !_p.selected )
		{
			undo_save ( player, o, x, y );

			psglist_play ( PSG_ITEM );

			level_draw_animation ( EMPTY, x, y );
			level_remove_object ( level, x, y );

			toani_set_explosion ( x, y );

			//player_update_score    ( player, o2->score );
			player_update_selected ( player, ret );
		}
		else
		{
			player_stop ( player );
		}
	}
	ELSEIF ( block )
	{
		player_stop ( player );
	}
	ELSEIF ( arrow )
	{
		if      ( object_is_left  ( ret ) && _p.distance_x > 0 ) player_stop ( player );
		else if ( object_is_right ( ret ) && _p.distance_x < 0 ) player_stop ( player );
		else if ( object_is_up    ( ret ) && _p.distance_y > 0 ) player_stop ( player );
		else if ( object_is_down  ( ret ) && _p.distance_y < 0 ) player_stop ( player );
	}
	ELSEIF ( key )
	{
		_p.key = ret;

		psglist_play ( PSG_KEY );

		toani_set_explosion ( x, y );

		Vect2D_u16 door = level_get_door();
		vsprite_animation ( bigboy_getByPos ( door.x, door.y )->index, DOOR_O );

		level_draw_animation ( EMPTY, x, y );
		level_remove_object ( level, x, y );
		level_actualizar_marcador ( );
		vsprite_set ( splist_key, level_hpos_to_pixel(x), level_hpos_to_pixel(y), EMPTY_SPRITE );
	}
	ELSEIF ( undo )
	{
      psglist_play ( PSG_ITEM );

		level_draw_animation ( EMPTY, x, y );
		level_remove_object ( level, x, y );
		toani_set_explosion ( x, y );

		undo_rest(+1);
		level_actualizar_marcador ( );
		undo_reset_duration ( );

		//player_update_score ( player, o2->score );
	}
	ELSEIF ( door )
	{
		if ( ! _p.key  && !object_is_opendoor(o) )
		{
			player_stop ( player );
		}
	}
	ELSEIF ( hurts )
	{
		_restore_x = _p.x;
		_restore_y = _p.y;
	}

	_prev_x = _p.x;
	_prev_y = _p.y;
}



void player_on_arrow ( u8 player )
{
	_p.on_arrow   = false;

	if ( ! _parado ( PLAYER_1 ) ) // si est� en Arrow y No parado hacer sonar PSG_ARROW
	{
		psglist_play ( PSG_FLECHAS );
	}

	u8 aux = _p.object;

	if ( object_is_arrow(_object) )
	{
		if      ( object_is_left ( _object ) ) _set_player_x ( GRIEL_LEFT,  -DISTANCE_TO_MOVE, -PLAYER_VEL_FAST );
		else if ( object_is_right( _object ) ) _set_player_x ( GRIEL_RIGHT, +DISTANCE_TO_MOVE, +PLAYER_VEL_FAST );
		else if ( object_is_down ( _object ) ) _set_player_y ( GRIEL_DOWN,  +DISTANCE_TO_MOVE, +PLAYER_VEL_FAST );
		else if ( object_is_up   ( _object ) ) _set_player_y ( GRIEL_UP,    -DISTANCE_TO_MOVE, -PLAYER_VEL_FAST );

		_p.on_arrow = true;
	}

	//fx_play(FX_SPEED_UP);
	vobject_swap ( aux, _p.object );


//   vobject_delete ( _p.object ) ;
//   vobject_add ( obj );

	//_p.object = obj;
}



void player_on_hurts ( u8 player )
{
	if ( undo_rest ( -1 ) == -1 )
	{
		music_stop();
		return;
	}

	//psglist_play ( PSG_BITE );

	wavelist_play(WAVE_GRIEL_OUCH_1);
   _death_animation ( );

	splist_hide_sprite ( splist_weapon );
	VDP_updateSprites (80,1);

	//waitMs(1000);

	undo_can_undo ( false );
	undo_explode();

	_p.x = _restore_x; // aqu� o fuera del if?
	_p.y = _restore_y; // est� por ver
}



//void player_on_grial ( u8 player, LEVEL *level )
//{
//	//music_play ( level->music_completed );
//
////	bigtext_init ( (genresSprites*) &cs_font_16x16, 1200, PAL0 );
//	//bigtext_drawSprite_XYcentered ( "STAGE CLEAR", 80 );
//	planHide();
//}



void player_update_selected ( u8 player, u16 selected )
{
	_p.selected = selected;

	if ( selected == EMPTY )
	{
		VDP_setSpritePosition ( splist_ui_weapon, 0, -64 );
		VDP_setSpritePosition ( splist_ui_enemy,  0, -64 );

		return;
	}


	u8 enemy = EMPTY;

	if ( gamestate.current_ambiente == 0 )
	{
		     if ( selected == STAFF ) enemy = WILDBOAR;
		else if ( selected == CROSS ) enemy = TOADSTOOL;
		else if ( selected == SWORD ) enemy = DARKELF;
	}
	else if ( gamestate.current_ambiente == 1 )
	{
		     if ( selected == STAFF ) enemy = WALRUS;
		else if ( selected == CROSS ) enemy = ESKIMO;
		else if ( selected == SWORD ) enemy = WAMPA;
	}
	else if ( gamestate.current_ambiente == 2 )
	{
		     if ( selected == STAFF ) enemy = SCORPIO;
		else if ( selected == CROSS ) enemy = BEDOUIN;
		else if ( selected == SWORD ) enemy = MUMMY;
	}
	else if ( gamestate.current_ambiente == 3 )
	{
		     if ( selected == STAFF ) enemy = CANGREJO;
		else if ( selected == CROSS ) enemy = PIRATA;
		else if ( selected == SWORD ) enemy = PLESI;
	}
	else if ( gamestate.current_ambiente == 4 )
	{
		     if ( selected == STAFF ) enemy = OGRE;
		else if ( selected == CROSS ) enemy = EYE;
		else if ( selected == SWORD ) enemy = DEMON;
	}

	if ( enemy == EMPTY )
	{
		return;
	}

	vsprite_set ( splist_ui_weapon, 30,                               13, selected  );
	vsprite_set ( splist_ui_enemy,  54, object_is_bigboy(enemy) ? 6 : 13, enemy     );
	vsprite_set ( splist_ui_left_1, 16,  0, UI_LEFT_1 );
	vsprite_set ( splist_ui_left_2, 16, 24, UI_LEFT_2 );

	VDP_setSpritePriorityGQ ( splist_ui_weapon, 1 );
	VDP_setSpritePriorityGQ ( splist_ui_enemy,  1 );
	VDP_setSpritePriorityGQ ( splist_ui_left_1, 1 );
	VDP_setSpritePriorityGQ ( splist_ui_left_2, 1 );
}



//u8 player_get_selected ( )
//{
//	u8 player = 0;
//   return _p.selected;
//}



void player_dead ( u8 player, LEVEL *level, u16 exit )
{
	if ( exit == LEVEL_HURT )
	{
		musiclist_play ( MUSIC_GAME_OVER );
	}
	else if ( exit == LEVEL_RESTART )
	{
		_death_animation();
		musiclist_play ( MUSIC_GAME_OVER );
	}

	//planHide();
}



void player_inc_level ( )
{
	music_stop();

	//psglist_play( SUBIR_ESCALERAS );

	game_level_inc ( );

	toani_init ( );

	vsprite_animation ( splist_flash,     EMPTY_SPRITE );
	vsprite_animation ( splist_element,   EMPTY_SPRITE );
	vsprite_animation ( splist_explosion, EMPTY_SPRITE );

	if ( gamestate_on_medallon() )
	{
		return;
	}

	splist_hide_sprite ( splist_weapon );
	splist_hide_sprite ( splist_griel );

	vobject_animation ( DOOR,   DOOR_EXIT );
	vobject_animation ( DOOR_O, DOOR_EXIT );
	vobject_reset ( DOOR_EXIT );

	u16 duracion = animation_duracion ( DOOR_EXIT );

	while ( duracion-- )
	{
		vobject_update();
		vobject_upload ( );

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}
}



u8 player_get_object ( u8 player, LEVEL *level )
{
	_object = level_get_object ( level, player_get_x(player), player_get_y(player) ) ;

	return _object;
}



void player_set_key ( u8 player, bool has_key )
{
	_p.key = has_key;
}



void player_speed ( u8 speed )
{
   _player_speed = speed;
}



void player_control_buttons ( LEVEL *wl )
{
	if ( joy1_pressed_a  &&  !gamestate_on_medallon() )
	{
		psglist_play ( PSG_START );
		htp_show ( wl );
	}

	if ( joy1_pressed_c )
	{
		undo_last_move ( wl );
	}

	u16 speed = PLAYER_VEL_NORMAL;

	if ( joy1_active_b )
	{
		speed = PLAYER_VEL_FAST;
	}

	player_speed ( speed );
	toani_inc_dust ( speed );
	vobject_speed ( DUST, speed );
	vobject_speed ( players[0].object, speed );
	vobject_speed ( weapon_get_object(), speed );
}



void player_ctrldev ( u16 *ret )
{
	if ( DEV == 0 )
	{
		return;
	}


	if ( joy1_pressed_x )
	{
	   //
	}

	else if ( joy1_pressed_y )
	{
		*ret = LEVEL_COMPLETED;
	}

	else if ( joy1_pressed_z )
	{
		//u8 reg = VDP_getReg(12);
		//
		//if ( reg == 129 ) VDP_setReg ( 12, 131 );
		//if ( reg == 131 ) VDP_setReg ( 12, 135 );
		//if ( reg == 135 ) VDP_setReg ( 12, 129 );
		//
		//waitMs(1000);
	}

	else if ( joy1_pressed_mode )
	{
	}
}




void player_interact_with_object ( LEVEL *wl )
{
	u8  obj = player_get_object ( PLAYER_1, wl );

	if ( object_is_door ( obj ) )
	{
		players [ PLAYER_1 ].on_door = true;
	}

	else if ( object_is_hurts ( obj )  )
	{
		JoyReader_reset ( );
		player_on_hurts ( PLAYER_1 );
		level_actualizar_marcador ( );
	}

	else if ( object_is_key ( obj ) )
	{
		//
	}

	else if ( object_is_arrow ( obj ) )
	{
		player_on_arrow ( PLAYER_1 );
	}
}













//
//void player_on_key ( u8 player, LEVEL *level )
//{
//	u8 ret = 0;
//
////	u8 x = ( _p.x - OFFSET_HORIZONTAL ) / 16;
////	u8 y = ( _p.y - OFFSET_VERTICAL   ) / 16;
////	u8 o = level_get_object ( level, x, y ) ;
//	u8 o = _object;
//
//	IF ( key )
//	{
//	}
//}
//
//u16 player_on_door ( u8 player, LEVEL *level )
//{
//	u8 ret = 0;
//
////	u8 x = ( _p.x - OFFSET_HORIZONTAL ) / 16;
////	u8 y = ( _p.y - OFFSET_VERTICAL   ) / 16;
////	u8 o = level_get_object ( level, x, y ) ;
//	u8 o = _object;
//
//	return object_is_door(_object);
//	IF ( door )
//	{
//		return ret;
//	}
//
//	return 0;
//}
//
//
//u16 player_on_grial ( u8 player, LEVEL *level )
//{
//	u8 ret = 0;
//
////	u8 x = ( _p.x - OFFSET_HORIZONTAL ) / 16;
////	u8 y = ( _p.y - OFFSET_VERTICAL   ) / 16;
////	u8 o = level_get_object ( level, x, y ) ;
//	u8 o = _object;
//
//	IF ( grial )
//	{
//		return ret;
//	}
//
//	return 0;
//}




//void player_set_score ( u8 player, u16 score )
//{
//	_p.score=score;
//}
//
//
//void player_update_score ( u8 player, u16 inc )
//{
//   return;
//
//	drawUInt ( _p.score+=inc, 7, 2, 5 );
//}
//
//
//void player_update_rest ( u8 player )
//{
//	u8 i;
//
//	if ( _p.rest > 4 )
//	{
//		for ( i = 0; i < 2; i++ )
//		{
//			level_draw_animation_rp ( GRIEL_REST, i*2+20, 1 );
//		}
//		level_draw_animation_rp ( EMPTY, 16+i*2, 29 );
//
//		drawUInt ( _p.rest, 24, 2, 2 );
//	}
//	else
//	{
//		for ( i = 0; i < 3;           i++ ) level_draw_animation_rp ( EMPTY,      i*2+20, 1 );
//		for ( i = 0; i < _p.rest - 1; i++ ) level_draw_animation_rp ( GRIEL_REST, i*2+20, 1 );
//	}
//}
//
//
//void player_inc_rest ( u8 player, s8 nb )
//{
//	_p.rest += nb;
//}
//
//
//
//
//static void _explode_demon ( LEVEL *level )
//{
//	//{ "Enemy Dead",       GRS(cs_sprites_16x16),    PAL1, 0,   0,  5, { { 60, WA_0 }, { 61, WA_0 }, { 62, WA_0 }, { 63, WA_0 }, { 64, WA_0 } } }, //29
//
//	VDP_loadTileData ( cs_sprites_16x16.sprites [ 60 ], POS_SP_EXPLOSION(0), SIZE_SP_DEMON, 0 );
//	VDP_loadTileData ( cs_sprites_16x16.sprites [ 61 ], POS_SP_EXPLOSION(1), SIZE_SP_DEMON, 0 );
//	VDP_loadTileData ( cs_sprites_16x16.sprites [ 62 ], POS_SP_EXPLOSION(2), SIZE_SP_DEMON, 0 );
//	VDP_loadTileData ( cs_sprites_16x16.sprites [ 63 ], POS_SP_EXPLOSION(3), SIZE_SP_DEMON, 0 );
//	VDP_loadTileData ( cs_sprites_16x16.sprites [ 64 ], POS_SP_EXPLOSION(4), SIZE_SP_DEMON, 0 );
//
//	u16 i, k;
//
//	splist_hide_sprite ( splist_element );
//
//	for ( i=0; i<20; i++ )
//	{
//		psglist_play ( PSG_KILL );
//
//		if ( i == 13 )
//		{
//			toani_demon_hide ( 1 );
//		}
//
//		for ( k=0; k<5; k++ )
//		{
//			VDP_setSprite ( 0, cords[i][0],  cords[i][1],  SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 1 );
//			VDP_setSprite ( 1, cords[i][2],  cords[i][3],  SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 2 );
//			VDP_setSprite ( 2, cords[i][4],  cords[i][5],  SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 3 );
//			VDP_setSprite ( 3, cords[i][6],  cords[i][7],  SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 4 );
//			VDP_setSprite ( 4, cords[i][8],  cords[i][9],  SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 5 );
//			VDP_setSprite ( 5, cords[i][10], cords[i][11], SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 6 );
//			VDP_setSprite ( 6, cords[i][12], cords[i][13], SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL3, 1, 0, 0, POS_SP_EXPLOSION(k) ), 7 );
//
//			VDP_updateSprites();
//			SYS_doVBlankProcess();
//			waitMs(20);
//		}
//	}
//
//	for ( k=0; k<=6; k++ )
//	{
//		splist_hide_sprite(k);
//	}
//
//	VDP_updateSprites();
//}






// struct stack {
// 	struct stack_type * my_type;
// 	// put the stuff that you put after private: here
//};
//
//struct stack_type {
//	void (* construct)(struct stack * this);
//	// this takes uninitialized memory
//	struct stack * (* operator_new)();
//	// this allocates a new struct, passes it to construct, and then returns it
//	void (*push)(struct stack * this, thing * t);
//	// pushing t onto this stack
//	thing * (*pop)(struct stack * this);
//	// pops the top thing off the stack and returns it
//	int this_is_here_as_an_example_only;
//}Stack = {
//	 .construct = stack_construct,
//	 .operator_new = stack_operator_new,
//	 .push = stack_push,
//	 .pop = stack_pop
// }; // all of these functions are assumed to be defined somewhere else
//
//y hacer:
//
// struct stack * st = Stack.operator_new();
// // make a new stack
// if (!st) {
// 	// do something about it
// 	 }
// 	 else
// 	 {
// 	 	// you can use the stack
// 	 	stack_push(st, thing0);
// 	 	// This is a non-virtual call
// 	 	Stack.push(st, thing1);
// 	 	// This is like casting *st to a Stack (which it already is) and doing the push st->my_type.push(st, thing2); // This is a virtual call }
//
//
//
//
//
//
//struct Animal_Vtable{
//	typedef void (*Walk_Fun)(struct Animal *a_This);
//	typedef struct Animal * (*Dtor_Fun)(struct Animal *a_This);
//	Walk_Fun Walk;
//	Dtor_Fun Dtor;
//};
//
//struct Animal{
//	Animal_Vtable vtable;
//	char *Name;
//};
//
//struct Dog{
//	Animal_Vtable vtable;
//	char *Name; // mirror member variables for easy access
//	char *Type;
//};
//
//void Animal_Walk(struct Animal *a_This){
//	printf("Animal (%s) walking\n", a_This->Name);
//}
//
//struct Animal* Animal_Dtor(struct Animal *a_This){
//	printf("animal::dtor\n");
//	return a_This;
//}
//
//Animal *Animal_Alloc(){
//	return (Animal*)malloc(sizeof(Animal));
//}
//
//Animal *Animal_New(Animal *a_Animal){
//	a_Animal->vtable.Walk = Animal_Walk;
//	a_Animal->vtable.Dtor = Animal_Dtor;
//	a_Animal->Name = "Anonymous";
//	return a_Animal;
//}
//
//void Animal_Free(Animal *a_This){
//	a_This->vtable.Dtor(a_This); f
//	ree(a_This);
//}
//
//void Dog_Walk(struct Dog *a_This){
//	printf("Dog walking %s (%s)\n", a_This->Type, a_This->Name);
//}
//
//Dog* Dog_Dtor(struct Dog *a_This){
//	// explicit call to parent destructor
//	Animal_Dtor((Animal*)a_This);
//	printf("dog::dtor\n");
//	return a_This;
//}
//
//Dog *Dog_Alloc(){
//	return (Dog*)malloc(sizeof(Dog));
//}
//
//Dog *Dog_New(Dog *a_Dog){
//	// explict call to parent constructor A
//	Animal_New((Animal*)a_Dog);
//	a_Dog->Type = "Dog type";
//	a_Dog->vtable.Walk = (Animal_Vtable::Walk_Fun) Dog_Walk;
//	a_Dog->vtable.Dtor = (Animal_Vtable::Dtor_Fun) Dog_Dtor;
//	return a_Dog;
//}
//
//int main(int argc, char **argv){
//	/* base class: Animal *a_Animal = Animal_New(Animal_Alloc()); */
//	Animal *a_Animal = (Animal*)Dog_New(Dog_Alloc());
//	a_Animal->vtable.Walk(a_Animal);
//	Animal_Free(a_Animal);
//}
//
//
//
//
//
//
//
//#include<stdio.h> struct foobarbaz{ int one; int two; int three; int (*exampleMethod)(int, int); }; int addTwoNumbers(int a, int b){ return a+b; } int main() { //define the function pointer int (*pointerToFunction)(int, int) = addTwoNumbers; //lets make sure we can call the pointer int test = (*pointerToFunction)(12,12); printf ("test: %u \n", test); //now, define an instance of our struct //and add some default values struct foobarbaz fbb; fbb.one = 1; fbb.two = 2; fbb.three = 3; //now add a "method" fbb.exampleMethod = addTwoNumbers; //try calling the method int test2 = fbb.exampleMethod(13,36); printf ("test2: %u \n", test2); printf("\nDone\n"); return 0; }
//
