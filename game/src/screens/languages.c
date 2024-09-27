#include "../inc/include.h"
#include "../../libs/psg.h"

void screen_languages()
{
    if (gamestate.lenguaje)
        return;

    u8 count = countLanguages();
    u8 y = VDP_getScreenHeight() / 8 / 2 - count;
    u8 x = 16;
    u8 inc_y = y;
    s8 option = 0;

    displayOff(0);

    VDP_setTextPalette(PAL0);
    prepareColor(0, 0x000);
    prepareColor(1, 0xfff);
    prepareColor(2, 0x444);

    font_setPalette();
    resetScreen();

    for (u16 i = 0; i < count; i++) {
        GRIEL_drawText(getLanguage(i), x, inc_y);
        inc_y += 2;
    }

    GRIEL_drawText(">", x - 2, option * 2 + y);
    displayOn(10);

    do {
        GRIEL_drawText(" ", x - 2, option * 2 + y);
        if (joy1_pressed_down) { if (++option > count - 1) option = 0;         psglist_play(PSG_SELECT_2); }
        if (joy1_pressed_up  ) { if (--option < 0        ) option = count - 1; psglist_play(PSG_SELECT_2); }
        GRIEL_drawText(">", x - 2, option * 2 + y);

        waitJoy();
    } while (!(joy1_pressed_abc | joy1_pressed_start));

    psglist_play(PSG_START);

    // blink //////////////
    u16 i = getHz() / 2;
    y = option * 2 + y;

    do{
        if (i % 2) GRIEL_drawText("                              ", x, y);
        waitHz(2);
        GRIEL_drawText(getLanguage(option), x, y);
    } while (i--);

    GRIEL_drawText(getLanguage(option), x, y);
    ///////////////////////

    gamestate.lenguaje = option + 1;

    psg_pause();
    music_stop();

    displayOff(10);
}
