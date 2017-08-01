#include <genesis.h>
#include "music.h"


#define wait  VDP_waitVSync();VDP_waitVSync();VDP_waitVSync();


void music_play ( MUSIC *m )
{
    wait
    SND_setForceDelayDMA_XGM ( 1 );

    wait
    SND_startPlay_XGM ( (u8*) m->data );

    wait
}


void music_stop ( )
{
    wait
    XGM_stopPlay();

    wait
    XGM_stopPlayPCM ( SOUND_PCM_CH1 ); // prevents long samples
    //XGM_stopPlayPCM ( SOUND_PCM_CH2 );
    //XGM_stopPlayPCM ( SOUND_PCM_CH3 );
    //XGM_stopPlayPCM ( SOUND_PCM_CH4 );

    wait
}



u16 music_is_playing ( )
{
   return 0;
}











//#include <genesis.h>
//#include "music.h"
//
//
//static u8 _type = 0;
//
//
//void music_play ( MUSIC *m )
//{
//	_type = m->type;
//
//	//music_stop();
//
//	if ( _type == MUSIC_TYPE_TFM )
//	{
//		SND_startPlay_TFM ( (u8*) m->data );
//	}
//	else if ( _type == MUSIC_TYPE_XGM )
//	{
//		u8 playing = SND_isPlaying_XGM();
//
//		music_stop();
//
//		if ( playing )
//		{
//			VDP_waitVSync();
//			VDP_waitVSync();
//			VDP_waitVSync();
//		}
//
//		SND_startPlay_XGM ( (u8*) m->data );
//		SND_setForceDelayDMA_XGM ( 1 );
//	}
//	else if ( _type == MUSIC_TYPE_VGM )
//	{
//		SND_startPlay_VGM ( (u8*) m->data );
//	}
//
//}
//
//
//void music_stop ( )
//{
//	if ( _type == MUSIC_TYPE_TFM )
//	{
//		SND_stopPlay_TFM ( );
//	}
//	else if ( _type == MUSIC_TYPE_XGM )
//	{
//	    if ( XGM_isPlaying() )
//        {
//            XGM_stopPlay();
//
//            XGM_stopPlayPCM ( SOUND_PCM_CH1 ); // prevents long samples
//            //XGM_stopPlayPCM ( SOUND_PCM_CH2 );
//            //XGM_stopPlayPCM ( SOUND_PCM_CH3 );
//            //XGM_stopPlayPCM ( SOUND_PCM_CH4 );
//
//            VDP_waitVSync();
//            VDP_waitVSync();
//            VDP_waitVSync();
//        }
//	}
//	else if ( _type == MUSIC_TYPE_VGM )
//	{
//		SND_stopPlay_VGM ( );
//	}
//	else
//	{
//		Z80_unloadDriver();
//	}
//}
//
//
//
//u16 music_is_playing ( )
//{
//   u16 ret = 0;
//
//   switch ( _type )
//   {
//      case MUSIC_TYPE_TFM:
//         break;
//
//      case MUSIC_TYPE_XGM:
//         ret = SND_isPlaying_XGM();
//         break;
//
//      case MUSIC_TYPE_VGM:
//         ret = SND_isPlaying_VGM();
//         break;
//   }
//
//   return ret;
//}
