#include "../inc/include.h"

static const FRASE _list[] = {
	(FRASE){99, 99, ""},
#include "../../frases/english.txt"
#include "../../frases/spanish.txt"
#include "../../frases/italian.txt"
#include "../../frases/french.txt"
#include "../../frases/catalan.txt"
#include "../../frases/finnish.txt"
#include "../../frases/galego.txt"
#include "../../frases/portuguese.txt"
	(FRASE){0, 0, ""}, // No quitar
};

static u16 _next;
static u16 _grupo;

void frases_init(u16 grupo)
{
	_next = 0;
	_grupo = grupo;
}

u8 *frases_next()
{
	FRASE *f;

	do {
		f = (FRASE *)&_list[_next++];

		if (f->lang == gamestate.lenguaje && f->grupo == _grupo)
			break;

	} while (f->lang);

	return f->cadena;
}

u8 *frases_find(u16 grupo, u16 numero)
{
	u16 i = 0;
	u16 contador = 0;
	FRASE *f;

	do {
		f = (FRASE *)&_list[i++];

		if (f->lang == gamestate.lenguaje && f->grupo == grupo && numero == contador++)
			break;

	} while (f->lang);

	return f->cadena;
}

u16 frases_count(u16 grupo)
{
	u16 i = 0;
	u16 contador = 0;
	FRASE *f;

	do {
		f = (FRASE *)&_list[i++];

		if (f->lang == gamestate.lenguaje && f->grupo == grupo)
			++contador;
			
	} while (f->lang);

	return contador;
}