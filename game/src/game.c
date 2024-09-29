#include "../inc/include.h"
#include "../inc/genres_externs.h"

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
		bigtext_init ( (struct genresSprites *) &cs_font_16x16, 16, PAL0 );
		u16 sprite = bigtext_drawSprite_XYcentered ( f, 30 );
		--sprite;

		VDP_setSpriteLink ( sprite, 0 );
		VDP_updateSprites ( 80, 1 );

		waitJoyScBtn ( 2 );
		music_stop();
	}
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

u16 game_ingame_step(u16 ret)
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
		return ret;
	}

	if ( ret == LEVEL_RESTART )
	{
		music_stop();
		player_dead ( PLAYER_1, &wl, ret );
		return ret;
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
		return ret;
	}

	player_move ( PLAYER_1 );
	player_update ( PLAYER_1 );

	vobject_update ( );
	vobject_upload ( );

	showFPS ( );

	VDP_updateSprites(80, 1);
	SYS_doVBlankProcess();

	return ret;
}


u16 game_play ( )
{
	displayInit();
	displayOff(0);
	resetScreen();
	resetSprites();
	resetScroll();
	resetPalettes();
		
	VDP_setPlaneSize ( 64, 32, false );

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

	//
	scene_presentation();
	splist_hide_sprites();
	bigtext_reset ( );

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

	u16 ret = LEVEL_OK;
	while ( ret == LEVEL_OK )
		ret = game_ingame_step(ret);

	planHide();
	_leave_text ( ret );
    music_stop();
    displayOff(30);
	resetSprites();
	vram_destroy();

	return ret;
}

void game_main_step()
{
	u16 to = SCREEN_JUMP_TO_NEWGAME;
	u16 first_time = 1;

	screen_mapa_init();

	gamestate.visito_la_puerta = false;
	puerta_abierta = 0;

	if (DEV < ++gamestate.localdev) // 5: intro
	{
		screen_intro(1);
	}
	
	if(DEV < ++gamestate.localdev) // 6: title
	{
		to = screen_title(0);
	}
	else
	{
		to = SCREEN_JUMP_TO_MAP; // 7: map
	}

	if (to == SCREEN_JUMP_TO_SOUNDTEST)
	{
		screen_sound_test();
		return;
	}

	if (to == SCREEN_JUMP_TO_CONTINUE && pwd8_screen())
	{
		to = SCREEN_JUMP_TO_MAP;
		first_time = 0;
	}

	if (to == SCREEN_JUMP_TO_MAP) // ||  to == SCREEN_JUMP_TO_DIFFICULT  )
	{
		while (1)
		{
			displayInit();
			displayOff(0);
			resetScreen();
			resetPalettes();
			resetScroll();
			resetSprites();

			to = screen_mapa(first_time);
			first_time = 0;

			// visita al rey
			if (to == SCREEN_JUMP_TO_INTRO5)
			{
				screen_intro(5);
			}

			// Muestra la puerta del ambiente volcán
			if (to == SCREEN_JUMP_TO_PUERTA)
			{
				to = screen_puerta();
			}

			// juego
			if (to == SCREEN_JUMP_TO_NEWGAME)
			{
				u16 state = LEVEL_OK;

				while (1)
				{
					state = game_play();

					if (state == LEVEL_EXIT)
						break;
					if (state == LEVEL_COMPLETED)
						break;
				}

				if (gamestate_go_to_ending(state))
				{
					to = SCREEN_JUMP_TO_ENDING;
					break;
				}
			}
		}
	}

	if (to == SCREEN_JUMP_TO_INTRO)
	{
		music_stop();
		// screen_wtfisaporron ();
		screen_griels(); // solo para Barcelona y demos
		screen_credits();
	}

	if (to == SCREEN_JUMP_TO_ENDING)
	{
		screen_final(0);
		screen_gameover();

		if (gamestate.dificultad == 3)
		{
			screen_staff();
		}
	}
}