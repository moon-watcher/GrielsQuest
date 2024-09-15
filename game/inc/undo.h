#pragma once

#define MAX_UNDO 3


bool debug1;


void undo_init      ( );
void undo_last_move ( LEVEL *level );
void undo_control   ( LEVEL *level );
void undo_save      ( u8 ply, u16 object, u16 x, u16 y );
s8   undo_rest      ( s8 x );
void undo_explode   ( );
void undo_can_undo  ( bool x );
void undo_reset_duration ( );
