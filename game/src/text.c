#include "../inc/include.h"



static struct genresSprites *_genres = NULL;
static u16            _base = 0;
static u16            _palette = 0;
static u8             _counter = 0;
static u8             _positions[96] = { };
static u8             _sprite = 0;



static u8 parse_chr ( u8 chr )
{
    chr -= ( 32 + 1 );
    chr  = ( chr == 255 ) ? 0 : chr; //drawUInt( chr,0, devu0++, 4 );

//      // for debug
//    drawUInt( chr,1,2,4 );
//    waitSc(1);

    switch ( chr )
    {
        case 248: chr = 95; break; // �
        case 247: chr = 94; break; // �
        case 178: chr = 94; break; // �
        case 245: chr = 93; break; // �
        case 244: chr = 92; break; // �
        case 243: chr = 91; break; // �
        case 234: chr = 90; break; // �
        case 233: chr = 89; break; // �
        case 231: chr = 88; break; // �
        case 230: chr = 87; break; // �
        case 229: chr = 86; break; // �
        case 213: chr = 84; break; // �
        case 227: chr = 85; break; // �
        case 215: chr = 83; break; // �
    };

    return chr;
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
	#define POSITION	_base + _positions[chr] * tiles + inc


	u8 chr;

	u16 k;
	u16 j;
	u16 i   = 0;
	u16 inc = 0;

	const u8 width  = _genres->width  >> 3;
	const u8 height = _genres->height >> 3;
	const u8 tiles  = width * height;

	//devu0 = 0;

	while ( (chr = *string++) )
	{
		inc = 0;
		chr = parse_chr ( chr );

		if ( ! _positions[chr] )
		{
			_positions[chr] = _counter++;

			SYS_disableInts();
			VDP_loadTileData ( _genres->sprites[chr], POSITION, 4, 0 );
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
	#define TILE    _base + _positions[chr] * ( _genres->width >> 3 ) * ( _genres->height >> 3 )
	#define ATTR	 TILE_ATTR_FULL ( _palette, 1, 0, 0, TILE )


	//splist_hide_sprites();

	u8 i, chr;

	const u16 size   = _genres->size >> 8;
	const u16 width  = _genres->width;
	const u16 length = strlen ( string );


	for ( i=0; i<length; i++ )
	{
		chr = parse_chr ( string[i] ) ;

		if ( chr != 0 ) // isn't space
		{
			SYS_disableInts();

			if ( ! _positions[chr] )
			{
				_positions[chr] = _counter++;
				VDP_loadTileData ( _genres->sprites[chr], TILE, size, 0 );
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






#define CHR(A, B) if (chr1 == A) chr = B;

static void wr_debug(s16 chr)
{
    if (!DEV)
        return;

    u8 write[2] = {chr, '\0'};
    drawInt(chr, 0, devu0, 5);
    VDP_drawText(write, 10, devu0);
    ++devu0;
}

void GRIEL_drawText(u8 *str, u16 x, u16 y)
{
    u16 i    = 0;
    u16 plan = VDP_getTextPlane();
    u16 pal  = VDP_getTextPalette();
    u16 prio = VDP_getTextPriority();

    while (str[i]) {
        s16 chr  = str[i+0];
        s16 chr1 = str[i+1];

        // wr_debug(chr);

        if (chr == 195 || chr == 194) {
            // wr_debug(chr1);
            ++i;
        }

        if (chr == 195)
        {
            CHR(186,  31); // ú
            CHR(179,  30); // ó
            CHR(177,  29); // ñ
            CHR(173,  28); // í
            CHR(169,  27); // é
            CHR(161,  26); // á
            CHR(154,  25); // Ú
            CHR(147,  24); // Ó
            CHR(145,  23); // Ñ
            CHR(141,  22); // Í
            CHR(137,  21); // É
            CHR(129,  20); // Á
            CHR(185,  17); // ù
            CHR(178,  16); // ò
            CHR(167,  15); // ç
            CHR(172,  14); // ì
            CHR(168,  13); // è
            CHR(160,  12); // à
            CHR(153,  11); // Ù
            CHR(146,  10); // Ò
            CHR(135,   9); // Ç
            CHR(140,   8); // Ì
            CHR(136,   7); // È
            CHR(128,   6); // À
            CHR(182,   5); // ö
            CHR(150,   4); // Ö
            CHR(187,   3); // û
            CHR(180,   2); // ô
            CHR(174,   1); // î
            // CHR(XXX,   0); //
            CHR(170,  -1); // ê
            CHR(162,  -2); // â
            CHR(165,  -2); // å // almost equal char
            CHR(155,  -3); // Û
            CHR(148,  -4); // Ô
            // CHR(XXX,  -4); //
            CHR(142,  -6); // Î
            CHR(138,  -7); // Ê
            CHR(130,  -8); // Â
            CHR(133,  -8); // Å // almost equal char
            CHR(164,  -9); // ä
            CHR(132, -10); // Ä
            CHR(188, -11); // ü 
            // CHR(XXX, -12); //
            CHR(175, -13); // ï
            // CHR(XXX, -14); //
            // CHR(XXX, -15); //
            // CHR(XXX, -16); //
            CHR(156, -17); // Ü
            // CHR(XXX,  -18); //
            // CHR(XXX,  -19); //
            CHR(143, -20); // Ï
            CHR(181, -21); // õ
            CHR(149, -22); // Õ
            CHR(163, -23); // ã
            CHR(131, -24); // Ã            
        }

        if (chr == 194)
        {
            CHR(191,  19); // ¿
            CHR(161,  18); // ¡
        }

        u16 tile = TILE_FONT_INDEX + chr - 32;
        VDP_setTileMapXY(plan, TILE_ATTR_FULL(pal, prio, 0, 0, tile), x++, y);

        ++i;
    }
}

