#include "../../inc/include.h"

void screen_disclaimer_simple(void)
{
	VDP_drawImageEx(BG_A, &ob_cs_disclaimer, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 16), 0, 0, 0, 0);
	preparePal(PAL1, ob_cs_disclaimer.palette->data);

	displayOn(0);
	waitJoySc(3);

	displayOff(5);
}