#include "../inc/include.h"



void gamestate_init ( )
{
	gamestate.current_round    = 0;
	gamestate.current_ambiente = 0;
	gamestate.lenguaje         = SPANISH; // ENGLISH;

	gamestate.dificultad       = 0;
	gamestate.ambientes [ 0 ]  = 0;
	gamestate.ambientes [ 1 ]  = 0;
	gamestate.ambientes [ 2 ]  = 0;
	gamestate.ambientes [ 3 ]  = 0;
	gamestate.ambientes [ 4 ]  = 0;

	gamestate.visito_la_puerta = false;
}



bool gamestate_terminado ( u8 ambiente )
{
	return level_list [ ambiente ] [ gamestate_get_dificultad ( ) ].cuantos == gamestate.ambientes [ ambiente ];
}



bool gamestate_terminados ( s8 ambiente, ... )
{
	va_list ap;

	va_start ( ap, ambiente);

	while ( ambiente >= 0 )
	{
		if ( !gamestate_terminado ( ambiente ) )
		{
			return false;
		}

		ambiente = va_arg ( ap, int );
	}

	va_end ( ap );

	return true;
}


u16 gamestate_cuantos_terminados ()
{
	u16 cuantos = 0;

	if ( gamestate_terminado(0) ) ++cuantos;
	if ( gamestate_terminado(1) ) ++cuantos;
	if ( gamestate_terminado(2) ) ++cuantos;
	if ( gamestate_terminado(3) ) ++cuantos;
	if ( gamestate_terminado(4) ) ++cuantos;

	return cuantos;
}


u16 gamestate_get_dificultad ( )
{
	u16 dificultad = gamestate.dificultad;

	if ( dificultad > 2 )
	{
		dificultad = 2;
	}

	return dificultad;
}


bool gamestate_go_to_ending ( u16 state )
{
	return (bool)
	(
		state                          == LEVEL_COMPLETED  &&
		gamestate_cuantos_terminados() == 5                &&
		gamestate.current_ambiente     == 4
	);
}


bool gamestate_on_medallon ( )
{
	if ( DEV )
	{
		return false;
	}

	return (bool) ( level_list [ (u8)gamestate.current_ambiente ] [ gamestate_get_dificultad ( ) ].cuantos == ( gamestate.current_round+1 ));
}
