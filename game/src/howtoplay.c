#include "../inc/include.h"




static const u16 _list [ 8 ] [ 5 ] =
{
	{ STAFF,      STAFF,      STAFF,      STAFF,      STAFF    },
	{ CROSS,      CROSS,      CROSS,      CROSS,      CROSS    },
	{ SWORD,      SWORD,      SWORD,      SWORD,      SWORD    },
	{ HTP_KEY,    HTP_KEY,    HTP_KEY,    HTP_KEY,    HTP_KEY  },
	{ WILDBOAR,   WALRUS,     SCORPIO,    CANGREJO,   OGRE     },
	{ TOADSTOOL,  ESKIMO,     BEDOUIN,    PIRATA,     EYE      },
	{ DARKELF,    WAMPA,      MUMMY,      PLESI,      DEMON    },
	{ HTP_DOOR,   HTP_DOOR,   HTP_DOOR,   HTP_DOOR,   HTP_DOOR },
};





static struct _hidden_sprites
{
	u16 sprite;
	s16 linea;
	s16 posx;
	s16 posy;
}
_hidden_sprites [ MAX_SPRITE ] = { };


static u16 _count = 0;





static void _show_nb_message ( u8 nb )
{
	const u8 total = frases_count ( 23 ) / 2;
	const u8 *format  = "< %02d/%02d >";

	u8  string [ 40 ];

	sprintf ( string, format, nb, total );
	TEXT_drawText_clear ( string, 23, 5 );
}





static void _show_message ( u8 content )
{
	u8 string1 [ 40 ];
	u8 string2 [ 40 ];

	strcpy ( string1, frases_find ( 23, content * 2 + 0 ) );
	strcpy ( string2, frases_find ( 23, content * 2 + 1 ) );

	StringPadRight ( string1, 29, " " );
	StringPadRight ( string2, 29, " " );

	TEXT_drawText_clear ( string1, 6, 7 );
	TEXT_drawText_clear ( string2, 6, 9 );
}





void _draw_content ( u16 i )
{
    const u8 enemies[5] = { 32, 33, 34, 35, 36 } ;
    const u8 enemy = enemies [ (u8) gamestate.current_ambiente ];


	//drawInt(i, 0,0,3);
	if ( i == 0 )
	{
		_show_nb_message ( 1 );
	}
	else if ( i == 4 )
	{
		_show_message ( 0 );
	}
	else if ( i == 7 )
	{
		// hacer que los espacios no deban estar
		// en los textos, si no generarlos aquí.

		TEXT_drawText_clear ( frases_find ( 24, 1 ),  8, 12 );
		TEXT_drawText_clear ( frases_find ( 24, 0 ), 22, 12 );
	}
	else if ( i == 10 )
	{
		u16 o1 = _list[0][(u16)gamestate.current_ambiente];
		u16 o2 = _list[4][(u16)gamestate.current_ambiente];

		vobject_add ( o1 );
		VOBJECT *vo2 = vobject_add ( o2 );

		vobject_reset ( o1 );
		vobject_reset ( o2 );

		PAL_setPalette ( PAL2, vo2->object->res->pal, CPU);

		vobject_update ( );
		vobject_upload ( );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 7, 14, 2, 2 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o1,  7, 14, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(31,0), 10, 15 );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 21, 14, 2, 2 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o2, 21, 14, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(enemy,0), 24, 15 );
	}
	else if ( i == 13 )
	{
		u16 o1 = _list[1][(u16)gamestate.current_ambiente];
		u16 o2 = _list[5][(u16)gamestate.current_ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o2 );

		vobject_update ( );
		vobject_upload ( );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 7, 17, 2, 2 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o1, 7 , 17, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(31,1), 10, 18 );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 21, 17, 2, 2 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o2, 21, 17, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(enemy,1), 24, 18 );
	}
	else if ( i == 16 )
	{
		u16 o1 = _list[2][(u16)gamestate.current_ambiente];
		u16 o2 = _list[6][(u16)gamestate.current_ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o2 );

		vobject_update ( );
		vobject_upload ( );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B,  7, 20, 2, 2 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o1,  7, 20, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(31,2), 10, 21 );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 21, 19, 2, 3 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o2, 21, 19, true, BG_A, 1, 0, 0, 0, 0 );

		char *str = frases_find(enemy,2);

//		if ( strlen (str) > 11 )  // special case for finnish "Pimeä Tonttu" text
//		{
//            char str1[30];
//
//            memset ( str1, NULL, 29 );
//            memcpy ( str1, &str[0],  5 );
//            TEXT_drawText_clear ( str1, 24, 20 );
//
//            memset ( str1, NULL, 29 );
//            memcpy ( str1, &str[6], 10 );
//		    TEXT_drawText_clear ( str1, 27, 21 );
//		}
//		else
        {
            TEXT_drawText_clear ( str, 24, 21 );
        }
	}
	else if ( i == 19 )
	{
		u16 o1 = _list[3][(u16)gamestate.current_ambiente];
		u16 o2 = _list[7][(u16)gamestate.current_ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o2 );

		vobject_update ( );
		vobject_upload ( );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 7, 22, 2, 3 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o1, 7, 22, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(31,3), 10, 24 );

		SYS_disableInts();
		VDP_clearTileMapRect ( BG_B, 21, 22, 2, 3 );
		SYS_enableInts();
		animation_set_raw();
		animation_draw ( o2, 21, 22, true, BG_A, 1, 0, 0, 0, 0 );
		TEXT_drawText_clear ( frases_find(37,0), 24, 24 );
	}
}





static void _hide_sprite ( u16 sprite )
{
	_hidden_sprites [ _count ].sprite = sprite;
	_hidden_sprites [ _count ].linea  = -1;
	_hidden_sprites [ _count ].posx   = vdpSpriteCache [ sprite ].x-128;
	_hidden_sprites [ _count ].posy   = vdpSpriteCache [ sprite ].y-128;

	_count++;

	splist_hide_sprite ( sprite );
}



static void _restore_sprite  ( s16 sprite )
{
	u8 i;

	for ( i=0; i<_count; i++ )
	{
		if ( sprite == _hidden_sprites[i].sprite )
		{
			VDP_setSpritePosition ( sprite, _hidden_sprites [ i ].posx, _hidden_sprites [ i ].posy );

			return;
		}
	}
}



static void _restore_sprite_by_line ( s16 line )
{
	u8 i;
	bool update = false;

	for ( i=0; i<_count; i++ )
	{
		if ( line == _hidden_sprites[i].linea )
		{
			VDP_setSpritePosition ( _hidden_sprites[i].sprite, _hidden_sprites [ i ].posx, _hidden_sprites [ i ].posy );
			update = true;
		}
	}

	if ( update )
	{
		VDP_updateSprites(80,1);
	}
}


static void _hide_sprites_by_line ( s16 linea )
{
	u16 x, y = linea;

	u8 key = player(0)->key;

	for ( x=0; x<16; x++ )
	{
		BIGBOY *b      = bigboy_getByPos ( x, y );
		bool    is_key = ( key && ( splist_key == (u8) b->index ) );

		if ( b  &&  !is_key )
		{
			_hidden_sprites [ _count ] = (struct _hidden_sprites)
			{
				b->index,
				y,
				vdpSpriteCache[ (u16)b->index ].x - 128,
				vdpSpriteCache[ (u16)b->index ].y - 128
			};

			++_count;

			splist_hide_sprite ( b->index );
		}
	}
}




static void _hide_important_sprites ( LEVEL *level )
{
	_hide_sprite ( splist_weapon );
	_hide_sprite ( splist_explosion );
	_hide_sprite ( splist_element );

	vsprite_animation ( splist_griel, REMOVE_SPRITE );

	u16 duraction = animation_duracion ( REMOVE_SPRITE );

	while ( duraction-- )
	{
		death_frame ( level );
		toani_update ( );
		chorrada_control ( level );
		undo_control ( level );
		level_update ( );

		vobject_update ( );
		vobject_upload ( );

		VDP_updateSprites (80,1);
		SYS_doVBlankProcess ( );
	}

	_hide_sprite ( splist_griel );
}



static void _restore_important_sprites ( )
{
	vsprite_animation ( splist_griel, GRIEL_STANDS );

	_restore_sprite ( splist_griel );
	_restore_sprite ( splist_weapon );
	//_restore_sprite ( splist_explosion ); // no hace falta
	//_restore_sprite ( splist_element   ); // no hace falta
}







static void _show_line ( u8 line )
{
    SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_howtoplay.tilemap, TILE_ATTR_FULL ( PAL1, true, false, false, 900 ), 4, line+5, 0, line, 32, 1 );
	SYS_enableInts();

	SYS_disableInts();
	VDP_setMapEx ( BG_A, cb_howtoplay.tilemap, TILE_ATTR_FULL ( PAL1, true, false, false, 900 ), 4, line+6, 0,   21, 32, 1 );
	SYS_enableInts();
}



static void _marco_desplegar ( )
{
    SYS_disableInts();
	VDP_loadTileSet ( cb_howtoplay.tileset, 900, 0 );
	SYS_enableInts();

	toani_delete_explosion ( );
	_hide_sprites_by_line ( 0 );

	u16 i;

	for ( i=0; i<21; i++ )
	{
		_show_line ( i );

		u16 linea = i +3;
		if ( linea % 2 == 0 )
		{
			linea = linea / 2 -1; // + 2;
			_hide_sprites_by_line ( linea );
		}

		_draw_content ( i );

		VDP_updateSprites(80,1);

		SYS_doVBlankProcess();
	}
}



void htp_marco_enrollar ( LEVEL *wl )
{
	s16 i  = 10;

	for ( i = 10; i >= 0; i-- )
	{
		SYS_doVBlankProcess();

		if ( i )
		{
		    SYS_disableInts();
			VDP_setMapEx ( BG_A, cb_howtoplay.tilemap,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, i*2+4, 0,  21, 32, 1 );
			SYS_enableInts();
		}

		//if ( i == 10 ) splist_hide_sprite(13);
		//if ( i ==  8 ) splist_hide_sprite(12);


		_restore_sprite_by_line ( i );


		if ( i < 10 )
		{
		    SYS_disableInts();
			VDP_setMapEx ( BG_B, wl->background->tilemap, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BG_B ) ), 3, i*2+5, 3, i*2+5, 34, 2 );
			SYS_enableInts();
		}

		level_draw_area ( wl, 0, i, 16, 1 );
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void htp_show ( LEVEL *wl )
{
	VDP_setTextPalette ( PAL0 );
	VDP_setTextPriority ( 1 );

	_count = 0;
	_hide_important_sprites ( wl );

	_marco_desplegar ( );


	const u8 max = ( frases_count ( 23 ) / 2 ) - 1;
	s16  option  = 0;
	s16  counter = 0;
	bool update  = false;

	while ( 1 )
	{
		JoyReader_update();

		if ( joy1_pressed_left || joy1_pressed_right  )
		{
			counter = 0;
			update  = true;

			if ( joy1_pressed_left  ) --option;
			if ( joy1_pressed_right ) ++option;
		}

		if ( option <   0 ) option = max;
		if ( option > max ) option =   0;

		if ( update )
		{
			_show_message    ( option );
			_show_nb_message ( option + 1 );

			psglist_play ( PSG_SELECT );

			update = false;
		}

		if ( counter == 300 ) // 5 secs
		{
			++option;
			counter = 0;
			update  = true;
		}

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			psglist_play ( PSG_START );
			break;
		}


		++counter;

		level_update();

		vobject_update ( );
		vobject_upload ( );

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}


	htp_marco_enrollar ( wl );


	_restore_important_sprites ( );
}
