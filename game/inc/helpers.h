#pragma once

#define IS      ==
#define AND     &&
#define OR      ||
#define NOT     !
#define ISNT    !=

#define is      IS
#define and     AND
#define or      OR
#define not     NOT
#define isnt    ISNT

#define TYPETEXT(COLOR, ABC, START) {                                 \
	u8 *s = frases_next();                                         \
	for (u16 i = 0, l = typetext_write_init(COLOR, s); i < l; i++) \
		switch (typetext_write_process(i, s)) {                    \
			case BUTTON_START: goto START;                         \
			case BUTTON_A:                                         \
			case BUTTON_B:                                         \
			case BUTTON_C: goto ABC;                               \
		}                                                          \
}

/*
#define TYPE2(COLOR) {                                             \
	u8 *s = frases_next();                                         \
	for (u16 i = 0, l = typetext_write_init(COLOR, s); i < l; i++) \
		typetext_write_process(i, s);                              \
}
*/

//u8  *my_strtok                  ( u8 *string, u8 delimitador );
u32  my_strtol                  ( u8 *cadena );
void my_strpad                  ( u8 *str, const u8 size, u8 type );
u16  my_strcmp                  ( u8 *str1, u8 *str2 );
char *StringPadRight            ( char *string, int padded_len, char *pad );
void drawInt                    ( u32 number, u8 x, u8 y, u8 leading_zeros );
void drawUInt                   ( u32 number, u8 x, u8 y, u8 leading_zeros );
void drawUIntBG                 ( u32 number, u8 x, u8 y, u8 leading_zeros, u16 plan, u16 flags );

void showFPS                    ( );
u32  ntsc2pal                   ( u32 value );
u8   getHz                      ( );
u16 between              ( s32 min, s32 nb, s32 max );
void resetPalettes              ( );
void resetVRAM                  ( );
void resetScroll                ( );
void resetSprites               ( );
void resetScreen                ( );
void fadeIn                     ( u16 pal0[16], u16 pal1[16], u16 pal2[16], u16 pal3[16], u16 numframe, u8 async );

void VDP_setSpriteAttributes    ( u16 index, u16 tile_attr );
void VDP_setSpriteVRAM          ( u16 index, u16 pos );
void VDP_setSpritePriorityGQ      ( u16 index, u16 high );

u16  in_array                   ( u16 needle, u16 array[] );

void inc_difficulty_level       ( );


u16 strlen_countChars(const u8 *);