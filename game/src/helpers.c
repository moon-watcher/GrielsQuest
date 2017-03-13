#include "../inc/include.h"



void VDP_setSpriteAttributes ( u16 index, u16 tile_attr )
{
	//
	// SGDK STYLE
	//
//	SpriteDef *spriteDst;
//
//	if (index >= MAX_SPRITE) return;
//
//	if (index >= spriteNum) spriteNum = index + 1;
//
//	spriteDst = &vdpSpriteCache[index];
//	spriteDst->tile_attr = tile_attr;


	vdpSpriteCache[index].attribut = tile_attr;
}



void VDP_setSpriteVRAM ( u16 index, u16 pos )
{
	//
	// SGDK STYLE
	//
//	SpriteDef *spriteDst;
//
//	if (index >= MAX_SPRITE) return;
//
//	if (index >= spriteNum) spriteNum = index + 1;
//
//	spriteDst = &vdpSpriteCache[index];
//	spriteDst->tile_attr = ( ( spriteDst->tile_attr >> 11 ) << 11 ) + pos ;


	vdpSpriteCache[index].attribut = ( ( vdpSpriteCache[index].attribut >> 11 ) << 11 ) + pos ;
}



void VDP_setSpritePriority ( u16 index, u16 high )
{
	if( high )
	{
		vdpSpriteCache[index].attribut |= ( 1 << 15 );
	}
	else
	{
		vdpSpriteCache[index].attribut &= ~( 1 << 15 );
	}
}









//
// throws some fails
//
//// idea de http://stackoverflow.com/questions/28931379/implementation-of-strtok-function
//
//static u8 *_my_strtok_string;
//
//u8 *my_strtok ( u8 *string, u8 delimitador )
//{
//	u8  i = 0;
//	u8 *part = (u8*) MEM_alloc ( sizeof(u8) * 100 ) ;
//
//	if ( string != NULL )
//	{
//		_my_strtok_string = string;
//	}
//
//	while ( _my_strtok_string )
//	{
//		u8 chr = *_my_strtok_string++;
//
//		if ( chr == delimitador )
//		{
//			break;
//		}
//
//		else if ( chr == '\0' )
//		{
//			_my_strtok_string = NULL;
//		}
//
//		part [ i++ ] = chr;
//	}
//
//	return part;
//}
//


u32 my_strtol ( u8 *cadena )
{
	u8  len = strlen ( cadena );
	u32 val = 0;
	u32 p10 = 1;

	while ( len-- )
	{
		val += ( ( cadena [ len ] - 48 ) * p10 ) ;
		p10 *= 10;
	}

	return val;
}


// copied from uintToStr_()
void my_strpad ( u8 *str, const u8 size, u8 type )
{
	if ( type == 0 )  // Left padding
	{
		u8 i = 0;
		s8 len = strlen(str);
		u8 string[size];
		u8 diff = size - len;

		for ( i=0; i<size; i++ )
		{
			string[i] = ' ';
		}

		string[i] = '\0';

		for ( i=diff; i<size; i++ )
		{
			string[i] = str[i-diff];
		}

		string[size+1] = '\0';
		strcpy ( str, string );
	}
}


//
// Returns 1 if both strings are equal. Else 0
//
u16 my_strcmp ( u8 *str1, u8 *str2 )
{
	u8 *s1 = str1;
	u8 *s2 = str2;

	u32 l1 = strlen ( s1 );
	u32 l2 = strlen ( s2 );

	if ( !l1 || l1 != l2 )
	{
		return 0;
	}

	while ( l1-- )
	{
		if ( *s1++ != *s2++ )
		{
			return 0;
		}
	}

	return 1;
}

//
// from http://stackoverflow.com/questions/276827/string-padding-in-c
//
char *StringPadRight(char *string, int padded_len, char *pad) {
    int len = (int) strlen(string);
    if (len >= padded_len) {
        return string;
    }
    int i;
    for (i = 0; i < padded_len - len; i++) {
        strcat(string, pad);
    }
    return string;
}


void showFPS()
{
	if ( DEV )
	{
		drawUInt ( getFPS(), 37, 27, 2 );
	}
}



void drawInt( u32 nb, u8 x, u8 y, u8 zeros )
{
	u8 str [ zeros+1 ];
	intToStr ( nb, str, zeros );
	VDP_drawText ( str, x, y );
}



void drawUInt( u32 nb, u8 x, u8 y, u8 zeros )
{
	u8 str [ zeros+1 ];
	uintToStr ( nb, str, zeros );
	VDP_drawText ( str, x, y );
}



void drawUIntBG( u32 nb, u8 x, u8 y, u8 zeros, u16 plan, u16 flags )
{
	u8 str [ zeros+1 ];
	uintToStr ( nb, str, zeros );
	VDP_drawTextBG ( PLAN_B, str, x, y );
}



u32 ntsc2pal ( u32 value )
{
	if ( IS_PALSYSTEM )
	{
		value = fix32ToRoundedInt ( fix32Mul ( intToFix32(value), FIX32(0.8333) ) ); // FIX32(0.8); ---> 50 Hz / 60 Hz
	}

	return value;
}


u8 getHz ( )
{
	return IS_PALSYSTEM ? 50 : 60;
}



inline u16 between ( s32 min, s32 nb, s32 max )
{
	return ( min <= nb && nb <= max );
}





void resetPalettes ()
{
	const u16 colores [ 64 ] = { };
	memsetU16 ( (u16*) colores, 0, 64 );

   VDP_setPaletteColors ( 0, (u16*)colores, 64 );
}


void resetVRAM ( )
{
   // reset video memory (len = 0 is a special value to define 0x10000)
   DMA_doVRamFill ( 0, 0, 0, 0 );

   // system tiles (16 "flat" tile)
   u16 i = 16;
   while ( i-- )
   {
      VDP_fillTileData ( i | (i << 4), TILE_SYSTEMINDEX + i, 1, 1 );
   }
}


void resetScreen ( )
{
	VDP_clearPlan ( PLAN_A, 1 );
	VDP_clearPlan ( PLAN_B, 1 );
}


void resetScroll ( )
{
	VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );

	VDP_setHorizontalScroll ( PLAN_A, 0 );
	VDP_setVerticalScroll   ( PLAN_A, 0 );
	VDP_setHorizontalScroll ( PLAN_B, 0 );
	VDP_setVerticalScroll   ( PLAN_B, 0 );
}


void resetSprites ( )
{
	u8 i;

	for ( i=0; i<MAX_SPRITE; i++ )
	{
		vdpSpriteCache[i] = (VDPSprite) { };
	}

	VDP_resetSprites();
	VDP_updateSprites(80,1);
}




void fadeIn ( u16 pal0[16], u16 pal1[16], u16 pal2[16], u16 pal3[16], u16 numframe, u8 async )
{
	u16 colores [ 64 ];

	memcpyU16 ( &colores[0],  pal0, 16 );
	memcpyU16 ( &colores[16], pal1, 16 );
	memcpyU16 ( &colores[32], pal2, 16 );
	memcpyU16 ( &colores[48], pal3, 16 );

	VDP_fadeInAll ( (u16 *) colores, numframe, async ) ;
}


u16 in_array ( u16 needle, u16 array[] )
{
	while (  *array  &&  *array != needle  ) ++array;

	return *array;
}



void inc_difficulty_level ( )
{
	u8 inc = 1;
	u8 aux = gamestate_get_dificultad();

	++gamestate.dificultad;

	if ( gamestate.dificultad >= 3 ) // 3 para la dificultad extra de los niveles invetidos
	{
		inc = 0;
		gamestate.dificultad = 3;
	}

	gamestate.ambientes[0] = level_list[0][aux].cuantos - inc;
	gamestate.ambientes[1] = level_list[1][aux].cuantos - inc;
	gamestate.ambientes[2] = level_list[2][aux].cuantos - inc;
	gamestate.ambientes[3] = level_list[3][aux].cuantos - inc;
	gamestate.ambientes[4] = level_list[4][aux].cuantos - inc;
}
