#define MAX_LINES 11

u8 splist_key;
u8 splist_door;
u8 splist_flash;
u8 splist_explosion;
u8 splist_element;
u8 splist_weapon;
u8 splist_griel;
u8 splist_dust;
u8 splist_ui_weapon;
u8 splist_ui_enemy;
u8 splist_ui_left_1;
u8 splist_ui_left_2;



#define splist_hide_sprite(s)  VDP_setSpritePosition ( (s), vdpSpriteCache[(unsigned)(s)].x, -64 )
#define splist_hide_sprites()  splist_hide_sprites_from_to ( 0, 80 )


void splist_init                   ( );
void splist_draw                   ( );
void splist_hide_sprites_in_height ( u16 min, u16 max );
void splist_reorder                ( );
void splist_hide_sprites_from_to   ( u16 from, u16 to );
void splist_reorder_bigboys        ( );
