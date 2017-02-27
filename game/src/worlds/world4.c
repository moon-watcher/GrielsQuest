#include "../inc/include.h"

const LEVEL w4r00 =
{
   3, 9,
   (Image *) &w4_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,     0,     0,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,       0 },
      {       0,BARREL,   KEY,  OGRE,  OGRE, STAFF,BARREL,     0,     0,BARREL, SWORD, SWORD, CROSS, STAFF,BARREL,       0 },
      {       0,BARREL,  OGRE,  OGRE,  OGRE,  OGRE,  OGRE,BARREL,BARREL,     0, SWORD, CROSS, SWORD, SWORD,BARREL,       0 },
      {       0,BARREL, CROSS,  OGRE, SWORD,  OGRE, CROSS, DEMON, DEMON, CROSS, SWORD, SWORD, SWORD, SWORD,BARREL,       0 },
      {       0,BARREL,BARREL,BARREL,BARREL,BARREL,  OGRE, DEMON, DEMON,  OGRE,BARREL,BARREL,BARREL,BARREL,BARREL,       0 },
      {       0,     0,     0,     0,     0,     0,BARREL, SWORD, SWORD,BARREL,     0,     0,     0,     0,     0,       0 },
      {       0,BARREL,BARREL,BARREL,BARREL,BARREL,  OGRE,   EYE,  OGRE,  OGRE,BARREL,BARREL,BARREL,BARREL,BARREL,       0 },
      {       0,BARREL, STAFF, CROSS,  OGRE, DEMON,   EYE,   EYE,   EYE, SWORD,   EYE, DEMON,  OGRE, STAFF,BARREL,       0 },
      {       0,BARREL, SWORD, CROSS,     0,     0, STAFF,BARREL,BARREL,  OGRE, DEMON,   EYE, DEMON,  OGRE,BARREL,       0 },
      {       0,BARREL, CROSS,     0,     0, STAFF,BARREL,     0,     0,BARREL,  OGRE,  OGRE,  OGRE,  DOOR,BARREL,       0 },
      {       0,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,     0,     0,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,       0 }
   }

};


const LEVEL w4r01 =
{
   4, 0,
   (Image *) &w4_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    OGRE,   STAFF,   OGRE,   STAFF,       0, BAFFLE,     KEY,   DEMON,   OGRE,     0, RIGHT5,       0,    OGRE,   CROSS,   STAFF,   OGRE },
      {    OGRE,    OGRE,   OGRE,    OGRE,   STAFF, BAFFLE,   DEMON,   STAFF,   OGRE, STAFF, BAFFLE,    OGRE,     EYE,   STAFF,   SWORD,   OGRE },
      {    OGRE,    OGRE,   OGRE,    OGRE,    OGRE, BAFFLE,   DEMON,    OGRE,  DEMON, SWORD, BAFFLE,   CROSS,     EYE,    OGRE,     EYE,  DEMON },
      {   SWORD,    OGRE,  STAFF,    OGRE,    OGRE, BAFFLE,   SWORD,   DEMON,  SWORD,  OGRE, BAFFLE,   SWORD,    OGRE,     EYE,   CROSS,   OGRE },
      {       0,   STAFF,   OGRE,    OGRE,   STAFF, BAFFLE,   DEMON,   SWORD,  DEMON,     0, BAFFLE,   DEMON,    OGRE,   STAFF,    OGRE,      0 },
      {   DOWN5,  BAFFLE, BAFFLE,  BAFFLE,  BAFFLE, BAFFLE,  BAFFLE,  BAFFLE, BAFFLE,   UP5, BAFFLE,  BAFFLE,  BAFFLE,  BAFFLE,  BAFFLE,  DOWN5 },
      {       0,   DEMON,  SWORD,   DEMON,   SWORD, BAFFLE,     EYE,   STAFF,    EYE,   EYE, BAFFLE,   CROSS,   DEMON,   SWORD,    OGRE,      0 },
      {    OGRE,   SWORD,  DEMON,   SWORD,   STAFF, BAFFLE,     EYE,    OGRE,  CROSS,   EYE, BAFFLE,    OGRE,   SWORD,   DEMON,     EYE,  DEMON },
      {   STAFF,    OGRE,  SWORD,   DEMON,   SWORD, BAFFLE,   CROSS,     EYE,    EYE, SWORD, BAFFLE,   STAFF,    OGRE,    OGRE,   CROSS,  STAFF },
      {    OGRE,   CROSS,   OGRE,   SWORD,   STAFF, BAFFLE,    OGRE,     EYE,  CROSS,   EYE, BAFFLE,     EYE,     EYE,    OGRE,    OGRE,    EYE },
      {   SWORD,    OGRE,  STAFF,    OGRE,   SWORD, RIGHT5,       0,     EYE,  STAFF,   EYE, BAFFLE,    DOOR,     EYE,    OGRE,   DEMON,  DEMON }
   }
};


const LEVEL w4r02 =
{
   14,  5,
   (Image *) &w4_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    STAFF,   EYE,        0,        0,        0,   OGRE,        0,   OGRE,    CROSS,    TORCH5,        0,    TORCH5,        0,   OGRE,    STAFF,    TORCH5 },
      {    TORCH5,   OGRE,    TORCH5,   OGRE,    TORCH5,    DEMON,    TORCH5,    TORCH5,   OGRE,        0,        0,        0,        0,    TORCH5,        0,        0 },
      {    TORCH5,    SWORD,    TORCH5,        0,    STAFF,        0,    STAFF,   OGRE,    LEFT5,    TORCH5,   OGRE,    TORCH5,    TORCH5,    TORCH5,   OGRE,    STAFF },
      {    DEMON,    DEMON,        0,        0,        0,        0,        0,        0,    LEFT5,    SWORD,    STAFF,    TORCH5,        0,    SWORD,    DEMON,    DEMON },
      {    CROSS,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    DOWN5,      UP5,    LEFT5,   RIGHT5 },
      {     DOOR,      KEY,        0,   EYE,        0,   EYE,   EYE,        0,    SWORD,    STAFF,   EYE,    CROSS,        0,    SWORD,        0,    SWORD },
      {    CROSS,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,   OGRE,    TORCH5,    TORCH5,    DOWN5,    DOWN5,    LEFT5,      UP5 },
      {    DEMON,        0,        0,        0,        0,        0,        0,        0,    LEFT5,        0,    STAFF,    TORCH5,    CROSS,    SWORD,    DEMON,   OGRE },
      {    STAFF,    TORCH5,        0,        0,        0,        0,        0,   OGRE,    LEFT5,    TORCH5,    DEMON,    TORCH5,    TORCH5,    TORCH5,   OGRE,        0 },
      {   OGRE,    TORCH5,    TORCH5,   OGRE,    TORCH5,    DEMON,    TORCH5,    TORCH5,   OGRE,        0,        0,        0,        0,    TORCH5,        0,    CROSS },
      {    STAFF,        0,        0,        0,        0,   OGRE,    STAFF,   OGRE,    STAFF,    TORCH5,    SWORD,    SWORD,    STAFF,   EYE,        0,    TORCH5 }
   }
};


const LEVEL w4r03 =
{
   7,  6,
   (Image *) &w4_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    TORCH5,   SWORD,   DEMON,   SWORD,   DEMON,   DEMON,    DEMON,    DEMON,    DEMON,   SWORD,   OGRE,   STAFF,    TORCH5,    TORCH5,    TORCH5,    TORCH5 },
      {    TORCH5,   DEMON,     EYE,   CROSS,   DEMON,   STAFF,   TORCH5,     OGRE,    TORCH5,    TORCH5,   SWORD,   SWORD,   EYE,   OGRE,   STAFF,    TORCH5 },
      {    TORCH5,   STAFF,    OGRE,   STAFF,   DEMON,  TORCH5,    SWORD,    DEMON,    DEMON,    TORCH5,   SWORD,    DEMON,   STAFF,   CROSS,   OGRE,    TORCH5 },
      {    TORCH5,    OGRE,    OGRE,  TORCH5,  TORCH5,   SWORD,    DEMON,    DEMON,    DEMON,   SWORD,    TORCH5,   STAFF,   EYE,    DEMON,   SWORD,    TORCH5 },
      {    TORCH5,    OGRE,  TORCH5,   STAFF,   DEMON,   CROSS,      EYE,    DEMON,   OGRE,   STAFF,    TORCH5,   CROSS,    DEMON,    DEMON,   OGRE,    TORCH5 },
      {    TORCH5,   STAFF,    OGRE,  TORCH5,       0,     EYE,      EYE,    SWORD,   OGRE,   EYE,    TORCH5,   OGRE,   EYE,   EYE,   SWORD,    TORCH5 },
      {    TORCH5,  TORCH5,    OGRE,  TORCH5,   SWORD,  TORCH5,    CROSS,        0,   STAFF,    TORCH5,     KEY,    DEMON,   STAFF,   OGRE,   EYE,    TORCH5 },
      {    TORCH5,  TORCH5,    OGRE,  TORCH5,  TORCH5,  TORCH5,   TORCH5,   TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5 },
      {    TORCH5,   SWORD,   DEMON,   STAFF,   SWORD,     EYE,    SWORD,      EYE,    DEMON,    DEMON,   EYE,   SWORD,   EYE,   OGRE,   EYE,    TORCH5 },
      {    TORCH5,   DEMON,   CROSS,     EYE,   DEMON,    OGRE,    DEMON,    DEMON,   SWORD,   STAFF,    DEMON,   CROSS,    DEMON,   OGRE,   OGRE,    TORCH5 },
      {    TORCH5,   SWORD,   DEMON,   STAFF,    OGRE,     EYE,     OGRE,    CROSS,   EYE,    DEMON,   SWORD,   EYE,   EYE,   OGRE,    DOOR,    TORCH5 }
   }
};


const LEVEL w4r04 =
{
   8, 6,
   (Image *) &w4_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    DOOR,   OGRE,   CROSS,    LEFT5,   CROSS,       0,    DEMON,    DEMON,   STAFF,   CROSS,       0,       0,       0,       0,       0,       0 },
      {   OGRE,BARREL,      UP5,BARREL,BARREL,    DOWN5,BARREL,BARREL,BARREL,BARREL,      UP5,BARREL,BARREL,      UP5,BARREL,       0 },
      {   EYE,    LEFT5,   OGRE,   SWORD,   OGRE,       0,   CROSS,   OGRE,   STAFF,   CROSS,    DEMON,   OGRE,   SWORD,   EYE,    LEFT5,       0 },
      {   EYE,BARREL,BARREL,   EYE,BARREL,    DOWN5,BARREL,BARREL,    DOWN5,BARREL,BARREL,      UP5,BARREL,      UP5,BARREL,       0 },
      {       0,       0,   EYE,   SWORD,       0,   CROSS,   OGRE,   SWORD,       0,    DEMON,   STAFF,   EYE,   STAFF,   OGRE,    LEFT5,       0 },
      {      UP5,BARREL,BARREL,BARREL,    DOWN5,BARREL,      UP5,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,      UP5 },
      {       0,   CROSS,    DEMON,   STAFF,    DEMON,   STAFF,       0,       0,       0,       0,       0,   OGRE,   SWORD,   EYE,   RIGHT5,       0 },
      {       0,BARREL,    DOWN5,BARREL,BARREL,BARREL,    DOWN5,BARREL,BARREL,BARREL,    DOWN5,BARREL,BARREL,BARREL,BARREL,       0 },
      {       0,    LEFT5,   EYE,   SWORD,     KEY,   OGRE,   STAFF,   OGRE,       0,   OGRE,   CROSS,   OGRE,   SWORD,    DEMON,   RIGHT5,       0 },
      {       0, BARREL,BARREL,BARREL,    DOWN5,BARREL,BARREL,BARREL,     UP5,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


//const LEVEL w4r05 =
//{
//   0, 2,
//   (Image *) &w4_marco_1,
//   (struct genresSprites *) &w2s_line_down,
//   (struct genresSprites *) NULL,
//   (struct genresSprites *) NULL,
//   {
//      {       0,       0,       0,       0,       0,       0,BARREL,BARREL,BARREL,BARREL,BARREL,       0,    TORCH5,    TORCH5,       0,    TORCH5 },
//      {       0,    TORCH5,    TORCH5,    TORCH5,       0,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,       0,    TORCH5,    TORCH5,       0 },
//      {       0,    TORCH5,    TORCH5,    TORCH5,       0,BARREL,       0,       0,BARREL,BARREL,BARREL,BARREL,       0,    TORCH5,    TORCH5,    TORCH5 },
//      {    TORCH5,    TORCH5,    TORCH5,    TORCH5,       0,BARREL,       0,       0,BARREL,       0,       0,BARREL,       0,    TORCH5,    TORCH5,    TORCH5 },
//      {       0,       0,       0,       0,       0,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,BARREL,       0,    TORCH5,    TORCH5,    TORCH5 },
//      {       0,    TORCH5,    TORCH5,    TORCH5,    TORCH5,       0,BARREL,BARREL,BARREL,BARREL,BARREL,       0,    TORCH5,       0,    TORCH5,    TORCH5 },
//      {       0,    TORCH5,       0,       0,       0,    TORCH5,BARREL,       0,BARREL,       0,BARREL,       0,    TORCH5,    TORCH5,    TORCH5,    TORCH5 },
//      {       0,    TORCH5,       0,    TORCH5,       0,    TORCH5,       0,       0,   GRIAL,       0,       0,    TORCH5,    TORCH5,    TORCH5,    TORCH5,       0 },
//      {       0,    TORCH5,       0,    TORCH5,       0,    TORCH5,       0,       0,       0,       0,       0,    TORCH5,    TORCH5,    TORCH5,    TORCH5,       0 },
//      {       0,    TORCH5,       0,    TORCH5,       0,ABBAYE_U,       0,       0,       0,       0,       0,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5 },
//      {       0,       0,       0,    TORCH5,       0,ABBAYE_D,    TORCH5,    TORCH5,    TORCH5,    TORCH5,    TORCH5,       0,    TORCH5,    TORCH5,    TORCH5,    TORCH5 },
//   }
//};


const LEVEL w4r05 =
{
   7, 9,
   (Image *) &w4_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
//GUITAR1,  GUITAR2, BARREL,
//TORCH5,     ABBAYE_D_5,  PENTACLE,    BAFFLE,   MEGADRIVE, BEER,       SOFA1,   SOFA2,    MURCIANO,

//      {       0,        0,       0,   BARREL,       0,   DEMON,   BARREL,         0,         0,        0, PENTACLE, PENTACLE,    DEMON,        0,        0,       0 },
//      {MURCIANO1,MURCIANO2,      0,        0,       0,  BARREL,   BARREL,         0,ABBAYE_U_5,        0, PENTACLE,        0,    SOFA1,    SOFA2,        0,       0 },
//      {MURCIANO3,MURCIANO4,      0,        0,       0,  BARREL,   BARREL,         0,ABBAYE_D_5,        0,        0,   BAFFLE,        0,        0,        0,       0 },
//      {       0,        0,       0,        0,   SWORD,       0,        0,         0,         0,        0,        0,   BAFFLE,        0,        0,        0,       0 },
//      {       0,        0,       0,        0,       0,       0,        0,KBRAH_DOOR,         0,        0,        0,   BAFFLE,        0,     OGRE,     BEER,       0 },
//      {       0,  GUITAR1, GUITAR1,        0,     UP5,     UP5,        0,    RIGHT5,ABBAYE_U_5,        0,        0,        0,        0,     BEER,     OGRE,    BEER },
//      {       0,  GUITAR2, GUITAR2,        0,       0,       0,        0,    RIGHT5,ABBAYE_D_5,        0,        0,        0,        0,     BEER,        0,       0 },
//      {       0,        0,       0,    LEFT5,       0,       0,        0,    RIGHT5,         0,        0,        0,        0,        0,        0,        0,       0 },
//      {       0,        0,       0,    LEFT5,       0,       0,        0,         0,         0,   TORCH5,   TORCH5,        0,        0,        0,        0,       0 },
//      {       0,        0,       0,    LEFT5,       0,   DOWN5,    DOWN5,       EYE,    TORCH5,      EYE,        0,MEGADRIVE,MEGADRIVE,MEGADRIVE,        0,       0 },
//      {       0,        0,       0,        0,       0,       0,        0,         0,    TORCH5,        0,        0,        0,        0,        0,        0,       0 }


      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,    BLOCK,     BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,MONEDON_DOOR,  BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,        0,     BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,    BLOCK,        0,     BLOCK,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,   BLOCK,    BLOCK,        0,        0,         0,    BLOCK,      BLOCK,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 },
      {       0,       0,        0,       0,       0,        0,        0,        0,         0,        0,          0,          0,        0,        0,        0,        0 }
   }
};

