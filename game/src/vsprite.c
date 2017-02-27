#include "../inc/include.h"


static u16 _tile ( VOBJECT *vo, s8 prio )
{
   if ( prio == -1 ) // -1 means AUTO
   {
      prio = object_is_over ( vo->index ) ? 1 : 0;
   }

	return TILE_ATTR_FULL ( vo->object->pal, prio, 0, 0, vo->vram_pos );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void vsprite_set ( u8 sp_index, s16 x, s16 y, u16 objeto )
{
   VOBJECT *vo = (VOBJECT*) vobject_add ( objeto );

//	vdpSpriteCache [ sp_index ].x        = x;
//	vdpSpriteCache [ sp_index ].y        = y;
//	vdpSpriteCache [ sp_index ].size     = vobject_get( objeto )->object->res->size >> 8;
//	vdpSpriteCache [ sp_index ].attribut = _tile ( objeto, -1 );
//
//   VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );

	VDP_setSprite ( sp_index, x, y, vo->object->res->size >> 8, _tile ( vo, -1 ) );
}


void vsprite_animation ( u8 sp_index, u16 objeto  )
{
	vdpSpriteCache [ sp_index ].attribut = _tile ( vobject_add ( objeto ), -1 );

   //VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );
   VDP_setSpriteAttribut ( sp_index, vdpSpriteCache [ sp_index ].attribut );
}


void vsprite_position ( u8 sp_index, s16 x, s16 y )
{
//	vdpSpriteCache [ sp_index ].x = x;
//	vdpSpriteCache [ sp_index ].y = y;
//
//   VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );
   VDP_setSpritePosition( sp_index, x, y );
}


//void vsprite_priority ( u8 sp_index, bool prio )
//{
//   if ( prio )
//   {
//      vdpSpriteCache [ sp_index ].tile_attr = BitSet ( vdpSpriteCache [ sp_index ].tile_attr, 15 );
//   }
//   else
//   {
//      vdpSpriteCache [ sp_index ].tile_attr = BitClr ( vdpSpriteCache [ sp_index ].tile_attr, 15 );
//   }
//
//   VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );
//}
