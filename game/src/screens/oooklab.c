#include "../inc/include.h"



void screen_oooklab ( u16 secs, u16 buttons, u8 on_release )
{
    if ( DEV > 1 ) return;

	displayInit();
	displayOff(0);

	SYS_disableInts();

	resetScreen   ( );
	resetPalettes ( );
	resetScroll   ( );
	resetSprites  ( );

	VDP_loadTileData ( ob_logo_OookLab.tiles, HOW_TO_PLAY_TILE, ob_logo_OookLab.width * ob_logo_OookLab.height, 0 );
	VDP_fillTileMapRectInc ( PLAN_A, TILE_ATTR_FULL ( PAL0, 1, 0, 0, HOW_TO_PLAY_TILE ), 12, 12, ob_logo_OookLab.width, ob_logo_OookLab.height );
	preparePal ( PAL0, ob_logo_OookLab.pal );

	SYS_enableInts();

	displayOn ( 5 );

	waitJoySc(3);

	planHide();

	displayOff(30);
}
