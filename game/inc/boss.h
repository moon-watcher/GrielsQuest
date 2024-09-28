#pragma once

//#define GRS(x)  (struct genresSprites *)  &(x)
#define BREAK   ((u16) -1)


#define BOSS_MAX_CHUNKS     10
#define BOSS_MAX_FRAMES     11
#define BOSS_MAX_ANIMATIONS  8
#define BOSS_MAX_BOSSES      5





typedef struct
{
	u8 sprite;
	u8 index;
	s8 x;
	s8 y;
}
Chunk;


typedef struct
{
	u16   start_time;
	Chunk chunks [ BOSS_MAX_CHUNKS ];
}
Frame;


typedef struct
{
	u8             nombre [ 10 ];
	bool           repeat;
	struct genresSprites *res;
	Frame          frames [ BOSS_MAX_FRAMES ];
}
TAnimation;


typedef struct
{
	u8        nombre[10];
	u8        level;
	TAnimation animaciones  [ BOSS_MAX_ANIMATIONS ];
}
Boss;


typedef struct
{
	u32 timer;

	u8  nb_boss;
	u8  nb_animation;
	u8  nb_frame;

	u16 inc_vram;
	u16 tiles;
	u8  size;
	u16 pal;

	s16 x;
	s16 y;
}
BossCtrl;




void      boss_loop      ( u8 nbLevel );
BossCtrl *boss_get       ( u8 nbBoss );
void      boss_init      ( BossCtrl *bc, u8 nb_boss, u8 nb_animacion, s16 x, s16 y, u16 pal );
void      boss_draw      ( BossCtrl *bc );
void      boss_position  ( BossCtrl *bc, s16 x, s16 y );
void      boss_animation ( BossCtrl *bc, u8 nb_animacion );
void      boss_auto      ( BossCtrl *bc );

