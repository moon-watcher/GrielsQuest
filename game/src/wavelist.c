#include <genesis.h>
#include "../libs/wave.h"
#include "../res/waveres.h"
#include "../inc/wavelist.h"



static const WAVE _list [ ] =
{
	{ 64, "Ding",   (u8*) &wave_ding,         sizeof(wave_ding),         1, SOUND_PCM_CH1 },
	{ 65, "Hooo!",  (u8*) &wave_griel_hooo,   sizeof(wave_griel_hooo),   1, SOUND_PCM_CH2 },
	{ 66, "Ia!",    (u8*) &wave_griel_ia,     sizeof(wave_griel_ia),     1, SOUND_PCM_CH3 },
	{ 67, "Ouch 1", (u8*) &wave_griel_ouch_1, sizeof(wave_griel_ouch_1), 1, SOUND_PCM_CH4 },
	{ 68, "Ouch 2", (u8*) &wave_griel_ouch_2, sizeof(wave_griel_ouch_2), 1, SOUND_PCM_CH4 },
};



void wavelist_play ( u8 nb )
{
	wave_play ( (WAVE*) & _list [ nb ] );
}

