#define DEATH_MAX     ASYNCOBJ9 - ASYNCOBJ0 + 1





typedef struct _DEATH
{
	u16      counter;
	u8       x;
	u8       y;

	VOBJECT *vo;

	u8       animation;
	u16      objeto;
	u8       chorrada;

	bool     is_big;
	s8       sprite_id;

	u16      width;
	u16      height;
}
DEATH;






void   death_init  ( );
DEATH *dead_get    ( u16 index );
DEATH *death_add   ( u16 objeto, u8 x, u8 y );
void   death_frame ( );
void   dead_cancel ( u8 x, u8 y );
DEATH *dead_find   ( u8 x, u8 y );

