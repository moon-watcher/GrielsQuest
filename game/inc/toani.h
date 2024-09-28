#pragma once

void toani_init             ( );
void toani_update           ( );

void toani_set_dead         ( s16 x, s16 y );
void toani_set_explosion    ( s16 x, s16 y );

void toani_draw_undo        ( );
void toani_draw_dust        ( );

void toani_delete_dead      ( );
void toani_delete_dust      ( );
void toani_delete_explosion ( );

void toani_inc_dead         ( u8 inc );
void toani_inc_dust         ( u8 inc );
void toani_inc_explosion    ( u8 inc );
