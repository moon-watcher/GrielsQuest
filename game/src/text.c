#include "../inc/include.h"



static struct genresSprites *_genres = NULL;
static u16            _base = 0;
static u16            _palette = 0;
static u8             _counter = 0;
static u8             _positions[96] = { };
static u8             _sprite = 0;



static u8 parse_chr0 ( u8 chr0 )
{
    chr0 -= ( 32 + 1 );
    chr0  = ( chr0 == 255 ) ? 0 : chr0; //drawUInt( chr0,0, devu0++, 4 );

//      // for debug
//    drawUInt( chr0,1,2,4 );
//    waitSc(1);

    switch ( chr0 )
    {
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


static u8 get_jump_pos ( u8 *string )
{
    u8 i;

    for ( i=0; i<strlen(string); i++ )
    {
        if ( string[i] == '|' )
        {
            return i;
        }
    }

    return 0;
}


void text_init ( struct genresSprites *genres, u16 vram, u16 palette )
{
	_genres  = genres;
	_base    = vram;
	_palette = palette;

	text_reset();
}


void text_reset ( )
{
	_sprite = 0;
	_counter     = 0;
	memset ( _positions, 0, 96 );
}


void text_setSprite ( u8 next )
{
	_sprite = next;
}



void text_draw ( u8 *string, u8 x, u8 y, u16 ms )
{
	#define POSITION	_base + _positions[chr0] * tiles + inc


	u8 chr0;

	u16 k;
	u16 j;
	u16 i   = 0;
	u16 inc = 0;

	const u8 width  = _genres->width  >> 3;
	const u8 height = _genres->height >> 3;
	const u8 tiles  = width * height;

	//devu0 = 0;

	while ( (chr0 = *string++) )
	{
		inc = 0;
		chr0 = parse_chr0 ( chr0 );

		if ( ! _positions[chr0] )
		{
			_positions[chr0] = _counter++;

			SYS_disableInts();
			VDP_loadTileData ( _genres->sprites[chr0], POSITION, 4, 0 );
			SYS_enableInts();
		}

		for ( j = 0; j < height; j++ )
		{
			for ( k = 0; k < width; k++ )
			{
			    SYS_disableInts();
				VDP_setTileMapXY ( BG_A, TILE_ATTR_FULL ( _palette, 0, 0, 0, POSITION ), i*width + x + j, y + k );
				SYS_enableInts();

				++inc;
			}
		}

		if ( ms > 3 )
		{
			waitMs ( ms );
		}

		++i;
	}
}




void text_draw_center ( u8 *string, u8 y, u16 ms )
{
	u16 len = strlen(string)*2;
	u16 x = 20 - len / 2;

	text_draw ( string, x, y, ms );
}





u16 text_draw_sprite ( u8 *string, u16 x, u16 y, u16 ms )
{
	#define TILE    _base + _positions[chr0] * ( _genres->width >> 3 ) * ( _genres->height >> 3 )
	#define ATTR	 TILE_ATTR_FULL ( _palette, 1, 0, 0, TILE )


	//splist_hide_sprites();

	u8 i, chr0;

	const u16 size   = _genres->size >> 8;
	const u16 width  = _genres->width;
	const u16 length = strlen ( string );


	for ( i=0; i<length; i++ )
	{
		chr0 = parse_chr0 ( string[i] ) ;

		if ( chr0 != 0 ) // isn't space
		{
			SYS_disableInts();

			if ( ! _positions[chr0] )
			{
				_positions[chr0] = _counter++;
				VDP_loadTileData ( _genres->sprites[chr0], TILE, size, 0 );
			}

			VDP_setSpriteFull ( _sprite, x+i*width, y, size, ATTR, _sprite+1 );
			++_sprite;

			SYS_enableInts();

			if ( ms > 3 )
			{
			    SYS_disableInts();
				VDP_updateSprites(80,1);
				SYS_enableInts();

				waitMs ( ms );
			}
		}
	}


	return _sprite;
}


u16 text_draw_sprites_centered ( u8 *string, u16 ms )
{
    u16 x = VDP_getScreenWidth()  / 2  - _genres->width  / 2 * strlen ( string );
    u16 y = VDP_getScreenHeight() / 2  - _genres->height / 2;

	u8 pos = get_jump_pos ( string );

	if ( pos )
    {
        u8 sprite, aux[40] = {};

        memcpy ( aux, &string[0], pos-1 );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        y = VDP_getScreenHeight() / 2  - _genres->height  / 2 - 16;
        sprite = text_draw_sprite ( aux, x, y, ms );

        memcpy ( aux, &string[pos+1], strlen(string)-pos );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        y = VDP_getScreenHeight() / 2  - _genres->height  / 2 - 0;
        sprite = text_draw_sprite ( aux, x, y+_genres->height, ms );

        return sprite;
    }

	return text_draw_sprite ( string, x, y, ms );
}



u16 text_draw_sprites_x_centered ( u8 *string, u16 y, u16 ms )
{
    u16 x = VDP_getScreenWidth()  / 2  - _genres->width  / 2 * strlen ( string );

	u8 pos = get_jump_pos ( string );

	if ( pos )
    {
        u8 sprite, aux[40] = {};

        memcpy ( aux, &string[0], pos-1 );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        sprite = text_draw_sprite ( aux, x, y, ms );

        memcpy ( aux, &string[pos+1], strlen(string)-pos );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        sprite = text_draw_sprite ( aux, x, y+_genres->height, ms );

        return sprite;
    }

	return text_draw_sprite ( string, x, y, ms );
}










static const s8 _values195[] = {
        [186] =  31, // ú
        [179] =  30, // ó
        [177] =  29, // ñ
        [173] =  28, // í
        [169] =  27, // é
        [161] =  26, // á
        [154] =  25, // Ú
        [147] =  24, // Ó
        [145] =  23, // Ñ
        [141] =  22, // Í
        [137] =  21, // É
        [129] =  20, // Á
        [185] =  17, // ù
        [178] =  16, // ò
        [167] =  15, // ç
        [172] =  14, // ì
        [168] =  13, // è
        [160] =  12, // à
        [153] =  11, // Ù
        [146] =  10, // Ò
        [135] =   9, // Ç
        [140] =   8, // Ì
        [136] =   7, // È
        [128] =   6, // À
        [182] =   5, // ö
        [150] =   4, // Ö
        [187] =   3, // û
        [180] =   2, // ô
        [174] =   1, // î
        // [XXX] =   0, // YYY
        [170] =  -1, // ê
        [162] =  -2, // â
        [165] =  -2, // å // almost equal char
        [155] =  -3, // Û
        [148] =  -4, // Ô
        // [XXX] =  -5, // YYY
        [142] =  -6, // Î
        [138] =  -7, // Ê
        [130] =  -8, // Â
        [133] =  -8, // Å // almost equal char
        [164] =  -9, // ä
        [132] = -10, // Ä
        [188] = -11, // ü 
        // [XXX] = -12, // YYY
        [175] = -13, // ï
        // [XXX] = -14, // YYY
        // [XXX] = -15, // YYY
        // [XXX] = -16, // YYY
        [156] = -17, // Ü
        // [XXX] = -18, // YYY
        // [XXX] = -19, // YYY
        [143] = -20, // Ï
        [181] = -21, // õ
        [149] = -22, // Õ
        [163] = -23, // ã
        [131] = -24, // Ã
    };

static const s8 _values194[] = {
        [191]  =  19, // ¿
        [161]  =  18, // ¡
};

static void _debug_prepareText(s16 chr){
    return;

    u8 write[2] = {chr, '\0'};
    drawInt(chr, 0, devu0, 5);
    TEXT_drawText(write, 10, devu0);
    ++devu0;
}

static void _drawText(u8 *str, u16 x, u16 y, bool clear){
    s16 buffer[120] = {};
    u16 len = TEXT_prepareText(str, buffer);
    u16 pos = TILE_ATTR(VDP_getTextPalette(), VDP_getTextPriority(), 0, 0);
    u16 plan = VDP_getTextPlane();

    SYS_disableInts();

    if (clear)
        VDP_clearTileMapRect(BG_B, x, y, len, 1);

    for (u16 i = 0; buffer[i]; i++){
        u16 tile = TILE_FONT_INDEX + buffer[i] - 32;
        VDP_setTileMapXY(plan, pos + tile, x++, y);
    }

    SYS_enableInts();
}

u16 TEXT_prepareText(u8 *str, s16 array[]){
    u16 i = 0;
    u16 j = 0;

    while (str[i]){
        u16 chr0 = str[i + 0];
        u16 chr1 = str[i + 1];

        i++;
        _debug_prepareText(chr0);

        if (chr0 == 195 || chr0 == 194){
            i++;
            _debug_prepareText(chr1);
        }

        array[j] = chr0;

        if (chr0 == 195) array[j] = _values195[chr1];
        if (chr0 == 194) array[j] = _values194[chr1];

        ++j;
    }

    return j;
}

void TEXT_drawText_clear(u8 *str, u16 x, u16 y){
    _drawText(str, x, y, true);
}

void TEXT_drawText(u8 *str, u16 x, u16 y){
    _drawText(str, x, y, false);
}