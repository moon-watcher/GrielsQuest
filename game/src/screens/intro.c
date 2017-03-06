#include "../inc/include.h"
#include "../inc/colores_textos.h"



#undef  WAITBREAK
#define WAITBREAK  { go = 0; goto fin; }




static u16 cont = 0;
static u16 paleta[16] = {};
static u16 go = 0;
static u16 ind = 0;
static u16 vel_text = 0;





static void _frases_tt_init ( u16 grupo )
{
	tt_init ( );
	frases_init ( grupo );


	#undef TT_A
	#undef TT_B
	#undef TT_C
	#undef TT_START

	#define TT_A       { go = 0; goto fin; } // tt_info.go_next = true;
	#define TT_B       { go = 0; goto fin; } // tt_info.go_next = true;
	#define TT_C       { go = 0; goto fin; } // tt_info.go_next = true;
	#define TT_START   { go = 0; goto fin; }

	tt_info.buttons = ( BUTTON_A|BUTTON_B|BUTTON_C|BUTTON_START );
	tt_info.speed = 2;
}





static u8 _escena_1 ( )
{
	go  = 2;
	ind = TILE_USERINDEX;

	u16 vel_show = 20;


	displayInit();
	displayOff(0);

	SYS_disableInts();

	resetScreen();
	resetSprites();
	resetScroll();
	resetPalettes();

	SYS_enableInts();


	_frases_tt_init( 7 );
	musiclist_play ( MUSIC_INTRO );

	frases_tt_write ( NARRADOR );



	SYS_disableInts();

	resetScreen();
	resetSprites();
	resetScroll();

	VDP_drawImageEx ( PLAN_A, &ob_intro_1_a, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 0, 1, false, 0 );
	ind += ob_intro_1_a.tileset->numTile;

	SYS_enableInts();


	VDP_fadePalTo ( PAL1, ob_intro_1_a.palette->data, vel_show, true );


	wb_fade ( joy1_pressed_btn );



	frases_tt_write ( NARRADOR );




	SYS_disableInts();
	//VDP_drawImageEx ( PLAN_A, &ob_intro_1_c, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 27, 1, false, true ); VDP_waitDMACompletion();
	VDP_drawImageEx ( PLAN_A, &ob_intro_1_c, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 27, 1, false, 0 );
	SYS_enableInts();

	VDP_fadePalTo ( PAL2, ob_intro_1_c.palette->data, vel_show, true );

	wb_fade ( joy1_pressed_btn );

	frases_tt_write ( NARRADOR );



	SYS_disableInts();
	//VDP_drawImageEx ( PLAN_A, &ob_intro_1_c, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 27, 1, false, true );  VDP_waitDMACompletion(); ind += ob_intro_1_c.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_intro_1_c, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 27, 1, false, 0 );  ind += ob_intro_1_c.tileset->numTile;
	SYS_enableInts();

	//wb_wait ( getHz(), joy1_pressed_btn );

	VDP_fadePalOut ( PAL1, vel_show, true );



	// oscurece los Kbrah's de los lados
	//vel_show = 120;
	s16 i = vel_show;

	while( i-- )
	{
		wb_wait ( 1, joy1_pressed_btn );

		if ( i == 10 )
		{
			VDP_interruptFade();
			break;
		}
	}
	//


	SYS_disableInts();
	VDP_setVerticalScroll ( PLAN_B, i-100 );
	VDP_drawImageEx ( PLAN_B, &ob_intro_1_b, TILE_ATTR_FULL(PAL3, true, false, false, ind), 12, 0, true, 0 );
	SYS_enableInts();

	for ( i = 250; i >= 0; i -= 6 )
	{
		SYS_disableInts();
		VDP_setVerticalScroll ( PLAN_B, i );
		SYS_enableInts();

		wb_wait ( 1, joy1_pressed_btn );
	}

	SYS_disableInts();
	VDP_setVerticalScroll ( PLAN_B, 0 );
	VDP_setPalette ( PAL0, font_getPalette() );
	SYS_enableInts();

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

//   VDP_drawImageEx ( PLAN_B, &ob_intro_2_b, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_2_b.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_intro_2_a, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_2_a.tileset->numTile;
	VDP_drawImageEx ( PLAN_B, &ob_intro_2_b, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind), 0, 0, true, 0 ); ind += ob_intro_2_b.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_intro_2_a, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 0, 0, true, 0 ); ind += ob_intro_2_a.tileset->numTile;

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



	//wb_wait(3*getHz(), joy1_pressed_btn );


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



//   VDP_drawImageEx ( PLAN_B, &ob_intro_3_a, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind),  0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_3_a.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_intro_3_b, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 10, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_3_b.tileset->numTile;
	VDP_drawImageEx ( PLAN_B, &ob_intro_3_a, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind),  0, 0, true, 0 ); ind += ob_intro_3_a.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_intro_3_b, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 10, 0, true, 0 ); ind += ob_intro_3_b.tileset->numTile;

	VDP_setHorizontalScroll ( PLAN_B, -80 );

	VDP_setPalette   ( PAL3, os_intro_3_c.pal );



	u16 i;
	u16 attr = 0;


	s16 gota_x = -65;
	s16 gota_y = 50;
	SPRITESET gota;
	attr = TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind );

	spriteset_new  ( &gota,   (struct genresSprites*) &os_intro_3_d, 1, 1 );
	spriteset_load ( &gota, ind, 0 );
	spriteset_show ( &gota, 0, gota_x, gota_y, attr );

	ind += 2;



	s16 jon_x = -180;
	SPRITESET jon;
	attr = TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind );

	spriteset_new  ( &jon,   (struct genresSprites*) &os_intro_3_c, 4, 4 );
	spriteset_load ( &jon, ind, 0 );
	spriteset_show ( &jon, 1, jon_x, 32, attr );




	VDP_setPalette ( PAL0, font_getPalette() );


	s16 values_a [ 19 ];
	s16 values_b [ 28 ];

	memsetU16(values_a,   0, 19 );
	memsetU16(values_b, -80, 28 );

	VDP_setScrollingMode ( HSCROLL_TILE, VSCROLL_PLANE );
//	VDP_setHorizontalScrollTile ( PLAN_A, 0, values_a, 19, true ); VDP_waitDMACompletion();
//	VDP_setHorizontalScrollTile ( PLAN_B, 0, values_b, 28, true ); VDP_waitDMACompletion();
	VDP_setHorizontalScrollTile ( PLAN_A, 0, values_a, 19, 0 );
	VDP_setHorizontalScrollTile ( PLAN_B, 0, values_b, 28, 0 );


	SYS_enableInts();
   VDP_setEnable ( true );


	frases_tt_write ( NOTA );




	s16 curval = 0;
   s16 inc_x_b = -80;
	u16 values [ 28 ];

   i = 0;

   while ( inc_x_b )
   {
      if ( i % 2 == 0 )
      {
			memsetU16 ( values, ++inc_x_b, 28 );

			VDP_setHorizontalScrollTile ( PLAN_B, 0, values, 28, true );

         jon_x+=2;

         if (  inc_x_b % 4 == 0  &&  inc_x_b > -30  )
			{
			   gota_y += 1;
			}

         spriteset_move ( &jon,  jon_x,    32 ) ;
         spriteset_move ( &gota, jon_x+55, gota_y ) ;
      }

		if ( i % 3 == 0 )
		{
			memsetU16 ( values, ++curval, 19 );
         //VDP_setHorizontalScrollTile ( PLAN_A, 0, values, 19, true );
         VDP_setHorizontalScrollTile ( PLAN_A, 0, values, 19, 0 );
		}

      //VDP_waitDMACompletion();
      VDP_updateSprites(80,1);

      VDP_waitVSync();

      JoyReader_update();

      if ( joy1_pressed_abc|joy1_pressed_start )
      {
         goto fin;
      }


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





static u8 _escena_4 ( int repeat )
{
	go  = 0;
	ind = TILE_USERINDEX;


	VDP_setEnable ( false );
	SYS_disableInts();


	VDP_interruptFade();
	VDP_resetSprites();
	VDP_updateSprites(80,1);

	resetScreen();
	resetScroll();


//   VDP_drawImageEx ( PLAN_B, &ob_intro_4_b, TILE_ATTR_FULL(PAL1, 0, 0, 0, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_4_b.tileset->numTile;
//   VDP_drawImageEx ( PLAN_A, &ob_intro_4_a, TILE_ATTR_FULL(PAL2, 0, 0, 0, ind), 0, 0, true, true ); VDP_waitDMACompletion(); ind += ob_intro_4_a.tileset->numTile;
	VDP_drawImageEx ( PLAN_B, &ob_intro_4_b, TILE_ATTR_FULL(PAL1, 0, 0, 0, ind), 0, 0, true, 0 ); ind += ob_intro_4_b.tileset->numTile;
	VDP_drawImageEx ( PLAN_A, &ob_intro_4_a, TILE_ATTR_FULL(PAL2, 0, 0, 0, ind), 0, 0, true, 0 ); ind += ob_intro_4_a.tileset->numTile;

	VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );

	VDP_setHorizontalScroll ( PLAN_A, -116 );
	VDP_setVerticalScroll   ( PLAN_A, 0 );




	//VDP_loadTileData ( os_intro_4_c.sprites[0], ind, 5*4*5*4, true ); VDP_waitDMACompletion();




	SPRITESET griel;
	u16 tile_attr = TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind );

	spriteset_new  ( &griel,   (struct genresSprites*) &os_intro_4_c, 5, 5 );
	spriteset_load ( &griel, ind, 0 );
	spriteset_show ( &griel, 0, 285, 0, tile_attr ); // x = 285

//font_init ( );
	VDP_setPalette( PAL3, os_intro_4_c.pal );

	VDP_setTextPalette(PAL0);

	SYS_enableInts();
	VDP_setEnable ( true );






	u16 i = 0;
	s16 inc_x =0;

	while ( ++i )
	{
		while ( SYS_isInHIntCallback() );

		++inc_x;

		//_draw_griel ( 285-inc_x, ind );
		spriteset_move ( &griel, 285 - inc_x, 0) ;
		VDP_setHorizontalScroll ( PLAN_A, + inc_x - 116 );

		if ( inc_x == 116 || joy1_pressed_btn  )
		{
			break;
		}


		VDP_updateSprites(80,1);

		VDP_waitVSync();

		JoyReader_update();

		if ( joy1_pressed_abc|joy1_pressed_start )
		{
			goto fin;
		}

	}


	if ( !repeat )
	{
		_frases_tt_init ( 10 );

		frases_tt_write ( NOTA );
		frases_tt_write ( GRIEL );
		frases_tt_write ( NOTA );
	}
	else
	{
		_frases_tt_init( 11 );
		frases_tt_write( NOTA );
	}


fin:

	VDP_fadeOutAll ( 30, false );

	return go;
}




void screen_ob_intro_2_b_f( )
{
   if ( cont % 5 == 0 )
   {
      VDP_setPalette ( PAL1, ( cont % 10 == 0 ) ? ob_intro_2_b.palette->data : paleta );
   }

   ++cont;
}





void screen_intro ( u8 jump )
{
//	if ( DEV ) return;



	music_stop();
	vel_text = 70;

	displayInit();
	displayOff(0);

	SYS_disableInts();
	VDP_setTextPalette(PAL0);

	font_init();

	resetScroll();
	resetSprites();
	resetScreen();
	resetPalettes ( );

	VDP_setPlanSize ( 64, 64 );

	SYS_enableInts();


	while ( jump )
	{
             if ( jump == 1 ) jump = _escena_1 ( );
		else if ( jump == 2 ) jump = _escena_2 ( );
		else if ( jump == 3 ) jump = _escena_3 ( );
		else if ( jump == 4 ) jump = _escena_4 ( 0 );
		else if ( jump == 5 ) jump = _escena_4 ( 1 );
	}

	vint_setOb_intro_2_b_f(false);
	VDP_waitVSync();
	VDP_interruptFade();

	displayOff ( 30 );
}
