#ifndef _BIGBOY_H_
#define _BIGBOY_H_



#define BIGBOY_START   25
#define BIGBOY_MAX     45


typedef struct
{
	u16 objeto;
	s8  index;
	s16 x;
	s16 y;
}
BIGBOY;


void    bigboy_init       ( );
BIGBOY *bigboy            ( );
BIGBOY *bigboy_get        ( u16 i );
BIGBOY *bigboy_getByPos   ( s16 x, s16 y );
BIGBOY *bigboy_getByIndex ( s8 index );
void    bigboy_set        ( s16 x, s16 y, u16 objeto );
u8      bigboy_count      ( );
void    bigboy_show       ( );

#endif
