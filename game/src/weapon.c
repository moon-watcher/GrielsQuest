#include "../inc/include.h"


/////////////////////////////////////////////////////////////////////////////////



static const struct
{
	u16 weapon;
	u16 object;
	u16 result;

	struct
	{
		bool show;
		s16  x;
		s16  y;
	}
	pos_x_frame[4];
}
_list [ ] = // 9 actions 3 times weapons
{
	{ SWORD, GRIEL_STANDS,     SWORD_STANDS,   { { 1,  0, +9 }, { 1, -1,  8 } }  }, // 0 // ok
	{ SWORD, GRIEL_UP,         SWORD_WALK_U,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 1 // ok
	{ SWORD, GRIEL_DOWN,       SWORD_WALK_D,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 2 // ok
	{ SWORD, GRIEL_LEFT,       SWORD_WALK_L,   { { 1, -1,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 3 // ok
	{ SWORD, GRIEL_RIGHT,      SWORD_WALK_R,   { { 1,  1,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 4 // ok
	{ SWORD, GRIEL_HACK_UP,    SWORD_CHARGE_U, { { 1, -8,  8 } }  }, // ok // 5
	{ SWORD, GRIEL_HACK_DOWN,  SWORD_CHARGE_D, { { 1,  0,  8 } }  }, // ok // 6
	{ SWORD, GRIEL_HACK_LEFT,  SWORD_CHARGE_L, { { 1,  0,  8 } }  }, // ok // 7
	{ SWORD, GRIEL_HACK_RIGHT, SWORD_CHARGE_R, { { 1,  0,  8 } }  }, // ok // 8

	{ CROSS, GRIEL_STANDS,     CROSS_STANDS,   { { 1,  0, +7 }, { 1,  0,  8 } }  }, // 9  // ok
	{ CROSS, GRIEL_UP,         CROSS_WALK_U,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 10 // ok
	{ CROSS, GRIEL_DOWN,       CROSS_WALK_D,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 11 // ok
	{ CROSS, GRIEL_LEFT,       CROSS_WALK_L,   { { 1, -2,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 12 // ok
	{ CROSS, GRIEL_RIGHT,      CROSS_WALK_R,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 13 // ok
	{ CROSS, GRIEL_HACK_UP,    CROSS_CHARGE_U, { { 1, -8,  8 } }  }, // 14 // ok
	{ CROSS, GRIEL_HACK_DOWN,  CROSS_CHARGE_D, { { 1,  0,  8 } }  }, // 15 // ok
	{ CROSS, GRIEL_HACK_LEFT,  CROSS_CHARGE_L, { { 1,  0,  8 } }  }, // 16 // ok
	{ CROSS, GRIEL_HACK_RIGHT, CROSS_CHARGE_R, { { 1,  0,  8 } }  }, // 17 // ok

	{ STAFF, GRIEL_STANDS,     STAFF_STANDS,   { { 1,  0,  8 }, { 1,  0,  8 } }  }, // 18
	{ STAFF, GRIEL_UP,         STAFF_WALK_U,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 19 // ok
	{ STAFF, GRIEL_DOWN,       STAFF_WALK_D,   { { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 20 // ok
	{ STAFF, GRIEL_LEFT,       STAFF_WALK_L,   { { 1, -4,  8 }, { 1, -1,  8 }, { 1, -1,  8 }, { 1, -1,  8 } }  }, // 21
	{ STAFF, GRIEL_RIGHT,      STAFF_WALK_R,   { { 1,  2,  8 }, { 1,  0,  8 }, { 1,  0,  8 }, { 1,  0,  8 } }  }, // 22 // ok
	{ STAFF, GRIEL_HACK_UP,    STAFF_CHARGE_U, { { 1, -8,  8 } }  }, // 23 // ok
	{ STAFF, GRIEL_HACK_DOWN,  STAFF_CHARGE_D, { { 1,  0,  8 } }  }, // 24 // ok
	{ STAFF, GRIEL_HACK_LEFT,  STAFF_CHARGE_L, { { 1,  0,  8 } }  }, // 25 // ok
	{ STAFF, GRIEL_HACK_RIGHT, STAFF_CHARGE_R, { { 1, -2,  8 } }  }, // 26 // ok

	{ EMPTY }
};


static s16 _cached_pos = -1;
static s16 _prev_aux   = -1;



/////////////////////////////////////////////////////////////////////////////////



static s16 _find ( PLAYER *p )
{
	u16 i = 0;

	if ( _cached_pos >= 0  &&  _list[_cached_pos].weapon == p->selected  &&  _list[_cached_pos].object == p->object )
	{
		return _cached_pos;
	}

	_cached_pos = -1;

	do
	{
		if ( _list[i].weapon == p->selected  &&  _list[i].object == p->object )
		{
			_cached_pos = i;
			break;
		}
	}
	while ( _list [++i].weapon != EMPTY );

	return _cached_pos;
}



static bool _selected ( PLAYER *p )
{
	if ( ! p->selected )
	{
		splist_hide_sprite ( splist_weapon );
		vsprite_animation ( splist_weapon, EMPTY_SPRITE );

		return false;
	}

	return true;
}


/////////////////////////////////////////////////////////////////////////////////



void weapon_init ( )
{
	_cached_pos = -1;
	_prev_aux   = -1;
}


void weapon_draw ( )
{
	PLAYER *p = player(0);

	if ( ! _selected ( p ) )
	{
		return;
	}


	const s16 i = _find ( p );

	if ( i >= 0 )
	{
		const u16 frame = vobject_get ( p->object )->frame;
		const s16 x     = _list[i].pos_x_frame [ frame ].x;
		const s16 y     = _list[i].pos_x_frame [ frame ].y;
		const u16 aux   = _list[i].pos_x_frame [ frame ].show ? _list[i].result : EMPTY_WEAPON;

		if ( _prev_aux >= 0 )
		{
			vobject_swap ( _prev_aux, aux );
		}

		vsprite_set ( splist_weapon, p->x + x, p->y + y, aux );

		_prev_aux = aux;
	}
}


void weapon_reset ( )
{
	PLAYER *p = player(0);

	if ( ! _selected ( p ) )
	{
		return;
	}


	s16 i = _find ( p );

	if ( i >= 0 )
	{
		vobject_reset ( _list[i].result );
	}
}
