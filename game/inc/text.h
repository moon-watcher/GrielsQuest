#pragma once

void text_init                    ( struct genresSprites *genres, u16 vram, u16 palette );
void text_reset                   ( );
void text_draw                    ( u8 *string, u8 x, u8 y, u16 ms );
void text_draw_center             ( u8 *string, u8 y, u16 ms );
u16  text_draw_sprite             ( u8 *string, u16 x, u16 y, u16 ms );
u16  text_draw_sprites_centered   ( u8 *string, u16 ms );
u16  text_draw_sprites_x_centered ( u8 *string, u16 y, u16 ms );
void text_setSprite               ( u8 next );

u16 TEXT_prepareText(u8 *, s16[]);
void TEXT_drawText_clear(u8 *, u16, u16);
void TEXT_drawText(u8 *, u16, u16);