#include "../inc/include.h"

const LEVEL w1r00 =
{
   13,  5,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {   TREE2,   TOMB2,  TREE22,   ROCK2, ICEBLOCK,STALAGMITE, SNOWMAN,  SKULL,       0,       0,   0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK },
      {  ICEBLOCK,       0,    DOOR,  ICEBLOCK,    STAFF,   ICEBLOCK,       0,       0,       0,       0,   ICEBLOCK,   CROSS,       0,       0,  0,   ICEBLOCK },
      {  ICEBLOCK,       0,   WILDBOAR,  ICEBLOCK,TOADSTOOL,   ICEBLOCK,       0,       0,       0,       0,   ICEBLOCK,   WILDBOAR,       0,       0,  0, ICEBLOCK },
      {       0,  TOMB2,       0,  ICEBLOCK,        0,   ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,   ICEBLOCK,       0,  ICEBLOCK,   STAFF,  ICEBLOCK, 0 },
      {       0,  TOMB2,       0,       0,        0,TOADSTOOL,       0,       0,       0,  ICEBLOCK,TOADSTOOL,   WILDBOAR,       0,       0,  ICEBLOCK,       0 },
      {       0,  TOMB2,       0,       0,        0,   ICEBLOCK,     KEY,       0,       0,       0,        0,  ICEBLOCK,       0,       0,  ICEBLOCK,  0 },
      {       0,  TOMB2,DARKELF,DARKELF, DARKELF,        0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,TOADSTOOL,       0,   WILDBOAR,       0,  ICEBLOCK, 0   },
      { CANDLE2,       0,       0,       0,        0,   ICEBLOCK,       0,       0,       0,DARKELF,        0,  ICEBLOCK,       0,       0,  0,     ICEBLOCK },
      { IGLU1,   IGLU2,   SWORD,       0,        0, DARKELF,   SWORD,   WILDBOAR,       0,  ICEBLOCK,    CROSS,   WILDBOAR,       0,   SWORD,  0,  ICEBLOCK },
      { IGLU3,   IGLU4,      FISH21, CANDLE2,        0,   TREE2,  TREE2,  TREE2,  TREE2,  ICEBLOCK,   ICEBLOCK,  ICEBLOCK,   0,      0,   ABBAYE_U_2, 0  },
      { ICEBLOCK,  SNOWMAN,  FISH22,  SKULL,   SNOWMAN,         0,       0,       0,       0,       0,        0,       0,  ICEBLOCK, ICEBLOCK,  ABBAYE_D_2,  ICEBLOCK}
   }
};


const LEVEL w1r01 =
{
   6, 5,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,          0,       0,       0,    SNOWMAN,    SNOWMAN,    SNOWMAN,    SNOWMAN,    SNOWMAN,       0,       0,       0,       0,  0,       0 },
      {       0,       0,          0,       0,    SNOWMAN,   WALRUS,   CROSS,    WAMPA,   WALRUS,   STAFF,    SNOWMAN,       0,       0,    0,    0,    0},
      {       0,       0,          0,    SNOWMAN,   STAFF,   ESKIMO,   WALRUS,   SWORD,   WALRUS,   ESKIMO,    WAMPA,    SNOWMAN,       0,       0,    0,       0 },
      {       0,       0,    SNOWMAN,    WAMPA,    WAMPA,   WALRUS,    SNOWMAN,    SNOWMAN,    SNOWMAN,   STAFF,    WAMPA,   STAFF,    SNOWMAN,       0,       0,       0 },
      {       0,       0,    SNOWMAN,    WAMPA,   STAFF,    SNOWMAN,   STAFF,   WALRUS,   SWORD,    SNOWMAN,   WALRUS,   ESKIMO,    SNOWMAN,       0,       0,       0 },
      {       0,       0,    SNOWMAN,     KEY,   ESKIMO,    SNOWMAN,       0,    DOOR,    WAMPA,   SWORD,    WAMPA,   WALRUS,    SNOWMAN,       0,       0,       0 },
      {       0,       0,    SNOWMAN,   ESKIMO,   SWORD,    SNOWMAN,   STAFF,   WALRUS,   CROSS,    SNOWMAN,   WALRUS,   SWORD,    SNOWMAN,       0,       0,       0 },
      {       0,       0,    SNOWMAN,   SWORD,   ESKIMO,    WAMPA,    SNOWMAN,    SNOWMAN,    SNOWMAN,   WALRUS,   CROSS,    WAMPA,    SNOWMAN,       0,       0,       0 },
      {       0,       0,       0,    SNOWMAN,   STAFF,   SWORD,   WALRUS,   ESKIMO,   WALRUS,   SWORD,   WALRUS,    SNOWMAN,       0,       0,    0,       0 },
      {       0,       0,       0,       0,    SNOWMAN,    WAMPA,   STAFF,    WAMPA,   CROSS,   ESKIMO,    SNOWMAN,       0,       0,    0,    0,    0 },
      {       0,       0,       0,       0,       0,    SNOWMAN,    SNOWMAN,    SNOWMAN,    SNOWMAN,    SNOWMAN,       0,       0,       0,       0,    0,       0 }
   }
};


const LEVEL w1r02 =
{
   7,  1,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,  ICEBLOCK,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,  ICEBLOCK,       0,  ICEBLOCK,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,  ICEBLOCK,   SWORD,   STAFF,   WALRUS,  ICEBLOCK,       0,       0,       0,       0,       0,       0 },
      {       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,   CROSS,   WALRUS,   ESKIMO,    WAMPA,   ESKIMO,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0,       0 },
      {       0,       0,  ICEBLOCK,   SWORD,   ESKIMO,    WAMPA,   STAFF,   WALRUS,   CROSS,   WALRUS,    WAMPA,   CROSS,  ICEBLOCK,       0,       0,       0 },
      {       0,       0,       0,  ICEBLOCK,   WALRUS,   CROSS,   WALRUS,   ESKIMO,   ESKIMO,   STAFF,   ESKIMO,  ICEBLOCK,       0,       0,       0,       0 },
      {       0,       0,       0,       0,  ICEBLOCK,   ESKIMO,   STAFF,   STAFF,   SWORD,   ESKIMO,  ICEBLOCK,       0,       0,       0,       0,       0 },
      {       0,       0,       0,  ICEBLOCK,   WALRUS,    WAMPA,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,   SWORD,    WAMPA,  ICEBLOCK,       0,       0,       0,       0 },
      {       0,       0,  ICEBLOCK,     KEY,   SWORD,  ICEBLOCK,       0,       0,       0,  ICEBLOCK,   ESKIMO,    DOOR,  ICEBLOCK,       0,       0,       0 },
      {       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0,       0,       0,       0,       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w1r03 =
{
   4, 10,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,     TREE2,     TREE2,   CROSS,   STAFF,   WALRUS,   SWORD,    WAMPA,     TREE2,     TREE2,       0,       0,       0 },
      {       0,       0,       0,     TREE2,    WAMPA,   WALRUS,   CROSS,   ESKIMO,   WALRUS,   WALRUS,    WAMPA,    WAMPA,   SWORD,     TREE2,       0,       0 },
      {       0,       0,     TREE2,    WAMPA,   ESKIMO,     TREE2,    WAMPA,   ESKIMO,   STAFF,   WALRUS,   WALRUS,   WALRUS,    WAMPA,   STAFF,     TREE2,       0 },
      {       0,       0,     TREE2,   ESKIMO,   ESKIMO,     TREE2,    WAMPA,   ESKIMO,   ESKIMO,   WALRUS,   WALRUS,   WALRUS,    WAMPA,   WALRUS,     TREE2,       0 },
      {       0,     TREE2,   ESKIMO,   ESKIMO,   ESKIMO,     TREE2,   ESKIMO,   ESKIMO,   ESKIMO,   WALRUS,   STAFF,    WAMPA,   CROSS,    WAMPA,   SWORD,     TREE2 },
      {       0,     TREE2,   WALRUS,   WALRUS,    WAMPA,   STAFF,     TREE2,     KEY,   WALRUS,   WALRUS,   WALRUS,   WALRUS,   WALRUS,   WALRUS,    WAMPA,     TREE2 },
      {       0,     TREE2,     TREE2,     TREE2,       0,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2 },
      {       0,       0,   CROSS,   CROSS,       0,   SWORD,   CROSS,   SWORD,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,   SWORD,     TREE2,       0,   STAFF,     TREE2,   SWORD,       0,       0,       0,       0,       0,       0,       0,    DOOR }
   }
};


const LEVEL w1r04 =
{
   15, 6,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    WAMPA,       0,       0,    WAMPA,       0,       0,       0,       0,    TREE2,       0,   STAFF,   WALRUS,   CROSS,   WALRUS,   SWORD,       0 },
      {       0,       0,       0,    TREE2,    WAMPA,    TREE2,    TREE2,    WAMPA,       0,       0,    TREE2,    TREE2,    TREE2,    DOWN2,       0,   WALRUS },
      {       0,       0,       0,       0,       0,    WAMPA,       0,       0,       0,    TREE2,       0,       0,       0,   SWORD,    TREE2,   SWORD },
      {       0,    TREE2,   RIGHT2,   RIGHT2,   RIGHT2,   RIGHT2,   RIGHT2,    TREE2,    TREE2,       0,       0,       0,    TREE2,   STAFF,    TREE2,   ESKIMO },
      {       0,    TREE2,      UP2,   RIGHT2,   RIGHT2,   RIGHT2,    WAMPA,   SWORD,   RIGHT2,   ESKIMO,       0,    WAMPA,    TREE2,   CROSS,    TREE2,    DOOR },
      {       0,    TREE2,      UP2,      UP2,       0,    TREE2,       0,    TREE2,       0,    TREE2,       0,    WAMPA,    TREE2,    DOWN2,    TREE2,    TREE2 },
      {       0,       0,       0,       0,    TREE2,   STAFF,       0,       0,       0,       0,    TREE2,       0,    LEFT2,       0,       0,       0 },
      {    TREE2,    TREE2,    TREE2,       0,   WALRUS,       0,       0,    WAMPA,       0,       0,       0,       0,    TREE2,      UP2,    TREE2,       0 },
      {       0,       0,       0,    WAMPA,    TREE2,       0,       0,       0,       0,       0,    TREE2,       0,       0,       0,    TREE2,       0 },
      {     KEY,    TREE2,      UP2,    TREE2,   SWORD,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,   STAFF,    TREE2,    TREE2,    TREE2,       0,       0 },
      {   WALRUS,       0,       0,       0,       0,   STAFF,       0,   WALRUS,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w1r05 =
{
   7, 0,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,   TREE2,   TREE2,   TREE2,   TREE2,       0,   TREE2,        0,       0,       0,       0,       0 },
      {       0,       0,       0,       0, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN,       0, SNOWMAN,  SNOWMAN,       0,       0,       0,       0 },
      {       0,       0,       0, SNOWMAN,  WALRUS,  WALRUS,   CROSS,  WALRUS,   CROSS,   STAFF,   SWORD,   WALRUS, SNOWMAN,       0,       0,       0 },
      {       0,       0, SNOWMAN,   STAFF,  ESKIMO,  WALRUS,   WAMPA,  WALRUS,  ESKIMO,  WALRUS,   WAMPA,    CROSS,  ESKIMO, SNOWMAN,       0,       0 },
      {       0,       0, SNOWMAN, SNOWMAN,   CROSS,  ESKIMO,   STAFF,  WALRUS,   STAFF,  ESKIMO,   STAFF,   ESKIMO, SNOWMAN, SNOWMAN,       0,       0 },
      {       0,       0,       0, SNOWMAN,  ESKIMO,   WAMPA,  WALRUS,  WALRUS,  ESKIMO,   WAMPA,  WALRUS,    CROSS, SNOWMAN,       0,       0,       0 },
      {       0,       0,       0, SNOWMAN,  WALRUS,   WAMPA,  ESKIMO,  ESKIMO,   WAMPA,   WAMPA,   WAMPA,   ESKIMO, SNOWMAN,       0,       0,       0 },
      {       0,       0,       0, SNOWMAN,     KEY,  ESKIMO,   CROSS,  WALRUS,   WAMPA,    DOOR,   WAMPA,   WALRUS, SNOWMAN,       0,       0,       0 },
      {       0,       0,       0, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN, SNOWMAN,  SNOWMAN, SNOWMAN,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,        0,       0,       0,       0,       0 }
   }
};



const LEVEL w1r06 =
{
   4, 4,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {   STAFF,   CROSS,   SWORD,   SWORD,   WALRUS,       0,       0,       0,    TREE2,   SWORD,   CROSS,   STAFF,   WALRUS,       0,   WALRUS,   CROSS },
      {    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,       0,    TREE2,       0,    TREE2,   ESKIMO,    TREE2,    TREE2,    TREE2,       0,    TREE2,    TREE2 },
      {   CROSS,   STAFF,   SWORD,   ESKIMO,       0,       0,    TREE2,       0,       0,   ESKIMO,       0,   STAFF,       0,       0,       0,    TREE2 },
      {    TREE2,    TREE2,    TREE2,    TREE2,       0,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,       0,    TREE2,    TREE2,       0,       0,    TREE2 },
      {   SWORD,   WALRUS,       0,       0,       0,       0,       0,       0,   RIGHT2,   STAFF,       0,       0,       0,       0,    TREE2,    DOOR },
      {    DOWN2,    TREE2,    TREE2,       0,    TREE2,   CROSS,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,       0,       0,       0,    TREE2,   SWORD },
      {       0,       0,       0,       0,    TREE2,    TREE2,       0,       0,       0,       0,       0,       0,    TREE2,    DOWN2,   SWORD,   SWORD },
      {    TREE2,      UP2,       0,   WALRUS,       0,       0,    LEFT2,    TREE2,   ESKIMO,    TREE2,    DOWN2,    TREE2,    TREE2,    DOWN2,   SWORD,   SWORD },
      {   STAFF,   STAFF,    TREE2,       0,       0,       0,       0,       0,   STAFF,   ESKIMO,       0,       0,    TREE2,    DOWN2,    WAMPA,   ESKIMO },
      {    TREE2,       0,    TREE2,    TREE2,    TREE2,    TREE2,    WAMPA,    TREE2,   ESKIMO,    TREE2,    TREE2,    TREE2,       0,    DOWN2,   STAFF,   WALRUS },
      {     KEY,   ESKIMO,    LEFT2,   WALRUS,       0,       0,       0,    LEFT2,       0,       0,       0,       0,       0,       0,   ESKIMO,   CROSS }
   }
};



const LEVEL w1r07 =
{
   6, 5,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,     SNOWMAN,     SNOWMAN,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,     SNOWMAN,   CROSS,    WAMPA,     SNOWMAN,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,     SNOWMAN,    WAMPA,    WAMPA,     SNOWMAN,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,     SNOWMAN,     SNOWMAN,    WAMPA,   STAFF,    WAMPA,   SWORD,     SNOWMAN,     SNOWMAN,       0,       0,       0,       0 },
      {       0,       0,       0,     SNOWMAN,    WAMPA,   SWORD,   SWORD,    WAMPA,    WAMPA,   WALRUS,    WAMPA,    WAMPA,     SNOWMAN,       0,       0,       0 },
      {       0,       0,       0,     SNOWMAN,    WAMPA,    WAMPA,       0,   SWORD,    WAMPA,   WALRUS,    WAMPA,    DOOR,     SNOWMAN,       0,       0,       0 },
      {       0,       0,       0,       0,     SNOWMAN,     SNOWMAN,    WAMPA,    WAMPA,   ESKIMO,    WAMPA,     SNOWMAN,     SNOWMAN,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,     SNOWMAN,    WAMPA,   SWORD,     SNOWMAN,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,     SNOWMAN,    WAMPA,     KEY,     SNOWMAN,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,     SNOWMAN,     SNOWMAN,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w1r08 =
{
    7, 5,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,       0,       0,       0,    TREE2,    TREE2,    TREE2,    TREE2,       0,       0 },
      {    DOOR,   WALRUS,   STAFF,   WALRUS,   STAFF,   CROSS,    TREE2,       0,       0,    TREE2,   WALRUS,    WAMPA,   STAFF,    DOWN2,    TREE2,       0 },
      {    TREE2,    TREE2,   WALRUS,    TREE2,    TREE2,    WAMPA,    TREE2,       0,    TREE2,   ESKIMO,   SWORD,    TREE2,    TREE2,       0,     KEY,    TREE2 },
      {    TREE2,       0,       0,    TREE2,       0,   CROSS,    TREE2,       0,    TREE2,       0,    TREE2,   STAFF,   WALRUS,    TREE2,       0,    TREE2 },
      {    TREE2,    TREE2,    TREE2,    TREE2,       0,    TREE2,    TREE2,    TREE2,    TREE2,       0,    TREE2,   WALRUS,   STAFF,    TREE2,       0,    TREE2 },
      {    TREE2,       0,   WALRUS,   STAFF,       0,       0,       0,       0,       0,       0,    TREE2,    TREE2,   ESKIMO,    TREE2,       0,    TREE2 },
      {    TREE2,       0,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,       0,       0,    TREE2,       0,       0,       0,    TREE2 },
      {    TREE2,       0,       0,ABBAYE_U_2,       0,       0,    TREE2,    TREE2,    TREE2,       0,    TREE2,    TREE2,    TREE2,    TREE2,   STAFF,    TREE2 },
      {    TREE2,       0,    TREE2,ABBAYE_D_2,    TREE2,       0,    TREE2,       0,    TREE2,       0,       0,    TREE2,       0,   WALRUS,   WALRUS,    TREE2 },
      {    TREE2,       0,   SWORD,    TREE2,   STAFF,       0,    TREE2,       0,       0,    TREE2,   ESKIMO,   SWORD,   CROSS,       0,    TREE2,       0 },
      {    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,    TREE2,       0,       0,       0,    TREE2,    TREE2,    TREE2,    TREE2,        0,      0 }
   }
};


const LEVEL w1r09 =
{
   3, 10,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,    WAMPA,   CROSS,   SWORD,   STAFF,   ESKIMO,   SWORD,       0,       0,   ESKIMO,   STAFF,  ICEBLOCK,    DOOR },
      {  ICEBLOCK,  ICEBLOCK,       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0,  ICEBLOCK,  ICEBLOCK,       0,       0 },
      {       0,       0,       0,       0,       0,    WAMPA,       0,       0,       0,  ICEBLOCK,       0,       0,  ICEBLOCK,    WAMPA,       0,   TREE2 },
      {  ICEBLOCK,       0,      UP2,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,   ESKIMO,       0,       0,       0,       0,  ICEBLOCK,  ICEBLOCK,       0,  ICEBLOCK,   CROSS },
      {     KEY,  ICEBLOCK,       0,       0,   STAFF,       0,   ESKIMO,  ICEBLOCK,       0,       0,       0,  ICEBLOCK,   STAFF,   STAFF,  ICEBLOCK,   WALRUS },
      {   SWORD,   WALRUS,    WAMPA,       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,    WAMPA,   ESKIMO,  ICEBLOCK,   CROSS },
      {       0,    LEFT2,       0,  ICEBLOCK,   CROSS,   STAFF,       0,       0,       0,   RIGHT2,       0,       0,       0,       0,       0,    WAMPA },
      {       0,  ICEBLOCK,  ICEBLOCK,   SWORD,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,   ESKIMO,  ICEBLOCK,    WAMPA,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0 },
      {   ESKIMO,  ICEBLOCK,   CROSS,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {   STAFF,   CROSS,  ICEBLOCK,       0,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,  ICEBLOCK,       0,  ICEBLOCK,  ICEBLOCK,    WAMPA },
      {   CROSS,   RIGHT2,   WALRUS,       0,   ESKIMO,   SWORD,   STAFF,  ICEBLOCK,   WALRUS,    WAMPA,       0,       0,       0,  ICEBLOCK,   CROSS,   WALRUS }
   }
};


const LEVEL w1r10 =
{
   15, 9,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    DOOR,     TREE2,     TREE2,       0,       0,   ESKIMO,       0,       0,   ESKIMO,    WAMPA,       0,       0,     TREE2,     TREE2,     TREE2,     TREE2 },
      {    WAMPA,     TREE2,       0,   CROSS,     TREE2,     TREE2,     TREE2,    DOWN2,     TREE2,       0,     TREE2,       0,       0,       0,       0,     TREE2 },
      {       0,   RIGHT2,       0,     TREE2,   CROSS,   CROSS,   ESKIMO,   CROSS,       0,    LEFT2,   CROSS,    LEFT2,    LEFT2,     TREE2,   ESKIMO,     TREE2 },
      {       0,   RIGHT2,       0,     TREE2,   ESKIMO,     TREE2,     TREE2,     TREE2,    DOWN2,   SWORD,     TREE2,   RIGHT2,      UP2,   ESKIMO,   CROSS,     TREE2 },
      {       0,   RIGHT2,       0,   RIGHT2,       0,       0,       0,       0,       0,       0,   ESKIMO,       0,       0,     TREE2,   ESKIMO,     TREE2 },
      {       0,   RIGHT2,   ESKIMO,     TREE2,       0,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,       0,     TREE2,       0,     TREE2,       0,     TREE2 },
      {       0,   RIGHT2,   CROSS,     TREE2,       0,   ESKIMO,       0,   STAFF,    WAMPA,   ESKIMO,       0,     TREE2,     TREE2,     TREE2,   CROSS,       0 },
      {       0,   RIGHT2,   ESKIMO,       0,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,     TREE2,       0,   SWORD,       0,     TREE2,   CROSS,       0 },
      {       0,   RIGHT2,       0,   ESKIMO,       0,   CROSS,       0,       0,       0,       0,       0,     TREE2,   SWORD,   RIGHT2,   CROSS,       0 },
      {       0,     TREE2,   RIGHT2,   RIGHT2,      UP2,     TREE2,      UP2,      UP2,     TREE2,     TREE2,     TREE2,   SWORD,   WALRUS,     TREE2,   CROSS,       0 },
      {     KEY,   ESKIMO,       0,       0,       0,    WAMPA,   ESKIMO,   ESKIMO,   CROSS,   CROSS,       0,   WALRUS,       0,   ESKIMO,       0,     TREE2 }
   }
};


const LEVEL w1r11 =
{
   1, 4,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    SNOWMAN,    SNOWMAN,    SNOWMAN,       0,       0,       0,       0,       0,    LEFT2,       0,   ESKIMO,   CROSS,   ESKIMO,   STAFF,   SWORD,    SNOWMAN },
      {    SNOWMAN,       0,       0,       0,    SNOWMAN,    WAMPA,    SNOWMAN,   WALRUS,    SNOWMAN,    SNOWMAN,       0,   WALRUS,    SNOWMAN,    SNOWMAN,   WALRUS,   CROSS },
      {    SNOWMAN,    SNOWMAN,   WALRUS,    SNOWMAN,   ESKIMO,       0,    SNOWMAN,       0,       0,       0,       0,    SNOWMAN,   STAFF,   ESKIMO,   WALRUS,   ESKIMO },
      {    SNOWMAN,    DOOR,       0,   RIGHT2,     KEY,    LEFT2,    SNOWMAN,   SWORD,    SNOWMAN,    SNOWMAN,       0,       0,    WAMPA,    SNOWMAN,       0,    SNOWMAN },
      {    SNOWMAN,       0,    SNOWMAN,    SNOWMAN,    SNOWMAN,    SNOWMAN,    SNOWMAN,       0,       0,       0,    SNOWMAN,       0,    SNOWMAN,       0,    WAMPA,   STAFF },
      {   SWORD,    DOWN2,   CROSS,   CROSS,    SNOWMAN,       0,    SNOWMAN,   WALRUS,    SNOWMAN,       0,    SNOWMAN,       0,       0,       0,    SNOWMAN,    SNOWMAN },
      {   WALRUS,       0,   WALRUS,   CROSS,   ESKIMO,       0,       0,       0,    SNOWMAN,       0,    SNOWMAN,    DOWN2,    SNOWMAN,    SNOWMAN,    SNOWMAN,   SWORD },
      {    SNOWMAN,       0,    SNOWMAN,    SNOWMAN,    SNOWMAN,      UP2,    SNOWMAN,    SNOWMAN,    SNOWMAN,    DOWN2,    SNOWMAN,       0,   WALRUS,       0,   ESKIMO,       0 },
      {    SNOWMAN,       0,   ESKIMO,   SWORD,       0,       0,       0,    WAMPA,    SNOWMAN,       0,    SNOWMAN,    SNOWMAN,    SNOWMAN,       0,    SNOWMAN,    SNOWMAN },
      {    SNOWMAN,       0,       0,    WAMPA,    SNOWMAN,   STAFF,    SNOWMAN,   STAFF,    SNOWMAN,       0,    SNOWMAN,       0,       0,       0,    WAMPA,   STAFF },
      {    SNOWMAN,   STAFF,    SNOWMAN,   RIGHT2,       0,       0,       0,   WALRUS,       0,       0,   ESKIMO,       0,    SNOWMAN,       0,    SNOWMAN,   STAFF }
   }
};


const LEVEL w1r12 =
{
      15,  0,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      { SNOWMAN,    DOOR,    DOWN2,   STAFF,    LEFT2,   CROSS,    LEFT2,   ESKIMO,    DOWN2,   STAFF,    DOWN2,   WALRUS,    LEFT2,   STAFF,    LEFT2,       0 },
      {    WALRUS,      UP2,   WALRUS,      UP2,    WAMPA,      UP2,   CROSS,    LEFT2,    WAMPA,      UP2,   SWORD,   RIGHT2,   STAFF,   RIGHT2,   WALRUS,    DOWN2 },
      {       UP2,   ESKIMO,    LEFT2,   CROSS,    DOWN2,   ESKIMO,    LEFT2,   CROSS,   RIGHT2,   CROSS,   RIGHT2,    WAMPA,    DOWN2,   ESKIMO,    DOWN2,   CROSS },
      {     STAFF,    LEFT2,   WALRUS,      UP2,    WAMPA,   RIGHT2,   SWORD,      UP2,    WAMPA,    DOWN2,   WALRUS,    LEFT2,    WAMPA,    LEFT2,   SWORD,    DOWN2 },
      {     DOWN2,   SWORD,      UP2,   STAFF,      UP2,   CROSS,    DOWN2,   CROSS,      UP2,   STAFF,      UP2,   CROSS,    DOWN2,    WAMPA,    LEFT2,   STAFF },
      {    ESKIMO,      UP2,   CROSS,      UP2,   SWORD,    LEFT2,       0,   RIGHT2,   SWORD,    LEFT2,   WALRUS,    LEFT2,   STAFF,   RIGHT2,    WAMPA,    DOWN2},
      {     DOWN2,   ESKIMO,    LEFT2,   CROSS,    LEFT2,   CROSS,   RIGHT2,   WALRUS,    DOWN2,       0,    DOWN2,   SWORD,    DOWN2,   CROSS,    LEFT2,   WALRUS },
      {     SWORD,    DOWN2,   WALRUS,    LEFT2,   ESKIMO,    LEFT2,   STAFF,    LEFT2,   WALRUS,    LEFT2,   STAFF,   RIGHT2,   ESKIMO,   RIGHT2,   STAFF,      UP2 },
      {     DOWN2,   SWORD,      UP2,     KEY,    LEFT2,   SWORD,      UP2,       0,    DOWN2,   WALRUS,    LEFT2,       0,    DOWN2,   ESKIMO,    DOWN2,   SWORD },
      {     WAMPA,      UP2,    WAMPA,    LEFT2,   SWORD,    DOWN2,   WALRUS,    LEFT2,   STAFF,    DOWN2,   STAFF,    DOWN2,   CROSS,      UP2,   WALRUS,    DOWN2 },
      {    RIGHT2,   STAFF,   RIGHT2,   WALRUS,      UP2,   STAFF,      UP2,       0,      UP2,   WALRUS,      UP2,   ESKIMO,    LEFT2,   CROSS,    LEFT2,    WAMPA }
   }
};




const LEVEL w1r13 =
{
   6, 5,
   (Image *) &w1_marco_1,
   (struct genresSprites *) &w1s_line_down,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,        0,  ESKIMO,   ESKIMO,       0,       0,        0,        0,       0,    CROSS,          0,         0,         0,         0,         0,       0 },
      {       0,        0,       0,        0,       0,       0,    STAFF,        0,       0,        0,          0,   CANDLE2,   CANDLE2,    FISH21,         0,  FISH21 },
      {       0,   TREE22,  TREE22,        0,  HOLE21,  HOLE21,    STAFF,    ROCK2,   ROCK2,        0,          0,         0,         0,    FISH22,         0,  FISH22 },
      {       0,    TREE2,   TREE2,    TREE2,       0,       0,    STAFF,    STAFF,   ROCK2,        0,   ICEBLOCK,    ESKIMO,         0,         0,         0,       0 },
      {       0,        0,       0,    TOMB2,   TOMB2,   TOMB2,        0,    STAFF,   WAMPA,        0,   ICEBLOCK,  ICEBLOCK,         0,         0,         0,       0 },
      {       0,        0,   SWORD,        0,       0,       0,        0,        0,       0,        0,      WAMPA,         0,         0,ABBAYE_U_2,         0,       0 },
      {   CROSS,        0,   SKULL,        0,       0,       0,        0,        0,       0,        0,          0,         0,         0,ABBAYE_D_2,         0,       0 },
      {   SWORD,        0,       0,        0,     UP2,       0,    DOWN2,        0,   LEFT2,        0,     RIGHT2,         0,STALAGMITE,         0,         0,       0 },
      {       0,    IGLU1,   IGLU2,        0,       0,       0,        0,        0,       0,    WAMPA,          0,         0,STALAGMITE,         0,ABBAYE_U_2,       0 },
      {       0,    IGLU3,   IGLU4,   WALRUS,  WALRUS,       0,        0,        0,  SNOWMAN,       0,          0,STALAGMITE,         0,         0,ABBAYE_D_2,       0 },
      {       0,        0,       0,  CANDLE2, CANDLE2,  WALRUS,   WALRUS,        0,  SNOWMAN,       0,          0,         0,         0,         0,         0,       0 }
   }
};
