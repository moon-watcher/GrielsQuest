#pragma once

enum
{
	LEVEL_OK = 1,
	LEVEL_PAUSED,
	LEVEL_RESTART,
	LEVEL_EXIT,
	LEVEL_HURT,
	LEVEL_COMPLETED,
	LEVEL_BACK = 1000
};



u16    game           ( );
u16    game_play      ( );
void   game_main      ( );
u16    game_ingame    ( );
void   game_level_inc ( );
LEVEL *game_get_wl    ( );
