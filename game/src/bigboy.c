#include "../inc/include.h"



static u8 _count;

BIGBOY _list [ BIGBOY_MAX ];




static s16 _find ( s16 x, s16 y )
{
	s16 i;

	for ( i=0; i<_count; i++ )
	{
		if ( x == _list[i].x  &&  y == _list[i].y )
		{
			return i;
		}
	}

	return -1;
}


///////////////////////////////////////////////////////////////////////////////



void bigboy_init (  )
{
	u8 i;

	for ( i=0; i<BIGBOY_MAX; i++ )
	{
		_list[i] = (BIGBOY) { EMPTY, -1, 0, 0 };
	}

	_count = 0;
}


BIGBOY * bigboy_get ( u16 i )
{
   return (BIGBOY*) &_list[i];
}


BIGBOY *bigboy_getByPos ( s16 x, s16 y )
{
	s16 pos = _find ( x, y );

	if ( pos < 0 )
	{
		return NULL;
	}

	return bigboy_get ( pos ) ;
}


void bigboy_set ( s16 x, s16 y, u16 objeto )
{
   s16 i = _find ( x, y );

   // es nuevo
   if ( i == -1 )
   {
		i = _count++;
   }

   _list[i].objeto = objeto;
   //_list[i].index  = 0; // no fijar
   _list[i].x      = x;
   _list[i].y      = y;
}


u8 bigboy_count ( )
{
   return _count;
}
