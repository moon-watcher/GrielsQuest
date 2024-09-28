#include "../inc/include.h"

static struct genresSprites *_genres = NULL;
static u16 _base = 0;
static u16 _palette = 0;
static u8 _counter = 0;
static u8 _positions[96] = {};
static u8 _sprite = 0;

static u8 parse_string(u8 *string, u8 i)
{
	u8 chr = string[i];
	drawUInt(chr, 1, devu0++, 4);

	chr -= (32 + 1);
	// chr  = ( chr == 255 ) ? 0 : chr; //drawUInt( chr,0, devu0++, 4 );

	// switch ( chr )
	// {
	//     case 248: chr = 95; break; // �
	//     case 247: chr = 94; break; // �
	//     case 178: chr = 94; break; // �
	//     case 245: chr = 93; break; // �
	//     case 244: chr = 92; break; // �
	//     case 243: chr = 91; break; // �
	//     case 234: chr = 90; break; // �
	//     case 233: chr = 89; break; // �
	//     case 231: chr = 88; break; // �
	//     case 230: chr = 87; break; // �
	//     case 229: chr = 86; break; // �
	//     case 213: chr = 84; break; // �
	//     case 227: chr = 85; break; // �
	//     case 215: chr = 83; break; // �
	// };

	return chr;
}

static u8 parse_chr0(u8 chr0)
{
	// drawUInt( chr0,1,devu0++,4 );

	chr0 -= (32 + 1);
	chr0 = (chr0 == 255) ? 0 : chr0; // drawUInt( chr0,0, devu0++, 4 );

	switch (chr0){
		case 248: chr0 = 95; break; // �
		case 247: chr0 = 94; break; // �
		case 178: chr0 = 94; break; // �
		case 245: chr0 = 93; break; // �
		case 244: chr0 = 92; break; // �
		case 243: chr0 = 91; break; // �
		case 234: chr0 = 90; break; // �
		case 233: chr0 = 89; break; // �
		case 231: chr0 = 88; break; // �
		case 230: chr0 = 87; break; // �
		case 229: chr0 = 86; break; // �
		case 213: chr0 = 84; break; // �
		case 227: chr0 = 85; break; // �
		case 215: chr0 = 83; break; // �
	};

	return chr0;
}

void bigtext_init(struct genresSprites *genres, u16 vram, u16 palette)
{
	_genres = genres;
	_base = vram;
	_palette = palette;

	bigtext_reset();
}

void bigtext_reset()
{
	_sprite = 0;
	_counter = 0;
	memset(_positions, 0, 96);
}

void bigtext_setSprite(u8 next)
{
	_sprite = next;
}

void bigtext_drawTile(u8 *string, u8 x, u8 y, u16 ms)
{
	u8 chr0;
	u16 i = 0;
	u16 inc = 0;

	const u8 width = _genres->width >> 3;
	const u8 height = _genres->height >> 3;
	const u8 tiles = width * height;

	devu0 = 0;

	while ((chr0 = *string++)){
		inc = 0;
		chr0 = parse_chr0(chr0);

		if (!_positions[chr0]){
			_positions[chr0] = _counter++;

			SYS_disableInts();
			VDP_loadTileData(_genres->sprites[chr0], (_base + _positions[chr0] * tiles + inc), 4, 0);
			SYS_enableInts();
		}

		for (u16 j = 0; j < height; j++)
			for (u16 k = 0; k < width; k++){
				SYS_disableInts();
				VDP_setTileMapXY(BG_A, TILE_ATTR_FULL(_palette, 0, 0, 0, (_base + _positions[chr0] * tiles + inc)), i * width + x + j, y + k);
				SYS_enableInts();

				++inc;
			}

		if (ms > 3)
			waitMs(ms);

		++i;
	}
}

void bigtext_drawTile_Xcentered(u8 *string, u8 y, u16 ms)
{
	u16 len = strlen_countChars(string) * 2;
	u16 x = 20 - len / 2;

	bigtext_drawTile(string, x, y, ms);
}


u16 bigtext_drawSprites(u8 *string, u16 x, u16 y, u16 ms)
{
#define TILE _base + _positions[chr0] * (_genres->width >> 3) * (_genres->height >> 3)
#define ATTR TILE_ATTR_FULL(_palette, 1, 0, 0, TILE)

	const u16 size = _genres->size >> 8;
	const u16 width = _genres->width;
	const u16 length = strlen_countChars(string);

	devu0 = 0;

	for (u8 i = 0; i < length; i++)
	{
		u8 chr0 = parse_string(string, i);

		if (chr0 == 0) // is space
			continue;

		SYS_disableInts();

		if (!_positions[chr0])
		{
			_positions[chr0] = _counter++;
			VDP_loadTileData(_genres->sprites[chr0], TILE, size, 0);
		}

		VDP_setSpriteFull(_sprite, x + i * width, y, size, ATTR, _sprite + 1);
		++_sprite;

		SYS_enableInts();

		if (ms > 3)
		{
			SYS_disableInts();
			VDP_updateSprites(80, 1);
			SYS_enableInts();

			waitMs(ms);
		}
	}

	return _sprite;
}

u16 bigtext_drawSprites_XYcentered(u8 *string, u16 ms)
{
	u16 y = VDP_getScreenHeight() / 2 - (_genres->height) / 2;
	u16 x = VDP_getScreenWidth() / 2 - (_genres->width * strlen_countChars(string)) / 2;
	return bigtext_drawSprites(string, x, y, ms);
}

u16 bigtext_drawSprites_Xcentered(u8 *string, u16 y, u16 ms)
{
	u16 x = VDP_getScreenWidth() / 2 - _genres->width * strlen_countChars(string) / 2;
	return bigtext_drawSprites(string, x, y, ms);

	// drawUInt(strlen_countChars(string), 3,3,4);
	// drawUInt(strlen(string), 3,4,4);

	// static u8 get_jump_pos ( u8 *string )
	// {
	// 	u8 i;

	// 	for ( i=0; i<strlen(string); i++ )
	// 	{
	// 		if ( string[i] == '|' )
	// 		{
	// 			return i;
	// 		}
	// 	}

	// 	return 0;
	// }

	// u8 pos = get_jump_pos(string);

	// if (pos)
	// {
	// 	u8 sprite, aux[40] = {0};
	// 	x = VDP_getScreenWidth() / 2 - 40 * _genres->width / 2;

	// 	memcpy(aux, &string[0], pos - 1);
	// 	sprite = bigtext_drawSprites(aux, x, y, ms);

	// 	memcpy(aux, &string[pos + 1], strlen(string) - pos);
	// 	sprite = bigtext_drawSprites(aux, x, y + _genres->height, ms);

	// 	return sprite;
	// }
}
