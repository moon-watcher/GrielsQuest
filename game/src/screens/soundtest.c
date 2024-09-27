#include "../inc/include.h"
#include "../inc/genres_externs.h"


void screen_sound_test ()
{

   int option = 0;
	u16	music  = 0,
		sound  = 0,
		max1   = MUSIC_MAX-1,
		max2   = PSG_MAX-1,
		pos    = 12;


    displayOff(0);


	SYS_disableInts();

//	resetScreen();
//	resetScroll();
//	//resetVRAM();

	music_stop();

//	struct mappyLevel lvl = { PAL1, 900, 0, BG_A.plan, (struct mappyResource*) &cb_soundtest };
//	mappy_all ( &lvl, 0, 0, 0, 0, 40, 28, 0 );

	font_init();
	text_init ( (struct genresSprites *) &cs_font_16x16, 1200, PAL0 );

	u8 f1[40];
	u8 f2[40];

	frases_init ( 28 );
	strcpy ( f1, frases_next() );
	strcpy ( f2, frases_next() );


	text_draw_center ( f1, 3, 0 );

	VDP_setTextPalette(PAL0);
	PAL_setPalette(PAL0, (u16*) font_getPalette(), CPU);

	SYS_enableInts();


	while ( true )
	{
		MUSIC *track = musiclist_get ( music );
		PSG   *psg   = psglist_get   ( sound );

		if ( option == 0 ) pos = 12;
		if ( option == 1 ) pos = 14;
		if ( option == 2 ) pos = 19;

		SYS_disableInts();

		TEXT_drawText ( " ", 14, 12 );
		TEXT_drawText ( " ", 14, 14 );
		TEXT_drawText ( " ", 14, 19 );
		TEXT_drawText ( ">                   ", 14, pos );

		TEXT_drawText ( track->title , 16, 12 );
		TEXT_drawText ( psg->title ,   16, 14 );
		TEXT_drawText ( f2,            16, 19 );

		SYS_enableInts();

		waitJoy(); //JOY_waitPress ( JOY_1, BUTTON_ALL );

		//if ( joy1_pressed_dir ) psglist_play ( PSG_SELECT );

		if ( option == 0 )
		{
			if ( joy1_pressed_right  &&  music < max1   ) music++;
			if ( joy1_pressed_left   &&  music > 0      ) music--;
			if ( joy1_pressed_abc || joy1_pressed_start ) musiclist_play ( music );
			//if ( joy1_pressed_b                         ) music_stop();
		}

		if ( option == 1 )
		{
			if ( joy1_pressed_right  &&  sound < max2   ) sound++;
			if ( joy1_pressed_left   &&  sound > 0      ) sound--;
			if ( joy1_pressed_abc || joy1_pressed_start ) psglist_play ( sound );
		}

		if ( option == 2 )
		{
			if ( joy1_pressed_abc || joy1_pressed_start )
			{
				psglist_play(PSG_BACK);
				waitMs(500);
				break;
			}
		}

		if ( joy1_pressed_down ) { option++; psglist_play ( PSG_SELECT_2 ); }
		if ( joy1_pressed_up   ) { option--; psglist_play ( PSG_SELECT_2 ); }


		if ( option == 3 ) option = 0;
		if ( option <  0 ) option = 2;
	}

	music_stop();
	//music_override_repeat ( AUTO );
	//music_override_repeat ( 2 );

	displayOff (30 );
}




