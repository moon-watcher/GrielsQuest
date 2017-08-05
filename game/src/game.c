#include "../inc/include.h"


static LEVEL wl;



static void _leave_text ( u16 ret )
{
	u8  *f      = NULL;
	u16  numero = 10000;

	if ( ret == LEVEL_RESTART   ) numero = 3;
	if ( ret == LEVEL_EXIT      ) numero = 4;
	if ( ret == LEVEL_COMPLETED ) numero = 5;

	f = frases_find ( 2, numero );

	if ( f != NULL )
	{
		text_init ( (struct genresSprites *) &cs_font_16x16, 16, PAL0 );
		u16 sprite = text_draw_sprites_centered ( f, 30 );
		--sprite;

		VDP_setSpriteLink ( sprite, 0 );
		VDP_updateSprites ( 80, 1 );

		waitSc(2);
	}
}





static void _init ( )
{
	displayInit();
	displayOff(0);

	resetScreen();
	resetSprites();
	resetScroll();
	resetPalettes();


	voffset_horizontal = VOFFSET_HORIZONTAL;
	voffset_vertical   = VOFFSET_VERTICAL;

	VDP_setPlanSize ( 64, 32 );

	font_init ( );
	sd_init();
	vram_init ( VRAM_DEFAULT );
	vobject_init ( );
	splist_init ( );
	bigboy_init ( );
	undo_init ( );
	toani_init ( );
	death_init ( );
	chorrada_init ( );
	weapon_init ( );
	stars_init ( );
	wl = level_init ( );
	player_init ( PLAYER_1 );

	level_presentation();
	splist_hide_sprites();
	text_reset ( );

	displayInit();
	displayOff(0);

	resetScreen();
	resetScroll();
	resetPalettes();


	splist_draw ( );
	player_update ( PLAYER_1 );
	level_draw ( &wl );

	vobject_update ( );
	vobject_upload ( );

	VDP_updateSprites(80, 1);

	displayOn(30);

	stars_draw ();


	musiclist_play ( level_get_music() ); // wl.music
}


//////////////////////////////////////////////////////


LEVEL *game_get_wl ( )
{
	return (LEVEL*) &wl;
}



void game_level_inc ( )
{
	// sólo incrementa el round si se ha
	// completado el útlimo nivel disponible

	if ( gamestate.current_round == gamestate.ambientes [ (u8) gamestate.current_ambiente ] )
	{
		++gamestate.ambientes [ (u8) gamestate.current_ambiente ];
	}
}


u16 game_play ( )
{
	u16  ret = LEVEL_OK;
	bool joyState = vint_getJoyReader();

	vint_setJoyReader ( false );

	_init ( );

	while ( ret == LEVEL_OK )
	{
		JoyReader_update();
		death_frame ( &wl );
		toani_update ( );
		chorrada_control ( &wl );
		undo_control ( &wl );
		level_update ( );
		splist_reorder ( );
		splist_reorder_bigboys ( );
		pause_show ( &wl, &ret );

		if ( ret == LEVEL_EXIT )
		{
		    music_stop();
			break;
		}

		if ( ret == LEVEL_RESTART )
		{
		    music_stop();
			player_dead ( PLAYER_1, &wl, ret );
			break;
		}


		player_control_buttons ( &wl );
		player_ctrldev ( &ret );

		if ( player_is_moving ( PLAYER_1 ) )
		{
			player_changed_dir ( PLAYER_1 );
		}
		else
		{
			player_interact_with_object ( &wl );

			if ( player(PLAYER_1)->on_door )
			{
				ret = LEVEL_COMPLETED;
			}

			if ( undo_rest(0) < 0 )
			{
				ret = LEVEL_RESTART;
			}

			player_action ( PLAYER_1 );
			player_logic_next ( PLAYER_1, &wl );
		}

		if ( ret == LEVEL_COMPLETED )
		{
			player_inc_level ( );
			musiclist_play ( MUSIC_FSCLEAR ); // wl.music
			break;
		}



		player_move ( PLAYER_1 );
		player_update ( PLAYER_1 );

		vobject_update ( );
		vobject_upload ( );

		showFPS ( );

		VDP_updateSprites(80, 1);
		VDP_waitVSync();
	}


	planHide();
	_leave_text ( ret );
    music_stop();
    displayOff(30);
	resetSprites();
	vint_setJoyReader(joyState);
	vram_destroy();

	return ret;
}






void game_loop()
{
	u16 to;

	while ( true )
	{
	    u16 first_time = 1;

		screen_mapa_init();

		gamestate.visito_la_puerta = false;
		puerta_abierta = 0;

		screen_intro ( 1 );
		to = screen_title ( 0 );






					if ( DEV  )
					{
					   gamestate.dificultad   =  3;
					   gamestate.ambientes[0] = 14; // 14;
					   gamestate.ambientes[1] = 14; // 14;
					   gamestate.ambientes[2] = 14; // 14;
					   gamestate.ambientes[3] = 14; // 14;
					   gamestate.ambientes[4] =  6; // 6 ;
					   gamestate.visito_la_puerta = true;
					   //gamestate.lenguaje         = SPANISH;


//					   gamestate.dificultad   =  2;
//					   gamestate.ambientes[0] = 13; // 14;
//					   gamestate.ambientes[1] = 13; // 14;
//					   gamestate.ambientes[2] = 13; // 14;
//					   gamestate.ambientes[3] = 13; // 14;
//					   gamestate.ambientes[4] =  0; // 6 ;
//					   gamestate.visito_la_puerta = false;
//					   //gamestate.lenguaje         = ENGLISH;

//					   gamestate.dificultad   =  2;
//					   gamestate.ambientes[0] =  0; // 14;
//					   gamestate.ambientes[1] =  0; // 14;
//					   gamestate.ambientes[2] =  0; // 14;
//					   gamestate.ambientes[3] =  0; // 14;
//					   gamestate.ambientes[4] =  0; // 6 ;
//					   gamestate.visito_la_puerta = true;
//					   //gamestate.lenguaje         = SPANISH;


//					   gamestate.dificultad   = 0;
//					   gamestate.ambientes[0] = 5;
//					   gamestate.ambientes[1] = 5;
//					   gamestate.ambientes[2] = 5;
//					   gamestate.ambientes[3] = 5;
//					   gamestate.ambientes[4] = 3;
//					   gamestate.visito_la_puerta = false;
//					   //gamestate.lenguaje         = SPANISH;

//					   gamestate.dificultad   = 0;
//					   gamestate.ambientes[0] = 6;
//					   gamestate.ambientes[1] = 6;
//					   gamestate.ambientes[2] = 6;
//					   gamestate.ambientes[3] = 6;
//					   gamestate.ambientes[4] = 0;
//					   gamestate.visito_la_puerta = false;
//					   gamestate.lenguaje         = FRENCH;

					}






		if ( to == SCREEN_JUMP_TO_SOUNDTEST )
		{
			screen_sound_test ( ) ;
			continue;
		}

		if ( to == SCREEN_JUMP_TO_CONTINUE  &&  pwd8_screen() )
		{
			to = SCREEN_JUMP_TO_AMBIENT;
			first_time = 0;
		}

		if (  to == SCREEN_JUMP_TO_AMBIENT ) // ||  to == SCREEN_JUMP_TO_DIFFICULT  )
		{
			while ( 1 )
			{
				displayInit();
				displayOff(0);


				resetScreen   ( );
				resetPalettes ( );
				resetScroll   ( );
				resetSprites  ( );

				to = screen_mapa( first_time );
				first_time = 0;

				// visita al rey
				if ( to == SCREEN_JUMP_TO_INTRO5 )
				{
					screen_intro ( 5 ) ;
				}

				// Muestra la puerta del ambiente volcán
				if ( to == SCREEN_JUMP_TO_PUERTA )
				{
					to = screen_puerta();
				}

				// juego
				if ( to == SCREEN_JUMP_TO_NEWGAME )
				{
					u16 state = LEVEL_OK;

					while ( 1 )
					{
						state = game_play ( );

						if ( state == LEVEL_EXIT      ) break;
						if ( state == LEVEL_COMPLETED ) break;
					}

					if ( gamestate_go_to_ending(state) )
					{
						to = SCREEN_JUMP_TO_ENDING;
						break;
					}
				}
			}
		}

        if ( to == SCREEN_JUMP_TO_INTRO )
        {
            music_stop();
            //screen_wtfisaporron ();
            screen_griels ( ); // solo para Barcelona y demos
            screen_credits ( );
        }

		if ( to == SCREEN_JUMP_TO_ENDING )
		{
			screen_final(0);
			screen_gameover();

			if (gamestate.dificultad == 3 )
			{
				screen_staff ();
			}
		}

	}
}

