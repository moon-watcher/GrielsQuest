#include "../inc/include.h"
#include "../inc/colores_textos.h"
#include "../res/xgmres.h"
#include "../inc/genres_externs.h"


#undef  WAITBREAK
#define WAITBREAK  { if ( joy1_pressed_abc ) goto next; if ( joy1_pressed_start ) goto fin; }




static u16 cont = 0;
static u16 paleta[16] = {};
static u16 go = 0;
static u16 ind = 0;
static u16 vel_text = 0;


#define GONEXT             \
    next:                  \
        displayOff ( 5 );  \
        ++go;              \
        return go;

#define GOEND              \
	fin:                   \
        music_stop();      \
        return 0;



static void _frases_tt_init ( u16 grupo )
{
	tt_init ( );
	frases_init ( grupo );
	tt_info.buttons = ( BUTTON_A|BUTTON_B|BUTTON_C|BUTTON_START );
	tt_info.speed = 2;
}





static u8 _escena_1 ( )
{
	// goto end;

    musiclist_play( MUSIC_INTRO );

	ind = TILE_USER_INDEX;

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

    devu0 = 0;
	FRASES_TT_WRITE ( NARRADOR, next, fin );



	SYS_disableInts();

	resetScreen();
	resetSprites();
	resetScroll();

	VDP_drawImageEx ( BG_A, &ob_intro_1_a, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 0, 1, false, 0 );
	ind += ob_intro_1_a.tileset->numTile;

	SYS_enableInts();


	PAL_fadeToPalette ( PAL1, ob_intro_1_a.palette->data, vel_show, true );
	


	wb_fade ( joy1_pressed_abc | joy1_pressed_start );



	FRASES_TT_WRITE ( NARRADOR, next, fin );




	SYS_disableInts();
	VDP_drawImageEx ( BG_A, &ob_intro_1_c, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, ind), 27, 1, false, 0 );
	SYS_enableInts();

	PAL_fadeToPalette ( PAL2, ob_intro_1_c.palette->data, vel_show, true );

	wb_fade ( joy1_pressed_abc | joy1_pressed_start );

	FRASES_TT_WRITE ( NARRADOR, next, fin );



	SYS_disableInts();
	VDP_drawImageEx ( BG_A, &ob_intro_1_c, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 27, 1, false, 0 );  ind += ob_intro_1_c.tileset->numTile;
	SYS_enableInts();

	//wb_wait ( getHz(), joy1_pressed_btn );

	PAL_fadeOutPalette ( PAL1, vel_show, true );



	// oscurece los Kbrah's de los lados
	//vel_show = 120;
	s16 i = vel_show;

	while( i-- )
	{
		wb_wait ( 1, joy1_pressed_abc | joy1_pressed_start );

		if ( i == 10 )
		{
			PAL_interruptFade();
			break;
		}
	}
	//


	SYS_disableInts();
	VDP_setVerticalScroll ( BG_B, i-100 );
	VDP_drawImageEx ( BG_B, &ob_intro_1_b, TILE_ATTR_FULL(PAL3, true, false, false, ind), 12, 0, true, 0 );
	SYS_enableInts();

	for ( i = 250; i >= 0; i -= 6 )
	{
		SYS_disableInts();
		VDP_setVerticalScroll ( BG_B, i );
		SYS_enableInts();

		wb_wait ( 1, joy1_pressed_abc | joy1_pressed_start );
	}

	SYS_disableInts();
	VDP_setVerticalScroll ( BG_B, 0 );
	PAL_setPalette ( PAL0, font_getPalette(), CPU);
	SYS_enableInts();

	FRASES_TT_WRITE ( NARRADOR, next, fin );




end:
    GONEXT
    GOEND
}




static u8 _escena_2()
{
	// goto end;

	cont = 0;
	ind  = TILE_USER_INDEX;

	displayOff(0);
	SYS_disableInts ( );

	PAL_interruptFade ( );
	resetScroll ( );

	VDP_drawImageEx ( BG_B, &ob_intro_2_b, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind), 0, 0, 0, 0 ); ind += ob_intro_2_b.tileset->numTile;
	VDP_drawImageEx ( BG_A, &ob_intro_2_a, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 0, 0, 0, 0 ); ind += ob_intro_2_a.tileset->numTile;

	u16 i;
	for ( i=0; i<16; i++)
	{
		paleta[i] = ob_intro_2_b.palette->data[i];
	}

	paleta[1] = ob_intro_2_b.palette->data[2];
	paleta[2] = ob_intro_2_b.palette->data[1];

	preparePal ( PAL0, font_getPalette() );
	preparePal ( PAL1, ob_intro_2_b.palette->data );
	preparePal ( PAL2, ob_intro_2_a.palette->data );

	SYS_enableInts();
	displayOn(0);

	vint_setOb_intro_2_b_f(true);

	_frases_tt_init ( 8 );

	FRASES_TT_WRITE ( NARRADOR, next, fin );

end:
    GONEXT
    GOEND
}




static u8 _escena_3 ()
{
	ind = TILE_USER_INDEX;

	vint_setOb_intro_2_b_f(false);

   	displayOff(0);
	resetScreen();
	preparePal(PAL0, font_getPalette());
	displayOn(0);

	_frases_tt_init ( 9 );
	FRASES_TT_WRITE ( NARRADOR, next, fin );
	FRASES_TT_WRITE ( NOTA, next, fin );

	displayOff(0);	
	VDP_setPlaneSize ( 64, 32, false );
	PAL_interruptFade();
	resetScreen ();
	resetScroll ();

	s16 values_a[19];
	s16 values_b[28];
	u16 attr = 0;
	s16 gota_x =  -65, gota_y = 50;
	s16 jon_x  = -180, jon_y  = 32;
	s16 curval = 0;
	s16 inc_x_b = -81;	
	SPRITESET gota, jon;

	VDP_setScrollingMode ( HSCROLL_TILE, VSCROLL_PLANE );
	VDP_setHorizontalScrollTile ( BG_A, 0, values_a, 19, 0 );
	VDP_setHorizontalScrollTile ( BG_B, 0, values_b, 28, 0 );

	VDP_drawImageEx ( BG_B, &ob_intro_3_a, TILE_ATTR_FULL(PAL1, false, FALSE, FALSE, ind),  0, 0, 0, 0 ); ind += ob_intro_3_a.tileset->numTile;
	VDP_drawImageEx ( BG_A, &ob_intro_3_b, TILE_ATTR_FULL(PAL2, false, FALSE, FALSE, ind), 10, 0, 0, 0 ); ind += ob_intro_3_b.tileset->numTile;

	memset(values_b, inc_x_b, 28*2);
	VDP_setHorizontalScrollTile(BG_B, 0, values_b, 28, DMA);
	SYS_doVBlankProcess();

	spriteset_new  ( &jon,  &os_intro_3_c, 4, 4 );
	spriteset_new  ( &gota, &os_intro_3_d, 1, 1 );
	spriteset_load ( &jon,  ind, 0 );
	spriteset_load ( &gota, ind, 0 );
	spriteset_show ( &jon,  1, jon_x,  jon_y,  TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind ) ); ind += 2;
	spriteset_show ( &gota, 0, gota_x, gota_y, TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind ) ); ind += 2;

	preparePal(PAL0, font_getPalette());
	preparePal(PAL1, ob_intro_3_a.palette->data);
	preparePal(PAL2, ob_intro_3_b.palette->data);
	preparePal(PAL3, os_intro_3_c.pal);

	displayOn(0);

	FRASES_TT_WRITE ( NOTA, next, fin );


	for (int i=0; inc_x_b<=0; i++ )
	{
		memset(values_a, curval,  19*2);
		memset(values_b, inc_x_b, 28*2);

		JoyReader_update();
		if ( joy1_pressed_start ) goto fin;
		if ( joy1_pressed_abc   ) goto next;
		if ( i % 2 == 0 ) inc_x_b+=2;
		if ( i % 2 == 0 ) jon_x+=4;
		if ( i % 3 == 0 ) curval+=2;
		if ( inc_x_b % 3 == 0 && inc_x_b > -30) ++gota_y;

		spriteset_move ( &jon,  jon_x,    32 ) ;
		spriteset_move ( &gota, jon_x+55, gota_y ) ;

		VDP_setHorizontalScrollTile(BG_A, 0, values_a, 19, DMA);
		VDP_setHorizontalScrollTile(BG_B, 0, values_b, 28, DMA);

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();
	}

	FRASES_TT_WRITE ( CORTAZAR, next, fin );
	FRASES_TT_WRITE ( NOTA, next, fin );

	GONEXT
	GOEND
}





static u8 _escena_4 ( int repeat )
{
	ind = TILE_USER_INDEX;


	displayOff(0);//VDP_setEnable ( false );
	SYS_disableInts();


	PAL_interruptFade();
	VDP_resetSprites();
	VDP_updateSprites(80,1);

	resetScreen();
	resetScroll();


	VDP_drawImageEx ( BG_B, &ob_intro_4_b, TILE_ATTR_FULL(PAL1, 0, 0, 0, ind), 0, 0, 0, 0 ); ind += ob_intro_4_b.tileset->numTile;
	VDP_drawImageEx ( BG_A, &ob_intro_4_a, TILE_ATTR_FULL(PAL2, 0, 0, 0, ind), 0, 0, 0, 0 ); ind += ob_intro_4_a.tileset->numTile;

	VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );

	VDP_setHorizontalScroll ( BG_A, -116 );
	VDP_setVerticalScroll   ( BG_A, 0 );





	SPRITESET griel;
	u16 tile_attr = TILE_ATTR_FULL ( PAL3, 0, 0, 0, ind );

	spriteset_new  ( &griel,   (struct genresSprites*) &os_intro_4_c, 5, 5 );
	SYS_enableInts();
	spriteset_load ( &griel, ind, 0 );
	SYS_disableInts();
	spriteset_show ( &griel, 0, 285, 0, tile_attr ); // x = 285

//font_init ( );
	preparePal( PAL3, os_intro_4_c.pal );//PAL_setPalette( PAL3, os_intro_4_c.pal );
	preparePal( PAL1, ob_intro_4_b.palette->data );
	preparePal( PAL2, ob_intro_4_a.palette->data );

	VDP_setTextPalette(PAL0);

	SYS_enableInts();
	displayOn(0);//VDP_setEnable ( true );



	s16 i = 0;

	while ( i++ < 116 )
	{
		spriteset_move ( &griel, 285 - i, 0) ;
		SYS_disableInts();
		VDP_setHorizontalScroll ( BG_A, i - 116 );
		SYS_enableInts();

		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();

		JoyReader_update();

		if ( joy1_pressed_abc|joy1_pressed_start )
		{
			goto fin;
		}
	}


	if ( !repeat )
	{
		_frases_tt_init ( 10 );

		FRASES_TT_WRITE ( NOTA, next, fin );
		FRASES_TT_WRITE ( GRIEL, next, fin );
		FRASES_TT_WRITE ( NOTA, next, fin );
	}
	else
	{
		_frases_tt_init( 11 );
		FRASES_TT_WRITE( NOTA, next, fin );
	}


next:
	music_stop();
	displayOff ( 5 );
	++go;
	return go;

fin:
	music_stop();
	return 0;
}




void screen_ob_intro_2_b_f( )
{
   if ( cont % 5 == 0 )
   {
      PAL_setPalette ( PAL1, ( cont % 10 == 0 ) ? ob_intro_2_b.palette->data : paleta, CPU );
   }

   ++cont;
}





void screen_intro ( u8 jump )
{
    if ( DEV > 1 ) return;


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

	VDP_setPlaneSize ( 64, 64, false );

	SYS_enableInts();

    go = jump;

    if ( go == 5 )
    {
        _escena_4 ( 1 );
    }
    else
    {
        while ( go )
        {
                 if ( go == 1 ) { go = _escena_1 ( ); }
            else if ( go == 2 ) { go = _escena_2 ( ); }
            else if ( go == 3 ) { go = _escena_3 ( ); }
            else if ( go == 4 ) { go = _escena_4 ( 0 ); break; }
        }
    }

	music_stop();

	vint_setOb_intro_2_b_f(false);
	SYS_doVBlankProcess();
	PAL_interruptFade();

	displayOff ( 30 );
	VDP_setPlaneSize ( 64, 32, false );
}
