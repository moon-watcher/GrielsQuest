#include "../inc/include.h"
#include "../inc/genres_externs.h"

void screen_gameover()
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
	pwd8_generate(pwd);

	strcpy(gameover,    frases_find(25, 0));
	strcpy(phrasepwd,   frases_find(25, 1));
	strcpy(thx4playing, frases_find(25, 2));
	strcpy(inverted,    frases_find(25, 3));

	bigtext_init((struct genresSprites *)&cs_font_16x16, 16, PAL0);
	bigtext_drawSprite_Xcentered(gameover, 60, 0);
	VDP_updateSprites(80, 1);

	u16 x = screenWidth / 8 / 2;
	u16 x1 = x - countChars(thx4playing) / 2;
	u16 x2 = x - countChars(inverted   ) / 2;
	u16 x3 = x - countChars(phrasepwd  ) / 2;

	TEXT_drawText(thx4playing, x1, 13);

	if (gamestate.dificultad > 2)
		TEXT_drawText(inverted, x2, 17);

	TEXT_drawText(phrasepwd, x3, 19);
	TEXT_drawText(pwd, 16, 22);

	displayOn(0);

	waitMs(4000);
	waitJoy();

	planHide();
	resetSprites();

	music_stop();
	waitMs(1000);
}
