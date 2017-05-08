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
	    if ( XGM_isPlaying() )
        {
            XGM_stopPlay();
            VDP_waitVSync();
            VDP_waitVSync();
            VDP_waitVSync();
        }
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



u16 music_is_playing ( )
{
   u16 ret = 0;

   switch ( _type )
   {
      case MUSIC_TYPE_TFM:
         break;

      case MUSIC_TYPE_XGM:
         ret = SND_isPlaying_XGM();
         break;

      case MUSIC_TYPE_VGM:
         ret = SND_isPlaying_VGM();
         break;
   }

   return ret;
}
