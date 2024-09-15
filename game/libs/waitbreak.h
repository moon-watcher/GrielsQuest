#pragma once

#ifndef _WAITBREAK_H_
#define _WAITBREAK_H_

#include "joyreader.h"


#define WAITBREAK



#define wb_fade(botones)          \
{                                 \
    while ( PAL_isDoingFade() )   \
    {                             \
        JoyReader_update ( );     \
                                  \
        if ( (botones) )          \
        {                         \
            WAITBREAK;            \
        }                         \
                                  \
        VDP_waitVSync ( );        \
    }                             \
}


#define wb_wait(wait,botones)     \
{                                 \
    u16 tiempo = (wait);          \
                                  \
    while ( tiempo-- )            \
    {                             \
        JoyReader_update ( );     \
                                  \
        if ( (botones) )          \
        {                         \
            WAITBREAK;            \
        }                         \
                                  \
        VDP_waitVSync ( );        \
    }                             \
}



#endif // _WAITBREAK_H_
