#pragma once

#ifndef _MUSICLIST_H_
#define _MUSICLIST_H_

#include "../libs/music.h"

enum
{
   MUSIC_INTRO,
   MUSIC_TITLE,
   MUSIC_MAP,
   MUSIC_NEW_ROUND,
   MUSIC_SCLEAR,
   MUSIC_GAME_OVER,
   MUSIC_BOSQUE_1,
   MUSIC_BOSQUE_2,
   MUSIC_DESIERTO_1,
   MUSIC_DESIERTO_2,
   MUSIC_DESIERTO_3,
   MUSIC_HIELO_1,
   MUSIC_HIELO_2,
   MUSIC_HIELO_3,
   MUSIC_PLAYA_1,
   MUSIC_PLAYA_2,
   MUSIC_PLAYA_3,
   MUSIC_GATE,
   MUSIC_CAVERNA_1,
   MUSIC_CAVERNA_2,
   MUSIC_SOLO_DRUMS,
   MUSIC_ENDING_1,
   MUSIC_ENDING_3,
   MUSIC_BOSS,
   MUSIC_FSCLEAR,
   MUSIC_STAFF,
   MUSIC_EXTRA,

   MUSIC_MAX
};


MUSIC *musiclist_get  ( u8 nb );
void   musiclist_play ( u8 nb );


#endif
