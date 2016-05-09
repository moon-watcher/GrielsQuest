#include "../inc/include.h"
#include "../inc/colores_textos.h"

u16 ct_color ( u16 personaje, u8 desp )
{
	return font_palette.data [ personaje + desp ];
}

