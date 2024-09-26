#pragma once

struct typetext_info
{
	u8   x;
	u8   y;
	u8   width;
	u8   height;

	u8   inc_line;
	u8   inc_char;

	u16  speed;
	u16  wait;
	u16  color[2];
	u8   fade_out;
	u16  buttons;

	bool go_next; // go next phrase

	u16  word;
	u16  vx;
	u16  vy;

	u8   chr;
	u8   command[14];
	u16  cmd_value[2];
	s8   cmd_inc;

	bool reset_pal;
	bool reset_area_at_end;
};

void  tt_init  ( );
void  tt_clear ( );

u16  tt_write_init    ( u16 indice, u8 *cadena );
u16  tt_write_process ( u16 i,      u8 *cadena );

struct typetext_info *tt_get();
