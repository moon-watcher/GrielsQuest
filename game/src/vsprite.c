#include "../inc/include.h"


static u16 _tile ( VOBJECT *vo, s8 prio )
{
	if ( prio == -1 ) // -1 means AUTO
	{
		prio = object_is_over ( vo->index ) ? 1 : 0;
	}

	return TILE_ATTR_FULL ( vo->object->pal, prio, 0, 0, vo->vram_pos );
}




void vsprite_set ( u8 sp_index, s16 x, s16 y, u16 objeto )
{
	VOBJECT *vo = (VOBJECT*) vobject_add ( objeto );

	VDP_setSprite ( sp_index, x, y, vo->object->res->size >> 8, _tile ( vo, -1 ) );
}


void vsprite_animation ( u8 sp_index, u16 objeto  )
{
	vdpSpriteCache [ sp_index ].attribut = _tile ( vobject_add ( objeto ), -1 );

	VDP_setSpriteAttribut ( sp_index, vdpSpriteCache [ sp_index ].attribut );
}


