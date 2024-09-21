#include "../../inc/include.h"

// disclaimer.c by Jack Nolddor

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

#define TEXTDISCLAIMER_FADESTEPS 8
#define TEXTDISCLAIMER_NUMCOLORS 3

#define DISCLAIMERBG_FADESTEPS 7
#define DISCLAIMERBG_NUMCOLORS 12

#define DISCLAIMERLOGO_FADESTEPS 8
#define DISCLAIMERLOGO_NUMCOLORS 13

#define DISCLAIMERLOGOLED_FADESTEPS 12
#define DISCLAIMERLOGOLED_NUMCOLORS 6

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

static const u16 textDisclaimerFadeColors[TEXTDISCLAIMER_FADESTEPS][TEXTDISCLAIMER_NUMCOLORS] = {
	{0x0000, 0x0000, 0x0000},
	{0x0222, 0x0222, 0x0222},
	{0x0444, 0x0444, 0x0444},
	{0x0666, 0x0666, 0x0666},
	{0x0888, 0x0888, 0x0888},
	{0x0AAA, 0x0AAA, 0x0AAA},
	{0x0CCC, 0x0CCC, 0x0AAA},
	{0x0EEE, 0x0CCC, 0x0AAA}};

static const u16 disclaimerBGFadeColors[DISCLAIMERBG_FADESTEPS][DISCLAIMERBG_NUMCOLORS] = {
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0040, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0060, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000, 0x0006, 0x0004, 0x0002, 0x0000, 0x0000, 0x0000},
	{0x0080, 0x0060, 0x0040, 0x0020, 0x0000, 0x0000, 0x0008, 0x0006, 0x0004, 0x0002, 0x0000, 0x0000},
	{0x00A0, 0x0080, 0x0060, 0x0040, 0x0020, 0x0000, 0x000A, 0x0008, 0x0006, 0x0004, 0x0002, 0x0000},
	{0x00C0, 0x00A0, 0x0080, 0x0060, 0x0040, 0x0020, 0x000C, 0x000A, 0x0008, 0x0006, 0x0004, 0x0002}};

static const u16 disclaimerLogoFadeColors[DISCLAIMERLOGO_FADESTEPS][DISCLAIMERLOGO_NUMCOLORS] = {
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x000A, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00A0, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x000C, 0x000A, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x00C0, 0x00A0, 0x0080, 0x0000, 0x0000, 0x0000},
	{0x000E, 0x000C, 0x000A, 0x0008, 0x0000, 0x0000, 0x0000, 0x00E0, 0x00C0, 0x00A0, 0x0080, 0x0000, 0x0000},
	{0x022E, 0x000E, 0x000C, 0x000A, 0x0008, 0x0000, 0x0000, 0x04E4, 0x00E0, 0x00C0, 0x00A0, 0x0080, 0x0000},
	{0x044E, 0x022E, 0x000E, 0x000C, 0x000A, 0x0008, 0x0000, 0x06E6, 0x04E4, 0x00E0, 0x00C0, 0x00A0, 0x0080},
	{0x066E, 0x044E, 0x022E, 0x000E, 0x000C, 0x000A, 0x0008, 0x06E6, 0x04E4, 0x00E0, 0x00C0, 0x00A0, 0x0080}};

static const u16 disclaimerLogoLedFadeColors[DISCLAIMERLOGOLED_FADESTEPS][DISCLAIMERLOGOLED_NUMCOLORS] = {
	{0x08E8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x06E6, 0x08E8, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x04E4, 0x06E6, 0x08E8, 0x0000, 0x0000, 0x0000},
	{0x00E0, 0x04E4, 0x06E6, 0x08E8, 0x0000, 0x0000},
	{0x00C0, 0x00E0, 0x04E4, 0x06E6, 0x08E8, 0x0000},
	{0x00A0, 0x00C0, 0x00E0, 0x04E4, 0x06E6, 0x08E8},
	{0x0000, 0x00A0, 0x00C0, 0x00E0, 0x04E4, 0x06E6},
	{0x0000, 0x0000, 0x00A0, 0x00C0, 0x00E0, 0x04E4},
	{0x0000, 0x0000, 0x0000, 0x00A0, 0x00C0, 0x00E0},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x00A0, 0x00C0},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00A0},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}};

static int disclaimerLogoLedIndex;
static int ledUpdate;
static int exit;

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

#define WAITBREAK_DISCLAIMER(n) \
	if (_wait(n))               \
	{                           \
		break;                  \
	}

static u16 _wait(u16 hz)
{
	while (!exit && hz--)
	{
		SYS_doVBlankProcess();
		JoyReader_update();

		if (!(joy1_pressed_abc | joy1_pressed_start))
			continue;

		exit = 1;
	}

	return exit;
}

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

static void _doDisclaimerLogoLedUpdate(void)
{
	if (ledUpdate + disclaimerLogoLedIndex == 0)
		return;

	PAL_setColors(33, disclaimerLogoLedFadeColors[disclaimerLogoLedIndex], DISCLAIMERLOGOLED_NUMCOLORS, CPU);

	if (++disclaimerLogoLedIndex >= DISCLAIMERLOGOLED_FADESTEPS)
		disclaimerLogoLedIndex = 0;
}

static void _doTextDisclaimerFadeIn(void)
{
	const int wait = 4;

	for (int i = 1; i < TEXTDISCLAIMER_FADESTEPS; i++)
	{
		WAITBREAK_DISCLAIMER(wait);
		PAL_setColors(13, textDisclaimerFadeColors[i], TEXTDISCLAIMER_NUMCOLORS, CPU);
	}
}

static void _doDisclaimerBGFadeIn(void)
{
	const int wait = 4;

	for (int i = 1; i < DISCLAIMERBG_FADESTEPS; i++)
	{
		WAITBREAK_DISCLAIMER(wait);
		PAL_setColors(1, disclaimerBGFadeColors[i], DISCLAIMERBG_NUMCOLORS, CPU);
	}
}

static void _doDisclaimerLogoFadeIn(void)
{
	const int wait = 4;

	for (int i = 1; i < DISCLAIMERLOGO_FADESTEPS; i++)
	{
		WAITBREAK_DISCLAIMER(wait);
		PAL_setColors(17, disclaimerLogoFadeColors[i], DISCLAIMERLOGO_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate();
	}
}

static void _doDisclaimerBGFadeOut(void)
{
	const int wait = 4;

	for (int i = DISCLAIMERBG_FADESTEPS - 2; i >= 0; i--)
	{
		WAITBREAK_DISCLAIMER(wait);
		PAL_setColors(1, disclaimerBGFadeColors[i], DISCLAIMERBG_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate();
	}
}

static void _doTextDisclaimerFadeOut(void)
{
	const int wait = 4;

	for (int i = TEXTDISCLAIMER_FADESTEPS - 2; i >= 0; i--)
	{
		WAITBREAK_DISCLAIMER(wait);
		PAL_setColors(13, textDisclaimerFadeColors[i], TEXTDISCLAIMER_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate();
	}
}

static void _doDisclaimerLogoFadeOut(void)
{
	const int wait = 4;
	ledUpdate = 0;

	for (int i = DISCLAIMERLOGO_FADESTEPS - 2; i >= 0; i--)
	{
		WAITBREAK_DISCLAIMER(wait);
		PAL_setColors(17, disclaimerLogoFadeColors[i], DISCLAIMERLOGO_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate();
	}
}

static void _doWaitForTimeout(int timeout)
{
	const int wait = 4;
	timeout /= wait;

	while (timeout--)
	{
		WAITBREAK_DISCLAIMER(wait);
		_doDisclaimerLogoLedUpdate();
	}
}

static int _init(int secs)
{
	disclaimerLogoLedIndex = 0;
	ledUpdate = 1;
	exit = 0;

	int pos = TILE_USER_INDEX;
	VDP_drawImageEx(BG_B, &screen_disclaimerBGImage_all, TILE_ATTR_FULL(PAL0, 0, 0, 0, pos), 0, 0, 0, 0);

	pos += screen_disclaimerBGImage_all.tileset->numTile;
	VDP_drawImageEx(BG_A, &screen_disclaimerLogoImage_all, TILE_ATTR_FULL(PAL1, 0, 0, 0, pos), 9, 9, 0, 0);

	pos += screen_disclaimerLogoImage_all.tileset->numTile;
	VDP_drawImageEx(BG_B, &screen_disclaimerLogoLedImage_all, TILE_ATTR_FULL(PAL2, 0, 0, 0, pos), 26, 9, 0, 0);

	return (IS_PAL_SYSTEM ? 50 : 60) * secs;
}

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void screen_disclaimer_cool()
{
	int timeout = _init(4);
	_doTextDisclaimerFadeIn();
	_doDisclaimerBGFadeIn();
	_doDisclaimerLogoFadeIn();
	_doWaitForTimeout(timeout);
	_doDisclaimerBGFadeOut();
	_doTextDisclaimerFadeOut();
	_doDisclaimerLogoFadeOut();
}