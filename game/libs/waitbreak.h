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
        SYS_doVBlankProcess ( );        \
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
        SYS_doVBlankProcess ( );        \
    }                             \
}



#endif // _WAITBREAK_H_
