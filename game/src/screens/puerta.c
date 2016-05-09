#include "../inc/include.h"
#include "../inc/colores_textos.h"






static u16       _terminados;
static u16       sprite;
static u16       pos_tile_vacio;
static SPRITESET sets [ 12 ];


const u32 tile_vacio[8] = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff };
const u16 paleta[16]    = { 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000 };



static void _frases_tt_init ( u16 f )
{
	tt_init ( );
	frases_init ( f );


	#undef TT_A
	#undef TT_B
	#undef TT_C
	#undef TT_START

//	#define TT_A       tt_info.next = true;
//	#define TT_B       tt_info.next = true;
//	#define TT_C       tt_info.next = true;

	#define TT_A       goto fin;
	#define TT_B       goto fin;
	#define TT_C       goto fin;
	#define TT_START   goto fin;

	tt_info.buttons = ( BUTTON_A|BUTTON_B|BUTTON_C|BUTTON_START );

	#undef  WAITBREAK_A
	#undef  WAITBREAK_B
	#undef  WAITBREAK_C
	#undef  WAITBREAK_START

	#define WAITBREAK_A      goto fin;
	#define WAITBREAK_B      goto fin;
	#define WAITBREAK_C      goto fin;
	#define WAITBREAK_START  goto fin;

}




static void _poner_mascara()
{
	pos_tile_vacio = vram_new ( 1 );

	VDP_loadTileData ( tile_vacio, pos_tile_vacio, 1, 1 );
	VDP_fillTileMapRect ( APLAN, TILE_ATTR_FULL ( PAL0, 1, 0, 0, pos_tile_vacio ),  1,  0, 38,  1 );
	VDP_fillTileMapRect ( APLAN, TILE_ATTR_FULL ( PAL0, 1, 0, 0, pos_tile_vacio ),  1, 19, 38,  9 );
}



static void _draw_spriteset ( SPRITESET *set, struct genresSprites *res, u8 width, u8 height, s16 x, s16 y, u16 tile_attr )
{
	spriteset_new  ( set, res, width, height );
	spriteset_load ( set, vram_new ( spriteset_tiles(set) ), 1 );
	spriteset_show ( set, sprite, x, y, tile_attr );

	sprite += spriteset_sprites ( set );
}



static void _mover_escena ( s16 posicion )
{
	VDP_setVerticalScroll ( PLAN_B, posicion );

	spriteset_move ( &sets[0],  40, - (posicion)+200  );

	spriteset_move ( &sets[1],  ( _terminados >= 4 ? 204 : 320), - (posicion)+208 );
	spriteset_move ( &sets[2],  ( _terminados >= 4 ? 200 : 320), - (posicion)+272 );

	spriteset_move ( &sets[3], 153, - (posicion)+184  );
	spriteset_move ( &sets[4], 130, - (posicion)+200  );
	spriteset_move ( &sets[5], 118, - (posicion)+232  );
	spriteset_move ( &sets[6], 102, - (posicion)+249  );
	spriteset_move ( &sets[7],  86, - (posicion)+272  );

	spriteset_move ( &sets[8],  ( gamestate_terminado(0) ? 125 : 320), - (posicion)+175  );
	spriteset_move ( &sets[9],  ( gamestate_terminado(1) ? 156 : 320), - (posicion)+162  );
	spriteset_move ( &sets[10], ( gamestate_terminado(2) ? 189 : 320), - (posicion)+164  );
	spriteset_move ( &sets[11], ( gamestate_terminado(3) ? 213 : 320), - (posicion)+180  );
}



static void _mover_puerta ( s16 x, s16 y )
{
	spriteset_move ( &sets[3], 153 + x, 184 + y );
	spriteset_move ( &sets[4], 130 + x, 200 + y );
	spriteset_move ( &sets[5], 118 + x, 232 + y );
	spriteset_move ( &sets[6], 102 + x, 249 + y );
	spriteset_move ( &sets[7],  86 + x, 272 + y );
}



bool screens_puerta_have_to_show ( u8 ambiente )
{
	// si es la primera vez que entra debe mostrarse
	if (  ambiente == 4  &&  gamestate.ambientes[4] == 0  )
	{
		return true;
	}

	return false;
}



void screens_puerta ( )
{
	gamestate.visito_la_puerta = true;

	sprite = 0;
	_terminados = gamestate_cuantos_terminados();


	vram_init(1);

	VDP_setEnable ( false );
	SYS_disableInts ( );

	VDP_setPlanSize ( 64, 128 );

	splist_reorder ( );

	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();



	VDP_drawImageEx ( BPLAN, &ob_puerta_fondo_b, TILE_ATTR_FULL(PAL0, 0, 0, 0, vram_new ( ob_puerta_fondo_b.tileset->numTile ) ),  1, 1, 0, 1 ); // Fondo

	_poner_mascara();


	_draw_spriteset ( &sets[0],  (struct genresSprites*) &os_puerta_griel_16x32,      7, 3, 328,   0, TILE_ATTR(PAL1,0,0,0) ); // Griel

	_draw_spriteset ( &sets[1],  (struct genresSprites*) &os_puerta_orco_1_24x32,     2, 2,  20,  40, TILE_ATTR(PAL2,0,0,0) ); // Orc
	_draw_spriteset ( &sets[2],  (struct genresSprites*) &os_puerta_orco_2_24x24,     2, 1,  20, 100, TILE_ATTR(PAL2,0,0,0) ); // Orc

	_draw_spriteset ( &sets[3],  (struct genresSprites*) &os_puerta_puerta_1_24x16,   2, 1,  20,  10, TILE_ATTR(PAL1,0,0,0) ); // Puerta
	_draw_spriteset ( &sets[4],  (struct genresSprites*) &os_puerta_puerta_2_16x32,   5, 1,  60,  10, TILE_ATTR(PAL1,0,0,0) ); // Puerta
	_draw_spriteset ( &sets[5],  (struct genresSprites*) &os_puerta_puerta_3_32x32,   3, 2,  80,  10, TILE_ATTR(PAL1,0,0,0) ); // Puerta
	_draw_spriteset ( &sets[6],  (struct genresSprites*) &os_puerta_puerta_4_16x24,   1, 2, 100,  10, TILE_ATTR(PAL1,0,0,0) ); // Puerta
	_draw_spriteset ( &sets[7],  (struct genresSprites*) &os_puerta_puerta_5_16x24,   1, 1, 120,  10, TILE_ATTR(PAL1,0,0,0) ); // Puerta

	_draw_spriteset ( &sets[8],  (struct genresSprites*) &os_puerta_medallon_1_24x24, 1, 1,  20,  10, TILE_ATTR(PAL1,0,0,0) ); // Medallón
	_draw_spriteset ( &sets[9],  (struct genresSprites*) &os_puerta_medallon_2_24x24, 1, 1,  20,  40, TILE_ATTR(PAL1,0,0,0) ); // Medallón
	_draw_spriteset ( &sets[10], (struct genresSprites*) &os_puerta_medallon_3_24x24, 1, 1,  20,  60, TILE_ATTR(PAL1,0,0,0) ); // Medallón
	_draw_spriteset ( &sets[11], (struct genresSprites*) &os_puerta_medallon_4_24x24, 1, 1,  20, 100, TILE_ATTR(PAL1,0,0,0) ); // Medallón

	vdpSpriteCache[sprite-1].link = 0;

	VDP_updateSprites ( );

	SYS_enableInts();
   VDP_setEnable ( true );

	musiclist_play ( MUSIC_GATE );

	// Muestra la pantalla
	fadeIn ( ob_puerta_fondo_b.palette->data, os_puerta_medallon_1_24x24.pal, os_puerta_orco_2_24x24.pal, 0, 30, true );
	VDP_waitVSync();



	s16 posicion = 0;
	u16 espera = 2;

   while ( posicion/espera <= 144 )
	{
		_mover_escena ( posicion/espera );

		++posicion;

		VDP_updateSprites();
		wb_wait(1,BUTTON_ABCS);
	}

	_mover_escena ( 144 );
	VDP_updateSprites();
	VDP_waitVSync();


	//_terminados = 4;
	VDP_setTextPalette(PAL0);

	if ( _terminados == 0 )
	{
		_frases_tt_init( 12 );
		frases_tt_write( GRIEL );
	}
	else if ( _terminados < 4 )
	{
		_frases_tt_init( 13 );
		frases_tt_write( GRIEL );
		frases_tt_write( NARRADOR );
	}
	else
	{
		_frases_tt_init ( 14 );

		frases_tt_write ( YONKI );
		frases_tt_write ( GRIEL );
		frases_tt_write ( YONKI );

		VDP_fillTileMapRect (APLAN, TILE_ATTR_FULL ( PAL0, 1, 0, 0, pos_tile_vacio ),  1, 19, 38,  9 );

		s16 x= 0, i= 144;

		while ( i>35 )
		{
			if ( i%5==0 ) x-=2;
			if ( i%4==0 ) x++;

			_mover_puerta (x, -i );
			--i;

			VDP_updateSprites();
			VDP_waitVSync();
		}

		_mover_puerta(300,0);
		VDP_updateSprites();

		frases_tt_write ( GRIEL );

		//wb_wait ( 2*getHz(), BUTTON_ABCS );
	}


fin:

	VDP_fadeOutAll ( 30, false );
}
