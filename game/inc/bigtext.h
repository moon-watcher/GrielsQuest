#pragma once

void bigtext_init(struct genresSprites *genres, u16 vram, u16 palette);
void bigtext_reset();
void bigtext_drawTile(u8 *string, u8 x, u8 y, u16 ms);
void bigtext_drawTile_Xcentered(u8 *string, u8 y, u16 ms);
u16 bigtext_drawSprites(u8 *string, u16 x, u16 y, u16 ms);
u16 bigtext_drawSprites_XYcentered(u8 *string, u16 ms);
u16 bigtext_drawSprites_Xcentered(u8 *string, u16 y, u16 ms);
void bigtext_setSprite(u8 next);