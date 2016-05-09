#include "../inc/include.h"



static struct genresSprites *_genres;
static u16            _base;
static u16            _palette;
static u8             _counter;
static u8             _positions[96];
static u8             _next_sprite;





void text_init ( struct genresSprites *genres, u16 vram, u16 palette )
{
	_genres  = genres;
	_base    = vram;
	_palette = palette;

	text_reset();
}


void text_reset ( )
{
	_next_sprite = 0;
	_counter     = 0;
	memset ( _positions, 0, 96 );
}


void text_setNextSprite ( u8 next )
{
	_next_sprite = next;
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


	while ( (chr = *string++) )
	{
		inc = 0;
		chr -= ( 32 + 1 );
		chr  = ( chr == 255 ) ? 0 : chr;

		if ( ! _positions[chr] )
		{
			_positions[chr] = _counter++;
			VDP_loadTileData ( _genres->sprites[chr], POSITION, 4, 0 );
		}

		for ( j = 0; j < height; j++ )
		{
			for ( k = 0; k < width; k++ )
			{
				VDP_setTileMapXY ( APLAN, TILE_ATTR_FULL ( _palette, 0, 0, 0, POSITION ), i*width + x + j, y + k );
				++inc;
			}
		}

		if ( ms > 4 )
		{
			waitMs ( ms );
		}

		++i;
	}
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
		chr = (u8) string[i];
		chr -= ( 32 + 1 );
		chr  = ( chr == 255 ) ? 0 : chr;

		if ( chr != 0 ) // isn't space
		{
			if ( ! _positions[chr] )
			{
				_positions[chr] = _counter++;
				VDP_loadTileData ( _genres->sprites[chr], TILE, size, 0 );
			}


			VDP_setSprite ( _next_sprite, x+i*width, y, size, ATTR, _next_sprite + 1 );
			++_next_sprite;

			if ( ms > 4 )
			{
				VDP_updateSprites();
				waitMs ( ms );
			}
		}
	}

	return _next_sprite;
}



u16 text_draw_sprites_centered ( u8 *string, u16 ms )
{
	const u16 x = VDP_getScreenWidth()  / 2  -  strlen (string) * _genres->width / 2;
	const u16 y = VDP_getScreenHeight() / 2  - _genres->height  / 2;

	return text_draw_sprite ( string, x, y, ms );
}



u16 text_draw_sprites_x_centered ( u8 *string, u16 y, u16 ms )
{
	const u16 x = VDP_getScreenWidth()  / 2  -  strlen (string) * _genres->width / 2;

	return text_draw_sprite ( string, x, y, ms );
}


