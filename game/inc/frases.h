#pragma once


#define FRASES_MAX_CHARS 512

typedef struct
{
	u8  lang;
	u8  grupo;
	char *cadena;
}
FRASE;


void  frases_init    ( u16 grupo );
u8   *frases_next    ( );
u8   *frases_find    ( u16 grupo, u16 numero );
u16   frases_count   ( u16 grupo );
u8   *prepare_string ( u8 *str );


u8 *GRIEL_frases_next( ); 