#include "../inc/include.h"


static s8     _rest = 0;
static bool   _can_undo = false;

static PLAYER _player = { };

static u16    _object = 0;
static u16    _object_x = 0;
static u16    _object_y = 0;

static u16    _key_x = 0;
static u16    _key_y = 0;

static u16    _door = 0;

static u16    _duration = 0;
static u16    _x = 0;
static u16    _y = 0;
static bool   _is_bigboy = false;







void undo_init ()
{
	_rest     = MAX_UNDO;
	_can_undo = FALSE;

	_player   = (PLAYER) {};
	_object   = 0;
	_object_x = 0;
	_object_y = 0;

	_door     = DOOR;

	_duration = 0;
	_x        = 0;
	_y        = 0;

	_is_bigboy = false;
}



void undo_last_move ( LEVEL *level )
{
	if ( ! _rest || !_can_undo  )
	{
		//psglist_play ( PSG_UNDO_ERROR );
		return;
	}

	undo_rest ( -1 ) ;
	undo_can_undo ( false );


	u8 aux = 0;


	// Puerta
	if ( vobject_get(DOOR)->active            ) aux = DOOR;
	if ( vobject_get(DOOR_O)->active          ) aux = DOOR_O;
	if ( vobject_get(DOOR_OPEN_ANIM)->active  ) aux = DOOR_OPEN_ANIM;

	vobject_swap(aux, _door);


	// weapon
	splist_hide_sprite( splist_weapon );


	// Player
	_player.object = player(0)->object;

	player_set             ( 0, _player);
	player_stop            ( 0 );
	player_update          ( 0 );
	player_update_selected ( 0, _player.selected );


	// Object

	s16 x = level_hpos_to_pixel ( _object_x );
	s16 y = level_vpos_to_pixel ( _object_y );

	if ( _is_bigboy )
	{
		vsprite_set ( bigboy_getByPos(_object_x, _object_y)->index, x, y, _object );
	}
	else
	{
		level_draw_animation ( _object, _object_x, _object_y );
	}


	level_set_object ( level, _object_x, _object_y, _object );
	dead_cancel ( _object_x, _object_y );  // if so


	// Key
	if ( _door == DOOR )
	{
		level_set_key ( _key_x, _key_y );
		level_set_object ( level, _key_x, _key_y, KEY );

		vsprite_animation ( bigboy_getByPos ( _key_x, _key_y )->index, KEY );

		Vect2D_u16 door = level_get_door();
		vsprite_animation ( bigboy_getByPos ( door.x, door.y )->index, DOOR );
	}

	level_actualizar_marcador ( );


	undo_explode ( );
}



void undo_explode ( )
{
   psglist_play ( PSG_KILL );
   toani_draw_undo ( );
}



void undo_save ( u8 ply, u16 object, u16 x, u16 y )
{
	     if ( object == WAMPA_ALT     ) object = WAMPA;
	else if ( object == WALRUS_ALT    ) object = WALRUS;
	else if ( object == ESKIMO_ALT    ) object = ESKIMO;
	else if ( object == DARKELF_ALT   ) object = DARKELF;
	else if ( object == WILDBOAR_ALT  ) object = WILDBOAR;
	else if ( object == TOADSTOOL_ALT ) object = TOADSTOOL;
	else if ( object == SCORPIO_ALT   ) object = SCORPIO;
	else if ( object == BEDOUIN_ALT   ) object = BEDOUIN;
	else if ( object == MUMMY_ALT     ) object = MUMMY;
	else if ( object == PLESI_ALT     ) object = PLESI;
	else if ( object == CANGREJO_ALT  ) object = CANGREJO;
	else if ( object == PIRATA_ALT    ) object = PIRATA;
	else if ( object == DEMON_ALT     ) object = DEMON;
	else if ( object == OGRE_ALT      ) object = OGRE;
	else if ( object == EYE_ALT       ) object = EYE;

	_can_undo  = true;
	_player    = *player ( ply );

	_object    = object;
	_object_x  = x;
	_object_y  = y;

	_key_x     = level_get_key( ).x;
	_key_y     = level_get_key( ).y;

	_is_bigboy = object_is_bigboy ( object );

	_door      = 0;

	if ( vobject_get(DOOR)->active           ) _door = DOOR;
	if ( vobject_get(DOOR_O)->active         ) _door = DOOR_O;
	if ( vobject_get(DOOR_OPEN_ANIM)->active ) _door = DOOR_OPEN_ANIM;
}



s8 undo_rest ( s8 x )
{
	_rest += x;

	if ( _rest > MAX_UNDO )
	{
		_rest = MAX_UNDO;
	}

	return _rest;
}


void undo_can_undo ( bool x )
{
	_can_undo = x;
}



void undo_control ( LEVEL *level )
{
	u16 prob = 0, last = 0;


	if ( _duration == 0 )
	{
		switch ( undo_rest(0) )
		{
			case 0: prob = 1300; last = 5;  break;
			case 1: prob = 1500; last = 8;  break;
			case 2: prob = 1700; last = 10; break;
		}
	}


	if ( prob  &&  random() % prob == 0  )
	{
		Vect2D_u16 grid [ LEVEL_HEIGHT * LEVEL_WIDTH ];

		u16 cnt = level_find ( EMPTY, level, grid );
		u8  pos = random() % cnt;

		_x        = grid[pos].x;
		_y        = grid[pos].y;
		_duration = 60*last;

		// set in wl LEVEL
		level_draw_animation ( UNDO, _x, _y );
		level_set_object ( level, _x, _y, UNDO );
	}


	if ( _duration  && --_duration == 0 )
	{
		level_draw_animation ( EMPTY, _x, _y );
		level_remove_object ( level, _x, _y ); // remove UNDO
		toani_draw_explosion ( _x, _y );
	}

}


void undo_reset_duration ( )
{
   _duration = 0;
}
