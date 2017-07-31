#include "../inc/include.h"


void screen_griels ( )
{
    if ( DEV > 1 ) return;

    displayOff(0);
    resetScreen();
    music_stop();


    VDP_setTextPalette ( PAL0 );
    prepareColor (  1, 0xfff );
    prepareColor (  2, 0x444 );
    prepareColor ( 17, font_palette.data [ 7 ] );
    prepareColor ( 18, font_palette.data [ 8 ] );
    prepareColor ( 33, 0xfff );
    prepareColor ( 34, 0x444 );

    //	VDP_drawText ( "                 RK709EX                ",  0, 10 );
    //	VDP_drawText ( "                                        ",  0, 11 );
    //	VDP_drawText ( "     GRIEL'S QUEST FOR THE SANGRAAL     ",  0, 12 );
    //	VDP_drawText ( "                                        ",  0, 13 );
    //	VDP_drawText ( "          - EXTENDED EDITION -          ",  0, 14 );
    //	VDP_drawText ( "                                        ",  0, 15 );
    //	VDP_drawText ( "                                        ",  0, 16 );
    //	VDP_drawText ( "           26th December 2005           ",  0, 17 );

    u8 y = 4;

    VDP_setTextPalette ( PAL1 );
    text_write ( "              Griel's Quest             ",  0,  y+=2 );
    text_write ( prepare_string ("           for the Holy Porrón          "),  0, y+=2 );

    VDP_setTextPalette ( PAL2 );
    text_write ( "       For Sega Megadrive/Genesis       ",  0, y+=2 );
    text_write ( "              @2013 - 2017              ",  0, y+=2 );


    VDP_setTextPalette ( PAL1 );
    text_write ( "            Original game by            ",  0, y+=6 );

    VDP_setTextPalette ( PAL2 );
    text_write ( "           Karoshi Corporation          ",  0, y+=2 );
    text_write ( "                  @2005                 ",  0, y+=2 );

    displayOn(10);

    waitJoySc(6);

    displayOff(10);
    resetScreen();
}


