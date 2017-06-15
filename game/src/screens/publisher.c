#include "../../inc/include.h"
//#include "../../res/all/screens.h"

#define IMAGES  1


void screen_publisher ( )
{
    if ( DEV > 1 ) return;

	displayOff(0);

	VDP_setScreenWidth320();
	VDP_setPlanSize ( 64, 32 );

//	palette_init();
	vram_init ( VRAM_DEFAULT );

	resetScroll();
	resetScreen();


	const u16 x = 12;
	const u16 y = 8;


	u16 i, vram_pos [ IMAGES ];

//
//
//    VDP_setPalette(PAL2, cs_publisher_1.pal) ;
//
//
//    u16 pos1 = 400;
//    u16 pos2 = 404;
//
//	VDP_loadTileData ( cs_publisher_1.sprites[0], pos1, 3, 0 );
//	VDP_loadTileData ( cs_publisher_2.sprites[0], pos2, 3, 0 );
//
//	VDP_setSpriteFull ( 0, 160,  94, 3, TILE_ATTR_FULL(PAL2, 0,0,0, pos1 ), 1 );
//	VDP_setSpriteFull ( 1, 160,  73, 3, TILE_ATTR_FULL(PAL2, 0,0,0, pos1 ), 0 );
//    //VDP_setSpriteLink(0,1);
//
//
//
//
//	VDP_updateSprites(80, 0);
//	VDP_waitVSync();
//
//



	Image *images [ IMAGES ] =
	{
		(Image*) &screen_publisher_00
	};

	for ( i=0; i<IMAGES; i++ )
	{
		u16 size = images[i]->tileset->numTile;
		vram_pos [ i ] = vram_new ( size );
		VDP_loadTileData ( images[i]->tileset->tiles, vram_pos[i], size, 0 );
	}


	waitHz(20);

	for ( i=0; i<IMAGES; i++ )
	{
		waitHz(3);

		SYS_disableInts();
		VDP_setPalette ( PAL1, images[i]->palette->data );
		VDP_setMap ( PLAN_A, images[i]->map,TILE_ATTR_FULL ( PAL1, 0, 0, 0, vram_pos[i] ), x, y );
		SYS_enableInts();
	}

	vram_destroy();

	waitJoySc(6);

	displayOff(10);
	//musicStop ( );
}
