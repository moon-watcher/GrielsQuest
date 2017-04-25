#include "../inc/include.h"



static void _blink ( const u16 x, const u16 y, u8 option )
{
    VDP_setTileMapDataRect ( PLAN_A, 0, x, y, 20, 1 );

	u8 i = ntsc2pal(15);

	while ( i-- )
	{
		if ( i % 2  )
		{
			VDP_setTileMapDataRect( PLAN_A, 0, x, y, 20, 1 );
        }
		else
		{
            VDP_setMapEx ( PLAN_A, cb_languages.map, TILE_ATTR_FULL(PAL1,0,0,0,200), x, y, 0, option*2, 8, 1 );
		}

		VDP_waitVSync();
		VDP_waitVSync();
	}

	VDP_setMapEx ( PLAN_A, cb_languages.map, TILE_ATTR_FULL(PAL1,0,0,0,200), x, y, 0, option*2, 8, 1 );
}


void screen_languages ()
{
    if ( gamestate.lenguaje )
    {
        return;
    }

    u16 y = 8;
    s8 option = 0;


    SYS_disableInts();

    font_setPalette();

    resetScreen();
    VDP_drawImageEx(PLAN_A, &cb_languages, TILE_ATTR_FULL(PAL1,0,0,0,200), 17, y, 1, 0 );
    VDP_drawText ( ">", 15, option*2 + y );

    SYS_enableInts();


    while ( 1 )
    {
        JOY_waitPress(JOY_1, BUTTON_UP | BUTTON_DOWN | BUTTON_ABCS );

        JoyReader_update();

        VDP_drawText ( " ", 15, option*2+y );

		if ( joy1_pressed_down ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   ) { option--; psglist_play ( PSG_SELECT_2 ); }

		if ( option < 0 ) option = 3;
		if ( option > 3 ) option = 0;

		VDP_drawText ( ">", 15, option*2+y );


        if ( joy1_pressed_abc | joy1_pressed_start )
        {
            break;
        }

        VDP_waitVSync();
    }

    psglist_play ( PSG_START );
    _blink ( 17, option*2+y, option );

    gamestate.lenguaje = option + 1;

    displayOff(30);
}
