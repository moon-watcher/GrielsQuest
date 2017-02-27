#include "../inc/include.h"


#define VIN(x)   _list[(x)].index
#define VFR(x)   _list[(x)].frame
#define VVR(x)   _list[(x)].vram_pos
#define VCO(x)   _list[(x)].counter
#define VAC(x)   _list[(x)].active
#define VOB(x)   _list[(x)].object
#define VTI(x)   _list[(x)].tiles


static VOBJECT _list [ MAX_ANIMATIONS ] = { };




VOBJECT *vobject_get ( u16 ani )
{
	return &_list [ ani ];
}


void vobject_init ()
{
	u16 i = MAX_ANIMATIONS;

	while ( i-- )
	{
		_list [ i ] = (VOBJECT) { };
	}
}


void vobject_update ( )
{
	u16 i = MAX_ANIMATIONS;
	u16 tiles = 0;

	while ( i-- )
	{
		VOBJECT *v = &_list[i];

		if ( !v->active || !v->object->frames || ( v->counter && v->object->frames == 1 ) )
		{
			continue;
		}

		if ( v->counter == v->object->frame [ v->frame ].timer )
		{
			v->counter = 0;

			if ( ++v->frame == v->object->frames )
			{
				v->frame = 0;
			}
		}

		if ( v->counter == 0 )
		{
			SYS_disableInts();
			VDP_loadTileData ( v->object->res->sprites [ v->object->frame[v->frame].pos ], v->vram_pos, v->tiles, 0 );
			SYS_enableInts();

			tiles += v->tiles;
		}

		++v->counter;
	}


	if ( DEV )
	{
		drawUInt ( tiles, 10, 0, 3 );
	}
}


//void vobject_update ( )
//{
//	u16 i = MAX_ANIMATIONS;
//	u16 tiles = 0;
//	u16 update [ MAX_ANIMATIONS ] = { };
//	u16 contador = 0;
//
//
//	while ( i-- )
//	{
//		if ( !VAC(i) || !VOB(i)->frames || ( VCO(i) && VOB(i)->frames == 1 ) )
//		{
//			continue;
//		}
//
//		if ( VCO(i) == VOB(i)->frame [ VFR(i) ].timer )
//		{
//			VCO(i) = 0;
//
//			if ( ++VFR(i) == VOB(i)->frames )
//			{
//				VFR(i) = 0;
//			}
//		}
//
//		if ( VCO(i) == 0 )
//		{
//			update [ contador++ ] = i;
//
//			tiles += VTI(i);
//		}
//
//		++VCO(i);
//	}
//
//
//
//	if ( contador )
//	{
//		SYS_disableInts();
//
//		while ( contador-- )
//		{
//			i = update [ contador ];
//			VDP_loadTileData ( VOB(i)->res->sprites [ VOB(i)->frame[VFR(i)].pos ], VVR(i), VTI(i), 0 );
//		}
//
//		SYS_enableInts();
//	}
//
//
//
//	if ( DEV )
//	{
//		//drawUInt ( tiles, 10, 0, 3 );
//	}
//}


VOBJECT *vobject_add ( u16 ani )
{
	if ( !VAC(ani) )
	{
		u16 tiles = animation_size ( ani );
		_list[ani] = (VOBJECT) { ani, 0, vram_new(tiles), 0, true, animation_get ( ani ), tiles };
	}

	return & _list [ ani ];
}


void vobject_delete ( u16 ani )
{
   vram_delete ( VVR(ani) );
   _list[ani] = (VOBJECT) { };
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
	VFR(ani) = 0;
	VCO(ani) = 0;
}
