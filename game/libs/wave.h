#pragma once

#ifndef _WAVE_H_
#define _WAVE_H_

typedef struct
{
	u8   id;
	u8  *title;
	u8  *data;
	u16  size;
	u8   priority;
	u8   channel;
}
WAVE;


void wave_play ( WAVE *w );
void wave_stop ( WAVE *w );


#endif
