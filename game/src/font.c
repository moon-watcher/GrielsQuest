#include "../inc/include.h"
#include "../inc/genres_externs.h"


static const u16 _palette [ 16 ] =
{
	0x0000,	0x0FFF,	0x0444,	0x0000,
	0x0000,	0x0000,	0x0000,	0x0000,
	0x0000,	0x0000,	0x0000,	0x0000,
	0x0000,	0x0000,	0x0000,	0x0000
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void font_init ()
{
	const u32 _tile[8] = {};
	const u8 nb_chars = 1 + 14 * 4;

	SYS_disableInts();

	//VDP_loadFont ( cb_font_8x8, 1 );
	VDP_loadFontData ( cb_font_8x8, FONT_LEN, 0 );

	// carga los caracteres especiales
	VDP_loadTileData ( (u32*)cb_font_8x8_chars, TILE_FONT_INDEX-nb_chars, nb_chars, 0 );

	// hack for VDP_loadFont, inserts " " in 0 position
	VDP_loadTileData ( _tile, TILE_FONT_INDEX-nb_chars, 1, 0 );
	VDP_loadTileData ( _tile, TILE_FONT_INDEX,          1, 0 );

	SYS_enableInts();
}


void font_setPalette()
{
	VDP_setTextPalette  ( PAL0 );
	PAL_setColor ( PAL0+0, _palette[0] );
	PAL_setColor ( PAL0+1, _palette[1] );
	PAL_setColor ( PAL0+2, _palette[2] );
}


u16 *font_getPalette ( )
{
	return ( u16*) _palette;
}
