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
    chr  = ( chr == 255 ) ? 0 : chr;

    switch ( chr )
    {
        case 248: chr = 95; break; // Ú
        case 247: chr = 94; break; // Ó
        case 245: chr = 93; break; // Í
        case 244: chr = 92; break; // É
        case 243: chr = 91; break; // Á
        case 234: chr = 90; break; // Ù
        case 233: chr = 89; break; // Ò
        case 231: chr = 88; break; // Ì
        case 230: chr = 87; break; // È
        case 229: chr = 86; break; // À
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


	SYS_disableInts();

	while ( (chr = *string++) )
	{
		inc = 0;
		chr = parse_chr ( chr );

		if ( ! _positions[chr] )
		{
			_positions[chr] = _counter++;
			VDP_loadTileData ( _genres->sprites[chr], POSITION, 4, 0 );
		}

		for ( j = 0; j < height; j++ )
		{
			for ( k = 0; k < width; k++ )
			{
				VDP_setTileMapXY ( PLAN_A, TILE_ATTR_FULL ( _palette, 0, 0, 0, POSITION ), i*width + x + j, y + k );
				++inc;
			}
		}

		if ( ms > 3 )
		{
			waitMs ( ms );
		}

		++i;
	}

	SYS_enableInts();
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
        u8 sprite, aux[40];

        memcpy ( aux, &string[0], pos );
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
        u8 sprite, aux[40];

        memcpy ( aux, &string[0], pos );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        sprite = text_draw_sprite ( aux, x, y, ms );

        memcpy ( aux, &string[pos+1], strlen(string)-pos );
        x = VDP_getScreenWidth()  / 2  -  strlen (aux) * _genres->width / 2;
        sprite = text_draw_sprite ( aux, x, y+_genres->height, ms );

        return sprite;
    }

	return text_draw_sprite ( string, x, y, ms );
}


