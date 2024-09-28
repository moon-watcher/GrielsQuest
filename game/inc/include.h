#pragma once

#ifndef _INCLUDE_H_
#define _INCLUDE_H_



#include <genesis.h>
#include <genres.h>
// #include <tfcplay.h>



///**
//* \struct genresSprites
//* genres Sprites definition structure.<br/>
//* - pal: pointer to pal data<br/>
//* - sprites: pointer to sprites data<br/>
//* - count: sprite number<br/>
//* - width: width of each sprite in pixels (not tiles!)<br/>
//* - height: height of each sprite in pixels (not tiles!)<br/>
//* - size: since we use width/height in pixel, useful info on sprite size<br/>
//*/
//typedef struct
//{
//   u16 *pal; // pointer to pal data
//   u32 **sprites; // pointer to sprites data
//   u16 count; // nb sprites
//   u16 width; // width of each sprite in pixels (not tiles!)
//   u16 height; // height of each sprite in pixels (not tiles!)
//   u16 size; // since we use width/height in pixel, useful info on sprite size
//   // TODO : size is not SGDK compliant, you need to use size>>8
//   // will be fixed in coming release
//} genresSprites;
//
//
///**
// * \struct genresTiles
// *      genres tile structure
// */
//typedef struct
//{
//   u16 *pal;               // pointer to pal data
//   u32 *tiles;             // pointer to tiles data
//   u16 width;              // width in tiles
//   u16 height;             // height in tiles
//   u16 compressedSize;     // 0
//}
//genresTiles;





// typedef enum
// {
//    false = 0,
//    true  = !false
// }
// bool;


#define MAX_SPRITE 80



#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define ABS(a) ( (a)<0 ? -(a) : (a) )

#define SWAP(x, y)   do { typeof(x) temp##x##y = x; x = y; y = temp##x##y; } while (0)

#define IMPLIES(x, y) (!(x) || (y))

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define SIGN(x) COMPARE(x, 0)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

//#define SWAP(x, y, T) do { T tmp = (x); (x) = (y); (y) = tmp; } while(0)
//#define SORT2(a, b, T) do { if ((a) > (b)) SWAP((a), (b), T); } while (0)

#define SET(d, n, v) do{ size_t i_, n_; for (n_ = (n), i_ = 0; n_ > 0; --n_, ++i_) (d)[i_] = (v); } while(0)
#define ZERO(d, n) SET(d, n, 0)


#define BitBool(x) (!(!(x)))
#define BitSet(arg,posn) ((arg) | (1L << (posn)))
#define BitClr(arg,posn) ((arg) & ~(1L << (posn)))
#define BitTst(arg,posn) BitBool((arg) & (1L << (posn)))
#define BitFlp(arg,posn) ((arg) ^ (1L << (posn)))


/*
// mas en:
// http://stackoverflow.com/questions/1772119/c-the-most-useful-user-made-c-macros-in-gcc-also-c99


// #define foreach(item, array) \
//    for(int keep=1, \
//            count=0,\
//            size=sizeof (array)/sizeof *(array); \
//        count != size; \
//        keep=1, count++) \
//      for(item = (array)+count; keep; keep = !keep)
//
//int main() {
//  int a[] = { 1, 2, 3 };
//  int sum = 0;
//  foreach(int const* c, a)
//    sum += *c;
//  printf("sum = %d\n", sum);
//
//  // multi-dim array
//  int a1[][2] = { { 1, 2 }, { 3, 4 } };
//  foreach(int (*c1)[2], a1)
//    foreach(int *c2, *c1)
//      printf("c2 = %d\n", *c2);
//}




//c(red)
//c(blue)
//c(green)
//c(yellow)
//c(brown)
//
//Now you can in your c file you can define your enum and your string conversion function:
//
//enum {
//#define c(color) color,
//# include "colors.def"
//#undef c
//};
//
//const char *
//color_to_string(enum color col)
//{
//    static const char *colors[] = {
//#define c(color) #color,
//# include "colors.def"
//#undef c
//    };
//    return (colors[col]);
//};




//#define NEW(type, n) ( (type *) malloc(1 + (n) * sizeof(type)) )
//
//And I use it like:
//
//object = NEW(object_type, 1);




// http://stackoverflow.com/questions/400951/does-c-have-a-foreach-loop-construct
//
// #define for_each_item(item, list) \
//    for(T * item = list->head; item != NULL; item = item->next)
//
//And can be used like
//
//for_each_item(i, processes) {
//    i->wakeup();
//}
//
//Iteration over an array is also possible:
//
// #define foreach(item, array) \
//    for(int keep = 1, \
//            count = 0,\
//            size = sizeof (array) / sizeof *(array); \
//        keep && count != size; \
//        keep = !keep, count++) \
//      for(item = (array) + count; keep; keep = !keep)
//
//And can be used like
//
//int values[] = { 1, 2, 3 };
//foreach(int *v, values) {
//    printf("value: %d\n", *v);
//}
//
//Edit: In case you are also interested in C++ solutions, boost has it (but C++ itself doesn't have a native for-each loop yet): Boost.ForEach
*/

#define HOW_TO_PLAY_TILE     32


#include "../../libs/stdarg.h"
#include "../../libs/conio.h"
#include "../../libs/binary.h"
#include "../../libs/dev.h"
#include "../../libs/burbuja.h"
#include "../../libs/list.h"

//#include "../libs/psg.h"
#include "../libs/vram.h"
#include "../libs/spritedispacher.h"
#include "../libs/joyreader.h"
#include "../libs/mappy.h"
#include "../libs/spriteset.h"
#include "../libs/waitbreak.h"
//#include "../libs/music.h"
//#include "../libs/wave.h"

#include "../res/intro.h"
#include "../res/title.h"
#include "../res/otherres.h"
#include "../res/commonres.h"
#include "../res/ambienteres.h"
#include "../res/finalres.h"
#include "../res/puertares.h"
//#include "../res/xgmres.h"
//#include "../res/waveres.h"
//#include "../res/fx_ding.h"
//#include "../res/fx_hahaha.h"
//#include "../res/resources.h"

#include "../inc/wavelist.h"
#include "../inc/psglist.h"
#include "../inc/musiclist.h"



//#include "../inc/cosas.h"

#include "../inc/display.h"
#include "../inc/gamestate.h"
// #include "../inc/genres_externs.h"
// #include "../inc/version.h"
#include "../inc/bigboy.h"
#include "../inc/animation.h"
#include "../inc/frases.h"
#include "../inc/level.h"
#include "../inc/tool.h"
#include "../inc/helpers.h"
#include "../inc/joy.h"
#include "../inc/object.h"
#include "../inc/chorrada.h"
#include "../inc/vobject.h"
#include "../inc/death.h"
#include "../inc/font.h"
#include "../inc/weapon.h"
#include "../inc/player.h"
#include "../inc/screen.h"
#include "../inc/vsprite.h"
#include "../inc/voffset.h"
#include "../inc/game.h"
#include "../inc/password.h"
#include "../inc/password8.h"
#include "../inc/text.h"
#include "../inc/bigtext.h"
#include "../inc/splist.h"
#include "../inc/toani.h"
#include "../inc/undo.h"
#include "../inc/cheats.h"
#include "../inc/howtoplay.h"
#include "../inc/pause.h"
#include "../inc/scoreball.h"
#include "../inc/stars.h"
#include "../inc/boss.h"
#include "../inc/screens/mapa.h"
#include "../inc/screens/intro.h"
#include "../inc/screens/final.h"
#include "../inc/screens/presentation.h"
#include "../inc/screens/puerta.h"
#include "../inc/screens/oldending.h"
#include "../inc/screens/oldintro.h"
#include "../inc/screens/staff.h"
#include "../inc/worlds/worlds.h"
#include "../inc/vint.h"
#include "../inc/typetext.h"
#include "../inc/language.h"
#include "../inc/prayer.h"



//
#endif
