#include "../inc/include.h"
#include "../inc/colores_textos.h"




static void _blink ( u8 *str, const u16 x, const u16 y )
{
	u8 i   = ntsc2pal(15);
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
	s16 option = 0, ret = 0;
	const u8 pos[4] = { 19, 21, 23 };

	VDP_clearTextLine ( pos[0] );
	VDP_clearTextLine ( pos[1] );
	VDP_clearTextLine ( pos[2] );

	u8 f1[30];
	u8 f2[30];
	u8 f3[30];

	frases_init(27);

	strcpy ( f1, frases_next ( ) );
	strcpy ( f2, frases_next ( ) );
	strcpy ( f3, frases_next ( ) );

	VDP_drawText ( f1, 16, pos[0] ); // NEW GAME
	VDP_drawText ( f2, 16, pos[1] ); // CONTINUE
	VDP_drawText ( f3, 16, pos[2] ); // SOUND TEST

	while ( not ret )
	{
		VDP_clearTileMapRect ( PLAN_A, 14, pos[0], 1, pos[2]-pos[0]+1);
		VDP_drawText ( ">", 14, pos[option] );

		if ( joy1_pressed_down ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   ) { option--; psglist_play ( PSG_SELECT_2 ); }

		if ( option > 2 ) option = 0;
		if ( option < 0 ) option = 2;


		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			break;
		}

		VDP_waitVSync();
	}

	psglist_play ( PSG_START );

	if ( option == 0 ) { _blink ( f1, 16, 19 ); ret = SCREEN_JUMP_TO_DIFFICULT; }
	if ( option == 1 ) { _blink ( f2, 16, 21 ); ret = SCREEN_JUMP_TO_CONTINUE;  }
	if ( option == 2 ) { _blink ( f3, 16, 23 ); ret = SCREEN_JUMP_TO_SOUNDTEST; }

	return ret;
}


void screen_title_menu_2 ( )
{
	s16 option = 0;
	const u8 pos[4] = { 19, 21, 23 };

	VDP_clearTextLine ( pos[0] );
	VDP_clearTextLine ( pos[1] );
	VDP_clearTextLine ( pos[2] );

	u8 f1[30];
	u8 f2[30];
	u8 f3[30];

	frases_init ( 26 );

	strcpy ( f1, frases_next ( ) );
	strcpy ( f2, frases_next ( ) );
	strcpy ( f3, frases_next ( ) );

	VDP_drawText ( f1, 16, pos[0] ); // debilucho
	VDP_drawText ( f2, 16, pos[1] ); // tipo duro
	VDP_drawText ( f3, 16, pos[2] ); // pesadilla

	while ( true )
	{
		VDP_clearTileMapRect ( PLAN_A, 14, pos[0], 1, pos[2]-pos[0]+1);
		VDP_drawText ( ">", 14, pos[option] );

		if ( joy1_pressed_down ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   ) { option--; psglist_play ( PSG_SELECT_2 ); }

		if ( option > 2 ) option = 0;
		if ( option < 0 ) option = 2;

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			break;
		}

		VDP_waitVSync();
	}


	psglist_play ( PSG_START );

	if ( option == 0 ) _blink ( f1, 16, 19 );
	if ( option == 1 ) _blink ( f2, 16, 21 );
	if ( option == 2 ) _blink ( f3, 16, 23 );

	gamestate.current_round    = 0;
	gamestate.current_ambiente = 0;

	gamestate.dificultad = option;
	gamestate.ambientes[0] = 0;
	gamestate.ambientes[1] = 0;
	gamestate.ambientes[2] = 0;
	gamestate.ambientes[3] = 0;
	gamestate.ambientes[4] = 0;
}




u16 screen_title ( u16 salto )
{
   u16 ind = TILE_USERINDEX;


	if ( salto == 2 )
	{
		goto salto_2;
	}

   //psgfx_init();
	musiclist_play ( MUSIC_TITLE );



	displayInit();
	displayOff(0);

	SYS_disableInts();

	//resetVRAM();
	resetPalettes();
	resetScroll();
	resetScreen();
	resetSprites();


	font_init();




//   VDP_drawImageEx ( PLAN_B, &ob_title_title, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind),  4,  8, 0, true ); VDP_waitDMACompletion(); ind += ob_title_title.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_title_kbrah, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind),  8, -3, 0, true ); VDP_waitDMACompletion(); ind += ob_title_kbrah.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_title_notah, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind),  0, 13, 0, true ); VDP_waitDMACompletion(); ind += ob_title_notah.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_title_mano,  TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 11, 16, 0, true ); VDP_waitDMACompletion(); ind += ob_title_mano.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_title_griel, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, ind), 30, 13, 0, true ); VDP_waitDMACompletion();
	VDP_drawImageEx ( PLAN_B, &ob_title_title, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind),  4,  8, 0, 0 ); ind += ob_title_title.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_title_kbrah, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind),  8, -3, 0, 0 ); ind += ob_title_kbrah.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_title_notah, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind),  0, 13, 0, 0 ); ind += ob_title_notah.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_title_mano,  TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 11, 16, 0, 0 ); ind += ob_title_mano.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_title_griel, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, ind), 30, 13, 0, 0 );

	preparePal ( PAL0, ob_title_title.palette->data );
	preparePal ( PAL1, ob_title_kbrah.palette->data );
	preparePal ( PAL2, ob_title_notah.palette->data );
	preparePal ( PAL3, ob_title_griel.palette->data );

	SYS_enableInts();

	displayOn(30);

	waitSc(2);

	ind = TILE_USERINDEX;

	SYS_disableInts();
	//VDP_drawImageEx ( PLAN_B, &ob_title_title, TILE_ATTR_FULL(PAL0, true, FALSE, FALSE, ind),  4,  8, 1, true ); VDP_waitDMACompletion(); ind += ob_title_title.tileset->numTile;
	VDP_drawImageEx ( PLAN_B, &ob_title_title, TILE_ATTR_FULL(PAL0, true, FALSE, FALSE, ind),  4,  8, 1, 0 ); ind += ob_title_title.tileset->numTile;
	SYS_enableInts();

   VDP_fadePalOut ( PAL1, getHz(), false );
   VDP_fadePalOut ( PAL2, getHz(), false );
   VDP_fadePalOut ( PAL3, getHz(), false );

//   VDP_clearPlan ( PLAN_A, true ); VDP_waitDMACompletion();
   VDP_clearPlan ( PLAN_A, 0 );
   //WAITSECS1(1,etiqueta_1);


   waitMs(500);

   u8 i;

   for ( i=0; i<120; i++ )
   {
      VDP_setVerticalScroll ( PLAN_B, i/2 );
      VDP_waitVSync();
   }




	SYS_disableInts();
	//VDP_drawImageEx ( PLAN_B, &ob_title_subtitle, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 8, 24, false, true ); VDP_waitDMACompletion(); ind += ob_title_subtitle.tileset->numTile;
	VDP_drawImageEx ( PLAN_B, &ob_title_subtitle, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 8, 24, false, 0 ); ind += ob_title_subtitle.tileset->numTile;
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
	//VDP_drawImageEx ( PLAN_A, &ob_title_press_start, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 15, 23, 1, true ); VDP_waitDMACompletion();
	VDP_drawImageEx ( PLAN_A, &ob_title_press_start, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 15, 23, 1, 0 );
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
			VDP_setPalette ( PAL2, (u16*) palette_black );
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
			VDP_setPalette ( PAL2, (u16*) palette_black );
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
			screen_title_menu_2 ( );

			ret = SCREEN_JUMP_TO_AMBIENT;
		}
	}

	VDP_fadeOutAll(60, false);

	//tool_reset();
	resetScroll ();
	resetScreen();


	return ret;
}
