#include <genesis.h>
#include "wave.h"


void wave_play ( WAVE *w )
{
	SND_setPCM_XGM       ( w->id, (u8*)w->data, w->size );
	SND_startPlayPCM_XGM ( w->id, w->priority, w->channel );
}


void wave_stop ( WAVE *w )
{
	SND_stopPlayPCM_XGM ( w->channel );
}
