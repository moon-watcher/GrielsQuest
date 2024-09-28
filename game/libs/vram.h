#pragma once

#ifndef _VRAM_H___BY_MUN_ // collide with SGDK, so I changed
#define _VRAM_H___BY_MUN_


#define VRAM_DEFAULT  16


void vram_init    ( u16 base );
void vram_destroy ( );
u16  vram_new     ( u16 tiles );
void vram_delete  ( u16 pos );
u16  vram_count   ( );

void vram_sample  ( );
void vram_info    ( );


#endif
