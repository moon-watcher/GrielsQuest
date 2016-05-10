#include "../inc/include.h"
#include "../inc/colores_textos.h"


#define SIZE        as_rounds_sprites_32x32.size   >> 8
#define TILES       ( as_rounds_sprites_32x32.width  >> 3 ) * ( as_rounds_sprites_32x32.height  >> 3 )
#define ATTR(pos)   TILE_ATTR_FULL ( PAL2, 1, 0, 0, POS_SPRITES + TILES * (pos) )
#define GETY(i)     ( (i) < 7 ? 159 : 190 )
#define GETX(i)     ( 16 + ( (i) < 7 ? (i) : (i)-7 ) * 8 * 5 )




static u16  index;
static u16  POS_SPRITES;
static u16  POS_TILES;
static u16  ambiente;
static s16  nivel;
static u16  cuantos;
static u16  superado;
static u16  flecha;
static u16  sprite;



static const struct
{
	u8         up;
	u8         down;
	u8         left;
	u8         right;
	Vect2D_u16 posicion;
}
datos [ 6 ] =
{
	{  2,  2,  1,  4, { 178,  5 } }, // 0
	{  3,  3,  5,  0, { 112, 20 } }, // 1
	{  0,  0,  3,  4, { 178, 50 } }, // 2
	{  1,  1,  5,  2, { 112, 60 } }, // 3
	{  0,  2,  0,  5, { 256, 00 } }, // 4
	{  1,  3,  4,  1, {  36, 30 } }  // 5
};







static void _show_title      ( );
static void _mostrar_niveles ( );
static void _selector_init   ( );
static void _selector_mover  ( s16 i );




static void _tt_init ()
{
	tt_init ( );

	tt_info.x         =  3;
	tt_info.y         = 21;
	tt_info.speed     =  1;
	tt_info.width     = 34;
	tt_info.height    =  5;
	tt_info.reset_pal = false;

	#undef  TT_POST_FN
	#define TT_POST_FN   VDP_updateSprites();


}




static void _init ( )
{
	_tt_init ();


   VDP_setEnable ( false );
	SYS_disableInts();

	u16 i, paleta[64];
	index = TILE_USERINDEX;

	VDP_setPalette ( PAL0, palette_black );
	VDP_setPalette ( PAL1, palette_black );
	VDP_setPalette ( PAL2, palette_black );
	VDP_setPalette ( PAL3, palette_black );

	resetScroll();
	resetScreen();
	resetSprites();


	VDP_drawImageEx ( BPLAN, &ob_ambiente_b_1, TILE_ATTR_FULL(PAL0, false, FALSE, FALSE, index),  0,  0, false, true ); index += ob_ambiente_b_1.tileset->numTile;
	VDP_drawImageEx ( APLAN, &ob_ambiente_a_1, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, index),  0,  0, false, true ); index += ob_ambiente_a_1.tileset->numTile;

	index += ob_ambiente_a_2.tileset->numTile;

	VDP_loadTileSet ( ob_ambiente_a_2.tileset, index, 0 );
	VDP_setMapEx ( APLAN, ob_ambiente_a_2.map, TILE_ATTR_FULL(PAL2, false, false, false, index),  0, 18,  0,  0, 40,  2 );
	VDP_setMapEx ( BPLAN, ob_ambiente_a_2.map, TILE_ATTR_FULL(PAL2, false, false, false, index), 11, 19, 11,  0, 18,  1 );
	VDP_setMapEx ( APLAN, ob_ambiente_a_2.map, TILE_ATTR_FULL(PAL2, false, false, false, index),  0, 20,  0,  2,  2,  6 );
	VDP_setMapEx ( APLAN, ob_ambiente_a_2.map, TILE_ATTR_FULL(PAL2, false, false, false, index), 38, 20, 38,  2,  2,  6 );
	VDP_setMapEx ( APLAN, ob_ambiente_a_2.map, TILE_ATTR_FULL(PAL2, false, false, false, index),  0, 26,  0,  8, 40,  2 );
	VDP_setMapEx ( BPLAN, ob_ambiente_a_2.map, TILE_ATTR_FULL(PAL2, false, false, false, index),  2, 20,  2,  2, 36,  6 );

	index += ob_ambiente_a_2.tileset->numTile;


	POS_SPRITES = index;
	VDP_loadTileData ( as_rounds_sprites_32x32.sprites[0], POS_SPRITES, TILES * as_rounds_sprites_32x32.count, true );

	POS_TILES = POS_SPRITES + TILES * as_rounds_sprites_32x32.count;
	VDP_loadTileSet ( ob_round_numbers.tileset, POS_TILES, 0 );

	index = POS_TILES + ob_round_numbers.tileset->numTile;
	text_init ( (struct genresSprites *) &cs_font_16x16, index, PAL3 );

	for ( i=0; i<16; i++ ) paleta[i+16*0] = ob_ambiente_b_1.palette->data[i];
	for ( i=0; i<16; i++ ) paleta[i+16*1] = ob_ambiente_a_1.palette->data[i];
	for ( i=0; i<16; i++ ) paleta[i+16*2] = ob_ambiente_a_2.palette->data[i];
	for ( i=0; i<16; i++ ) paleta[i+16*3] = font_getPalette()[i];//as_rounds_sprites_32x32.pal[i];

	VDP_setTextPalette ( PAL3 );
	_selector_init ( );
	_show_title();
	_mostrar_niveles ( );

	PASSWORD8 pwd;
	pwd8_generate(pwd);
	VDP_drawText ( "PASSWORD: ", 11, 19 );
	VDP_drawText ( pwd, 21, 19 );

	SYS_enableInts ( );
	VDP_setEnable ( true );

	musiclist_play ( MUSIC_MAP );

	VDP_fadeInAll ( paleta, 30, false );
}




static void _selector_init ( )
{
	_selector_mover ( -1 );
}




static void _selector_mover ( s16 i )
{
	s16 x = GETX(i);
	s16 y = GETY(i);

	if ( i > 6 )
	{
		x += 16;
		y -= 7;
	}

	if ( i<0 )
	{
		y = 240;
	}

	if ( i == 0 )
	{
		VDP_setSprite ( 1, 320, y, SIZE, ATTR(0), 2 );
	}
	else
	{
		VDP_setSprite ( 1, x-12, y, SIZE, ATTR(0), 2 );
	}

	VDP_setSprite ( 2, x-12, y, SIZE, ATTR(1), 3 );
	VDP_setSprite ( 3, x+20, y, SIZE, ATTR(2), 4 );
}




static void _show_title ( )
{
	sprite = 4;
	text_setNextSprite ( sprite );

   u8 *frase = frases_find ( 1, ambiente );
	sprite = text_draw_sprites_x_centered ( frase, 6, 0 ); // texto arriba
}





static void _mostrar_niveles (  )
{
	u16 i;

	//sprite = 4;


	SYS_disableInts();


	if ( ambiente == 5 )
	{
		VDP_fillTileMapRect(APLAN, 0, 2, 20, 36, 6 );
		VDP_fillTileMapRect(BPLAN, 0, 2, 20, 36, 6 );

		SYS_enableInts();


		VDP_waitVSync();
		VDP_updateSprites();


		VDP_setTextPalette ( PAL1 );

		_tt_init ( );
		tt_info.wait = 0;
		tt_info.reset_area_at_end = false;
		tt_write ( GRIEL, frases_find ( 1, 6 ) );

		return;
	}



	// borra el texto en caso de que lo haya
	VDP_clearTileMapRect ( APLAN, 2, 20, 36, 6 );


	cuantos  = level_list [ ambiente ] [ gamestate.dificultad ].cuantos;
	superado = gamestate.ambientes [ ambiente ];

	// si ha superado el nivel y matado al monstruo el superado tiene el valor "cuantos"
	u8 resta = ( superado == cuantos ) ? 1 : 0;

	// pone las flechas intermedias
	for ( i = 0; i < superado - resta; i++ )
	{
		u16 x    = GETX(i)+28;
		u16 y    = GETY(i);
		u16 tile = 3;

		if ( i == 6 )
		{
			VDP_setSprite ( sprite, GETX(i+1)+4, GETY(i+1)-7, SIZE, ATTR(tile), sprite+1 );
			++sprite;

			tile = 6;
		}

		if ( i > 6 )
		{
			x += 16;
			y -= 7;
		}

		VDP_setSprite ( sprite, x, y, SIZE, ATTR(tile), sprite+1 );
		++sprite;
	}

	--sprite;
	vdpSpriteCache[sprite].link = 0;




	// dibuja los numeros, candados y caras
	for ( i=0; i<14; i++ )
	{
		u16 x = GETX(i);
		u16 y = GETY(i);

		if ( i >  6 )
		{
			x += 16;
			y -= 10;
		}

		x = x / 8;
		y = y / 8 + 1;

		u16 tile = i * 4;

		if ( i >  superado    ) tile = 14 * 4;
		if ( i >= cuantos     ) tile = 13 * 4;
		if ( i == cuantos - 1 )
		{
			tile = 15 * 4;

			if ( superado == i       ) tile = 16 * 4;
			if ( superado == cuantos ) tile = 17 * 4;
		}

		VDP_setMapEx ( APLAN, ob_round_numbers.map, TILE_ATTR_FULL(PAL2, 0, false, false, POS_TILES), x, y, tile, 0, 4, 3 );
	}

	VDP_updateSprites ( );

	SYS_enableInts();
}




static u16 _loop_niveles ( )
{
	u16 to = 0;

	psglist_play ( 5 ); // 4,5 seleecionada // 8


	// vamos a casa del Nota a que nos dé unos consejos
	if ( ambiente == 5 )
	{
		return SCREEN_JUMP_TO_INTRO5;
	}


	// si has matado al boss
	if ( superado == cuantos )
	{
		--superado;
	}

	_selector_mover ( superado );

	nivel = superado;




	while ( true )
	{
		JoyReader_update();


		// jugar ese nivel
		if ( joy1_pressed_a || joy1_pressed_c || joy1_pressed_start )
		{
			if ( !gamestate.visito_la_puerta  &&  ambiente < 4 )
			{
				// pone los mensajes graciosos antes de ir al volcan
				SYS_disableInts();

				_selector_init ( );
				VDP_updateSprites();

				VDP_clearTileMapRect ( APLAN, 2, 20, 36, 6 );
				VDP_clearTileMapRect ( BPLAN, 2, 20, 36, 6 );

				SYS_enableInts();


				u16 f = ambiente;

				// cambia el texto 1 de cada 3 veces
				if ( random() % 3 == 0 )
				{
					f = 4 + ( random() % 12 ) ;
				}

				VDP_setTextPalette ( PAL1 );

				_tt_init ( );
				tt_write ( GRIEL, frases_find ( 6, f ) );

				_mostrar_niveles ( ) ;
			}
			else
			{
				to = SCREEN_JUMP_TO_NEWGAME;

				if ( screens_puerta_have_to_show ( ambiente ) )
				{
					to = SCREEN_JUMP_TO_PUERTA;
				}

				gamestate.current_round    = nivel;
				gamestate.ambiente = ambiente;

				psglist_play ( 3 );
			}

			break;
		}


		// mueve el joy por los niveles disponibles
		else if ( joy1_pressed_dir )
		{
			psglist_play(3);

			u16 saved = nivel;
			u16 linea = nivel / 7;

			u16 linea1_min = 0;
			u16 linea1_max = MIN ( MIN(cuantos-1, 6), superado ) ;
			u16 linea2_min = cuantos >= 7 ? 7 : 0;
			u16 linea2_max = cuantos >= 7 ? MAX(superado, 7) : 0;

			if ( joy1_active_right )
			{
				++nivel;

				if ( linea == 0  &&  nivel > linea1_max ) nivel = linea1_min;
				if ( linea == 1  &&  nivel > linea2_max ) nivel = linea2_min;
			}

			else if ( joy1_active_left  )
			{
				--nivel;

				if ( linea == 0  &&  nivel < linea1_min ) nivel = linea1_max;
				if ( linea == 1  &&  nivel < linea2_min ) nivel = linea2_max;
			}

			else if ( joy1_active_up  ||  joy1_active_down )
			{
				if ( linea == 1 )
				{
					nivel -= 7;
				}
				else if ( nivel+7 <= linea2_max )
				{
					nivel += 7;
				}
			}


			if ( nivel > superado )
			{
				nivel = saved;
			}

			_selector_mover ( nivel );
		}


		// sale de elegir el nivel
		else if ( joy1_pressed_b )
		{
			psglist_play ( 1 );
			_selector_init  ( );

			break;
		}


		VDP_updateSprites();
		VDP_waitVSync();
	}

	return to;
}






static u16 _loop ( )
{
	u16 to = 0;

	while ( !to )
	{
		JoyReader_update ( );

		if ( joy1_pressed_dir )
		{
			     if ( joy1_pressed_up    ) ambiente = datos[ambiente].up;
			else if ( joy1_pressed_down  ) ambiente = datos[ambiente].down;
			else if ( joy1_pressed_left  ) ambiente = datos[ambiente].left;
			else if ( joy1_pressed_right ) ambiente = datos[ambiente].right;

			psglist_play ( 3 ); // 4,5 seleecionada // 8

			flecha = 0;
			_show_title ( );
			_mostrar_niveles ( ) ;
		}

		else if ( joy1_pressed_a || joy1_pressed_c || joy1_pressed_start )
		{
			vint_setFlechaMap ( false );

			to = _loop_niveles ( );

			vint_setFlechaMap ( true );
		}

		VDP_updateSprites();
		VDP_waitVSync();
	}

	return to;
}





u16 screens_ambiente ( )
{
	music_stop();


	flecha = 0;
	ambiente = gamestate.ambiente;


	_init();

	vint_setFlechaMap ( true );

	u16 to = _loop ( );


	waitMs ( 500 );
	vint_setFlechaMap ( false );
	music_stop ( );

	VDP_fadeOutAll ( 30, false );
	waitMs ( 500 ); // pausa valorativa


	return to;
}



void screens_ambiente_flecha ( )
{

	VDP_setSprite ( 0, datos[ambiente].posicion.x, datos[ambiente].posicion.y + flecha/3, SIZE, ATTR(4), 1 );

	++flecha;
	flecha %= 30;
}
