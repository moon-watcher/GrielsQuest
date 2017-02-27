#ifndef _MUSIC_H_
#define _MUSIC_H_


enum
{
   MUSIC_TYPE_TFM = 1,
   MUSIC_TYPE_XGM,
   MUSIC_TYPE_VGM
};


typedef struct
{
	u8  type;
	u8 *title;
	u8 *data;
}
MUSIC;


void   music_play       ( MUSIC *m );
void   music_stop       ( );
u16    music_is_playing ( );

#endif
