#include <genesis.h>

#include "../inc/vint.h"
#include "../inc/tool.h"
#include "../inc/screens/intro.h"
#include "../inc/screens/mapa.h"
#include "../libs/psg.h"
#include "../libs/joyreader.h"

static u16 _vint_ob_intro_2_b_f = 0;
static u16 _vint_flecha_map     = 0;

void vint_init ( )
{
	_vint_ob_intro_2_b_f = 0;
	_vint_flecha_map     = 0;
}


VoidCallback *vint_callback ( )
{
	psg_callback ();

	if ( _vint_ob_intro_2_b_f ) screen_ob_intro_2_b_f( );
	if ( _vint_flecha_map     ) screen_mapa_flecha();

	//SND_setMusicTempo_XGM ( 50 );

	return 0;
}

void vint_setOb_intro_2_b_f ( u16 active ) { _vint_ob_intro_2_b_f = active; }
void vint_setFlechaMap      ( u16 active ) { _vint_flecha_map     = active; }

u16  vint_getOb_intro_2_b_f ( ) { return _vint_ob_intro_2_b_f; }
u16  vint_getFlechaMap      ( ) { return _vint_flecha_map;     }