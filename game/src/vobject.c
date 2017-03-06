#include "../inc/include.h"



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
	u16 update [ MAX_ANIMATIONS ] = { };
	u16 contador = 0;
	VOBJECT *v;

	while ( i-- )
	{
		v = &_list [ i ];

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
			update [ contador++ ] = i;
			tiles += v->tiles;
		}

		++v->counter;
	}

	if ( contador )
	{
		SYS_disableInts();

		while ( contador-- )
		{
			v = &_list [ update [ contador ] ];
			VDP_loadTileData ( v->object->res->sprites [ v->object->frame[v->frame].pos ], v->vram_pos, v->tiles, 0 );
		}

		SYS_enableInts();
	}

	if ( DEV )
	{
		drawUInt ( tiles, 10, 0, 3 );
	}
}


VOBJECT *vobject_add ( u16 ani )
{
	if ( !_list[ani].active )
	{
		u16 tiles = animation_size ( ani );
		_list[ani] = (VOBJECT) { ani, 0, vram_new(tiles), 0, true, animation_get ( ani ), tiles };
	}

	return & _list [ ani ];
}


void vobject_delete ( u16 ani )
{
   vram_delete ( _list[ani].vram_pos );
   _list[ani] = (VOBJECT) { };
}


void vobject_animation ( u16 ani, u16 animation )
{
	if ( ani == animation || !_list[ani].active )
	{
		return;
	}

	vobject_reset ( ani );
	_list[ani].object = animation_get ( animation );
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
	_list [ ani ].frame   = 0;
	_list [ ani ].counter = 0;
}
