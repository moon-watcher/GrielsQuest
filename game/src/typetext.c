#include "../inc/include.h"
#include "../inc/colores_textos.h"

#define EOF '\0'
#define SPACE 32	  // ' '
#define SOFTBREAK 172 // '?' breaks a line (with exceptions)
#define HARDBREAK 126 // '~' breaks a line
#define NEXT 124	  // '|' new page
#define SEPARATOR ':'

static struct typetext_info tt;

#define cmd(x) (strcmp(tt.command, (x)) == 0)

static u16 _speed = 0;
static u16 _color[2] = {};

static void _inc_y();
static void _inc_x();
static void _reset_pal();
static u16 _reset_area(bool wait);
static u16 _wait(u16 wait);
static u16 _buid_command();
static void _assign_value(u8 *command, u8 nb, u8 *string);

static void _assign_value(u8 *command, u8 nb, u8 *string)
{
	u16 i = 0;
	u16 start = 0;

	if (nb > 0)
	{
		while (1)
		{
			u8 chr = command[start++];

			if ((chr == EOF) || (chr == SEPARATOR && --nb == 0))
			{
				break;
			}
		}
	}

	while (1)
	{
		u8 chr = command[i + start];

		if (chr == EOF || chr == SEPARATOR)
		{
			break;
		}

		string[i++] = chr;
	}

	string[++i] = EOF;
}

static u16 _buid_command()
{
	u16 ret = 0;

	if (tt.cmd_inc >= 0)
	{
		if (tt.chr == ' ' || tt.chr == '|' || tt.chr == '\0')
		{
			ret = 2;

			u8 command0[20] = {};
			u8 command1[10] = {};
			u8 command2[10] = {};

			tt.command[(u8)tt.cmd_inc] = '\0';

			_assign_value(tt.command, 0, command0);
			_assign_value(tt.command, 1, command1);
			_assign_value(tt.command, 2, command2);

			strcpy(tt.command, command0);
			tt.cmd_value[0] = my_strtol(command1);
			tt.cmd_value[1] = my_strtol(command2);
			tt.cmd_inc = -1;
		}
		else
		{
			ret = 1;

			tt.command[(u8)tt.cmd_inc++] = tt.chr;
		}
	}
	else if (tt.chr == '|')
	{
		ret = 1;

		tt.cmd_inc = 0;
		tt.command[0] = '\0';
		tt.cmd_value[0] = 0;
		tt.cmd_value[1] = 0;
	}

	return ret;
}

static void _inc_x()
{
	tt.vx += tt.inc_char;

	if (tt.word > 0)
	{
		--tt.word;
	}

	if (tt.vx + tt.word >= tt.width)
	{
		_inc_y();
	}
}

static void _inc_y()
{
	tt.vx = 0;
	tt.vy += tt.inc_line;

	if (tt.vy >= tt.height)
	{
		_reset_area(true);
	}
}

static void _reset_pal()
{
	if (tt.reset_pal)
	{
		PAL_waitFadeCompletion();
		PAL_setColor(16 * VDP_getTextPalette() + 1, tt.color[0]);
		PAL_setColor(16 * VDP_getTextPalette() + 2, tt.color[1]);
	}
}

static u16 _reset_area(bool wait)
{
	u16 ret = 0;

	if (wait)
	{
		ret = _wait(tt.wait);
	}

	typetext_clear();
	_reset_pal();

	tt.vx = 0;
	tt.vy = 0;
	tt.go_next = false;

	return ret;
}

static u16 _wait(u16 wait)
{
	if (tt.go_next)
	{
		return 0;
	}

	while (wait--)
	{
		JoyReader_update();

		if (tt.buttons && joy1_pressed)
		{
			u16 ret = 0;

			     if ((tt.buttons & BUTTON_A    ) && joy1_pressed_a    ) ret = BUTTON_A;
			else if ((tt.buttons & BUTTON_B    ) && joy1_pressed_b    ) ret = BUTTON_B;
			else if ((tt.buttons & BUTTON_C    ) && joy1_pressed_c    ) ret = BUTTON_C;
			else if ((tt.buttons & BUTTON_START) && joy1_pressed_start) ret = BUTTON_START;

			return ret;
		}

		SYS_doVBlankProcess();
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void typetext_init()
{
	tt.x = 1;
	tt.y = 20;
	tt.width = 38;
	tt.height = 7;

	tt.inc_line = 2;
	tt.inc_char = 1;

	tt.speed = 2; // Hz
	tt.wait = 3 * getHz();
	tt.color[0] = 0;
	tt.color[1] = 0;
	tt.fade_out = 10; // en pasos
	tt.buttons = (BUTTON_A | BUTTON_B | BUTTON_C | BUTTON_START);

	tt.go_next = false;

	tt.word = 0;
	tt.vx = 0;
	tt.vy = 0;

	tt.chr = '\0';
	tt.reset_pal = true;
	tt.reset_area_at_end = true;
}

struct typetext_info *tt_get()
{
	return &tt;
}

void typetext_clear()
{
	if (tt.reset_pal)
	{
		PAL_fadeOut(1, 2, tt.fade_out, 1);
	}

	waitHz(tt.fade_out + 1);

	SYS_disableInts();
	VDP_fillTileMapRect(VDP_getTextPlane(), 0, tt.x, tt.y, tt.width, tt.height);
	SYS_enableInts();
}

// Used by tt_write macro
u16 typetext_write_init(u16 indice, u8 *cadena)
{
	tt.cmd_inc = -1;

	tt.vx = 0;
	tt.vy = 0;
	tt.word = 0;

	tt.color[0] = font_palette.data[indice + 0];
	tt.color[1] = font_palette.data[indice + 1];
	tt.go_next = false;

	tt.chr = '\0';

	SYS_disableInts();
	VDP_fillTileMapRect(VDP_getTextPlane(), 0, tt.x, tt.y, tt.width, tt.height);
	SYS_enableInts();

	_speed = tt.speed;
	_color[0] = tt.color[0];
	_color[1] = tt.color[1];

	_reset_pal();

	return strlen(cadena) + 1;
}

// Used by tt_write macro
u16 typetext_write_process(u16 i, u8 *cadena)
{
	tt.chr = cadena[i];

	u16 cmd_stat = _buid_command();

	if (cmd_stat == 1)
	{
		return 0;
	}

	else if (cmd_stat == 2)
	{

		if (cmd("WAIT"))
		{
			return _wait(tt.cmd_value[0] ? tt.cmd_value[0] : tt.wait);
		}

		else if (cmd("QUIT"))
		{
			//
		}

		else if (cmd("BREAK"))
		{
			// Salto de linea forzado o bien s�lo lo hace si x > 0
			if (tt.cmd_value[0] || tt.vx > 0)
			{
				_inc_y();
			}

			return 0; // continue
		}

		else if (cmd("SPEED"))
		{
			tt.speed = tt.cmd_value[0] ? tt.cmd_value[0] : _speed;
		}

		else if (cmd("COLOR"))
		{
			tt.color[0] = tt.cmd_value[0] ? tt.cmd_value[0] : _color[0];
			tt.color[1] = tt.cmd_value[0] ? tt.cmd_value[0] : _color[1];

			PAL_setColor(16 * VDP_getTextPalette() + 1, tt.color[0]);
			PAL_setColor(16 * VDP_getTextPalette() + 2, tt.color[1]);
		}

		else if (cmd("CLEAR"))
		{
			_reset_area(false);

			return 0; // continue
		}

		else if (cmd("WCLEAR"))
		{
			u16 btn = 0;
			u16 wait = tt.wait;

			if (tt.cmd_value[0])
			{
				wait = tt.cmd_value[0];
			}

			if (wait)
			{
				btn = _wait(wait); // este falla, hace que se quede cogado porque el valor debe ser alt�simo
			}

			_reset_area(false);

			return btn;
		}

		else if (cmd("WBREAK"))
		{
			u16 wait = tt.cmd_value[0];

			u16 w = _wait(wait ? wait : getHz());

			// Salto de linea forzado o bien s�lo lo hace si x > 0
			if (tt.cmd_value[1] || tt.vx > 0)
			{
				_inc_y();
			}

			return w; // continue
		}
	}

	else
	{
		// Salto de pagina o �ltimo caracter
		if (tt.chr == EOF)
		{
			if (tt.reset_area_at_end)
			{
				return _reset_area(true);
			}

			return 0;
		}

		else if (tt.chr == SPACE || tt.vx == 0)
		{
			// Salta los espacios en blanco de la primera posicion
			if (tt.chr == SPACE && tt.vx == 0)
			{
				return 0; // continue
			}

			// Cuenta las letras de �sta palabra
			tt.word = 0;

			while (cadena[i + tt.word + 1] != SPACE && cadena[i + tt.word + 1] != EOF)
			{
				++tt.word;
			}

			if (tt.vx == 0)
			{
				++tt.word;
			}
		}
	}

	// Escribe el caracter
	if (tt.go_next == false && tt.chr != SPACE)
	{
		u8 write[2] = {tt.chr, EOF};

		TEXT_drawText(write, tt.x + tt.vx, tt.y + tt.vy);
	}

	// Incrementa posiciones
	_inc_x();
	// psglist_play(3); // 3 es foot

	// espera
	return _wait(tt.speed);
}
