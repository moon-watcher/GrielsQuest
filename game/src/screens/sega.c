#include "../inc/include.h"
#include "../inc/genres_externs.h"

void screen_sega()
{
	const struct
	{
		u16 pal[16];
		u16 wait;
	} logo[] = {
		//   UNUSED       2       3       4       5       6       7       8       9  UNUSED      11      12      13      14      15      16    WAIT
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, 500},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0777, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FFF, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0333, 0x0000, 0x0000, 0x0000, 0x0000, 0x0fff, 0x0777, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0fff, 0x0777, 0x0333, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0fff, 0x0777, 0x0333, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0fff, 0x0777, 0x0333, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0777, 0x0333, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0333, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  500},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0EA0},  100}, // 10
		{{0x0000, 0x0000, 0x0000, 0x0EA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E60},  100},
		{{0x0000, 0x0000, 0x0000, 0x0E60, 0x0000, 0x0EA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0A20},  100},
		{{0x0000, 0x0000, 0x0000, 0x0A20, 0x0000, 0x0E60, 0x0000, 0x0EA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0600},  100},
		{{0x0000, 0x0000, 0x0000, 0x0600, 0x0000, 0x0A20, 0x0EA0, 0x0E60, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0EA0, 0x0600, 0x0E60, 0x0A20, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0000, 0x0EA0, 0x0000, 0x0E60, 0x0000, 0x0A20, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0EA0, 0x0E60, 0x0000, 0x0A20, 0x0000, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0E60, 0x0A20, 0x0000, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0A20, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100},
		{{0x0000, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  100}, // 20
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},  500},
		{{0x0000, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0200},  100},
		{{0x0000, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400},  100},
		{{0x0000, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0600},  100},
		{{0x0000, 0x0600, 0x0600, 0x0600, 0x0900, 0x0920, 0x0920, 0x0920, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0600},  100},
		{{0x0000, 0x0600, 0x0600, 0x0900, 0x0920, 0x0B20, 0x0940, 0x0B70, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0600},  100},
		{{0x0000, 0x0600, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0B70, 0x0D90, 0x0222, 0x0000, 0x0222, 0x0222, 0x0222, 0x0222, 0x0222, 0x0600},  100},
		{{0x0000, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0F70, 0x0E90, 0x0EB0, 0x0333, 0x0000, 0x0333, 0x0333, 0x0333, 0x0333, 0x0333, 0x0600},  100},
		{{0x0000, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0F70, 0x0D90, 0x0FB0, 0x0444, 0x0000, 0x0444, 0x0444, 0x0444, 0x0444, 0x0444, 0x0600},  100},
		{{0x0000, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0F70, 0x0D90, 0x0FB0, 0x0676, 0x0000, 0x0676, 0x0676, 0x0676, 0x0676, 0x0676, 0x0600},  100}, // 30
		{{0x0000, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0F70, 0x0D90, 0x0FB0, 0x0999, 0x0000, 0x0999, 0x0999, 0x0999, 0x0999, 0x0999, 0x0600},  100},
		{{0x0000, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0F70, 0x0D90, 0x0FB0, 0x0DDD, 0x0000, 0x0DDD, 0x0DDD, 0x0DDD, 0x0DDD, 0x0DDD, 0x0600},  100},
		{{0x0000, 0x0600, 0x0900, 0x0B20, 0x0D40, 0x0F70, 0x0D90, 0x0FB0, 0x0FFF, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0600}, 4000},
		{{0x0000, 0x0400, 0x0400, 0x0600, 0x0920, 0x0940, 0x0940, 0x0970, 0x0999, 0x0000, 0x0999, 0x0999, 0x0999, 0x0999, 0x0999, 0x0400},  100},
		{{0x0000, 0x0200, 0x0200, 0x0400, 0x0400, 0x0620, 0x0420, 0x0640, 0x0676, 0x0000, 0x0676, 0x0676, 0x0676, 0x0676, 0x0676, 0x0200},  100},
		{{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},    0},
	};

	displayInit();
	displayOff(0);

	SYS_disableInts();
	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();

	VDP_loadTileData(ob_logo_Sega.tiles, HOW_TO_PLAY_TILE, ob_logo_Sega.width * ob_logo_Sega.height, 0);
	VDP_fillTileMapRectInc(BG_A, TILE_ATTR_FULL(PAL1, 1, 0, 0, HOW_TO_PLAY_TILE), 14, 12, ob_logo_Sega.width, ob_logo_Sega.height);

	SYS_enableInts();

	u16 i = 0;

	while (logo[i].wait)
	{
		SYS_disableInts();
		PAL_setPalette(PAL1, logo[i].pal, CPU);
		SYS_enableInts();

		waitJoyHz(logo[i].wait / 17);

		if (joy1_pressed_abc | joy1_pressed_start)
			break;

		++i;
	}

	displayOff(10);
}
