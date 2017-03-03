#include "../inc/include.h"



const LEVEL w0r00 =
{
   7,  1,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,        0,       0,   TOCON1,   TOCON1,   TOCON1, TOCON1,   TOCON1,  TOCON1,  TOCON1,    TOCON1,       0,       0,       0,        0,       0 },
      {       0,        0,   STAFF,  DARKELF,   TOCON1,  TOCON1,       0,        0,   SWORD, DARKELF,    TOCON1,  TOCON1,  TOCON1,  TOCON1,        0,       0 },
      {       0,   TOCON1,  TOCON1,    SWORD,TOADSTOOL,       0,       0,   TOCON1,  TOCON1,   STAFF,         0,WILDBOAR,   CROSS,  TOCON1,        0,       0 },
      {       0,   TOCON1,  TOCON1,   TOCON1,   TOCON1, DARKELF,  TOCON1,   TOCON1,  TOCON1,  TOCON1, TOADSTOOL,  TOCON1,  TOCON1,  TOCON1,   TOCON1,       0 },
      {       0,   TOCON1,    DOOR,        0,   TOCON1,       0,   CROSS,TOADSTOOL,WILDBOAR,       0,     STAFF,  TOCON1,       0,     KEY,   TOCON1,       0 },
      {       0,   TOCON1,       0,        0,        0,  TOCON1,  TOCON1,        0,       0,  TOCON1,    TOCON1,       0,       0,       0,   TOCON1,       0 },
      {       0,   TOCON1,  TOCON1,   TOCON1,        0, DARKELF,   STAFF, WILDBOAR,       0,   SWORD,  WILDBOAR,       0,       0,       0,   TOCON1,       0 },
      {       0,        0,       0,   TOCON1,        0,       0, DARKELF,   TOCON1,  TOCON1,WILDBOAR,         0,       0,  TOCON1,  TOCON1,        0,       0 },
      {       0,        0,       0,   TOCON1,   TOCON1,  TOCON1,       0,   TOCON1,  TOCON1,   SWORD,    TOCON1,  TOCON1,  TOCON1,       0,        0,       0 },
      {       0,        0,       0,       0,   TOCON1,  TOCON1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,     TOCON1,       0,       0,        0,  ABBAYE_U,       0 },
      {       0,        0,       0,       0,        0,       0,       0,        0,       0,       0,          0,       0,       0,        0,  ABBAYE_D,       0 },
   }
};


const LEVEL w0r01 =
{
   //10,  5,
   7,  2,  // esta es la posción buena
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,        0,       0,       0,        0,       0,       0,       0,       0,        0,       0,       0,       0 },
      {       0,       0,       0,       0,   TOCON1,       0,  TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,        0,       0,       0,       0 },
      {       0,       0,       0,  TOCON1,        0,    DOOR,  TOCON1,        0,   CROSS,  TOCON1,     KEY,       0,   TOCON1,       0,       0,       0 },
      {       0,       0,  TOCON1,       0,        0,       0,  TOCON1,    SWORD,   CROSS,  TOCON1,       0,       0,        0,  TOCON1,       0,       0 },
      {       0,       0,  TOCON1,       0,        0,       0,  TOCON1,  DARKELF,   SWORD,  TOCON1,       0,       0,        0,  TOCON1,       0,       0 },
      {       0,       0,  TOCON1,       0,        0,       0,  TOCON1,    SWORD, DARKELF,  TOCON1,       0,       0,        0,  TOCON1,       0,       0 },
      {       0,       0,  TOCON1,       0,   TOCON1,       0,  TOCON1,  DARKELF,   STAFF,  TOCON1,       0,  TOCON1,        0,  TOCON1,       0,       0 },
      {       0,       0,  TOCON1,WILDBOAR,TOADSTOOL,  TOCON1,  TOCON1,TOADSTOOL,WILDBOAR,  TOCON1,  TOCON1,   SWORD,TOADSTOOL,  TOCON1,       0,       0 },
      {       0,       0,       0,  TOCON1,  DARKELF,WILDBOAR,   STAFF,    SWORD, DARKELF, DARKELF,WILDBOAR, DARKELF,   TOCON1,       0,       0,       0 },
      {       0,       0,       0,       0,   TOCON1,  TOCON1,   CROSS,    SWORD,   CROSS,   SWORD,  TOCON1,  TOCON1,        0,       0,       0,       0 },
      {       0,       0,       0,       0,        0,       0,  TOCON1,   TOCON1,  TOCON1,   STAFF,       0,       0,        0,       0,       0,       0 }
   }
};


const LEVEL w0r02 =
{
   7,  0,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,        0,        0,        0,       0,        0,       0,        0,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,        0,        0,        0,   STAFF,        0,       0,        0,        0,       0,       0,       0,       0 },
      { PIEDRA1,   WILDBOAR,   WILDBOAR,   WILDBOAR,    WILDBOAR,    WILDBOAR,    WILDBOAR,   WILDBOAR,    WILDBOAR,   WILDBOAR,    WILDBOAR,    WILDBOAR,   WILDBOAR,   WILDBOAR, PIEDRA1,       0 },
      {       0, PIEDRA1,   WILDBOAR,   SWORD,TOADSTOOL,TOADSTOOL, DARKELF,   STAFF, DARKELF,   CROSS, DARKELF,    WILDBOAR,   STAFF, PIEDRA1,       0,       0 },
      {       0,       0, PIEDRA1,DARKELF,    STAFF, DARKELF,    CROSS,DARKELF,TOADSTOOL,DARKELF,    CROSS,TOADSTOOL, PIEDRA1,       0,       0,       0 },
      {       0,       0,       0, PIEDRA1,TOADSTOOL,    SWORD,TOADSTOOL,   STAFF, DARKELF,   WILDBOAR,TOADSTOOL,  PIEDRA1,       0,       0,       0,       0 },
      {       0,       0,       0,       0,  PIEDRA1,TOADSTOOL,    WILDBOAR,DARKELF,TOADSTOOL,   SWORD,  PIEDRA1,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,        0,  PIEDRA1, DARKELF,     KEY,    WILDBOAR, PIEDRA1,        0,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,        0,        0,  PIEDRA1,   WILDBOAR,  PIEDRA1,       0,        0,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,        0,        0,        0,    DOOR,        0,       0,        0,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,        0,  PIEDRA1,  PIEDRA1, PIEDRA1,  PIEDRA1, PIEDRA1,        0,        0,       0,       0,       0,       0 },
   }
};


const LEVEL w0r03 =
{
   7,  0,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,    TOMB1,       0,   CROSS,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1 },
      {   TOMB1,       0,  LEFT1,       0,  LEFT1,       0,   LEFT1,       0,       0, RIGHT1,       0,  LEFT1,       0,  LEFT1,   STAFF,   TOMB1 },
      {   TOMB1,  DOWN1,   TOCON1,    UP1,   TOCON1,    UP1,    TOCON1,  DOWN1,  DOWN1,   TOCON1,  DOWN1,   TOCON1,  DOWN1,   TOCON1,    UP1,   TOMB1 },
      {   TOMB1,       0, RIGHT1,       0, RIGHT1,       0,   LEFT1,       0,       0,  LEFT1,       0,  LEFT1,       0, RIGHT1,       0,   TOMB1 },
      {   TOMB1,  DOWN1,   TOCON1,    UP1,   TOCON1,  DOWN1,    TOCON1,    UP1,    UP1,   TOCON1,  DOWN1,   TOCON1,  DOWN1,   TOCON1,    UP1,   TOMB1 },
      {   TOMB1,       0,  LEFT1,       0,  LEFT1,       0,  RIGHT1,DARKELF,     KEY, RIGHT1,       0, RIGHT1,       0, RIGHT1,       0,   TOMB1 },
      {   TOMB1,  DOWN1,   TOCON1,  DOWN1,   TOCON1,  DOWN1,    TOCON1,    UP1,   WILDBOAR,   TOCON1,    UP1,   TOCON1,    UP1,   TOCON1,    UP1,   TOMB1 },
      {   TOMB1,       0,  LEFT1,       0,  LEFT1,       0,TOADSTOOL,   WILDBOAR,    DOOR, RIGHT1,       0, RIGHT1,   SWORD,  LEFT1,       0,   TOMB1 },
      {   TOMB1,  DOWN1,   TOCON1,    UP1,   TOCON1,  DOWN1,    TOCON1,  DOWN1,  DOWN1,   TOCON1,    UP1,   TOCON1,  DOWN1,   TOCON1,    UP1,   TOMB1 },
      {   TOMB1,       0, RIGHT1,       0,  LEFT1,       0,  RIGHT1,       0,       0, RIGHT1,       0, RIGHT1,       0, RIGHT1,       0,   TOMB1 },
      {   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,    TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1,   TOMB1 }
   }
};


const LEVEL w0r04 =
{
   1,  2,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {     KEY,        0,        0,        0,        0,        0,        0,        0,   STAFF,       0,    SWORD,  TOCON1,       0,   LEFT1,        0,       0 },
      {       0,    ZARZA,    ZARZA,    ZARZA,    ZARZA,    ZARZA,    ZARZA,    ZARZA,       0,       0,   TOCON1,       0,       0,  TOCON1,    SWORD,       0 },
      {   ZARZA,        0,    STAFF, WILDBOAR,   RIGHT1,    CROSS,TOADSTOOL,    SWORD,   ZARZA,       0,   TOCON1,       0,       0,       0, WILDBOAR,       0 },
      {   ZARZA,    CROSS,  DARKELF,    SWORD,    CROSS, WILDBOAR,  DARKELF,  DARKELF,   ZARZA,       0,  DARKELF,       0,       0,       0,   TOCON1,       0 },
      {   ZARZA,TOADSTOOL, WILDBOAR, WILDBOAR,  DARKELF,  DARKELF,WILDBOAR,     STAFF,   ZARZA,   ZARZA,    ZARZA,   ZARZA,   ZARZA,   ZARZA,   TOCON1,       0 },
      {   ZARZA,   RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,TOADSTOOL, DARKELF,  RIGHT1,   RIGHT1,  RIGHT1, DARKELF,    DOOR,   TOCON1,       0 },
      {   ZARZA,    SWORD,TOADSTOOL,    STAFF,    CROSS,TOADSTOOL,TOADSTOOL,    CROSS,   ZARZA,   ZARZA,    ZARZA,   ZARZA,   ZARZA,   ZARZA,        0,       0 },
      {   ZARZA,TOADSTOOL,TOADSTOOL, WILDBOAR,TOADSTOOL,    CROSS,TOADSTOOL,TOADSTOOL,   ZARZA,       0,        0,       0,       0,       0,        0,       0 },
      {   ZARZA, WILDBOAR,    CROSS,    STAFF,   RIGHT1, WILDBOAR,    STAFF,TOADSTOOL,   ZARZA,       0,   TOCON1,       0,       0,  TOCON1,        0,       0 },
      {       0,    ZARZA,    ZARZA,    ZARZA,    ZARZA,    ZARZA,  DARKELF,    ZARZA,       0,       0,        0,  TOCON1,       0,       0,   TOCON1,       0 },
      {       0,        0,        0,        0,        0,        0,        0,        0,       0,       0,        0,       0,       0,       0,        0,       0 }
   }
};



const LEVEL w0r05 =
{
   2, 8,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,         0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,       0 },
      {       0,       0,   CANDLE,   CANDLE,   CANDLE,   CANDLE,        0,        0,        0,        0,   CANDLE,   CANDLE,   CANDLE,   CANDLE,        0,       0 },
      {       0,  CANDLE,    CROSS, WILDBOAR, WILDBOAR, WILDBOAR,   CANDLE,        0,        0,   CANDLE, WILDBOAR, WILDBOAR, WILDBOAR,    CROSS,   CANDLE,       0 },
      {       0,  CANDLE,   CANDLE,   CANDLE,   CANDLE,    SWORD,  DARKELF,   CANDLE,   CANDLE,  DARKELF,    SWORD,   CANDLE,   CANDLE,   CANDLE,   CANDLE,       0 },
      {       0,  TOCON1,    STAFF,  DARKELF,  DARKELF,    SWORD,  DARKELF,      UP1,      UP1,    SWORD,  DARKELF,  DARKELF,    STAFF,  DARKELF,   TOCON1,       0 },
      {       0,  TOCON1,  DARKELF,    SWORD,    STAFF,  DARKELF,  DARKELF,   RIGHT1,      KEY,        0,TOADSTOOL,  DARKELF,  DARKELF,  DARKELF,   TOCON1,       0 },
      {       0,  TOCON1,    SWORD,  DARKELF,  DARKELF,  DARKELF,    SWORD,    DOWN1,    DOWN1,TOADSTOOL,  DARKELF,    STAFF,    SWORD,TOADSTOOL,   TOCON1,       0 },
      {       0,   ZARZA,  DARKELF,  DARKELF,    STAFF,    SWORD,  DARKELF,   TOCON1,   TOCON1,TOADSTOOL,  DARKELF,    STAFF,    SWORD,TOADSTOOL,   TOCON1,       0 },
      {       0,   ZARZA,        0,        0,        0,        0,   TOCON1,        0,    LAKE1,    LAKE2,    SWORD,    STAFF, TOADSTOOL,    DOOR,   TOCON1,       0 },
      {       0,       0,    ZARZA,    ZARZA,    ZARZA,    ZARZA,        0,        0,    LAKE3,    LAKE4,   TOCON1,   TOCON1,   TOCON1,   TOCON1,        0,       0 },
      {       0,       0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,       0 }
   }
};


const LEVEL w0r06 =
{
   7,  5,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {   CROSS,        0,       0,        0,       0,       0,TOADSTOOL,        0,       0,        0,   WILDBOAR,TOADSTOOL,   WILDBOAR,    STAFF,TOADSTOOL,   SWORD },
      {       0, DARKELF, CANDLE,TOADSTOOL, CANDLE,DARKELF,  CANDLE,    WILDBOAR,    UP1,        0, CANDLE,    WILDBOAR, CANDLE,        0,  CANDLE,DARKELF },
      {   WILDBOAR,    CROSS, CANDLE,    SWORD, CANDLE,       0,  CANDLE,    CROSS,    UP1,        0, CANDLE,        0, CANDLE,        0,  CANDLE,       0 },
      {       0,        0, CANDLE,    STAFF, CANDLE,       0,  CANDLE,        0,    UP1,    WILDBOAR, CANDLE,        0, CANDLE,        0,  CANDLE,   CROSS },
      {DARKELF, DARKELF,       0,  CANDLE,   CROSS,       0,  CANDLE,        0,    UP1, DARKELF, CANDLE,        0, CANDLE,        0,  CANDLE,       0 },
      { CANDLE, DARKELF, CANDLE,TOADSTOOL, CANDLE,       0,  CANDLE,        0,    DOOR,      KEY, CANDLE,        0, CANDLE,TOADSTOOL,  CANDLE,       0 },
      { CANDLE,    STAFF, CANDLE,    CROSS, CANDLE,       0,  CANDLE,TOADSTOOL,  DOWN1, DARKELF, CANDLE,        0,       0,        0,  CANDLE,       0 },
      {       0,  CANDLE, CANDLE,    STAFF, CANDLE,       0,  CANDLE,    WILDBOAR,  DOWN1,        0, CANDLE,        0, CANDLE,TOADSTOOL,  CANDLE,       0 },
      {       0,TOADSTOOL, CANDLE,    WILDBOAR, CANDLE,       0,  CANDLE,        0,  DOWN1,TOADSTOOL, CANDLE,        0, CANDLE,        0,  CANDLE,   WILDBOAR },
      { CANDLE,    CROSS, CANDLE,        0, CANDLE,   WILDBOAR,  CANDLE,        0,  DOWN1,    STAFF, CANDLE,TOADSTOOL, CANDLE,    WILDBOAR,  CANDLE,       0 },
      {       0,        0,       0,        0,       0,       0,        0,        0,       0,        0,   WILDBOAR,        0,       0,        0,        0,       0 }
   }
};


const LEVEL w0r07 =
{
   6, 10,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,        0,       0,        0,       0,        0,       0,       0,       0,       0,        0,       0,ABBAYE_U,       0 },
      {       0,  TOCON1,  TOCON1,   TOCON1,  TOCON1,   TOCON1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  DOWN1,   TOCON1,  TOCON1,ABBAYE_D,       0 },
      {       0,  TOCON1,   SWORD,   DOWN1,  LEFT1,TOADSTOOL,  TOCON1,TOADSTOOL,       0,DARKELF,       0,DARKELF,    SWORD,DARKELF,  TOCON1,       0 },
      {   SWORD,  TOCON1,       0,   LEFT1,    UP1,     UP1,  TOCON1,   TOCON1,       0,  DOWN1,   WILDBOAR,   SWORD,    WILDBOAR,   STAFF,  TOCON1,       0 },
      {   STAFF,  TOCON1,DARKELF,    WILDBOAR,  TOCON1,     UP1,  LEFT1,   TOCON1,       0,  DOWN1,   SWORD,DARKELF,TOADSTOOL,   CROSS,  TOCON1,       0 },
      {DARKELF,  TOCON1,   STAFF, DARKELF,   CROSS,   TOCON1,       0,        0,       0,  DOWN1,       0,  TOCON1,        0,  DOWN1,  TOCON1,       0 },
      {    UP1,  TOCON1,   WILDBOAR,    WILDBOAR,   WILDBOAR,        0,       0,   TOCON1,DARKELF,  DOWN1,       0,  TOCON1,        0,  DOWN1,  TOCON1,       0 },
      {       0,  TOCON1,   STAFF,    WILDBOAR,DARKELF,   TOCON1,       0,   TOCON1,   STAFF,  LEFT1,       0,   CROSS,        0,   WILDBOAR,  TOCON1,       0 },
      {       0,  TOCON1,   STAFF,    WILDBOAR,  TOCON1,        0,       0,   LEFT1,       0, RIGHT1, RIGHT1, RIGHT1,   TOCON1,    DOOR,  TOCON1,       0 },
      {       0,  TOCON1,  TOCON1,TOADSTOOL,  TOCON1,   TOCON1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,       0 },
      {       0,       0,       0,        0,     KEY,   TOCON1,       0,    STAFF,       0,       0,       0,       0,        0,       0,   WILDBOAR,       0 }
   }
};


const LEVEL w0r08 =
{
   5,  9,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,        0,        0,        0,     TOMB1,     TOMB1,     TOMB1,     TOMB1,        0,        0,        0,        0,        0,       0 },
      {       0,       0,       0,        0,     TOMB1,     TOMB1,     TOMB1,  DARKELF,    CROSS,     TOMB1,     TOMB1,     TOMB1,        0,        0,        0,       0 },
      {       0,       0,    TOMB1,     TOMB1,     TOMB1, WILDBOAR,    CROSS, WILDBOAR,TOADSTOOL,TOADSTOOL,    STAFF,     TOMB1,     TOMB1,     TOMB1,        0,       0 },
      {       0,    TOMB1,    TOMB1, WILDBOAR,    CROSS, WILDBOAR, WILDBOAR, WILDBOAR,    STAFF,TOADSTOOL,TOADSTOOL,TOADSTOOL,TOADSTOOL,     TOMB1,     TOMB1,       0 },
      {       0,    TOMB1,    DOOR, WILDBOAR, WILDBOAR,    SWORD,  DARKELF,  DARKELF,  DARKELF,TOADSTOOL,    CROSS,TOADSTOOL,TOADSTOOL,      KEY,     TOMB1,       0 },
      {       0,       0,    TOMB1,     TOMB1,     TOMB1,    CROSS,  DARKELF,  DARKELF,    SWORD,TOADSTOOL,TOADSTOOL,     TOMB1,     TOMB1,     TOMB1,        0,       0 },
      {       0,       0,       0,        0,     TOMB1,  DARKELF,  DARKELF,    STAFF,  DARKELF,TOADSTOOL,    STAFF,     TOMB1,        0,        0,        0,       0 },
      {       0,       0,       0,        0,     TOMB1,  DARKELF,    SWORD,  DARKELF,    STAFF,  DARKELF,TOADSTOOL,     TOMB1,        0,        0,        0,       0 },
      {       0,       0,       0,        0,     TOMB1,  DARKELF,  DARKELF,  DARKELF,  DARKELF,  DARKELF,  DARKELF,     TOMB1,        0,        0,        0,       0 },
      {       0,       0,       0,        0,     TOMB1,        0,        0,    SWORD,    SWORD,    SWORD,    STAFF,     TOMB1,        0,        0,        0,       0 },
      {       0,       0,       0,        0,        0,     TOMB1,     TOMB1,     TOMB1,     TOMB1,     TOMB1,     TOMB1,        0,        0,        0,        0,       0 }
   }
};


const LEVEL w0r09 =
{
   0, 10,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  RIGHT1, RIGHT1, RIGHT1,     KEY },
      {       0,        0,    SWORD,    SWORD,   WILDBOAR,       0,DARKELF,  TOCON1,       0,       0,   SWORD,   SWORD,    CROSS,  TOCON1,  DOWN1,DARKELF },
      {   STAFF,   TOCON1,   TOCON1,   TOCON1,  TOCON1,  TOCON1,  DOWN1,  TOCON1,  TOCON1,  TOCON1,   SWORD,  TOCON1,   TOCON1,  TOCON1,  DOWN1,  TOCON1 },
      {   CROSS,   TOCON1,        0,        0,       0,       0,       0,       0,       0,       0,       0,       0,        0,  TOCON1,  DOWN1,  TOCON1 },
      {   CROSS,   TOCON1,   TOCON1,   TOCON1,  TOCON1,  TOCON1,       0,  TOCON1,  TOCON1,  TOCON1,       0,       0,        0,       0,  LEFT1,  TOCON1 },
      {   CROSS,   TOCON1,    WILDBOAR,    WILDBOAR,   WILDBOAR,   WILDBOAR,   WILDBOAR,  LEFT1,  LEFT1,  TOCON1,       0,       0,        0,  TOCON1,       0,  TOCON1 },
      {       0,TOADSTOOL,TOADSTOOL,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,    UP1,  TOCON1,       0,  TOCON1,   TOCON1,  TOCON1,       0,  TOCON1 },
      {       0,        0,TOADSTOOL,TOADSTOOL,   STAFF,   STAFF,   STAFF, RIGHT1,    UP1,  TOCON1,       0,       0,        0,       0,       0,  TOCON1 },
      {       0,   TOCON1,   TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,       0,  TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1 },
      {       0,   TOCON1,   TOCON1,   TOCON1,   STAFF,   CROSS,   SWORD,DARKELF,DARKELF,DARKELF,DARKELF,DARKELF,TOADSTOOL,  TOCON1,  TOCON1,  TOCON1 },
      {       0,   TOCON1,   TOCON1,   TOCON1,    DOOR,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,    STAFF,  TOCON1,  TOCON1,  TOCON1 }
   }
};



const LEVEL w0r10 =
{
      10, 0,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {  RIGHT1, RIGHT1,  RIGHT1, RIGHT1,DARKELF,    STAFF,        0,   TOCON1,   CROSS,   SWORD,       0, DARKELF,       0,   WILDBOAR,       0,        0 },
      {     UP1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,   TOCON1,    CROSS,TOADSTOOL,  TOCON1,  TOCON1,  TOCON1,        0,       0,   WILDBOAR,  TOCON1,        0 },
      {     UP1,       0,        0,  TOCON1,  DOWN1,   LEFT1,        0,        0,       0,       0,       0,        0,       0,  TOCON1,       0,    WILDBOAR },
      {   TOCON1,   STAFF,     UP1,  TOCON1,  DOWN1,    STAFF,   TOCON1,   TOCON1,  TOCON1,    UP1,  TOCON1,   TOCON1,  TOCON1,       0,       0,TOADSTOOL },
      {    STAFF,  TOCON1,     UP1,   CROSS,  DOWN1,TOADSTOOL,TOADSTOOL,        0,       0,       0,       0,        0,       0,       0,ABBAYE_U,    STAFF },
      {TOADSTOOL,       0,        0,   CROSS,  DOWN1,        0,        0,   TOCON1,       0,  DOWN1,       0,    WILDBOAR,       0,       0,ABBAYE_D,TOADSTOOL },
      {    CROSS,DARKELF,        0,   WILDBOAR,  DOWN1,   TOCON1,        0,        0,       0,  DOWN1,  TOCON1,TOADSTOOL,  TOCON1,       0,  TOCON1,    WILDBOAR },
      {    STAFF,  TOCON1,        0,   WILDBOAR,  DOWN1,   LEFT1,   LEFT1,   LEFT1,  LEFT1,       0,DARKELF,    CROSS,  TOCON1,       0,  TOCON1,TOADSTOOL },
      {    SWORD,   WILDBOAR,TOADSTOOL,  LEFT1,  LEFT1,   TOCON1,    SWORD,    WILDBOAR,   WILDBOAR,       0,  TOCON1,    SWORD,  TOCON1,       0,  TOCON1, DARKELF },
      {   TOCON1,  TOCON1,   TOCON1,  TOCON1,       0,    STAFF,   TOCON1,   TOCON1,  TOCON1,  TOCON1,       0,   TOCON1,   SWORD,       0,  TOCON1,      KEY },
      {     DOOR,   WILDBOAR, DARKELF,   STAFF,       0,        0,        0, DARKELF,       0,       0,       0,        0,DARKELF,       0,  TOCON1,    SWORD }
   }
};



const LEVEL w0r11 =
{
   15,  0,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {   CROSS,    SWORD, RIGHT1, RIGHT1, RIGHT1, RIGHT1,TOADSTOOL,DARKELF,        0,    CROSS,   STAFF,  LEFT1,  LEFT1,   LEFT1,  LEFT1,       0 },
      {DARKELF, DARKELF,DARKELF,DARKELF,  TOCON1,  TOCON1,    SWORD,  TOCON1,   TOCON1,        0, RIGHT1, RIGHT1, RIGHT1,  RIGHT1, RIGHT1,  DOWN1 },
      {DARKELF, DARKELF,DARKELF,DARKELF, RIGHT1, RIGHT1,TOADSTOOL,       0,TOADSTOOL,    STAFF,  TOCON1,  TOCON1,  TOCON1,   TOCON1,  TOCON1,  DOWN1 },
      {       0, DARKELF,DARKELF,DARKELF,  TOCON1,  TOCON1,   TOCON1,       0,        0,   TOCON1,  TOCON1,DARKELF,DARKELF, DARKELF,    DOOR,  DOWN1 },
      {   SWORD,        0,       0,       0,  LEFT1,  LEFT1,        0,  LEFT1,        0, DARKELF,DARKELF,DARKELF,  TOCON1,   TOCON1,  TOCON1,  DOWN1 },
      {  TOCON1,TOADSTOOL,  TOCON1,  TOCON1,  TOCON1,  TOCON1,    SWORD,  TOCON1,   TOCON1, DARKELF,  TOCON1,  TOCON1,     KEY,TOADSTOOL,DARKELF,   WILDBOAR },
      {  TOCON1, DARKELF,DARKELF,       0,   SWORD,  TOCON1,    SWORD,    UP1,   TOCON1,TOADSTOOL,  TOCON1,  TOCON1,  TOCON1,   TOCON1,  TOCON1,  DOWN1 },
      {  TOCON1,    SWORD,DARKELF,DARKELF,   SWORD,  TOCON1,  RIGHT1,    UP1,   TOCON1, DARKELF,   WILDBOAR,   WILDBOAR,   STAFF,    SWORD,  TOCON1,  DOWN1 },
      {  TOCON1, DARKELF,DARKELF,DARKELF,   SWORD,  TOCON1,     UP1,  TOCON1,   TOCON1,   TOCON1,       0,   WILDBOAR,   CROSS,    CROSS,  TOCON1,  DOWN1 },
      {  TOCON1, DARKELF,DARKELF,   SWORD,   SWORD,  TOCON1,     UP1,  TOCON1,    CROSS,    WILDBOAR,   STAFF,    UP1,   SWORD,    SWORD,  TOCON1,  DOWN1 },
      {  TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,     UP1,  LEFT1,   LEFT1,    SWORD,  LEFT1,   STAFF,  LEFT1,   LEFT1,  LEFT1,  LEFT1 }
   }
};



const LEVEL w0r12 =
{
   0,  0,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {        0,  TOCON1,      KEY,   WILDBOAR,   WILDBOAR,    WILDBOAR,       0,   WILDBOAR,        0,       0,       0,  LEFT1,  LEFT1,  LEFT1,   LEFT1,  LEFT1 },
      {    STAFF,       0,   TOCON1,  TOCON1,  TOCON1,    CROSS,   WILDBOAR,       0,    WILDBOAR,   STAFF,   STAFF,   STAFF,       0,       0,        0,      UP1 },
      {   TOCON1,       0,        0,   WILDBOAR,       0,   TOCON1,  TOCON1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,  TOCON1,TOADSTOOL,       0 },
      {     DOOR,  TOCON1,        0,       0,       0,    WILDBOAR,   STAFF,   WILDBOAR,    WILDBOAR,   WILDBOAR,       0, RIGHT1, RIGHT1,  DOWN1,   TOCON1,       0 },
      { DARKELF,  TOCON1,   TOCON1,  TOCON1,   STAFF,    WILDBOAR,   STAFF,   WILDBOAR,   TOCON1,   WILDBOAR,   WILDBOAR,    UP1,  LEFT1,  DOWN1,   TOCON1,       0 },
      {TOADSTOOL,DARKELF,TOADSTOOL,DARKELF,  TOCON1,TOADSTOOL,   STAFF,  TOCON1,    SWORD,  TOCON1,   SWORD,   WILDBOAR,       0,  LEFT1,   TOCON1,       0 },
      {   TOCON1,  TOCON1,   TOCON1,       0,       0,   TOCON1,       0,  TOCON1,TOADSTOOL,   STAFF,  TOCON1,  TOCON1,       0,  TOCON1,        0,       0 },
      {    SWORD,   CROSS,    SWORD,   CROSS,       0,        0,  TOCON1,   WILDBOAR,        0,  TOCON1,   CROSS,DARKELF,       0,DARKELF,        0,       0 },
      {   TOCON1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,        0,  TOCON1,       0,   TOCON1,       0,  TOCON1,  TOCON1,       0,  TOCON1,   TOCON1,  TOCON1 },
      {    STAFF,       0,   LEFT1,  LEFT1,  LEFT1,        0,  TOCON1,       0,        0,       0,       0,       0,       0,  TOCON1,   DOWN1,   SWORD },
      {  RIGHT1, RIGHT1,    SWORD, RIGHT1, RIGHT1,        0,       0,       0,        0,       0,       0,       0,       0,       0,  RIGHT1,      UP1 }
   }
};







const LEVEL w0r13 =
{
//    // Aquú muestra todos los elementos de la lista de abajo. Está bien para saber sus nombres a la hora de distribuirlos por los niveles
//   3, 4,
//   (Image *) &w0_marco_1,
//   (struct genresSprites *) NULL,
//   (struct genresSprites *) NULL,
//   (struct genresSprites *) NULL,
//   {
//      {  TOMB1,   TOCON1,   MATOJOS,    ZARZA,   PIEDRA1,  SETA_2,   CANDLE,BIGTREE1_U,   TOCON1,   TOCON1,     TOCON1,    DOWN1,   TOCON1,  TOCON1,  ABBAYE_U, TOCON1 },
//      {       0,    SWORD,  DARKELF,    SWORD,  DARKELF,    SWORD,  DARKELF,     SWORD,  DARKELF,    SWORD,    DARKELF,    SWORD,  DARKELF,   SWORD,  ABBAYE_D, TOCON1 },
//      {       0,    STAFF, WILDBOAR,    STAFF, WILDBOAR,        0,        0,         0,        0,        0,          0,    STAFF, WILDBOAR,   STAFF,  WILDBOAR, RIGHT1 },
//      {   SWORD,        0,        0,        0,        0,        0,        0,BIGTREE1_U,        0, ABBAYE_U,          0,        0,        0,       0,         0,      0 },
//      {   SWORD,     FIRE,        0,        0,        0,        0,        0,BIGTREE1_D,        0, ABBAYE_D,          0,        0,        0,       0,         0,      0 },
//      { DARKELF,        0,        0,        0,        0,        0,        0,         0,        0,        0,      LEFT1,    LEFT1,        0,       0,         0,      0 },
//      {       0,        0,        0,      KEY,     DOOR,    DOWN1,   TOCON1,       UP1,   TOCON1,    DOWN1,     TOCON1,      UP1,   TOCON1,  TOCON1,  ABBAYE_U, TOCON1 },
//      {       0,   TOCON1,        0,        0,        0,    DOWN1,   TOCON1,       UP1,    LEFT1,    LEFT1,     TOCON1,      UP1,   TOCON1,  TOCON1,  ABBAYE_U, TOCON1 },
//      {       0,   TOCON1,   TOCON1,   TOCON1,   TOCON1,   RIGHT1,    DOWN1,    TOCON1,   TOCON1,   TOCON1,     RIGHT1,      UP1,   TOCON1,  TOCON1,  ABBAYE_U, TOCON1 },
//      {       0,  DARKELF,        0,        0,        0,   TOCON1,   RIGHT1,    RIGHT1,   RIGHT1,   RIGHT1,        UP1,   TOCON1,  DARKELF, DARKELF,  ABBAYE_U, TOCON1 },
//      {       0,   TOCON1,   TOCON1,   TOCON1,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,   TOCON1,     TOCON1,   TOCON1,   TOCON1,  TOCON1,  ABBAYE_D, TOCON1 }
//   }

//TOMB1,
//TOCON1,
//MATOJOS,
//ZARZA,
//PIEDRA1,
//SETA_2,
//CANDLE,
//FIRE,
//ABBAYE_U,
//ABBAYE_D,
//BIGTREE1_U,
//BIGTREE1_D,
//LAKE1,



   7, 9,
   (Image *) &w0_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,    BLOCK,     BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,MONEDON_DOOR,  BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,        0,     BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,        0,        0,         0,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,        0,        0,         0,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 }


//      {       0,       0,        0,  RIGHT1,  RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,  RIGHT1,   RIGHT1,     RIGHT1,     RIGHT1,    DOWN1,        0,        0,        0 },
//      {       0,       0,   RIGHT1,     UP1,       0,        0,        0,        0,       0,        0,          0,          0,   RIGHT1,    DOWN1,        0,        0 },
//      {       0,  RIGHT1,      UP1,       0,  RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,  RIGHT1,   RIGHT1,     RIGHT1,      DOWN1,        0,   RIGHT1,    DOWN1,        0 },
//      {  RIGHT1,     UP1,        0,  RIGHT1,     UP1,        0,        0,        0,       0,        0,          0,     RIGHT1,    DOWN1,        0,   RIGHT1,    DOWN1 },
//      {     UP1,       0,   RIGHT1,     UP1,       0,        0,        0,        0,       0,        0,          0,          0,   RIGHT1,    DOWN1,        0,    DOWN1 },
//      {     UP1,       0,      UP1,       0,  RIGHT1,        0,        0,        0,       0,MONEDON_DOOR,       0,          0,        0,    DOWN1,        0,    DOWN1 },
//      {     UP1,       0,      UP1,       0,     UP1,        0,        0,        0,       0,        0,          0,          0,        0,    DOWN1,        0,    DOWN1 },
//      {     UP1,       0,      UP1,       0,     UP1,    LEFT1,        0,        0,       0,        0,          0,          0,    DOWN1,    LEFT1,        0,    DOWN1 },
//      {     UP1,       0,      UP1,   LEFT1,       0,      UP1,    LEFT1,    LEFT1,   LEFT1,    LEFT1,      LEFT1,      LEFT1,    LEFT1,        0,    DOWN1,    LEFT1 },
//      {       0,       0,        0,     UP1,   LEFT1,        0,        0,        0,       0,        0,          0,          0,        0,    DOWN1,    LEFT1,        0 },
//      {       0,       0,        0,       0,     UP1,    LEFT1,    LEFT1,    LEFT1,   LEFT1,    LEFT1,      LEFT1,      LEFT1,    LEFT1,    LEFT1,        0,        0 }



//      {       0,       0,   TOCON1,  RIGHT1,  RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,  RIGHT1,   RIGHT1,     RIGHT1,     RIGHT1,    DOWN1,   TOCON1,        0,        0 },
//      {       0,  TOCON1,   RIGHT1,     UP1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   RIGHT1,    DOWN1,   TOCON1,        0 },
//      {  TOCON1,  RIGHT1,      UP1,  TOCON1,  RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,  RIGHT1,   RIGHT1,     RIGHT1,      DOWN1,   TOCON1,   RIGHT1,    DOWN1,   TOCON1 },
//      {  RIGHT1,     UP1,   TOCON1,  RIGHT1,     UP1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     RIGHT1,    DOWN1,   TOCON1,   RIGHT1,    DOWN1 },
//      {     UP1,  TOCON1,   RIGHT1,     UP1,  TOCON1,        0,        0,        0,       0,        0,          0,     TOCON1,   RIGHT1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,  RIGHT1,        0,        0,        0,       0,MONEDON_DOOR,       0,          0,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,     UP1,   TOCON1,        0,        0,       0,        0,          0,          0,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,     UP1,    LEFT1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,    DOWN1,    LEFT1,   TOCON1,    DOWN1 },
//      {       0,  TOCON1,      UP1,   LEFT1,  TOCON1,      UP1,    LEFT1,    LEFT1,   LEFT1,    LEFT1,      LEFT1,      LEFT1,    LEFT1,   TOCON1,    DOWN1,    LEFT1 },
//      {       0,       0,   TOCON1,     UP1,   LEFT1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,    DOWN1,    LEFT1,   TOCON1 },
//      {       0,       0,        0,  TOCON1,     UP1,    LEFT1,    LEFT1,    LEFT1,   LEFT1,    LEFT1,      LEFT1,      LEFT1,    LEFT1,    LEFT1,   TOCON1,        0 }


//      {       0,       0,   TOCON1,  RIGHT1,       0,        0,        0,        0,       0,        0,          0,          0,    DOWN1,   TOCON1,        0,        0 },
//      {       0,  TOCON1,   RIGHT1,     UP1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   RIGHT1,    DOWN1,   TOCON1,        0 },
//      {  TOCON1,  RIGHT1,      UP1,  TOCON1,  RIGHT1,        0,        0,        0,       0,        0,          0,      DOWN1,   TOCON1,   RIGHT1,    DOWN1,   TOCON1 },
//      {  RIGHT1,     UP1,   TOCON1,  RIGHT1,     UP1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     RIGHT1,    DOWN1,   TOCON1,   RIGHT1,    DOWN1 },
//      {       0,  TOCON1,   RIGHT1,     UP1,  TOCON1,        0,        0,        0,       0,        0,          0,     TOCON1,   RIGHT1,    DOWN1,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,  RIGHT1,        0,        0,        0,       0,MONEDON_DOOR,       0,          0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,   TOCON1,        0,        0,       0,        0,          0,          0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,     UP1,    LEFT1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,    DOWN1,    LEFT1,   TOCON1,        0 },
//      {       0,  TOCON1,      UP1,   LEFT1,  TOCON1,      UP1,        0,        0,       0,        0,          0,          0,    LEFT1,   TOCON1,    DOWN1,    LEFT1 },
//      {       0,       0,   TOCON1,     UP1,   LEFT1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,    DOWN1,    LEFT1,   TOCON1 },
//      {       0,       0,        0,  TOCON1,     UP1,        0,        0,        0,       0,        0,          0,          0,        0,    LEFT1,   TOCON1,        0 }


//      {       0,       0,   TOCON1,       0,       0,        0,        0,        0,         0,        0,      STAFF,   WILDBOAR,        0,   TOCON1,        0,        0 },
//      {       0,  TOCON1,        0,       0,  TOCON1,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,     TOCON1,        0,        0,   TOCON1,        0 },
//      {  TOCON1,       0,        0,  TOCON1,       0,        0,        0,        0,         0,        0,          0,          0,   TOCON1,        0,        0,   TOCON1 },
//      {       0,       0,   TOCON1,       0,       0,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,          0,        0,   TOCON1,        0,        0 },
//      {       0,  TOCON1,        0,       0,  TOCON1,        0,        0,        0,         0,        0,          0,     TOCON1,        0,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,  DARKELF,   TOCON1,        0,         0,MONEDON_DOOR,       0,          0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,   TOCON1,        0,        0,         0,        0,          0,     TOCON1,        0,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,        0,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,          0,        0,   TOCON1,        0,        0 },
//      {       0,  TOCON1,TOADSTOOL,       0,  TOCON1,        0,        0,    SWORD,         0,        0,          0,          0,   TOCON1,        0,        0,   TOCON1 },
//      {       0,       0,   TOCON1,       0,       0,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,     TOCON1,        0,        0,   TOCON1,        0 },
//      {       0,       0,        0,  TOCON1,       0,        0,        0,        0,         0,        0,          0,          0,    CROSS,   TOCON1,        0,        0 }



//      {       0,       0,   TOCON1,       0,       0,        0,        0,        0,         0,        0,      STAFF,   WILDBOAR,        0,   TOCON1,        0,        0 },
//      {       0,  TOCON1,        0,       0,  TOCON1,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,     TOCON1,        0,        0,   TOCON1,        0 },
//      {  TOCON1,       0,        0,  TOCON1,       0,        0,        0,        0,         0,        0,          0,          0,   TOCON1,        0,        0,   TOCON1 },
//      {       0,       0,   TOCON1,       0,       0,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,          0,        0,   TOCON1,        0,        0 },
//      {       0,  TOCON1,        0,       0,  TOCON1,        0,        0,    SWORD,   DARKELF,        0,          0,     TOCON1,        0,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,        0,   TOCON1,   TOCON1,         0,MONEDON_DOOR,       0,          0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,   TOCON1,        0,        0,         0,        0,          0,     TOCON1,        0,        0,   TOCON1,        0 },
//      {       0,  TOCON1,TOADSTOOL,  TOCON1,       0,        0,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,          0,        0,   TOCON1,        0,        0 },
//      {       0,  TOCON1,    CROSS,       0,  TOCON1,        0,        0,        0,         0,        0,          0,          0,   TOCON1,        0,        0,   TOCON1 },
//      {       0,       0,   TOCON1,       0,       0,   TOCON1,   TOCON1,   TOCON1,    TOCON1,   TOCON1,     TOCON1,     TOCON1,        0,        0,   TOCON1,        0 },
//      {       0,       0,        0,  TOCON1,       0,        0,        0,        0,         0,        0,          0,          0,        0,   TOCON1,        0,        0 }

//      {       0,       0,        0,       0,       0,        0,        0,        0,       0,        0,          0,          0,        0,        0,        0,        0 },
//      {       0,  TOCON1,   TOCON1,  TOCON1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,   TOCON1,   TOCON1,        0 },
//      {       0,  TOCON1,        0,       0,       0,        0,        0,        0,       0,        0,          0,          0,        0,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,        0,        0,        0,       0,        0,          0,          0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,   TOCON1,   TOCON1,        0,       0,        0,MONEDON_DOOR,         0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,   TOCON1,        0,        0,       0,        0,          0,          0,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,       0,        0,        0,        0,       0,        0,          0,          0,        0,        0,   TOCON1,        0 },
//      {       0,  TOCON1,        0,  TOCON1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,   TOCON1,   TOCON1,        0 },
//      {       0,  TOCON1,        0,       0,       0,        0,        0,        0,       0,        0,          0,          0,        0,        0,        0,        0 }



//      {  RIGHT1,  RIGHT1,   RIGHT1,  RIGHT1,  RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,  RIGHT1,   RIGHT1,     RIGHT1,     RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,    DOWN1 },
//      {     UP1,  TOCON1,   TOCON1,  TOCON1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,   TOCON1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,   RIGHT1,  RIGHT1,  RIGHT1,   RIGHT1,   RIGHT1,   RIGHT1,  RIGHT1,   RIGHT1,     RIGHT1,     RIGHT1,   RIGHT1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,  RIGHT1,   RIGHT1,        0,        0,       0,        0,          0,          0,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,     UP1,   TOCON1,   TOCON1,        0,       0,        0,MONEDON_DOOR,         0,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,     UP1,   TOCON1,        0,        0,       0,        0,          0,          0,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,     UP1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,    DOWN1,   TOCON1,    DOWN1 },
//      {     UP1,  TOCON1,      UP1,  TOCON1,     UP1,    LEFT1,    LEFT1,    LEFT1,   LEFT1,    LEFT1,      LEFT1,      LEFT1,    LEFT1,    LEFT1,   TOCON1,    DOWN1 },
//      {       0,  TOCON1,      UP1,  TOCON1,  TOCON1,   TOCON1,   TOCON1,   TOCON1,  TOCON1,   TOCON1,     TOCON1,     TOCON1,   TOCON1,   TOCON1,   TOCON1,    DOWN1 },
//      {       0,  TOCON1,      UP1,   LEFT1,   LEFT1,    LEFT1,    LEFT1,    LEFT1,   LEFT1,    LEFT1,      LEFT1,      LEFT1,    LEFT1,    LEFT1,    LEFT1,    LEFT1 }


//      {       0,   TOCON1,  TOCON1,        0,       0,       0,   TOCON1,        0,       0,        0,     TOCON1,        0,        0,   TOCON1,        0,        0 },
//      {       0,   TOCON1,       0,   TOCON1,       0,  TOCON1,        0,   TOCON1,       0,   TOCON1,          0,        0,   TOCON1,        0,        0,        0 },
//      {       0,   TOCON1,       0,   TOCON1,       0,  TOCON1,        0,   TOCON1,       0,   TOCON1,          0,        0,   TOCON1,        0,        0,        0 },
//      {       0,   TOCON1,  TOCON1,        0,       0,  TOCON1,        0,   TOCON1,       0,        0,     TOCON1,        0,        0,   TOCON1,        0,        0 },
//      {       0,   TOCON1,       0,   TOCON1,       0,  TOCON1,        0,   TOCON1,       0,        0,     TOCON1,        0,        0,   TOCON1,        0,        0 },
//      {       0,   TOCON1,       0,   TOCON1,       0,  TOCON1,        0,   TOCON1,       0,        0,     TOCON1,        0,        0,   TOCON1,        0,        0 },
//      {       0,   TOCON1,  TOCON1,        0,       0,       0,   TOCON1,        0,       0,   TOCON1,          0,        0,   TOCON1,        0,        0,        0 },
//      {       0,        0,       0,        0,       0,       0,        0,        0,       0,        0,          0,        0,        0,        0,        0,        0 },
//      {    LAKE1,    LAKE2,       0,        0,       0,       0,        0,        0,       0,        0,          0,        0,        0,        0,        0,        0 },
//      {    LAKE3,    LAKE4,       0,        0,       0,       0,      KEY,     DOOR,       0,        0,          0,        0,        0,        0,        0,        0 }
   }
};
