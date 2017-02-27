#define TT_UP
#define TT_DOWN
#define TT_LEFT
#define TT_RIGHT
#define TT_A
#define TT_B
#define TT_C
#define TT_START
#define TT_X
#define TT_Y
#define TT_Z
#define TT_MODE
#define TT_DIR
#define TT_BTN
#define TT_ALL

#define TT_PRE_FN
#define TT_POST_FN




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

struct typetext_info tt_info;




void  tt_init  ( );
void  tt_clear ( );

u16  _tt_write_init    ( u16 indice, u8 *cadena );
u16  _tt_write_process ( u16 i,      u8 *cadena );




#define tt_write(colorw,cadena)                                \
{                                                              \
	u16 i, boton, len = _tt_write_init ( (colorw), (cadena) );  \
	                                                            \
	for ( i = 0; i < len; i++ )                                 \
	{                                                           \
		TT_PRE_FN;                                               \
		                                                         \
		if ( ( boton = _tt_write_process ( i, (cadena) ) ) )     \
		{                                                        \
				  if ( boton == BUTTON_UP    ) { TT_UP;    }       \
			else if ( boton == BUTTON_DOWN  ) { TT_DOWN;  }       \
			else if ( boton == BUTTON_LEFT  ) { TT_LEFT;  }       \
			else if ( boton == BUTTON_RIGHT ) { TT_RIGHT; }       \
			else if ( boton == BUTTON_A     ) { TT_A;     }       \
			else if ( boton == BUTTON_B     ) { TT_B;     }       \
			else if ( boton == BUTTON_C     ) { TT_C;     }       \
			else if ( boton == BUTTON_START ) { TT_START; }       \
			else if ( boton == BUTTON_X     ) { TT_X;     }       \
			else if ( boton == BUTTON_Y     ) { TT_Y;     }       \
			else if ( boton == BUTTON_Z     ) { TT_Z;     }       \
			else if ( boton == BUTTON_MODE  ) { TT_MODE;  }       \
			else if ( boton == BUTTON_DIR   ) { TT_DIR;   }       \
			else if ( boton == BUTTON_BTN   ) { TT_BTN;   }       \
			else if ( boton == BUTTON_ALL   ) { TT_ALL;   }       \
		}                                                        \
		                                                         \
		TT_POST_FN;                                              \
	}                                                           \
}
