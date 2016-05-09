#include "../inc/include.h"




static const u16 _list [  8 ] [ 5 ] =
{
	{ WILDBOAR,   WALRUS,     SCORPIO,    CANGREJO,   OGRE       },
	{ TOADSTOOL,  ESKIMO,     BEDOUIN,    PIRATA,     EYE        },
	{ DARKELF,    WAMPA,      MUMMY,      PLESI,      DEMON      },
	{ DEMON_EYES, DEMON_EYES, DEMON_EYES, DEMON_EYES, DEMON_EYES },
	{ STAFF,      STAFF,      STAFF,      STAFF,      STAFF      },
	{ CROSS,      CROSS,      CROSS,      CROSS,      CROSS      },
	{ SWORD,      SWORD,      SWORD,      SWORD,      SWORD      },
	{ KEY,        KEY,        KEY,        KEY,        KEY        }
};





static struct
{
	u16 sprite;
	s16 linea;
	s16 posy;
}
_hided_sprites[MAX_SPRITE];

static u16 _count;



static void _hide_sprite  ( u16 sprite );
static void _restore_sprite  ( s16 sprite );
static void _hide_sprites ( s16 linea );
//static void _restore_sprites ( s16 linea );
static void _write ( u8 *str, u8 x, u8 y );
static void _hide_important_sprites( LEVEL *level );
static void _restore_important_sprites ( );
static void _marco_desplegar();
static void _marco_enrollar( LEVEL *wl );
static void _show_message ( u8 content );




void _draw_content ( u16 i )
{
	drawUInt ( i, 0, 2, 2 );

	if ( i ==  0 )
	{
		_write ( "Ambiente tal", 11, 1 );
		_write ( "03",           27, 1 );
	}
	else if ( i == 3 )
	{
		VDP_clearTileMapRect ( BPLAN, 12, 3, 16, 2 );
		text_draw("ASDFASDF",12,3,0);
	}
	else if ( i == 5 )
	{
		_write ( "INSTRUCTIONS", 14,  6 );
	}
	else if ( i == 10 )
	{
		_show_message ( 0 );
	}
	else if ( i == 11 )
	{
		_write ( "MONSTERS",  9, 12 );
		_write ( "ELEMENTS", 23, 12 );
	}
	else if ( i == 14 )
	{
		u16 o1 = _list[0][(u16)gamestate.ambiente];
		u16 o2 = _list[4][(u16)gamestate.ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o1 );

		VDP_clearTileMapRect ( BPLAN, 7, 14, 2, 2 );
		animation_draw ( o1, 7, 14, true, APLAN, 1, 0, 0, 0, 0 );
		_write ( animation_get(o1)->name, 10, 15 );

		VDP_clearTileMapRect ( BPLAN, 21, 14, 2, 2 );
		animation_draw ( o2, 21, 14, true, APLAN, 1, 0, 0, 0, 0 );
		_write ( animation_get(o2)->name, 24, 15 );
	}
	else if ( i == 17 )
	{
		u16 o1 = _list[1][(u16)gamestate.ambiente];
		u16 o2 = _list[5][(u16)gamestate.ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o1 );

		VDP_clearTileMapRect ( BPLAN, 7, 17, 2, 2 );
		animation_draw ( o1, 7, 17, true, APLAN, 1, 0, 0, 0, 0 );
		_write ( animation_get(o1)->name, 10, 18 );

		VDP_clearTileMapRect ( BPLAN, 21, 17, 2, 2 );
		animation_draw ( o2, 21, 17, true, APLAN, 1, 0, 0, 0, 0 );
		_write ( animation_get(o2)->name, 24, 18 );
	}
	else if ( i == 20 )
	{
		u16 o1 = _list[2][(u16)gamestate.ambiente];
		u16 o2 = _list[6][(u16)gamestate.ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o1 );

		vobject_add ( o1  );
		vsprite_set ( 12, 7*8, 152, o1 );
		VDP_setSpritePiority ( 12, true );
		_write ( animation_get(o1)->name, 10, 21 );

		VDP_clearTileMapRect ( BPLAN, 21, 20, 2, 2 );
		animation_draw ( o2, 21, 20, true, APLAN, 1, 0, 0, 0, 0 );
		_write ( animation_get(o2)->name, 24, 21 );
	}
	else if ( i == 24 )
	{
		u16 o1 = _list[3][(u16)gamestate.ambiente];
		u16 o2 = _list[7][(u16)gamestate.ambiente];

		vobject_add ( o1 ); vobject_reset ( o1 );
		vobject_add ( o2 ); vobject_reset ( o1 );

		VDP_clearTileMapRect ( BPLAN, 7, 23, 2, 2 );
		animation_draw ( o1, 7, 23, true, APLAN, 1, 0, 0, 0, 0 );
		_write ( animation_get(o1)->name, 10, 24 );

		vobject_add ( o2  );
		vsprite_set ( 13, 21*8, 176, o2 );
		VDP_setSpritePiority ( 13, true );
		_write ( animation_get(o2)->name, 24, 24 );

		//VDP_clearTileMapRect ( BPLAN, 21, 23, 2, 2 );
		//animation_draw ( o2, 21, 23, true, APLAN, 1, 0, 0, 0, 0 );
	}






//	vobject_add(htp.head);
//	vsprite_set ( 1, 24, 144, htp.head );
//	vsprite_priority ( 1, true );
//
//	vobject_add(DEMON_EYES);
//	vsprite_set ( 2, 8, 160, DEMON_EYES );
//	vsprite_priority ( 2, true );
//
////   vobject_add(KEY);
////   vsprite_set (  3, 8, 24, GRIEL_STANDS );
////	vsprite_priority ( 3, true );
//
//
//	for ( i = 0; i < 8; i++ )
//	{
//			OBJECT *o = object_get ( htp.positions[i].element );
//
//			//animation_draw ( htp.positions[i].element, htp.positions[i].x, htp.positions[i].y-1, APLAN, 1, o->pal );
//			level_draw_animation_rp ( htp.positions[i].element, htp.positions[i].x, htp.positions[i].y-1 );
//
//			_write ( o->name, htp.positions[i].x+3, htp.positions[i].y );
//	}

	VDP_updateSprites();
}



static void _hide_sprite  ( u16 sprite )
{
	_hided_sprites [ _count ].sprite = sprite;
	_hided_sprites [ _count ].linea  = -1;
	_hided_sprites [ _count ].posy   = vdpSpriteCache [ sprite ].posy;

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
			vdpSpriteCache[ sprite ].posy = _hided_sprites [ i ].posy;
			VDP_setSpriteDirectP ( sprite, &( vdpSpriteCache[ sprite ] ) );

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
	u16 x, y = linea / 2 -1;// + 2;
	u8 update_sprite=0;

	for ( x=0; x<16; x++ )
	{
		if ( ( b = bigboy_getByPos ( x, y ) ) )
		{
			_hided_sprites [ _count ].sprite = b->index;
			_hided_sprites [ _count ].linea  = linea;
			_hided_sprites [ _count ].posy   = vdpSpriteCache[ (u16)b->index ].posy;

			_count++;

			splist_hide_sprite ( b->index );

			++update_sprite;
		}
	}

	if ( update_sprite )
	{
		VDP_updateSprites();
	}
}



//static void _restore_sprites ( s16 linea )
//{
//	u8 i, update_sprite=0;
//
//	for ( i=0; i<_count; i++ )
//	{
//		if ( linea == _hided_sprites[i].linea )
//		{
//			u8 sprite = _hided_sprites[i].sprite;
//
//			vdpSpriteCache[ sprite ].posy = _hided_sprites [ i ].posy;
//			VDP_setSpriteDirectP ( sprite, &vdpSpriteCache[sprite] );
//
//			++update_sprite;
//		}
//	}
//
//	if ( update_sprite )
//	{
//		VDP_updateSprites();
//	}
//}





static void _write ( u8 *str, u8 x, u8 y )
{
	u8 len = strlen(str);

	VDP_clearTileMapRect ( BPLAN, x, y, len, 1 );
	VDP_drawText ( str, x, y );
}




static void _hide_important_sprites( LEVEL *level )
{
	_hide_sprite ( splist_weapon );
	_hide_sprite ( splist_explosion );
	_hide_sprite ( splist_element );



	vsprite_animation( splist_griel, REMOVE_SPRITE );

	u16 duraction = animation_duracion( REMOVE_SPRITE );

	while ( --duraction )
	{
		death_frame ( level );
		toani_remove();
		toani_demon_update ( );
		chorrada_control ( level );
		undo_control ( level );
		//scoreball_frame();
		level_update();


		vobject_update();
		VDP_updateSprites();
		VDP_waitVSync();
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



static void _marco_desplegar()
{
	VDP_loadTileSet ( cb_howtoplay.tileset, 900, 0 );

	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4,  1, 0,  0, 32, 1 );


	u16 i;

	for ( i=0; i<25; i++ )
	{
		VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, i+1, 0,  i, 32, 1 );
		VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, i+2, 0, 26, 32, 1 );

		_hide_sprites ( i );
		_draw_content ( i );

		waitMs(4); // 19
	}
}



static void _marco_enrollar( LEVEL *wl )
{
	s16 wait = 5; // 22;



	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 0, 0, 0,  0, 32, 27 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 24, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 10, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 24, 0,  26, 32, 1 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 22, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 9, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 23, 0,  25, 32, 1 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 20, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 8, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 20, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 18, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 7, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 18, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 16, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 6, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 16, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 14, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 5, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 14, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 12, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 4, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 12, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 10, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 3, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 10, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4,  8, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 2, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4,  8, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4, 6, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 1, 16, 1, false );
	waitMs ( wait );

//	VDP_setMapEx ( BPLAN, wl->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, 6, 4, 26, 32, 2 );
	VDP_setMapEx ( APLAN, cb_howtoplay.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 4,  4, 0,  26, 32, 1 );
	level_draw_area ( *wl, 0, 0, 16, 1, false );
	waitMs ( wait );

}









static void _show_message ( u8 content )
{
	if ( content == 0 )
	{
		_write ( "Guide Griel in his quest for", 6,  8 );
		_write ( "the Holy Porr`n.            ", 6, 10 );
		_write ( "1/4", 30, 6 );
	}
	else if ( content == 1 )
	{
		_write ( "Find the key in each maze to", 6,  8 );
		_write ( "break the magic seal.       ", 6, 10 );
		_write ( "2/4", 30,6);
	}
	else if ( content == 2 )
	{
		_write ( "Use the magic weapons to    ", 6,  8 );
		_write ( "vanquish the evil foes.     ", 6, 10 );
		_write ( "3/4", 30, 6 );
	}
	else if ( content == 3 )
	{
		_write ( "Only the Holy Porr`n would  ", 6,  8 );
		_write ( "restore King's mind.        ", 6, 10 );
		_write ( "4/4", 30, 6 );
	}
}




//////////////////////////////////////////////////////////////////////////////////////////////




void htp_show ( LEVEL *wl )
{
	_count   = 0;
	_hide_important_sprites( wl );



	_marco_desplegar();


	s16 option = 0;

	JoyReader_reset();

	while ( 1 )
	{
		JoyReader_update();

		if ( joy1_pressed_left || joy1_pressed_right  )
		{
			if ( joy1_pressed_left   &&  --option < 0 ) option = 3;
			if ( joy1_pressed_right  &&  ++option > 3 ) option = 0;

			_show_message ( option );
			psglist_play ( PSG_SELECT );
		}

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			psglist_play ( PSG_START );
			break;
		}

		vobject_update ( );

		VDP_updateSprites();
		VDP_waitVSync();
	}





	_marco_enrollar ( wl );


	_restore_important_sprites ( );
}






















//#include "../inc/include.h"
//
//static SpriteDef sprites [ 4 ];
//
//
//
//typedef struct
//{
//	u8  head;
//
//	struct
//	{
//      u8  element;
//      u8  x;
//      u8  y;
//	}
//	positions[8];
//}
//HTP;
//
//
//static const HTP _list[] =
//{
//   {
//      DARKELF,
//      {
//         { WILDBOAR,    5, 15 },
//         { TOADSTOOL,   5, 18 },
//         { DARKELF,     5, 21 },
//         { DEMON_EYES,  5, 24 },
//         { STAFF,      22, 15 },
//         { CROSS,      22, 18 },
//         { SWORD,      22, 21 },
//         { KEY,        22, 24 },
//      },
//	},
//
//   {
//      WAMPA,
//      {
//         { WALRUS,      5, 15 },
//         { ESKIMO,      5, 18 },
//         { WAMPA,       5, 21 },
//         { DEMON_EYES,  5, 24 },
//         { STAFF,      22, 15 },
//         { CROSS,      22, 18 },
//         { SWORD,      22, 21 },
//         { KEY,        22, 24 },
//      }
//   },
//
//   {
//      MUMMY,
//      {
//         { SCORPIO,     5, 15 },
//         { BEDOUIN,     5, 18 },
//         { MUMMY,       5, 21 },
//         { DEMON_EYES,  5, 24 },
//         { STAFF,      22, 15 },
//         { CROSS,      22, 18 },
//         { SWORD,      22, 21 },
//         { KEY,        22, 24 },
//      },
//   },
//
//   {
//      PLESI,
//      {
//         { CANGREJO,    5, 15 },
//         { PIRATA,      5, 18 },
//         { PLESI,       5, 21 },
//         { DEMON_EYES,  5, 24 },
//         { STAFF,      22, 15 },
//         { CROSS,      22, 18 },
//         { SWORD,      22, 21 },
//         { KEY,        22, 24 },
//      },
//   },
//
//   {
//      DEMON,
//      {
//         { OGRE,    5, 15 },
//         { EYE,      5, 18 },
//         { DEMON,       5, 21 },
//         { DEMON_EYES,  5, 24 },
//         { STAFF,      22, 15 },
//         { CROSS,      22, 18 },
//         { SWORD,      22, 21 },
//         { KEY,        22, 24 },
//      },
//   },
//
//   {
//      0
//   }
//};
//
//
//
//static const struct _cadena
//{
//	u8  index;
//	u8  x;
//	u8  y;
//	u8 *cadena;
//}
//cadenas [] =
//{
//	{ 1,  8, 6, "Guide Griel in his quest  " },
//	{ 1,  8, 8, "for the Holy Porr`n.      " },
//	{ 1, 32,10, "1/4"                        },
//
//	{ 2,  8, 6, "Find the key in each maze " },
//	{ 2,  8, 8, "to break the magic seal.  " },
//	{ 2, 32,10, "2/4"                        },
//
//	{ 3,  8, 6, "Use the magic weapons to  " },
//	{ 3,  8, 8, "vanquish the evil foes.   " },
//	{ 3, 32,10, "3/4"                        },
//
//	{ 4,  8, 6, "Only the Holy Porr`n would" },
//	{ 4,  8, 8, "restore King's mind.      " },
//	{ 4, 32,10, "4/4"                        },
//
//	{ 0,  0, 0, "" }, // EOF
//};
//
//
//
//
//
//
//static void _show_message ( u8 content )
//{
//	u8 i = 0;
//
//	while ( cadenas[i].index )
//	{
//		if ( content == cadenas[i].index )
//		{
//			VDP_drawText ( cadenas[i].cadena, cadenas[i].x, cadenas[i].y );
//		}
//
//		++i;
//	}
//}
//
//
//static void _hide_sprites()
//{
//   u8 i;
//
//   for ( i=0; i< MAX_SPRITE; i++ )
//   {
//      s16 x = vdpSpriteCache[i].posx;
//      s16 y = vdpSpriteCache[i].posy;
//
//      if (
//         x >= (4+0)*8  &&  x < (4+1)*8 + (32-0)*8  &&
//         y >= (4-1)*8  &&  y < (4-1)*8 + (23-1)*8
//      )
//      {
//         splist_hide_sprite ( i );
//      }
//   }
//
//   VDP_updateSprites();
//}
//
//
//HTP _find_htp()
//{
//   u8  i = 0;
//
//   do
//   {
//      if ( _list[i].head == 0 )
//      {
//         return _list[0];
//      }
//
//      if ( _list[i].head == level_get_head ( ) )
//      {
//         return _list[i];
//      }
//   }
//   while ( i++ );
//
//   return (HTP) {};
//}
//
//
//static void _draw()
//{
//   VDP_drawImageEx ( APLAN, &cb_howtoplay, TILE_ATTR_FULL(PAL1, true, false, false, 900), 3, 4, false, true );
//
//   VDP_clearTileMapRect ( BPLAN,  4,  5, 32,  6 );
//   VDP_clearTileMapRect ( BPLAN,  4, 13, 15, 13 );
//   VDP_clearTileMapRect ( BPLAN, 21, 13, 15, 13 );
//}
//
//
//static void _restore ( LEVEL *level )
//{
//   u8 i; //, j=0;
//
//   VDP_clearTileMapRect ( APLAN,  3,  4, 34,  1 );
//
//   for ( i=0; i<11; i++ )
//   {
//      u8 j = i * 2 + 5;
//
//      VDP_clearTileMapRect ( APLAN, 36,  j,  1, 2 );
//      VDP_clearTileMapRect ( APLAN,  3,  j,  1, 2 );
//
//      VDP_setMapEx ( BPLAN, level->background->map, TILE_ATTR_FULL(PAL0, false, false, false, level_vram_pos ( BPLAN ) ), 4, j, 4, j, 32, 2 );
//      level_draw_area ( *level, 0, i, LEVEL_WIDTH, 1, false );
//      VDP_updateSprites();
//   }
//}
//
//
//
//void _draw_content ( )
//{
//	_show_message ( 1 );
//
//   u8 i;
//   HTP htp = _find_htp();
//
//	vsprite_set ( 0, 144, 152, KEY );
//	vsprite_priority ( 0, true );
//
//	vsprite_set ( 1, 24, 144, htp.head );
//	vsprite_priority ( 1, true );
//
//	vsprite_set ( 2, 8, 160, DEMON_EYES );
//	vsprite_priority ( 2, true );
//
//   vsprite_set (  3, 8, 24, GRIEL_STANDS );
//	vsprite_priority ( 3, true );
//
//
//	for ( i = 0; i < 8; i++ )
//	{
//			OBJECT *o = object_get ( htp.positions[i].element );
//
//			//animation_draw ( htp.positions[i].element, htp.positions[i].x, htp.positions[i].y-1, APLAN, 1, o->pal );
//			level_draw_animation_rp ( htp.positions[i].element, htp.positions[i].x, htp.positions[i].y-1 );
//
//			VDP_drawText  ( o->name, htp.positions[i].x+3, htp.positions[i].y );
//	}
//
//	VDP_updateSprites();
//}
//
//
//
//////////////////////////////////////////////////
//
//
//
//
//u16 htp_show ( LEVEL *level )
//{
//	u16 i      = 0;
//	u16 vel    = ( IS_PALSYSTEM ? 50+1 : 60-1 ) * 6 ; // * 5 segundos
//	s8 content = 1;
//
//   sprites[0] = vdpSpriteCache[0];
//   sprites[1] = vdpSpriteCache[1];
//   sprites[2] = vdpSpriteCache[2];
//   sprites[3] = vdpSpriteCache[3];
//
//
//	_hide_sprites();
//	_draw();
//   _draw_content();
//
//   tool_waitWhilePessed ( JOY_1, BUTTON_A );
//
//
//	while ( ++i )
//	{
//		if ( i % vel == 0 )
//		{
//			content++;
//		}
//		else if ( joy1.state & BUTTON_RIGHT ) { content++; waitMs(200); i=0; }
//		else if ( joy1.state & BUTTON_LEFT  ) { content--; waitMs(200); i=0; }
//		else if ( joy1.state & BUTTON_BTN )
//		{
//			psglist_play ( PSG_START );
//			break;
//		}
//
//		if ( content > 4 ) content = 1;
//		if ( content < 1 ) content = 4;
//
//		_show_message ( content );
//
//		vobject_update();
//		VDP_waitVSync();
//	}
//
//   tool_waitWhilePessed ( JOY_1, BUTTON_BTN );
//
//   vdpSpriteCache[0] = sprites[0];
//   vdpSpriteCache[1] = sprites[1];
//   vdpSpriteCache[2] = sprites[2];
//   vdpSpriteCache[3] = sprites[3];
//
// 	_restore ( level );
//
//
//
//	return LEVEL_RESUME;
//}
