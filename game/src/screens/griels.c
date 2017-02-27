#include "../inc/include.h"


void screen_griels ( u16 secs, u16 buttons, u8 on_release )
{
   return;


   VDP_setEnable(false);
   resetScreen();


   VDP_setTextPalette ( PAL0 );
	VDP_setPaletteColor ( 1, 0xfff );

//	VDP_drawText ( "                 RK709EX                ",  0, 10 );
//	VDP_drawText ( "                                        ",  0, 11 );
//	VDP_drawText ( "     GRIEL'S QUEST FOR THE SANGRAAL     ",  0, 12 );
//	VDP_drawText ( "                                        ",  0, 13 );
//	VDP_drawText ( "          - EXTENDED EDITION -          ",  0, 14 );
//	VDP_drawText ( "                                        ",  0, 15 );
//	VDP_drawText ( "                                        ",  0, 16 );
//	VDP_drawText ( "           26th December 2005           ",  0, 17 );


	VDP_drawText ( "      GRIEL'S QUEST FOR THE PORRON      ",  0,  8 );
	VDP_drawText ( "       FOR SEGA MEGADRIVE/GENESIS       ",  0, 10 );

	VDP_drawText ( "          SPECIAL VERSION FOR           ",  0, 16 );
	VDP_drawText ( "             GAMESCOM  2016             ",  0, 18 );

	VDP_setEnable(true);

	waitJoySc(3);

   VDP_fadeOutAll(10, 0);
   resetScreen();
}


