#include <genesis.h>
#include "mappy.h"



//// based on Kaneda's mappy sample
//// no borrar

//void mappy_load ( struct mappyLevel *mLevel )
//{
//	u16 x, y, tile;
//	u16 *curMap = (u16*) mLevel->data->maps [ mLevel->idxLevel ];
//
//	VDP_setPalette ( mLevel->idxPal, palette_black );
//	VDP_loadTileData ( (u32*) mLevel->data->ptrTiles, VRAM_BG_POS, mLevel->data->nbTiles, 1 );
//
//	for ( y = 0; y < mLevel->data->height; y++ )
//	{
//		for ( x = 0; x < mLevel->data->width; x++ )
//		{
//			tile = y * mLevel->data->width + x ;
//			tile = TILE_ATTR_FULL ( mLevel->idxPal, 0, 0, 0, curMap [ tile ] + VRAM_BG_POS ) ;
//
//			VDP_setTileMapXY ( mLevel->fieldAdr, tile, x, y );
//		}
//	}
//
//	VDP_setPalette ( mLevel->idxPal, (u16*) mLevel->data->ptrPal );
//}


void mappy_load ( struct mappyLevel *mLevel )
{
	VDP_loadTileData ( (u32*) mLevel->data->ptrTiles, mLevel->idxTile, mLevel->data->nbTiles, 0 );
}


void mappy_set_palette ( struct mappyLevel *mLevel )
{
	VDP_setPalette ( mLevel->idxPal, (u16*) mLevel->data->ptrPal );
}


void mappy_draw ( struct mappyLevel *mLevel, s8 x_pos, s8 y_pos, s8 x_inner, s8 y_inner, u8 width, u8 height, u8 prio )
{
	u16 x, y, aux, xxx, *map = (u16*) mLevel->data->maps [ mLevel->idxLevel ];

	for ( y = 0; y < height; y++ )
	{
		aux = ( y + y_inner ) * mLevel->data->width + x_inner;

		for ( x = 0; x < width; x++ )
		{
         xxx = TILE_ATTR_FULL ( mLevel->idxPal, prio, 0, 0, map [ aux+x ] + mLevel->idxTile );

			VDP_setTileMapXY ( mLevel->fieldAdr, xxx, x + x_pos, y + y_pos );
		}
	}
}


void mappy_all ( struct mappyLevel *mLevel, s8 x_pos, s8 y_pos, s8 x_inner, s8 y_inner, u8 width, u8 height, u8 prio )
{
	mappy_load        ( (struct mappyLevel*) mLevel );
	mappy_set_palette ( (struct mappyLevel*) mLevel );
	mappy_draw        ( (struct mappyLevel*) mLevel, x_pos, y_pos, x_inner, y_inner, width, height, prio );
}


void map_info ( )
{
	//	u8 sy[16], sx[16];
	//
	//	intToStr ( global_get_y(), sy, 1 );
	//	intToStr ( global_get_x(), sx, 1 );
	//
	//	VDP_drawText ( sx,  1, 2 );
	//	VDP_drawText ( ",", 2, 2 );
	//	VDP_drawText ( sy,  3, 2 );
}

