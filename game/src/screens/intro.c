#include "../inc/include.h"
#include "../inc/colores_textos.h"






/*

#define SALE                                                                                                \
	{                                                                                                        \
		if ( joy1_pressed_abc   ) { vint_setOb_intro_2_b_f(false); VDP_waitVSync(); VDP_fadeOutAll ( 30, false ); return go; } \
		if ( joy1_pressed_start ) { return 0; }                                                               \
	}

#define BUCLE       { SALE; VDP_waitVSync(); };
#define WAITMS(s)   { u16 t = (s) * getHz() / 1000; while ( t-- ) BUCLE; };
#define WAITFADE    { while ( VDP_isDoingFade() ) BUCLE; };

#define TYPE(s,x,y)                                \
	{                                               \
		u8 *aux = (s);                               \
		u8 i, len = strlen ( aux );                  \
		for ( i=0; i<len; i++ )                      \
		{                                            \
			u8  chr[2] = { *aux++ };                  \
			if ( chr[0] == ' ' ) continue;            \
			VDP_drawText ( chr, (x)+i, (y) );         \
			WAITMS(vel_text);                         \
		}                                            \
	};

*/






static u16 cont;
static u16 paleta[16];
static u16 go;
static u16 ind;
static u16 vel_text;




static void _draw_griel ( s16 x, u16 ind )
{
	u16 i, j, inc = 0;

	for ( j = 0; j < 5; j++ )
	{
		for ( i = 0; i < 5; i++ )
		{
			VDP_setSprite ( inc, x+i*32, j*32, os_intro_4_c.size   >> 8, TILE_ATTR_FULL ( PAL2, 0, 0, 0, ind ), inc+1 );

			ind += ( ( os_intro_4_c.width  >> 3 ) * ( os_intro_4_c.height >> 3 ) );
			++inc;
		}
	}
	VDP_setSprite ( inc, 0, 0, 0, 0, 0 );
}




static void _frases_tt_init ( u16 grupo )
{
	tt_init ( );
	frases_init ( grupo );


	#undef TT_A
	#undef TT_B
	#undef TT_C
	#undef TT_START

	#define TT_A       { go = 0; goto fin; } // tt_info.next = true;
	#define TT_B       { go = 0; goto fin; } // tt_info.next = true;
	#define TT_C       { go = 0; goto fin; } // tt_info.next = true;
	#define TT_START   { go = 0; goto fin; }

	tt_info.buttons = ( BUTTON_A|BUTTON_B|BUTTON_C|BUTTON_START );
	tt_info.speed = 2;

	#undef  WAITBREAK_START
	#define WAITBREAK_START  { go = 0; goto fin; }
}






static u8 _escena_1()
{
	go  = 2;
	ind = TILE_USERINDEX;

	u16 vel_show = 20;



	VDP_setEnable ( false );
	SYS_disableInts();

	resetScreen();
	resetSprites();

   font_setPalette();
   SYS_enableInts();
   VDP_setEnable ( true );



	_frases_tt_init( 7 );
	musiclist_play ( MUSIC_INTRO );



	frases_tt_write ( NARRADOR );



	SYS_disableInts();

	resetScreen();

   VDP_drawImageEx ( APLAN, &ob_intro_1_a, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 0, 1, false, true );
   VDP_waitDMACompletion();
   ind += ob_intro_1_a.tileset->numTile;

   VDP_fadePalTo ( PAL1, ob_intro_1_a.palette->data, vel_show, true );

   SYS_enableInts();

   wb_fade ( BUTTON_START );

   frases_tt_write ( NARRADOR );




	SYS_disableInts();
   VDP_drawImageEx ( APLAN, &ob_intro_1_c, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 27, 1, false, true ); VDP_waitDMACompletion();
   VDP_fadePalTo ( PAL2, ob_intro_1_c.palette->data, vel_show, true );
   SYS_enableInts();

   wb_fade ( BUTTON_START );

   frases_tt_write ( NARRADOR );



	SYS_disableInts();
	VDP_drawImageEx ( APLAN, &ob_intro_1_c, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 27, 1, false, true );  VDP_waitDMACompletion(); ind += ob_intro_1_c.tileset->numTile;
	SYS_enableInts();

   //wb_wait ( getHz(), BUTTON_START );

   VDP_fadePalOut ( PAL1, vel_show, true );



   // oscurece los Kbrah's de los lados
   //vel_show = 120;
   s16 i = vel_show;

   while( i-- )
   {
      wb_wait ( 1, BUTTON_START );

      if ( i == 10 )
      {
         VDP_interruptFade();
         break;
      }
   }
   //


   VDP_setVerticalScroll ( PLAN_B, i-100 );

   SYS_disableInts();
   VDP_drawImageEx ( BPLAN, &ob_intro_1_b, TILE_ATTR_FULL(PAL3, true, false, false, ind), 12, 0, true, true ); VDP_waitDMACompletion();
   SYS_enableInts();

   for ( i = 250; i >= 0; i -= 6 )
   {
      VDP_setVerticalScroll ( PLAN_B, i );
		wb_wait ( 1, BUTTON_START );
   }

   VDP_setVerticalScroll ( PLAN_B, 0 );

   VDP_setPalette ( PAL0, font_getPalette() );


   frases_tt_write ( NARRADOR );



fin:

	VDP_fadeOutAll ( 30, false );

	return go;
}




static u8 _escena_2()
{
	cont = 0;
	go   = 3;
	ind  = TILE_USERINDEX;

   VDP_setEnable ( false );
	SYS_disableInts ( );

   VDP_interruptFade ( );
	resetScroll ( );

   VDP_drawImageEx ( BPLAN, &ob_intro_2_b, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_2_b.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_intro_2_a, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_2_a.tileset->numTile;

   u16 i;
	for ( i=0; i<16; i++)
   {
      paleta[i] = ob_intro_2_b.palette->data[i];
   }

   paleta[1] = ob_intro_2_b.palette->data[2];
   paleta[2] = ob_intro_2_b.palette->data[1];

   VDP_setPalette ( PAL0, font_getPalette() );

   vint_setOb_intro_2_b_f(true);

	SYS_enableInts();
   VDP_setEnable ( true );

#undef  WAITBREAK_A
#undef  WAITBREAK_B
#undef  WAITBREAK_C

#define WAITBREAK_A break;
#define WAITBREAK_B break;
#define WAITBREAK_C break;

   //wb_wait(3*getHz(), BUTTON_ABCS );


	_frases_tt_init ( 8 );

	frases_tt_write ( NARRADOR );


fin:

	vint_setOb_intro_2_b_f(false);
//	VDP_waitVSync();

	VDP_fadeOutAll ( 30, false );


   return go;
}




static u8 _escena_3 ()
{
	go  = 4;
	ind = TILE_USERINDEX;



	vint_setOb_intro_2_b_f(false);

   //SYS_setVIntCallback ( NULL );


   VDP_setEnable ( false );
	SYS_disableInts();

	resetScreen();
   VDP_setPalette ( PAL0, font_getPalette() );

	SYS_enableInts();
   VDP_setEnable ( true );


	_frases_tt_init ( 9 );

	frases_tt_write ( NARRADOR );
	frases_tt_write ( NOTA );







   VDP_setEnable ( false );
	SYS_disableInts();

   VDP_interruptFade();

	resetScreen ();



   VDP_drawImageEx ( BPLAN, &ob_intro_3_a, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind),  0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_3_a.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_intro_3_b, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 10, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_3_b.tileset->numTile;

   VDP_setHorizontalScroll ( PLAN_B, -80 );

   VDP_setPalette   ( PAL3, os_intro_3_c.pal );

	VDP_resetSprites();
	VDP_updateSprites();

	u16 size = ( os_intro_3_d.width >> 3 ) * ( os_intro_3_d.height >> 3 );
	u16 tile = TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind );
	ind += size;

	VDP_loadTileData ( os_intro_3_d.sprites[0], tile, size, 0 );
	VDP_setSprite ( 0, -125, 50, os_intro_3_d.size>>8, tile, 1 );

	u16 i;

   for ( i=1; i<17; i++ )
   {
      u16 size = ( os_intro_3_c.width >> 3 ) * ( os_intro_3_c.height >> 3 );
      u16 tile = TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind );
      ind += size;

      VDP_loadTileData ( os_intro_3_c.sprites[(i-1)], tile, size, 0 );
      VDP_setSprite ( i,  ((i-1)%4)*32-180,  ((i-1)/4)*32 + 32, os_intro_3_c.size>>8, tile, i+1 );
   }

   vdpSpriteCache[i-1].link = 0;


   VDP_setPalette ( PAL0, font_getPalette() );


	s16 values_a [ 19 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	s16 values_b [ 28 ] = { -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80 };

	VDP_setScrollingMode ( HSCROLL_TILE, VSCROLL_PLANE );
	VDP_setHorizontalScrollTile ( PLAN_A, 0, values_a, 19, true ); VDP_waitDMACompletion();
	VDP_setHorizontalScrollTile ( PLAN_B, 0, values_b, 28, true ); VDP_waitDMACompletion();


	SYS_enableInts();
   VDP_setEnable ( true );


	frases_tt_write ( NOTA );




	s16 curval = 0;
   s16 inc_x_b = -80;
	u16 x, j, values[28];

   i = 0;

   while ( inc_x_b )
   {
      if ( i % 2 == 0 )
      {
      	++inc_x_b;

			for ( x=0; x<28; x++ ) values[x] = inc_x_b;

			VDP_setHorizontalScrollTile ( PLAN_B, 0, values, 28, true );

         //VDP_setHorizontalScroll ( PLAN_B, ++inc_x_b );

         for ( j=0; j<17; j++ )
         {
            vdpSpriteCache[j].posx += 2;
            VDP_setSpriteP ( j, &vdpSpriteCache[j] );
         }

         if (  inc_x_b % 4 == 0  &&  inc_x_b > -30  )
			{
				vdpSpriteCache[0].posy += 1;
            VDP_setSpriteP ( 0, &vdpSpriteCache[0] );
			}
      }

		if ( i % 3 == 0)
		{
			curval +=1;

			for ( x=0; x<19; x++ ) values[x] = curval;

			VDP_setHorizontalScrollTile ( PLAN_A, 0, values, 19, true );
			VDP_waitDMACompletion();
		}

      VDP_updateSprites();
      wb_wait(1, BUTTON_ABCS);


      i++;
   }


	frases_tt_write ( CORTAZAR );
	frases_tt_write ( NOTA );





fin:

	VDP_fadeOutAll ( 30, false );

	vint_setOb_intro_2_b_f(false);
	VDP_waitVSync();

   return go;
}




static u8 _escena_4 ()
{
	go  = 0;
	ind = TILE_USERINDEX;


   VDP_setEnable ( false );
	SYS_disableInts();


   VDP_interruptFade();
   VDP_resetSprites();
   VDP_updateSprites();

	resetScreen();
	resetScroll();

	VDP_resetSprites();
	VDP_updateSprites();



   VDP_drawImageEx ( BPLAN, &ob_intro_4_b, TILE_ATTR_FULL(PAL0, 0, 0, 0, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_4_b.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_intro_4_a, TILE_ATTR_FULL(PAL1, 0, 0, 0, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_4_a.tileset->numTile;

   VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );

   VDP_setHorizontalScroll ( PLAN_A, -116 );
   VDP_setVerticalScroll   ( PLAN_A, 0 );




	VDP_loadTileData ( os_intro_4_c.sprites[0], ind, 5*4*5*4, true ); VDP_waitDMACompletion();

	VDP_setPalette( PAL2, os_intro_4_c.pal );


	SYS_enableInts();
   VDP_setEnable ( true );






   u16 i = 0;
   s16 inc_x =0;

   while ( ++i )
   {
		++inc_x;

		_draw_griel ( 285-inc_x, ind );
      VDP_setHorizontalScroll ( PLAN_A, + inc_x - 116 );

      if ( inc_x == 116 || ( JOY_readJoypad(JOY_1) & BUTTON_ABCS ) )
      {
         break;
      }


      VDP_updateSprites();
      wb_wait(1, BUTTON_ABCS);
   }



	_frases_tt_init ( 10 );

	frases_tt_write ( NOTA );
	frases_tt_write ( GRIEL );
	frases_tt_write ( NOTA );


fin:

	VDP_fadeOutAll ( 30, false );

	return go;
}




static u8 _escena_5 ()
{
	VDP_fadeOutAll(30, true);
	waitMs(500);


	go  = 0;
   ind = TILE_USERINDEX;



	music_stop();
   VDP_setEnable ( false );
	SYS_disableInts();

   VDP_interruptFade();
   VDP_resetSprites();
   VDP_updateSprites();



	resetScreen();
	resetScroll();

	VDP_resetSprites();
	VDP_updateSprites();

	VDP_setPalette ( PAL0, palette_black );
	VDP_setPalette ( PAL1, palette_black );
	VDP_setPalette ( PAL2, palette_black );
	VDP_setPalette ( PAL3, palette_black );

   VDP_drawImageEx ( BPLAN, &ob_intro_4_b, TILE_ATTR_FULL(PAL3, 0, 0, 0, ind), 0, 0, 0, true ); VDP_waitDMACompletion(); ind += ob_intro_4_b.tileset->numTile;
   VDP_drawImageEx ( APLAN, &ob_intro_4_a, TILE_ATTR_FULL(PAL1, 0, 0, 0, ind), 0, 0, 0, true ); VDP_waitDMACompletion(); ind += ob_intro_4_a.tileset->numTile;

   VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );

   VDP_setHorizontalScroll ( PLAN_A, -116 );
   VDP_setVerticalScroll   ( PLAN_A, 0 );




	VDP_loadTileData ( os_intro_4_c.sprites[0], ind, 5*4*5*4, true ); VDP_waitDMACompletion();


	u16 i, palette[64];

	for ( i=0; i<16; i++ ) palette[i+16*3] = ob_intro_4_b.palette->data[i];
	for ( i=0; i<16; i++ ) palette[i+16*1] = ob_intro_4_a.palette->data[i];
	for ( i=0; i<16; i++ ) palette[i+16*2] = os_intro_4_c.pal[i];
	for ( i=0; i<16; i++ ) palette[i+16*0] = font_getPalette()[i];//as_rounds_sprites_32x32.pal[i];


	VDP_setTextPalette ( PAL0 );

	SYS_enableInts ( );
	VDP_setEnable ( true );

	VDP_fadeInAll ( palette, 30, true );


   i = 0;
   s16 x =0;

   while ( ++i )
   {
      ++x;

		_draw_griel ( 285-x, ind );
      VDP_setHorizontalScroll ( PLAN_A, x - 116 );

      if ( x == 116 )
      {
         break;
      }


      VDP_updateSprites();
 		wb_wait ( 1, BUTTON_ABCS );
  }

	_frases_tt_init( 11 );
	frases_tt_write( NOTA );


fin:

	VDP_fadeOutAll ( 30, false );

	return go;
}





void screens_ob_intro_2_b_f( )
{
   if ( cont % 5 == 0 )
   {
      VDP_setPalette ( PAL1, ( cont % 10 == 0 ) ? ob_intro_2_b.palette->data : paleta );
   }

   ++cont;
}





void screens_intro ( u8 jump )
{
	vel_text = 70;

	//waitMs(500);
   //music_play ( MUSIC_TFM_INTRO );

	resetPalettes ( );
	VDP_setPlanSize ( 64, 64 );

	while ( jump )
	{
      if      ( jump == 1 ) jump = _escena_1 ( );
		else if ( jump == 2 ) jump = _escena_2 ( );
		else if ( jump == 3 ) jump = _escena_3 ( );
		else if ( jump == 4 ) jump = _escena_4 ( );
		else if ( jump == 5 ) jump = _escena_5 ( );
	}

	vint_setOb_intro_2_b_f(false);
	VDP_waitVSync();
   VDP_interruptFade();

	VDP_fadeOutAll ( 30, false );

   tool_reset();
}
