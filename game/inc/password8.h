#pragma once

#define PWD8_DIFFICULT_TO_FIND_A_PASSWORD  40 // cuanto mayor más difícil
#define PWD8_A_STARTS_AT                   65

#define PWD_HEIGHT   3
#define PWD_WIDTH   10

const char password_letras [ PWD_HEIGHT ] [ PWD_WIDTH ];


typedef char PASSWORD8[9];


bool pwd8_isOk ( PASSWORD8 pwd );
void pwd8_generate ( PASSWORD8 pwd );
void pwd8_debug ( u16 x, s32 args, ... );
