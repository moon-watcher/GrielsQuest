#define PLAYER_MAX_PLAYERS    1

#define PLAYER_1 0
#define PLAYER_2 1

#define DISTANCE_TO_MOVE      16

#define PLAYER_VEL_NONE   0
#define PLAYER_VEL_NORMAL 1
#define PLAYER_VEL_FAST   2




typedef struct
{
	u16  x;
	u16  y;

	u8   key;
	u8   selected;
	u8   object;

	s8   distance_x;
	s8   distance_y;

	s8   vel_x;
	s8   vel_y;

	u16  on_arrow;
	u16  on_hurts;

	bool on_door;
}
PLAYER;

//
//#include "../inc/level.h"


PLAYER *player                 ( u8 player ) ;
void    player_init            ( u8 player ) ;
void    player_update          ( u8 player ) ;
u16     player_is_stopped      ( u8 player ) ;
bool    player_is_moving       ( u8 player ) ;
void    player_move            ( u8 player ) ;
void    player_update          ( u8 player ) ;
void    player_stop            ( u8 player ) ;
void    player_action          ( u8 player ) ;
u16     player_logic           ( u8 player, LEVEL *level );
void    player_logic_next      ( u8 player, LEVEL *level );
//void    player_on_grial        ( u8 player, LEVEL *level );
void    player_on_arrow        ( u8 player );
void    player_on_hurts        ( u8 player );
void    player_update_selected ( u8 player, u16 selected );
//void    player_update_score    ( u8 player, u16 inc );
//u8      player_get_rest        ( u8 player ) ;
//void    player_update_rest     ( u8 player );
//void    player_inc_rest        ( u8 player, s8 nb );
//void    player_hide            ( u8 player );
void    player_dead            ( u8 player, LEVEL *level, u16 exit );
void    player_inc_level       ( );
void    player_set             ( u8 nb, PLAYER ply );
u8      player_get_object      ( u8 player, LEVEL *level );
//void    player_set_score       ( u8 player, u16 socre );
//u8      player_get_selected    ( );
void    player_set_key         ( u8 player, bool has_key );
void    player_speed           ( u8 speed );
bool    player_changed_dir     ( u8 player );

void    player_control_buttons      ( LEVEL *level );
void    player_ctrldev              ( u16 *ret );
void    player_interact_with_object ( LEVEL *wl );
