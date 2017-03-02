#include "../inc/include.h"



static u8 _count = 0;

BIGBOY _list [ BIGBOY_MAX ] = {};




static s16 _find ( s16 x, s16 y )
{
	s16 i;

	for ( i=0; i<BIGBOY_MAX; i++ )
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
		_list[i] = (BIGBOY) { EMPTY, -1, -1, -1 };
	}

	_count = 0;
}


BIGBOY * bigboy ( )
{
   return (BIGBOY*) &_list;
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

	return (BIGBOY*) &_list[pos];
}


BIGBOY *bigboy_getByIndex ( s8 index )
{
	u16 i = BIGBOY_MAX;

	while ( i-- )
	{
		if ( index == _list[i].index )
		{
			return (BIGBOY*) &_list[i];
		}
	}

	return NULL;
}


void bigboy_set ( s16 x, s16 y, u16 objeto )
{
//	s16 i = _find ( x, y );
//
//	// es nuevo
//	if ( i == -1 )
//	{
//		i = _count++;
//	}

	u16 i = _count++;

	_list[i].objeto = objeto;
	//_list[i].index  = 0; // no fijar
	_list[i].x      = x;
	_list[i].y      = y;
}


u8 bigboy_count ( )
{
	return _count;
}


void bigboy_show ()
{
	u8 i;

	drawUInt  ( _count,     20, 0, 2 );

	for ( i=0; i<BIGBOY_MAX; i++ )
	{
		//if ( _list[i].index != -1 )
		{
			drawInt  ( _list[i].index, 10, i+2, 2 );
			drawInt  ( _list[i].x,     13, i+2, 2 );
			drawInt  ( _list[i].y,     16, i+2, 2 );
		}
	}
}






//
//#include "../inc/include.h"
//
//
//
//static u8 _count = 0;
//
//BIGBOY _list [ BIGBOY_MAX ] = {};
//
//
//
//
//static BIGBOY *_find ( s16 x, s16 y )
//{
//	s16 i;
//
//	for ( i=0; i<_count; i++ )
//	{
//		if ( x == _list[i].x  &&  y == _list[i].y )
//		{
//			return &_list[i];
//		}
//	}
//
//	return NULL;
//}
//
//
/////////////////////////////////////////////////////////////////////////////////
//
//
//
//void bigboy_init (  )
//{
//	u8 i;
//
//	for ( i=0; i<BIGBOY_MAX; i++ )
//	{
//		_list[i] = (BIGBOY) { EMPTY, -1, 0, 0 };
//	}
//
//	_count = 0;
//}
//
//
//BIGBOY * bigboy_get ( u16 i )
//{
//   return (BIGBOY*) &_list[i];
//}
//
//
//BIGBOY *bigboy_getByPos ( s16 x, s16 y )
//{
//	BIGBOY *bb = _find ( x, y );
//
//	if ( bb )
//	{
//		return (BIGBOY *) bb;
//	}
//
//	return NULL;
//}
//
//
//void bigboy_set ( s16 x, s16 y, u16 objeto )
//{
//   BIGBOY *bb = _find ( x, y );
//
//   if ( !bb )
//   {
//		bb = & _list [ _count++ ];
//   }
//
//   bb = (BIGBOY*) { objeto, -1, x, y };
//
////   _list[_count].objeto = objeto;
////   //_list[i].index  = 0; // no fijar
////   _list[_count].x      = x;
////   _list[_count].y      = y;
////   ++_count;
//}
//
//
//u8 bigboy_count ( )
//{
//   return _count;
//}

















//
//#include "../inc/include.h"
//
//
//
//static u8 _count = 0;
//
//BIGBOY _list [ BIGBOY_MAX ] = {};
//
//
//
//
//static s16 _find ( s16 x, s16 y )
//{
//	s16 i;
//
//	for ( i=0; i<_count; i++ )
//	{
//		if ( x == _list[i].x  &&  y == _list[i].y )
//		{
//			return i;
//		}
//	}
//
//	return -1;
//}
//
//
/////////////////////////////////////////////////////////////////////////////////
//
//
//
//void bigboy_init (  )
//{
//	u8 i;
//
//	for ( i=0; i<BIGBOY_MAX; i++ )
//	{
//		_list[i] = (BIGBOY) { EMPTY, -1, 0, 0 };
//	}
//
//	_count = 0;
//}
//
//
//BIGBOY * bigboy_get ( u16 i )
//{
//   return (BIGBOY*) &_list[i];
//}
//
//
//BIGBOY *bigboy_getByPos ( s16 x, s16 y )
//{
//	s16 pos = _find ( x, y );
//
//
//	drawInt(pos, 10,0, 2);
//	drawUInt(_count, 14,0, 2);
//	if ( pos < 0 )
//	{
//		return NULL;
//	}
//
//	return (BIGBOY*) &_list[pos];
//	//return (BIGBOY*)  bigboy_get ( pos ) ;
//}
//
//
//void bigboy_set ( s16 x, s16 y, u16 objeto )
//{
//   s16 i = _find ( x, y );
//
//   // es nuevo
//   if ( i == -1 )
//   {
//		i = _count++;
//   }
//
//   _list[i] = (BIGBOY) { objeto, -1, x, y };
//}
//
//
//u8 bigboy_count ( )
//{
//   return _count;
//}
//
//
//void bigboy_show ()
//{
//	u8 i;
//
//	for ( i=0; i<BIGBOY_MAX; i++ )
//	{
//		if ( _list[i].index != -1 )
//		{
//			drawInt  ( _list[i].index, 0, i+2, 2 );
//			drawInt  ( _list[i].x,     3, i+2, 2 );
//			drawInt  ( _list[i].y,     6, i+2, 2 );
//		}
//	}
//}
