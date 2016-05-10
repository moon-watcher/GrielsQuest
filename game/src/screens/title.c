#include "../inc/include.h"
#include "../inc/colores_textos.h"




static void _blink ( u8 *str, const u16 x, const u16 y )
{
	u8 i   = ntsc2pal(30);
	u8 len = strlen(str);

	VDP_drawText ( str, x, y );

	while ( i-- )
	{
		if ( i % 2  )
		{
			VDP_clearText ( x, y, len );
		}
		else
		{
			VDP_drawText ( str, x, y );
		}

		VDP_waitVSync();
		VDP_waitVSync();
	}

	VDP_drawText ( str, x, y );
}







u16 screen_title_menu_1 ( )
{
	u16 option = 0, ret = 0;
	//const u8 pos[4] = { 18, 20, 22, 24 };
	const u8 pos[4] = { 19, 21, 23 };

	while ( !ret )
	{
		VDP_drawText ( "  NEW GAME",     14, pos[0] );
		VDP_drawText ( "  CONTINUE",     14, pos[1] );
		VDP_drawText ( "  SOUND TEST",   14, pos[2] );
		//VDP_drawText ( "  GRAPHIC TEST", 14, pos[3] );
		VDP_drawText ( ">", 14, pos[option] );

		if ( joy1_pressed_down && option < 2 ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   && option > 0 ) { option--; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			psglist_play ( PSG_START );

			if ( option == 0 ) { _blink("NEW GAME",   16, 19 ); ret = SCREEN_JUMP_TO_DIFFICULT;  }
			if ( option == 1 ) { _blink("CONTINUE",   16, 21 ); ret = SCREEN_JUMP_TO_CONTINUE;   }
			if ( option == 2 ) { _blink("SOUND TEST", 16, 23 ); ret = SCREEN_JUMP_TO_SOUNDTEST; }
		}

		VDP_waitVSync();
	}

	return ret;
}


void screen_title_menu_2 ( )
{
	u16 option = 0;
	const u8 pos[4] = { 19, 21, 23 };

	while ( true )
	{
		VDP_drawText ( "  WIMPY     ", 14, pos[0] ); // debilucho
		VDP_drawText ( "  TOUGH GUY ", 14, pos[1] ); // tipo duro
		VDP_drawText ( "  NIGHTMARE ", 14, pos[2] ); // pesadilla

		VDP_drawText ( ">", 14, pos[option] );

		if ( joy1_pressed_down && option < 2 ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   && option > 0 ) { option--; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			psglist_play ( PSG_START );

			if ( option == 0 ) _blink("WIMPY     ", 16, 19 );
			if ( option == 1 ) _blink("TOUGH GUY ", 16, 21 );
			if ( option == 2 ) _blink("NIGHTMARE ", 16, 23 );

			gamestate.current_round      = 0;
			gamestate.ambiente   = 0;

			gamestate.dificultad = option;
			gamestate.ambientes[0] = 0;
			gamestate.ambientes[1] = 0;
			gamestate.ambientes[2] = 0;
			gamestate.ambientes[3] = 0;
			gamestate.ambientes[4] = 0;

			break;
		}

		VDP_waitVSync();
	}
}




u16 screen_title( u16 salto )
{
   u16 ind = TILE_USERINDEX;


	if ( salto == 2 )
	{
		goto salto_2;
	}

   //psgfx_init();
	musiclist_play ( MUSIC_TITLE );


	VDP_setEnable ( false );
	SYS_disableInts();

	resetVRAM();
	font_init();
	resetScroll();

   VDP_drawImageEx ( BPLAN, &ob_title_title, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind),  4,  8, 1, true ); VDP_waitDMACompletion(); ind += ob_title_title.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_title_kbrah, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind),  8, -3, 1, true ); VDP_waitDMACompletion(); ind += ob_title_kbrah.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_title_notah, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind),  0, 13, 1, true ); VDP_waitDMACompletion(); ind += ob_title_notah.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_title_mano,  TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 11, 16, 1, true ); VDP_waitDMACompletion(); ind += ob_title_mano.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_title_griel, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, ind), 30, 13, 1, true ); VDP_waitDMACompletion();

   SYS_enableInts();
	VDP_setEnable ( true );


   //WAITSECS1 ( 2,etiqueta_1 );
   waitMs(2000);

	ind = TILE_USERINDEX;

   SYS_disableInts();
   VDP_drawImageEx ( BPLAN, &ob_title_title, TILE_ATTR_FULL(PAL0, true, FALSE, FALSE, ind),  4,  8, 1, true ); VDP_waitDMACompletion(); ind += ob_title_title.tileset->numTile;
	SYS_enableInts();

   VDP_fadePalOut ( PAL1, getHz(), false );
   VDP_fadePalOut ( PAL2, getHz(), false );
   VDP_fadePalOut ( PAL3, getHz(), false );

   VDP_clearPlan ( APLAN, true );
   VDP_waitDMACompletion();
   //WAITSECS1(1,etiqueta_1);
   waitMs(500);

   u8 i;

   for ( i=0; i<120; i++ )
   {
      VDP_setVerticalScroll ( PLAN_B, i/2 );
      VDP_waitVSync();
   }




	SYS_disableInts();
   VDP_drawImageEx ( BPLAN, &ob_title_subtitle, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 8, 24, false, true ); VDP_waitDMACompletion(); ind += ob_title_subtitle.tileset->numTile;
   SYS_enableInts();


salto_2:


   VDP_fadePalTo ( PAL1, ob_title_subtitle.palette->data, getHz(), false );


   //WAITSECS1(1,etiqueta_1);
   waitMs(100);




   //JOY_setEventHandler( &_readJOY );


	s16 tiles[28] = { };
	tiles[20] = -4;

	u16 counter = 0;
	u16 ret     = 0;
	u16 blink   = 0;
	u16 hz      = ntsc2pal ( 60 );




	//_blink_title_cnt = 0;
	//SYS_setVIntCallback ( (_voidCallback*) _blink_title_callback );


	SYS_disableInts();
	VDP_drawImageEx ( APLAN, &ob_title_press_start, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 15, 23, 1, true ); VDP_waitDMACompletion();
	SYS_enableInts();



	while ( true )
	{
		if ( counter % hz == 0 )
		{
			VDP_setPalette ( PAL2, ob_title_press_start.palette->data ); // tool_setPalette (PAL2, ob_title_press_start.palette->data );

			blink = 0;
		}

		if ( ++blink == 45 )
		{
			VDP_setPalette ( PAL2, (u16*) palette_black ); // tool_setPalette (PAL2, (u16*) palette_black);
		}

		if ( counter == hz * 20 ) // 20 segundos de espera y si no salta de nuevo a Ooklab
		{
			ret = SCREEN_JUMP_TO_INTRO;
			break;
		}

//		if ( ( joy = _pressed(JOY_1,BUTTON_BTN) )  )
//		{
//			_release ( joy, JOY_1 ) ;

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			VDP_fadeOutAll (10, true );

			u8 i=0;
			while ( VDP_isDoingFade() )
			{
				if ( i++ == 5 )
				{
					VDP_interruptFade();
					break;
				}

				VDP_waitVSync();
			}

			VDP_setTextPalette (PAL3);
			VDP_setPalette(PAL3, font_getPalette());


			psglist_play ( PSG_START );
			ret = SCREEN_JUMP_TO_NEWGAME;
			break;
		}

		VDP_waitVSync();

		++counter;
	}


//etiqueta_1:
//etiqueta_2:


	if ( ret == SCREEN_JUMP_TO_NEWGAME )
	{
		ret = screen_title_menu_1 ( );

		if ( ret == SCREEN_JUMP_TO_DIFFICULT )
		{
			//ret = screen_title_menu_2 ( );
			screen_title_menu_2 ( );
		}
	}

   VDP_fadeOutAll(60, false);

   tool_reset();
   resetScroll ();

   VDP_clearPlan ( APLAN, true );
   VDP_clearPlan ( BPLAN, true );


	return ret;
}



//void screen_chose_difficult()
//{
//   tool_reset();
//   resetScroll();
//   resetSprites();
//
//   psgfx_init ( );
//
//   u16 option = 0;
//
//   while ( true )
//   {
//      _aux_02 ( option );
//      waitMs(150);
//
//      u16 joy = JOY_waitPress ( JOY_1, BUTTON_BTN|BUTTON_UP|BUTTON_DOWN );
//
//      if ( joy & BUTTON_DOWN && option < 2 ) { option++; psglist_play ( PSG_SELECT_2 ); }
//      if ( joy & BUTTON_UP   && option > 0 ) { option--; psglist_play ( PSG_SELECT_2 ); }
//      if ( joy & BUTTON_BTN )
//      {
//         psglist_play ( PSG_START );
//
//         if ( option == 0 ) _blink("WIMPY!",     16, 19 );
//         if ( option == 1 ) _blink("TOUGH GUY!", 16, 21 );
//         if ( option == 2 ) _blink("NIGHTMARE!", 16, 23 );
//
//         gamestate.dificultad = option;
//
//         break;
//      }
//
//      VDP_waitVSync();
//   }
//
//
////	_blink_title_cnt = 0;
////	SYS_setVIntCallback ( (_voidCallback*) psgfx_init );
////
////
//////	// para centrar PRESS START /////
//////	tiles[20] = 0;
//////	VDP_setHorizontalScrollTile ( PLAN_A, 0, tiles, 28, 0 );
//////	VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );
//////	/////////////////////////////////
//
//
//
//	tool_planHide();
//
//	music_stop();
//
////	return ret;
//}
