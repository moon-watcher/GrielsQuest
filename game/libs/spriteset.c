#include <genesis.h>
#include <genres.h>

#include "spriteset.h"


void spriteset_new ( SPRITESET *set, struct genresSprites *res, u8 width, u8 height )
{
	set->res    = ( struct genresSprites *) res;
	set->width  = width;
	set->height = height;
}



void spriteset_load ( SPRITESET *set, u16 vrampos, u16 dma )
{
	set->vrampos = vrampos;
	VDP_loadTileData ( set->res->sprites[0], set->vrampos, spriteset_tiles(set), dma );
}


//
// OJO, no hace FlipH ni FlipV
//
void spriteset_show ( SPRITESET *set, u8 sprite, s16 pos_x, s16 pos_y, u16 tile_attr )
{
	set->first_sprite = sprite;

	u16 x, y;
	u16 vrampos = set->vrampos;

	const u16 base = ( ( tile_attr >> 11 ) << 11 );

	for ( y = 0; y < set->height; y++ )
	{
		for ( x = 0; x < set->width; x++ )
		{
			s16 xx = pos_x + x * set->res->width;
			s16 yy = pos_y + y * set->res->height;

			VDP_setSprite ( sprite, xx, yy, set->res->size >> 8, base + vrampos, sprite+1 );

			vrampos += ( ( set->res->width  >> 3 ) * ( set->res->height >> 3 ) );
			++sprite;
		}
	}
}



void spriteset_move ( SPRITESET *set, s16 pos_x, s16 pos_y )
{
	u16 x, y;
	u16 sprite = set->first_sprite;

	for ( y = 0; y < set->height; y++ )
	{
		for ( x = 0; x < set->width; x++ )
		{
			s16 xx = pos_x + x * set->res->width;
			s16 yy = pos_y + y * set->res->height;

			VDP_setSpritePosition ( sprite++, xx, yy );
		}
	}
}



u16 spriteset_tiles ( SPRITESET *set )
{
	return ( set->res->width >> 3 ) * ( set->res->height >> 3 ) * set->width * set->height;;
}



u16 spriteset_sprites ( SPRITESET *set )
{
	return set->width * set->height;
}
