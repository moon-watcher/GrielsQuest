#include "../inc/include.h"


#define VCF(x)   _list[(x)].frame
#define VVP(x)   _list[(x)].vram_pos
#define VCO(x)   _list[(x)].counter
#define VAC(x)   _list[(x)].active
#define VOB(x)   _list[(x)].object
#define VNT(x)   _list[(x)].tiles




static VOBJECT _list [ MAX_ANIMATIONS ];






VOBJECT *vobject_get ( u16 ani )
{
	return &_list [ ani ];
}


void vobject_init ()
{
	u16 i;

	for ( i = 0; i < MAX_ANIMATIONS; i++ )
	{
      _list[i] = (VOBJECT) { 0, 0, 0, false, NULL, 0 };
   }
}


void vobject_update ( )
{
	u16 i = 0;

	for ( i = 0; i < MAX_ANIMATIONS; i++ )
	{
      if ( !VAC(i) || !VOB(i)->frames || ( VCO(i) && VOB(i)->frames == 1 ) )
		{
			continue;
		}

		if ( VCO(i) == VOB(i)->frame [ VCF(i) ].timer )
		{
			VCO(i) = 0;

			if ( ++VCF(i) == VOB(i)->frames )
			{
				VCF(i) = 0;
			}
		}

		if ( VCO(i) == 0 )
		{
			VDP_loadTileData ( VOB(i)->res->sprites [ VOB(i)->frame[VCF(i)].pos ], VVP(i), VNT(i), true );
		}

		++VCO(i);
   }
}


VOBJECT *vobject_add ( u16 ani )
{
   if ( !VAC(ani) )
   {
		VAC(ani) = true;
		VOB(ani) = animation_get ( ani );
		VNT(ani) = animation_size ( ani );
		VVP(ani) = vram_new ( VNT(ani) );
		VCF(ani) = 0;
		VCO(ani) = 0;
	}

	return &_list[ani];
}


void vobject_delete ( u16 ani )
{
   vram_delete ( VVP(ani) );
   _list[ani] = (VOBJECT) { 0, 0, 0, false, NULL, 0 };
}


void vobject_animation ( u16 ani, u16 animation )
{
   if ( ani == animation || !VAC(ani) )
   {
      return;
   }

   vobject_reset ( ani );
   VOB(ani) = animation_get ( animation );
}


void vobject_swap ( u16 delete, u16 add )
{
   if ( delete == add )
   {
      return;
   }

   vobject_delete ( delete );
   vobject_add ( add );
}


void vobject_reset ( u16 ani )
{
   VCF(ani) = 0;
	VCO(ani) = 0;
}
