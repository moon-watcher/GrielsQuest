#ifndef _VOBJECT_H_
#define _VOBJECT_H_


typedef struct
{
	u16        index;
	u8         frame;
	u16        vram_pos;
	u16        counter;
	bool       active;
	ANIMATION *object;
	u8         tiles;
}
VOBJECT;


VOBJECT *vobject_get       ( u16 objeto );
void     vobject_init      ( );
void     vobject_update    ( );
VOBJECT *vobject_add       ( u16 ani );
void     vobject_delete    ( u16 objeto );
void     vobject_animation ( u16 objeto, u16 data );
void     vobject_swap      ( u16 delete, u16 add );
void     vobject_reset     ( u16 objeto );


#endif
