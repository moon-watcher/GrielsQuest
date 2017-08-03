#include "../inc/include.h"




void text_write ( char *str, u8 x, u8 y )
{
	SYS_disableInts ( );
	VDP_clearTileMapRect ( PLAN_B, x, y, strlen(str), 1 );
	VDP_drawText ( str, x, y );
	SYS_enableInts ( );
}


void planHide_Ex (  VDPPlan plan )
{
	u16 width = screenWidth / 8 + 1;
	s16 desp  = screenWidth == 320 ? 0 : 4;
	u16 pal   = PAL1;

	if ( plan.value == PLAN_B.value )
	{
		pal = PAL2;
	}

	while ( width-- )
	{
	    SYS_disableInts();
        VDP_clearTileMapRect ( plan, width - 1 + desp, 0, 1, planHeight );
        SYS_enableInts ( );

		//waitMs ( PLAN_HIDE_MS );
		waitHz(1);
	}
}


void planHide_and_sprites (  )
{
	u16 w, sprite;

	const u16 height = VDP_getPlanHeight();
	const u16 width  = VDP_getScreenWidth()  / 8 + 1;
	const s16 desp   = VDP_getScreenWidth() == 320 ? 0 : 4;

	for ( w = width; w > 0; w-- )
	{
		for ( sprite=0; sprite<MAX_SPRITE; sprite++ )
		{
			if ( vdpSpriteCache[sprite].x/8+2 >= w )
			{
				splist_hide_sprite ( sprite );
			}
		}

		VDP_updateSprites(80,1);

		SYS_disableInts();
        VDP_clearTileMapRect ( PLAN_B, w-1+desp, 0, 1, height );
        VDP_clearTileMapRect ( PLAN_A, w-1+desp, 0, 1, height );
        SYS_enableInts ( );

		//waitMs ( PLAN_HIDE_MS );
		waitHz(1);
	}
}



void planHide ( )
{
	u16 sprite;
	u16 width  = VDP_getScreenWidth()  / 8 + 1;
	s16 desp   = VDP_getScreenWidth() == 320 ? 0 : 4;

    for ( ; width > 0; width-- )
	{
        bool update = false;

		for ( sprite=0; sprite<MAX_SPRITE; sprite++ )
		{
			if ( vdpSpriteCache[sprite].x/8+2  - 16 + 1 >= width )
			{
				splist_hide_sprite ( sprite );
				update = true;
			}
		}

		if ( update )
		{
			VDP_updateSprites(80,1);
		}

		SYS_disableInts();
		VDP_clearTileMapRect ( PLAN_B, width - 1 + desp, 0, 1, planHeight );
		VDP_clearTileMapRect ( PLAN_A, width - 1 + desp, 0, 1, planHeight );
		SYS_enableInts();

		//waitMs ( PLAN_HIDE_MS );
		waitHz(1);
	}
}



void showBmp ( u16 pal, struct genresTiles *grt, u16 tile, VDPPlan plan, u16 x, u16 y, u8 pal_steps )
{
	SYS_disableInts();
	VDP_loadTileData ( grt->tiles, tile, grt->width * grt->height, 0 );
	SYS_enableInts();

	SYS_disableInts();
	VDP_fillTileMapRectInc ( plan, TILE_ATTR_FULL ( pal, 1, 0, 0, tile ), x, y, grt->width, grt->height );
	SYS_enableInts();
}



void typeText ( char *str, u8 x, u8 y, u16 ms )
{
	u8 i, len = strlen ( str );

	for ( i=0; i<len; i++ )
	{
	    const char aux[2] = { str[i], '\0' };

        SYS_disableInts();
		VDP_drawText ( aux, x++, y );
		SYS_enableInts();

		if ( aux[0] != ' ' )
        {
            waitMs(ms);
        }
	}
}



void waitHz ( u16 hz )
{
	while ( hz-- )
	{
		VDP_waitVSync();
	}
}

void waitSc ( u16 sc )
{
	sc *= getHz();

	while ( sc-- )
	{
		VDP_waitVSync();
	}
}

void waitJoy ( )
{
	while ( 1 )
	{
		VDP_waitVSync();

		JoyReader_update();

		if ( joy1_pressed )
		{
			return ;
		}
	}
}

void waitJoyHz ( u16 hz )
{
	while ( hz-- )
	{
		VDP_waitVSync();

		JoyReader_update();

		if ( joy1_pressed )
		{
			return ;
		}
	}
}

void waitJoySc ( u16 sc )
{
    waitJoyHz ( sc * getHz() );
}

void waitMusicStop ( )
{
    while ( XGM_isPlaying() )
    {
        VDP_waitVSync();
    }
}


static s16 _plan_dir_a = 0;
static s16 _plan_dir_b = 0;

void tool_reset_plan ( VDPPlan plan )
{
    if ( plan.value == PLAN_A.value ) _plan_dir_a = 0;
    else _plan_dir_b = 0;

    SYS_disableInts();
    VDP_setHorizontalScroll( plan, 0 );
    SYS_enableInts();
}

void tool_move_plan ( VDPPlan plan, s16 dir )
{
    if ( plan.value == PLAN_A.value )
    {
        _plan_dir_a += dir;

        SYS_disableInts();
        VDP_setHorizontalScroll( plan, _plan_dir_a );
        SYS_enableInts();
    }
    else
    {
        _plan_dir_b += dir;

        SYS_disableInts();
        VDP_setHorizontalScroll( plan, _plan_dir_b );
        SYS_enableInts();
    }
}
