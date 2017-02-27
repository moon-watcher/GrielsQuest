//#include "../inc/include.h"
//
//#define STARTS_ELEMENTS  3
//#define STARTS_SPRITES   4
//
//
//
//
////static u8 sprites [ STARTS_ELEMENTS ] [ STARTS_SPRITES ];
//
//
//
//void stars_init ( )
//{
//}
//
//
//void stars_draw ( )
//{
//	u8 i, s = 0;
//
//	vobject_add ( ESTRELLITA1 );
//	vobject_add ( ESTRELLITA2 );
//	vobject_add ( ESTRELLITA3 );
//	vobject_add ( ESTRELLITA4 );
//
//	Vect2D_s16 posiciones[STARTS_ELEMENTS] =
//	{
//		{ vdpSpriteCache[splist_griel].posx - 4, vdpSpriteCache[splist_griel].posy + 2 },
//		{ vdpSpriteCache[splist_key].posx   - 4, vdpSpriteCache[splist_key].posy   + 4 },
//		{ vdpSpriteCache[splist_door].posx  - 4, vdpSpriteCache[splist_door].posy  + 2 }
//	};
//
//	for ( i=0; i<STARTS_ELEMENTS; i++ )
//	{
//		s16 x = posiciones[i].x;
//		s16 y = posiciones[i].y;
//
//		vsprite_set ( s++, x-12, y-12, ESTRELLITA1 );
//		vsprite_set ( s++, x+12, y-12, ESTRELLITA2 );
//		vsprite_set ( s++, x-12, y+12, ESTRELLITA3 );
//		vsprite_set ( s++, x+12, y+12, ESTRELLITA4 );
//	}
//
//
//	u16 duracion = animation_duracion(ESTRELLITA1);
//
//	while ( --duracion )
//	{
//		vobject_update();
//		VDP_updateSprites();
//		VDP_waitVSync();
//	}
//
//	vobject_delete ( ESTRELLITA1 );
//	vobject_delete ( ESTRELLITA2 );
//	vobject_delete ( ESTRELLITA3 );
//	vobject_delete ( ESTRELLITA4 );
//
//
//	for ( i=0; i<STARTS_ELEMENTS*STARTS_SPRITES; i++ )
//	{
//		splist_hide_sprite ( i );
//		vsprite_animation ( i, EMPTY_SPRITE );
//	}
//}


















#include "../inc/include.h"

#define STARTS_ELEMENTS  1 // 3 // puerta, llave y Griel
#define STARTS_SPRITES   4




static u8 sprites [ STARTS_ELEMENTS ] [ STARTS_SPRITES ] = { };


static void _freeze_objects ()
{
	u16 i;

	for ( i = 0; i < MAX_ANIMATIONS; i++ )
	{
		if ( vobject_get ( i )->active && i != ESTRELLITA1 && i != ESTRELLITA2 && i != ESTRELLITA3 && i != ESTRELLITA4 )
		{
			vobject_get ( i )->counter=0;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void stars_init ( )
{
	u8 i;

	for ( i=0; i<STARTS_ELEMENTS; i++ )
	{
		sprites[i][0] = 0;
		sprites[i][1] = 0;
		sprites[i][2] = 0;
		sprites[i][3] = 0;
	}
}


void stars_draw ( )
{
	u8 i;

	vobject_add ( ESTRELLITA1 );
	vobject_add ( ESTRELLITA2 );
	vobject_add ( ESTRELLITA3 );
	vobject_add ( ESTRELLITA4 );

	Vect2D_s16 posiciones[STARTS_ELEMENTS] =
	{
		{ vdpSpriteCache[splist_griel].x - 4-128, vdpSpriteCache[splist_griel].y + 2-128 },
//		{ vdpSpriteCache[splist_key].x   - 4-128, vdpSpriteCache[splist_key].y   + 4-128 },
//		{ vdpSpriteCache[splist_door].x  - 4-128, vdpSpriteCache[splist_door].y  + 2-128 }
	};

	for ( i=0; i<STARTS_ELEMENTS; i++ )
	{
		s16 x = posiciones[i].x;
		s16 y = posiciones[i].y;

		//vsprite_set ( sprites[i][0] = sd_new(7, SD_DOWN), x-12, y-12, ESTRELLITA1 );
		vsprite_set ( sprites[i][0] = sd_next(), x-12, y-12, ESTRELLITA1 );
		vsprite_set ( sprites[i][1] = sd_next(), x+12, y-12, ESTRELLITA2 );
		vsprite_set ( sprites[i][2] = sd_next(), x-12, y+12, ESTRELLITA3 );
		vsprite_set ( sprites[i][3] = sd_next(), x+12, y+12, ESTRELLITA4 );
	}


	u16 duracion = animation_duracion(ESTRELLITA1);

	while ( --duracion )
	{
		if ( duracion % 4 == 0 ) _freeze_objects();

		vobject_update();
		VDP_updateSprites(80,1);
		VDP_waitVSync();
	}

	vobject_delete ( ESTRELLITA1 );
	vobject_delete ( ESTRELLITA2 );
	vobject_delete ( ESTRELLITA3 );
	vobject_delete ( ESTRELLITA4 );

	for ( i=0; i<STARTS_ELEMENTS; i++ )
	{
		u8 j;

		for ( j=0; j<STARTS_SPRITES; j++ )
		{
			u8 sprite = sprites [ i ] [ j ] ;

			splist_hide_sprite ( sprite );
			vsprite_animation ( sprite, EMPTY_SPRITE );
			sd_delete ( sprite );
		}
	}

	stars_init ();
}
