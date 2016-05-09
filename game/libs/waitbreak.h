#ifndef _WAITBREAK_H_
#define _WAITBREAK_H_

#include "joyreader.h"


#define WAITBREAK_START
#define WAITBREAK_A
#define WAITBREAK_B
#define WAITBREAK_C



#define wb_action(botones)                                                                  \
{                                                                                           \
	JoyReader_update ( );                                                                    \
	                                                                                         \
	if ( (botones) && joy1_pressed )                                                         \
	{                                                                                        \
			  if ( ( (botones) & BUTTON_START )  &&  joy1_pressed_start ) { WAITBREAK_START; } \
		else if ( ( (botones) & BUTTON_A     )  &&  joy1_pressed_a     ) { WAITBREAK_A;     } \
		else if ( ( (botones) & BUTTON_B     )  &&  joy1_pressed_b     ) { WAITBREAK_B;     } \
		else if ( ( (botones) & BUTTON_C     )  &&  joy1_pressed_c     ) { WAITBREAK_C;     } \
	}                                                                                        \
}


#define wb_fade(botones)                                                                    \
{                                                                                           \
	while ( VDP_isDoingFade() )                                                              \
	{                                                                                        \
		wb_action ( (botones) );                                                              \
		VDP_waitVSync ( );                                                                    \
	}                                                                                        \
}


#define wb_wait(wait,botones)                                                               \
{                                                                                           \
	u16 tiempo = (wait);                                                                     \
																														  \
	while ( tiempo-- )                                                                       \
	{                                                                                        \
		wb_action ( (botones) );                                                              \
		VDP_waitVSync ( );                                                                    \
	}                                                                                        \
}



#endif // _WAITBREAK_H_
