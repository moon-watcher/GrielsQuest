#include "../inc/include.h"


void splist_init (  )
{

	splist_reorder ( );

	splist_key         =  0; // needed
	splist_door        =  0; // needed
	splist_weapon      =  9;
	splist_flash       = 10;
	splist_explosion   = 11;
	splist_griel       = 12; // needed
	splist_ui_weapon   = 13;
	splist_ui_enemy    = 14;
	splist_ui_left_1   = 15;
	splist_ui_left_2   = 16;
    splist_ui_key      = 17;
	splist_element     = 78;
	splist_dust        = 79;
}


void splist_draw ( )
{
	int  i      = BIGBOY_MAX;
	int  sprite = 0;
	bool flip_v = level_flipped_v();
	int  bbs    = bigboy_count() - 1;

	while ( i-- )
	{
		BIGBOY *bb = bigboy_get ( i );

		if ( bb->objeto == EMPTY )
		{
			continue;
		}

		if ( flip_v )
		{
			bb->index = BIGBOY_START - sprite + bbs;
		}
		else
		{
			bb->index = BIGBOY_START + sprite;
		}

		++sprite;

		s16 x = level_hpos_to_pixel ( bb->x );
		s16 y = level_vpos_to_pixel ( bb->y );

		vsprite_set ( bb->index, x, y, bb->objeto );

		     if ( object_is_key   ( bb->objeto ) ) splist_key   = bb->index;
		else if ( object_is_door  ( bb->objeto ) ) splist_door  = bb->index;
		else if ( object_is_griel ( bb->objeto ) ) splist_griel = bb->index;
	}
}


void splist_hide_sprites_in_height (  u16 min, u16 max )
{
	int i = MAX_SPRITE;

	while ( i-- )
	{
		if ( between ( vdpSpriteCache[i].y, min, max ) )
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
	int i = MAX_SPRITE-1;

	while ( i-- )
	{
		vdpSpriteCache[i].link = i + 1;
	}

	vdpSpriteCache[79].link = 0;
}


void splist_reorder_bigboys ( )
{
	int total = 0;
	int i = BIGBOY_MAX;

	while ( i-- )
	{
		if ( vdpSpriteCache[BIGBOY_START+i].y > vdpSpriteCache[splist_griel].y )
		{
			++total;
		}
	}

	if ( total )
	{
		vdpSpriteCache [ splist_weapon - 1        ].link = BIGBOY_START;
		vdpSpriteCache [ BIGBOY_START + total - 1 ].link = splist_weapon;
		vdpSpriteCache [ splist_weapon            ].link = splist_flash;
		vdpSpriteCache [ splist_flash             ].link = splist_explosion;
		vdpSpriteCache [ splist_explosion         ].link = splist_griel;
		vdpSpriteCache [ BIGBOY_START - 1         ].link = BIGBOY_START + total;
	}
}
