#include "../../inc/include.h"
#include "../inc/genres_externs.h"


static void show_staff_title ( struct genresTiles *grt, u16 pal, u16 tile, VDPPlane plan, s16 x, u16 y, u16 fade, u16 wait )
{
	showBmp ( pal, (struct genresTiles*) grt, tile, plan, x, y, 0 );
    PAL_fadeToPalette( pal, grt->pal, fade, 0 );
    waitSc ( wait );
}


static s16 plan_x;
static s16 plan_y;

static VoidCallback *move1 ()
{
    if ( vtimer % 3 == 0 )
    {
        SYS_disableInts();
        VDP_setHorizontalScroll( BG_B, plan_x++ );
        SYS_enableInts();
    }

    return 0;
}

static VoidCallback *move3 ()
{
    if ( vtimer % 4 == 0 )
    {
        SYS_disableInts();
        VDP_setHorizontalScroll( BG_B, plan_x-- );
        SYS_enableInts();
    }

    return 0;
}

static VoidCallback *move2 ()
{
    if ( vtimer % 4 == 0 )
    {
        SYS_disableInts();
        VDP_setVerticalScroll( BG_B, plan_y-- );
        SYS_enableInts();
    }

    return 0;
}


static void palette_text_init()
{
    PAL_setColor (  1, 0xfff );
	PAL_setColor (  2, 0x444 );
    PAL_setColor ( 17, font_palette.data [ 7 ] );
	PAL_setColor ( 18, font_palette.data [ 8 ] );

}


void screen_staff()
{

    u16 i;
    u16 colors [ 64 ] = { };
    u8 wait1;

    u16 aux_planeHeight = planeHeight;
    u16 aux_planeWidth  = planeWidth;
    VDP_setPlaneSize(64,64, false);

    wait1 = ntsc2pal ( 69 );

    displayInit();
    displayOff(0);

    resetScreen();
    resetScroll();
    resetSprites();

    JoyReader_pause();

    palette_text_init();

	VDP_setTextPalette(PAL0);
    colors[1] = 0xfff;
    colors[2] = 0x444;
    colors[17] = 0x84f;
    colors[18] = 0x224;
    prepareColors(colors);


//goto salto;


    VDP_setHorizontalScroll(BG_A, 8);
	displayOn(0);


	bigtext_init ( (struct genresSprites*) &cs_font_16x16, 1200, PAL0 );
    bigtext_drawTile ( "GRIEL'S QUEST",   6,  6, wait1 ) ;
	bigtext_drawTile ( "FOR THE",        12,  9, wait1 ) ;
	bigtext_drawTile ( "HOLY PORRÓN",     8, 12, wait1 ) ;


	musiclist_play ( MUSIC_STAFF );
	XGM_setMusicTempo(50);

    VDP_setTextPlane(BG_B);
	typeText( "For Sega Genesis / Megadrive", 6, 21, wait1 ); // desp 4

	waitSc(3);
	planHide();
	displayOff(0);
    VDP_setTextPlane(BG_A);
    VDP_setHorizontalScroll(BG_A, 0);




	preparePal(PAL3, ob_logo_Karoshi.pal);
	memcpy(&colors[48], ob_logo_Karoshi.pal, 16*2 );
	prepareColors( colors );

    displayOn(0);

	typeText( "Based on", 16, 6, wait1);
	waitHz ( ntsc2pal(110) );

	showBmp ( PAL3, (struct genresTiles*) &ob_logo_Karoshi, HOW_TO_PLAY_TILE, BG_B, 12, 10, wait1 );


    u16 colores[17*3] =
	{
		 0, 0x111, 0, 0, 0x222, 5, 0, 0x333, 0, 0, 0x444, 5, 0, 0x555, 0, 0, 0x666, 5, 0, 0x777, 0, 0, 0x888, 5,
		 0, 0x999, 0, 0, 0xAAA, 5, 0, 0xBBB, 0, 0, 0xCCC, 5, 0, 0xDDD, 0, 0, 0xEEE, 5, 0, 0xFFF, 0, 0, 0x000, 5,
		49, 0xFFF, 0
	};

	for ( i=0; i<17*3; i+=3 )
	{
	    prepareColor( colores[i+0], colores[i+1] );
		PAL_setColor ( colores[i+0], colores[i+1] );
		if ( colores[i+2] ) SYS_doVBlankProcess();
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

    PAL_fadeOutAll(1,0);
    displayOn(0);


    show_staff_title ( (struct genresTiles*) &ob_staff_title_1, PAL0,  16, BG_A,  4,  2, getHz(), 1 );
    show_staff_title ( (struct genresTiles*) &ob_staff_title_2, PAL1, 600, BG_A,  8, 18, getHz(), 1 );

    waitSc(4);
    PAL_fadeOutAll ( getHz(), 0 );

    show_staff_title ( (struct genresTiles*) &ob_staff_title_3, PAL2, 800, BG_A, 18, 11, getHz(), 1 );

    waitSc(3);
    PAL_fadeOutAll ( getHz(), 0 );
    resetScreen();





    palette_text_init();

	VDP_setTextPalette(PAL1);
	typeText( "Graphics",   5, 10, wait1 );
	VDP_setTextPalette(PAL0);
	typeText( "Daniel Nevado",  5, 13, wait1 );
	typeText( "@DanySnowyman",  5, 15, wait1 );

	waitSc(1);

	showBmp ( PAL3, (struct genresTiles*) &ob_staff_griel, HOW_TO_PLAY_TILE, BG_B, 18, 2, wait1 );
    PAL_fadeToPalette( PAL3, ob_staff_griel.pal, getHz(), 1 );

    waitSc(4);

    plan_x = 0;
	SYS_setVIntCallback( (VoidCallback *)move1 );

	planHide_Ex(BG_A);
    PAL_fadeOutPalette( PAL3, getHz()*2, 0 );

    displayOff(0);
    SYS_setVIntCallback( NULL );
    resetScreen();
    resetScroll();

    waitSc(1);





	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbrah, HOW_TO_PLAY_TILE, BG_B, 13, 4, wait1 );
    PAL_fadeToPalette( PAL3, ob_staff_kbrah.pal, getHz(), 1 );

	palette_text_init();

	VDP_setTextPalette(PAL1);
	typeText( "Music & SFX",     5,  4, wait1 );
	VDP_setTextPalette(PAL0);
	typeText( "David Sánchez", 5, 7, wait1 );
	typeText( "@DavidBonus",   5, 9, wait1 );

	waitSc(5);

    plan_y = 0;
    SYS_setVIntCallback( (VoidCallback *)move2 );

	planHide_Ex(BG_A);
	PAL_fadeOutPalette( PAL3, getHz()*2,0 );

    displayOff(0);
    SYS_setVIntCallback( NULL );
    resetScreen();
    resetScroll();

    waitSc(1);



    palette_text_init();

	VDP_setTextPalette(PAL1);
	typeText( "Code",     23,  15, wait1 );
    VDP_setTextPalette(PAL0);
	typeText( "Mun", 23, 18, wait1 );
	typeText( "@MoonWatcherMD",   23, 20, wait1 );

	waitSc(2);

	showBmp ( PAL3, (struct genresTiles*) &ob_staff_notah, HOW_TO_PLAY_TILE, BG_B, 0, 1, wait1 );
    PAL_fadeToPalette( PAL3, ob_staff_notah.pal, getHz(), 0 );

    waitSc(4);
	planHide_Ex(BG_A);

	plan_x = 0;
	SYS_setVIntCallback( (VoidCallback *)move3 );
	PAL_fadeOutPalette( PAL3, getHz()*3,0 );
	SYS_setVIntCallback( NULL );

    displayOff(0);
    resetScreen();
    resetScroll();




    showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbrah2, HOW_TO_PLAY_TILE, BG_B, 19, 6, wait1 );
    PAL_fadeToPalette ( PAL3, ob_staff_kbrah2.pal, getHz(), 1 );

    palette_text_init();

    VDP_setTextPalette(PAL1);
    typeText( "Beta testing",     3,  3, wait1 );

    waitSc(1);

    VDP_setTextPalette(PAL0);
    typeText( "Alfonso Martínez", 3, 6, wait1 );
    typeText( "@_SrPresley_",     3, 8, wait1 );

    waitSc(4);
    planHide_Ex(BG_A);

    PAL_fadeOutPalette(  PAL3, getHz()*2, 0 );

    displayOff(0);
    resetScreen();
    resetScroll();

    waitSc(1);

    palette_text_init();

    u8 y = 2;

    SYS_disableInts();


    VDP_setTextPalette(PAL1);
    TEXT_drawText ( "Translators", 2, y ); y+=3;

    VDP_setTextPalette(PAL0);

    TEXT_drawText ( "Felipe Monge Corbalán @vakapp", 2, y ); y+=2;
    TEXT_drawText ( "DaRkHoRaCe @oongamoonga", 2, y ); y+=2; // ITALIAN
    TEXT_drawText ( "KanedaFr @SpritesMind", 2, y ); y+=2; // FRENCH
    TEXT_drawText ( "Jordi Montornés Solé @jordimontornes", 2, y ); y+=2; // CATAL�
    TEXT_drawText ( "Natsumi", 2, y ); y+=2; // FINNISH
    TEXT_drawText ( "Paspallas @PaspallasDev", 2, y ); y+=2; // GALEGO
    TEXT_drawText ( "Thiago F. Alves", 2, y ); y+=2; // BR-PORTUGUESE
//    TEXT_drawText ( "teaduckie", 2, y ); y+=2; // ESPERANTO & INTERLINGUA
    TEXT_drawText ( "Clare Eddleston", 2, y ); y+=2; // ENGLISH-REVIEWER
    TEXT_drawText ( "Xavier Bravo", 2, y ); y+=2;// ENGLISH-REVIEWER

    SYS_enableInts();

    waitSc(7);

    PAL_fadeOutAll(   getHz()*1, 0);

    planHide_Ex(BG_A);

    displayOff(0);
    resetScreen();
    resetScroll();


    showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbritah, HOW_TO_PLAY_TILE, BG_B, 1, 5, wait1 );
    PAL_fadeToPalette( PAL3, ob_staff_kbritah.pal, getHz()*2, 0 );

    palette_text_init();

	VDP_setTextPalette(PAL1);
    typeText ( "Thanks to", 22, 6, wait1 );

	VDP_setTextPalette(PAL0);
	typeText ( "Bruce Rodriguez", 22, 9, wait1 );
	typeText ( "@emigrantebruce", 22, 11, wait1 );
	typeText ( "Eduardo Robsy", 22, 14, wait1 );
	typeText ( "@EduRobsy",     22, 16, wait1 );
	typeText ( "Jon Cortazar",   22, 19, wait1 );
	typeText ( "@Jon_Cortazar",  22, 21, wait1 );
	waitSc(4);

	planHide_Ex(BG_A);
	PAL_fadeOutPalette(  PAL3, getHz()*1, 0 );
    displayOff(0);
    resetScreen();
    resetScroll();



	showBmp ( PAL3, (struct genresTiles*) &ob_staff_kbritah2, HOW_TO_PLAY_TILE, BG_B, 10, 8, wait1 );
    PAL_fadeToPalette( PAL3, ob_staff_kbritah2.pal, getHz()*2, 1 );

    palette_text_init();
    VDP_setTextPalette(PAL0);
	typeText ( "...and you", 15, 3, wait1 );

	VDP_setTextPalette(PAL1);
	typeText ( "Thanks for playing", 11, 6, wait1 );

	waitSc(10);
    displayOff(120);

    resetScreen();

	JoyReader_resume();
	music_stop();

    waitSc(2);

    VDP_setPlaneSize(aux_planeWidth,aux_planeHeight, false);
    SYS_setVIntCallback ( (VoidCallback*) vint_callback );
}

