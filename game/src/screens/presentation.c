#include "../inc/include.h"
#include "../inc/genres_externs.h"

void scene_presentation()
{
	displayInit();
	displayOff(0);

	resetScreen();
	resetSprites();
	resetScroll();
	resetPalettes();

	musiclist_play ( MUSIC_NEW_ROUND );

	u16 *palette = font_getPalette ();

	PAL_setColor( PAL0+0, palette[0] );
	PAL_setColor( PAL0+1, palette[1] );
	PAL_setColor( PAL0+2, palette[2] );

	u8   string [ 41 ];
	u16  ambiente = gamestate.current_ambiente;
	u8  *frase    = frases_find ( 1, ambiente );

	bigtext_init ( (struct genresSprites *) &cs_font_16x16, 16, PAL0 );
	bigtext_drawSprites_Xcentered ( frase,  88, 30 );


	ambiente = gamestate.current_round+1;
	frase    = frases_find ( 1, 7 );

	memcpy ( string, frase, strlen ( frase ) ) ;
	sprintf ( string, frase, ambiente );
	u16 sprite = bigtext_drawSprites_Xcentered ( string, 120, 30 ) - 1;

	VDP_setSpriteLink ( sprite, 0 );
	VDP_updateSprites (80,1);


	waitJoyScBtn ( 3 );
	music_stop();


	displayOff(30);

	resetSprites();
	splist_reorder();
}
