
#define FRASES_MAX_CHARS 512

typedef struct
{
	u8  lang;
	u8  grupo;
	u8  cadena [ FRASES_MAX_CHARS ];
}
FRASE;



enum
{
	INGLES = 1,
	ESPANOL
};



void  frases_init ( u8 grupo );
u8   *frases_next ( );
u8   *frases_find ( u8 grupo, u8 numero );
