#include <genesis.h>
#include "../../res/commonres.h"

// disclaimer.c by Jack Nolddor
// disclaimer_cool.c by Mun

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

static int disclaimerLogoLedIndex, exit;

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

static void _init(int pos)
{
	disclaimerLogoLedIndex = exit = 0;

	VDP_drawImageEx(BG_B, &screen_disclaimerBGImage_all, TILE_ATTR_FULL(PAL0, 0, 0, 0, pos), 0, 0, 0, 0);
	pos += screen_disclaimerBGImage_all.tileset->numTile;

	VDP_drawImageEx(BG_A, &screen_disclaimerLogoImage_all, TILE_ATTR_FULL(PAL1, 0, 0, 0, pos), 9, 9, 0, 0);
	pos += screen_disclaimerLogoImage_all.tileset->numTile;

	VDP_drawImageEx(BG_B, &screen_disclaimerLogoLedImage_all, TILE_ATTR_FULL(PAL2, 0, 0, 0, pos), 26, 9, 0, 0);
}

void _waitbreak_disclaimer(int hz, int (*joyctrl)())
{
	while (!(exit = joyctrl()) && hz--)
		SYS_doVBlankProcess();
}

static void _doDisclaimerLogoLedUpdate(int ledUpdate)
{
	if (ledUpdate + disclaimerLogoLedIndex == 0)
		return;

	PAL_setColors(33, disclaimerLogoLedFadeColors[disclaimerLogoLedIndex], DISCLAIMERLOGOLED_NUMCOLORS, CPU);

	if (++disclaimerLogoLedIndex >= DISCLAIMERLOGOLED_FADESTEPS)
		disclaimerLogoLedIndex = 0;
}

static void _doTextDisclaimerFadeIn(int wait, int (*joyctrl)())
{
	for (int i = 1; i < TEXTDISCLAIMER_FADESTEPS && !exit; i++)
	{
		PAL_setColors(13, textDisclaimerFadeColors[i], TEXTDISCLAIMER_NUMCOLORS, CPU);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

static void _doDisclaimerBGFadeIn(int wait, int (*joyctrl)())
{
	for (int i = 1; i < DISCLAIMERBG_FADESTEPS && !exit; i++)
	{
		PAL_setColors(1, disclaimerBGFadeColors[i], DISCLAIMERBG_NUMCOLORS, CPU);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

static void _doDisclaimerLogoFadeIn(int wait, int (*joyctrl)(), int ledUpdate)
{
	for (int i = 1; i < DISCLAIMERLOGO_FADESTEPS && !exit; i++)
	{
		PAL_setColors(17, disclaimerLogoFadeColors[i], DISCLAIMERLOGO_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate(ledUpdate);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

static void _doWaitForTimeout(int wait, int (*joyctrl)(), int ledUpdate, int timeout)
{
	for (int i = timeout /= wait; i && !exit; i--)
	{
		_doDisclaimerLogoLedUpdate(ledUpdate);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

static void _doDisclaimerBGFadeOut(int wait, int (*joyctrl)(), int ledUpdate)
{
	for (int i = DISCLAIMERBG_FADESTEPS - 2; i >= 0 && !exit; i--)
	{
		PAL_setColors(1, disclaimerBGFadeColors[i], DISCLAIMERBG_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate(ledUpdate);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

static void _doTextDisclaimerFadeOut(int wait, int (*joyctrl)(), int ledUpdate)
{
	for (int i = TEXTDISCLAIMER_FADESTEPS - 2; i >= 0 && !exit; i--)
	{
		PAL_setColors(13, textDisclaimerFadeColors[i], TEXTDISCLAIMER_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate(ledUpdate);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

static void _doDisclaimerLogoFadeOut(int wait, int (*joyctrl)(), int ledUpdate)
{
	for (int i = DISCLAIMERLOGO_FADESTEPS - 2; i >= 0 && !exit; i--)
	{
		PAL_setColors(17, disclaimerLogoFadeColors[i], DISCLAIMERLOGO_NUMCOLORS, CPU);
		_doDisclaimerLogoLedUpdate(ledUpdate);
		_waitbreak_disclaimer(wait, joyctrl);
	}
}

/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void screen_disclaimer_cool(int vram, int waitHz, int (*joyctrl)())
{
	_init(vram);
	_doTextDisclaimerFadeIn(4, joyctrl);
	_doDisclaimerBGFadeIn(4, joyctrl);
	_doDisclaimerLogoFadeIn(4, joyctrl, 1);
	_doWaitForTimeout(4, joyctrl, 1, waitHz);
	_doDisclaimerBGFadeOut(4, joyctrl, 1);
	_doTextDisclaimerFadeOut(4, joyctrl, 1);
	_doDisclaimerLogoFadeOut(4, joyctrl, 0);
}