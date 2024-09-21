#include "../../inc/include.h"

void screen_publisher_POR( )
{
    displayOff(0);

    VDP_setScreenWidth320();
    VDP_setPlaneSize(64, 32, false);
    resetScroll();
    resetScreen();

    VDP_drawImageEx(BG_A, &logo_POR_bgA, TILE_ATTR_FULL(PAL1, 0, 0, 0, 16), 0, 0, 0, 0);
    preparePal(PAL1, logo_POR_bgA.palette->data);
    
    displayOn(10);
    waitJoySc(6);
    displayOff(10);
}