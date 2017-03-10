#include "../inc/include.h"


#define GRS    (struct genresSprites*)&

#define WA0    0
#define WA1   10
#define WA2    5
#define WA3   60
#define WA4   30
#define WA5    3
#define WA6   11
#define WA7    7
#define WA8  120
#define WA9   20
#define WAA   23
#define WAB   91
#define WAC   47
#define WAD   41
#define WAE   15
#define WAF  250
#define WAG   37



static const ANIMATION _list [ ] =
{
	{ "Empty",            GRS cs_empty,         PAL2 }, // 0


   // inicio - freeobjects

	{ "ASYNCOBJ#0",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#1",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#2",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#3",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#4",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#5",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#6",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#7",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#8",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24
	{ "ASYNCOBJ#9",       GRS cs_empty_32x32,   PAL2 }, // cs_empty_16x24

	// fin - freeobjects



   // inicio - common - sprite 16x24

	{ "Door",             GRS cs_sprites_16x24, PAL1,   1, { {  0, WA0 } } },
	{ "Door Open Anim",   GRS cs_sprites_16x24, PAL1,   2, { {  1, WA3 }, {  2, WA5 } } },
	{ "Door opened",      GRS cs_sprites_16x24, PAL1,   1, { {  2, WA0 } } },
	{ "Door Griel exits", GRS cs_sprites_16x24, PAL1,  10, { {  3, WA6 }, {  4, WA6 }, {  5, WA6 }, {  6, WA6 }, {  7, WA6 }, {  9, WA6 }, {  8, WA6 }, {  9, WA6 }, {  8, WA6 }, {  9, WA6 } } },

	{ "Griel Up",         GRS cs_sprites_16x24, PAL1,   4, { { 10, WA7 }, { 11, WA7 }, { 12, WA7 }, { 11, WA7 } } },
	{ "Griel Down",       GRS cs_sprites_16x24, PAL1,   4, { { 15, WA7 }, { 16, WA7 }, { 17, WA7 }, { 16, WA7 } } },
	{ "Griel Left",       GRS cs_sprites_16x24, PAL1,   4, { { 20, WA7 }, { 21, WA7 }, { 22, WA7 }, { 21, WA7 } } },
	{ "Griel Right",      GRS cs_sprites_16x24, PAL1,   4, { { 25, WA7 }, { 26, WA7 }, { 27, WA7 }, { 26, WA7 } } },
	{ "Griel Hack Up",    GRS cs_sprites_16x24, PAL1,   4, { { 30, WAE }, { 31, WA1 }, { 32, WA4 }, { 31, WA2 } } },
	{ "Griel Hack Down",  GRS cs_sprites_16x24, PAL1,   4, { { 35, WAE }, { 36, WA1 }, { 37, WA4 }, { 36, WA2 } } },
	{ "Griel Hack Left",  GRS cs_sprites_16x24, PAL1,   4, { { 40, WAE }, { 41, WA1 }, { 42, WA4 }, { 41, WA2 } } },
	{ "Griel Hack Rrigh", GRS cs_sprites_16x24, PAL1,   4, { { 45, WAE }, { 46, WA1 }, { 47, WA4 }, { 46, WA2 } } },
	{ "Griel Stands",     GRS cs_sprites_16x24, PAL1,   2, { { 50, WA3 }, { 51, WA3 } } },

	{ "Griel RIP",        GRS cs_muertes_16x24, PAL1,  20, { {100, WA2 }, {101, WA2 }, {102, WA2 }, {103, WA2 }, {104, WA1 }, {105, WA1 }, {106, WA1 }, {107, WA2 }, {108, WA2 }, {109, WA2 }, {110, WA2 }, {111, WA2 }, {112, WA2 }, {113, WA2 }, {114, WA2 }, {115, WA2 }, {116, WA2 }, {117, WA2 }, {118, WA2 }, {119, WA2 } } },
	{ "Griel RIP Fire",   GRS cs_muertes_16x24, PAL1,  14, { {  0, WA2 }, {  1, WA2 }, {  2, WA2 }, {  3, WA2 }, {  4, WA2 }, {  5, WA3 }, {  6, WA2 }, {  7, WA2 }, {  8, WA2 }, {  9, WA2 }, { 10, WA2 }, { 11, WA2 }, { 12, WA2 }, { 13, WAB } } },
	{ "Griel RIP Water",  GRS cs_muertes_16x24, PAL1,  20, { { 20, WA7 }, { 21, WA7 }, { 22, WA7 }, { 23, WA7 }, { 24, WA7 }, { 25, WA7 }, { 26, WA7 }, { 27, WA7 }, { 28, WA7 }, { 29, WA7 }, { 30, WA1 }, { 31, WA1 }, { 32, WA1 }, { 33, WA1 }, { 34, WA1 }, { 35, WAC }, { 36, WAC }, { 37, WAC }, { 38, WAC }, { 39, WAC } } },
	{ "Griel RIP Hole",   GRS cs_muertes_16x24, PAL1,  19, { { 40, WA2 }, { 41, WA2 }, { 42, WA2 }, { 43, WA2 }, { 44, WA2 }, { 45, WA2 }, { 46, WA2 }, { 47, WA2 }, { 48, WA2 }, { 49, WA2 }, { 50, WA2 }, { 51, WA2 }, { 52, WA2 }, { 53, WA2 }, { 54, WA2 }, { 55, WA2 }, { 56,   2 }, { 57,   2 }, { 58,   2 } } },
	{ "Griel RIP Tent.1", GRS cs_muertes_16x24, PAL1,   8, { { 60, WA3 }, { 61, WA4 }, { 62, WA4 }, { 63, WA4 }, { 64, WA4 }, { 65, WA4 }, { 66, WAE }, { 67, WA3+WA3 } } },
	{ "Griel RIP Tent.2", GRS w3s_muerte,       PAL3,   8, { {  0, WA3 }, {  1, WA4 }, {  2, WA4 }, {  3, WA4 }, {  4, WA4 }, {  5, WA4 }, {  6, WAE }, {  7, WA3+WA3 } } },
	{ "Griel RIP Pentac", GRS cs_muertes_16x24, PAL1,  20, { { 80, WA2 }, { 81, WA2 }, { 82, WA2 }, { 83, WA2 }, { 84, WA1 }, { 85, WA1 }, { 86, WA1 }, { 87, WA2 }, { 88, WA2 }, { 89, WA2 }, { 90, WA2 }, { 91, WA2 }, { 92, WA2 }, { 93, WA2 }, { 94, WA2 }, { 95, WA2 }, { 96, WA2 }, { 97, WA2 }, { 98, WA2 }, { 99, WA2 } } },

	{ "Grial",            GRS cs_sprites_16x24, PAL1,  10, { { 60, WA3 }, { 64, WA3 }, { 60, WA3 }, { 64, WA3 }, { 60, WA3 }, { 64, WA3 }, { 60, WA3 }, { 61, WA4 }, { 62, WA4 }, { 63, WA4 } } },
	{ "Key",              GRS cs_sprites_16x24, PAL1,   1, { { 65, 0 } } },

	{ "Sprite Empty",     GRS cs_sprites_16x24, PAL1,   1, { { 69, 0 } } },

	// fin - common - sprite 16x24



	// inicio - common - sprite 16x16

	{ "Remove Object",    GRS cs_sprites_16x16, PAL1,   6, { {  0, WA5 }, {  1, WA5 }, {  2, WA5 }, {  3, WA5 }, {  4, WA5 }, {  9, 5 } } },// el último hace borrar la VRAM
	{ "Remove Sprite",    GRS cs_sprites_16x24, PAL1,   6, { { 70, WA5 }, { 71, WA5 }, { 72, WA5 }, { 73, WA5 }, { 74, WA5 }, { 89, 5 } } },// el último hace borrar la VRAM
	{ "Enemy Dead",       GRS cs_sprites_16x16, PAL1,   5, { {  5, WA7 }, {  6, WA7 }, {  7, WA7 }, {  8, WA7 }, {  9, WA7 } } },
	{ "Staff",            GRS cs_sprites_16x16, PAL1,   1, { { 10, WA0 } } },
	{ "Cross",            GRS cs_sprites_16x16, PAL1,   1, { { 11, WA0 } } },
	{ "Sword",            GRS cs_sprites_16x16, PAL1,   1, { { 12, WA0 } } },
	{ "Dust",             GRS cs_sprites_16x16, PAL1,   3, { { 13, WA7 }, { 14, WA5 }, { 15, WA7 } } },
	{ "Undo",             GRS cs_sprites_16x16, PAL1,   1, { { 16, WA0 } } },
	{ "Undo OK",          GRS cs_sprites_16x16, PAL1,   1, { { 17, WA0 } } },
	{ "Boss",             GRS cs_sprites_16x16, PAL1,   2, { { 18, WAB }, { 19, WA3 } } },

   // fin - common - sprite 16x16


   // inicio - common - sprite 24x24

	{ "Estrellita 1",     GRS cs_estrellitas,   PAL1,  18, { {  0, WA5 }, {  2, WA5 }, {  4, WA5 }, {  6, WA5 }, {  0, WA5 }, {  2, WA5 }, {  4, WA5 }, {  6, WA5 }, {  0, WA5 }, {  2, WA5 }, {  4, WA5 }, {  6, WA5 }, {  0, WA5 }, {  2, WA5 }, {  4, WA5 }, {  6, WA5 }, {  8, WA2 }, { 10, WA7 } } },
	{ "Estrellita 2",     GRS cs_estrellitas,   PAL1,  18, { {  1, WA5 }, {  3, WA5 }, {  5, WA5 }, {  7, WA5 }, {  1, WA5 }, {  3, WA5 }, {  5, WA5 }, {  7, WA5 }, {  1, WA5 }, {  3, WA5 }, {  5, WA5 }, {  7, WA5 }, {  1, WA5 }, {  3, WA5 }, {  5, WA5 }, {  7, WA5 }, {  9, WA2 }, { 11, WA7 } } },
	{ "Estrellita 3",     GRS cs_estrellitas,   PAL1,  18, { { 12, WA5 }, { 14, WA5 }, { 16, WA5 }, { 18, WA5 }, { 12, WA5 }, { 14, WA5 }, { 16, WA5 }, { 18, WA5 }, { 12, WA5 }, { 14, WA5 }, { 16, WA5 }, { 18, WA5 }, { 12, WA5 }, { 14, WA5 }, { 16, WA5 }, { 18, WA5 }, { 20, WA2 }, { 22, WA7 } } },
	{ "Estrellita 4",     GRS cs_estrellitas,   PAL1,  18, { { 13, WA5 }, { 15, WA5 }, { 17, WA5 }, { 19, WA5 }, { 13, WA5 }, { 15, WA5 }, { 17, WA5 }, { 19, WA5 }, { 13, WA5 }, { 15, WA5 }, { 17, WA5 }, { 19, WA5 }, { 13, WA5 }, { 15, WA5 }, { 17, WA5 }, { 19, WA5 }, { 21, WA2 }, { 23, WA7 } } },

   // fin - common - sprite 24x24



   // inicio // ambiente 0

	{ "Up",               GRS w0s_blocks,       PAL3,   1, { {  3, 0 } } },
	{ "Down",             GRS w0s_blocks,       PAL3,   1, { {  4, 0 } } },
	{ "Left",             GRS w0s_blocks,       PAL3,   1, { {  5, 0 } } },
	{ "Right",            GRS w0s_blocks,       PAL3,   1, { {  6, 0 } } },

	{ "Tomb",             GRS w0s_blocks,       PAL3,   1, { {  1, 0 } } },
	{ "Tocon",            GRS w0s_blocks,       PAL3,   1, { {  2, 0 } } },
	{ "Zarza",            GRS w0s_blocks,       PAL3,   1, { { 11, 0 } } },
	{ "Piedras",          GRS w0s_blocks,       PAL3,   1, { { 12, 0 } } },
	{ "Seta 1",           GRS w0s_blocks,       PAL3,   1, { { 13, 0 } } },
	{ "Seta 2",           GRS w0s_blocks,       PAL3,   1, { { 14, 0 } } },
	{ "Candle",           GRS w0s_blocks,       PAL3,   2, { {  7, WA6 }, { 17, WA6 } } },
	{ "Fire",             GRS w0s_blocks,       PAL3,   2, { { 15, WA6 }, { 16, WA6 } } },
	{ "AbbayeMD 1",       GRS w0s_blocks,       PAL3,   1, { {  8, WA0 } } },
	{ "AbbayeMD 2",       GRS w0s_blocks,       PAL3,   1, { { 18, WA0 } } },
	{ "Bigtree 1",        GRS w0s_blocks,       PAL3,   1, { {  9, WA0 } } },
	{ "Bigtree 2",        GRS w0s_blocks,       PAL3,   1, { { 19, WA0 } } },

	{ "Lake",             GRS w0s_blocks_32x32, PAL3,   2, { {  0, WAD }, {  2, WAD } } },
	{ "Lake",             GRS w0s_blocks_32x32, PAL3,   2, { {  1, WAD }, {  3, WAD } } },
	{ "Lake",             GRS w0s_blocks_32x32, PAL3,   2, { {  4, WAD }, {  6, WAD } } },
	{ "Lake",             GRS w0s_blocks_32x32, PAL3,   2, { {  5, WAD }, {  7, WAD } } },

	{ "Wildboar",         GRS w0s_enemies,      PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Wildboar Alt",     GRS w0s_enemies,      PAL2,   2, { {  2, WAA }, {  3, WAA } } },
	{ "Wildboar Die",     GRS w0s_enemies,      PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Toadstool",        GRS w0s_enemies,      PAL2,   2, { { 10, WAG }, { 11, WAG } } },
	{ "Toadstool Alt",    GRS w0s_enemies,      PAL2,   2, { { 12, WAA }, { 13, WAA } } },
	{ "Toadstool Die",    GRS w0s_enemies,      PAL2,   4, { { 14, WA3 }, { 15, WA4 }, { 16, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Dark Elf",         GRS w0s_bigboy,       PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Dark Elf Alt",     GRS w0s_bigboy,       PAL2,   2, { {  2, WAA }, {  3, WAA } } },
	{ "Dark Elf Die",     GRS w0s_bigboy,       PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

   // fin // ambiente 0



   // inicio // ambiente 1

	{ "Tree",             GRS w1s_blocks,       PAL3,   1, { {  0, 0 } } },
	{ "Tomb",             GRS w1s_blocks,       PAL3,   1, { {  1, 0 } } },
	{ "Up",               GRS w1s_blocks,       PAL3,   1, { {  3, 0 } } },
	{ "Down",             GRS w1s_blocks,       PAL3,   1, { {  4, 0 } } },
	{ "Left",             GRS w1s_blocks,       PAL3,   1, { {  5, 0 } } },
	{ "Right",            GRS w1s_blocks,       PAL3,   1, { {  6, 0 } } },
	{ "Tree",             GRS w1s_blocks,       PAL3,   1, { { 10, 0 } } },
	{ "Rock",             GRS w1s_blocks,       PAL3,   1, { { 11, 0 } } },
	{ "Iceblock",         GRS w1s_blocks,       PAL3,   1, { { 12, 0 } } },
	{ "Stalagmite",       GRS w1s_blocks,       PAL3,   1, { { 13, 0 } } },
	{ "Snowman",          GRS w1s_blocks,       PAL3,   1, { { 14, 0 } } },
	{ "Skull",            GRS w1s_blocks,       PAL3,   1, { { 15, 0 } } },

	{ "Hole",             GRS w1s_blocks,       PAL3,   2, { { 27, WA3 }, { 37, WA3 } } },
	{ "Fish 1",           GRS w1s_blocks,       PAL3,   1, { { 22, 0 } } },
	{ "Fish 2",           GRS w1s_blocks,       PAL3,   1, { { 32, 0 } } },
	{ "Iglu 1",           GRS w1s_blocks,       PAL3,   1, { { 23, 0 } } },
	{ "Iglu 2",           GRS w1s_blocks,       PAL3,   1, { { 24, 0 } } },
	{ "Iglu 3",           GRS w1s_blocks,       PAL3,   1, { { 33, 0 } } },
	{ "Iglu 4",           GRS w1s_blocks,       PAL3,   1, { { 34, 0 } } },
	{ "Candle",           GRS w1s_blocks,       PAL3,   2, { { 25, WAA }, { 35, WAA } } },
	{ "Abbaye U 2",       GRS w1s_blocks,       PAL3,   1, { { 26, 0 } } },
	{ "Abbaye D 2",       GRS w1s_blocks,       PAL3,   1, { { 36, 0 } } },

	{ "Walrus",           GRS w1s_enemies,      PAL2,   2, { { 10, WAG }, { 11, WAG } } },
	{ "Walrus Alt",       GRS w1s_enemies,      PAL2,   2, { { 12, WAA }, { 13, WAA } } },
	{ "Walrus Die",       GRS w1s_enemies,      PAL2,   4, { { 14, WA3 }, { 15, WA4 }, { 16, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Eskimo",           GRS w1s_enemies,      PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Eskimo Alt",       GRS w1s_enemies,      PAL2,   2, { {  2, WAD }, {  3, WAD } } },
	{ "Eskimo Die",       GRS w1s_enemies,      PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Wampa",            GRS w1s_bigboy,       PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Wampa Alt",        GRS w1s_bigboy,       PAL2,   2, { {  2, WA1 }, {  3, WA1 } } },
	{ "Wampa Die",        GRS w1s_bigboy,       PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

   // fin // ambiente 1





   // inicio // ambiente 2

	{ "Hole",             GRS w2s_trampa,       PAL0,   2, { {  0, WA4 }, { 1, WAF } } },
	{ "Cruz",             GRS w2s_blocks,       PAL3,   1, { {  1, 0 } } },
	{ "Up",               GRS w2s_blocks,       PAL3,   1, { {  3, 0 } } },
	{ "Down",             GRS w2s_blocks,       PAL3,   1, { {  4, 0 } } },
	{ "Left",             GRS w2s_blocks,       PAL3,   1, { {  5, 0 } } },
	{ "Right",            GRS w2s_blocks,       PAL3,   1, { {  6, 0 } } },
	{ "Escarabajo",       GRS w2s_blocks,       PAL3,   1, { { 11, 0 } } },
	{ "Cuadrado",         GRS w2s_blocks,       PAL3,   1, { { 12, 0 } } },
	{ "Bloque",           GRS w2s_blocks,       PAL3,   1, { { 13, 0 } } },
	{ "Gato",             GRS w2s_blocks,       PAL3,   1, { { 14, 0 } } },

	{ "Orus 1",           GRS w2s_blocks,       PAL3,   1, { {  8, 0 } } },
	{ "Orus 2",           GRS w2s_blocks,       PAL3,   1, { { 18, 0 } } },
	{ "Sarcofago 1",      GRS w2s_blocks,       PAL3,   1, { {  9, 0 } } },
	{ "Sarcofago 2",      GRS w2s_blocks,       PAL3,   1, { { 19, 0 } } },

	{ "Bedouin",          GRS w2s_enemies,      PAL2,   2, { { 10, WAG }, { 11, WAG } } },
	{ "Bedouin Alt",      GRS w2s_enemies,      PAL2,   2, { { 12, WAA }, { 13, WAA } } },
	{ "Bedouin Die",      GRS w2s_enemies,      PAL2,   4, { { 14, WA3 }, { 15, WA4 }, { 16, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Scorpio",          GRS w2s_enemies,      PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Scorpio Alt",      GRS w2s_enemies,      PAL2,   2, { {  2, WAD }, {  3, WAD } } },
	{ "Scorpio Die",      GRS w2s_enemies,      PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Mummy",            GRS w2s_bigboy,       PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Mummy Alt",        GRS w2s_bigboy,       PAL2,   2, { {  2, WA1 }, {  3, WA1 } } },
	{ "Mummy Die",        GRS w2s_bigboy,       PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Esfinge 1",        GRS w2s_blocks,       PAL3,   1, { { 20, 0 } } },
	{ "Esfinge 2",        GRS w2s_blocks,       PAL3,   1, { { 21, 0 } } },
	{ "Esfinge 3",        GRS w2s_blocks,       PAL3,   1, { { 30, 0 } } },
	{ "Esfinge 4",        GRS w2s_blocks,       PAL3,   1, { { 31, 0 } } },


	{ "Vasija",           GRS w2s_blocks,       PAL3,   1, { {  2,  0 } } },
	{ "Candle",           GRS w2s_blocks,       PAL3,   2, { {  7, 33 }, { 17, 33 } } },
   // fin // ambiente 2



   // inicio // ambiente 3

	{ "Tomb",             GRS w3s_blocks,       PAL3,   1, { {  1, 0 } } },
	{ "Up",               GRS w3s_blocks,       PAL3,   1, { {  2, 0 } } },
	{ "Down",             GRS w3s_blocks,       PAL3,   1, { {  3, 0 } } },
	{ "Left",             GRS w3s_blocks,       PAL3,   1, { {  4, 0 } } },
	{ "Right",            GRS w3s_blocks,       PAL3,   1, { {  5, 0 } } },
	{ "Torch",            GRS w3s_blocks,       PAL3,   2, { {  6, WA4 }, { 16, WA4 }  } },
	{ "Totem 1",          GRS w3s_blocks,       PAL3,   1, { {  7, 0 } } },
	{ "Totem 2",          GRS w3s_blocks,       PAL3,   1, { { 17, 0 } } },
	{ "Tentacle",         GRS w3s_blocks,       PAL3,   2, { {  8, WAB }, { 18, WAB } } },
	{ "Big Tree 4-1",     GRS w3s_blocks,       PAL3,   1, { {  9, 0 } } },
	{ "Big Tree 4-2",     GRS w3s_blocks,       PAL3,   1, { { 19, 0 } } },
	{ "Stone 4-1",        GRS w3s_blocks,       PAL3,   1, { { 11, 0 } } },
	{ "Seto",             GRS w3s_blocks,       PAL3,   1, { { 12, 0 } } },
	{ "Sea Star",         GRS w3s_blocks,       PAL3,   1, { { 13, 0 } } },
	{ "Ancla",            GRS w3s_blocks,       PAL3,   1, { { 14, 0 } } },
	{ "Caracola",         GRS w3s_blocks,       PAL3,   1, { { 15, 0 } } },

	{ "Galeon1",          GRS w3s_blocks,       PAL3,   1, { { 20,   0 } } },
	{ "Galeon2",          GRS w3s_blocks,       PAL3,   1, { { 21,   0 } } },
	{ "Galeon3",          GRS w3s_blocks,       PAL3,   1, { { 30,   0 } } },
	{ "Galeon4",          GRS w3s_blocks,       PAL3,   1, { { 31,   0 } } },

	{ "Cangrejo",         GRS w3s_enemies,      PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Cangrejo Alt",     GRS w3s_enemies,      PAL2,   2, { {  2, WAD }, {  3, WAD } } },
	{ "Cangrejo Die",     GRS w3s_enemies,      PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Pirata",           GRS w3s_enemies,      PAL2,   2, { { 10, WAG }, { 11, WAG } } },
	{ "Pirata Alt",       GRS w3s_enemies,      PAL2,   2, { { 12, WAA }, { 13, WAA } } },
	{ "Pirata Die",       GRS w3s_enemies,      PAL2,   4, { { 14, WA3 }, { 15, WA4 }, { 16, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Plesi",            GRS w3s_bigboy,       PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Plesi Alt",        GRS w3s_bigboy,       PAL2,   2, { {  2, WA1 }, {  3, WA1 } } },
	{ "Plesi Die",        GRS w3s_bigboy,       PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "SEA",              GRS w3s_sea,          PAL0,   4, { {  0, WA3 }, {  1, WA4 }, {  2, WA3 }, {  1, WA4 } } },

   // fin // ambiente 3



   // inicio // ambiente 4

	{ "Guitar 1",         GRS w4s_blocks,       PAL3,   1, { {  0, 0 } } },
	{ "Guitar 2",         GRS w4s_blocks,       PAL3,   1, { { 10, 0 } } },
	{ "Barrel",           GRS w4s_blocks,       PAL3,   1, { {  1, 0 } } },
	{ "Up",               GRS w4s_blocks,       PAL3,   1, { {  2, 0 } } },
	{ "Down",             GRS w4s_blocks,       PAL3,   1, { {  3, 0 } } },
	{ "Left",             GRS w4s_blocks,       PAL3,   1, { {  4, 0 } } },
	{ "Right",            GRS w4s_blocks,       PAL3,   1, { {  5, 0 } } },
	{ "Torch",            GRS w4s_blocks,       PAL3,   2, { {  6, WA4 }, { 16, WA4 }  } },
	{ "Abbaye51",         GRS w4s_blocks,       PAL3,   1, { {  7, 0 } } },
	{ "Abbaye52",         GRS w4s_blocks,       PAL3,   1, { { 17, 0 } } },
	{ "Pentacle",         GRS w4s_blocks,       PAL3,   2, { {  8, WAB }, { 18, WAB } } },
	{ "Baffle",           GRS w4s_blocks,       PAL3,   1, { { 11, 0 } } },
	{ "Megadrive",        GRS w4s_blocks,       PAL3,   1, { { 12, 0 } } },
	{ "Beer",             GRS w4s_blocks,       PAL3,   1, { { 13, 0 } } },
	{ "Sofa1",            GRS w4s_blocks,       PAL3,   1, { { 14, 0 } } },
	{ "Sofa2",            GRS w4s_blocks,       PAL3,   1, { { 15, 0 } } },

	{ "Murci",            GRS w4s_murci,        PAL3,   6, { {  0, WA1 }, {  2, WA1 }, {  4, WA1 }, {  6, WA1 }, {  8, WA1 }, { 10, WA1 } } },
	{ "Murci",            GRS w4s_murci,        PAL3,   6, { {  1, WA1 }, {  3, WA1 }, {  5, WA1 }, {  7, WA1 }, {  9, WA1 }, { 11, WA1 } } },
	{ "Murci",            GRS w4s_murci,        PAL3,   6, { { 12, WA1 }, { 14, WA1 }, { 16, WA1 }, { 18, WA1 }, { 20, WA1 }, { 22, WA1 } } },
	{ "Murci",            GRS w4s_murci,        PAL3,   6, { { 13, WA1 }, { 15, WA1 }, { 17, WA1 }, { 19, WA1 }, { 21, WA1 }, { 23, WA1 } } },

	{ "Eye",              GRS w4s_enemies,      PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Eye Alt",          GRS w4s_enemies,      PAL2,   2, { {  2, WAD }, {  3, WAD } } },
	{ "Eye Die",          GRS w4s_enemies,      PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Ogre",             GRS w4s_enemies,      PAL2,   2, { { 10, WAG }, { 11, WAG } } },
	{ "Ogre Alt",         GRS w4s_enemies,      PAL2,   2, { { 12, WAA }, { 13, WAA } } },
	{ "Ogre Die",         GRS w4s_enemies,      PAL2,   4, { { 14, WA3 }, { 15, WA4 }, { 16, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Demon",            GRS w4s_bigboy,       PAL2,   2, { {  0, WAG }, {  1, WAG } } },
	{ "Demon Alt",        GRS w4s_bigboy,       PAL2,   2, { {  2, WA1 }, {  3, WA1 } } },
	{ "Demon Die",        GRS w4s_bigboy,       PAL2,   4, { {  4, WA3 }, {  5, WA4 }, {  6, WAB }, {8,3} } }, // el último hace borrar la VRAM

	{ "Lava 1",           GRS w4s_lava,         PAL0,   8, { {  0, 11 }, {  1, 23 }, {  0, 11 }, {  1, 11 }, {  2, 83 }, {  1, 23 }, {  2, 37 }, {  1, 11 } } }, // el último hace borrar la VRAM
	{ "Lava 2",           GRS w4s_lava,         PAL0,   8, { {  3, 11 }, {  4, 23 }, {  3, 11 }, {  4, 11 }, {  5, 83 }, {  4, 23 }, {  5, 37 }, {  4, 11 } } }, // el último hace borrar la VRAM

	{ "Ventana 1",        GRS w4s_ventana_1,    PAL0,   2, { {  0, 49 }, {  1, 49 } } },
	{ "Ventana 2",        GRS w4s_ventana_2,    PAL0,   2, { {  0, 49 }, {  1, 49 } } },
	{ "Ventana 3",        GRS w4s_ventana_3,    PAL0,   2, { {  0, 49 }, {  1, 49 } } },
	{ "Ventana 4",        GRS w4s_ventana_4,    PAL0,   2, { {  0, 49 }, {  1, 49 } } },

   // fin // ambiente 4




	{ "Key",              GRS cs_htp_objects,   PAL1,   1, { { 1, 119 } } },
	{ "Door",             GRS cs_htp_objects,   PAL1,   1, { { 0, 117 } } },

	{ "UI Left 1",        GRS cs_ui_left,       PAL1,   1, { { 0, 117 } } },
	{ "UI Left 2",        GRS cs_ui_left,       PAL1,   1, { { 1, 117 } } },


	{ "Block",            GRS cs_empty,         PAL3 },

	{ "Slash Up",         GRS cs_slash,         PAL1,   5, { {  4, 15 }, {  0, 10 }, {  1, 10 }, {  2, 10 }, {  3, 15 } } },
	{ "Slash Down",       GRS cs_slash,         PAL1,   5, { {  9, 15 }, {  5, 10 }, {  6, 10 }, {  7, 10 }, {  8, 15 } } },
	{ "Slash Left",       GRS cs_slash,         PAL1,   5, { { 14, 15 }, { 10, 10 }, { 11, 10 }, { 12, 10 }, { 13, 15 } } },
	{ "Slash Right",      GRS cs_slash,         PAL1,   5, { { 19, 15 }, { 15, 10 }, { 16, 10 }, { 17, 10 }, { 18, 15 } } },

	{ "Sword stands",     GRS cs_weapons,       PAL1,   1, { {  0, WA3 } } },

	{ "Sword walk U",     GRS cs_weapons,       PAL1,   4, { {  2, WA7 }, {  1, WA7 }, {  3, WA7 }, {  1, WA7 } } },
	{ "Sword walk D",     GRS cs_weapons,       PAL1,   4, { {  5, WA7 }, {  4, WA7 }, {  6, WA7 }, {  4, WA7 } } },
	{ "Sword walk L",     GRS cs_weapons,       PAL1,   4, { {  9, WA7 }, {  7, WA7 }, {  8, WA7 }, {  7, WA7 } } },
	{ "Sword walk R",     GRS cs_weapons,       PAL1,   4, { { 11, WA7 }, { 10, WA7 }, { 12, WA7 }, { 10, WA7 } } },

	{ "Sword charge U",   GRS cs_weapons,       PAL1,   1, { { 13, WA7 } } },
	{ "Sword charge D",   GRS cs_weapons,       PAL1,   1, { { 14, WA7 } } },
	{ "Sword charge L",   GRS cs_weapons,       PAL1,   1, { { 15, WA7 } } },
	{ "Sword charge R",   GRS cs_weapons,       PAL1,   1, { { 16, WA7 } } },

	{ "Cross stands",     GRS cs_weapons,       PAL1,   1, { { 20, WA3 } } },

	{ "Cross walk U",     GRS cs_weapons,       PAL1,   4, { { 22, WA7 }, { 21, WA7 }, { 23, WA7 }, { 21, WA7 } } },
	{ "Cross walk D",     GRS cs_weapons,       PAL1,   4, { { 25, WA7 }, { 24, WA7 }, { 26, WA7 }, { 24, WA7 } } },
	{ "Cross walk L",     GRS cs_weapons,       PAL1,   4, { { 29, WA7 }, { 27, WA7 }, { 28, WA7 }, { 27, WA7 } } },
	{ "Cross walk R",     GRS cs_weapons,       PAL1,   4, { { 31, WA7 }, { 30, WA7 }, { 32, WA7 }, { 30, WA7 } } },

	{ "Cross charge U",   GRS cs_weapons,       PAL1,   1, { { 33, WA7 } } },
	{ "Cross charge D",   GRS cs_weapons,       PAL1,   1, { { 34, WA7 } } },
	{ "Cross charge L",   GRS cs_weapons,       PAL1,   1, { { 35, WA7 } } },
	{ "Cross charge R",   GRS cs_weapons,       PAL1,   1, { { 36, WA7 } } },

	{ "Staff stands",     GRS cs_weapons,       PAL1,   1, { { 40, WA3 } } },

	{ "Staff walk U",     GRS cs_weapons,       PAL1,   4, { { 42, WA7 }, { 41, WA7 }, { 43, WA7 }, { 41, WA7 } } },
	{ "Staff walk D",     GRS cs_weapons,       PAL1,   4, { { 45, WA7 }, { 44, WA7 }, { 46, WA7 }, { 44, WA7 } } },
	{ "Staff walk L",     GRS cs_weapons,       PAL1,   4, { { 49, WA7 }, { 47, WA7 }, { 48, WA7 }, { 47, WA7 } } },
	{ "Staff walk R",     GRS cs_weapons,       PAL1,   4, { { 51, WA7 }, { 50, WA7 }, { 52, WA7 }, { 50, WA7 } } },

	{ "Staff charge U",   GRS cs_weapons,       PAL1,   1, { { 53, WA7 } } },
	{ "Staff charge D",   GRS cs_weapons,       PAL1,   1, { { 54, WA7 } } },
	{ "Staff charge L",   GRS cs_weapons,       PAL1,   1, { { 55, WA7 } } },
	{ "Staff charge R",   GRS cs_weapons,       PAL1,   1, { { 56, WA7 } } },

	{ "Monedon",          GRS cs_monedon_16x24, PAL3,   3, { {  0, 200 }, {  1, WA7 }, {  2, WA7 } } },
	{ "Kbrah",            GRS cs_kbrah_32x32,   PAL3,   6, { {  0, WA1 }, {  1, WA7 }, {  2, WA7 }, {  3, WA1 }, {  2, WA7 }, {  1, WA7 } } },

	{ "Hidden door",      },

	{ "EMPTY WEAPON",     GRS cs_weapons,       PAL1,   1, { { 18, WA3 } } },


//	{ "Scoreball create", GRS cs_scoreball),     PAL1,   5, { { 0, 6 }, { 1, 6 }, { 2, 5 }, { 3, 4 }, { 4, 6 } } },
//	{ "Scoreball delete", GRS cs_empty_32x32,   PAL1,   1, { { 0, 3 } } },
//	{ "Scoreball static", GRS cs_scoreball),     PAL1,   1, { { 4, 6 } } },

	//{ "EOF",             NULL } // x
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



static bool _is_raw = false;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



ANIMATION *animation ( )
{
   return (ANIMATION*) &_list;
}


ANIMATION *animation_get ( u16 x )
{
   return (ANIMATION*) &_list [ x ];
}


u16 animation_size ( u16 ani )
{
   return ( _list[ani].res->width >> 3 ) * ( _list[ani].res->height >> 3 );
}


u16 animation_duracion ( u16 ani )
{
	u16 i = _list[ani].frames;
	u16 cnt = 0;

	while ( i-- )
	{
		cnt += _list[ani].frame[i].timer;
	}

	return cnt;
}


void animation_set_raw ( )
{
	_is_raw = true;
}



#define FOR_1    for  (  j = x;          j <  width;   j++  )
#define FOR_2    for  (  i = height - 1; i >= y;       i--  )
#define FOR_3    for  (  j = width  - 1; j >= x;       j--  )
#define FOR_4    for  (  i = y;          i <  height;  i++  )

#define DO_GFX_STUFF                                                               \
{                                                                                  \
	*plctrl = GFX_WRITE_VRAM_ADDR ( plane_dir + ( ( j + planWidth * i ) << 1 ) );  \
	*pwdata = TILE_ATTR_FULL ( palette, prioridad, flip_v, flip_h, tile++ );       \
}

void animation_draw ( u16 ani, u8 x, u8 y, bool absolutepos, VDPPlan plan, s16 prioridad, u16 flip_h, u16 flip_v, u8 width, u8 height )
{
	bool notraw = !_is_raw;
	_is_raw = false;


	if ( ani == BLOCK )
	{
		return;
	}


	DEATH     *dead      = NULL;
	ANIMATION *animation = animation_get ( ani );
	u16        is_big    = notraw && object_is_bigboy ( ani );


	if (  !is_big  &&  object_is_asyncobj(ani)  &&  ( dead = dead_find ( x, y ) )  )
	{
		width  = dead->width;
		height = dead->height;
		ani    = dead->objeto;
		is_big = notraw && dead->is_big;

		dead->vo->counter = 0;
		dead->vo->frame   = 2;
	}
	else
	{
		if ( !width  )  width  = animation->res->width  >> 3;
		if ( !height )  height = animation->res->height >> 3;
	}


	if ( !absolutepos ) // relative
	{
		x = ( x << 1 ) + ( voffset_horizontal >> 3 );
		y = ( y << 1 ) + ( voffset_vertical   >> 3 );
	}


	if ( ani == 0 )
	{
		VDP_clearTileMapRect ( plan, x, y, width, height );
	}
	else if ( is_big )
	{
		if ( !absolutepos ) // relative
		{
			VDP_clearTileMapRect ( plan, x, y, width, --height );
		}
	}
	else
	{
		//
		// needed for macros
		//
		s16 i, j;

		u16 tile    = vobject_add ( ani )->vram_pos;
		u16 palette = animation->pal;

		width  += x;
		height += y;

		if ( prioridad < 0 )
		{
			prioridad = object_is_over ( ani ) ? 1 : 0;
		}

		u16 plane_dir = ( plan.value == PLAN_B.value ) ? VDP_PLAN_B : VDP_PLAN_A;

		vu32 *plctrl = (u32 *) GFX_CTRL_PORT;
		vu16 *pwdata = (u16 *) GFX_DATA_PORT;
		//
		//

		if   ( flip_v )  {  if  (  flip_h  )  FOR_3 FOR_2  DO_GFX_STUFF  else  FOR_1 FOR_2  DO_GFX_STUFF  }
		else             {  if  (  flip_h  )  FOR_3 FOR_4  DO_GFX_STUFF  else  FOR_1 FOR_4  DO_GFX_STUFF  }
	}
}
