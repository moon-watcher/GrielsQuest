#include <genesis.h>
#include <genres.h>

#include "../inc/include.h"


#define FIRST_SPRITE_BASE  0


extern const LEVEL w0r00, w0r01, w0r02, w0r03, w0r04, w0r05, w0r06, w0r07, w0r08, w0r09, w0r10, w0r11, w0r12, w0r13;
extern const LEVEL w1r00, w1r01, w1r02, w1r03, w1r04, w1r05, w1r06, w1r07, w1r08, w1r09, w1r10, w1r11, w1r12, w1r13;
extern const LEVEL w2r00, w2r01, w2r02, w2r03, w2r04, w2r05, w2r06, w2r07, w2r08, w2r09, w2r10, w2r11, w2r12, w2r13;
extern const LEVEL w3r00, w3r01, w3r02, w3r03, w3r04, w3r05, w3r06, w3r07, w3r08, w3r09, w3r10, w3r11, w3r12, w3r13;
extern const LEVEL w4r00, w4r01, w4r02, w4r03, w4r04, w4r05;




#define LV   (LEVEL*)&

#define MS0  { MUSIC_BOSQUE_1,   MUSIC_BOSQUE_2                     }
#define MS1  { MUSIC_HIELO_1,    MUSIC_HIELO_2,    MUSIC_HIELO_3    } // pendiente
#define MS2  { MUSIC_DESIERTO_1, MUSIC_DESIERTO_2, MUSIC_DESIERTO_3 } // pendiente
#define MS3  { MUSIC_PLAYA_1,    MUSIC_PLAYA_2,    MUSIC_PLAYA_3    }
#define MS4  { MUSIC_CAVERNA_1,  MUSIC_CAVERNA_2                    }


const LEVELLIST level_list [ LEVEL_DIF_MAX_AMBIENTES ] [ LEVEL_DIF_MAX_DIFICULTAD ] =
{
   {
      { "FOREST",       6, DARKELF, MS0, { LV w0r00, LV w0r01, LV w0r02, LV w0r03, LV w0r04, LV w0r13 } },
      { "FOREST",      10, DARKELF, MS0, { LV w0r00, LV w0r01, LV w0r02, LV w0r03, LV w0r04, LV w0r05, LV w0r06, LV w0r07, LV w0r08, LV w0r13 } },
      { "FOREST",      14, DARKELF, MS0, { LV w0r00, LV w0r01, LV w0r02, LV w0r03, LV w0r04, LV w0r05, LV w0r06, LV w0r07, LV w0r08, LV w0r09, LV w0r10, LV w0r11, LV w0r12, LV w0r13 } },
   },

   {
      { "ICELAND",      6, WAMPA,   MS1, { LV w1r00, LV w1r01, LV w1r02, LV w1r03, LV w1r04, LV w1r13 } },
      { "ICELAND",     10, WAMPA,   MS1, { LV w1r00, LV w1r01, LV w1r02, LV w1r03, LV w1r04, LV w1r05, LV w1r06, LV w1r07, LV w1r08, LV w1r13 } },
      { "ICELAND",     14, WAMPA,   MS1, { LV w1r00, LV w1r01, LV w1r02, LV w1r03, LV w1r04, LV w1r05, LV w1r06, LV w1r07, LV w1r08, LV w1r09, LV w1r10, LV w1r11, LV w1r12, LV w1r13 } },
   },

   {
      { "THE PYRAMID",  6, MUMMY,   MS2, { LV w2r00, LV w2r01, LV w2r02, LV w2r03, LV w2r04, LV w2r13 } },
      { "THE PYRAMID", 10, MUMMY,   MS2, { LV w2r00, LV w2r01, LV w2r02, LV w2r03, LV w2r04, LV w2r05, LV w2r06, LV w2r07, LV w2r08, LV w2r13 } },
      { "THE PYRAMID", 14, MUMMY,   MS2, { LV w2r00, LV w2r01, LV w2r02, LV w2r03, LV w2r04, LV w2r05, LV w2r06, LV w2r07, LV w2r08, LV w2r09, LV w2r10, LV w2r11, LV w2r12, LV w2r13 } },
   },

   {
      { "BEACH",        6, PLESI,   MS3, { LV w3r00, LV w3r01, LV w3r02, LV w3r03, LV w3r04, LV w3r13 } },
      { "BEACH",       10, PLESI,   MS3, { LV w3r00, LV w3r01, LV w3r02, LV w3r03, LV w3r04, LV w3r05, LV w3r06, LV w3r07, LV w3r08, LV w3r13 } },
      { "BEACH",       14, PLESI,   MS3, { LV w3r00, LV w3r01, LV w3r02, LV w3r03, LV w3r04, LV w3r05, LV w3r06, LV w3r07, LV w3r08, LV w3r09, LV w3r10, LV w3r11, LV w3r12, LV w3r13 } },
   },

   {
      { "VOLCANO",      4, DEMON,   MS4, { LV w4r00, LV w4r01, LV w4r02, LV w4r05 } },
      { "VOLCANO",      5, DEMON,   MS4, { LV w4r00, LV w4r01, LV w4r02, LV w4r03, LV w4r05 } },
      { "VOLCANO",      6, DEMON,   MS4, { LV w4r00, LV w4r01, LV w4r02, LV w4r03, LV w4r04, LV w4r05 } },
   }
};




static Vect2D_u16  _key = { };
static Vect2D_u16  _door = { };
static u16         _vram_pos[2] = { };
static fix16       _vscroll = 0;
static u16         _pal2 = 0;
static u16         _pal3 = 0;
static bool        _flip_h = false;
static bool        _flip_v = false;
static u8          _force_width = 0;
static u8          _force_height = 0;








static bool _flip_vh ( )
{
	if ( gamestate_on_medallon() )
	{
		return false;
	}

	if ( gamestate.dificultad > 2 )
	{
		return (bool) ( random() % 2 );
	}

	return false;
}


static void _draw_marcador ()
{
	VDP_loadTileSet ( cb_ui.tileset, _vram_pos[1], 0 );
	VDP_setMapEx ( PLAN_A,cb_ui.map, TILE_ATTR_FULL(PAL1, false, false, false, _vram_pos[1]),  4,  0,  2,  0,  17,  5 );

	vsprite_set ( splist_ui_left_1, 16,  0, UI_LEFT_1 );
	vsprite_set ( splist_ui_left_2, 16, 24, UI_LEFT_2 );

	VDP_setSpritePiority ( splist_ui_weapon, 1 );
	VDP_setSpritePiority ( splist_ui_enemy,  1 );
	VDP_setSpritePiority ( splist_ui_left_1, 1 );
	VDP_setSpritePiority ( splist_ui_left_2, 1 );

	VDP_updateSprites(80,1);
}



static LEVEL _reorder_level ( LEVEL *level )
{
	s16 j, i;

	LEVEL ret = *level;

	s16 flipped_h [ MAX_ANIMATIONS ];
	s16 flipped_v [ MAX_ANIMATIONS ];

	memsetU16 ( flipped_h, MAX_U16, MAX_ANIMATIONS );
	memsetU16 ( flipped_v, MAX_U16, MAX_ANIMATIONS );

	flipped_h [ LEFT1       ] = RIGHT1;
	flipped_h [ RIGHT1      ] = LEFT1;
	flipped_h [ LEFT2       ] = RIGHT2;
	flipped_h [ RIGHT2      ] = LEFT2;
	flipped_h [ LEFT3       ] = RIGHT3;
	flipped_h [ RIGHT3      ] = LEFT3;
	flipped_h [ LEFT4       ] = RIGHT4;
	flipped_h [ RIGHT4      ] = LEFT4;
	flipped_h [ LEFT5       ] = RIGHT5;
	flipped_h [ RIGHT5      ] = LEFT5;
	flipped_h [ SOFA1       ] = SOFA2;
	flipped_h [ SOFA2       ] = SOFA1;
	flipped_h [ IGLU1       ] = IGLU2;
	flipped_h [ IGLU2       ] = IGLU1;
	flipped_h [ IGLU3       ] = IGLU4;
	flipped_h [ IGLU4       ] = IGLU3;
	flipped_h [ ESFINGE1    ] = ESFINGE2;
	flipped_h [ ESFINGE2    ] = ESFINGE1;
	flipped_h [ ESFINGE3    ] = ESFINGE4;
	flipped_h [ ESFINGE4    ] = ESFINGE3;
	flipped_h [ BIGPLESI1   ] = BIGPLESI2;
	flipped_h [ BIGPLESI2   ] = BIGPLESI1;
	flipped_h [ BIGPLESI3   ] = BIGPLESI4;
	flipped_h [ BIGPLESI4   ] = BIGPLESI3;
	flipped_h [ MURCIANO1   ] = MURCIANO2;
	flipped_h [ MURCIANO2   ] = MURCIANO1;
	flipped_h [ MURCIANO3   ] = MURCIANO4;
	flipped_h [ MURCIANO4   ] = MURCIANO3;
	flipped_h [ LAKE1       ] = LAKE2;
	flipped_h [ LAKE2       ] = LAKE1;
	flipped_h [ LAKE3       ] = LAKE4;
	flipped_h [ LAKE4       ] = LAKE3;

	flipped_v [ UP1         ] = DOWN1;
	flipped_v [ DOWN1       ] = UP1;
	flipped_v [ UP2         ] = DOWN2;
	flipped_v [ DOWN2       ] = UP2;
	flipped_v [ UP3         ] = DOWN3;
	flipped_v [ DOWN3       ] = UP3;
	flipped_v [ UP4         ] = DOWN4;
	flipped_v [ DOWN4       ] = UP4;
	flipped_v [ UP5         ] = DOWN5;
	flipped_v [ DOWN5       ] = UP5;
	flipped_v [ ABBAYE_D    ] = TOCON1;
	flipped_v [ ABBAYE_U    ] = 0;
	flipped_v [ BIGTREE1_D  ] = TOCON1;
	flipped_v [ BIGTREE1_U  ] = 0;
	flipped_v [ ABBAYE_D_2  ] = TREE2;
	flipped_v [ ABBAYE_U_2  ] = 0;
	flipped_v [ FISH22      ] = TREE2;
	flipped_v [ FISH21      ] = 0;
	flipped_v [ ORUS2       ] = CRUZPY;
	flipped_v [ ORUS1       ] = 0;
	flipped_v [ SARCOFAGO2  ] = CRUZPY;
	flipped_v [ SARCOFAGO1  ] = 0;
	flipped_v [ TOTEM_2     ] = TENTACLE;
	flipped_v [ TOTEM_1     ] = 0;
	flipped_v [ BIGTREE_D_4 ] = TENTACLE;
	flipped_v [ BIGTREE_U_4 ] = 0;
	flipped_v [ ABBAYE_D_5  ] = BAFFLE;
	flipped_v [ ABBAYE_U_5  ] = 0;
	flipped_v [ GUITAR2     ] = BAFFLE;
	flipped_v [ GUITAR1     ] = 0;
	flipped_v [ IGLU1       ] = IGLU3;
	flipped_v [ IGLU2       ] = IGLU4;
	flipped_v [ IGLU3       ] = IGLU1;
	flipped_v [ IGLU4       ] = IGLU2;
	flipped_v [ ESFINGE1    ] = ESFINGE3;
	flipped_v [ ESFINGE2    ] = ESFINGE4;
	flipped_v [ ESFINGE3    ] = ESFINGE1;
	flipped_v [ ESFINGE4    ] = ESFINGE2;
	flipped_v [ BIGPLESI1   ] = BIGPLESI3;
	flipped_v [ BIGPLESI2   ] = BIGPLESI4;
	flipped_v [ BIGPLESI3   ] = BIGPLESI1;
	flipped_v [ BIGPLESI4   ] = BIGPLESI2;
	flipped_v [ MURCIANO1   ] = MURCIANO3;
	flipped_v [ MURCIANO2   ] = MURCIANO4;
	flipped_v [ MURCIANO3   ] = MURCIANO1;
	flipped_v [ MURCIANO4   ] = MURCIANO2;
	flipped_v [ LAKE1       ] = LAKE3;
	flipped_v [ LAKE2       ] = LAKE4;
	flipped_v [ LAKE3       ] = LAKE1;
	flipped_v [ LAKE4       ] = LAKE2;

	for ( i = 0; i < LEVEL_HEIGHT; i++ )
	{
		for ( j = 0; j < LEVEL_WIDTH; j++ )
		{
			s16 jj = j;
			s16 ii = i;

			u16 object = level->grid[i][j];

			if ( _flip_h )
			{
				jj = 15 - j;

				if ( flipped_h [ object ] >= 0 )
				{
					object = flipped_h [ object ];
				}
			}

			if ( _flip_v )
			{
				ii = 10 - i;

				if ( flipped_v [ object ] >= 0 )
				{
					object = flipped_v [ object ];
				}
			}

			if ( object_is_bigboy ( object ) )
			{
				bigboy_set ( jj, ii, object );
			}

			ret.grid [ ii ] [ jj ] = object;
		}
	}

	return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////



LEVEL *level ()
{
   return (LEVEL*) level_list [ (u16)gamestate.current_ambiente ] [ gamestate_get_dificultad ( ) ].levels ;
}


LEVEL *level_get (  )
{
	return (LEVEL*) level_list [ (u16)gamestate.current_ambiente ] [ gamestate_get_dificultad ( ) ].levels [ gamestate.current_round ] ;
}



LEVEL level_init ( )
{
	_door         = (Vect2D_u16) { 20, 15 };
	_key          = (Vect2D_u16) { 20, 15 };
	_vram_pos[0]  = 0;
	_vram_pos[1]  = 0;
	_vscroll      = FIX16 ( 0 );
	_pal2         = 0;
	_pal3         = 0;
	_flip_h       = _flip_vh();
	_flip_v       = _flip_vh();

	LEVEL level = ( *level_list[ (u16)gamestate.current_ambiente][ gamestate_get_dificultad ( ) ].levels[gamestate.current_round] );
	level = _reorder_level ( &level );

	return level;
}



void level_draw ( LEVEL *level )
{
	SYS_disableInts();

	bool on_medallon = gamestate_on_medallon();
	//on_medallon = false;

	_vram_pos[0] = vram_new ( level->background->tileset->numTile );
	_vram_pos[1] = vram_new ( cb_ui.tileset->numTile );

	VDP_drawImageEx ( PLAN_B, level->background, TILE_ATTR_FULL(PAL0, false, false, false, _vram_pos[0]), 0, 0, false, 0 );

	level_draw_linedown  ( level );
	level_draw_ambiente_3 ( );
	level_draw_ambiente_4 ( );

	if ( !on_medallon )
	{
		level_draw_area ( level, 0, 0, LEVEL_WIDTH, LEVEL_HEIGHT );
	}

	preparePal ( PAL0, level->background->palette->data );
	preparePal ( PAL1, cb_ui.palette->data );
	preparePal ( PAL2, animation_get(_pal2)->res->pal );
	preparePal ( PAL3, animation_get(_pal3)->res->pal );

	// obtie el color 1 de la paleta 3, que será el color de las sombra de
	// los bloques y enemigos, y modifica la paleta de estos asignándoselo
	prepareColor ( 17, animation_get(_pal3)->res->pal[1] );

	_draw_marcador ();

	if ( on_medallon )
	{
		u16 tile = 800;
		u16 pal  = PAL3;
		VDP_loadTileData ( cb_poyete.tiles, tile, cb_poyete.width * cb_poyete.height, 0 );
		VDP_fillTileMapRectInc ( PLAN_A, TILE_ATTR_FULL ( pal, 0, 0, 0, tile ), 12, 7, cb_poyete.width, cb_poyete.height );
		preparePal ( pal, cb_poyete.pal );
	}

	SYS_enableInts();
}



void level_actualizar_marcador ( )
{
	u16 x = level_hpos_to_pixel ( _key.x );
	u16 y = level_vpos_to_pixel ( _key.y );

	if ( player(0)->key )
	{
		x = 128 + 16;
		y =   4;
	}

	s16 un = undo_rest ( 0 );

	if ( un < 0 )
	{
		un = 0;
	}

	VDP_setSpritePosition ( splist_key, x, y );

	const u16 pos_y [ 4 ] = { 11, 8, 5, 1 };
	VDP_setMapEx ( PLAN_A, cb_ui.map, TILE_ATTR_FULL(PAL1, false, false, false, _vram_pos[1]), 9, 1, 7, pos_y [ (u16) un ], 8, 3 );
}



void level_draw_area ( LEVEL *level, u8 x, u8 y, u8 width, u8 height )
{
	s16 j = x;
	s16 i = y;

	width  += x;
	height += y;

	for ( i = y; i < height; i++ )
	{
		for ( j = x; j < width; j++ )
		{
			u16  obj = level->grid [ i ] [ j ];

				 if ( object_is_door ( obj ) ) _door = ( Vect2D_u16 ) { j, i };
			else if ( object_is_key  ( obj ) ) _key  = ( Vect2D_u16 ) { j, i };

				 if ( !_pal2 && animation_get(obj)->pal == PAL2 ) _pal2 = obj;
			else if ( !_pal3 && animation_get(obj)->pal == PAL3 ) _pal3 = obj;

			animation_draw ( obj, j, i, false, PLAN_A, -1, 0, 0, _force_width, _force_height );
		}
	}
}




u16 level_get_object ( LEVEL *level, u8 x, u8 y )
{
	return level->grid[y][x];
}


void level_set_object ( LEVEL *level, u8 x, u8 y, u16 object )
{
	level->grid[y][x] = object;
}


void level_remove_object ( LEVEL *level, u8 x, u8 y )
{
	level->grid[y][x] = EMPTY;
}


Vect2D_u16 level_get_key ( )
{
	return (Vect2D_u16) _key;
}


Vect2D_u16 level_get_door ( )
{
	return (Vect2D_u16) _door;
}


void level_set_door ( u16 x, u16 y )
{
	_door.x = x ;
	_door.y = y ;
}

void level_set_key ( u16 x, u16 y )
{
	_key.x = x ;
	_key.y = y ;
}


void level_remove_key ( )
{
	_key.x = 24; // tile 40 y tantas: out of the screen

	_key.x = 0;
	_key.y = 0;
}


void level_draw_demon ( u16 x, u16 y, u8 ojos, u8 cola )
{
//	ojos = ojos ? 0 : 1;
//	cola = cola ? 2 : 3;
//
//	VDP_loadTileData ( w1s_demon.sprites [ ojos ], POS_SP_DEMON(0), SIZE_SP_DEMON, 0 );
//	VDP_loadTileData ( w1s_demon.sprites [ cola ], POS_SP_DEMON(1), SIZE_SP_DEMON, 0 );
//
//	VDP_setSprite ( 7, x +  0, y +  0, SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL1, 1, 0, 0, POS_SP_DEMON(0) ), 8 );
//	VDP_setSprite ( 8, x +  0, y + 16, SIZE_SP_DEMON, TILE_ATTR_FULL ( PAL1, 1, 0, 0, POS_SP_DEMON(1) ), 9 );
}


u16 level_vram_pos ( VDPPlan plan )
{
	return _vram_pos [ plan.value == PLAN_B.value ? 0 : 1 ] ;
}


void level_draw_linedown ( LEVEL *level  )
{
	if ( !level->line_down )
	{
		return;
	}

	u16 size    = level->line_down->size >> 8;
	u16 width   = level->line_down->width  >> 3;
	u16 height  = level->line_down->height >> 3;
	u16 nbTiles = level->line_down->count * width * height;

	u16 i       = 0;
	u16 pos_x   = 8 * 4;
	u16 pos_y   = VDP_getScreenHeight() - 16 ;
	u16 vrampos = vram_new ( nbTiles );

	SYS_disableInts();

	VDP_loadTileData ( level->line_down->sprites[0], vrampos, nbTiles, false );

	for ( i = 0; i < 8; i++ )
	{
		s8 sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
		VDP_setSpriteFull ( sp, pos_x, pos_y, size, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos ), sp + 1 );

		pos_x   += level->line_down->width;
		vrampos += width * height;
	}

	SYS_enableInts();
}


u16 level_get_music ( )
{
	u16 cuantas    = 0;
	u16 ambiente   = (u16) gamestate.current_ambiente;
	u16 dificultad = gamestate_get_dificultad ( );
	u16 round      = (u16) gamestate.current_round;

	while ( level_list [ ambiente ] [ dificultad ].musicas [ cuantas ] > 0 )
	{
		++cuantas ;
	}

	return level_list [ ambiente ] [ dificultad ].musicas [ round % cuantas ];
}


u16 level_get_head ( )
{
   return level_list [ (u16)gamestate.current_ambiente ] [ gamestate_get_dificultad ( ) ].head;
}


void level_update ( )
{
	if ( gamestate.current_ambiente == 4 )
	{
		_vscroll = fix16Sub ( _vscroll, 2.3 );

		s16 values[20] = { };
		s16 value = fix16ToInt ( _vscroll );

		values[0]  = values[1]  = +value; // baja
		values[18] = values[19] = -value; // sube

		VDP_setVerticalScrollTile(PLAN_A, 0, values, 20, 0 );
	}
}


void level_draw_ambiente_3 ( )
{
	if ( gamestate.current_ambiente != 3 )
	{
		return;
	}


	u8 x = 0;
	u8 y = 26;
	u16 aux;

	vobject_add ( SEA );
	aux = vobject_get ( SEA )->vram_pos;

	for ( x=0; x < 40; x+=4 )
	{
		u16 i, pos = aux;

		for ( i=0; i<4; i++ )
		{
			VDP_setTileMapXY ( PLAN_B, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos++ ), x + i, y + 0 );
			VDP_setTileMapXY ( PLAN_B, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos++ ), x + i, y + 1 );
		}
	}
}


void level_draw_ambiente_4 ( )
{
	if ( gamestate.current_ambiente != 4 )
	{
		return;
	}

	VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_2TILE );

	VDP_setMapEx ( PLAN_B, level_get()->background->map, TILE_ATTR_FULL(PAL0, true, 0, 0, level_vram_pos(PLAN_B)),  0, 0,  0, 0, 4, 28 );
	VDP_setMapEx ( PLAN_B, level_get()->background->map, TILE_ATTR_FULL(PAL0, true, 0, 0, level_vram_pos(PLAN_B)), 36, 0, 36, 0, 4, 28 );

	animation_draw ( LAVA1,  0,  0, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0,  4, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA1,  0,  8, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0, 12, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA1,  0, 16, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0, 20, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA1,  0, 24, true, PLAN_A, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0, 28, true, PLAN_A, false, 0, 0, 3, 4 );


	animation_draw ( LAVA2, 37,  0, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37,  4, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA2, 37,  8, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37, 12, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA2, 37, 16, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37, 20, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA2, 37, 24, true, PLAN_A, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37, 28, true, PLAN_A, false, 1, 1, 3, 4 );


	animation_draw ( VENTANA_1,   0,  0, true, PLAN_B, true,  0, 0, 2, 1 );
	animation_draw ( VENTANA_1,  38,  0, true, PLAN_B, true,  1, 0, 2, 1 );

	animation_draw ( VENTANA_2,   5,  0, true, PLAN_B, false, 0, 0, 4, 4 );
	animation_draw ( VENTANA_2,  31,  0, true, PLAN_B, false, 1, 0, 4, 4 );

	animation_draw ( VENTANA_3,  11,  0, true, PLAN_B, false, 0, 0, 4, 4 );
	animation_draw ( VENTANA_3,  26,  0, true, PLAN_B, false, 1, 0, 4, 4 );

	animation_draw ( VENTANA_4,  18,  2, true, PLAN_B, false, 0, 0, 4, 3 );




	u16 vrampos [ 4 ], nbTiles, sp;

	nbTiles = ( w4s_line_down_1.width  >> 3 ) * ( w4s_line_down_1.height >> 3 );
	vrampos [ 0 ] = vram_new ( nbTiles );
	VDP_loadTileData ( w4s_line_down_1.sprites[0], vrampos [ 0 ], nbTiles, false );

	nbTiles = ( w4s_line_down_2.width  >> 3 ) * ( w4s_line_down_2.height >> 3 );
	vrampos [ 1 ] = vram_new ( nbTiles );
	VDP_loadTileData ( w4s_line_down_2.sprites[0], vrampos [ 1 ], nbTiles, false );

	nbTiles = ( w4s_line_down_3.width  >> 3 ) * ( w4s_line_down_3.height >> 3 );
	vrampos [ 2 ] = vram_new ( nbTiles );
	VDP_loadTileData ( w4s_line_down_3.sprites[0], vrampos [ 2 ], nbTiles, false );

	nbTiles = ( w4s_line_down_4.width  >> 3 ) * ( w4s_line_down_4.height >> 3 );
	vrampos [ 3 ] = vram_new ( nbTiles );
	VDP_loadTileData ( w4s_line_down_4.sprites[0], vrampos [ 3 ], nbTiles, false );


	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp,  32, 192, w4s_line_down_1.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[0] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp,  55, 208, w4s_line_down_2.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[1] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp,  87, 208, w4s_line_down_3.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[2] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp, 119, 208, w4s_line_down_4.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[3] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp, 151, 208, w4s_line_down_2.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[1] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp, 183, 208, w4s_line_down_3.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[2] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp, 215, 208, w4s_line_down_4.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[3] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp, 247, 208, w4s_line_down_2.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos[1] ), sp + 1 );

	sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	VDP_setSpriteFull ( sp, 272, 192, w4s_line_down_1.size >> 8, TILE_ATTR_FULL ( PAL0, 0, 0, 1, vrampos[0] ), sp + 1 );
}



void level_presentation()
{
	displayInit();
	displayOff(0);

	SYS_disableInts();

	resetScreen();
	resetSprites();
	resetScroll();
	resetPalettes();




	musiclist_play ( MUSIC_NEW_ROUND );

	u16 *palette = font_getPalette ();

	VDP_setPaletteColor( PAL0+0, palette[0] );
	VDP_setPaletteColor( PAL0+1, palette[1] );
	VDP_setPaletteColor( PAL0+2, palette[2] );

	SYS_enableInts();



	u8   string [ 41 ];
	u16  ambiente = gamestate.current_ambiente;
	u8  *frase    = frases_find ( 1, ambiente );


	text_init ( (struct genresSprites *) &cs_font_16x16, 16, PAL0 );
	text_draw_sprites_x_centered ( frase,  88, 30 );


	ambiente = gamestate.current_round+1;
	frase    = frases_find ( 1, 7 );

	memcpy ( string, frase, strlen ( frase ) ) ;
	sprintf ( string, frase, ambiente );
	u16 sprite = text_draw_sprites_x_centered ( string, 120, 30 ) - 1;

	VDP_setSpriteLink ( sprite, 0 );
	VDP_updateSprites (80,1);


	waitMs ( 2000 );


	VDP_fadeOutAll ( 30, false );

	resetSprites();
	splist_reorder();
}


bool level_flipped_h ( )
{
	return _flip_h;
}


bool level_flipped_v ( )
{
	return _flip_v;
}


u16 level_find ( u16 object, LEVEL *level, Vect2D_u16 grid[] )
{
	u16 i, j, cnt=0;

	for ( i=0; i<LEVEL_HEIGHT; i++ )
	{
		for ( j=0; j<LEVEL_WIDTH; j++ )
		{
			if ( (*level).grid[i][j] == object )
			{
				grid [ cnt++ ] = (Vect2D_u16) { j, i };
			}
		}
	}

	return cnt;
}


void level_draw_animation ( u16 ani, u8 x, u8 y )
{
	animation_draw ( ani, x, y, false, PLAN_A, -1, 0, 0, _force_width, _force_height );

	_force_height = 0;
	_force_width  = 0;
}


void level_draw_animation_size ( u8 width, u8 height )
{
	_force_height = height;
	_force_width  = width;
}


