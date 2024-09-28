#pragma once

#define PRAYER_PRAYERS  11
#define PRAYER_LINES     6


typedef struct
{
	u8  keyword [ 9 ];
	char *pharse [ PRAYER_LINES ];
}
PRAYER;

PRAYER *prayer_get  ( u16 i );
void    prayer_show ( u16 level );
bool    prayer_compare ( PASSWORD8 pwd );
