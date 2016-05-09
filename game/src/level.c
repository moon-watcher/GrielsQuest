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




static Vect2D_u16  _key ;
static Vect2D_u16  _door ;
static u16         _vram_pos[2];
static fix16       _vscroll;
static u16         _pal2;
static u16         _pal3;
static bool        _flip_h;
static bool        _flip_v;
static u16         _wait_by_line;
static u16         _marcador_x_pos;

static u8 _force_width  = 0;
static u8 _force_height = 0;







static void _find_bigboys ( LEVEL level, u8 x, u8 y, u8 width, u8 height )
{
	s16 j, i;

	for ( i = y; i < height + y; i++ )
	{
		for ( j = x; j < width + x; j++ )
		{
			u16 object = level.grid[i][j];

			if ( object_is_bigboy ( object ) )
			{
				bigboy_set ( j, i, object );
			}
		}
	}
}


LEVEL _reorder_level_ ( LEVEL *level )
{
	s16 j, i;

	LEVEL ret = *level;

	for ( i = 0; i < LEVEL_HEIGHT; i++ )
	{
		for ( j = 0; j < LEVEL_WIDTH; j++ )
		{
			u16 object = level->grid[i][j];

			s16 jj = _flip_h ? 15 - j : j;
			s16 ii = _flip_v ? 10 - i : i;

			ret.grid [ ii ] [ jj ] = object;
		}
	}

	return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////



LEVEL *level ()
{
   return (LEVEL*) level_list [ (u16)gamestate.ambiente ] [ (u16)gamestate.dificultad ].levels ;
}


LEVEL *level_get (  )
{
	return (LEVEL*) level_list [ (u16)gamestate.ambiente ] [ (u16)gamestate.dificultad ].levels [ gamestate.round ] ;
}



LEVEL level_init ( bool flip_h, bool flip_v )
{
	_door         = (Vect2D_u16) { 20, 15 };
	_key          = (Vect2D_u16) { 20, 15 };
	_vram_pos[0]  = 0;
	_vram_pos[1]  = 0;
	_vscroll      = FIX16 ( 0 );
	_pal2         = 0;
	_pal3         = 0;

	_flip_h       = flip_h;
	_flip_v       = flip_v;

	_wait_by_line = 0;

	LEVEL level = ( *level_list[ (u16)gamestate.ambiente][(u16)gamestate.dificultad].levels[gamestate.round] );
	level = _reorder_level_ ( &level );

	_find_bigboys ( level, 0, 0, 16, 11 );

	_marcador_x_pos = 2;

	return level;
}



void level_draw ( )
{
	SYS_disableInts();

	LEVEL level = ( *level_list [ (u16)gamestate.ambiente ] [ gamestate.dificultad ].levels [ gamestate.round ] );
	level = _reorder_level_ ( &level );

	_vram_pos[0] = vram_new ( level.background->tileset->numTile );
	_vram_pos[1] = vram_new ( cb_ui.tileset->numTile );

	VDP_drawImageEx ( BPLAN, level.background, TILE_ATTR_FULL(PAL0, false, false, false, _vram_pos[0]), 0, 0, false, true );

	level_draw_linedown  ( &level );
	level_draw_lineleft  ( &level );
	level_draw_lineright ( &level );

	level_draw_ambiente_3 ( );
	level_draw_ambiente_4 ( );

	level_draw_area ( level, 0, 0, LEVEL_WIDTH, LEVEL_HEIGHT, true );
	VDP_updateSprites ( );


	// obtie el color 1 de la paleta 3, que será el color de las sombra de
	// los bloques y enemigos, y modifica la paleta de estos asignándoselo

	u16 pal0[16], pal1[16], pal2[16], pal3[16];

	memcpyU16 ( pal0, level.background->palette->data, 16 );
	memcpyU16 ( pal1, cb_ui.palette->data,             16 );
	memcpyU16 ( pal2, animation_get(_pal2)->res->pal,     16 );
	memcpyU16 ( pal3, animation_get(_pal3)->res->pal,     16 );

	pal1[1] = pal3[1];

	//


	// dibuja el marcador
	VDP_loadTileSet ( cb_ui.tileset, _vram_pos[1], true );
	VDP_setMapEx ( APLAN,cb_ui.map, TILE_ATTR_FULL(PAL1, false, false, false, _vram_pos[1]),  _marcador_x_pos,  0,  0,  0,  19,  5 );
	//

	vobject_update ( );

	fadeIn ( pal0, pal1, pal2, pal3, 30, false );

	SYS_enableInts();
}



void level_actualizar_marcador ( )
{
	u16 x = level_hpos_to_pixel ( _key.x );
	u16 y = level_vpos_to_pixel ( _key.y );

	if ( player(0)->key )
	{
		x = 128 + _marcador_x_pos * 8;
		y =   4;
	}

	s16 un = undo_rest ( 0 );

	if ( un < 0 )
	{
		un = 0;
	}

	VDP_setSpritePosition ( splist_key, x, y );

	const u16 pos_y [ 4 ] = { 11, 8, 5, 1 };
	VDP_setMapEx ( APLAN, cb_ui.map, TILE_ATTR_FULL(PAL1, false, false, false, _vram_pos[1]), _marcador_x_pos+7, 1, 7, pos_y [ (u16) un ], 8, 3 );
}



void level_draw_area ( LEVEL level, u8 x, u8 y, u8 width, u8 height, bool animation )
{
	u16 j, i;


	for ( i = y; i < height + y; i++ )
	{
		for ( j = x; j < width + x; j++ )
		{
			u16 obj = level.grid [ i ] [ j ];
			u16 pal = animation_get(obj)->pal;

			if ( object_is_door ( obj ) ) _door = ( Vect2D_u16 ) { j, i };
			if ( object_is_key  ( obj ) ) _key  = ( Vect2D_u16 ) { j, i };

			if ( !_pal2 && pal == PAL2 ) _pal2 = obj;
			if ( !_pal3 && pal == PAL3 ) _pal3 = obj;

			level_draw_animation ( obj, j, i );
		}

		if ( _wait_by_line )
		{
			waitMs(_wait_by_line);
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


u16 level_current ()
{
	return gamestate.round;
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


u16 level_vram_pos ( u16 plan )
{
	return _vram_pos [ plan == BPLAN ? 0 : 1 ] ;
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
	u16 sprites = level->line_down->count * width * height;

	u16 i       = 0;
	u16 pos_x   = 8 * 4;
	u16 pos_y   = VDP_getScreenHeight() - height*8 ;
	u16 vrampos = vram_new ( sprites );

	VDP_loadTileData ( level->line_down->sprites[0], vrampos, sprites, false );

	for ( i = 0; i < 8; i++ )
	{
		s8 sp = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
      //VDP_setSprite ( sp, pos_x, pos_y, size, TILE_ATTR_FULL ( PAL0, 1, 0, 0, vrampos ), sp + 1 ); // hace que estos sprites queden por encima del howtoplay
      VDP_setSprite ( sp, pos_x, pos_y, size, TILE_ATTR_FULL ( PAL0, 0, 0, 0, vrampos ), sp + 1 ); // hace que estos sprites queden por debajo del howtoplay

		pos_x   += level->line_down->width;
		vrampos += width * height;
	}
}


void level_draw_lineleft  ( LEVEL *level )
{
	return;



   if ( !level->line_left )
   {
      return;
   }

	const u8 size    = level->line_left->size   >> 8;
	const u8 width   = level->line_left->width  >> 3;
	const u8 height  = level->line_left->height >> 3;
	const u8 sprites = level->line_left->count * width * height;

	u8  i       = 0;
	u16 pos_x   = 8 * 4;
	u16 pos_y   = 8 * 4;
	u16 vrampos = 	vram_new ( sprites );

	VDP_loadTileData ( level->line_left->sprites[0], vrampos, sprites, false );

	u8 inicio = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	u8 fin    = inicio + 5;

	for ( i = inicio; i < fin; i++ )
	{
		VDP_setSprite ( i, pos_x, pos_y, size, TILE_ATTR_FULL ( PAL0, 1, 0, 0, vrampos ), i + 1 );

		pos_y   += level->line_left->height;
		vrampos += width * height;
	}
}


void level_draw_lineright ( LEVEL *level )
{
	return;



   if ( !level->line_right )
   {
      return;
   }

	const u8 size    = level->line_right->size   >> 8;
	const u8 width   = level->line_right->width  >> 3;
	const u8 height  = level->line_right->height >> 3;
	const u8 sprites = level->line_right->count * width * height;

	u8  i       = 0;
	u16 pos_x   = 8 * 35;
	u16 pos_y   = 8 * 4;
	u16 vrampos = vram_new ( sprites );

	VDP_loadTileData ( level->line_right->sprites[0], vrampos, sprites, false );

	u8 inicio = sd_new ( FIRST_SPRITE_BASE, SD_DOWN );
	u8 fin    = inicio + 5;

	for ( i = inicio; i < fin; i++ )
	{
		VDP_setSprite ( i, pos_x, pos_y, size, TILE_ATTR_FULL ( PAL0, 1, 0, 0, vrampos ), i + 1 );

		pos_y   += level->line_right->height;
		vrampos += width * height;
	}
}


u16 level_get_max_rounds ( )
{
   return level_list[(u16)gamestate.ambiente][(u16)gamestate.dificultad].cuantos;
}


u16 level_get_music ( )
{
	u16 cuantas    = 0;
	u16 ambiente   = (u16) gamestate.ambiente;
	u16 dificultad = (u16) gamestate.dificultad;
	u16 round      = (u16) gamestate.round;

	while ( level_list [ ambiente ] [ dificultad ].musicas [ cuantas ] > 0 )
	{
		++cuantas ;
	}

	return level_list [ ambiente ] [ dificultad ].musicas [ round % cuantas ];
}


u16 level_get_head ( )
{
   return level_list[(u16)gamestate.ambiente][(u16)gamestate.dificultad].head;
}


void level_update ( )
{
	if ( gamestate.ambiente == 4 )
	{
		_vscroll = fix16Sub ( _vscroll, 2.3 );

		s16 values[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		s16 value = fix16ToInt ( _vscroll );

		values[0]  = values[1]  = +value; // baja
		values[18] = values[19] = -value; // sube

		VDP_setVerticalScrollTile(PLAN_A, 0, values, 20, 0 );
	}
}


void level_draw_ambiente_3 ( )
{
   if ( gamestate.ambiente != 3 )
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
			VDP_setTileMapXY ( BPLAN, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos++ ), x + i, y + 0 );
			VDP_setTileMapXY ( BPLAN, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos++ ), x + i, y + 1 );
		}
	}
}


void level_draw_ambiente_4 ( )
{
   if ( gamestate.ambiente != 4 )
   {
   	return;
   }

	VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_2TILE );

	VDP_setMapEx ( BPLAN, level_get()->background->map, TILE_ATTR_FULL(PAL0, true, 0, 0, level_vram_pos(BPLAN)),  0, 0,  0, 0, 4, 28 );
	VDP_setMapEx ( BPLAN, level_get()->background->map, TILE_ATTR_FULL(PAL0, true, 0, 0, level_vram_pos(BPLAN)), 36, 0, 36, 0, 4, 28 );

	animation_draw ( LAVA1,  0,  0, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0,  4, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA1,  0,  8, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0, 12, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA1,  0, 16, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0, 20, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA1,  0, 24, true, APLAN, false, 0, 0, 3, 4 );
	animation_draw ( LAVA2,  0, 28, true, APLAN, false, 0, 0, 3, 4 );


	animation_draw ( LAVA2, 37,  0, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37,  4, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA2, 37,  8, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37, 12, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA2, 37, 16, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37, 20, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA2, 37, 24, true, APLAN, false, 1, 1, 3, 4 );
	animation_draw ( LAVA1, 37, 28, true, APLAN, false, 1, 1, 3, 4 );


	animation_draw ( VENTANA_1,   0,  0, true, BPLAN, true,  0, 0, 2, 1 );
	animation_draw ( VENTANA_1,  38,  0, true, BPLAN, true,  1, 0, 2, 1 );

	animation_draw ( VENTANA_2,   5,  0, true, BPLAN, false, 0, 0, 4, 4 );
	animation_draw ( VENTANA_2,  31,  0, true, BPLAN, false, 1, 0, 4, 4 );

	animation_draw ( VENTANA_3,  11,  0, true, BPLAN, false, 0, 0, 4, 4 );
	animation_draw ( VENTANA_3,  26,  0, true, BPLAN, false, 1, 0, 4, 4 );

	animation_draw ( VENTANA_4,  18,  2, true, BPLAN, false, 0, 0, 4, 3 );
}



void level_presentation()
{
	musiclist_play ( MUSIC_NEW_ROUND );

	u16 *palette = font_getPalette ();

	VDP_setPaletteColor( PAL0+0, palette[0] );
	VDP_setPaletteColor( PAL0+1, palette[1] );
	VDP_setPaletteColor( PAL0+2, palette[2] );


	u8   string [ 41 ];
	u16  ambiente = gamestate.ambiente + 1;
	u8  *frase    = frases_find ( 1, ambiente );


	text_init ( (struct genresSprites *) &cs_font_16x16, 16, PAL0 );
	text_draw_sprites_x_centered ( frase,  88, 30 );


	ambiente = gamestate.ambientes [ gamestate.ambiente ] + 1;
	frase    = frases_find ( 1, 7 );

	memcpy ( string, frase, strlen ( frase ) ) ;
	sprintf ( string, frase, ambiente );
	u16 sprite = text_draw_sprites_x_centered ( string, 120, 30 );
	--sprite;

   vdpSpriteCache [ sprite ].link = 0;
	VDP_setSpriteP ( sprite, &vdpSpriteCache [ sprite ] );
	VDP_updateSprites ( );


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


void level_wait_by_line ( u16 wait )
{
	_wait_by_line = wait;
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


s16 level_hpos_to_pixel ( s16 x )
{
	return x * 8 * 2 + voffset_horizontal_get() - 0;
}


s16 level_vpos_to_pixel ( s16 y )
{
	return y * 8 * 2 + voffset_vertical_get()   - 8; // el -8 es para compensar la altuta extra (+8px) respecto a los bloques, armas y enemigos
}


void level_draw_animation ( u16 ani, u8 x, u8 y )
{
	animation_draw ( ani, x, y, false, APLAN, -1, 0, 0, _force_width, _force_height );

	_force_height = 0;
	_force_width  = 0;
}


void level_draw_animation_size ( u8 width, u8 height )
{
	_force_height = height;
	_force_width  = width;
}


