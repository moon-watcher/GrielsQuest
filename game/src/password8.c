#include "../inc/include.h"
#include "../inc/genres_externs.h"

const char password_letras [ PWD_HEIGHT ] [ PWD_WIDTH ] =
{
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' },
	{ 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' },
	{ 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', ' ', '<', '[' }
};



void _posiciones ( PASSWORD8 pwd, u8 *pos1, u8 *pos2, u8 *pos3, u8 *pos4, u8 *pos5, u8 *pos6, u8 *pos7 )
{
	const u8 posiciones [ 7 ] [ 7 ] =
	{
		{ 1, 3, 7, 5, 6, 4, 2 },
		{ 4, 2, 5, 3, 7, 6, 1 },
		{ 5, 2, 6, 7, 1, 3, 4 },
		{ 6, 7, 1, 4, 5, 2, 3 },
		{ 7, 5, 3, 6, 4, 1, 2 },
		{ 3, 6, 4, 7, 2, 5, 1 },
		{ 6, 1, 5, 4, 7, 2, 3 }
	};

	u8 aux = pwd [ 0 ] % 7;

	*pos1 = posiciones [ aux ] [ 0 ];
	*pos2 = posiciones [ aux ] [ 1 ];
	*pos3 = posiciones [ aux ] [ 2 ];
	*pos4 = posiciones [ aux ] [ 3 ];
	*pos5 = posiciones [ aux ] [ 4 ];
	*pos6 = posiciones [ aux ] [ 5 ];
	*pos7 = posiciones [ aux ] [ 6 ];
}




static char _rnd ( )
{
	return random() % 26 + PWD8_A_STARTS_AT;
}


static u16 letra_a_numero ( u16 letra, u16 max )
{
	++max;

	return letra % max;
}


static char numero_a_letra ( u16 numero, u16 max )
{
	++max;

	while ( true )
	{
		char letra = _rnd();

		if ( letra % max == numero )
		{
			return letra;
		}
	}

	return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void pwd8_debug ( u16 x, s32 args, ... )
{
	if ( !DEV )
	{
		return;
	}

	va_list ap;
	s32 y = 0;

	va_start ( ap, args );

	while ( args >= 0 )
	{
		drawUInt ( args, x, y++, 2 );
		args = va_arg ( ap, s32 );
	}

	va_end ( ap );
}


bool pwd8_isOk ( PASSWORD8 pwd )
{
	u16  i    = 0;
	bool ret  = false;
	u16  play = 1;


	// que todas sean mayúsculas
	for ( i=0; i<8; i++ )
	{
		if ( pwd[i] < 65 || pwd[i] > 90 )
		{
			return ret;
		}
	}


	u8 pos1, pos2, pos3, pos4, pos5, pos6, pos7;

	_posiciones ( pwd, &pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7 );


	u16 posicion   = pwd [ 0 ] % 7;
	u16 dificultad = letra_a_numero ( pwd[pos2], 3 ); // 0, 1, 2, 3
	u16 aux        = dificultad;

	if ( aux > 2 ) aux = 2;

	u16 ambiente0  = letra_a_numero ( pwd[pos3], level_list [ 0 ] [ aux ].cuantos );
	u16 ambiente1  = letra_a_numero ( pwd[pos4], level_list [ 1 ] [ aux ].cuantos );
	u16 ambiente2  = letra_a_numero ( pwd[pos5], level_list [ 2 ] [ aux ].cuantos );
	u16 ambiente3  = letra_a_numero ( pwd[pos6], level_list [ 3 ] [ aux ].cuantos );
	u16 ambiente4  = letra_a_numero ( pwd[pos7], level_list [ 4 ] [ aux ].cuantos );

	u16 suma       = ( dificultad + ambiente0 + ambiente1 + ambiente2 + ambiente3 + ambiente4 + posicion ) / 3;
	u16 verifica   = ABS ( ( pwd[pos1] - PWD8_A_STARTS_AT ) - suma );



	//
	pwd8_debug ( 3, dificultad, ambiente0, ambiente1, ambiente2, ambiente3, ambiente4, suma, verifica, -1 );


	u8 max_verifica = frases_count ( 5 ) - 1;

	if ( verifica > max_verifica )
	{
		verifica = max_verifica;
	}

	if ( verifica == 0 ) // 0 es que no hay diferencias entre la verificacion y el código
	{
		gamestate.current_ambiente = 0;
		gamestate.current_round    = 0;

		if ( dificultad > 2 )
		{
			gamestate.visito_la_puerta = true;
		}

		gamestate.dificultad   = dificultad;
		gamestate.ambientes[0] = ambiente0;
		gamestate.ambientes[1] = ambiente1;
		gamestate.ambientes[2] = ambiente2;
		gamestate.ambientes[3] = ambiente3;
		gamestate.ambientes[4] = ambiente4;

		play = 4;
		ret  = true;

		pwd8_debug ( 35, gamestate.dificultad, gamestate.ambientes[0], gamestate.ambientes[1], gamestate.ambientes[2], gamestate.ambientes[3], gamestate.ambientes[4], -1 );
	}

	u8 *string = frases_find ( 5, verifica );

	SYS_disableInts();
	VDP_clearTextLine ( 25 );
	SYS_enableInts();
	TEXT_drawText ( string, 20 - strlen ( string ) / 2, 25 );

	psglist_play ( play );

	if ( ret )
	{
		waitSc(1);
	}


	return ret;
}

void pwd8_generate ( PASSWORD8 letras )
{
	setRandomSeed(vtimer);

	letras [ 0 ] = _rnd();
	letras [ 1 ] = '-';
	letras [ 2 ] = '-';
	letras [ 3 ] = '-';
	letras [ 4 ] = '-';
	letras [ 5 ] = '-';
	letras [ 6 ] = '-';
	letras [ 7 ] = '-';
	letras [ 8 ] = '\0';

	u8 pos1, pos2, pos3, pos4, pos5, pos6, pos7;

	_posiciones ( letras, &pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7 );

	u8 aux = gamestate_get_dificultad ( );

	letras [ pos2 ] = numero_a_letra ( gamestate.dificultad, 3 ); // 0, 1, 2, 3
	letras [ pos3 ] = numero_a_letra ( gamestate.ambientes[0], level_list [ 0 ] [ aux ].cuantos );
	letras [ pos4 ] = numero_a_letra ( gamestate.ambientes[1], level_list [ 1 ] [ aux ].cuantos );
	letras [ pos5 ] = numero_a_letra ( gamestate.ambientes[2], level_list [ 2 ] [ aux ].cuantos );
	letras [ pos6 ] = numero_a_letra ( gamestate.ambientes[3], level_list [ 3 ] [ aux ].cuantos );
	letras [ pos7 ] = numero_a_letra ( gamestate.ambientes[4], level_list [ 4 ] [ aux ].cuantos );

	u16 posicion    = letras [ 0 ] % 7;
	u16 suma        = ( gamestate.dificultad + gamestate.ambientes[0] + gamestate.ambientes[1] + gamestate.ambientes[2] + gamestate.ambientes[3] + gamestate.ambientes[4] + posicion ) / 3;

	letras [ pos1 ] = suma + PWD8_A_STARTS_AT;

	//bigtext_drawTile ( (u8*) letras, 12, 12, 0 );
	//pwd8_isOk ( letras );
}
