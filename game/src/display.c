#include <genesis.h>


static       u16 cache  [ 64 ] = { [0 ... 63] = 0x0000 };
static const u16 blacks [ 64 ] = { [0 ... 63] = 0x0000 };


//////////////////////////////////////////////////////////////////////////////////////////////////////////


static void setDisplay ( u16 on, u16 frames, u16 *colors )
{
    SYS_doVBlankProcess();

	if ( frames )
	{
	    if ( on )
        {
            PAL_fadeToAll ( (u16*) colors, frames, 0 );
        }
        else
        {
            PAL_fadeOutAll ( frames, 0 );
        }
	}
    else
    {
        SYS_disableInts ( );
        SYS_enableInts ( );
        Palette p = { 64, colors};
        PAL_setPaletteColors ( 0, &p, CPU);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////


void displayInit ( )
{
	memset ( cache, 0, 64 );
}


void preparePal ( u16 pal, u16 *colors )
{
	memcpy ( cache + ( pal << 4 ), colors, 16 );
}


void prepareColors ( u16 *colors )
{
	memcpy ( cache, colors, 64 );
}


void prepareColor ( u16 index, u16 color )
{
	cache [ index ] = color;
}


void displayOff ( u16 frames )
{
    setDisplay ( 0, frames, (u16*) blacks );
}


void displayOn ( u16 frames )
{
    setDisplay ( 1, frames, (u16*) cache );
}


u16 *getColors ( )
{
	return (u16*) cache;
}
