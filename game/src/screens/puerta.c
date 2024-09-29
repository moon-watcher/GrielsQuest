#include "../inc/include.h"
#include "../inc/colores_textos.h"
#include "../inc/genres_externs.h"






static u16       _terminados = 0;
static u16       sprite = 0;
static u16       pos_tile_vacio = 0;
static SPRITESET sets [ 12 ] = {};


const u32 tile_vacio[8] = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff };
const u16 paleta[16]    = { 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000 };



static void _frases_tt_init ( u16 f )
{
	typetext_init ( );
	frases_init ( f );
	
	#undef  WAITBREAK
	#define WAITBREAK      goto fin;
}




static void _poner_mascara()
{
	pos_tile_vacio = vram_new ( 1 );

	SYS_disableInts();
	VDP_loadTileData ( tile_vacio, pos_tile_vacio, 1, 1 );
	SYS_enableInts();

	SYS_disableInts();
	VDP_fillTileMapRect ( BG_A, TILE_ATTR_FULL ( PAL0, 1, 0, 0, pos_tile_vacio ),  1,  0, 38,  1 );
	SYS_enableInts();

	SYS_disableInts();
	VDP_fillTileMapRect ( BG_A, TILE_ATTR_FULL ( PAL0, 1, 0, 0, pos_tile_vacio ),  1, 19, 38,  9 );
	SYS_enableInts();
}



static void _draw_spriteset ( SPRITESET *set, struct genresSprites *res, u8 width, u8 height, s16 x, s16 y, u16 tile_attr )
{
	spriteset_new  ( set, res, width, height );
	SYS_disableInts();
	spriteset_load ( set, vram_new ( spriteset_tiles(set) ), 0 );
	SYS_enableInts();
	spriteset_show ( set, sprite, x, y, tile_attr );

	sprite += spriteset_sprites ( set );
}



static void _mover_escena ( s16 posicion )
{
	VDP_setVerticalScroll ( BG_B, posicion );

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



bool screen_puerta_have_to_show ( u8 ambiente )
{
	if ( gamestate.dificultad > 2 )
	{
		return false;
	}

	if ( ambiente == 4 )
	{
		if ( !puerta_abierta )
		{
			return true;
		}

		if ( !( gamestate.ambientes[0] == level_list [ 0 ] [ gamestate.dificultad ].cuantos &&
				gamestate.ambientes[1] == level_list [ 1 ] [ gamestate.dificultad ].cuantos &&
				gamestate.ambientes[2] == level_list [ 2 ] [ gamestate.dificultad ].cuantos &&
				gamestate.ambientes[3] == level_list [ 3 ] [ gamestate.dificultad ].cuantos ) )
		{
			return true;
		}
	}

	return false;
}



u16 screen_puerta ( )
{
	u16 ret = 0;
	gamestate.visito_la_puerta = true;

	sprite = 0;
	_terminados = gamestate_cuantos_terminados();



	if ( _terminados >= 4 )
	{
		ret = SCREEN_JUMP_TO_NEWGAME;
		puerta_abierta = 1;
	}


	vram_init(1);

	displayOff(0);//VDP_setEnable ( false );
	SYS_disableInts ( );

	VDP_setPlaneSize ( 64, 64, false );

	splist_reorder ( );

	resetPalettes();
	resetScroll();
	resetSprites();
	resetScreen();


	SYS_disableInts();
    VDP_drawImageEx ( BG_B, &ob_puerta_fondo_b, TILE_ATTR_FULL(PAL0, 0, 0, 0, vram_new ( ob_puerta_fondo_b.tileset->numTile ) ),  1, 1, 0, 0 ); // Fondo
    SYS_enableInts();

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

	VDP_updateSprites(80,1);

	SYS_enableInts();
	//VDP_setEnable ( true );

	musiclist_play ( MUSIC_GATE );

	// Muestra la pantalla
	fadeIn ( ob_puerta_fondo_b.palette->data, os_puerta_medallon_1_24x24.pal, os_puerta_orco_2_24x24.pal, 0, 30, true );
	SYS_doVBlankProcess();



	s16 posicion = 0;
	u16 espera = 2;

	while ( posicion/espera <= 144 )
	{
		_mover_escena ( posicion/espera );

		++posicion;

		VDP_updateSprites(80,1);
		wb_wait ( 1, joy1_pressed_abc | joy1_pressed_start );
	}

	_mover_escena ( 144 );
	VDP_updateSprites(80,1);
	SYS_doVBlankProcess();


	VDP_setTextPalette(PAL0);

	if ( _terminados == 0 )
	{
		_frases_tt_init( 12 );
		TYPETEXT( GRIEL, fin, fin );
	}
	else if ( _terminados < 4 )
	{
		_frases_tt_init( 13 );
		TYPETEXT( GRIEL, fin, fin );
		TYPETEXT( NARRADOR, fin, fin );
	}
	else
	{
		_frases_tt_init ( 14 );

		TYPETEXT ( YONKI, fin, fin );
		TYPETEXT ( GRIEL, fin, fin );
		TYPETEXT ( YONKI, fin, fin );

		SYS_disableInts();
		VDP_fillTileMapRect (BG_A, TILE_ATTR_FULL ( PAL0, 1, 0, 0, pos_tile_vacio ),  1, 19, 38,  9 );
        SYS_enableInts();

		s16 x= 0, i= 144;

		while ( i>35 )
		{
			if ( i%5==0 ) x-=2;
			if ( i%4==0 ) x++;

			_mover_puerta (x, -i );
			--i;

			VDP_updateSprites(80,1);
			SYS_doVBlankProcess();
		}

		_mover_puerta(300,0);
		VDP_updateSprites(80,1);
		SYS_doVBlankProcess();

		TYPETEXT ( GRIEL, fin, fin );


		ret = SCREEN_JUMP_TO_NEWGAME;
		puerta_abierta = 1;
	}


fin:
	vram_destroy();
	music_stop();
	displayOff ( 30 );


	VDP_setPlaneSize ( 64, 32, false );

	return ret;
}
