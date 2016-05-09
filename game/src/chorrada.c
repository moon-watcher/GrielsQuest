#include "../inc/include.h"


typedef struct
{
	u16  object;
	u16  object_alt;
	u16  duration;
	bool is_bigboy;
}
CHORRADA;


static CHORRADA _data;

static u16 _x;
static u16 _y;


static const CHORRADA _values [  ] =
{
	{ DARKELF,   DARKELF_ALT,   3, true  },
	{ WAMPA,     WAMPA_ALT,     4, true  },
	{ MUMMY,     MUMMY_ALT,     4, true  },
	{ PLESI,     PLESI_ALT,     4, true  },
	{ DEMON,     DEMON_ALT,     4, true  },
	{ TOADSTOOL, TOADSTOOL_ALT, 3, false },
	{ WILDBOAR,  WILDBOAR_ALT,  6, false },
	{ ESKIMO,    ESKIMO_ALT,    3, false },
	{ WALRUS,    WALRUS_ALT,    4, false },
	{ BEDOUIN,   BEDOUIN_ALT,   5, false },
	{ SCORPIO,   SCORPIO_ALT,   6, false },
	{ PIRATA,    PIRATA_ALT,    3, false },
	{ CANGREJO,  CANGREJO_ALT,  4, false },
	{ EYE,       EYE_ALT,       3, false },
	{ OGRE,      OGRE_ALT,      4, false },
	{ EMPTY }
};


static s16 _find ( u16 objeto )
{
	u16 i = 0;

	do
	{
		if ( _values[i].object  ==  objeto )
		{
			return i;
		}
	}
	while ( _values[++i].object != EMPTY );

	return -1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void chorrada_init ( )
{
	_x    = 0;
	_y    = 0;

	_data = (CHORRADA) { };
}



void chorrada_control ( LEVEL *level )
{
	if ( _data.duration == 0 )
	{
		u8 x = random() % 16;
		u8 y = random() % 11;

		u16 object   = level->grid [ y ] [ x ];
		s16 position = _find ( object );

		if ( position == -1 )
		{
			return;
		}

		_x = x;
		_y = y;

		_data.object     = _values [ position ].object;
		_data.object_alt = _values [ position ].object_alt;
		_data.duration   = _values [ position ].duration * getHz(); // x segundos;
		_data.is_bigboy  = _values [ position ].is_bigboy;

		level_set_object ( level, _x, _y, _data.object_alt );

		if ( _data.is_bigboy )
		{
			s8 index = bigboy_getByPos(_x,_y)->index;

			if ( index < 0 )
			{
				chorrada_init();
				return;
			}

			vsprite_animation ( index, _data.object_alt );
		}
		else
		{
			level_draw_animation ( _data.object_alt, _x, _y );
		}
	}


	if ( _data.duration && --_data.duration == 0 )
	{
		if ( level_get_object ( level, _x, _y ) != _data.object_alt )
		{
			return;
		}

		level_set_object ( level, _x, _y, _data.object );
		vobject_delete(_data.object_alt);

		if ( _data.is_bigboy )
		{
			s8 index = bigboy_getByPos(_x,_y)->index;

			if ( index >= 0 )
			{
				vsprite_animation ( index, _data.object);
			}
		}
		else
		{
			level_draw_animation ( _data.object, _x, _y );
		}

		chorrada_init();
	}
}








//#include "../inc/include.h"
//
//
//typedef struct
//{
//	u8  object;
//	u8  object_alt;
//	u16 duration;
//	bool is_bigboy;
//}
//CHORRADA;
//
//
//static CHORRADA _data;
//
//static u16 _x;
//static u16 _y;
//
//
//static const CHORRADA _values [ 5 ] [ 4 ] =
//{
//	{
//		{ DARKELF,   DARKELF_ALT,   3 },
//		{ TOADSTOOL, TOADSTOOL_ALT, 3, false },
//		{ WILDBOAR,  WILDBOAR_ALT,  6, false }
//	},
//
//	{
//		{ WAMPA,     WAMPA_ALT,     4, true  },
//		{ ESKIMO,    ESKIMO_ALT,    3, false },
//		{ WALRUS,    WALRUS_ALT,    4, false }
//	},
//
//	{
//		{ MUMMY,     MUMMY_ALT,     4, true  },
//		{ BEDOUIN,   BEDOUIN_ALT,   5, false },
//		{ SCORPIO,   SCORPIO_ALT,   6, false }
//	},
//
//	{
//		{ PLESI,     PLESI_ALT,     4, true  },
//		{ PIRATA,    PIRATA_ALT,    3, false },
//		{ CANGREJO,  CANGREJO_ALT,  4, false }
//	},
//
//	{
//		{ DEMON,     DEMON_ALT,     4, true  },
//		{ EYE,       EYE_ALT,       3, false },
//		{ OGRE,      OGRE_ALT,      4, false }
//	},
//};
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//void chorrada_init ( )
//{
//	_x    = 0;
//	_y    = 0;
//	_data = (CHORRADA) { };
//}
//
//
//
//void chorrada_control ( LEVEL *level )
//{
//	//if ( _data.duration == 0 && random() % 101 == 0 )
//	if ( _data.duration == 0 && random() % 10 == 0 )
//	{
//		u8 head = level_list[gamestate.ambiente][gamestate.dificultad].head;
//		u8 pos  = random() % 3;
//
//      switch ( head )
//      {
//         case DARKELF: head = 0; break;
//         case WAMPA:   head = 1; break;
//         case MUMMY:   head = 2; break;
//         case PLESI:   head = 3; break;
//         case DEMON:   head = 4; break;
//      }
//
//
//		Vect2D_u16 grid [ LEVEL_HEIGHT * LEVEL_WIDTH ];
//
//		_data = _values [ head ] [ pos ];
//		pos   = level_find ( _data.object, level, grid ) ;
//
//		if ( ! pos  )
//		{
//			return;
//		}
//
//		pos = random() % pos;
//
//		_x             = grid[pos].x;
//		_y             = grid[pos].y;
//		_data.duration = _data.duration * getHz(); // x segundos
//
//		level_set_object ( level, _x, _y, _data.object_alt );
//		level_draw_animation ( _data.object_alt, _x, _y );
//	}
//
//
//	if ( _data.duration && --_data.duration == 0 )
//	{
//		if ( level_get_object ( level, _x, _y ) != _data.object_alt )
//		{
//			return;
//		}
//
//		level_set_object ( level, _x, _y, _data.object );
//		level_draw_animation ( _data.object, _x, _y );
//
//		vobject_delete(_data.object_alt);
//	}
//}
