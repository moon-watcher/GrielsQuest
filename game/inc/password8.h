#define PWD8_DIFFICULT_TO_FIND_A_PASSWORD  40 // cuanto mayor más difícil
#define PWD8_A_STARTS_AT                   65

typedef u8 PASSWORD8[9];


void pwd8_generate ( PASSWORD8 pwd );
bool pwd8_screen   ( );
