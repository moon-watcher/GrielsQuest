#pragma once


#define LEVEL_NB_LEVELS	 64


#define LEVEL_HEIGHT     11
#define LEVEL_WIDTH      16


#define LEVEL_VRAM_POS       400

#define VRAM_POS_DEMON       800
//#define SIZE_SP_DEMON        ( w1s_demon.size >> 8 )
//#define POS_SP_DEMON(i)      ( VRAM_POS_DEMON + SIZE_SP_DEMON * (i) )

#define VRAM_POS_EXPLOSION   770
//#define SIZE_SP_EXPLOSION    ( w1s_demon.size >> 8 )
//#define POS_SP_EXPLOSION(i)  ( VRAM_POS_EXPLOSION + SIZE_SP_EXPLOSION * (i) )






#define LEVEL_DIF_FACIL   0
#define LEVEL_DIF_NORMAL  1
#define LEVEL_DIF_DIFICIL 2


#define LEVEL_DIF_MAX_AMBIENTES    5
#define LEVEL_DIF_MAX_DIFICULTAD   3 // + 1 // 1 es para RetroBarcelona
#define LEVEL_DIF_MAX_NIVELES     14
#define LEVEL_DIF_MUSICS           3







typedef struct
{
	u8  player_x;
	u8  player_y;
	Image *background;
	u16 grid [ LEVEL_HEIGHT ] [ LEVEL_WIDTH ];
}
LEVEL;



typedef struct
{
   u8     nombre[12];
   u8     cuantos;
   u8     head;
   //MUSIC *musicas [ LEVEL_DIF_MUSICS ];
   u8     musicas [ LEVEL_DIF_MUSICS ];
   LEVEL *levels [ LEVEL_DIF_MAX_NIVELES ];
}
LEVELLIST;



const LEVELLIST level_list [ LEVEL_DIF_MAX_AMBIENTES ] [ LEVEL_DIF_MAX_DIFICULTAD ];




#define level_current()          gamestate.current_round
#define level_get_max_rounds()   level_list [ (u16)gamestate.current_ambiente ] [ gamestate_get_dificultad ( ) ].cuantos
#define level_hpos_to_pixel(x)   ( ( (x) << 4 ) + VOFFSET_HORIZONTAL - 0 )
#define level_vpos_to_pixel(y)   ( ( (y) << 4 ) + VOFFSET_VERTICAL   - 8 ) // el -8 es para compensar la altuta extra (+8px) respecto a los bloques, armas y enemigos




LEVEL      *level                     ( );
LEVEL      *level_get                 ( );
LEVEL       level_init                ( );
void        level_draw                ( LEVEL *level );
void        level_draw_area           ( LEVEL *level, u8 x, u8 y, u8 width, u8 height );
u16         level_get_object          ( LEVEL *level, u8 x, u8 y );
void        level_set_object          ( LEVEL *level, u8 x, u8 y, u16 object );
void        level_remove_object       ( LEVEL *level, u8 x, u8 y );
void        level_draw_door           ( );
void        level_draw_key            ( );
void        level_griel_exits         ( );
void        level_find_bigboys        ( LEVEL level, u8 x, u8 y, u8 width, u8 height );

Vect2D_u16  level_get_key             ( );
void        level_set_key             ( u16 x, u16 y );
Vect2D_u16  level_get_door            ( );
void        level_set_door            ( u16 x, u16 y );

void        level_draw_demon          ( u16 x, u16 y, u8 ojos, u8 cola );
u16         level_vram_pos            ( VDPPlane plan );

void        level_ol_set              ( u8 obj, bool value );
bool        level_ol_get              ( u8 obj );

u16         level_get_music           ( );

void        level_update              ( );

//void        level_draw_linedown       ( LEVEL *level );
bool        level_flipped_h           ( );
bool        level_flipped_v           ( );

void        level_actualizar_marcador ( );

u16         level_find                ( u16 object, LEVEL *level, Vect2D_u16 grid[] );

void        level_draw_animation      ( u16 nb, u8 x, u8 y );
void        level_draw_animation_size ( u8 width, u8 height );
