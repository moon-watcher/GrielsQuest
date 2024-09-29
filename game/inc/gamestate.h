#pragma once


typedef struct
{
	// parametros de juego
	u8 current_round;    // nivel actual
	s8 current_ambiente; // ambiente actual
	u8 lenguaje;

	// dificultad actual elegida + 1 si supera knightmare
	u8 dificultad;

	// nivel máximo donde se han llegado por cada ambiente
	u8 ambientes[5]; // número de rounds terminados

	bool visito_la_puerta;
	u16 localdev;

	bool nolddor_released_ZoS; // Zooming Secretary MD
   	u8 publisher; // 1: 1985 Alternativo; 2 Play On Retro
}
GAMESTATE;



GAMESTATE gamestate;




void gamestate_init               ( );
bool gamestate_terminado          ( u8 ambiente );
bool gamestate_terminados         ( s8 ambiente, ... );
u16  gamestate_cuantos_terminados ( );
u16  gamestate_get_dificultad     ( );
bool gamestate_go_to_ending       ( u16 state );
bool gamestate_on_medallon        ( );
