#include "../inc/include.h"


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


static u16 y;


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


static void writeText ( u8 *str, u16 pal, u8 inc_y )
{
    VDP_setTextPalette ( pal );

    u8 len = strlen(str);
    u8 x = 20 - len/2;

    SYS_disableInts();
    VDP_drawText ( prepare_string(str), x, y );
    SYS_enableInts();

    y += inc_y;
}


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


static void writeTextCredits1 ()
{
    writeText ( "Code", PAL1, 2 );
    writeText ( "Mun @MoonWatcherMD", PAL2, 4 );

    writeText ( "Graphics", PAL1, 2);
    writeText ( "Daniel Nevado @DanySnowyman", PAL2, 4 );

    writeText ( "Music & SFX", PAL1, 2 );
    writeText ( "David Sánchez @DavidBonus", PAL2, 4 );
}


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


static void writeTextCredits2 ()
{
    writeText ( "Testing", PAL1, 2 );
    writeText ( "Alfonso Martínez @_SrPresley_", PAL2, 2 );
    writeText ( "Jimy @TodoMegaDrive", PAL2, 4 );

    writeText ( "Translators", PAL1, 2 );
    writeText ( "Felipe Monge Corbalán @vakapp", PAL2, 2 );
    writeText ( "DaRkHoRaCe @oongamoonga", PAL2, 2 );
    writeText ( "KanedaFr @SpritesMind", PAL2, 2 );


}


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


static void writeTextCredits3 ()
{
    writeText ( "Thanks to", PAL1, 2 );
    writeText ( "Bruce Rodríguez @emigrantebruce", PAL2, 2 );
    writeText ( "Eduardo Robsy @EduRobsy", PAL2, 2 );
    writeText ( "Jon Cortazar @Jon_Cortazar ", PAL2, 4 );
}


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


static u16 writeCredits ( u8 part, u8 y_pos )
{
    y = y_pos;

    if ( part == 1 ) writeTextCredits1();
    if ( part == 2 ) writeTextCredits2();
    if ( part == 3 ) writeTextCredits3();

    displayOn(10);

    u16 ret = JOY_waitPressBtnTime(6000);

    displayOff ( 10 );

    resetScreen();

    return ret;
}


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */


void screen_credits ()
{
    if ( DEV > 1 ) return;

    music_stop();
    displayOff(0);
    resetScreen();

    VDP_setTextPalette ( PAL0 );
    prepareColor (  1, 0xfff );
    prepareColor (  2, 0x444 );
    prepareColor ( 17, font_palette.data [ 7 ] );
    prepareColor ( 18, font_palette.data [ 8 ] );
    prepareColor ( 33, 0xfff );
    prepareColor ( 34, 0x444 );

    writeCredits ( 1, 6 );
    writeCredits ( 2, 6 );
    writeCredits ( 3, 10 );

    waitSc(2);
}


/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

