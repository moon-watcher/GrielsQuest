#include "../inc/include.h"



static void _blink ( const u16 x, const u16 y, u8 option )
{

    return;


   // VDP_setTileMapDataRect( PLAN_A, 0, x, option*2+y, 20, 1 );


	u8 i = ntsc2pal(15);

//  	VDP_drawText ( str, x, y );


	while ( i-- )
	{
		if ( i % 2  )
		{
			VDP_setTileMapDataRect( PLAN_A, 0, x, y, 20, 1 );
        }
		else
		{
//		    s8 k = 8;
//            while ( k-- )
//            {
//                VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL ( PAL1, true, false, false,tiles[k]), x+k, y );
//            }
//			{
                //VDP_setMapEx ( PLAN_A, cb_howtoplay.map, TILE_ATTR_FULL ( PAL1, true, false, false, 900 ), 4, line+5, 0, line, 32, 1 );
                //VDP_setMapEx ( PLAN_A, &cb_languages, TILE_ATTR_FULL(PAL1,0,0,0,200), 4, line+5, 0, line, 32, 1 );

				//VDP_setMapEx ( PLAN_A, cb_pause.map,TILE_ATTR_FULL(PAL1, true, false, false, 900), 12, 12, 0,  11, 16, 1 );

//            u8 j;
//            for ( j=0; j<8; j++)
//				VDP_setMapEx ( PLAN_A, &cb_languages, TILE_ATTR_FULL(PAL1,0,0,0,200), x+j, y+option*2, x+j, option*2, 1, 1 );
//
//
//                    waitMs(300);
//			}
		}


        //VDP_setTileMapDataRectEx( PLAN_A, 0, x, y, 20, 1 );

		VDP_waitVSync();
		VDP_waitVSync();
	}

//	VDP_drawText ( str, x, y );
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

    _blink ( 17, option*2+y, option );

    psglist_play ( PSG_START );
    gamestate.lenguaje = option + 1;

    displayOff(30);
}
