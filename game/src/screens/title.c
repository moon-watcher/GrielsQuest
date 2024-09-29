#include "../inc/include.h"
#include "../inc/colores_textos.h"
#include "../../libs/psg.h"




static void _blink ( u8 *str, const u16 x, const u16 y )
{
	u8 i   = ntsc2pal(15);
	u8 len = strlen(str);

	SYS_disableInts();
	TEXT_drawText ( str, x, y );
	SYS_enableInts();

	while ( i-- )
	{
        SYS_disableInts();

		if ( i % 2  )
		{
			VDP_clearText ( x, y, len );
		}
		else
		{
			TEXT_drawText ( str, x, y );
		}

        SYS_enableInts();

		SYS_doVBlankProcess();
		SYS_doVBlankProcess();
	}

	SYS_disableInts();
	TEXT_drawText ( str, x, y );
    SYS_enableInts();
}







u16 screen_title_menu_1 ( )
{
	s16 option = 0, ret = 0;
	const u8 pos[4] = { 19, 21, 23 };

    SYS_disableInts();
	VDP_clearTextLine ( pos[0] );
	VDP_clearTextLine ( pos[1] );
	VDP_clearTextLine ( pos[2] );
    SYS_enableInts();

	u8 f1[30];
	u8 f2[30];
	u8 f3[30];

	frases_init(27);

	strcpy ( f1, frases_next ( ) );
	strcpy ( f2, frases_next ( ) );
	strcpy ( f3, frases_next ( ) );

	SYS_disableInts();
	TEXT_drawText ( f1, 16, pos[0] ); // NEW GAME
	TEXT_drawText ( f2, 16, pos[1] ); // CONTINUE
	TEXT_drawText ( f3, 16, pos[2] ); // SOUND TEST
    SYS_enableInts();

	while ( not ret )
	{
	    JoyReader_update();

	    SYS_disableInts();
		VDP_clearTileMapRect ( BG_A, 14, pos[0], 1, pos[2]-pos[0]+1);
		TEXT_drawText ( ">", 14, pos[option] );
		SYS_enableInts();

		if ( joy1_pressed_down ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   ) { option--; psglist_play ( PSG_SELECT_2 ); }

		if ( option > 2 ) option = 0;
		if ( option < 0 ) option = 2;

		if (joy1_pressed_abcs)
		{
			break;
		}

		SYS_doVBlankProcess();
	}

	psglist_play ( PSG_START );

	if ( option == 0 ) { _blink ( f1, 16, pos[0] ); ret = SCREEN_JUMP_TO_DIFFICULT; }
	if ( option == 1 ) { _blink ( f2, 16, pos[1] ); ret = SCREEN_JUMP_TO_CONTINUE;  }
	if ( option == 2 ) { _blink ( f3, 16, pos[2] ); ret = SCREEN_JUMP_TO_SOUNDTEST; }

	return ret;
}


void screen_title_menu_2 ( )
{
	s16 option = 0;
	const u8 pos[4] = { 19, 21, 23 };

	SYS_disableInts();
	VDP_clearTextLine ( pos[0] );
	VDP_clearTextLine ( pos[1] );
	VDP_clearTextLine ( pos[2] );
	SYS_enableInts();

	u8 f1[30];
	u8 f2[30];
	u8 f3[30];

	frases_init ( 26 );

	strcpy ( f1, frases_next ( ) );
	strcpy ( f2, frases_next ( ) );
	strcpy ( f3, frases_next ( ) );

    SYS_disableInts();
	TEXT_drawText ( f1, 16, pos[0] ); // debilucho
	TEXT_drawText ( f2, 16, pos[1] ); // tipo duro
	TEXT_drawText ( f3, 16, pos[2] ); // pesadilla
	SYS_enableInts();

	while ( true )
	{
        JoyReader_update();

	    SYS_disableInts();
		VDP_clearTileMapRect ( BG_A, 14, pos[0], 1, pos[2]-pos[0]+1);
		TEXT_drawText ( ">", 14, pos[option] );
		SYS_enableInts();

		if ( joy1_pressed_down ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   ) { option--; psglist_play ( PSG_SELECT_2 ); }

		if ( option > 2 ) option = 0;
		if ( option < 0 ) option = 2;

		if (joy1_pressed_abcs)
		{
			break;
		}

		SYS_doVBlankProcess();
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
    u16 ind = TILE_USER_INDEX;


    if ( salto == 2 )
    {
        goto salto_2;
    }

    displayInit();
    displayOff(0);

    resetPalettes();
    resetScroll();
    resetScreen();
    resetSprites();

    font_init();

    SYS_disableInts();
    VDP_drawImageEx ( BG_B, &ob_title_title, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind),  4,  8, 0, 0 ); ind += ob_title_title.tileset->numTile;
    VDP_drawImageEx ( BG_A, &ob_title_kbrah, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind),  8, -3, 0, 0 ); ind += ob_title_kbrah.tileset->numTile;
    VDP_drawImageEx ( BG_A, &ob_title_notah, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind),  0, 13, 0, 0 ); ind += ob_title_notah.tileset->numTile;
    VDP_drawImageEx ( BG_A, &ob_title_mano,  TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 11, 16, 0, 0 ); ind += ob_title_mano.tileset->numTile;
    VDP_drawImageEx ( BG_A, &ob_title_griel, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, ind), 30, 13, 0, 0 );
    SYS_enableInts();

    preparePal ( PAL0, ob_title_title.palette->data );
    preparePal ( PAL1, ob_title_kbrah.palette->data );
    preparePal ( PAL2, ob_title_notah.palette->data );
    preparePal ( PAL3, ob_title_griel.palette->data );

    VDP_setTextPalette ( PAL0 );

    SYS_disableInts();
    TEXT_drawText ( "@2017, 2025 Oook!Lab", 10, 26 );
    SYS_enableInts();


    displayOn(30);

    //psgfx_init();
    musiclist_play ( MUSIC_TITLE );

    waitSc(2);

    ind = TILE_USER_INDEX;

    SYS_disableInts();
    VDP_drawImageEx ( BG_B, &ob_title_title, TILE_ATTR_FULL(PAL0, true, FALSE, FALSE, ind),  4,  8, 1, 0 ); ind += ob_title_title.tileset->numTile;
    SYS_enableInts();

    PAL_fadeOutPalette ( PAL1, getHz(), false );
    PAL_fadeOutPalette ( PAL2, getHz(), false );
    PAL_fadeOutPalette ( PAL3, getHz(), false );

    SYS_disableInts();
    VDP_clearPlane ( BG_A, 1 );
    SYS_enableInts();

    waitMs(500);

    u8 i;

    for ( i=0; i<120; i++ )
    {
        VDP_setVerticalScroll ( BG_B, i/2 );
        SYS_doVBlankProcess();
    }




    SYS_disableInts();
    VDP_drawImageEx ( BG_B, &ob_title_subtitle, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 8, 24, false, 0 ); ind += ob_title_subtitle.tileset->numTile;
    SYS_enableInts();


salto_2:


    PAL_fadeToPalette ( PAL1, ob_title_subtitle.palette->data, getHz(), false );


    //WAITSECS1(1,etiqueta_1);
    waitMs(100);


    //JOY_setEventHandler( &_readJOY );

    s16 tiles[28] = { };
    tiles[20] = -4;

    u16 counter = 0;
    u16 ret     = 0;
    u16 blink   = 0;
    u16 hz      = ntsc2pal ( 60 );


    SYS_disableInts();
    VDP_drawImageEx ( BG_A, &ob_title_press_start, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 15, 23, 1, 0 );
    SYS_enableInts();



    while ( true )
    {
        JoyReader_update();

        if ( counter % hz == 0 )
        {
            SYS_disableInts();
            PAL_setPalette ( PAL2, ob_title_press_start.palette->data, CPU ); // tool_setPalette (PAL2, ob_title_press_start.palette->data );
            SYS_enableInts();

            blink = 0;
        }

        if ( ++blink == 45 )
        {
            SYS_disableInts();
            PAL_setPalette ( PAL2, (u16*) palette_black, CPU );
            SYS_enableInts();
        }

        if ( counter == hz * 20 ) // 20 segundos de espera y si no salta de nuevo a Ooklab
        {
            ret = SCREEN_JUMP_TO_INTRO;
            break;
        }

        if (joy1_pressed_abcs)
        {
            SYS_disableInts();
            PAL_setPalette ( PAL2, (u16*) palette_black, CPU );
            SYS_enableInts();

            PAL_fadeOutAll (10, true );
            waitHz(5);
            PAL_interruptFade();

            SYS_disableInts();
            VDP_setTextPalette (PAL3);
            PAL_setPalette(PAL3, font_getPalette(), CPU);
            SYS_enableInts();

            psglist_play ( PSG_START );
            ret = SCREEN_JUMP_TO_NEWGAME;
            break;
        }

        ++counter;

        SYS_doVBlankProcess();
	}




    if ( ret == SCREEN_JUMP_TO_NEWGAME )
    {
        ret = screen_title_menu_1 ( );

        if ( ret == SCREEN_JUMP_TO_DIFFICULT )
        {
            screen_title_menu_2 ( );

            ret = SCREEN_JUMP_TO_MAP;
        }
    }

    music_stop();
	waitSc(1);

	displayOff (30);
	psg_pause();

    resetScroll ();
    resetScreen();

    return ret;
}
