#include "../inc/include.h"



static u16 _tile ( u16 objeto, s8 prio )
{
   if ( prio == -1 ) // -1 means AUTO
   {
      prio = object_is_over ( objeto ) ? 1: 0;
   }

	return TILE_ATTR_FULL ( vobject_get(objeto)->object->pal, prio, 0, 0, vobject_get(objeto)->vram_pos );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void vsprite_set ( u8 sp_index, s16 x, s16 y, u16 objeto )
{
   vobject_add ( objeto );

	vdpSpriteCache [ sp_index ].posx      = x;
	vdpSpriteCache [ sp_index ].posy      = y;
	vdpSpriteCache [ sp_index ].size      = vobject_get( objeto )->object->res->size >> 8;
	vdpSpriteCache [ sp_index ].tile_attr = _tile ( objeto, -1 );

   VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );
}


void vsprite_animation ( u8 sp_index, u16 objeto  )
{
   vobject_add ( objeto );
	vdpSpriteCache [ sp_index ].tile_attr = _tile ( objeto, -1 );

   VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );
}


void vsprite_position ( u8 sp_index, s16 x, s16 y )
{
	vdpSpriteCache [ sp_index ].posx = x;
	vdpSpriteCache [ sp_index ].posy = y;

   VDP_setSpriteP ( sp_index, &vdpSpriteCache [ sp_index ] );
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
