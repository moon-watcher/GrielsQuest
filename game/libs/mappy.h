#pragma once

#ifndef _MAPPY_H_
#define _MAPPY_H_


struct mappyResource
{
	u16  width;
	u16  height;
	u16  nbColors;
	u32  ptrPal;
	u16  nbTiles;
	u32  ptrTiles;
	u16  nbLayers;
	u32 *maps;
};

struct mappyLevel
{
	u8  idxPal;
	u16 idxTile;
	u16 idxLevel;
	u16 fieldAdr;
	const struct mappyResource *data;
};



void mappy_load        ( struct mappyLevel *mLevel );
void mappy_set_palette ( struct mappyLevel *mLevel );
void mappy_draw        ( struct mappyLevel *mLevel, s8 x_pos, s8 y_pos, s8 x_inner, s8 y_inner, u8 width, u8 height, u8 prio );
void mappy_all         ( struct mappyLevel *mLevel, s8 x_pos, s8 y_pos, s8 x_inner, s8 y_inner, u8 width, u8 height, u8 prio );
void map_info          ( );



#endif // _MAPPY_H_
