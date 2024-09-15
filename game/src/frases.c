#include "../inc/include.h"


static const FRASE _list [ ] =
{
    (FRASE) { 99, 99, "" },

    #include "frases_english.txt"
    #include "frases_spanish.txt"
    #include "frases_italian.txt"
    #include "frases_french.txt"
    #include "frases_catalan.txt"
    #include "frases_finnish.txt"
    #include "frases_galego.txt"
    #include "frases_portuguese.txt"

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
	    //
	    // debug special chars
	    // DON'T DELETE
	    //
	    //VDP_init();
	    //if ( devu0 )
        //{
//	    u8 write[2] = { chr, '\0' };
//	    drawUInt( chr, 0, devu0, 5 );
//	    VDP_drawText ( write, 10, devu0++ );
//	    //waitSc(1);
	    //}
	    //
	    //


        _string[j] = chr;

        switch ( _string[j] )
        {
            case 250: _string[j] =  31;  break; // �
            case 243: _string[j] =  30;  break; // �
            case 241: _string[j] =  29;  break; // �
            case 237: _string[j] =  28;  break; // �
            case 233: _string[j] =  27;  break; // �
            case 225: _string[j] =  26;  break; // �
            case 218: _string[j] =  25;  break; // �
            case 211: _string[j] =  24;  break; // �
            case 209: _string[j] =  23;  break; // �
            case 205: _string[j] =  22;  break; // �
            case 201: _string[j] =  21;  break; // �
            case 193: _string[j] =  20;  break; // �
            case 191: _string[j] =  19;  break; // �
            case 161: _string[j] =  18;  break; // �
            case 249: _string[j] =  17;  break; // �
            case 242: _string[j] =  16;  break; // �
            case 231: _string[j] =  15;  break; // �
            case 236: _string[j] =  14;  break; // �
            case 232: _string[j] =  13;  break; // �
            case 224: _string[j] =  12;  break; // �
            case 217: _string[j] =  11;  break; // �
            case 210: _string[j] =  10;  break; // �
            case 199: _string[j] =   9;  break; // �
            case 204: _string[j] =   8;  break; // �
            case 200: _string[j] =   7;  break; // �
            case 192: _string[j] =   6;  break; // �
            case 251: _string[j] =   3;  break; // �
            case 244: _string[j] =   2;  break; // �
            case 238: _string[j] =   1;  break; // �
            case 234: _string[j] = 255;  break; // �
            case 226: _string[j] = 254;  break; // �
            case 194: _string[j] = 253;  break; // �
            case 212: _string[j] = 252;  break; // �
            case 206: _string[j] = 250;  break; // �
            case 202: _string[j] = 249;  break; // �
            case 229: _string[j] = 248;  break; // �
            case 196: _string[j] = 246;  break; // �
            case 228: _string[j] = 247;  break; // �
            case 214: _string[j] =   4;  break; // �
            case 246: _string[j] =   5;  break; // �
            case 197: _string[j] = 248;  break; // �
            case 195: _string[j] = 232;  break; // �
            case 227: _string[j] = 233;  break; // �

// for ���� ���� ---> portuguese
        }

        // Exception. Weird collision :?
        if ( gamestate.lenguaje == FINNISH )
        {
            if ( chr == 229 )
            {
                _string[j] = 254; // �
            }
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
