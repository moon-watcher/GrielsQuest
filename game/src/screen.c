#include "../inc/include.h"







void screen_staff()
{
    displayInit();

    displayOff(0);

	u16 i;
	u8 wait1 = ntsc2pal ( 69 );
	u16 colors [ 64 ] = { };

    font_init();
	musiclist_play ( MUSIC_STAFF );
	XGM_setMusicTempo(50);


//	u16 tiles[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	VDP_setScrollingMode ( HSCROLL_TILE, VSCROLL_PLANE );

	//static const u16 _pal [ 16 ] = { 0x0000, 0x00FF, 0x0044, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };
	//VDP_setPalette ( PAL2, _pal );


	VDP_setTextPalette(PAL0);
    colors[1] = 0x00f;
    colors[2] = 0x008;
    colors[17] = 0x84f;
    colors[18] = 0x448;
    prepareColors(colors);

//goto salto;

//	tiles[8] = 8;
//	tiles[9] = 8;
//	tiles[22] = 4;
//	tiles[24] = 4;
//
//	VDP_setHorizontalScrollTile ( PLAN_A, 0, tiles, 28, 0 );

	displayOn(0);

	text_init ( (struct genresSprites*) &cs_font_16x16, 1200, PAL0 );
    text_draw ( "GRIEL'S QUEST",    6, 8, wait1 ) ;
	text_draw ( "FOR THE SANGRAAL", 4, 12, wait1 ) ;

	typeText( "For Sega Genesis / Megadrive", 6, 21, wait1 ); // desp 4

	waitMs(ntsc2pal(3000));
	planHide();
	displayOff(0);



	///////////////////////////



//	tiles[9]  = 0;
//	tiles[8]  = 0;
//	tiles[17] = 4;
//	tiles[22] = 0;
//	tiles[24] = 0;
//
//	VDP_setHorizontalScrollTile ( PLAN_A, 0, tiles, 28, 0 );

	preparePal(PAL3, ob_logo_Karoshi.pal);
	memcpyU16(&colors[48], ob_logo_Karoshi.pal, 16 );
	prepareColors( colors );

    displayOn(0);

	typeText( "Based on", 16, 6, wait1);

	showBmp ( PAL3, (struct genresTiles*) &ob_logo_Karoshi, HOW_TO_PLAY_TILE, PLAN_B, 12, 10, wait1 );


    u16 colores[17*3] =
	{
		 0, 0x111, 0, 0, 0x222, 5, 0, 0x333, 0, 0, 0x444, 5, 0, 0x555, 0, 0, 0x666, 5, 0, 0x777, 0, 0, 0x888, 5,
		 0, 0x999, 0, 0, 0xAAA, 5, 0, 0xBBB, 0, 0, 0xCCC, 5, 0, 0xDDD, 0, 0, 0xEEE, 5, 0, 0xFFF, 0, 0, 0x000, 5,
		49, 0xFFF, 0
	};

	for ( i=0; i<17*3; i+=3 )
	{
	    prepareColor( colores[i+0], colores[i+1] );
		VDP_setPaletteColor ( colores[i+0], colores[i+1] );
		if ( colores[i+2] ) VDP_waitVSync();
	}

	displayOn(0);

	typeText( "Griel's Quest",    13, 17, wait1 );
	typeText( "for the Sangraal", 12, 19, wait1 );
	typeText( "Extended Edition", 12, 21, wait1 );


	waitMs(ntsc2pal(3000));
	planHide();




	//////////////////////////////


//	tiles[17] = 0;
//
//	VDP_setHorizontalScrollTile ( PLAN_A, 0, tiles, 28, 0 );
	//VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE ); // --> no parece funcionar

	VDP_setReg(0x0B, 0);//  resete el scroll


	VDP_setHorizontalScroll ( PLAN_A, 0 );
	VDP_setHorizontalScroll ( PLAN_B, 0 );


	//////////////////////////////


	//showBmp_bn ( PAL1, (struct genresTiles*) &ob_title_2, HOW_TO_PLAY_TILE, BPLAN, 8, 12, wait1 );
	//SYS_setVIntCallback ( (_voidCallback*) _desplazar_fondo );


	//////////////////////////////

salto:

    displayOn(0);

    preparePal(PAL3, ob_staff_griel.pal);
	memcpyU16(&colors[48], ob_staff_griel.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_griel, HOW_TO_PLAY_TILE, PLAN_B, 18, 2, wait1 );

    displayOn(60);

	VDP_setTextPalette(PAL1);
	typeText( "Graphics, sprites",   7, 10, wait1 );
	typeText( "and background",      7, 12, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "Daniel Nevado",  7, 15, wait1 );
	typeText( "@DaniSnowyman",  7, 17, wait1 );

	waitMs(ntsc2pal(3000));
	planHide_Ex(PLAN_A);
    displayOff(0);
    VDP_clearPlan(PLAN_A, 1);
	VDP_clearPlan(PLAN_B, 1);






    preparePal(PAL3, ob_staff_kbrah.pal);
	memcpyU16(&colors[48], ob_staff_kbrah.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbrah, HOW_TO_PLAY_TILE, PLAN_B, 10, 4, wait1 );
    displayOn(60);

	VDP_setTextPalette(PAL1);
	typeText( "Music & sfx",     5,  5, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "David Sanchez", 5, 10, wait1 );
	typeText( "@DavidBonus",   5, 12, wait1 );

	waitMs(ntsc2pal(3000));
	planHide_Ex(PLAN_A);
    displayOff(0);
    VDP_clearPlan(PLAN_A, 1);
	VDP_clearPlan(PLAN_B, 1);





    preparePal(PAL3, ob_staff_notah.pal);
	memcpyU16(&colors[48], ob_staff_notah.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_notah, HOW_TO_PLAY_TILE, PLAN_B, 0, 1, wait1 );
    displayOn(60);

	VDP_setTextPalette(PAL1);
	typeText( "Code",     23,  15, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "Mun", 23, 19, wait1 );
	typeText( "@MoonWatcherMD",   23, 21, wait1 );

	waitMs(ntsc2pal(3000));
	planHide_Ex(PLAN_A);
    displayOff(0);
    VDP_clearPlan(PLAN_A, 1);
	VDP_clearPlan(PLAN_B, 1);






    preparePal(PAL3, ob_staff_kbrah2.pal);
	memcpyU16(&colors[48], ob_staff_kbrah2.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbrah2, HOW_TO_PLAY_TILE, PLAN_B, 11, -5, wait1 );
    displayOn(60);

	VDP_setTextPalette(PAL1);
	typeText( "Beta testing",     3,  3, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "Alfonso Martinez", 3, 7, wait1 );
	typeText( "@_SrPresley_",   3, 9, wait1 );
	waitSc(1);
    typeText( "Alfonso Martinez", 3, 13, wait1 );
	typeText( "@_SrPresley_",   3, 15, wait1 );
	waitSc(1);
    typeText( "Alfonso Martinez", 3, 19, wait1 );
	typeText( "@_SrPresley_",   3, 21, wait1 );
    waitMs(ntsc2pal(3000));
	planHide_Ex(PLAN_A);
    displayOff(0);
    VDP_clearPlan(PLAN_A, 1);
	VDP_clearPlan(PLAN_B, 1);





    preparePal(PAL3, ob_staff_beach.pal);
	memcpyU16(&colors[48], ob_staff_beach.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_beach, HOW_TO_PLAY_TILE, PLAN_B, 16, 10, wait1 );
    displayOn(60);

	VDP_setTextPalette(PAL1);
	typeText( "Thank to",     8,  5, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	VDP_drawText ( "Brusito",                10,  9 );
	waitMs(ntsc2pal(3000));

	VDP_drawText ( "Eduardo Robsy",          10, 11 );
	waitMs(ntsc2pal(3000));

	VDP_drawText ( "Jon Cortazar",           10, 13 );
	waitMs(ntsc2pal(3000));

	planHide_Ex(PLAN_A);
    displayOff(0);
    VDP_clearPlan(PLAN_A, 1);
	VDP_clearPlan(PLAN_B, 1);





/*
	VDP_setPalette(PAL0,palette_black);

	VDP_drawText ( "Thank to:",               8,  5 );
//	VDP_drawText ( "People at SpritesMind",  10, 15 );
//	VDP_drawText ( "Stef Dallongevile",      10, 17 );
//	VDP_drawText ( "Shiru",                  10, 19 );

	VDP_fadePalIn ( PAL0, font_getPalette(), 60, 1 );
	VDP_waitFadeCompletion();

	VDP_setPalette ( PAL0, font_getPalette() );
*/




    preparePal(PAL3, ob_staff_kbritah.pal);
	memcpyU16(&colors[48], ob_staff_kbritah.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbritah, HOW_TO_PLAY_TILE, PLAN_B, 8, 5, wait1 );
    displayOn(60);

    VDP_setTextPalette(PAL0);
	VDP_drawText ( "...and you", 15, 4 );

	waitMs(ntsc2pal(3000));
	planHide_Ex(PLAN_A);
    displayOff(0);
    VDP_clearPlan(PLAN_A, 1);
	VDP_clearPlan(PLAN_B, 1);

//	VDP_drawText ( "...and you", 15, 13 );
//	VDP_drawText ( "Thanks for playing", 11, 15 );




	//_wait ( 5, BUTTON_ALL, 0 );
	waitMs(5000);


	planHide();
}
