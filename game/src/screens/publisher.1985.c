#include "../../inc/include.h"

#define READ_JOY                               \
    JoyReader_update();                        \
    if (joy1_pressed_abc | joy1_pressed_start) \
    {                                          \
        exit = 1;                              \
        return;                                \
    }

static u16 exit;
static u16 black;
static u16 dark;
static u16 red;

static const u16 *numbers[10][7] = {
    {&red,  &dark, &red,  &red,  &red,  &red,  &red }, // 0
    {&dark, &dark, &dark, &dark, &dark, &red,  &red }, // 1
    {&red,  &red,  &red,  &dark, &red,  &red,  &dark}, // 2
    {&red,  &red,  &red,  &dark, &dark, &red,  &red }, // 3
    {&dark, &red,  &dark, &red,  &dark, &red,  &red }, // 4
    {&red,  &red,  &red,  &red,  &dark, &dark, &red }, // 5
    {&red,  &red,  &red,  &red,  &red,  &dark, &red }, // 6
    {&red,  &dark, &dark, &dark, &dark, &red,  &red }, // 7
    {&red,  &red,  &red,  &red,  &red,  &red,  &red }, // 8
    {&red,  &red,  &red,  &red,  &dark, &red,  &red }, // 9
};

static void drawNumber(u16 pal, u16 num)
{
    num = num % 10;
    pal = pal * 16;

    prepareColor(pal + 1, *numbers[num][0]);
    prepareColor(pal + 2, *numbers[num][1]);
    prepareColor(pal + 3, *numbers[num][2]);
    prepareColor(pal + 4, *numbers[num][3]);
    prepareColor(pal + 5, *numbers[num][4]);
    prepareColor(pal + 6, *numbers[num][5]);
    prepareColor(pal + 7, *numbers[num][6]);
}

static void drawUntil(u16 pal, u16 max)
{
    if (exit)
        return;

    for (int i = 0; i <= max; i++)
    {
        drawNumber(pal, i);
        
        SYS_doVBlankProcess();
        displayOn(0);

        READ_JOY;
    }
}

static void logo_fucnt_1()
{
    for (int i = 0; i <= 1985; i += 31)
    {
        drawNumber(PAL0, i / 1000);
        drawNumber(PAL1, i / 100);
        drawNumber(PAL2, i / 10);
        drawNumber(PAL3, i / 1);

        displayOn(0);

        READ_JOY;
    }
}

static void logo_fucnt_2()
{
    for (int j = 0; j < 10; j++)
    {
        if (j <= 1) drawNumber(PAL0, j);
        if (j <= 9) drawNumber(PAL1, j);
        if (j <= 8) drawNumber(PAL2, j);
        if (j <= 5) drawNumber(PAL3, j);

        SYS_doVBlankProcess();
        SYS_doVBlankProcess();
        displayOn(0);

        READ_JOY;
    }
}

static void logo_fucnt_3()
{
    for (int i = 0; i < 50; i++)
    {
        drawNumber(PAL0, random() % 10);
        drawNumber(PAL1, random() % 10);
        drawNumber(PAL2, random() % 10);
        drawNumber(PAL3, random() % 10);

        displayOn(0);

        READ_JOY;
    }
}

static void logo_fucnt_4()
{
    drawUntil(PAL3, 5);
    drawUntil(PAL2, 8);
    drawUntil(PAL1, 9);
    drawUntil(PAL0, 1);
}

static void resetNumbers()
{
    for (int i = 1; i <= 7; i++)
    {
        prepareColor(PAL0 * 16 + i, dark);
        prepareColor(PAL1 * 16 + i, dark);
        prepareColor(PAL2 * 16 + i, dark);
        prepareColor(PAL3 * 16 + i, dark);
    }

    prepareColor(0, black);
}

void screen_publisher_1985()
{
    displayOff(0);

    VDP_setScreenWidth320();
    VDP_setPlaneSize(64, 32, false);

    vram_init(VRAM_DEFAULT);

    resetScroll();
    resetScreen();

    VDP_drawImageEx(BG_B, &logo_1985_bg, TILE_ATTR_FULL(PAL0, 0, 0, 0, 16), 12, 8, 0, 0);
    VDP_drawImageEx(BG_A, &logo_1985_1, TILE_ATTR_FULL(PAL0, 0, 0, 0, 100), 12, 9, 0, 0);
    VDP_drawImageEx(BG_A, &logo_1985_2, TILE_ATTR_FULL(PAL1, 0, 0, 0, 150), 16, 9, 0, 0);
    VDP_drawImageEx(BG_A, &logo_1985_3, TILE_ATTR_FULL(PAL2, 0, 0, 0, 200), 20, 9, 0, 0);
    VDP_drawImageEx(BG_A, &logo_1985_4, TILE_ATTR_FULL(PAL3, 0, 0, 0, 250), 24, 9, 0, 0);

    preparePal(PAL0, logo_1985_bg.palette->data);
    preparePal(PAL1, logo_1985_2.palette->data);
    preparePal(PAL2, logo_1985_3.palette->data);
    preparePal(PAL3, logo_1985_4.palette->data);

    exit = 0;
    setRandomSeed(vtimer);

    u16 i = random() % 4;
    // drawUInt( i, 2, 2, 1 );

    black = logo_1985_1.palette->data[11];
    dark = logo_1985_1.palette->data[13];
    red = logo_1985_1.palette->data[15];

    const u16 darks[] = {dark, dark, dark, dark, dark, dark, dark};
    const void (*functptr[])() = {logo_fucnt_1, logo_fucnt_2, logo_fucnt_3, logo_fucnt_4};

    resetNumbers();
    displayOn(10);

    (*functptr[i])();

    drawNumber(PAL0, 1);
    drawNumber(PAL1, 9);
    drawNumber(PAL2, 8);
    drawNumber(PAL3, 5);
    displayOn(0);

    if (!exit)
        waitJoySc(4);

    displayOff(10);
}

// #define IMAGES  1
//
//
// void screen_publisher ( )
//{
//     if ( DEV > 1 ) return;
//
//	displayOff(0);
//
//	VDP_setScreenWidth320();
//	VDP_setPlaneSize ( 64, 32 );
//
////	palette_init();
//	vram_init ( VRAM_DEFAULT );
//
//	resetScroll();
//	resetScreen();
//
//
//	const u16 x = 12;
//	const u16 y = 8;
//
//
//	u16 i, vram_pos [ IMAGES ];
//
//
//	Image *images [ IMAGES ] =
//	{
//		(Image*) &screen_publisher_00
//	};
//
//	for ( i=0; i<IMAGES; i++ )
//	{
//		u16 size = images[i]->tileset->numTile;
//		vram_pos [ i ] = vram_new ( size );
//		SYS_disableInts();
//		VDP_loadTileData ( images[i]->tileset->tiles, vram_pos[i], size, 0 );
//		SYS_enableInts();
//	}
//
//
//	waitHz(20);
//
//	for ( i=0; i<IMAGES; i++ )
//	{
//		waitHz(3);
//
//		SYS_disableInts();
//		preparePal ( PAL1, images[i]->palette->data );
//		VDP_setMap ( BG_A, images[i]->tilemap,TILE_ATTR_FULL ( PAL1, 0, 0, 0, vram_pos[i] ), x, y );
//		SYS_enableInts();
//	}
//
//	vram_destroy();
//	displayOn(10);
//
//	waitJoySc(6);
//
//	displayOff(10);
//	//musicStop ( );
//}
