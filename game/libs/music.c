#include <genesis.h>
#include "music.h"


#define wait  SYS_doVBlankProcess();SYS_doVBlankProcess();SYS_doVBlankProcess();SYS_doVBlankProcess();SYS_doVBlankProcess();


void music_play ( MUSIC *m )
{
    if ( !m || !m->data )
    {
        music_stop ( );
        return;
    }

    if ( XGM_isPlaying() )
    {
        music_stop ( );
    }

    SYS_disableInts();
    XGM_stopPlay();
    SYS_enableInts();

    wait
    SYS_disableInts();
    XGM_setMusicTempo ( 50 );
    XGM_startPlay ( (u8*) m->data );
    SYS_enableInts();

    wait
    SYS_disableInts();
    XGM_setForceDelayDMA ( 1 );
    SYS_enableInts();

    wait
}


void music_stop ( )
{
    if ( !XGM_isPlaying() )
    {
        return;
    }

    wait
    SYS_disableInts();
    XGM_stopPlay();
    SYS_enableInts();

    wait
    SYS_disableInts();
    XGM_stopPlayPCM ( SOUND_PCM_CH1 ); // prevents long samples
    //XGM_stopPlayPCM ( SOUND_PCM_CH2 );
    //XGM_stopPlayPCM ( SOUND_PCM_CH3 );
    //XGM_stopPlayPCM ( SOUND_PCM_CH4 );
    SYS_enableInts();

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
//			SYS_doVBlankProcess();
//			SYS_doVBlankProcess();
//			SYS_doVBlankProcess();
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
//            SYS_doVBlankProcess();
//            SYS_doVBlankProcess();
//            SYS_doVBlankProcess();
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
