#include "../inc/include.h"


void screen_oldintro ( )
{
    u16 colors[64] = { };

    displayOff ( 0 );
    resetScreen();
    music_stop();


    JoyReader_pause();


    // text colors
    colors[1] = 0xfff;
    colors[2] = 0x888;
    prepareColors(colors);

	musiclist_play ( MUSIC_GATE );
	XGM_setMusicTempo(60);


    // 1
	showBmp ( PAL2, (struct genresTiles*) &ob_intro_1, HOW_TO_PLAY_TILE, PLAN_A, 12, 5, 60 );
	preparePal( PAL2, ob_intro_1.pal );
	displayOn ( getHz() );
	waitMs ( 500 );

	typeText ( "Every thousand years, the  ", 7, 15, 100 );
	typeText ( "Enemy awakes and comes to  ", 7, 17, 100 );
	typeText ( "our World to destroy it.   ", 7, 19, 100 );
	typeText ( "A dark age begins now...   ", 7, 21, 100 );
	waitMs(8000);
	planHide();


	// 2
    displayOff ( 0 );
	showBmp ( PAL2, (struct genresTiles*) &ob_intro_2, HOW_TO_PLAY_TILE, PLAN_A, 12, 5, 60 );
	preparePal( PAL2, ob_intro_2.pal );
    displayOn ( getHz() );
	waitMs ( 500 );

	typeText ( "Only a blessed Knight with ", 7, 15, 100 );
	typeText ( "a pure heart and the aid of", 7, 17, 100 );
	typeText ( "the Sangraal would be able ", 7, 19, 100 );
	typeText ( "to defeat the Evil Lord.   ", 7, 21, 100 );
	waitMs ( 8000 );
	planHide();


	// 3
    displayOff ( 0 );
	showBmp ( PAL2, (struct genresTiles*) &ob_intro_3, HOW_TO_PLAY_TILE, PLAN_A, 12, 5, 60 );
	preparePal( PAL2, ob_intro_3.pal );
	displayOn ( getHz() );
	waitMs ( 500 );

	typeText ( "Sir Griel has been selected", 7, 15, 100 );
	typeText ( "to begin the Quest for the ", 7, 17, 100 );
	typeText ( "Sangraal and save our World", 7, 19, 100 );
	typeText ( "from total annihilation.   ", 7, 21, 100 );
	waitMs ( 8000 );
	planHide ( );


    music_stop();
    displayOff ( 0 );
	JoyReader_resume();
}
