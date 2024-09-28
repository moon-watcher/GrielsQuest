#include "../inc/include.h"

static const s8 _values195[] = {
        [186] =  31, // ú
        [179] =  30, // ó
        [177] =  29, // ñ
        [173] =  28, // í
        [169] =  27, // é
        [161] =  26, // á
        [154] =  25, // Ú
        [147] =  24, // Ó
        [145] =  23, // Ñ
        [141] =  22, // Í
        [137] =  21, // É
        [129] =  20, // Á
        [185] =  17, // ù
        [178] =  16, // ò
        [167] =  15, // ç
        [172] =  14, // ì
        [168] =  13, // è
        [160] =  12, // à
        [153] =  11, // Ù
        [146] =  10, // Ò
        [135] =   9, // Ç
        [140] =   8, // Ì
        [136] =   7, // È
        [128] =   6, // À
        [182] =   5, // ö
        [150] =   4, // Ö
        [187] =   3, // û
        [180] =   2, // ô
        [174] =   1, // î
        // [XXX] =   0, // YYY
        [170] =  -1, // ê
        [162] =  -2, // â
        [165] =  -2, // å // almost equal char
        [155] =  -3, // Û
        [148] =  -4, // Ô
        // [XXX] =  -5, // YYY
        [142] =  -6, // Î
        [138] =  -7, // Ê
        [130] =  -8, // Â
        [133] =  -8, // Å // almost equal char
        [164] =  -9, // ä
        [132] = -10, // Ä
        [188] = -11, // ü 
        // [XXX] = -12, // YYY
        [175] = -13, // ï
        // [XXX] = -14, // YYY
        // [XXX] = -15, // YYY
        // [XXX] = -16, // YYY
        [156] = -17, // Ü
        // [XXX] = -18, // YYY
        // [XXX] = -19, // YYY
        [143] = -20, // Ï
        [181] = -21, // õ
        [149] = -22, // Õ
        [163] = -23, // ã
        [131] = -24, // Ã
    };

static const s8 _values194[] = {
        [191]  =  19, // ¿
        [161]  =  18, // ¡
};

static int _debug_prepareText(s16 chr){
    return 0;

    u8 write[2] = {chr, '\0'};
    drawInt(chr, 0, devu0, 5);
    TEXT_drawText(write, 10, devu0);
    ++devu0;

    return 1;
}

static void _drawText(u8 *str, u16 x, u16 y, bool clear){
    s16 buffer[120] = {};
    u16 len = TEXT_prepareText(str, buffer);
    u16 pos = TILE_ATTR(VDP_getTextPalette(), VDP_getTextPriority(), 0, 0);
    u16 plan = VDP_getTextPlane();

    SYS_disableInts();

    if (clear)
        VDP_clearTileMapRect(BG_B, x, y, len, 1);

    for (u16 i = 0; buffer[i]; i++){
        u16 tile = TILE_FONT_INDEX + buffer[i] - 32;
        VDP_setTileMapXY(plan, pos + tile, x++, y);
    }

    SYS_enableInts();
}

u16 TEXT_prepareText(u8 *str, s16 array[]){
    u16 chr, counter = 0, total = 0;

    while (chr = str[counter++]){
        u16 next = str[counter];

        _debug_prepareText(chr);

             if (chr == 195) counter++, array[total++] = _values195[next], _debug_prepareText(next);
        else if (chr == 194) counter++, array[total++] = _values195[next], _debug_prepareText(next);
        else array[total++] = chr;
    }

    return total;
}

void TEXT_drawText_clear(u8 *str, u16 x, u16 y){
    _drawText(str, x, y, true);
}

void TEXT_drawText(u8 *str, u16 x, u16 y){
    _drawText(str, x, y, false);
}