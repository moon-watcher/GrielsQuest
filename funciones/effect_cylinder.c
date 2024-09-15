#include "effect_cylinder.h"

void EFFECT_cylinder(int sens, int speed, int length)
{
    u16 j = 0;
    u16* scrollTable;
    u16 curY;
    int curX;
    u16 ttt=0;
    int vscroll;
    u16 scr = 0;

    void initTable()
    {
        scrollTable = (u16*)MEM_alloc(21*42*sizeof(u16));
        vscroll=0x840;
        int k, h;
        int center = 12;
        for (k=0 ; k<42 ; ++k)
        {
            int count = (k*k)*0.02f;
            for (h=0 ; h<21 ; ++h)
            {
                int xv;
                if (k<center) xv = (h-10)*(h-10)*((center-k)*(center-k))*0.004;
                else xv = -(h-10)*(h-10)*((k-center)*(k-center))*0.004;
                scrollTable[k*21+h] = 0x840-count+xv;
            }
        }
    }

    int posY = 0;
    u16* scrollData = NULL;

    void vblank()
    {
        ++ttt;
        curY = 0;
        posY += sens*speed;

        scrollData = scrollTable;
    }

    void hblank()
    {
        vu16 *pw = (u16 *) VDP_DATA_PORT;
        vu32 *pl = (u32 *) VDP_CTRL_PORT;
        int val = -posY-ttt/4;

        int x;
        for (x=0 ; x<21 ; ++x)
        {
            u16 addr = (x&0x1F)*4;
            *pl = GFX_WRITE_VSRAM_ADDR(addr);
            *pw = val+scrollData[x];
            *pl = GFX_WRITE_VSRAM_ADDR(addr+2);
            *pw = val/2+scrollData[x];
        }

        scrollData += 21;
        curY++;
    }

    GSKE_setScrollMode(GSKE_HSCROLL_Plane, GSKE_VSCROLL_Column);

    initTable();

    u32 start = SND_getTime_PCM();

    int xs=0, ys=0;

    u16 w = cylinder[0];
    u16 h = cylinder[1];
    PAL_setPalette(PAL2, &cylinder[2], CPU);
    VDP_loadBMPTileData((u32*) &cylinder[18], 1, w / 8, h / 8, w/8 );
    for (ys=0 ; ys<VDP_getPlaneHeight()/(h/8); ++ys)
    for (xs=0 ; xs<VDP_getPlaneWidth()/(w/8); ++xs)
        VDP_fillTileMapRectInc(APLAN, TILE_ATTR_FULL(PAL2, 0, 0, 0, 1), xs*(w/8), ys*(h/8), w/8, h/8);

    w = cylinder_back[0];
    h = cylinder_back[1];
    PAL_setPalette(PAL1, &cylinder_back[2], CPU);
    VDP_loadBMPTileData((u32*) &cylinder_back[18], 257, w / 8, h / 8, w/8 );
    for (ys=0 ; ys<VDP_getPlaneHeight()/(h/8); ++ys)
    for (xs=0 ; xs<VDP_getPlaneWidth()/(w/8); ++xs)
        VDP_fillTileMapRectInc(BPLAN, TILE_ATTR_FULL(PAL1, 0, 0, 0, 257), xs*(w/8), ys*(h/8), w/8, h/8);

    SYS_setVIntCallback(vblank);
    SYS_setHIntCallback(hblank);
    VDP_setHIntCounter(1);
    VDP_setHInterrupt(1);

    curY = 0;

    u32 t=0;
    do
    {
        u32 ct = SND_getTime_PCM();
        if (ct>start) t = ct-start;

        VDP_setHorizontalScroll(APLAN, 0, sinFix16(t*speed/20)*2);
        VDP_setHorizontalScroll(BPLAN, 0, sinFix16(t*speed/20)*2);
    }
    while(t<length);

    SYS_setVIntCallback(0);
    SYS_setHIntCallback(0);
    MEM_free(scrollTable);
}
