#include "../inc/include.h"
#include "../inc/colores_textos.h"



#define VEL_TEXT 70

#define WAITSECS_RET(s)                            \
	{                                               \
		u16 t = (s) * getHz();                  \
		while ( t-- )                                \
		{                                            \
			if ( joy1_pressed_abc )                   \
			{                                         \
				return;                                \
			}                                         \
			VDP_waitVSync();                          \
		}                                            \
	}

#define SALE             { if ( joy1_pressed_start ) goto fin; if ( joy1_active_abc ) vel_text = 5; else vel_text = VEL_TEXT; }
#define BUCLE            { SALE; VDP_waitVSync(); }
#define WAITSECS(s)      { u16 t = (s) * getHz(); while ( t-- ) BUCLE; }
#define WAITMS(s)        { u16 t = (s) * getHz() / 1000; while ( t-- ) BUCLE; }
#define WAITFADE         { while ( VDP_isDoingFade() ) BUCLE; }

#define TYPE(s,x,y)      {                         \
		u8 *aux = (s);                               \
		u8 i, len = strlen ( aux );                  \
		for ( i=0; i<len; i++ )                      \
		{                                            \
			u8  chr[2] = { *aux++ };                  \
			if ( chr[0] == ' ' ) continue;            \
			VDP_drawText ( chr, (x)+i, (y) );         \
			WAITMS(vel_text);                         \
		}                                            \
	}

//#define TYPEEX(c,s,x,y,m)   { _setTextColor(c); TYPE(s,x,y); WAITSECS(m);  tool_clearLinesText( ); }




#undef  WAITBREAK
#define WAITBREAK  goto fin;



static u16       vel_text = 0;
static u16       sprite = 0;
static u16       colores [ 5 ] = { };
static SPRITESET sets [ 10 ] = { };




static void _frases_tt_init ( u16 f )
{
	tt_init ( );
	frases_init ( f );


	#undef TT_A
	#undef TT_B
	#undef TT_C
	#undef TT_START

	#define TT_A       goto fin; // tt_info.go_next = true;
	#define TT_B       goto fin; // tt_info.go_next = true;
	#define TT_C       goto fin; // tt_info.go_next = true;
	#define TT_START   goto fin;

	tt_info.buttons = ( BUTTON_A|BUTTON_B|BUTTON_C|BUTTON_START );
}



void _initTextColors ( u16 color1, u16 color2, u16 color3, u16 color4, u16 color5 )
{
	colores[0] = color1; // Griel
	colores[1] = color2; // Kbrah
	colores[2] = color3; // Kbritah
	colores[3] = color4; // Notah
	colores[4] = color5; // Gorda
}



void _visible ( u8 escena, u8 sprite, bool visible, u8 segundos )
{
	// posiciones de los sprites
	const Vect2D_s16 posiciones [ 4 ] [ 7 ] =
	{
		{ // 0
		},
		{ // 1
			{  80,  80 },
			{ 240,  40 },
			{ 152,  40 },
			{   0,   0 },
			{ 240,  24 },
			{   0,   0 },
			{ 229, 120 }
		},
		{ // 2
			{   0,   0 },
			{   8,   8 },
			{   8,   8 }
		},
		{ // 3
			{ 206,  64 }
		}
	};

	s16 x = posiciones [ escena ] [ sprite ].x;
	s16 y = posiciones [ escena ] [ sprite ].y;

	if ( !visible )
	{
		x = 320;
	}

	spriteset_move ( &sets[sprite], x, y ) ;

	if ( segundos )
	{
		VDP_updateSprites(80,1);
		WAITSECS_RET(segundos);
	}
}



//static void _setTextColor ( u8 color )
//{
//	VDP_setTextPalette ( PAL0 );
//	VDP_setPaletteColor ( PAL0+1, colores[color] );
//}



static void _draw_spriteset ( SPRITESET *set, struct genresSprites *res, u8 width, u8 height, s16 x, s16 y, u16 tile_attr )
{
	spriteset_new  ( set, res, width, height );
	spriteset_load ( set, vram_new ( spriteset_tiles(set) ), 0 );
	spriteset_show ( set, sprite, x, y, tile_attr );

	sprite += spriteset_sprites ( set );
}



static void _final_1 ( )
{
	sprite = 0;

	s16 griel_x = -145;

	vram_init(VRAM_DEFAULT);

	VDP_setEnable ( false );
	SYS_disableInts ( );

	splist_reorder ( );

	//resetVRAM();
	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();


	// Fondo
	VDP_drawImageEx ( PLAN_B, &ob_f1_fondo_b, TILE_ATTR_FULL(PAL3, 0, 0, 0, vram_new ( ob_f1_fondo_b.tileset->numTile ) ),  1, 1, 0, 0 );

	// Kbrah
	VDP_drawImageEx ( PLAN_A, &ob_f1_fondo_a, TILE_ATTR_FULL(PAL1, 1, 0, 0, vram_new ( ob_f1_fondo_a.tileset->numTile ) ), 19, 2, 0, 0 );

	_draw_spriteset ( &sets[0], (struct genresSprites*) &os_f1_griel_2_32x32,   1, 1,     320,   0, TILE_ATTR(PAL2,1,0,0) ); // Cara de Griel
	_draw_spriteset ( &sets[1], (struct genresSprites*) &os_f1_kbritah_2_32x32, 2, 1,     320,   8, TILE_ATTR(PAL1,1,0,0) ); // Cara de Kbritah // --> 240
	_draw_spriteset ( &sets[2], (struct genresSprites*) &os_f1_kbrah_32x32,     2, 2,     320,   0, TILE_ATTR(PAL1,1,0,0) ); // Cara de Kbrah
	_draw_spriteset ( &sets[3], (struct genresSprites*) &os_f1_griel_1_32x32,   3, 3, griel_x,  56, TILE_ATTR(PAL2,0,0,0) ); // Griel
	_draw_spriteset ( &sets[4], (struct genresSprites*) &os_f1_kbritah_1_32x32, 2, 4,     320,  24, TILE_ATTR(PAL1,1,0,0) ); // Kbritah
	_draw_spriteset ( &sets[5], (struct genresSprites*) &os_f1_sombras_1_32x32, 3, 2,     158,  88, TILE_ATTR(PAL3,0,0,0) ); // sombra Kbrah
	_draw_spriteset ( &sets[6], (struct genresSprites*) &os_f1_sombras_2_32x32, 2, 1,     320, 120, TILE_ATTR(PAL3,0,0,0) ); // sombra Kbritah
	vdpSpriteCache[sprite-1].link = 0;

	VDP_updateSprites(80,1);

	_initTextColors ( os_f1_griel_1_32x32.pal[5], ob_f1_fondo_a.palette->data[8], os_f1_kbritah_1_32x32.pal[4], 0, 0 );

	SYS_enableInts();
	VDP_setEnable ( true );


	// Muestra la pantalla
	fadeIn ( ob_f1_fondo_b.palette->data, os_f1_kbritah_1_32x32.pal, os_f1_griel_1_32x32.pal, os_f1_sombras_2_32x32.pal, 30, true );


	// Mueve a Griel
	s16 vel = 7;

	while ( vel > 0 )
	{
		spriteset_move ( &sets[3], griel_x, 56 );

		if ( griel_x % 12 == 0 ) --vel;
		griel_x += vel;

		VDP_updateSprites(80,1);
		wb_wait ( 1, joy1_pressed_btn );
	}


	_frases_tt_init( 15 );

	//frases_tt_write( KBRAH );
	frases_tt_write( GRIEL );
	frases_tt_write( KBRAH );


	// Aparece Kbritah
	_visible ( 1, 4, true, 0 ); // Kbritah
	_visible ( 1, 6, true, 0 ); // sombra Kbrita
	VDP_updateSprites(80,1);

	// Habla Kbritah
	frases_tt_write( KBRITAH );

	// Griel y Kbrah cambia caras
	_visible ( 1, 0, true, 0 );
	_visible ( 1, 2, true, 0 );
	VDP_updateSprites(80,1);

	frases_tt_write( KBRAH );

	// kbrah y Kbritah cambian cara
	_visible ( 1, 2, false, 0 );
	_visible ( 1, 1, true, 0 );
	_visible ( 1, 0, false, 0 );
	VDP_updateSprites(80,1);

	frases_tt_write( GRIEL );
	frases_tt_write( KBRAH );


fin:
   vram_destroy();
	VDP_fadeOutAll ( 30, false );
}




static void _final_2()
{
	sprite = 0;

	vram_init(VRAM_DEFAULT);

	VDP_setEnable ( false );
	SYS_disableInts ( );

	splist_reorder ( );

	//resetVRAM();
	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();


	VDP_drawImageEx ( PLAN_B, &ob_f2_fondo_b, TILE_ATTR_FULL(PAL0, 0, 0, 0, vram_new ( ob_f2_fondo_b.tileset->numTile ) ),  1, 1, 0, 0 ); // Fondo
	VDP_drawImageEx ( PLAN_A, &ob_f2_fondo_a, TILE_ATTR_FULL(PAL1, 1, 0, 0, vram_new ( ob_f2_fondo_a.tileset->numTile ) ),  1, 1, 0, 0 ); // Rey

	_draw_spriteset ( &sets[0], (struct genresSprites*) &os_f2_griel_32x32, 4, 4,  32,  24, TILE_ATTR(PAL2,1,0,0) ); // Griel
	_draw_spriteset ( &sets[1], (struct genresSprites*) &os_f2_gorda_32x32, 1, 2, 320,   8, TILE_ATTR(PAL3,0,0,0) ); // Gorda
	_draw_spriteset ( &sets[2], (struct genresSprites*) &os_f2_pibon_32x32, 1, 2, 320,   8, TILE_ATTR(PAL3,0,0,0) ); // Pibon
	vdpSpriteCache[sprite-1].link = 0;

	VDP_updateSprites(80,1);


	// 0 Griel,
	// 1 Kbrah,
	// 2 Kbritah,
	// 3 Notah,
	// 4 Gorda
	_initTextColors ( os_f2_griel_32x32.pal[6], 0, 0, ob_f2_fondo_a.palette->data[9], ob_f3_fondo_a_1.palette->data[4] ); //recoge el color de la gorda del final3

	SYS_enableInts();
	VDP_setEnable ( true );

	VDP_waitVSync();

	// Muestra la pantalla
	fadeIn ( ob_f2_fondo_b.palette->data, ob_f2_fondo_a.palette->data, os_f2_griel_32x32.pal, os_f2_gorda_32x32.pal, 30, true );




	_frases_tt_init( 16 );

	frases_tt_write( NOTA );
	frases_tt_write( GRIEL );
	frases_tt_write( NOTA );
	frases_tt_write( GRIEL );
//	frases_tt_write( NOTA );
//	frases_tt_write( GRIEL );

	// debilucho
	if ( gamestate.dificultad == 0 )
	{
		_frases_tt_init( 17 );

		frases_tt_write( NOTA );
		frases_tt_write( GRIEL );
		frases_tt_write( NOTA );
	}
	// tipio duro o pesadilla
	else
	{
		_frases_tt_init( 18 );

		frases_tt_write( NOTA );

		_visible ( 2, 2, true, 3 ); // Pibon

		frases_tt_write( NOTA );

		_visible ( 2, 2, false, 1 ); // Pibon

		frases_tt_write( NOTA );

		_visible ( 2, 1, true,  1 ); // Gorda

		frases_tt_write( GORDA );
	}


fin:
	vram_destroy();
	VDP_fadeOutAll ( 30, false );
}




static void _final_3()
{
	sprite = 0;

	vram_init(VRAM_DEFAULT);

	VDP_setEnable ( false );
	SYS_disableInts ( );

	splist_reorder ( );

	//resetVRAM();
	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();

	VDP_drawImageEx ( PLAN_B, &ob_f3_fondo_b_1, TILE_ATTR_FULL(PAL0, 0, 0, 0, vram_new ( ob_f3_fondo_b_1.tileset->numTile ) ),  1, 1, 0, 0 ); // Fondo
	VDP_drawImageEx ( PLAN_A, &ob_f3_fondo_a_1, TILE_ATTR_FULL(PAL1, 0, 0, 0, vram_new ( ob_f3_fondo_a_1.tileset->numTile ) ),  1, 1, 0, 0 ); // Gorda

	_draw_spriteset ( &sets[0], (struct genresSprites*) &os_f3_griel_1_32x32, 4, 3, 190,  56, TILE_ATTR(PAL2,0,0,0) ); // Griel
	vdpSpriteCache[sprite-1].link = 0;

	VDP_updateSprites(80,1);


	// 0 Griel,
	// 1 Kbrah,
	// 2 Kbritah,
	// 3 Notah,
	// 4 Gorda
	_initTextColors ( os_f3_griel_1_32x32.pal[6], 0, 0, 0, ob_f3_fondo_a_1.palette->data[4] );

	SYS_enableInts();
	VDP_setEnable ( true );



	VDP_waitVSync();

	// Muestra la pantalla
	fadeIn ( ob_f3_fondo_b_1.palette->data, ob_f3_fondo_a_1.palette->data, os_f3_griel_2_32x32.pal, ob_f3_fondo_a_2.palette->data, 30, true );

//	WAITSECS(1);
//
//
//	TYPEEX ( 4, "No te escapes, pequenin",  2, 20, 2 );
//	TYPEEX ( 4, "Ven a mis brazos!",  2, 20, 3 );
//
//	// Griel Grita
//   TYPEEX ( 0, "AAAAAAHHHHHHH!!!",      2, 20, 2 );

	_frases_tt_init( 19 );

	frases_tt_write( GORDA );
	frases_tt_write( GRIEL );
	frases_tt_write( GORDA );


	if ( gamestate.dificultad < 2 )
	{
		_frases_tt_init( 20 );
		frases_tt_write( GRIEL );
	}

	// es pesadilla (2) o superior
	else
	{
		// flash blanco
		SYS_disableInts ( );

		sprite = 0;
		vram_init(VRAM_DEFAULT);

		u16 paleta_blanca[64];
		memsetU16(paleta_blanca, 0xEEE, 64);
		VDP_setPaletteColors ( 0, paleta_blanca, 64 );

		resetScreen();

		VDP_drawImageEx ( PLAN_B, &ob_f3_fondo_b_2, TILE_ATTR_FULL(PAL0, 0, 0, 0, vram_new ( ob_f3_fondo_b_2.tileset->numTile ) ),  1, 1, 0, 0 ); // Gorda
		VDP_drawImageEx ( PLAN_A, &ob_f3_fondo_a_2, TILE_ATTR_FULL(PAL1, 0, 0, 0, vram_new ( ob_f3_fondo_a_2.tileset->numTile ) ),  1, 1, 0, 0 ); // Kbritah

		_draw_spriteset ( &sets[0], (struct genresSprites*) &os_f3_griel_2_32x32, 2, 2, 320,  64, TILE_ATTR(PAL2,0,0,0) ); // Cara de Griel // 206, 64
		_draw_spriteset ( &sets[1], (struct genresSprites*) &os_f3_griel_1_32x32, 4, 3, 190,  56, TILE_ATTR(PAL2,0,0,0) ); // Griel
		_draw_spriteset ( &sets[2], (struct genresSprites*) &os_f3_gorda_32x32,   3, 3, 144,  32, TILE_ATTR(PAL0,0,0,0) ); // Cara de Gorda
		vdpSpriteCache[sprite-1].link = 0;

		VDP_updateSprites(80,1);

		// 0 Griel,
		// 1 Kbrah,
		// 2 Kbritah,
		// 3 Notah,
		// 4 Gorda
		_initTextColors ( os_f3_griel_1_32x32.pal[6], 0, ob_f3_fondo_a_2.palette->data[8], 0, os_f3_gorda_32x32.pal[6] ); //recoge el color de la gorda del final3



		SYS_enableInts();

		VDP_waitVSync();



		// Muestra la pantalla
		fadeIn ( ob_f3_fondo_b_2.palette->data, ob_f3_fondo_a_2.palette->data, os_f3_griel_2_32x32.pal, ob_f3_fondo_a_2.palette->data, 30, true );


		u16 fuerza = 20;

		while ( fuerza -- )
		{
			spriteset_move ( &sets[2], 144, 32 + fuerza * ( fuerza % 2  ? + 1 : -1));

			VDP_updateSprites(80,1);

			u16 espera = 3;
			while ( espera-- ) VDP_waitVSync();
		}

//		WAITSECS(1);
//
//
//		// Kbritah habla
//		TYPEEX ( 2, "Toma esto",      2, 20, 2 );
//
//		// Griel cambia cara
//		_visible ( 3, 0, true, 1 ); 	// Cara de Gorda
//
//		// Kbritah habla
//		TYPEEX ( 2, "Estas a salvo",      2, 20, 4 );
//
//
//		WAITSECS(100);

		_frases_tt_init( 21 );

		frases_tt_write( KBRITAH );

		_visible ( 3, 0, true, 1 );

		frases_tt_write( GRIEL );
	}

fin:
	vram_destroy();
	VDP_fadeOutAll ( 30, false );
}




static void _final_4()
{
	sprite = 0;

	vram_init(VRAM_DEFAULT);

	VDP_setEnable ( false );
	SYS_disableInts ( );

	splist_reorder ( );

	//resetVRAM();
	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();


	VDP_drawImageEx ( PLAN_B, &ob_f4_fondo_b, TILE_ATTR_FULL(PAL0, 0, 0, 0, vram_new ( ob_f4_fondo_b.tileset->numTile ) ),  1, 1, 0, 0 ); // Fondo
	VDP_drawImageEx ( PLAN_A, &ob_f4_fondo_a, TILE_ATTR_FULL(PAL1, 1, 0, 0, vram_new ( ob_f4_fondo_a.tileset->numTile ) ),  1, 1, 0, 0 ); // Moto


	_draw_spriteset ( &sets[0], (struct genresSprites*) &os_f4_griel_32x32,   2, 4, 192, -16, TILE_ATTR(PAL2,1,0,0) ); // Griel
	_draw_spriteset ( &sets[1], (struct genresSprites*) &os_f4_kbritah_32x32, 3, 4, 120,   0, TILE_ATTR(PAL3,0,0,0) ); // Kbritah
	vdpSpriteCache[sprite-1].link = 0;

	VDP_updateSprites(80,1);


	// 0 Griel,
	// 1 Kbrah,
	// 2 Kbritah,
	// 3 Notah,
	// 4 Gorda
	_initTextColors ( os_f4_griel_32x32.pal[6], 0, os_f4_kbritah_32x32.pal[8], 0, 0 );

	SYS_enableInts();
	VDP_setEnable ( true );

	VDP_waitVSync();

	// Muestra la pantalla
	fadeIn ( ob_f4_fondo_b.palette->data, ob_f4_fondo_a.palette->data, os_f4_griel_32x32.pal, os_f4_kbritah_32x32.pal, 30, true );


//	WAITSECS(1);
//
//	// Notah habla
//   TYPEEX ( 2, "Te voy a echar 50 polvos, chaval",      2, 20, 2 );
//   TYPEEX ( 0, "Tratame con cuidado",  2, 20, 1 );
//   TYPEEX ( 0, "Me pica desde que me tire a la gordarrr",  2, 20, 1 );
//   TYPEEX ( 2, "Seras cabron........",  2, 20, 1 );
//   TYPEEX ( 2, "OLVIDATE DE LOS POLVOS, GILIPOLLAS",  2, 20, 1 );
//	TYPEEX ( 0, "Pfff, pues llamo a la gorda xD",  2, 20, 1 );
//
//   WAITSECS(5);

	_frases_tt_init( 22 );

	frases_tt_write( GRIEL );
	frases_tt_write( KBRITAH );
	frases_tt_write( GRIEL );
	frases_tt_write( KBRITAH );
	frases_tt_write( GRIEL );
	frases_tt_write( KBRITAH );

fin:
	vram_destroy();
	VDP_fadeOutAll ( 30, false );
}




void screen_final ( u16 jump )
{
	VDP_setTextPalette(PAL0);

	sprite   = 0;
	vel_text = VEL_TEXT;

	resetPalettes ( );
	VDP_setPlanSize ( 64, 64 );

	musiclist_play ( MUSIC_ENDING_3 );

	if      ( jump == 1 ) _final_1 ( );
	else if ( jump == 2 ) _final_2 ( );
	else if ( jump == 3 ) _final_3 ( );
	else if ( jump == 4 ) _final_4 ( );
	else
	{
		_final_1();
		_final_2();

		if ( gamestate.dificultad > 0 )
		{
			_final_3();
		}

		if ( gamestate.dificultad > 1 )
		{
			_final_4();
		}
	}

	VDP_setPlanSize ( 64, 32 );
}


















