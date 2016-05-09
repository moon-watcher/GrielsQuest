#include <genesis.h>
#include "../libs/psg.h"
#include "../inc/psglist.h"

#include "../psg/flechas.h"
#include "../psg/back.h"
#include "../psg/item.h"
#include "../psg/key.h"
#include "../psg/kill.h"
#include "../psg/select.h"
#include "../psg/select_2.h"
#include "../psg/start.h"
#include "../psg/wrong.h"


static const PSG _list [ ] =
{
   { "Arrow",     (u8*) flechas_data,   0 },
   { "Back",      (u8*) back_data,      0 },
   { "Item",      (u8*) item_data,      0 },
   { "Key",       (u8*) key_data,       0 },
   { "Kill",      (u8*) kill_data,      0 },
   { "Select",    (u8*) select_data,    0 },
   { "Select 2",  (u8*) select_2_data,  0 },
   { "Start",     (u8*) start_data,     0 },
   { "Wrong",     (u8*) wrong_data,     0 },
};


PSG *psglist_get ( u8 nb )
{
	return (PSG*) & _list [ nb ];
}


void psglist_play ( u8 nb )
{
	PSG *m = psglist_get ( nb );
	psg_play ( m->data, m->num );
}
