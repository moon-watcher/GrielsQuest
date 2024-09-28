#pragma once

#ifndef _PSGLIST_H_
#define _PSGLIST_H_


enum
{
   PSG_FLECHAS,
   PSG_BACK,
   PSG_ITEM,
   PSG_KEY,
   PSG_KILL,
   PSG_SELECT,
   PSG_SELECT_2,
   PSG_START,
   PSG_WRONG,

   PSG_MAX
};



typedef struct
{
	u8 *title;
	u8 *data;
	u8  num;
}
PSG;



PSG  *psglist_get  ( u8 nb );
void  psglist_play ( u8 nb );


#endif
