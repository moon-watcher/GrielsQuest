#include "../inc/include.h"
#include "../inc/genres_externs.h"


static void _draw ( PASSWORD8 password )
{
	displayOff(0);//VDP_setEnable ( FALSE );

	resetScreen();

	u16 y = 0;
	u16 x = 0;

	SYS_disableInts();
	for ( y = 0; y < PWD_HEIGHT; y++ )
		for ( x = 0; x < PWD_WIDTH; x++ )
			VDP_setTileMapXY ( BG_A, TILE_FONT_INDEX + password_letras [ y ] [ x ] - 32, 6 + x * 3, 15 + y * 3 );

	SYS_enableInts();

	//SYS_disableInts();
	VDP_setTextPalette (PAL0);
	preparePal ( PAL0, font_getPalette());//PAL_setPalette ( PAL0, font_getPalette());
	//SYS_enableInts();

	bigtext_init ( (struct genresSprites*) &cs_font_16x16, 1200, PAL0 );
	vdpSpriteCache[0].link = 1;
	bigtext_setSprite(1);

	frases_init (30);
	bigtext_drawSprite_Xcentered(frases_next(), 24, 0);
	bigtext_drawTile ( ( char*) password, 12, 9, 0 ) ; // ">>>>>>>>" --> ">" Es el "guión alto"

	SYS_disableInts();
	preparePal ( PAL3, cs_square.pal ); //PAL_setPalette ( PAL3, cs_square.pal );
	VDP_loadTileData ( cs_square.sprites[0], 5, cs_square.size>>8, 0 );
	VDP_setSprite ( 0, 40, 112, cs_square.size>>8, TILE_ATTR_FULL(PAL3, 1,0,0,5) );
	SYS_enableInts();

	VDP_updateSprites(80,1);

    pwd8_debug( 0, gamestate.dificultad, gamestate.ambientes[0], gamestate.ambientes[1], gamestate.ambientes[2], gamestate.ambientes[3], gamestate.ambientes[4], -1 );

	displayOn(10);//VDP_setEnable ( TRUE );
}




bool screen_password()
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

                    ch = password_letras[y][x];
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


        ch = password_letras[y][x];


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

				bigtext_drawTile ( letras, 12, 12, 0 );
				pwd8_isOk ( letras );
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

		    ret = pwd8_isOk ( password );
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

			ret = pwd8_isOk ( password );

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
			bigtext_drawTile ( ( char*) password, 12, 9, 0 ) ;
			VDP_clearTextLine ( 25 );
			SYS_enableInts();
		}


		SYS_doVBlankProcess();
	}


	//waitMs(1000);

	displayOff( 10 );
	resetSprites ( );

	return ret;
}


