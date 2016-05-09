enum
{
	SCREEN_JUMP_TO_HOWTOPLAY = 1,
	SCREEN_JUMP_TO_NEWGAME,
	SCREEN_JUMP_TO_CONTINUE,
	SCREEN_JUMP_TO_INTRO,
	SCREEN_JUMP_TO_TITLE,
	SCREEN_JUMP_TO_STAFF,
	SCREEN_JUMP_TO_SOUNDTEST,
	SCREEN_JUMP_TO_DIFFICULT,
	SCREEN_JUMP_TO_AMBIENT,
	SCREEN_JUMP_TO_INTRO5,
	SCREEN_JUMP_TO_PUERTA,
	SCREEN_JUMP_TO_ENDING,
	SCREEN_JUMP_TO_GAMEOVER
};


#define SCREEN_NEW_GAME 0
#define SCREEN_CONTINUE 1


enum
{
	SCREEN_CHEAT_SOUND  = 1000,
	SCREEN_CHEAT_KONAMI,
	SCREEN_CHEAT_SONIC,
	SCREEN_CHEAT_MUMMY,
	SCREEN_CHEAT_STAFF,
	SCREEN_CHEAT_ENDING
};


bool ob_intro_2_b_f;



void  screen_sega         ( u16 secs, u16 buttons, u8 on_release );
void  screen_oooklab      ( u16 secs, u16 buttons, u8 on_release );
void  screen_griels       ( u16 secs, u16 buttons, u8 on_release );
u16   screen_title        ( u16 salto );
u16   screen_title_menu_1 ( ) ;
//u16   screen_paused       ( LEVEL );
//u16   screen_options      ( );
void  screen_gameover     ( );
//void  screen_intro        ( );
void  screen_ending       ( );
void  screen_sound_test   ( );
void  screen_staff        ( );
u16   screen_ingame_how_to_play ( LEVEL wl );
//void  screen_chose_ambient   ( );
//void  screen_chose_difficult ( ) ;
void  screen_disclaimer      ( );
void  screen_ob_intro_2_b_f  ( );
