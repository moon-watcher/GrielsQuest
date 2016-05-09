//#include "../inc/include.h"
//
//
//
//const static u8 _posiciones [ ] = { 0, 3, 7, 10, 14, 20, 26 };
//const static u8 _elementos  [ ] = { EMPTY, 0, 0, 10, 14, 20, 26 };
//
//
//
//
//static struct
//{
//	u8 object;
//	u8 counter;
//	u8 elemento;
//	u8 duration;
//	enum
//	{
//		HIDDEN,
//		VISIBLE,
//		BUILDING
//	}
//	status;
//}
//scoreballs [ 6 ];
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//static void _reset ( u8 which )
//{
////	scoreballs [ which ].object   = ASYNCOBJ19 - which;
//	scoreballs [ which ].counter  = 0;
//	scoreballs [ which ].elemento = 0;
//	scoreballs [ which ].duration = 0;
//	scoreballs [ which ].status   = HIDDEN;
//}
//
//
//
//
//static u16 _get_elemento ( u16 which )
//{
//	u16 elemento = 0;
//
//	if ( which == SCOREBALL_ENEMY )
//	{
//		u8 enemy  = EMPTY;
//		u8 weapon = player_get_selected();
//
//		if      ( gamestate.ambiente == 0 && weapon == STAFF ) enemy = WILDBOAR;
//		else if ( gamestate.ambiente == 0 && weapon == CROSS ) enemy = TOADSTOOL;
//		else if ( gamestate.ambiente == 0 && weapon == SWORD ) enemy = DARKELF;
//		else if ( gamestate.ambiente == 1 && weapon == STAFF ) enemy = WALRUS;
//		else if ( gamestate.ambiente == 1 && weapon == CROSS ) enemy = ESKIMO;
//		else if ( gamestate.ambiente == 1 && weapon == SWORD ) enemy = WAMPA;
//		else if ( gamestate.ambiente == 2 && weapon == STAFF ) enemy = SCORPIO;
//		else if ( gamestate.ambiente == 2 && weapon == CROSS ) enemy = BEDOUIN;
//		else if ( gamestate.ambiente == 2 && weapon == SWORD ) enemy = MUMMY;
//		else if ( gamestate.ambiente == 3 && weapon == STAFF ) enemy = CANGREJO;
//		else if ( gamestate.ambiente == 3 && weapon == CROSS ) enemy = PIRATA;
//		else if ( gamestate.ambiente == 3 && weapon == SWORD ) enemy = PLESI;
//		else if ( gamestate.ambiente == 4 && weapon == STAFF ) enemy = OGRE;
//		else if ( gamestate.ambiente == 4 && weapon == CROSS ) enemy = EYE;
//		else if ( gamestate.ambiente == 4 && weapon == SWORD ) enemy = DEMON;
//
//		elemento = enemy;
//	}
//
//	if ( which == SCOREBALL_KEY )
//	{
//		elemento = KEY;
//	}
//
//	return elemento;
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//void scoreball_init ( )
//{
//	u8 i = 0;
//
//	for ( i = 0; i < SCOREBALL_MAX; i++)
//	{
//		_reset ( i );
//	}
//}
//
//
//void scoreball_add ( u8 which, bool animate )
//{
//	if ( !which )
//	{
//		return;
//	}
//
//	if ( scoreballs [ which ].status == HIDDEN )
//	{
//		_reset ( which );
//	}
//	else
//	{
//		animate = false;
//	}
//
//	u16 animation = 0; //u16 animation = animate ? SCOREBALL_CREATE : SCOREBALL_STATIC;
//
//	vobject_add ( scoreballs[which].object );
//	vobject_animation ( scoreballs[which].object, animation );
//	animation_draw ( scoreballs[which].object, _posiciones[which], 0, true, APLAN, -1, 0, 0, 4, 4 );
//
//	scoreballs [ which ].elemento = _get_elemento ( which ); // calcular el elemento
//	scoreballs [ which ].duration = animation_duracion ( animation );
//	scoreballs [ which ].status   = BUILDING;
//}
//
//
//void scoreball_frame ( )
//{
//	u8 i = 0;
//
//	for ( i = 0; i < SCOREBALL_MAX; i++)
//	{
//		if ( scoreballs[i].status != BUILDING )
//		{
//			continue;
//		}
//
//		if ( scoreballs[i].counter == scoreballs[i].duration - 1 )
//		{
//			vobject_animation ( scoreballs[i].object, 0 ); //vobject_animation ( scoreballs[i].object, SCOREBALL_STATIC );
//			scoreballs[i].status = VISIBLE;
//
//			// y dibujar el elemento
//			//animation_draw ( scoreballs[i].elemento, _posiciones [i], 0, true, 2,  );
//			level_draw_animation_rp ( scoreballs[i].elemento, _posiciones[SCOREBALL_WEAPON]+1, 1 );
//		}
//
//		++scoreballs[i].counter;
//	}
//
//
//
//
//
////	if ( _actual == SCOREBALL_NONE )
////	{
////		//waitMs(1999);
////		return;
////	}
////
////	if ( ++_frame == _duracion )
////	{
////		_put ( SCOREBALL_STATIC );
////
////		if ( _weapon )
////		{
////			level_draw_animation_rp ( _weapon, _posiciones[SCOREBALL_WEAPON]+1, 1 );
////			_prepare_map ( SCOREBALL_CREATE, SCOREBALL_WEAPON );
////
////			if ( object_is_bigboy ( _enemy ) )
////			{
////				vsprite_set ( 3, (_posiciones[SCOREBALL_ENEMY]+1)*8, 0*8, _enemy );
////			}
////			else
////			{
////				level_draw_animation_rp ( _enemy, _posiciones[SCOREBALL_ENEMY]+1, 1 );
////			}
////
////			_prepare_map ( SCOREBALL_CREATE, SCOREBALL_ENEMY );
////		}
////
////		scoreball_init ();
////	}
//}
//
//
//void scoreball_delete ( u8 which )
//{
//}
//
//
////#include "../inc/include.h"
////
////
////const static u8 _posiciones [ ] = { 0, 3, 7, 14, 20, 26 };
////
////static u8 _frame    = 0;
////static u8 _actual   = SCOREBALL_NONE;
////static u8 _duracion = 0;
////static u8 _weapon   = 0;
////static u8 _enemy    = 0;
////
////
////void _prepare_map ( u8 action, u8 tipo )
////{
////	u8 posicion = _posiciones [ tipo ];
////
////	if ( action == SCOREBALL_CREATE )
////	{
////		VDP_clearTileMapRect ( BPLAN, posicion + 1, 1,  2, 2 );
////	}
////
////	if ( action == SCOREBALL_DELETE )
////	{
////		//VDP_setMapEx()
////	}
////}
////
////
////
////static void _put ( u8 action )
////{
////	if ( action == SCOREBALL_DELETE )
////	{
////		u8 posicion = _posiciones [ _actual ];
////		VDP_clearTileMapRect ( APLAN, posicion, 0,  4, 4 );
////
////		return;
////	}
////
////
////	vobject_reset ( action );
////
////	animation_draw ( action, _posiciones [ _actual ], 0, true, 4, 4 );
////
////	if ( _actual == SCOREBALL_WEAPON )
////	{
////		animation_draw ( action, _posiciones [ SCOREBALL_ENEMY ], 0, true, 4, 4 );
////	}
////}
////
////
////
////static void _prepare_vars ( )
////{
////	if ( _actual != SCOREBALL_WEAPON )
////	{
////		return;
////	}
////
////
////	u8 weapon = player_get_selected();
////
////   if ( weapon == EMPTY )
////   {
//////      level_draw_animation_rp ( EMPTY, _posiciones[SCOREBALL_WEAPON]+2,  1 );
//////      level_draw_animation_rp ( EMPTY, _posiciones[SCOREBALL_ENEMY]+1, 1 );
////      vsprite_set ( 3, 48, -64, EMPTY_SPRITE );
////
////      return;
////   }
////
////
////   u8 enemy;
////
////   if      ( gamestate.ambiente == 0 && weapon == STAFF ) enemy = WILDBOAR;
////	else if ( gamestate.ambiente == 0 && weapon == CROSS ) enemy = TOADSTOOL;
////	else if ( gamestate.ambiente == 0 && weapon == SWORD ) enemy = DARKELF;
////	else if ( gamestate.ambiente == 1 && weapon == STAFF ) enemy = WALRUS;
////	else if ( gamestate.ambiente == 1 && weapon == CROSS ) enemy = ESKIMO;
////	else if ( gamestate.ambiente == 1 && weapon == SWORD ) enemy = WAMPA;
////	else if ( gamestate.ambiente == 2 && weapon == STAFF ) enemy = SCORPIO;
////	else if ( gamestate.ambiente == 2 && weapon == CROSS ) enemy = BEDOUIN;
////	else if ( gamestate.ambiente == 2 && weapon == SWORD ) enemy = MUMMY;
////	else if ( gamestate.ambiente == 3 && weapon == STAFF ) enemy = CANGREJO;
////	else if ( gamestate.ambiente == 3 && weapon == CROSS ) enemy = PIRATA;
////	else if ( gamestate.ambiente == 3 && weapon == SWORD ) enemy = PLESI;
////	else if ( gamestate.ambiente == 4 && weapon == STAFF ) enemy = OGRE;
////	else if ( gamestate.ambiente == 4 && weapon == CROSS ) enemy = EYE;
////	else if ( gamestate.ambiente == 4 && weapon == SWORD ) enemy = DEMON;
////	else return;
////
////	_weapon = weapon;
////	_enemy  = enemy;
////}
////
////
////
////
////void scoreball_init ( )
////{
////	_frame    = 0;
////	_actual   = SCOREBALL_NONE;
////	_duracion = animation_duracion ( SCOREBALL_CREATE );
////	_weapon   = EMPTY;
////	_enemy    = EMPTY;
////
////	//drawUInt(_duracion, 0,0,3);
////}
////
////
////void scoreball_frame ( )
////{
////	if ( _actual == SCOREBALL_NONE )
////	{
////		//waitMs(1999);
////		return;
////	}
////
////	if ( ++_frame == _duracion )
////	{
////		_put ( SCOREBALL_STATIC );
////
////		if ( _weapon )
////		{
////			level_draw_animation_rp ( _weapon, _posiciones[SCOREBALL_WEAPON]+1, 1 );
////			_prepare_map ( SCOREBALL_CREATE, SCOREBALL_WEAPON );
////
////			if ( object_is_bigboy ( _enemy ) )
////			{
////				vsprite_set ( 3, (_posiciones[SCOREBALL_ENEMY]+1)*8, 0*8, _enemy );
////			}
////			else
////			{
////				level_draw_animation_rp ( _enemy, _posiciones[SCOREBALL_ENEMY]+1, 1 );
////			}
////
////			_prepare_map ( SCOREBALL_CREATE, SCOREBALL_ENEMY );
////		}
////
////		scoreball_init ();
////	}
////}
////
////
////void scoreball_add ( u8 type )
////{
//////	if ( _actual != SCOREBALL_NONE )
//////	{
//////
//////	}
//////
//////	if ( _frame )
//////	{
//////		_frame = 0;
//////	}
//////
//////
//////	if ( type == SCOREBALL_NONE )
//////	{
//////		return;
//////	}
////
////	if
////	(
////		type != SCOREBALL_NONE   &&
////		type != SCOREBALL_WEAPON &&
////		type != SCOREBALL_ENEMY  &&
////		type != SCOREBALL_LEVEL  &&
////		type != SCOREBALL_KEY    &&
////		type != SCOREBALL_UNDO
////	)
////	{
////		return;
////	}
////
////	drawUInt( type, 0,0,3);
////
////
////
////	_frame  = 0;
////	_actual = type;
////
////	_put ( SCOREBALL_CREATE );
////	_prepare_vars ( );
////}
////
////
////void scoreball_delete ( u8 type )
////{
////	_frame  = 0;
////	_actual = type;
////
////	_put ( SCOREBALL_DELETE );
////	//_prepare_map ( SCOREBALL_DELETE, _actual );
//////level_draw_animation_rp_4x4 ( SCOREBALL_DELETE, _posiciones[type], 0 );
////}
////
////
