#include "../inc/include.h"



void screen_disclaimer ( )
{
	if ( DEV ) return;



	displayInit();
	displayOff(0);

	SYS_disableInts();

	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();

	VDP_drawImageEx ( PLAN_A, &ob_cs_disclaimer, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 16),  0, 0, 0, 0 );

	preparePal ( PAL1, ob_cs_disclaimer.palette->data );

	SYS_enableInts();

	displayOn(0);

	waitJoySc(3);

	displayOff(10);
}






