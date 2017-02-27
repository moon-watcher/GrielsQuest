#include "../inc/include.h"


//static u8 _no_pass;
//static u8 _pass_1;
//static u8 _pass_2;
//static u8 _complete;

static u8 _ambients[4] = { };


static const u8 _valores[4][4][2] =
{
	{ {65,81}, {69,85}, {73,89}, {77,50} },
	{ {66,82}, {70,86}, {74,90}, {78,51} },
	{ {67,83}, {71,87}, {75,48}, {79,52} },
	{ {68,84}, {72,88}, {76,49}, {80,53} }
};



static u8   _random_var ( );
static void _random_pos ( u8 indice, u8 *posiciones );
static u8   _search     ( u8 find );



//---------------------------------------------------------------------------------------------------------------------



static u8 _random_var ( )
{
	u8 aux;

	do
	{
		aux = random();
	}
	while (  !between ( aux, 48, 57 )  &&  !between ( aux, 65, 90 )  );

	return aux;
}


static void _random_pos ( u8 indice, u8 *posiciones )
{
	u8 aux;

	while ( 1 )
	{
		aux = random() % 8;

		if
		(
			aux == 0              ||
			aux == 2              ||
			aux == 4              ||
			aux == 7              ||
			aux == posiciones[0]  ||
			aux == posiciones[1]  ||
			aux == posiciones[2]  ||
			aux == posiciones[3]
		)
		{
			continue;
		}

		posiciones[indice] = aux;

		return ;
	}
}


static u8 _search ( u8 find )
{
	u8 j, k;

	for ( j=0; j<4; j++ )
	{
		for ( k=0; k<4; k++ )
		{
			if ( find == _valores[j][k][0] || find == _valores[j][k][1] )
			{
				return _valores[j][k][ random() % 2 ];
			}
		}
	}

	return 0;
}



// ---------------------------------------------------------------------------------------------------------------------------



//
// 65, 86, 75, 53  >--- to --->  "9V9A95K9" or equivalent
//

void password_encode ( u8 stra[], u8 no_pass, u8 pass_1, u8 pass_2, u8 complete )
{
	u8 pos [ 4 ];

	_random_pos ( 0, pos );
	_random_pos ( 1, pos );
	_random_pos ( 2, pos );
	_random_pos ( 3, pos );


	u8 *str =stra;

	str [ 0      ] = _random_var ( );
	str [ 2      ] = _random_var ( );
	str [ 4      ] = _random_var ( );
	str [ 7      ] = _random_var ( );
	str [ pos[0] ] = _search ( no_pass  );
	str [ pos[1] ] = _search ( pass_1   );
	str [ pos[2] ] = _search ( pass_2   );
	str [ pos[3] ] = _search ( complete );


	//VDP_drawText ( str, 0, 0 );
}




//
// "9V9A95K9"  >--- to --->  65, 86, 75, 53
//
void password_decode ( u8 string[] )
{
	u8 chr, i = strlen(string), j, k, l;

	while ( i-- )
	{
		if ( i == 0 || i == 2 || i == 4 || i == 7 )
		{
			continue;
		}


		chr = string[i];

		for ( j=0; j<4; j++ )
		{
			for ( k=0; k<4; k++ )
			{
				for ( l=0; l<2; l++ )
				{
					if ( chr == _valores[j][k][l] )
					{
						_ambients[j] = chr;
					}
				}
			}
		}
	}
}
