#include "../inc/include.h"
#include "../inc/colores_textos.h"


#define EOF         '\0'
#define SPACE        32  // ' '
#define SOFTBREAK	  172  // '�' breaks a line (with exceptions)
#define HARDBREAK	  126  // '~' breaks a line
#define NEXT	     124  // '|' new page
#define SEPARATOR   ':'


static struct typetext_info tt_info;


#define cmd(x)  ( strcmp ( tt_info.command, (x) ) == 0 )



static u16 _speed = 0;
static u16 _color[2] = { };



static void _inc_y        ( );
static void _inc_x        ( );
static void _reset_pal    ( );
static u16  _reset_area   ( bool wait );
static u16  _wait         ( u16 wait );
static u16  _buid_command ( );
static void _assign_value ( u8 *command, u8 nb, u8 *string );




static void _assign_value ( u8 *command, u8 nb, u8 *string )
{
	u16 i = 0;
	u16 start = 0;

	if ( nb > 0 )
	{
		while ( 1 )
		{
			u8 chr = command [ start++ ];

			if ( ( chr == EOF )  ||  ( chr == SEPARATOR  &&  --nb == 0  )  )
			{
				break;
			}
		}
	}

	while ( 1 )
	{
		u8 chr = command [ i + start ];

		if ( chr == EOF || chr == SEPARATOR )
		{
			break;
		}

		string [ i++ ] = chr;
	}

	string [ ++i ] = EOF;
}


static u16 _buid_command ( )
{
	u16 ret = 0;

	if ( tt_info.cmd_inc >= 0 )
	{
		if (  tt_info.chr == ' '  ||  tt_info.chr == '|'  ||  tt_info.chr == '\0'  )
		{
			ret = 2;

			u8 command0 [ 20 ] = { };
			u8 command1 [ 10 ] = { };
			u8 command2 [ 10 ] = { };

			tt_info.command [ (u8) tt_info.cmd_inc ] = '\0';

			_assign_value ( tt_info.command, 0, command0 );
			_assign_value ( tt_info.command, 1, command1 );
			_assign_value ( tt_info.command, 2, command2 );

			strcpy ( tt_info.command, command0 );
			tt_info.cmd_value [ 0 ] = my_strtol ( command1 );
			tt_info.cmd_value [ 1 ] = my_strtol ( command2 );
			tt_info.cmd_inc = -1;
		}
		else
		{
			ret = 1;

			tt_info.command [ (u8) tt_info.cmd_inc ++ ] = tt_info.chr;
		}
	}
	else if ( tt_info.chr == '|' )
	{
		ret = 1;

		tt_info.cmd_inc      = 0;
		tt_info.command[0]   = '\0';
		tt_info.cmd_value[0] = 0;
		tt_info.cmd_value[1] = 0;
	}

	return ret;
}


static void _inc_x ( )
{
	tt_info.vx += tt_info.inc_char;

	if ( tt_info.word > 0 )
	{
		--tt_info.word;
	}

	if ( tt_info.vx + tt_info.word >= tt_info.width )
	{
		_inc_y () ;
	}
}


static void _inc_y ( )
{
	tt_info.vx  = 0;
	tt_info.vy += tt_info.inc_line;

	if ( tt_info.vy >= tt_info.height )
	{
		_reset_area(true);
	}
}


static void _reset_pal ( )
{
	if ( tt_info.reset_pal )
	{
		PAL_waitFadeCompletion ( );
		PAL_setColor ( 16 * VDP_getTextPalette() + 1, tt_info.color[0] );
		PAL_setColor ( 16 * VDP_getTextPalette() + 2, tt_info.color[1] );
	}
}


static u16 _reset_area ( bool wait )
{
	u16 ret = 0;

	if ( wait )
	{
		ret = _wait ( tt_info.wait );
	}

	tt_clear ( );
	_reset_pal ( );

	tt_info.vx = 0;
	tt_info.vy = 0;
	tt_info.go_next = false;

	return ret;
}

static u16 _wait(u16 wait)
{
	if (tt_info.go_next)
	{
		return 0;
	}

	while (wait--)
	{
		JoyReader_update();

		if (tt_info.buttons && joy1_pressed)
		{
			u16 ret = 0;

			     if ((tt_info.buttons & BUTTON_A    ) && joy1_pressed_a    ) ret = BUTTON_A;
			else if ((tt_info.buttons & BUTTON_B    ) && joy1_pressed_b    ) ret = BUTTON_B;
			else if ((tt_info.buttons & BUTTON_C    ) && joy1_pressed_c    ) ret = BUTTON_C;
			else if ((tt_info.buttons & BUTTON_START) && joy1_pressed_start) ret = BUTTON_START;

			return ret;
		}

		SYS_doVBlankProcess();
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void tt_init ( )
{
	tt_info.x         =  1;
	tt_info.y         = 20;
	tt_info.width     = 38;
	tt_info.height    =  7;

	tt_info.inc_line  =  2;
	tt_info.inc_char  =  1;

	tt_info.speed     =  2;  // Hz
	tt_info.wait      =  3 * getHz();
	tt_info.color[0]  =  0;
	tt_info.color[1]  =  0;
	tt_info.fade_out  = 10; // en pasos
	tt_info.buttons   =  ( BUTTON_A | BUTTON_B | BUTTON_C | BUTTON_START );

	tt_info.go_next      =  false;

	tt_info.word      =  0;
	tt_info.vx        =  0;
	tt_info.vy        =  0;

	tt_info.chr       = '\0';
	tt_info.reset_pal = true;
	tt_info.reset_area_at_end = true;
}


struct typetext_info *tt_get()
{
	return &tt_info;
}


void tt_clear ( )
{
	if ( tt_info.reset_pal )
	{
		PAL_fadeOut ( 1, 2,  tt_info.fade_out, 1 );
	}

	waitHz(tt_info.fade_out+1);

    SYS_disableInts();
	VDP_fillTileMapRect  (  VDP_getTextPlane(),  0,  tt_info.x,  tt_info.y,  tt_info.width,  tt_info.height );
	SYS_enableInts();
}



// Used by tt_write macro
u16 tt_write_init ( u16 indice, u8 *cadena )
{
	tt_info.cmd_inc  = -1;

	tt_info.vx       = 0;
	tt_info.vy       = 0;
	tt_info.word     = 0;

	tt_info.color[0] = ct_color(indice,0);
	tt_info.color[1] = ct_color(indice,1);
	tt_info.go_next     = false;

	tt_info.chr      = '\0';


	SYS_disableInts();
	VDP_fillTileMapRect  (  VDP_getTextPlane(),  0,  tt_info.x,  tt_info.y,  tt_info.width,  tt_info.height );
	SYS_enableInts();

	_speed           = tt_info.speed;
	_color[0]        = tt_info.color[0];
	_color[1]        = tt_info.color[1];

	_reset_pal ( );

	return strlen ( cadena ) + 1;
}





// Used by tt_write macro
u16 tt_write_process ( u16 i, u8 *cadena )
{
	tt_info.chr = cadena [ i ];

	u16 cmd_stat = _buid_command ( );



	if ( cmd_stat == 1 )
	{
		return 0;
	}

	else if ( cmd_stat == 2 )
	{

		if ( cmd("WAIT") )
		{
			return _wait ( tt_info.cmd_value[0] ? tt_info.cmd_value[0] : tt_info.wait );
		}

		else if ( cmd("QUIT") )
		{
			//
		}

		else if ( cmd("BREAK") )
		{
			// Salto de linea forzado o bien s�lo lo hace si x > 0
			if ( tt_info.cmd_value[0] || tt_info.vx > 0 )
			{
				_inc_y () ;
			}

			return 0; // continue
		}

		else if ( cmd("SPEED") )
		{
			tt_info.speed = tt_info.cmd_value[0] ? tt_info.cmd_value[0] : _speed;
		}

		else if ( cmd("COLOR") )
		{
			tt_info.color[0] = tt_info.cmd_value[0] ? tt_info.cmd_value[0] : _color[0];
			tt_info.color[1] = tt_info.cmd_value[0] ? tt_info.cmd_value[0] : _color[1];

			PAL_setColor ( 16 * VDP_getTextPalette() + 1, tt_info.color[0] );
			PAL_setColor ( 16 * VDP_getTextPalette() + 2, tt_info.color[1] );
		}

		else if ( cmd("CLEAR") )
		{
			_reset_area ( false );

			return 0; // continue
		}

		else if ( cmd("WCLEAR") )
		{
			u16 btn  = 0;
			u16 wait = tt_info.wait;

			if ( tt_info.cmd_value[0] )
         {
            wait = tt_info.cmd_value[0];
         }

			if ( wait )
			{
				btn = _wait ( wait ); // este falla, hace que se quede cogado porque el valor debe ser alt�simo
			}

         _reset_area ( false );

         return btn;
		}

		else if ( cmd("WBREAK") )
		{
			u16 wait = tt_info.cmd_value[0];

			u16 w = _wait ( wait ? wait : getHz() );

			// Salto de linea forzado o bien s�lo lo hace si x > 0
			if ( tt_info.cmd_value[1] || tt_info.vx > 0 )
			{
            _inc_y () ;
			}

			return w; // continue
		}
	}

	else
	{
		// Salto de pagina o �ltimo caracter
		if ( tt_info.chr == EOF  )
		{
			if ( tt_info.reset_area_at_end )
			{
				return _reset_area ( true );
			}

			return 0;
		}

		else if ( tt_info.chr == SPACE  ||  tt_info.vx == 0 )
		{
			// Salta los espacios en blanco de la primera posicion
			if ( tt_info.chr == SPACE  &&  tt_info.vx == 0 )
			{
				return 0; // continue
			}

			// Cuenta las letras de �sta palabra
			tt_info.word = 0;

			while ( cadena [ i + tt_info.word + 1 ] != SPACE  &&  cadena [ i + tt_info.word + 1 ] != EOF )
			{
				++tt_info.word;
			}

			if ( tt_info.vx == 0 )
			{
				++tt_info.word;
			}
		}
	}





	// Escribe el caracter
	if ( tt_info.go_next == false  &&  tt_info.chr != SPACE )
	{
		u8 write[2] = { tt_info.chr, EOF };

		GRIEL_drawText ( write,  tt_info.x + tt_info.vx,  tt_info.y + tt_info.vy );
	}

	// Incrementa posiciones
	_inc_x ( );
	//psglist_play(3); // 3 es foot


	// espera
	return _wait ( tt_info.speed );
}
