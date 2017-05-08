#include <genesis.h>


static u16 cache  [ 64 ] = { [0 ... 63] = 0x0000 };


//////////////////////////////////////////////////////////////////////////////////////////////////////////


void displayInit ( )
{
	memsetU16 ( cache, 0, 64 );
}


void preparePal ( u16 pal, u16 *colors )
{
	memcpyU16 ( cache + ( pal << 4 ), colors, 16 );
}


void prepareColors ( u16 *colors )
{
	memcpyU16 ( cache, colors, 64 );
}


void prepareColor ( u16 index, u16 color )
{
	cache [ index ] = color;
}


void displayOff ( u16 frames )
{
    SYS_disableInts();
    VDP_fadeOutAll ( frames ? frames : 1, 0 );
    SYS_enableInts();
}


void displayOn ( u16 frames )
{
    SYS_disableInts();
    VDP_fadeAllTo ( (u16*) cache, frames ? frames : 1, 0 );
    SYS_enableInts();
}


u16 *getColors ( )
{
	return (u16*) cache;
}
