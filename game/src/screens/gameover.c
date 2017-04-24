#include "../inc/include.h"


void screen_gameover ( )
{
	displayOff(0);

	splist_hide_sprites();
	resetScreen();

	u8 gameover[40];
	u8 phrasepwd[40];
	u8 thx4playing[40];
	u8 inverted[40];
	PASSWORD8 pwd;

	inc_difficulty_level();
	pwd8_generate ( pwd );

	strcpy ( gameover,    frases_find ( 25, 0 ) );
	strcpy ( phrasepwd,   frases_find ( 25, 1 ) );
	strcpy ( thx4playing, frases_find ( 25, 2 ) );
	strcpy ( inverted,    frases_find ( 25, 3 ) );


	text_init ( (struct genresSprites*)&cs_font_16x16, 16, PAL0 );
	text_draw_sprites_x_centered ( gameover, 60, 0 );
	VDP_updateSprites(80,1);


	u16 x1 = screenWidth/8/2 - strlen(thx4playing)/2;
	u16 x2 = screenWidth/8/2 - strlen(inverted)/2;
	u16 x3 = screenWidth/8/2 - strlen(phrasepwd)/2;

	VDP_drawText ( thx4playing, x1, 13 );

	if ( gamestate.dificultad > 2 )
	{
		VDP_drawText ( inverted, x2, 17 );
	}

	VDP_drawText ( phrasepwd, x3, 19 );
	VDP_drawText ( pwd, 16, 21 );



	displayOn(0);


	waitMs(4000);
	waitJoy();

	planHide();
	resetSprites();

	music_stop();
    waitMs(1000);

	//music_stop();
}
