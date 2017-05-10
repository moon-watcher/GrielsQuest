#include "../../inc/include.h"


void screen_staff()
{
    displayInit();
    displayOff(0);
    resetScreen();
    JoyReader_pause();

	u16 i;
	u8 wait1 = ntsc2pal ( 69 );
	u16 colors [ 64 ] = { };

	musiclist_play ( MUSIC_STAFF );
	XGM_setMusicTempo(50);



	VDP_setTextPalette(PAL0);
    colors[1] = 0xfff;
    colors[2] = 0x444;
    colors[17] = 0x84f;
    colors[18] = 0x224;
    prepareColors(colors);


//    goto salto;


	displayOn(0);

	text_init ( (struct genresSprites*) &cs_font_16x16, 1200, PAL0 );
    text_draw ( "GRIEL'S QUEST",    6,  8, wait1 ) ;
	text_draw ( "FOR THE SANGRAAL", 4, 12, wait1 ) ;

	typeText( "For Sega Genesis / Megadrive", 6, 21, wait1 ); // desp 4

	waitSc(3);
	planHide();
	displayOff(0);





	preparePal(PAL3, ob_logo_Karoshi.pal);
	memcpyU16(&colors[48], ob_logo_Karoshi.pal, 16 );
	prepareColors( colors );

    displayOn(0);

	typeText( "Based on", 16, 6, wait1);
	waitHz ( ntsc2pal(100) );

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

	typeText( "  Griel's Quest ", 12, 17, wait1 );
	typeText( "for the Sangraal", 12, 19, wait1 );
	typeText( "Extended Edition", 12, 21, wait1 );
	typeText( "    for MSX     ", 12, 23, wait1 );


	waitSc(3);
	planHide();
    displayOff(0);


goto salto;
salto:

    displayOn(0);

    preparePal(PAL3, ob_staff_griel.pal);
	memcpyU16(&colors[48], ob_staff_griel.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_griel, HOW_TO_PLAY_TILE, PLAN_B, 18, 2, wait1 );
    VDP_fadeAllTo ( getColors(), getHz(), 1 );


	VDP_setTextPalette(PAL1);
	typeText( "Graphics",   7, 10, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "Daniel Nevado",  7, 13, wait1 );
	typeText( "@DanySnowyman",  7, 15, wait1 );

	waitSc(3);
	planHide_Ex(PLAN_A);
    displayOff(0);
    resetScreen();






    preparePal(PAL3, ob_staff_kbrah.pal);
	memcpyU16(&colors[48], ob_staff_kbrah.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbrah, HOW_TO_PLAY_TILE, PLAN_B, 10, 4, wait1 );
    VDP_fadeAllTo ( getColors(), getHz(), 1 );

	VDP_setTextPalette(PAL1);
	typeText( "Music & SFX",     5,  5, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "David Sanchez", 5, 8, wait1 );
	typeText( "@DavidBonus",   5, 10, wait1 );

	waitSc(3);
	planHide_Ex(PLAN_A);
    displayOff(0);
    resetScreen();





    preparePal(PAL3, ob_staff_notah.pal);
	memcpyU16(&colors[48], ob_staff_notah.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_notah, HOW_TO_PLAY_TILE, PLAN_B, 0, 1, wait1 );
    VDP_fadeAllTo ( getColors(), getHz(), 1 );

	VDP_setTextPalette(PAL1);
	typeText( "Code",     23,  15, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText( "Mun", 23, 18, wait1 );
	typeText( "@MoonWatcherMD",   23, 20, wait1 );

	waitSc(3);
	planHide_Ex(PLAN_A);
    displayOff(0);
    resetScreen();






    preparePal(PAL3, ob_staff_kbrah2.pal);
    memcpyU16(&colors[48], ob_staff_kbrah2.pal, 16 );
    prepareColors( colors );
    showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbrah2, HOW_TO_PLAY_TILE, PLAN_B, 11, -5, wait1 );
    VDP_fadeAllTo ( getColors(), getHz(), 1 );

    VDP_setTextPalette(PAL1);
    typeText( "Beta testing",     3,  3, wait1 );

    waitSc(1);

    VDP_setTextPalette(PAL0);
    typeText( "Alfonso Martinez", 3, 7, wait1 );
    typeText( "@_SrPresley_",     3, 9, wait1 );
//    waitSc(1);
//    typeText( "Alfonso Martinez", 3, 13, wait1 );
//    typeText( "@_SrPresley_",     3, 15, wait1 );
//    waitSc(1);
//    typeText( "Alfonso Martinez", 3, 19, wait1 );
//    typeText( "@_SrPresley_",     3, 21, wait1 );
    waitSc(3);
    planHide_Ex(PLAN_A);
    displayOff(0);
    resetScreen();





    preparePal(PAL3, ob_staff_beach.pal);
	memcpyU16(&colors[48], ob_staff_beach.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_beach, HOW_TO_PLAY_TILE, PLAN_B, 16, 10, wait1 );
    VDP_fadeAllTo ( getColors(), getHz(), 1 );

	VDP_setTextPalette(PAL1);
	typeText( "Thank to",     8,  5, wait1 );

	waitSc(1);

	VDP_setTextPalette(PAL0);
	typeText ( "Bruce Rodriguez", 8, 9, wait1 );
	waitSc(1);

	typeText ( "Eduardo Robsy", 8, 11, wait1 );
	waitSc(1);

	typeText ( "Jon Cortazar",  8, 13, wait1 );
	waitSc(1);

	planHide_Ex(PLAN_A);
    displayOff(0);
    resetScreen();







    preparePal(PAL3, ob_staff_kbritah.pal);
	memcpyU16(&colors[48], ob_staff_kbritah.pal, 16 );
	prepareColors( colors );
	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbritah, HOW_TO_PLAY_TILE, PLAN_B, 8, 5, wait1 );
    VDP_fadeAllTo ( getColors(), getHz(), 1 );

    VDP_setTextPalette(PAL0);
	typeText ( "...and you", 15, 3, wait1 );
	typeText ( "Thanks for playing", 11, 6, wait1 );

	waitSc(10);
    VDP_fadeOutAll ( 120, 1 );
    waitHz ( 121 );

    resetScreen();

	JoyReader_resume();
	music_stop();

    waitSc(2);
}

