#include "../inc/include.h"
#include "../inc/genres_externs.h"

void screen_oooklab ( )
{
	displayInit();
	displayOff(0);

    SYS_disableInts();

	resetScreen   ( );
	resetPalettes ( );
	resetScroll   ( );
	resetSprites  ( );

	VDP_loadTileData ( ob_logo_OookLab.tiles, HOW_TO_PLAY_TILE, ob_logo_OookLab.width * ob_logo_OookLab.height, 0 );
	VDP_fillTileMapRectInc ( BG_A, TILE_ATTR_FULL ( PAL0, 1, 0, 0, HOW_TO_PLAY_TILE ), 12, 8, ob_logo_OookLab.width, ob_logo_OookLab.height );
	preparePal ( PAL0, ob_logo_OookLab.pal );

    prepareColor(17, 0x000 );
    prepareColor(18, 0xddd );
    prepareColor(33, 0x00f );
    prepareColor(34, 0xddd );

    VDP_setTextPalette(PAL1);
    VDP_drawText("Mun @MoonWatcherMD", 11, 17 );
    VDP_drawText("Daniel Nevado @DanySnowyman", 7, 19 );
    VDP_drawText("David Sanchez @DavidBonus", 8, 21 );
    VDP_drawText("Alfonso Martinez @_SrPresley_", 6, 23 );

    VDP_setTextPalette(PAL2);
    VDP_drawText("@2013 - 2017", 14, 26 );

    SYS_enableInts();

	displayOn ( 10 );


    prepare_string("á");
    prepare_string("í");


	waitJoySc(6);

	planHide();

	displayOff(30);
}
