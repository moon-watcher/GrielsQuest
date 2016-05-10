
typedef struct
{
	// parametros actuales de juego
   u8 current_round; // nivel actual
   s8 ambiente; // ambiente actual
   u8 lenguaje; // ambiente actual

	// dificultad actual elegida
   u8 dificultad;

   // nivel máximo donde se han llegado por cada ambiente
   u8 ambientes[5]; // número de rounds terminados

//   bool terminados[5]; // ambientes terminados

	bool visito_la_puerta;
}
GAMESTATE;



GAMESTATE gamestate;




void gamestate_init       ( );
bool gamestate_terminado  ( u8 ambiente );
bool gamestate_terminados ( s8 ambiente, ... );
u16  gamestate_cuantos_terminados ( );
