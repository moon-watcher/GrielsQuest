#include "../inc/include.h"





static DEATH _deaths [ DEATH_MAX ] = { };

static const u8 _values [ 3 * 5 ] [ 4 ] =
{
	{ WILDBOAR,  WILDBOAR_ALT,  WILDBOAR_DIE,  false },
	{ TOADSTOOL, TOADSTOOL_ALT, TOADSTOOL_DIE, false },
	{ DARKELF,   DARKELF_ALT,   DARKELF_DIE,   true  },

	{ ESKIMO,    ESKIMO_ALT,    ESKIMO_DIE,    false },
	{ WALRUS,    WALRUS_ALT,    WALRUS_DIE,    false },
	{ WAMPA,     WAMPA_ALT,     WAMPA_DIE,     true  },

	{ BEDOUIN,   BEDOUIN_ALT,   BEDOUIN_DIE,   false },
	{ SCORPIO,   SCORPIO_ALT,   SCORPIO_DIE,   false },
	{ MUMMY,     MUMMY_ALT,     MUMMY_DIE,     true  },

	{ CANGREJO,  CANGREJO_ALT,  CANGREJO_DIE,  false },
	{ PIRATA,    PIRATA_ALT,    PIRATA_DIE,    false },
	{ PLESI,     PLESI_ALT,     PLESI_DIE,     true  },

	{ OGRE,      OGRE_ALT,      OGRE_DIE,      false },
	{ EYE,       EYE_ALT,       EYE_DIE,       false },
	{ DEMON,     DEMON_ALT,     DEMON_DIE,     true  }
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



static u8 _find ( )
{
	u8 i;

	for ( i = 0; i < DEATH_MAX; i++ )
	{
		if ( _deaths[i].counter == 0 )
		{
         _deaths[i].counter = 1000;
         return i;
		}
	}

	_deaths[0].counter = 1000;

	return 0;
}


s16 _find_xy ( u8 x, u8 y )
{
	u8 i;

	for ( i = 0; i < DEATH_MAX; i++ )
	{
		if (  _deaths[i].counter  &&  x == _deaths[i].x  &&  y == _deaths[i].y  )
		{
			return i;
		}
	}

	return -1;
}


static void _delete ( u8 i )
{
	_deaths[i] = (DEATH) { } ;
	_deaths[i].sprite_id = -1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void death_init (  )
{
	u8 i;

	for ( i = 0; i < DEATH_MAX; i ++ )
	{
		_delete ( i );
	}
}


DEATH *dead_get ( u16 index )
{
	return &_deaths [ index  ];
}


DEATH *death_add ( u16 lvl_obj, u8 x, u8 y )
{
	u8 i;
	u8 index     = _find();
	u8 animation = 0;
	u8 objeto    = ASYNCOBJ0 + index;
	u8 chorrada  = 0;
	u8 is_big    = false;
	s8 sprite_id = -1;
	u8 width     = animation_get(lvl_obj)->res->width >> 3;
	u8 height    = animation_get(lvl_obj)->res->height >> 3;

	for ( i = 0; i < 3 * 5; i++ )
	{
		if ( lvl_obj == _values[i][0] || lvl_obj == _values[i][1] )
		{
			if ( lvl_obj == _values[i][1] )
			{
				chorrada = lvl_obj;
			}

			animation = _values[i][2];
			is_big    = _values[i][3];

			break;
		}
	}


	VOBJECT *v = vobject_add ( objeto );
	vobject_animation ( objeto, animation );

	if ( is_big )
	{
		sprite_id = bigboy_getByPos ( x, y )->index;
		vsprite_animation ( sprite_id, objeto );
	}
	else
	{
		level_draw_animation_size ( width, height );
		level_draw_animation ( objeto, x, y );
	}


	_deaths [ index ].counter   = animation_duracion ( animation );
	_deaths [ index ].x         = x;
	_deaths [ index ].y         = y;

	_deaths [ index ].vo        = v;

	_deaths [ index ].animation = animation;
	_deaths [ index ].objeto    = objeto;
	_deaths [ index ].chorrada  = chorrada;

	_deaths [ index ].is_big    = is_big;
	_deaths [ index ].sprite_id = sprite_id;

	_deaths [ index ].width     = width;
	_deaths [ index ].height    = height;


	return &_deaths[index];
}



void death_frame ( LEVEL *level )
{
	u8 i;

	for ( i = 0; i < DEATH_MAX; i++ )
	{
		DEATH *d = &_deaths[i];

		if ( ! d->counter )
		{
			continue;
		}


		--d->counter;


		if ( d->vo->frame == 2 )
		{
			d->vo->counter = 0;
		}

		if ( d->counter == 5 )
		{
			toani_set_explosion ( d->x, d->y  );
		}

		if ( d->counter == 0 )
		{
			if ( d->is_big )
			{
				vsprite_animation ( d->sprite_id, EMPTY_SPRITE );
			}
			else
			{
				level_draw_animation ( EMPTY, d->x, d->y );
			}

			level_remove_object ( level, d->x, d->y );

			vobject_delete ( d->animation );
			vobject_delete ( d->objeto );

			if ( d->chorrada )
			{
				vobject_delete ( d->chorrada );
			}

			_delete ( i );
		}
	}
}


void dead_cancel ( u8 x, u8 y )
{
	s16 i = _find_xy ( x, y );

	if ( i >= 0 )
	{
		_delete ( i );
	}
}



DEATH *dead_find ( u8 x, u8 y )
{
	s16 i = _find_xy ( x, y );

	if ( i >= 0 )
	{
		return &_deaths[i];
	}

	return NULL;
}
