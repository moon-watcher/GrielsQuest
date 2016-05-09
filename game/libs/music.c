#include <genesis.h>
#include "music.h"


static u8 _type = 0;


void music_play ( MUSIC *m )
{
	_type = m->type;

	//music_stop();

	if ( _type == MUSIC_TYPE_TFM )
	{
		SND_startPlay_TFM ( (u8*) m->data );
	}
	else if ( _type == MUSIC_TYPE_XGM )
	{
		SND_startPlay_XGM ( (u8*) m->data );
	}
	else if ( _type == MUSIC_TYPE_VGM )
	{
		SND_startPlay_VGM ( (u8*) m->data );
	}
}


void music_stop ( )
{
	if ( _type == MUSIC_TYPE_TFM )
	{
		SND_stopPlay_TFM ( );
	}
	else if ( _type == MUSIC_TYPE_XGM )
	{
		SND_stopPlay_XGM ( );
	}
	else if ( _type == MUSIC_TYPE_VGM )
	{
		SND_stopPlay_VGM ( );
	}
	else
	{
		Z80_unloadDriver();
	}
}
