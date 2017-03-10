#include "../inc/include.h"
#include "../inc/colores_textos.h"




static void _blink ( u8 *str, u16 y )
{
	u8 i   = ntsc2pal(20);
	u8 len = strlen(str);
	u16 x  = 20 - len / 2;

	VDP_setTextPalette ( PAL2 );
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



static void _write ( u16 opcion, u16 index, u8 *f, u8 pos )
{
	VDP_setTextPalette ( opcion == index ? PAL2 : PAL3 );
	VDP_drawText ( f, 20-strlen(f)/2, pos );
}



static u16 _menu ( u16 frases )
{
	s16 option = 0;
	const u8 pos[4] = { 19, 21, 23 };

	VDP_clearTextLine ( pos[0] );
	VDP_clearTextLine ( pos[1] );
	VDP_clearTextLine ( pos[2] );

	u8 f1[30];
	u8 f2[30];
	u8 f3[30];

	frases_init ( frases );

	strcpy ( f1, frases_next ( ) );
	strcpy ( f2, frases_next ( ) );
	strcpy ( f3, frases_next ( ) );

	VDP_setPaletteColor ( 33, ct_color(7,0) );
	VDP_setPaletteColor ( 34, ct_color(7,1) );


	while ( true )
	{
		_write ( option, 0, f1, pos[0] );
		_write ( option, 1, f2, pos[1] );
		_write ( option, 2, f3, pos[2] );

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

	if ( option == 0 ) _blink ( f1, pos[option] );
	if ( option == 1 ) _blink ( f2, pos[option] );
	if ( option == 2 ) _blink ( f3, pos[option] );

	return option;
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
	VDP_drawImageEx ( PLAN_B, &ob_title_title, TILE_ATTR_FULL(PAL0, true, FALSE, FALSE, ind),  4,  8, 1, 0 ); ind += ob_title_title.tileset->numTile;
	SYS_enableInts();

	VDP_fadePalOut ( PAL1, getHz(), false );
	VDP_fadePalOut ( PAL2, getHz(), false );
	VDP_fadePalOut ( PAL3, getHz(), false );

	SYS_disableInts();
	VDP_clearPlan ( PLAN_A, 0 );
	SYS_enableInts();



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
		ret = _menu ( 27 );

		     if ( ret == 0 ) ret = SCREEN_JUMP_TO_DIFFICULT;
		else if ( ret == 1 ) ret = SCREEN_JUMP_TO_CONTINUE;
		else if ( ret == 2 ) ret = SCREEN_JUMP_TO_SOUNDTEST;

		if ( ret == SCREEN_JUMP_TO_DIFFICULT )
		{
			ret = _menu ( 26 );

			gamestate.current_round    = 0;
			gamestate.current_ambiente = 0;
			gamestate.dificultad       = ret;
			gamestate.ambientes[0]     = 0;
			gamestate.ambientes[1]     = 0;
			gamestate.ambientes[2]     = 0;
			gamestate.ambientes[3]     = 0;
			gamestate.ambientes[4]     = 0;

			ret = SCREEN_JUMP_TO_AMBIENT;
		}
	}

	VDP_fadeOutAll(60, false);


	resetScroll ();
	resetScreen();


	return ret;
}
