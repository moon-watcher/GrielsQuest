#include "../inc/include.h"


const static FRASE _list [ ] =
{
    (FRASE) { 99, 99, "" },

    #include "frases_english.txt"
    #include "frases_spanish.txt"
    #include "frases_italian.txt"
    #include "frases_french.txt"

    (FRASE) {  0,  0, "" }, // No quitar
};




static u16 _next;
static u16 _grupo;
static u8  _string [ FRASES_MAX_CHARS + 1 ];



static void _prepare_string ( u8 *str )
{
	u16 i = 0;
	u16 j = 0;
	u8  chr;

	strclr ( _string );

	while ( ( chr = str[i++] ) )
	{
//	    //
//	    // debug special chars
//	    // DON'T DELETE
//	    //
//	    VDP_init();
//	    u8 write[2] = { chr, '\0' };
//	    drawUInt( chr, 0, 0, 5 );
//	    VDP_drawText ( write, 10, 0 );
//	    waitSc(1);
//	    //
//	    //

        _string[j] = chr;

        switch ( _string[j] )
        {
            case 250: _string[j] = 31;  break; // ú
            case 243: _string[j] = 30;  break; // ó
            case 241: _string[j] = 29;  break; // ñ
            case 237: _string[j] = 28;  break; // í
            case 233: _string[j] = 27;  break; // é
            case 225: _string[j] = 26;  break; // á
            case 218: _string[j] = 25;  break; // Ú
            case 211: _string[j] = 24;  break; // Ó
            case 209: _string[j] = 23;  break; // Ñ
            case 205: _string[j] = 22;  break; // Í
            case 201: _string[j] = 21;  break; // É
            case 193: _string[j] = 20;  break; // Á
            case 191: _string[j] = 19;  break; // ¿
            case 161: _string[j] = 18;  break; // ¡
            case 249: _string[j] = 17;  break; // ù
            case 242: _string[j] = 16;  break; // ò
            case 231: _string[j] = 15;  break; // ç
            case 236: _string[j] = 14;  break; // ì
            case 232: _string[j] = 13;  break; // è
            case 224: _string[j] = 12;  break; // à
            case 217: _string[j] = 11;  break; // Ù
            case 210: _string[j] = 10;  break; // Ò
            case 199: _string[j] =  9;  break; // Ç
            case 204: _string[j] =  8;  break; // Ì
            case 200: _string[j] =  7;  break; // È
            case 192: _string[j] =  6;  break; // À
        }

        ++j;
	}

	_string[j] = '\0';
}




/////////////////////////////////////////////////////////////////////////////////////////////////////



void frases_init ( u16 grupo )
{
	_next  = 0;
	_grupo = grupo ;
}



u8 *frases_next ( )
{
	FRASE *f ;

	do
	{
		f = (FRASE*) & _list [ _next++ ];

		if ( f->lang == gamestate.lenguaje  &&  f->grupo == _grupo )
		{
			break;
		}
	}
	while ( f->lang );


	_prepare_string ( f->cadena ) ;

	return _string;
}



u8 *frases_find ( u16 grupo, u16 numero )
{
	u16 i        = 0;
	u16 contador = 0;

	FRASE *f ;

	do
	{
		f = (FRASE*) & _list [ i++ ];

		if ( f->lang == gamestate.lenguaje  &&  f->grupo == grupo )
		{
			if ( numero == contador++ )
			{
				break;
			}
		}
	}
	while ( f->lang );


	_prepare_string ( f->cadena ) ;

	return _string;
}



u16 frases_count ( u16 grupo )
{
	u16 i        = 0;
	u16 contador = 0;

	FRASE *f ;

	do
	{
		f = (FRASE*) & _list [ i++ ];

		if ( f->lang == gamestate.lenguaje  &&  f->grupo == grupo )
		{
			++contador;
		}
	}
	while ( f->lang );

	return contador;
}


u8 *prepare_string ( u8 *str )
{
    _prepare_string ( str );

    return (u8*) _string;
}
