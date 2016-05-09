#include <genesis.h>
#include <genres.h>

#define DISPLAY_BLACK_TILE   16
#define PLAN_HIDE_MS         4



//const u16 palette_alf_grey[16]  = { 0x0000, 0x0111, 0x0222, 0x0333, 0x0444, 0x0555, 0x0666, 0x0777, 0x0888, 0x0999, 0x0AAA, 0x0BBB, 0x0CCC, 0x0DDD, 0x0EEE, 0x0FFF } ;
//const u16 palette_alf_blue[16]  = { 0x0F00, 0x0F11, 0x0F22, 0x0F33, 0x0F44, 0x0F55, 0x0F66, 0x0F77, 0x0F88, 0x0F99, 0x0FAA, 0x0FBB, 0x0FCC, 0x0FDD, 0x0FEE, 0x0FFF } ;
//const u16 palette_alf_green[16] = { 0x00F0, 0x01F1, 0x02F2, 0x03F3, 0x04F4, 0x05F5, 0x06F6, 0x07F7, 0x08F8, 0x09F9, 0x0AFA, 0x0BFB, 0x0CFC, 0x0DFD, 0x0EFE, 0x0FFF } ;
//const u16 palette_alf_red[16]   = { 0x000F, 0x011F, 0x022F, 0x033F, 0x044F, 0x055F, 0x066F, 0x077F, 0x088F, 0x099F, 0x0AAF, 0x0BBF, 0x0CCF, 0x0DDF, 0x0EEF, 0x0FFF } ;



//struct genresTiles *wuw;

void tool_planHide              ( );
void tool_planHide_Ex           ( u16 plan );
void tool_planHide_and_sprites  ( );
void tool_showBmp               ( u16 pal, struct genresTiles *grt, u16 tile, u16 plan, u16 x, u16 y, u8 pal_steps );
void tool_showBmp_bn            ( u16 pal, struct genresTiles *grt, u16 tile, u16 plan, u16 x, u16 y, u8 pal_steps );
void tool_typeText              ( u8 *str, u8 x, u8 y, u16 ms );
u16  tool_typeTextHalt          ( u8 *str, u8 x, u8 y, u16 ms, u16 joy, u16 buttons );
void tool_reset                 ( );
//void tool_deleteArea            ( u16 plan, u8 x, u8 y, u8 width, u8 height );

//void tool_waitWhilePessed       ( u16 joy, u16 btn );
//void tool_setPalette            ( u16 pal, u16 *colors );
//void tool_clearLinesText        ( );


u16 sprintf(char *buffer, const char *fmt, ...);
