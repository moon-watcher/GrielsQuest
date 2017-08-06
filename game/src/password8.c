#include "../inc/include.h"


#define PWD_HEIGHT   3
#define PWD_WIDTH   10



const static char _letras [ PWD_HEIGHT ] [ PWD_WIDTH ] =
{
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' },
	{ 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' },
	{ 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', ' ', '<', '[' }
};



void _posiciones ( PASSWORD8 pwd, u8 *pos1, u8 *pos2, u8 *pos3, u8 *pos4, u8 *pos5, u8 *pos6, u8 *pos7 )
{
	const u8 posiciones [ 7 ] [ 7 ] =
	{
		{ 1, 3, 7, 5, 6, 4, 2 },
		{ 4, 2, 5, 3, 7, 6, 1 },
		{ 5, 2, 6, 7, 1, 3, 4 },
		{ 6, 7, 1, 4, 5, 2, 3 },
		{ 7, 5, 3, 6, 4, 1, 2 },
		{ 3, 6, 4, 7, 2, 5, 1 },
		{ 6, 1, 5, 4, 7, 2, 3 }
	};

	u8 aux = pwd [ 0 ] % 7;

	*pos1 = posiciones [ aux ] [ 0 ];
	*pos2 = posiciones [ aux ] [ 1 ];
	*pos3 = posiciones [ aux ] [ 2 ];
	*pos4 = posiciones [ aux ] [ 3 ];
	*pos5 = posiciones [ aux ] [ 4 ];
	*pos6 = posiciones [ aux ] [ 5 ];
	*pos7 = posiciones [ aux ] [ 6 ];
}


static void _debug ( u16 x, s32 args, ... )
{
	if ( !DEV )
	{
		return;
	}

	va_list ap;
	s32 y = 0;

	va_start ( ap, args );

	while ( args >= 0 )
	{
		drawUInt ( args, x, y++, 2 );
		args = va_arg ( ap, s32 );
	}

	va_end ( ap );
}


static char _rnd ( )
{
	return random() % 26 + PWD8_A_STARTS_AT;
}


static u16 letra_a_numero ( u16 letra, u16 max )
{
	++max;

	return letra % max;
}


static char numero_a_letra ( u16 numero, u16 max )
{
	++max;

	while ( true )
	{
		char letra = _rnd();

		if ( letra % max == numero )
		{
			return letra;
		}
	}

	return 0;
}


static void _draw ( PASSWORD8 password )
{
	displayOff(0);//VDP_setEnable ( FALSE );

	resetScreen();

	u16 y = 0;
	u16 x = 0;

	for ( y = 0; y < PWD_HEIGHT; y++ )
	{
		for ( x = 0; x < PWD_WIDTH; x++ )
		{
			u16 x0   =  6 + x * 3;
			u16 y0   = 15 + y * 3;
			u16 tile = TILE_FONTINDEX + _letras [ y ] [ x ] - 32;

			SYS_disableInts();
			VDP_setTileMapXY ( PLAN_A, tile, x0, y0 );
			SYS_enableInts();
		}
	}

	//SYS_disableInts();
	VDP_setTextPalette (PAL0);
	preparePal ( PAL0, font_getPalette());//VDP_setPalette ( PAL0, font_getPalette());
	//SYS_enableInts();

	text_init ( (struct genresSprites*) &cs_font_16x16, 1200, PAL0 );

	frases_init (30);
	text_draw_center ( frases_next(), 3,  0 );
	text_draw ( ( char*) password, 12, 9, 0 ) ; // ">>>>>>>>" --> ">" Es el "guión alto"

	SYS_disableInts();
	preparePal ( PAL3, cs_square.pal ); //VDP_setPalette ( PAL3, cs_square.pal );
	VDP_loadTileData ( cs_square.sprites[0], 5, cs_square.size>>8, 0 );
	VDP_setSprite ( 0, 40, 112, cs_square.size>>8, TILE_ATTR_FULL(PAL3, 1,0,0,5) );
	SYS_enableInts();

	VDP_updateSprites(80,1);

	_debug ( 0, gamestate.dificultad, gamestate.ambientes[0], gamestate.ambientes[1], gamestate.ambientes[2], gamestate.ambientes[3], gamestate.ambientes[4], -1 );

	displayOn(10);//VDP_setEnable ( TRUE );
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static bool pwd_is_ok ( PASSWORD8 pwd )
{
	u16  i    = 0;
	bool ret  = false;
	u16  play = 1;


	// que todas sean mayúsculas
	for ( i=0; i<8; i++ )
	{
		if ( pwd[i] < 65 || pwd[i] > 90 )
		{
			return ret;
		}
	}


	u8 pos1, pos2, pos3, pos4, pos5, pos6, pos7;

	_posiciones ( pwd, &pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7 );


	u16 posicion   = pwd [ 0 ] % 7;
	u16 dificultad = letra_a_numero ( pwd[pos2], 3 ); // 0, 1, 2, 3
	u16 aux        = dificultad;

	if ( aux > 2 ) aux = 2;

	u16 ambiente0  = letra_a_numero ( pwd[pos3], level_list [ 0 ] [ aux ].cuantos );
	u16 ambiente1  = letra_a_numero ( pwd[pos4], level_list [ 1 ] [ aux ].cuantos );
	u16 ambiente2  = letra_a_numero ( pwd[pos5], level_list [ 2 ] [ aux ].cuantos );
	u16 ambiente3  = letra_a_numero ( pwd[pos6], level_list [ 3 ] [ aux ].cuantos );
	u16 ambiente4  = letra_a_numero ( pwd[pos7], level_list [ 4 ] [ aux ].cuantos );

	u16 suma       = ( dificultad + ambiente0 + ambiente1 + ambiente2 + ambiente3 + ambiente4 + posicion ) / 3;
	u16 verifica   = ABS ( ( pwd[pos1] - PWD8_A_STARTS_AT ) - suma );



	//
	_debug ( 3, dificultad, ambiente0, ambiente1, ambiente2, ambiente3, ambiente4, suma, verifica, -1 );


	u8 max_verifica = frases_count ( 5 ) - 1;

	if ( verifica > max_verifica )
	{
		verifica = max_verifica;
	}

	if ( verifica == 0 ) // 0 es que no hay diferencias entre la verificacion y el código
	{
		gamestate.current_ambiente = 0;
		gamestate.current_round    = 0;

		if ( dificultad > 2 )
		{
			gamestate.visito_la_puerta = true;
		}

		gamestate.dificultad   = dificultad;
		gamestate.ambientes[0] = ambiente0;
		gamestate.ambientes[1] = ambiente1;
		gamestate.ambientes[2] = ambiente2;
		gamestate.ambientes[3] = ambiente3;
		gamestate.ambientes[4] = ambiente4;

		play = 4;
		ret  = true;

		_debug ( 35, gamestate.dificultad, gamestate.ambientes[0], gamestate.ambientes[1], gamestate.ambientes[2], gamestate.ambientes[3], gamestate.ambientes[4], -1 );
	}

	char *string = frases_find ( 5, verifica );

	SYS_disableInts();
	VDP_clearTextLine ( 25 );
	VDP_drawText ( string, 20 - strlen ( string ) / 2, 25 );
	SYS_enableInts();

	psglist_play ( play );

	if ( ret )
	{
		waitSc(1);
	}


	return ret;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//void pwd8_generate ( )
void pwd8_generate ( PASSWORD8 letras )
{
	setRandomSeed(vtimer);

	letras [ 0 ] = _rnd();
	letras [ 1 ] = '-';
	letras [ 2 ] = '-';
	letras [ 3 ] = '-';
	letras [ 4 ] = '-';
	letras [ 5 ] = '-';
	letras [ 6 ] = '-';
	letras [ 7 ] = '-';
	letras [ 8 ] = '\0';

	u8 pos1, pos2, pos3, pos4, pos5, pos6, pos7;

	_posiciones ( letras, &pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7 );

	u8 aux = gamestate_get_dificultad ( );

	letras [ pos2 ] = numero_a_letra ( gamestate.dificultad, 3 ); // 0, 1, 2, 3
	letras [ pos3 ] = numero_a_letra ( gamestate.ambientes[0], level_list [ 0 ] [ aux ].cuantos );
	letras [ pos4 ] = numero_a_letra ( gamestate.ambientes[1], level_list [ 1 ] [ aux ].cuantos );
	letras [ pos5 ] = numero_a_letra ( gamestate.ambientes[2], level_list [ 2 ] [ aux ].cuantos );
	letras [ pos6 ] = numero_a_letra ( gamestate.ambientes[3], level_list [ 3 ] [ aux ].cuantos );
	letras [ pos7 ] = numero_a_letra ( gamestate.ambientes[4], level_list [ 4 ] [ aux ].cuantos );

	u16 posicion    = letras [ 0 ] % 7;
	u16 suma        = ( gamestate.dificultad + gamestate.ambientes[0] + gamestate.ambientes[1] + gamestate.ambientes[2] + gamestate.ambientes[3] + gamestate.ambientes[4] + posicion ) / 3;

	letras [ pos1 ] = suma + PWD8_A_STARTS_AT;

	//text_draw ( (u8*) letras, 12, 12, 0 );
	//pwd_is_ok ( letras );
}




bool pwd8_screen()
{
	s16 len = 0;
	s16 y   = 0;
	s16 x   = 0;
	char password[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '\0' };
	bool ret = false;


	music_stop();

	_draw ( password );



	u8 activeTo = 0;
	u8 activeCo = 0;

	while ( true )
	{
		char ch = 0;
		bool paint = false;

		JoyReader_update ( );

		if ( joy1_active_dir )
		{
		    ++activeCo;

		    if ( activeTo == 0 )
            {
                psglist_play ( PSG_SELECT );

                do
                {
                    if ( joy1_active_up    ) --y;
                    if ( joy1_active_down  ) ++y;
                    if ( joy1_active_left  ) --x;
                    if ( joy1_active_right ) ++x;

                    if ( y < 0              ) y = PWD_HEIGHT - 1;
                    if ( x < 0              ) x = PWD_WIDTH  - 1;
                    if ( y > PWD_HEIGHT - 1 ) y = 0;
                    if ( x > PWD_WIDTH  - 1 ) x = 0;

                    ch = _letras[y][x];
                }
                while ( ch == 32 );

                VDP_setSpritePosition ( 0, x * 24 + 40, y * 24 + 112 );
                VDP_updateSprites (80,1);

                if ( activeCo == 1 )
                {
                    activeTo = 10;
                }
                else
                {
                    activeTo = 4;
                }

                continue;
            }
		}
		else
        {
            activeCo = 0;
        }


        ch = _letras[y][x];


		if ( activeTo )
        {
            --activeTo;
        }


		if ( DEV )
		{
			drawUInt ( ch , 38, 27, 2 );

			if ( joy1_pressed_x  ||  joy1_pressed_y  ||  joy1_pressed_z )
			{
				PASSWORD8 letras;
				pwd8_generate ( letras );

				text_draw ( letras, 12, 12, 0 );
				pwd_is_ok ( letras );
			}
		}


		// C salir
		if ( joy1_pressed_c )
		{
		    if ( prayer_compare( password ) )
            {
                ret = false;
                break;
            }

		    ret = pwd_is_ok ( password );
			break;
		}

		// A+OK | START: check password
		if (  joy1_pressed_start || ( joy1_pressed_a && ch == 91 ) )
		{
		    if ( prayer_compare( password ) )
            {
                ret = false;
                break;
            }

			ret = pwd_is_ok ( password );

			if ( ret )
			{
				break;
			}
		}

		// A seleccionar
		if ( len < 8  &&  joy1_pressed_a  &&  ch >= 65  &&  ch <= 90 )
		{
			psglist_play(2);

			password [ len++ ] = ch;
			paint = true;
		}

		// B borrar
		if ( len > 0  &&  ( joy1_pressed_b  ||  ( joy1_pressed_a && ch == 60 ) )  )
		{
			psglist_play(3);

			password [ --len ] = '-';
			paint = true;
		}


		if ( paint )
		{
			SYS_disableInts();
			text_draw ( ( char*) password, 12, 9, 0 ) ;
			VDP_clearTextLine ( 25 );
			SYS_enableInts();
		}


		VDP_waitVSync();
	}


	//waitMs(1000);

	displayOff( 10 );
	resetSprites ( );

	return ret;
}


