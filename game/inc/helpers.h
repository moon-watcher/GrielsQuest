#define IS      ==
#define AND     &&
#define OR      ||
#define NOT     !
#define ISNT    !=

#define BUTTON_ABC   ( BUTTON_A | BUTTON_B | BUTTON_C )
#define BUTTON_ABCS  ( BUTTON_ABC | BUTTON_START )




#define frases_tt_write(color)    \
{                                 \
	u8 *cadena = frases_next ( ) ; \
	tt_write ( (color), cadena ) ; \
}









//u8  *my_strtok                  ( u8 *string, u8 delimitador );
u32  my_strtol                  ( u8 *cadena );
void my_strpad                  ( u8 *str, const u8 size, u8 type );
u16  my_strcmp                  ( u8 *str1, u8 *str2 );
void drawInt                    ( u32 number, u8 x, u8 y, u8 leading_zeros );
void drawUInt                   ( u32 number, u8 x, u8 y, u8 leading_zeros );
void drawUIntBG                 ( u32 number, u8 x, u8 y, u8 leading_zeros, u16 plan, u16 flags );
void showFPS                    ( );
u32  ntsc2pal                   ( u32 value );
u8   getHz                      ( );
inline u16 between              ( s32 min, s32 nb, s32 max );
void resetPalettes              ( );
void resetVRAM                  ( );
void resetScroll                ( );
void resetSprites               ( );
void resetScreen                ( );
void fadeIn                     ( u16 pal0[16], u16 pal1[16], u16 pal2[16], u16 pal3[16], u16 numframe, u8 async );

void VDP_setSpriteAttributes    ( u16 index, u16 tile_attr );
void VDP_setSpriteVRAM          ( u16 index, u16 pos );
void VDP_setSpritePiority       ( u16 index, u16 high );

u16  in_array                   ( u16 needle, u16 array[] );
