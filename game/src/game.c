#include "../inc/include.h"


static LEVEL wl;



static void _leave ( u16 ret )
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

		waitMs(1000);
		VDP_fadeOutAll ( 30, false );

		waitMs(500); // pausa valorativa
	}

	vram_destroy();
}





static LEVEL _init ( )
{
	displayInit();
	displayOff(0);
	SYS_disableInts();
	resetScreen();
	resetSprites();
	resetScroll();
	resetPalettes();
	SYS_enableInts();

	voffset_horizontal = VOFFSET_HORIZONTAL;
	voffset_vertical   = VOFFSET_VERTICAL;

	VDP_setPlanSize ( 64, 32 );

//   VDP_setTextPalette ( PAL0 );

	font_init ( );
	sd_init();
	vram_init ( VRAM_DEFAULT );
	vobject_init ( );
	splist_init ( );
	bigboy_init ( );
	//scoreball_init ( );
	undo_init ( );
	toani_init ( );
	death_init ( );
	chorrada_init ( );
	weapon_init ( );
	stars_init ( );
	LEVEL wl = level_init ( );
	player_init ( PLAYER_1 );

	level_presentation();
	splist_hide_sprites();
	text_reset ( );

	displayInit();
	displayOff(0);
	SYS_disableInts();
	resetScreen();
	resetScroll();
	resetPalettes();
	SYS_enableInts();

	splist_draw ( );
	player_update ( PLAYER_1 );
	level_draw ( &wl );
	vobject_update ( );

	VDP_updateSprites(80, 1);

	displayOn(30);

	stars_draw ();


	musiclist_play ( level_get_music() ); // wl.music


	return wl;
}


//////////////////////////////////////////////////////


LEVEL *game_get_wl ( )
{
	return (LEVEL*) &wl;
}



void game_level_inc ( )
{
	// s�lo incrementa el round si se ha
	// completado el �tlimo nivel disponible

	if ( gamestate.current_round == gamestate.ambientes [ (u8) gamestate.current_ambiente ] )
	{
		++gamestate.ambientes [ (u8) gamestate.current_ambiente ];
	}
}


u16 game_play ( )
{
	u16  ret = LEVEL_OK;
	bool joy = vint_getJoyReader();

	vint_setJoyReader ( false );

	wl = _init ( );


	while ( ret == LEVEL_OK )
	{
		JoyReader_update();

		death_frame ( &wl );
		toani_remove ( );
		//toani_demon_update ( );
		chorrada_control ( &wl );
		undo_control ( &wl );
		//scoreball_frame();
		level_update ( );

		//bossctrl_frame();
		//boss_loop ( 1 );

		splist_reorder_bigboys ( );

		ret = pause_show ( &wl );

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

		if ( ret == LEVEL_EXIT )
		{
			break;
		}

		if ( ret == LEVEL_RESTART )
		{
			player_dead ( PLAYER_1, &wl, ret );
			break;
		}



		player_move ( PLAYER_1 );
		player_update ( PLAYER_1 );
		vobject_update ( );

		//showFPS ( );

		VDP_updateSprites(80, 1);
		VDP_waitVSync();
	}


	planHide();
	_leave ( ret );
	resetSprites();
	vint_setJoyReader(joy);
	vram_destroy();

	return ret;
}






void game_loop()
{
	u16 to;

	while ( true )
	{
		screen_mapa_init();

		gamestate.visito_la_puerta = false;
		puerta_abierta = 0;

		screen_oooklab ( 4, BUTTON_BTN, 0 );
		screen_intro ( 1 );
		to = screen_title ( 0 );






					if ( DEV )
					{
					   gamestate.dificultad   =  3;
					   gamestate.ambientes[0] = 14; // 14;
					   gamestate.ambientes[1] = 14; // 14;
					   gamestate.ambientes[2] = 14; // 14;
					   gamestate.ambientes[3] = 14; // 14;
					   gamestate.ambientes[4] =  6; // 6 ;
					   gamestate.visito_la_puerta = true;
					   gamestate.lenguaje         = SPANISH;

//					   gamestate.dificultad   = 0;
//					   gamestate.ambientes[0] = 6;
//					   gamestate.ambientes[1] = 6;
//					   gamestate.ambientes[2] = 6;
//					   gamestate.ambientes[3] = 6;
//					   gamestate.ambientes[4] = 4;
//					   gamestate.visito_la_puerta = false;
//					   gamestate.lenguaje         = SPANISH;

					}






		if ( to == SCREEN_JUMP_TO_SOUNDTEST )
		{
			screen_sound_test ( ) ;
			continue;
		}

		if ( to == SCREEN_JUMP_TO_CONTINUE  &&  pwd8_screen() )
		{
			to = SCREEN_JUMP_TO_AMBIENT;
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

				to = screen_mapa();

				// visita al rey
				if ( to == SCREEN_JUMP_TO_INTRO5 )
				{
					screen_intro ( 5 ) ;
				}

				// Muestra la puerta del ambiente volc�n
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


		if ( to == SCREEN_JUMP_TO_ENDING )
		{
			screen_final(0);
			//screen_staff ();
			//screen_ending();
			screen_gameover();
		}

	}
}
