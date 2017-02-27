#ifndef _ANIMATION_H_
#define _ANIMATION_H_



#define MAX_FRAMES     20



typedef struct
{
	u8                    name[16];

	struct genresSprites *res;
	u16                   pal;

	u8                    frames;

	struct
   {
      u8 pos;
      u8 timer;
   }
   frame [ MAX_FRAMES ];
}
ANIMATION;




enum
{
   EMPTY,


   // inicio - freeobjects

   ASYNCOBJ0,
   ASYNCOBJ1,
   ASYNCOBJ2,
   ASYNCOBJ3,
   ASYNCOBJ4,
   ASYNCOBJ5,
   ASYNCOBJ6,
   ASYNCOBJ7,
   ASYNCOBJ8,
   ASYNCOBJ9,

   // fin - freeobjects



   // inicio - common - sprite 16x24

   DOOR,
   DOOR_OPEN_ANIM,
   DOOR_O,
   DOOR_EXIT,

   GRIEL_UP,
   GRIEL_DOWN,
   GRIEL_LEFT,
   GRIEL_RIGHT,
   GRIEL_HACK_UP,
   GRIEL_HACK_DOWN,
   GRIEL_HACK_LEFT,
   GRIEL_HACK_RIGHT,
   GRIEL_STANDS,

   GRIEL_DEAD,
   GRIEL_DEAD_FIRE,
   GRIEL_DEAD_WATER,
   GRIEL_DEAD_HOLE,
   GRIEL_DEAD_TENT_1,
   GRIEL_DEAD_TENT_2,
   GRIEL_DEAD_PENTACLE,

   GRIAL,
   KEY,

   EMPTY_SPRITE,

   // fin - common - sprite 16x24



   // inicio - common - sprite 16x16

   REMOVE_OBJECT,
   REMOVE_SPRITE,
   ENEMY_DEAD,
   STAFF,
   CROSS,
   SWORD,
   DUST,
   UNDO,
   UNDO_OK,
   DEMON_EYES, // DEMON

   // fin - common - sprite 16x16


   // inicio - common - sprite 24x24

   ESTRELLITA1,
   ESTRELLITA2,
   ESTRELLITA3,
   ESTRELLITA4,

   // fin - common - sprite 24x24



   // inicio // ambiente 0

   UP1,
   DOWN1,
   LEFT1,
   RIGHT1,

   TOMB1,
   TOCON1,
   MATOJOS,
   ZARZA,
   PIEDRA1,
   SETA_2,
   CANDLE,
   FIRE,
   ABBAYE_U,
   ABBAYE_D,
   BIGTREE1_U,
   BIGTREE1_D,

   LAKE1,
   LAKE2,
   LAKE3,
   LAKE4,

   WILDBOAR,
   WILDBOAR_ALT,
   WILDBOAR_DIE,

   TOADSTOOL,
   TOADSTOOL_ALT,
   TOADSTOOL_DIE,

   DARKELF,
   DARKELF_ALT,
   DARKELF_DIE,

   // fin // ambiente 0



   // inicio // ambiente 1

   TREE2,
   TOMB2,
   UP2,
   DOWN2,
   LEFT2,
   RIGHT2,
   TREE22,
   ROCK2,
   ICEBLOCK,
   STALAGMITE,
   SNOWMAN,
   SKULL,

   HOLE21,
   FISH21,
   FISH22,
   IGLU1,
   IGLU2,
   IGLU3,
   IGLU4,
   CANDLE2,
   ABBAYE_U_2,
   ABBAYE_D_2,

   WALRUS,
   WALRUS_ALT,
   WALRUS_DIE,

   ESKIMO,
   ESKIMO_ALT,
   ESKIMO_DIE,

   WAMPA,
   WAMPA_ALT,
   WAMPA_DIE,

   // fin // ambiente 1





   // inicio // ambiente 2

   HOLEPY,
   CRUZPY, // TOMB2,
   UP3,
   DOWN3,
   LEFT3,
   RIGHT3,
   ESCARABAJO,
   CUADRADOPY,
   BLOQUEPY,
   GATOPY,

   ORUS1,
   ORUS2,
   SARCOFAGO1,
   SARCOFAGO2,

   SCORPIO,
   SCORPIO_ALT,
   SCORPIO_DIE,

   BEDOUIN,
   BEDOUIN_ALT,
   BEDOUIN_DIE,

   MUMMY,
   MUMMY_ALT,
   MUMMY_DIE,

   ESFINGE1,
   ESFINGE2,
   ESFINGE3,
   ESFINGE4,

   // fin // ambiente 2



   // inicio // ambiente 3

   TOMB4,
   UP4,
   DOWN4,
   LEFT4,
   RIGHT4,
   TORCH4,
   TOTEM_1,
   TOTEM_2,
   TENTACLE,
   BIGTREE_U_4,
   BIGTREE_D_4,
   STONE41,
   SETO4,
   SEASTAR,
   ANCLA,
   CARACOLA,

   BIGPLESI1,
   BIGPLESI2,
   BIGPLESI3,
   BIGPLESI4,

   CANGREJO,
   CANGREJO_ALT,
   CANGREJO_DIE,

   PIRATA,
   PIRATA_ALT,
   PIRATA_DIE,

   PLESI,
   PLESI_ALT,
   PLESI_DIE,

   SEA,

   // fin // ambiente 3



   // inicio // ambiente 4

   GUITAR1,
   GUITAR2,
   BARREL,
   UP5,
   DOWN5,
   LEFT5,
   RIGHT5,
   TORCH5,
   ABBAYE_U_5,
   ABBAYE_D_5,
   PENTACLE,
   BAFFLE,
   MEGADRIVE,
   BEER,
   SOFA1,
   SOFA2,

   MURCIANO1,
   MURCIANO2,
   MURCIANO3,
   MURCIANO4,

   EYE,
   EYE_ALT,
   EYE_DIE,

   OGRE,
   OGRE_ALT,
   OGRE_DIE,

   DEMON,
   DEMON_ALT,
   DEMON_DIE,

   LAVA1,
   LAVA2,

   VENTANA_1,
   VENTANA_2,
   VENTANA_3,
   VENTANA_4,

   // fin // ambiente 4



   HTP_KEY,
   HTP_DOOR,

   UI_LEFT_1,
   UI_LEFT_2,

   BLOCK,

   SLASH_UP,
   SLASH_DOWN,
   SLASH_LEFT,
   SLASH_RIGHT,

   SWORD_STANDS,

   SWORD_WALK_U,
   SWORD_WALK_D,
   SWORD_WALK_L,
   SWORD_WALK_R,

   SWORD_CHARGE_U,
   SWORD_CHARGE_D,
   SWORD_CHARGE_L,
   SWORD_CHARGE_R,

   CROSS_STANDS,

   CROSS_WALK_U,
   CROSS_WALK_D,
   CROSS_WALK_L,
   CROSS_WALK_R,

   CROSS_CHARGE_U,
   CROSS_CHARGE_D,
   CROSS_CHARGE_L,
   CROSS_CHARGE_R,

   STAFF_STANDS,

   STAFF_WALK_U,
   STAFF_WALK_D,
   STAFF_WALK_L,
   STAFF_WALK_R,

   STAFF_CHARGE_U,
   STAFF_CHARGE_D,
   STAFF_CHARGE_L,
   STAFF_CHARGE_R,

   MONEDON_DOOR,
   KBRAH_DOOR,

   EMPTY_WEAPON,


//   SCOREBALL_CREATE,
//   SCOREBALL_DELETE,
//   SCOREBALL_STATIC,

   MAX_ANIMATIONS
};



void       gfx_init           ( );

ANIMATION *animation          ( );
ANIMATION *animation_get      ( u16 x );
u16        animation_size     ( u16 ani );
u16        animation_duracion ( u16 ani );
void       animation_draw     ( u16 ani, u8 x, u8 y, bool absolutepos, VDPPlan plan, s16 prioridad, u16 flip_h, u16 flip_v, u8 width, u8 height );
void       animation_draw_raw ( u16 ani, u8 x, u8 y, bool absolutepos, VDPPlan plan, s16 prioridad, u16 flip_h, u16 flip_v, u8 width, u8 height );


#endif
