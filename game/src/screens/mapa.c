#include "../inc/include.h"
#include "../inc/colores_textos.h"
#include "../inc/genres_externs.h"


#define SIZE        as_rounds_sprites_32x32.size   >> 8
#define TILES       ( as_rounds_sprites_32x32.width  >> 3 ) * ( as_rounds_sprites_32x32.height  >> 3 )
#define ATTR(pos)   TILE_ATTR_FULL ( PAL2, 1, 0, 0, POS_SPRITES + TILES * (pos) )
#define GETY(i)     ( (i) < 7 ? 159 : 190 )
#define GETX(i)     ( 16 + ( (i) < 7 ? (i) : (i)-7 ) * 8 * 5 )

#define FIRST_SPRITE_TEXT 4


static u16  index = 0;
static u16  POS_SPRITES = 0;
static u16  POS_TILES = 0;
static s8   ambiente = 0;
static s16  nivel = 0;
static u16  cuantos = 0;
static u16  superado = 0;
static u16  flecha = 0;
static u16  sprite = 0;
static u16  sprites[6] = {};
static u16  sprite_last_letter = 0;
static u16  _counter     = 0;
static u16  _counter_sp1 = 0;
static u16  _counter_sp2 = 0;
static u16  _selector_inc = 0;
static bool jump_loop_niveles = false;


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





#define WRITE(COLOR, STR)                                      \
	for (u16 i = 0, l = typetext_write_init(COLOR, STR); i < l; i++) \
		typetext_write_process(i, STR);





static void _mostrar_niveles ( );



static void _update_sprites ()
{
	++_counter;


	if (_counter % 10 == 0 )
	{
		++_counter_sp1;
		_counter_sp1 %= 7;

		SYS_disableInts();
		VDP_loadTileData ( as_sprites_16x16.sprites[0+_counter_sp1], sprites[0], 4, 0 );
		SYS_enableInts();
	}


	if (_counter % 60 == 0 )
	{
		++_counter_sp2;
		_counter_sp2 %= 7;

		SYS_disableInts();
		VDP_loadTileData ( as_sprites_16x16.sprites[7+_counter_sp2], sprites[1], 4, 0 );
		SYS_enableInts();
	}
}




static void _init_tt ()
{
	typetext_init ( );
	struct typetext *const tt_info = typetext_get();

	tt_info->x         =  3;
	tt_info->y         = 21;
	tt_info->speed     =  1;
	tt_info->width     = 34;
	tt_info->height    =  5;
	tt_info->reset_pal = false;
}



static void _show_title ( )
{
	sprite = FIRST_SPRITE_TEXT;
	bigtext_setSprite ( sprite );

	u8 *frase = frases_find ( 1, ambiente );
	sprite = bigtext_drawSprite_Xcentered ( frase, 6, 0 ); // texto arriba
	sprite_last_letter = sprite;
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
		VDP_setSpriteFull ( 1, 320, y, SIZE, ATTR(0), 2 );
	}
	else
	{
		VDP_setSpriteFull ( 1, x-12, y, SIZE, ATTR(0), 2 );
	}

	VDP_setSpriteFull ( 2, x-12, y, SIZE, ATTR(1), 3 );
	VDP_setSpriteFull ( 3, x+20, y, SIZE, ATTR(2), 4 );

	u8 hz = getHz()/2;

	++_selector_inc;

	if ( _selector_inc > hz )
    {
        vdpSpriteCache[1].x = 3;
        vdpSpriteCache[2].x = 3;
        vdpSpriteCache[3].x = 3;

        if ( _selector_inc == hz+hz/3 )
        {
            _selector_inc = 0;
        }
    }
}


static void _selector_init ( )
{
    _selector_inc = 0;
	_selector_mover ( -1 );
}


static void _init ( )
{
    _init_tt ();
	index = TILE_USER_INDEX;

	sprites[0] = index; index += 4;
	sprites[1] = index; index += 4;


	displayInit();
	displayOff(0);

	SYS_disableInts();

	resetPalettes();
	resetScroll();
	resetScreen();
	resetSprites();

	VDP_drawImageEx ( BG_B, &ob_ambiente_b_1, TILE_ATTR_FULL(PAL0, false, FALSE, FALSE, index),  0,  0, false, 0 ); index += ob_ambiente_b_1.tileset->numTile;
	VDP_drawImageEx ( BG_A, &ob_ambiente_a_1, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, index),  0,  0, false, 0 ); index += ob_ambiente_a_1.tileset->numTile;

	index += ob_ambiente_a_2.tileset->numTile;

	VDP_loadTileSet ( ob_ambiente_a_2.tileset, index, 0 );
	VDP_setMapEx ( BG_A, ob_ambiente_a_2.tilemap, TILE_ATTR_FULL(PAL2, false, false, false, index),  0, 18,  0,  0, 40,  2 );
	VDP_setMapEx ( BG_B, ob_ambiente_a_2.tilemap, TILE_ATTR_FULL(PAL2, false, false, false, index), 11, 19, 11,  0, 18,  1 );
	VDP_setMapEx ( BG_A, ob_ambiente_a_2.tilemap, TILE_ATTR_FULL(PAL2, false, false, false, index),  0, 20,  0,  2,  2,  6 );
	VDP_setMapEx ( BG_A, ob_ambiente_a_2.tilemap, TILE_ATTR_FULL(PAL2, false, false, false, index), 38, 20, 38,  2,  2,  6 );
	VDP_setMapEx ( BG_A, ob_ambiente_a_2.tilemap, TILE_ATTR_FULL(PAL2, false, false, false, index),  0, 26,  0,  8, 40,  2 );
	VDP_setMapEx ( BG_B, ob_ambiente_a_2.tilemap, TILE_ATTR_FULL(PAL2, false, false, false, index),  2, 20,  2,  2, 36,  6 );

	index += ob_ambiente_a_2.tileset->numTile;


	POS_SPRITES = index;
	VDP_loadTileData ( as_rounds_sprites_32x32.sprites[0], POS_SPRITES, TILES * as_rounds_sprites_32x32.count, 0 );

	POS_TILES = POS_SPRITES + TILES * as_rounds_sprites_32x32.count;
	VDP_loadTileSet ( ob_round_numbers.tileset, POS_TILES, 0 );

	index = POS_TILES + ob_round_numbers.tileset->numTile;
	bigtext_init ( (struct genresSprites *) &cs_font_16x16, index, PAL3 );





	VDP_loadTileData ( as_sprites_16x16.sprites[0], sprites[0], 4, 0 );
	VDP_loadTileData ( as_sprites_16x16.sprites[7], sprites[1], 4, 0 );

	VDP_setSpriteFull ( 74, 242,  28, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1,1,0,0,sprites[0]), 75 );
	VDP_setSpriteFull ( 75, 160,  80, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1,1,0,0,sprites[0]), 76 );
	VDP_setSpriteFull ( 76, 230,  35, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1,1,0,0,sprites[0]), 77 );
	VDP_setSpriteFull ( 77,  40,  44, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1,1,0,0,sprites[0]), 78 );
	VDP_setSpriteFull ( 78,  30,  40, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1,1,0,0,sprites[0]), 79 );
	VDP_setSpriteFull ( 79,  90, 128, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1,1,0,0,sprites[1]), 0 );


	preparePal ( PAL0, ob_ambiente_b_1.palette->data );
	preparePal ( PAL1, ob_ambiente_a_1.palette->data );
	preparePal ( PAL2, ob_ambiente_a_2.palette->data );
	preparePal ( PAL3, font_getPalette() );


	VDP_setTextPalette ( PAL3 );
	_selector_init ( );
	_show_title();
	_mostrar_niveles ( );

	PASSWORD8 pwd;
	pwd8_generate(pwd);

	frases_init(29);
	TEXT_drawText ( frases_next(), 11, 19 );
	TEXT_drawText ( ":", 19, 19 );
	TEXT_drawText ( pwd, 21, 19 );

	SYS_enableInts ( );

	music_stop();

	displayOn(30);

	musiclist_play ( MUSIC_MAP );
}



static void _mostrar_niveles (  )
{
	u16 i;

	// borra el foreground (candados y cuadrados completados)
	SYS_disableInts();
	VDP_fillTileMapRect(BG_A, 0, 2, 20, 36, 6 );
	SYS_enableInts();

	if ( ambiente == 5 )
	{
		// borra el fondo (los cuadrados vacíos)
		SYS_disableInts();
		VDP_fillTileMapRect(BG_B, 0, 2, 20, 36, 6 );


		vdpSpriteCache [ sprite-1 ].link = 74; //0;

		SYS_doVBlankProcess();
		VDP_updateSprites(80,1);
		VDP_setTextPalette ( PAL1 );

		SYS_enableInts();

		_init_tt ( );
		struct typetext *const tt_info = typetext_get();
		tt_info->wait = 0;
		tt_info->reset_area_at_end = false;
		WRITE ( GRIEL, frases_find ( 1, 6 ) );

		return;
	}



	SYS_disableInts();

	cuantos  = level_list [ (u8)ambiente ] [ gamestate_get_dificultad () ].cuantos;
	superado = gamestate.ambientes [ (u8)ambiente ];

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
			VDP_setSpriteFull ( sprite, GETX(i+1)+4, GETY(i+1)-7, SIZE, ATTR(tile), sprite+1 );
			++sprite;

			tile = 6;
		}

		if ( i > 6 )
		{
			x += 16;
			y -= 7;
		}

		VDP_setSpriteFull ( sprite, x, y, SIZE, ATTR(tile), sprite+1 );
		++sprite;
	}


	//--sprite; vdpSpriteCache[sprite].link = 0;

	vdpSpriteCache[sprite-1].link = 74;

	//vdpSpriteCache[sprite].link = 0;




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

		VDP_setMapEx ( BG_A, ob_round_numbers.tilemap, TILE_ATTR_FULL(PAL2, 0, false, false, POS_TILES), x, y, tile, 0, 4, 3 );
	}


	VDP_updateSprites (80,1);

	SYS_enableInts();
}




static u16 _loop_niveles ( )
{
	u16 to = 0;

	psglist_play ( 5 ); // 4,5 seleecionada // 8


	// vamos a casa del Nota a que nos dá unos consejos
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

				vdpSpriteCache[0].link = FIRST_SPRITE_TEXT;
				vdpSpriteCache[sprite_last_letter-1].link = 0;
				_selector_init ( );
				VDP_updateSprites(80,1);


				VDP_clearTileMapRect ( BG_A, 2, 20, 36, 6 );
				VDP_clearTileMapRect ( BG_B, 2, 20, 36, 6 );

				VDP_setTextPalette ( PAL1 );

				SYS_enableInts();


				u16 f = ambiente;

				// cambia el texto 1 de cada 3 veces
				if ( random() % 3 == 0 )
				{
					f = 4 + ( random() % 13 ) ;
				}

				_init_tt ( );
				WRITE ( GRIEL, frases_find ( 6, f ) );

				vdpSpriteCache[sprite_last_letter-1].link = sprite_last_letter;
				VDP_updateSprites(80,1);

				_mostrar_niveles ( ) ;
			}
			else
			{
				to = SCREEN_JUMP_TO_NEWGAME;

				if ( screen_puerta_have_to_show ( ambiente ) )
				{
					to = SCREEN_JUMP_TO_PUERTA;
				}

				gamestate.current_round    = nivel;
				gamestate.current_ambiente = ambiente;

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

            _selector_inc = 0;
		}


		// sale de elegir el nivel
		else if ( joy1_pressed_b )
		{
			psglist_play ( 1 );
			_selector_init ( );

			jump_loop_niveles = false;

			break;
		}

		_selector_mover ( nivel );

		_update_sprites ();

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}

	return to;
}






static u16 _loop_main ( )
{
	u16 to = 0;


	while ( !to )
	{
		JoyReader_update ( );

		if ( jump_loop_niveles || joy1_pressed_a || joy1_pressed_c || joy1_pressed_start )
		{
			to = _loop_niveles ( );
		}

		else if ( joy1_pressed_dir )
		{
				 if ( joy1_pressed_up    ) ambiente = datos[(u8)ambiente].up;
			else if ( joy1_pressed_down  ) ambiente = datos[(u8)ambiente].down;
			else if ( joy1_pressed_left  ) ambiente = datos[(u8)ambiente].left;
			else if ( joy1_pressed_right ) ambiente = datos[(u8)ambiente].right;

			psglist_play ( 3 ); // 4,5 seleecionada // 8

			flecha = 0;
			_show_title ( );
			_mostrar_niveles ( ) ;
		}

		_update_sprites ();


		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}

	return to;
}



static void _visito_la_puerta()
{
	if ( !gamestate.visito_la_puerta )
	{
		gamestate.visito_la_puerta = ( bool )
			gamestate.ambientes [ 0 ] +
			gamestate.ambientes [ 1 ] +
			gamestate.ambientes [ 2 ] +
			gamestate.ambientes [ 3 ] +
			gamestate.ambientes [ 4 ];
	}
}



void screen_mapa_init()
{
	index = 0;
	POS_SPRITES = 0;
	POS_TILES = 0;
	ambiente = 0;
	nivel = 0;
	cuantos = 0;
	superado = 0;
	flecha = 0;
	sprite = 0;
	sprites[0] = 0;
	sprites[1] = 0;
	sprites[2] = 0;
	sprites[3] = 0;
	sprites[4] = 0;
	sprites[5] = 0;
	sprite_last_letter = 0;
	_counter = 0;
	_counter_sp1 = 0;
	_counter_sp2 = 0;
	jump_loop_niveles = false;
}



u16 screen_mapa ( u16 first_time )
{
	music_stop();


	flecha = 0;
	ambiente = first_time ? 4 : gamestate.current_ambiente;



	_visito_la_puerta();
	_init();

	vint_setFlechaMap ( true );

	u16 to = _loop_main ( );


	waitMs ( 500 );
	vint_setFlechaMap ( false );
	music_stop ( );

	displayOff(30);
	waitMs ( 500 ); // pausa valorativa

	jump_loop_niveles = (bool) to;

	return to;
}



void screen_mapa_flecha ( )
{
	VDP_setSpriteFull ( 0, datos[(u8)ambiente].posicion.x, datos[(u8)ambiente].posicion.y + flecha/3, SIZE, ATTR(4), 1 );

	++flecha;
	flecha %= 30;
}
