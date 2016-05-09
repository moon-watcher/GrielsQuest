#include "../inc/include.h"


static void _do_leave_stuff ( u16 ret )
{
	u8  *f      = NULL;
	u16  numero = 10000;

	if ( ret == LEVEL_RESTART   ) numero = 4;
	if ( ret == LEVEL_EXIT      ) numero = 5;
	if ( ret == LEVEL_COMPLETED ) numero = 6;

	f = frases_find ( 2, numero );

	if ( f != NULL )
	{
		text_init ( (struct genresSprites *) &cs_font_16x16, 16, PAL0 );
		u16 sprite = text_draw_sprites_centered ( f, 30 );
		--sprite;

		vdpSpriteCache [ sprite ].link = 0;
		VDP_setSpriteP ( sprite, &vdpSpriteCache [ sprite ] );
		VDP_updateSprites ( );

		waitMs(1000);
		VDP_fadeOutAll ( 30, false );

		waitMs(500); // pausa valorativa
	}
}





static LEVEL _init ( )
{
   resetPalettes();
   resetVRAM();
   resetSprites ( );
   resetScroll ( );

	voffset_horizontal_set ( OFFSET_HORIZONTAL );
	voffset_vertical_set   ( OFFSET_VERTICAL );


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
	LEVEL wl = level_init ( false, false );
	player_init ( PLAYER_1 );


	//if ( !DEVELOPEMENT )
	{
		level_presentation();
		splist_hide_sprites();
		text_reset ( );
	}

	splist_draw ( );
	player_update ( PLAYER_1 );
	level_draw ( );

	//if ( !DEVELOPEMENT )
	{
		stars_draw ();
	}

	musiclist_play ( level_get_music() ); // wl.music


	return wl;
}


//////////////////////////////////////////////////////




void game_level_inc ( )
{
	// sólo incrementa el round si se ha
	// completado el útlimo nivel disponible

	if ( gamestate.round == gamestate.ambientes [ gamestate.ambiente ] )
	{
		++gamestate.ambientes [ gamestate.ambiente ];
	}
}


u16 game_play ( )
{
	u16  ret = LEVEL_OK;
   bool joy = vint_getJoyReader();

   vint_setJoyReader ( false );

	LEVEL wl = _init ( );




	while ( ret == LEVEL_OK )
	{
		JoyReader_update();

		death_frame ( &wl );
		toani_remove ( );
		toani_demon_update ( );
		chorrada_control ( &wl );
		undo_control ( &wl );
		//scoreball_frame();
		level_update ( );

		//bossctrl_frame();
		//boss_loop ( 1 );

		ret = pause_show ( &wl );

		player_control_buttons ( &wl );
		player_ctrldev ( &ret );

		if ( ret == LEVEL_RESTART   ) break;
		if ( ret == LEVEL_EXIT      ) break;
		if ( ret == LEVEL_COMPLETED ) break;



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
				musiclist_play ( MUSIC_FSCLEAR ); // wl.music
				break;
			}

			if ( undo_rest(0) < 0 )
			{
				ret = LEVEL_RESTART;
				player_dead ( PLAYER_1, &wl, ret );
				break;
			}

			player_action ( PLAYER_1 );
			player_logic_next ( PLAYER_1, &wl );
		}

		player_move ( PLAYER_1 );
		player_update ( PLAYER_1 );
		vobject_update ( );

		showFPS ( );

		VDP_updateSprites();
		VDP_waitVSync();
	}


	tool_planHide();
	_do_leave_stuff ( ret );
	resetSprites();
	vint_setJoyReader(joy);


	return ret;
}






u16 game_ingame ()
{
	u16 ended = LEVEL_OK;

	while ( 1 )
	{
		ended = game_play ( );

		if ( ended == LEVEL_EXIT      ) break;
		if ( ended == LEVEL_COMPLETED ) break;
	}


	return ended;
}

//	u16 ended;
//
//	while ( 1 )
//	{
//		ended = game_play ( );
//
//		if ( ended == LEVEL_OK ) // ok
//		{
//			// check if boss
//			//boss_loop ( level );
//
//			++gamestate.round;
//
//			if ( gamestate.round == level_get_max_rounds() ) // si es el último nivel
//			{
//				// congratulations!
//				screen_ending ( );
//				//screen_staff ( );
//				break;
//			}
//		}
//
//		if ( ended == LEVEL_RESTART || ended == LEVEL_HURT ) // ok
//		{
//			// no hace nada, solo sigue en el bucle
//		}
//
//
//		// para borrar //////////////////////////////////////////
//		if ( ended == LEVEL_BACK ) // back
//		{
//			--gamestate.round; // restar un nivel y continua el bucle
//		}
//		/////////////////////////////////////////////////////////
//
//
//		if ( ended == LEVEL_EXIT ) // give up
//		{
//			//screen_gameover ( );
//			break;
//		}
//
//
////					if ( ret == LEVEL_EXIT )
////			{
////				player_dead ( PLAYER_1, &wl, ret );
////				break;
////			}
////						drawUInt(ret, 0,1,0);
////			waitMs(1000);
//	}
//
//
//	return 1111;




void game_loop()
{
	u16 to;

   while ( true )
   {
		gamestate.visito_la_puerta = false;

//		screen_oooklab ( 4, BUTTON_BTN, 0 );
//		screens_intro ( 1 );
//		to = screen_title ( 0 );



					// dev stuff
					to = SCREEN_JUMP_TO_AMBIENT;
					gamestate.visito_la_puerta = true;
					gamestate.lenguaje = ESPANOL;
  					//



		if ( to == SCREEN_JUMP_TO_SOUNDTEST )
      {
         screen_sound_test ( ) ;
      }

      if ( to == SCREEN_JUMP_TO_CONTINUE  &&  pwd8_screen() )
		{
			to = SCREEN_JUMP_TO_AMBIENT;
      }

      if (  to == SCREEN_JUMP_TO_AMBIENT ) // ||  to == SCREEN_JUMP_TO_DIFFICULT  )
      {
			while ( 1 )
			{
				to = screens_ambiente();

				// visita al rey
				if ( to == SCREEN_JUMP_TO_INTRO5 )
				{
					screens_intro ( 5 ) ;
				}

				// Muestra la puerta del ambiente volcán
				if ( to == SCREEN_JUMP_TO_PUERTA )
				{
					screens_puerta();
				}

				// juego
				if ( to == SCREEN_JUMP_TO_NEWGAME )
				{
					to = game_ingame();
				}
			}
      }
   }
}

