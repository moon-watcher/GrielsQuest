#include <genesis.h>
#include "wave.h"


void wave_play ( WAVE *w )
{
	XGM_setPCM       ( w->id, (u8*)w->data, w->size );
	XGM_startPlayPCM ( w->id, w->priority, w->channel );
}


void wave_stop ( WAVE *w )
{
	XGM_stopPlayPCM ( w->channel );
}
