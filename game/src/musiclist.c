#include <genesis.h>
#include "../libs/music.h"
#include "../inc/musiclist.h"
#include "../res/xgmres.h"



static const MUSIC _list [] =
{
	{ MUSIC_TYPE_XGM, "Intro",             (u8*) &vgm_intro      },
	{ MUSIC_TYPE_XGM, "Title",             (u8*) &vgm_title      },
	{ MUSIC_TYPE_XGM, "Map",               (u8*) &vgm_map        },
	{ MUSIC_TYPE_XGM, "New round",         (u8*) &vgm_round      },
	{ MUSIC_TYPE_XGM, "Round clear",       (u8*) &vgm_sclear     },
	{ MUSIC_TYPE_XGM, "Game over",         (u8*) &vgm_gover      },
	{ MUSIC_TYPE_XGM, "Risky woods 1",     (u8*) &vgm_bosque_1   },
	{ MUSIC_TYPE_XGM, "Risky woods 2",     (u8*) &vgm_bosque_2   },
	{ MUSIC_TYPE_XGM, "Abu's depths 1",    (u8*) &vgm_desierto_1 },
	{ MUSIC_TYPE_XGM, "Abu's depths 2",    (u8*) &vgm_desierto_2 },
	{ MUSIC_TYPE_XGM, "Abu's depths 3",    (u8*) &vgm_desierto_3 },
	{ MUSIC_TYPE_XGM, "Murciano's lair 1", (u8*) &vgm_hielo_1    },
	{ MUSIC_TYPE_XGM, "Murciano's lair 2", (u8*) &vgm_hielo_2    },
	{ MUSIC_TYPE_XGM, "Murciano's lair 3", (u8*) &vgm_hielo_3    },
	{ MUSIC_TYPE_XGM, "Chumino beach 1",   (u8*) &vgm_playa_1    },
	{ MUSIC_TYPE_XGM, "Chumino beach 2",   (u8*) &vgm_playa_2    },
	{ MUSIC_TYPE_XGM, "Chumino beach 3",   (u8*) &vgm_playa_3    },
	{ MUSIC_TYPE_XGM, "Gate",              (u8*) &vgm_gate       },
	{ MUSIC_TYPE_XGM, "Kbrah's castle 1",  (u8*) &vgm_caverna_1  },
	{ MUSIC_TYPE_XGM, "Kbrah's castle 2",  (u8*) &vgm_caverna_2  },
	{ MUSIC_TYPE_XGM, "Kbrah's castle 3",  (u8*) &vgm_caverna_3  },
	{ MUSIC_TYPE_XGM, "Ending 1",          (u8*) &vgm_ending_1   },
	{ MUSIC_TYPE_XGM, "Ending 3",          (u8*) &vgm_ending_3   },
	{ MUSIC_TYPE_XGM, "Boss",              (u8*) &vgm_boss       },
	{ MUSIC_TYPE_XGM, "Boss clear",        (u8*) &vgm_fsclear    },
	{ MUSIC_TYPE_XGM, "Staff",             (u8*) &vgm_staff      },
	{ MUSIC_TYPE_XGM, "Extra",             (u8*) &vgm_extra      },
};



MUSIC *musiclist_get ( u8 nb )
{
	return (MUSIC*) &_list[nb];
}


void musiclist_play ( u8 nb )
{
	music_play ( (MUSIC*) &_list[nb] );
}
