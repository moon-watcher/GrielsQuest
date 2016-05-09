
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
	u8  player_x, player_y;

//	u8 password[9];
//	void (*pInit) ( u16 );
//	u8  head;
//	u8  music;
//	u8  music_completed;

	Image *background;

	struct genresSprites *line_down;
	struct genresSprites *line_left;
	struct genresSprites *line_right;

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




LEVEL      *level                     ( );
LEVEL      *level_get                 ( );
LEVEL       level_init                ( bool flip_h, bool flip_v );
void        level_draw                ( );
void        level_draw_area           ( LEVEL  level, u8 x, u8 y, u8 width, u8 height, bool animation );
void        level_draw_linedown       ( LEVEL *level );
void 	      level_draw_lineleft       ( LEVEL *level );
void        level_draw_lineright      ( LEVEL *level );
u16         level_get_object          ( LEVEL *level, u8 x, u8 y );
void        level_set_object          ( LEVEL *level, u8 x, u8 y, u16 object );
void        level_remove_object       ( LEVEL *level, u8 x, u8 y );
void        level_draw_door           ( );
void        level_draw_key            ( );
void        level_griel_exits         ( );
void        level_find_bigboys        ( LEVEL level, u8 x, u8 y, u8 width, u8 height );
void        level_presentation        ( );

Vect2D_u16  level_get_key             ( );
void        level_set_key             ( u16 x, u16 y );
Vect2D_u16  level_get_door            ( );
void        level_set_door            ( u16 x, u16 y );

u16         level_current             ( );
void        level_remove_key          ( );
void        level_draw_demon          ( u16 x, u16 y, u8 ojos, u8 cola );
u16         level_vram_pos            ( u16 plan );

void        level_ol_set              ( u8 obj, bool value );
bool        level_ol_get              ( u8 obj );
u16         level_get_max_rounds      ( );
u16         level_get_music           ( );
u16         level_get_head            ( );

void        level_update              ( );
void        level_draw_ambiente_3     ( );
void        level_draw_ambiente_4     ( );

bool        level_flipped_h           ( );
bool        level_flipped_v           ( );

void        level_wait_by_line        ( u16 wait );
void        level_actualizar_marcador ( );

u16         level_find                ( u16 object, LEVEL *level, Vect2D_u16 grid[] );
s16         level_hpos_to_pixel       ( s16 x );
s16         level_vpos_to_pixel       ( s16 y );

void        level_draw_animation      ( u16 nb, u8 x, u8 y );
void        level_draw_animation_size ( u8 width, u8 height );
