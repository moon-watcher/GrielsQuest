#include "../inc/include.h"

static struct
{
	u16 sprite;
	s16 linea;
	s16 posx;
	s16 posy;
}
_hided_sprites[MAX_SPRITE] = { };

static u8 _count = 0;




static void _hide_sprite  ( u16 sprite )
{
	_hided_sprites [ _count ].sprite = sprite;
	_hided_sprites [ _count ].linea  = -1;
	_hided_sprites [ _count ].posx   = vdpSpriteCache [ sprite ].x - 128;
	_hided_sprites [ _count ].posy   = vdpSpriteCache [ sprite ].y - 128;

	_count++;

	splist_hide_sprite ( sprite );
}


static void _restore_sprite  ( s16 sprite )
{
	u8 i;

	for ( i=0; i<_count; i++ )
	{
		if ( sprite == _hided_sprites[i].sprite )
		{
			VDP_setSpritePosition ( sprite, _hided_sprites [ i ].posx, _hided_sprites [ i ].posy );

			return;
		}
	}
}


static void _hide_sprites ( s16 linea )
{
	if ( linea % 2 )
	{
		return;
	}

	BIGBOY *b;
	u16 x, y = linea / 2 + 2;

	for ( x=4; x<=11; x++ )
	{
		if ( ( b = bigboy_getByPos ( x, y ) ) )
		{
			_hided_sprites [ _count ].sprite = b->index;
			_hided_sprites [ _count ].linea  = linea;
			_hided_sprites [ _count ].posx   = vdpSpriteCache[ (u16)b->index].x - 128;
			_hided_sprites [ _count ].posy   = vdpSpriteCache[ (u16)b->index].y - 128;

			_count++;

			splist_hide_sprite ( b->index );
		}
	}

   VDP_updateSprites(80,1);
}



static void _restore_sprites ( s16 linea )
{
	u8 i;

	for ( i=0; i<_count; i++ )
	{
		if ( linea == _hided_sprites[i].linea )
		{
			VDP_setSpritePosition ( _hided_sprites[i].sprite, _hided_sprites [ i ].posx, _hided_sprites [ i ].posy );
		}
	}

   VDP_updateSprites(80,1);
}









static void _hide_important_sprites( LEVEL *level )
{
	_hide_sprite ( splist_weapon );
	_hide_sprite ( splist_explosion );
	_hide_sprite ( splist_element );

	vobject_reset ( REMOVE_SPRITE );
	vsprite_animation ( splist_griel, REMOVE_SPRITE );

	u16 duraction = animation_duracion ( REMOVE_SPRITE );

	while ( duraction-- )
	{
		death_frame ( level );
		toani_update();
		chorrada_control ( level );
		undo_control ( level );
		level_update();

		vobject_update();
		vobject_upload ( );

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}

	_hide_sprite ( splist_griel );
}


static void _restore_important_sprites ( )
{
	vsprite_animation ( splist_griel, GRIEL_STANDS );

	_restore_sprite ( splist_griel );
	_restore_sprite ( splist_weapon );
	//_restore_sprite ( splist_explosion ); // no hace falta
	//_restore_sprite ( splist_element ); // no hace falta
}



static void _marco_desplegar ( )
{
    SYS_disableInts();
	VDP_loadTileSet ( cb_pause.tileset, 900, 0 );
	VDP_setMapEx ( BG_A, cb_pause.tilemap,TILE_ATTR_FULL(PAL1, true, false, false, 900), 12,  9, 0,  0, 16, 1 );
	SYS_enableInts();

	toani_delete_explosion ( );

	u16 i;

	for ( i=0; i<10; i++ )
	{
	    SYS_disableInts();
		VDP_setMapEx ( BG_A, cb_pause.tilemap, TILE_ATTR_FULL(PAL1, true, false, false, 900), 12, i+10, 0, i+1, 16, 1 );
		VDP_setMapEx ( BG_A, cb_pause.tilemap, TILE_ATTR_FULL(PAL1, true, false, false, 900), 12, i+11, 0,  11, 16, 1 );
		SYS_enableInts();

		_hide_sprites ( i );

		if ( i == 2 ) TEXT_drawText_clear ( frases_next(), 14, 12 );
		if ( i == 5 )
		{
            u8 *str = frases_next();

//            if ( strlen (str) > 13 )  // special case for finnish "ALOITA ALUSTA" text
//            {
//                char str1[30];
//
//                memset(str1, NULL, 29 );
//                memcpy( str1, &str[0], 9 );
//                TEXT_drawText_clear ( str1, 14, 14 );
//
//                memset ( str1, NULL, 29 );
//                memcpy ( str1, &str[9], 6 );
//                TEXT_drawText_clear ( str1, 20, 15 );
//            }
//            else
            {
                TEXT_drawText_clear ( str, 14, 14 );
            }
        }
		if ( i == 7 ) TEXT_drawText_clear ( frases_next(), 14, 17 );

		waitHz(1);
	}
}



static void _marco_enrollar( LEVEL *wl )
{
	u16 wait = 1; // 22;
	u16 aux1 = TILE_ATTR_FULL(PAL1, true, false, false, 900);
	u16 aux2 = TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BG_B ) );


	_restore_sprites ( 8 );
	_restore_sprites ( 7 );
	SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_pause.tilemap, aux1, 12, 18, 0,  11, 16, 1 );
	VDP_setMapEx ( BG_B, wl->background->tilemap, aux2, 13, 19, 13, 19, 16, 2 );
    SYS_enableInts();
	level_draw_area ( wl, 4, 7, 8, 1 );
	waitHz(wait);

	_restore_sprites( 6 );
	SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_pause.tilemap, aux1, 12, 16, 0,  11, 16, 1 );
	VDP_setMapEx ( BG_B, wl->background->tilemap, aux2, 13, 17, 13, 17, 16, 2 );
    SYS_enableInts();
	level_draw_area ( wl, 4, 6, 8, 1 );
	waitHz(wait);

	_restore_sprites( 5 );
	SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_pause.tilemap, aux1, 12, 14, 0,  11, 16, 1 );
	VDP_setMapEx ( BG_B, wl->background->tilemap, aux2, 13, 15, 13, 15, 16, 2 );
    SYS_enableInts();
	level_draw_area ( wl, 4, 5, 8, 1 );
	waitHz(wait);

	_restore_sprites( 4 );
	SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_pause.tilemap, aux1, 12, 12, 0,  11, 16, 1 );
	VDP_setMapEx ( BG_B, wl->background->tilemap, aux2, 13, 13, 13, 13, 16, 2 );
    SYS_enableInts();
	level_draw_area ( wl, 4, 4, 8, 1 );
	waitHz(wait);

	_restore_sprites( 3 );
	SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_pause.tilemap, aux1, 12, 10, 0,  11, 16, 1 );
	VDP_setMapEx ( BG_B, wl->background->tilemap, aux2, 13, 11, 13, 11, 16, 2 );
    SYS_enableInts();
	level_draw_area ( wl, 4, 3, 8, 1 );
	waitHz(wait);

	_restore_sprites( 2 );
	_restore_sprites( 1 );
	_restore_sprites( 0 );
	SYS_disableInts();
	VDP_setMapEx ( BG_B, wl->background->tilemap, aux2, 13,  9, 13,  9, 16, 2 );
    SYS_enableInts();

	level_draw_area ( wl, 4, 2, 8, 1 );
	waitHz(wait);
}


//////////////////////////////////////////////////////////////////////////////////////////////




void pause_show ( LEVEL *wl, u16 *ret )
{
	*ret = 0;


	if ( !joy1_pressed_start || gamestate_on_medallon() )
	{
		*ret = LEVEL_OK;
		return;
	}


	psglist_play ( PSG_START );
	frases_init(2);
	VDP_setTextPalette(PAL0);

	_count = 0;


	const struct
	{
		u16 psgfx;
		u16 ret;
		u8  y;
	}
	opciones[3] =
	{
		{ PSG_START, LEVEL_OK,      12 },
		{ PSG_WRONG, LEVEL_RESTART, 14 },
		{ PSG_WRONG, LEVEL_EXIT,    17 }
	};


	_hide_important_sprites( wl );
	_marco_desplegar();


	s16 option = 0;

	while ( *ret == 0 )
	{
		JoyReader_update();

		if ( joy1_pressed_up || joy1_pressed_down  )
		{
			if ( joy1_pressed_up    &&  --option < 0 ) option = 2;
			if ( joy1_pressed_down  &&  ++option > 2 ) option = 0;

			TEXT_drawText ( " ",  14, opciones[0].y );
			TEXT_drawText ( " ",  14, opciones[1].y );
			TEXT_drawText ( " ",  14, opciones[2].y );
			TEXT_drawText ( "\\", 14, opciones[option].y );

			psglist_play ( PSG_SELECT );
		}

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			*ret = opciones[option].ret;
		}

		SYS_doVBlankProcess();
	}

	psglist_play ( opciones[option].psgfx );

	_marco_enrollar ( wl );
	_restore_important_sprites ( );

	JoyReader_reset();
	JoyReader_update();

	if ( *ret == LEVEL_RESTART )
	{
		//player_dead ( PLAYER_1, wl, ret );
	}

	if ( *ret == LEVEL_EXIT )
	{
		music_stop();
	}
}
