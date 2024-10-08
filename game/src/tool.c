#include "../inc/include.h"

#define PLAN_HIDE_HZ 1

void planHide_Ex (  VDPPlane plan )
{
	u16 width = screenWidth / 8 + 1;
	s16 desp  = screenWidth == 320 ? 0 : 4;
	u16 pal   = PAL1;

	if ( plan == BG_B )
	{
		pal = PAL2;
	}

	while ( width-- )
	{
	    SYS_disableInts();
        VDP_clearTileMapRect ( plan, width - 1 + desp, 0, 1, planeHeight );
        SYS_enableInts ( );

		waitHz(PLAN_HIDE_HZ);
	}
}

// void planHide_and_sprites()
// {
// 	const u16 height = VDP_getPlanHeight();
// 	const u16 width = VDP_getScreenWidth() / 8 + 1;
// 	const s16 desp = VDP_getScreenWidth() == 320 ? 0 : 4;

// 	for (u16 w = width; w > 0; w--)
// 	{
// 		for (u16 sprite = 0; sprite < MAX_SPRITE; sprite++)
// 			if (vdpSpriteCache[sprite].x / 8 + 2 >= w)
// 				splist_hide_sprite(sprite);

// 		VDP_updateSprites(80, 1);

// 		SYS_disableInts();
// 		VDP_clearTileMapRect(BG_B, w - 1 + desp, 0, 1, height);
// 		VDP_clearTileMapRect(BG_A, w - 1 + desp, 0, 1, height);
// 		SYS_enableInts();

// 		waitHz(PLAN_HIDE_HZ);
// 	}
// }

void planHide(){
	u16 sprite;
	u16 width  = VDP_getScreenWidth()  / 8 + 1;
	s16 desp   = VDP_getScreenWidth() == 320 ? 0 : 4;

    for ( ; width > 0; width-- ){
        bool update = false;

		for (sprite=0; sprite<MAX_SPRITE; sprite++)
			if (vdpSpriteCache[sprite].x/8+2  - 16 + 1 >= width){
				splist_hide_sprite ( sprite );
				update = true;
			}

		if (update)
			VDP_updateSprites(80,1);

		SYS_disableInts();
		VDP_clearTileMapRect(BG_B, width - 1 + desp, 0, 1, planeHeight);
		VDP_clearTileMapRect(BG_A, width - 1 + desp, 0, 1, planeHeight);
		SYS_enableInts();

		waitHz(PLAN_HIDE_HZ);
	}
}



void showBmp ( u16 pal, struct genresTiles *grt, u16 tile, VDPPlane plan, u16 x, u16 y, u8 pal_steps )
{
	SYS_disableInts();
	VDP_loadTileData ( grt->tiles, tile, grt->width * grt->height, 0 );
	VDP_fillTileMapRectInc ( plan, TILE_ATTR_FULL ( pal, 1, 0, 0, tile ), x, y, grt->width, grt->height );
	SYS_enableInts();
}

void typeText(u8 *str, u8 x, u8 y, u16 ms){
	for (u8 i = 0, len = strlen(str); i < len; i++){
		const u8 aux[4] = {str[i], '\0'};		
		TEXT_drawText(aux, x++, y);
		
		if (aux[0] != ' ')
			waitMs(ms);
	}
}

void waitHz(u16 hz){
	while (hz--)
		SYS_doVBlankProcess();
}

void waitSc(u16 sc){
	waitHz(sc * getHz());
}

void waitJoy() {
	while (1) {
		SYS_doVBlankProcess();
		JoyReader_update();
		if (joy1_pressed)
			return;
	}
}

void waitJoyHz(u16 hz) {
	while (hz--) {
		SYS_doVBlankProcess();
		JoyReader_update();
		if (joy1_pressed)
			return;
	}
}

void waitJoySc(u16 sc){
    waitJoyHz(sc * getHz());
}

void waitJoyHzBtn(u16 hz){
    while (hz--){
		SYS_doVBlankProcess();
		JoyReader_update();
		if (joy1_pressed_abc|joy1_pressed_start)
			return;
	}
}

void waitJoyScBtn(u16 sc){
    waitJoyHzBtn(sc * getHz());
}

void waitMusicStop(){
    while (XGM_isPlaying())
        SYS_doVBlankProcess();
}