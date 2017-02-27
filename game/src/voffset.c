#include "../inc/include.h"


static s16 _horizontal = 0;
static s16 _vertical   = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void voffset_vertical_set ( s16 offset )
{
	_vertical = offset;
}


void voffset_horizontal_set ( s16 offset )
{
	_horizontal = offset;
}


s16 voffset_vertical_get ( )
{
	return _vertical;
}


s16 voffset_horizontal_get ( )
{
	return _horizontal;
}
