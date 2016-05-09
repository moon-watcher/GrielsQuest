#include "../inc/include.h"


static u8 free_sprites [ MAX_LINES ];



void splist_init (  )
{
   memset ( free_sprites, 0, sizeof(MAX_LINES) );

   splist_reorder ( );

   splist_key        = 0; // needed
   splist_door       = 0; // needed
   splist_griel      = 0; // needed
	splist_weapon     = 8;
	splist_explosion  = 9;
	splist_ui_weapon  = 10;
	splist_ui_enemy   = 11;
	splist_flash      = 12;
	splist_element    = 78;
	splist_dust       = 79;
}


void splist_draw ( )
{
   u8 i, line;
   u8 sprite  = BIGBOY_START + BIGBOY_MAX;
   u8 bigboys = bigboy_count();

   for ( line = 0; line < MAX_LINES; line++ )
   {
      for ( i = 0; i < bigboys; i++ )
      {
         BIGBOY *bb = bigboy_get ( i );

         if ( bb->y == line )
         {
            bb->index = sprite--;

            s16 x = level_hpos_to_pixel ( bb->x );
            s16 y = level_vpos_to_pixel ( bb->y );

            vsprite_set ( bb->index, x, y, bb->objeto );

            if ( object_is_key  ( bb->objeto ) ) splist_key  = bb->index;
            if ( object_is_door ( bb->objeto ) ) splist_door = bb->index;
         }
      }

      vsprite_set ( sprite, -40, -40, EMPTY_SPRITE );
      free_sprites [ line ] = sprite--;
   }

   //VDP_updateSprites();
}


void splist_hide_sprite ( u8 sprite )
{
	vdpSpriteCache[sprite].posy = -64; //VDP_getScreenHeight()+10;
	VDP_setSpriteDirectP ( sprite, &vdpSpriteCache[sprite] );
}


void splist_hide_sprites ( )
{
	splist_hide_sprites_in_height (  0, VDP_getPlanHeight()*8 );
}


void splist_hide_sprites_in_height (  u16 min, u16 max )
{
	u8 i;

	for ( i=0; i<MAX_SPRITE; i++ )
	{
		if ( between ( vdpSpriteCache[i].posy, min, max ) )
		{
			splist_hide_sprite ( i );
		}
	}
}


void splist_hide_sprites_from_to ( u16 from, u16 to )
{
	u8 i;

	for ( i=from; i<to; i++ )
	{
		splist_hide_sprite ( i );
	}
}



void splist_reorder ( )
{
	u8 i;

	for ( i=0; i<MAX_SPRITE; ++i )
	{
		vdpSpriteCache[i].link = i + 1;
	}

	vdpSpriteCache [ 79 ].link = 0;
}


s8 splist_update_griel ( u8 y )
{
   return  free_sprites  [  ( ( y - 16 ) / 16 ) - 1  ];
}
