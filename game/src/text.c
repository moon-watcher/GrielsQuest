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






void GRIEL_prepareText(u8 *str, s16 array[]) {
    s16 i = 0;
    s16 j = 0;

    void _debug_prepareText(s16 chr) {
        return;
        
        u8 write[2] = {chr, '\0'};
        drawInt(chr, 0, devu0, 5);
        VDP_drawText(write, 10, devu0);
        ++devu0;
    }

    while (str[i]) {
        s16 chr0 = str[i+0];
        s16 chr1 = str[i+1];

        i++;
         _debug_prepareText(chr0);

        if (chr0 == 195)
        {
            i++;
            _debug_prepareText(chr1);

            if (0);
            else if (chr1 == 186) chr0 =  31; // ú
            else if (chr1 == 179) chr0 =  30; // ó
            else if (chr1 == 177) chr0 =  29; // ñ
            else if (chr1 == 173) chr0 =  28; // í
            else if (chr1 == 169) chr0 =  27; // é
            else if (chr1 == 161) chr0 =  26; // á
            else if (chr1 == 154) chr0 =  25; // Ú
            else if (chr1 == 147) chr0 =  24; // Ó
            else if (chr1 == 145) chr0 =  23; // Ñ
            else if (chr1 == 141) chr0 =  22; // Í
            else if (chr1 == 137) chr0 =  21; // É
            else if (chr1 == 129) chr0 =  20; // Á
            else if (chr1 == 185) chr0 =  17; // ù
            else if (chr1 == 178) chr0 =  16; // ò
            else if (chr1 == 167) chr0 =  15; // ç
            else if (chr1 == 172) chr0 =  14; // ì
            else if (chr1 == 168) chr0 =  13; // è
            else if (chr1 == 160) chr0 =  12; // à
            else if (chr1 == 153) chr0 =  11; // Ù
            else if (chr1 == 146) chr0 =  10; // Ò
            else if (chr1 == 135) chr0 =   9; // Ç
            else if (chr1 == 140) chr0 =   8; // Ì
            else if (chr1 == 136) chr0 =   7; // È
            else if (chr1 == 128) chr0 =   6; // À
            else if (chr1 == 182) chr0 =   5; // ö
            else if (chr1 == 150) chr0 =   4; // Ö
            else if (chr1 == 187) chr0 =   3; // û
            else if (chr1 == 180) chr0 =   2; // ô
            else if (chr1 == 174) chr0 =   1; // î
            // else if (chr1 == XXX) chr0 =   0; // YYY
            else if (chr1 == 170) chr0 =  -1; // ê
            else if (chr1 == 162) chr0 =  -2; // â
            else if (chr1 == 165) chr0 =  -2; // å // almost equal char
            else if (chr1 == 155) chr0 =  -3; // Û
            else if (chr1 == 148) chr0 =  -4; // Ô
            // else if (chr1 == XXX) chr0 =  -4; // YYY
            else if (chr1 == 142) chr0 =  -6; // Î
            else if (chr1 == 138) chr0 =  -7; // Ê
            else if (chr1 == 130) chr0 =  -8; // Â
            else if (chr1 == 133) chr0 =  -8; // Å // almost equal char
            else if (chr1 == 164) chr0 =  -9; // ä
            else if (chr1 == 132) chr0 = -10; // Ä
            else if (chr1 == 188) chr0 = -11; // ü 
            // else if (chr1 == XXX) chr0 = -12; // YYY
            else if (chr1 == 175) chr0 = -13; // ï
            // else if (chr1 == XXX) chr0 = -14; // YYY
            // else if (chr1 == XXX) chr0 = -15; // YYY
            // else if (chr1 == XXX) chr0 = -16; // YYY
            else if (chr1 == 156) chr0 = -17; // Ü
            // else if (chr1 == XXX) chr0 =  -1); // YYY
            // else if (chr1 == XXX) chr0 =  -1); // YYY
            else if (chr1 == 143) chr0 = -20; // Ï
            else if (chr1 == 181) chr0 = -21; // õ
            else if (chr1 == 149) chr0 = -22; // Õ
            else if (chr1 == 163) chr0 = -23; // ã
            else if (chr1 == 131) chr0 = -24; // Ã            
        }

        if (chr0 == 194)
        {
            i++;
            _debug_prepareText(chr1);

            if (0);
            else if (chr1 == 191) chr0 =  19; // ¿
            else if (chr1 == 161) chr0 =  18; // ¡
        }

        array[j++] = chr0;
    }
}

void GRIEL_drawText(u8 *str, u16 x, u16 y) {
    s16 buffer[120];

    u16 plan = VDP_getTextPlane();
    u16 pal  = VDP_getTextPalette();
    u16 prio = VDP_getTextPriority();

    GRIEL_prepareText(str, buffer);

    for (u16 i = 0; buffer[i]; i++) {
        u16 tile = TILE_FONT_INDEX + buffer[i] - 32;
        VDP_setTileMapXY(plan, TILE_ATTR_FULL(pal, prio, 0, 0, tile), x++, y);
    }
}
