#include "../inc/include.h"

const LEVEL w3r00 =
{
   2, 3,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {      UP4,       0,    LEFT4,       0,    DOWN4,       0,    LEFT4,       0,    DOWN4,       0,    LEFT4,       0,   RIGHT4,       0,   RIGHT4,       0 },
      {       0,    LEFT4,       0,      UP4,       0,    DOWN4,       0,    LEFT4,       0,   RIGHT4,       0,      UP4,       0,    DOWN4,       0,      UP4 },
      {       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,    LEFT4,       0,    DOWN4,       0,    DOWN4,       0,    LEFT4,       0,    LEFT4,       0 },
      {       0,     STONE41,       0,   RIGHT4,       0,     STONE41,       0,   RIGHT4,       0,   RIGHT4,       0,    DOWN4,       0,    DOWN4,       0,    LEFT4 },
      {       0,     STONE41,    DOWN4,       0,      UP4,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,       0,    LEFT4,       0,      UP4,       0 },
      {       0,     STONE41,       0,   RIGHT4,       0,      UP4,       0,    LEFT4,       0,      UP4,     STONE41,    DOWN4,       0,    DOWN4,       0,      UP4 },
      {       0,     STONE41,    DOWN4,       0,    DOWN4,       0,   RIGHT4,       0,   RIGHT4,       0,     STONE41,       0,    LEFT4,       0,    LEFT4,       0 },
      {     KEY,     STONE41,       0,      UP4,       0,    DOWN4,       0,      UP4,       0,    LEFT4,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,       0 },
      {       0,     STONE41,      UP4,       0,    DOWN4,       0,      UP4,       0,   RIGHT4,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,    DOOR }
   }
};


const LEVEL w3r01 =
{
   4, 1,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,       0,       0,       0,       0,       0 },
      {       0,       0,       0,     STONE41,       0,   CROSS,   PIRATA,   CROSS,   PIRATA,   CANGREJO,   PIRATA,     STONE41,       0,       0,       0,       0 },
      {       0,       0,       0,     STONE41,       0,   PIRATA,   STAFF,   PIRATA,   CROSS,    PLESI,   CROSS,   SWORD,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,   CROSS,   PIRATA,     STONE41,       0,       0,       0 },
      {       0,       0,       0,       0,     STONE41,       0,     STONE41,       0,       0,     STONE41,    DOWN4,    PLESI,     STONE41,       0,       0,       0 },
      {       0,       0,       0,       0,     STONE41,       0,     STONE41,       0,       0,     STONE41,   PIRATA,     KEY,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,   STAFF,   STAFF,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,    DOOR,    PLESI,   CANGREJO,   CROSS,   CANGREJO,   SWORD,   CANGREJO,   CANGREJO,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,    PLESI,    PLESI,   CANGREJO,   CANGREJO,   SWORD,   STAFF,   CANGREJO,   CROSS,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w3r02 =
{
   2, 5,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,   SWORD,    PLESI,   STAFF,   CANGREJO,   CANGREJO,   CANGREJO,   CROSS,   PIRATA,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,   STAFF,    PLESI,   SWORD,   CANGREJO,   PIRATA,   CANGREJO,   CROSS,   PIRATA,     STONE41,       0,       0,       0 },
      {       0,       0,       0,   RIGHT4,   SWORD,    PLESI,   STAFF,   PIRATA,     KEY,   PIRATA,   SWORD,   PIRATA,   RIGHT4,    DOOR,       0,       0 },
      {       0,       0,       0,     STONE41,   SWORD,    PLESI,   STAFF,   CANGREJO,   PIRATA,   CANGREJO,   SWORD,   PIRATA,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,   SWORD,    PLESI,   SWORD,   PIRATA,   PIRATA,   PIRATA,   SWORD,   PIRATA,     STONE41,       0,       0,       0 },
      {       0,       0,       0,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,     STONE41,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w3r03 =
{
   12, 6,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,  CARACOLA,     KEY,    PLESI,  CARACOLA,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,  CARACOLA,    PLESI,   SWORD,  CARACOLA,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,  CARACOLA,    PLESI,    PLESI,  CARACOLA,       0,       0,       0,       0,       0,       0 },
      {       0,       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,   SWORD,   PIRATA,   CANGREJO,   STAFF,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,    DOOR,   CANGREJO,   CANGREJO,    PLESI,   CROSS,   PIRATA,   PIRATA,       0,       0,       0,  CARACOLA,       0,       0 },
      {       0,       0,       0,  CARACOLA,   STAFF,   CANGREJO,   CROSS,   CROSS,   PIRATA,   CROSS,       0,       0,  CARACOLA,       0,       0,       0 },
      {       0,       0,       0,       0,  CARACOLA,   CANGREJO,   STAFF,   CROSS,   CROSS,   CROSS,       0,  CARACOLA,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w3r04 =
{
   3, 2,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0,       0,       0,       0 },
      {       0,       0,       0,  CARACOLA,   CANGREJO,   CANGREJO,   CANGREJO,   RIGHT4,   RIGHT4,   CANGREJO,   CANGREJO,   CANGREJO,  CARACOLA,       0,       0,       0 },
      {       0,       0,  CARACOLA,       0,   STAFF,   STAFF,   STAFF,   RIGHT4,   RIGHT4,   STAFF,   STAFF,   STAFF,     KEY,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,   CANGREJO,   STAFF,   CROSS,   CROSS,   RIGHT4,   RIGHT4,   CROSS,   CROSS,   STAFF,   CANGREJO,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,   CANGREJO,   STAFF,   CROSS,   CROSS,   RIGHT4,   RIGHT4,   CROSS,   CROSS,   STAFF,   CANGREJO,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,   CANGREJO,   STAFF,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,   STAFF,   CANGREJO,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,   CANGREJO,   STAFF,  CARACOLA,   PIRATA,  CARACOLA,  CARACOLA,   PIRATA,  CARACOLA,   STAFF,   CANGREJO,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,   CANGREJO,   STAFF,   CROSS,  CARACOLA,   PIRATA,   PIRATA,  CARACOLA,   PIRATA,   STAFF,   CANGREJO,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,   PIRATA,   STAFF,   CROSS,   CROSS,  CARACOLA,  CARACOLA,   CROSS,   STAFF,   STAFF,   CANGREJO,  CARACOLA,       0,       0 },
      {       0,       0,  CARACOLA,    DOOR,   PIRATA,   CANGREJO,   CANGREJO,    LEFT4,    LEFT4,   CANGREJO,   CANGREJO,   CANGREJO,   CANGREJO,  CARACOLA,       0,       0 },
            {       0,       0,       0,CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,CARACOLA,       0,       0,       0 }
   }
};


const LEVEL w3r05 =
{
   4, 2,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,      UP4,      UP4,      UP4,      UP4,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,    LEFT4,       0,   STAFF,   RIGHT4,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,    LEFT4,       0,   STAFF,   RIGHT4,      UP4,      UP4,      UP4,      UP4,      UP4,      UP4,       0,       0,       0 },
      {       0,       0,       0,    LEFT4,       0,       0,   CANGREJO,   SWORD,   CANGREJO,   CROSS,   CANGREJO,   CANGREJO,   RIGHT4,       0,       0,       0 },
      {       0,       0,       0,    LEFT4,   CANGREJO,    PLESI,   SWORD,   PIRATA,    PLESI,    PLESI,   PIRATA,   STAFF,   RIGHT4,       0,       0,       0 },
      {       0,       0,       0,    LEFT4,    PLESI,   PIRATA,   SWORD,     KEY,   SWORD,   PIRATA,   SWORD,   SWORD,   RIGHT4,       0,       0,       0 },
      {       0,       0,       0,    LEFT4,    DOWN4,    DOWN4,    DOWN4,    DOWN4,    DOWN4,    LEFT4,   SWORD,   SWORD,   RIGHT4,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,    LEFT4,   SWORD,    DOOR,   RIGHT4,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,    DOWN4,    DOWN4,    DOWN4,   RIGHT4,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w3r06 =
{
   0, 0,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,  CARACOLA,  CARACOLA,   SWORD,   STAFF,  CARACOLA,  CARACOLA,  CARACOLA,   STAFF,     KEY,  CARACOLA,   CROSS,    PLESI,       0,       0 },
      {       0,       0,  CARACOLA,       0,  CARACOLA,   STAFF,  CARACOLA,       0,       0,   CANGREJO,  CARACOLA,       0,  CARACOLA,    PLESI,    LEFT4,      UP4 },
      {       0,       0,  CARACOLA,  CARACOLA,       0,       0,  CARACOLA,  CARACOLA,  CARACOLA,       0,  CARACOLA,  CARACOLA,  CARACOLA,    PLESI,    LEFT4,       0 },
      {       0,       0,  CARACOLA,       0,       0,       0,  CARACOLA,       0,       0,   CANGREJO,  CARACOLA,   SWORD,  CARACOLA,    PLESI,    LEFT4,       0 },
      {       0,       0,  CARACOLA,   CANGREJO,   CANGREJO,   CANGREJO,  CARACOLA,  CARACOLA,  CARACOLA,       0,  CARACOLA,   CANGREJO,  CARACOLA,    PLESI,    LEFT4,    DOWN4 },
      {       0,       0,       0,       0,       0,   CANGREJO,       0,   CANGREJO,       0,   CANGREJO,       0,       0,       0,       0,       0,       0 },
      {       0,  CARACOLA,  CARACOLA,       0,  CARACOLA,   STAFF,  CARACOLA,       0,  CARACOLA,   STAFF,  CARACOLA,   CANGREJO,  CARACOLA,  CARACOLA,       0,       0 },
      {  CARACOLA,   STAFF,   CANGREJO,       0,  CARACOLA,   STAFF,  CARACOLA,       0,  CARACOLA,   STAFF,  CARACOLA,       0,  CARACOLA,       0,  CARACOLA,   PIRATA },
      {  CARACOLA,   SWORD,   CANGREJO,       0,  CARACOLA,  CARACOLA,  CARACOLA,       0,  CARACOLA,       0,  CARACOLA,       0,  CARACOLA,  CARACOLA,       0,       0 },
      {  CARACOLA,       0,   CANGREJO,       0,  CARACOLA,       0,  CARACOLA,       0,  CARACOLA,       0,  CARACOLA,       0,  CARACOLA,    DOOR,       0,       0 },
      {       0,  CARACOLA,  CARACOLA,   STAFF,  CARACOLA,       0,  CARACOLA,   SWORD,  CARACOLA,  CARACOLA,  CARACOLA,   SWORD,  CARACOLA,       0,       0,       0 }
   }
};


const LEVEL w3r07 =
{
   3, 8,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  0,       0 },
      {       0,       0,       0,       0,   PIRATA,    LEFT4,    PLESI,       0,   SWORD,       0,       0,    LEFT4,   SWORD,    PLESI,  CARACOLA,       0 },
      {       0,     KEY,       0,       0,       0,  CARACOLA,   CANGREJO,       0,       0,       0,   CANGREJO,  CARACOLA,   PIRATA,   SWORD,  CARACOLA,       0 },
      {       0,       0,       0,       0,       0,  CARACOLA,   SWORD,  CARACOLA,  CARACOLA,  CARACOLA,       0,  CARACOLA,   CROSS,    PLESI,  CARACOLA,       0 },
      { CARACOLA,       0,       0,  CARACOLA,    DOWN4,  CARACOLA,    PLESI,  CARACOLA,    DOOR,  CARACOLA,   SWORD,  CARACOLA,   CANGREJO,   CANGREJO,  CARACOLA,       0 },
      {       0,CARACOLA,CARACOLA,  0,    PLESI,  CARACOLA,   STAFF,   CROSS,    PLESI,   PIRATA,   CROSS,  CARACOLA,   STAFF,   STAFF,  CARACOLA,       0 },
      {       0,       0,       0,           0,       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,   CANGREJO,   CANGREJO,  CARACOLA,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,   STAFF,  0,     CARACOLA },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};



const LEVEL w3r08 =
{
   7, 0,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,    DOOR,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,    DOWN4,      UP4,       0,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,TORCH4,       0,   SWORD,TORCH4,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,TORCH4,   SWORD,       0,   STAFF,   SWORD,TORCH4,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,TORCH4,    PLESI,   CANGREJO,    PLESI,   CANGREJO,    PLESI,   CANGREJO,TORCH4,       0,       0,       0,       0 },
      {       0,       0,       0,TORCH4,    PLESI,   CANGREJO,    PLESI,   CANGREJO,    PLESI,   CANGREJO,    PLESI,   CANGREJO,TORCH4,       0,       0,       0 },
      {       0,       0,       0,TORCH4,   CROSS,   SWORD,   SWORD,   SWORD,   SWORD,   SWORD,   SWORD,   CROSS,TORCH4,       0,       0,       0 },
      {       0,       0,       0,       0,TORCH4,   PIRATA,   PIRATA,   CANGREJO,   CANGREJO,   PIRATA,   PIRATA,TORCH4,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,TORCH4,    PLESI,   PIRATA,   PIRATA,    PLESI,TORCH4,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,TORCH4,     KEY,   PIRATA,TORCH4,       0,       0,       0,       0,       0,       0 },
      {       0,       0,       0,       0,       0,       0,       0,TORCH4,TORCH4,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w3r09 =
{
   1, 0,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {     STONE41,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,   PIRATA,    PLESI,    DOOR,     STONE41 },
      {       0,     STONE41,    DOWN4,     STONE41,       0,       0,       0,       0,       0,       0,       0,       0,     STONE41,      UP4,     STONE41,       0 },
      {   SWORD,       0,   CANGREJO,       0,     STONE41,    DOWN4,       0,     STONE41,     STONE41,       0,      UP4,     STONE41,       0,    PLESI,       0,   SWORD },
      {   PIRATA,     STONE41,       0,       0,       0,       0,     STONE41,       0,       0,     STONE41,       0,       0,       0,       0,     STONE41,       0 },
      {   PIRATA,       0,   RIGHT4,       0,       0,   RIGHT4,       0,       0,   CROSS,       0,    LEFT4,       0,       0,    LEFT4,       0,   PIRATA },
      {       0,     STONE41,       0,       0,       0,       0,    LEFT4,   PIRATA,       0,   RIGHT4,       0,       0,       0,       0,     STONE41,       0 },
      {       0,    LEFT4,       0,       0,       0,       0,     STONE41,       0,       0,     STONE41,       0,       0,       0,       0,   RIGHT4,       0 },
      {   CANGREJO,   CANGREJO,    PLESI,       0,     STONE41,       0,       0,     STONE41,     STONE41,       0,       0,     STONE41,       0,   PIRATA,   PIRATA,   PIRATA },
      {   CROSS,   CANGREJO,   STAFF,     STONE41,   CANGREJO,      UP4,   PIRATA,    PLESI,    PLESI,   CANGREJO,    DOWN4,   PIRATA,     STONE41,   PIRATA,   PIRATA,   PIRATA },
      {   CROSS,     STONE41,   CANGREJO,   CANGREJO,       0,       0,       0,   STAFF,       0,       0,       0,       0,   CANGREJO,   CANGREJO,     STONE41,       0 },
      {     STONE41,   CROSS,   CANGREJO,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,   PIRATA,     KEY,     STONE41 }
   }
};

const LEVEL w3r10 =
{
   2, 8,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 },
      {       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0 },
      {       0,  CARACOLA,   STAFF,       0,       0,       0,   CANGREJO,   CROSS,       0,   PIRATA,   CROSS,       0,   CANGREJO,     KEY,  CARACOLA,       0 },
      {       0,  CARACOLA,  CARACOLA,      UP4,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,    DOWN4,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0 },
      {       0,  CARACOLA,   CROSS,   CANGREJO,       0,       0,   CANGREJO,       0,   STAFF,    PLESI,   PIRATA,   CROSS,       0,   SWORD,  CARACOLA,       0 },
      {       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,      UP4,  CARACOLA,  CARACOLA,    DOWN4,  CARACOLA,  CARACOLA,  CARACOLA,      UP4,  CARACOLA,  CARACOLA,       0 },
      {       0,  CARACOLA,   STAFF,   SWORD,       0,       0,    PLESI,   CANGREJO,   SWORD,       0,       0,    PLESI,   PIRATA,   STAFF,  CARACOLA,       0 },
      {       0,  CARACOLA,  CARACOLA,      UP4,  CARACOLA,  CARACOLA,  CARACOLA,    DOWN4,  CARACOLA,  CARACOLA,  CARACOLA,    DOWN4,  CARACOLA,  CARACOLA,  CARACOLA,       0 },
      {       0,  CARACOLA,       0,       0,   SWORD,    PLESI,   CROSS,       0,   PIRATA,    PLESI,   SWORD,       0,    PLESI,    DOOR,  CARACOLA,       0 },
      {       0,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,  CARACOLA,       0 },
      {       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};


const LEVEL w3r11 =
{
   0, 0,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {       0,   SWORD,    PLESI,       0,   PIRATA,       0,    PLESI,   SWORD,    PLESI,       0,       0,       0,       0,       0,   STAFF,   CROSS },
      {     KEY,    PLESI,   SWORD,   PIRATA,   CROSS,   PIRATA,   SWORD,    PLESI,   SWORD,    PLESI,       0,       0,       0,ICEBLOCK,    PLESI,    PLESI },
      {       0,   STAFF,    PLESI,   SWORD,   PIRATA,   SWORD,    PLESI,   STAFF,    PLESI,ICEBLOCK,ICEBLOCK,       0,       0,ICEBLOCK,    PLESI,   STAFF },
      {       0,       0,   STAFF,    PLESI,   SWORD,    PLESI,   STAFF,    PLESI,   SWORD,    PLESI,ICEBLOCK,       0,ICEBLOCK,    PLESI,    PLESI,       0 },
      {       0,       0,       0,   STAFF,    PLESI,   STAFF,       0,   STAFF,    PLESI,   SWORD,    PLESI,ICEBLOCK,    PLESI,   SWORD,    PLESI,   STAFF },
      {       0,       0,       0,    PLESI,   SWORD,    PLESI,       0,       0,   STAFF,    PLESI,   STAFF,    PLESI,ICEBLOCK,ICEBLOCK,    PLESI,       0 },
      {       0,   SWORD,       0,       0,    PLESI,   STAFF,       0,       0,   PIRATA,   SWORD,    PLESI,   SWORD,    PLESI,   SWORD,    PLESI,       0 },
      {       0,       0,   STAFF,    PLESI,   SWORD,    PLESI,   STAFF,   PIRATA,   CROSS,   PIRATA,   SWORD,    PLESI,   STAFF,   PIRATA,   STAFF,ICEBLOCK },
      {       0,   STAFF,    PLESI,   SWORD,    PLESI,   SWORD,    PLESI,   STAFF,   PIRATA,   STAFF,    PLESI,   STAFF,   PIRATA,   CROSS,   PIRATA,       0 },
      {   PIRATA,       0,   SWORD,    PLESI,   STAFF,    PLESI,   SWORD,    PLESI,   STAFF,       0,   STAFF,       0,       0,   PIRATA,       0,       0 },
      {    DOOR,   PIRATA,       0,   SWORD,       0,   STAFF,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0 }
   }
};

const LEVEL w3r12 =
{
      1, 1,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41 },
      {    STONE41,       0,   STAFF,    STONE41,   STAFF,   CANGREJO,   STAFF,   SWORD,       0,       0,       0,       0,       0,   PIRATA,    DOOR,    STONE41 },
      {    STONE41,   CANGREJO,   CANGREJO,    STONE41,   STAFF,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    PLESI,    STONE41 },
      {    STONE41,   CROSS,   PIRATA,    STONE41,   STAFF,   CANGREJO,   CANGREJO,   CANGREJO,   PIRATA,   CROSS,   CANGREJO,       0,       0,       0,   STAFF,    STONE41 },
      {    STONE41,   CROSS,   SWORD,    STONE41,       0,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,   STAFF,    STONE41 },
      {    STONE41,   PIRATA,    PLESI,    STONE41,   PIRATA,   CANGREJO,   CANGREJO,   CANGREJO,    PLESI,     KEY,   CANGREJO,   CANGREJO,   STAFF,    PLESI,   PIRATA,    STONE41 },
      {    STONE41,   SWORD,   STAFF,    STONE41,   CROSS,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,   PIRATA,    STONE41 },
      {    STONE41,   CANGREJO,    PLESI,    STONE41,   SWORD,    PLESI,   SWORD,   PIRATA,   SWORD,   STAFF,   SWORD,   CROSS,   PIRATA,   SWORD,   CROSS,    STONE41 },
      {    STONE41,   CANGREJO,   CROSS,    STONE41,   CANGREJO,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    PLESI,    STONE41 },
      {    STONE41,   CANGREJO,   PIRATA,   STAFF,   PIRATA,   STAFF,   STAFF,    PLESI,    PLESI,    PLESI,   SWORD,    PLESI,   STAFF,   CANGREJO,   SWORD,    STONE41 },
      {    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41,    STONE41 }
   }
};



const LEVEL w3r13 =
{
   6, 5,
   (Image *) &w3_marco_1,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   (struct genresSprites *) NULL,
   {
      {  SEASTAR,        0,       0,    TOTEM_1,       0,       0,        0,        0,       0,        0,          0,        0,        0,        0,        0,       0 },
      {  SEASTAR,        0,       0,    TOTEM_2,       0,  TORCH4,        0, TENTACLE,TENTACLE,        0,      ANCLA,        0,        0,        0,        0,       0 },
      {       0,   STONE41,       0,          0,       0,       0,        0, TENTACLE,       0,        0,      ANCLA,        0, CARACOLA,        0,        0,       0 },
      {       0,         0,       0,BIGTREE_U_4, TOTEM_1,       0,        0,        0,       0,        0,          0,        0,        0,        0,        0,       0 },
      {       0,         0,       0,BIGTREE_D_4, TOTEM_2,       0,        0,        0,       0,        0,    SEASTAR,        0,        0,        0,        0,       0 },
      {       0,     TOMB4,       0,          0,   CROSS,       0,        0,    STAFF,   SWORD,        0,          0,        0,        0,        0,        0,       0 },
      {       0,         0,       0,          0,       0,   PLESI,        0, CANGREJO,  PIRATA,        0,    STONE41,        0,        0,  BIGPLESI1,  BIGPLESI2,       0 },
      {       0,         0,       0,          0,       0,       0,        0,        0,       0,        0,      SETO4,        0,        0,  BIGPLESI3,  BIGPLESI4,       0 },
      {       0,         0,       0,          0,       0,       0,        0,        0,       0,        0,          0,        0,        0,        0,        0,       0 },
      {       0,         0,     UP4,          0,   DOWN4,       0,    LEFT4,        0,  RIGHT4,        0,          0,        0,        0,        0,        0,       0 },
      {       0,         0,       0,          0,       0,       0,        0,        0,       0,        0,          0,        0,        0,        0,        0,       0 }
   }
};
