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


void bigtext_init ( struct genresSprites *genres, u16 vram, u16 palette )
{
	_genres  = genres;
	_base    = vram;
	_palette = palette;

	bigtext_reset();
}


void bigtext_reset ( )
{
	_sprite = 0;
	_counter     = 0;
	memset ( _positions, 0, 96 );
}


void bigtext_setSprite ( u8 next )
{
	_sprite = next;
}



void bigtext_draw ( u8 *string, u8 x, u8 y, u16 ms )
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




void bigtext_draw_center ( u8 *string, u8 y, u16 ms )
{
	u16 len = strlen(string)*2;
	u16 x = 20 - len / 2;

	bigtext_draw ( string, x, y, ms );
}





u16 bigtext_draw_sprite ( u8 *string, u16 x, u16 y, u16 ms )
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


u16 bigtext_draw_sprites_centered ( u8 *string, u16 ms )
{
    u16 y = VDP_getScreenHeight() / 2  - _genres->height / 2;
    return bigtext_draw_sprites_x_centered(string, y, ms);
}



u16 bigtext_draw_sprites_x_centered ( u8 *string, u16 y, u16 ms )
{
    u16 x = VDP_getScreenWidth()  / 2  - _genres->width  / 2 * strlen ( string );

	u8 pos = get_jump_pos ( string );

	if ( pos )
    {
        u8 sprite, aux[40] = {};

        memcpy ( aux, &string[0], pos-1 );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        sprite = bigtext_draw_sprite ( aux, x, y, ms );

        memcpy ( aux, &string[pos+1], strlen(string)-pos );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        sprite = bigtext_draw_sprite ( aux, x, y+_genres->height, ms );

        return sprite;
    }

	return bigtext_draw_sprite ( string, x, y, ms );
}








