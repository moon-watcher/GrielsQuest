#include "../inc/include.h"




#define OBJECT_IS_OVER     ABBAYE_U, ABBAYE_U_2, BIGTREE1_U, FISH21, TOTEM_1, BIGTREE_U_4, ENEMY_DEAD, REMOVE_OBJECT, GUITAR1, ABBAYE_U_5, SARCOFAGO1, ORUS1, ESTRELLITA1, ESTRELLITA2, ESTRELLITA3, ESTRELLITA4

#define OBJECT_IS_BELOW    FIRE, \
                             HOLE21, \
                             UP1, DOWN1, LEFT1, RIGHT1, \
                             UP2, DOWN2, LEFT2, RIGHT2, \
                             UP3, DOWN3, LEFT3, RIGHT3, \
                             UP4, DOWN4, LEFT4, RIGHT4, \
                             UP5, DOWN5, LEFT5, RIGHT5
                             // RIVER1, RIVER2, RIVER3, RIVER4, RIVER5, RIVER6, RIVER7, RIVER8, RIVER9, RIVER10


#define OBJECT_IS_DEAD     ASYNCOBJ0, ASYNCOBJ1, ASYNCOBJ2, ASYNCOBJ3, ASYNCOBJ4, ASYNCOBJ5, ASYNCOBJ6, ASYNCOBJ7, ASYNCOBJ8, ASYNCOBJ9

#define OBJECT_IS_ENEMY    WILDBOAR, WILDBOAR_ALT, TOADSTOOL, TOADSTOOL_ALT, DARKELF, DARKELF_ALT,   \
                             WALRUS,   WALRUS_ALT,   ESKIMO,	ESKIMO_ALT,    WAMPA,   WAMPA_ALT,   \
                             BEDOUIN,  BEDOUIN_ALT,  SCORPIO,   SCORPIO_ALT,   MUMMY,   MUMMY_ALT,   \
                             PLESI,    PLESI_ALT,    CANGREJO,  CANGREJO_ALT,  PIRATA,  PIRATA_ALT,  \
                             DEMON,    DEMON_ALT,    OGRE,      OGRE_ALT,      EYE,     EYE_ALT

#define OBJECT_IS_WEAPON   STAFF, CROSS, SWORD

#define OBJECT_IS_BLOCK    BLOCK, \
                             TOCON1,   TOMB1,      TOCON1,     TOCON1,     ZARZA,       MATOJOS,     PIEDRA1,     SETA_2,    BIGTREE1_D, CANDLE,    ABBAYE_D,  LAKE1,     LAKE2,     LAKE3,      LAKE4,     \
                             TREE2,    TOMB2,      TREE22,     ROCK2,      ICEBLOCK,    STALAGMITE,  SNOWMAN,     SKULL,     FISH22,     IGLU1,     IGLU2,     IGLU3,     IGLU4,     ABBAYE_D_2, CANDLE2,   \
                             CRUZPY,   ESCARABAJO, BLOQUEPY,   GATOPY,     CUADRADOPY,  ORUS2,       SARCOFAGO2,  ESFINGE1,  ESFINGE2,   ESFINGE3,  ESFINGE4,                                               \
                             SEASTAR,  TOMB4,      TORCH4,     TOTEM_2,    BIGTREE_D_4, STONE41,     STONE41,     SETO4,     SEASTAR,    ANCLA,     CARACOLA,  BIGPLESI1, BIGPLESI2, BIGPLESI3,  BIGPLESI4, \
                             GUITAR2,  BARREL,     TORCH5,     ABBAYE_D_5, BAFFLE,      MEGADRIVE,   BEER,        SOFA1,     SOFA2,      MURCIANO1, MURCIANO2, MURCIANO3, MURCIANO4

#define OBJECT_IS_KEY      KEY //, GRIAL
#define OBJECT_IS_DOOR     DOOR, DOOR_O,  \
                             MONEDON_DOOR, KBRAH_DOOR

#define OBJECT_IS_OPENDOOR DOOR_O,  \
                             MONEDON_DOOR, KBRAH_DOOR


#define OBJECT_IS_GRIEL    GRIEL_STANDS,                                                                \
                             GRIEL_UP,          GRIEL_DOWN,        GRIEL_LEFT,          GRIEL_RIGHT,      \
                             GRIEL_HACK_UP,     GRIEL_HACK_DOWN,   GRIEL_HACK_LEFT,     GRIEL_HACK_RIGHT, \
                             GRIEL_DEAD,        GRIEL_DEAD_FIRE,   GRIEL_DEAD_WATER,    GRIEL_DEAD_HOLE,  \
                             GRIEL_DEAD_TENT_1, GRIEL_DEAD_TENT_2, GRIEL_DEAD_PENTACLE

#define OBJECT_IS_BIGBOY   DOOR,              KEY,                            \
                             DARKELF,           DARKELF_ALT,       DARKELF_DIE, \
                             WAMPA,             WAMPA_ALT,         WAMPA_DIE,   \
                             MUMMY,             MUMMY_ALT,         MUMMY_DIE,   \
                             PLESI,             PLESI_ALT,         PLESI_DIE,   \
                             DEMON,             DEMON_ALT,         DEMON_DIE,   \
                             OBJECT_IS_GRIEL, \
                             MONEDON_DOOR, KBRAH_DOOR



#define OBJECT_IS_HURTS    FIRE,     \
                             HOLE21,   \
                             HOLEPY,   \
                             TENTACLE, \
                             PENTACLE

                             // RIVER1, RIVER3, RIVER5, RIVER7, RIVER8, RIVER9, RIVER10

#define OBJECT_IS_UNDO     UNDO

#define OBJECT_IS_UP       UP1,    UP2,    UP3,    UP4,    UP5
#define OBJECT_IS_DOWN     DOWN1,  DOWN2,  DOWN3,  DOWN4,  DOWN5
#define OBJECT_IS_LEFT     LEFT1,  LEFT2,  LEFT3,  LEFT4,  LEFT5
#define OBJECT_IS_RIGHT    RIGHT1, RIGHT2, RIGHT3, RIGHT4, RIGHT5

#define OBJECT_IS_ARROW    UP1,    UP2,    UP3,    UP4,    UP5,    \
                             DOWN1,  DOWN2,  DOWN3,  DOWN4,  DOWN5,  \
                             LEFT1,  LEFT2,  LEFT3,  LEFT4,  LEFT5,  \
                             RIGHT1, RIGHT2, RIGHT3, RIGHT4, RIGHT5

#define OBJECT_IS_KILLED_BY_STAFF    WALRUS, WILDBOAR,  SCORPIO, CANGREJO, OGRE,   WALRUS_ALT, WILDBOAR_ALT,  SCORPIO_ALT, CANGREJO_ALT, OGRE_ALT
#define OBJECT_IS_KILLED_BY_CROSS    ESKIMO, TOADSTOOL, BEDOUIN, PIRATA,   EYE,    ESKIMO_ALT, TOADSTOOL_ALT, BEDOUIN_ALT, PIRATA_ALT,   EYE_ALT
#define OBJECT_IS_KILLED_BY_SWORD    WAMPA,  DARKELF,   MUMMY,   PLESI,    DEMON,  WAMPA_ALT,  DARKELF_ALT,   MUMMY_ALT,   PLESI_ALT,    DEMON_ALT

#define OBJECT_IS_ASYNCOBJ  ASYNCOBJ0, ASYNCOBJ1, ASYNCOBJ2, ASYNCOBJ3, ASYNCOBJ4, ASYNCOBJ5, ASYNCOBJ6, ASYNCOBJ7, ASYNCOBJ8, ASYNCOBJ9





u16 object_is_enemy           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_ENEMY,           0 } ); }
u16 object_is_weapon          ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_WEAPON,          0 } ); }
u16 object_is_block           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_BLOCK,           0 } ); }
u16 object_is_arrow           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_ARROW,           0 } ); }
u16 object_is_key             ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_KEY,             0 } ); }
u16 object_is_door            ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_DOOR,            0 } ); }
u16 object_is_opendoor        ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_OPENDOOR,        0 } ); }
u16 object_is_bigboy          ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_BIGBOY,          0 } ); }
u16 object_is_hurts           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_HURTS,           0 } ); }
u16 object_is_undo            ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_UNDO,            0 } ); }
u16 object_is_up              ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_UP,              0 } ); }
u16 object_is_down            ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_DOWN,            0 } ); }
u16 object_is_left            ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_LEFT,            0 } ); }
u16 object_is_right           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_RIGHT,           0 } ); }
u16 object_is_over            ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_OVER,            0 } ); }
u16 object_is_below           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_BELOW,           0 } ); }
u16 object_is_dead            ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_DEAD,            0 } ); }
u16 object_is_griel           ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_GRIEL,           0 } ); }
u16 object_is_asyncobj        ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_ASYNCOBJ,        0 } ); }
u16 object_is_killed_by_staff ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_KILLED_BY_STAFF, 0 } ); }
u16 object_is_killed_by_cross ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_KILLED_BY_CROSS, 0 } ); }
u16 object_is_killed_by_sword ( u16 nb ) { return in_array ( nb, (u16[]) { OBJECT_IS_KILLED_BY_SWORD, 0 } ); }
