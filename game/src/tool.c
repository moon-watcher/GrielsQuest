#include "../inc/include.h"







void text_write ( u8 *str, u8 x, u8 y )
{
	SYS_disableInts ( );

	VDP_clearTileMapRect ( PLAN_B, x, y, strlen(str), 1 );
	VDP_drawText ( str, x, y );

	SYS_enableInts ( );
}





//void tool_setPalette ( u16 pal, u16 *colors )
//{
//	u16   i;
//	vu16 *pw = (u16 *) GFX_DATA_PORT;
//	vu32 *pl = (u32 *) GFX_CTRL_PORT;
//
//	for ( i=0; i<16; i++ )
//	{
//		u16 addr = ( pal * 16 + i ) * 2;
//		*pl = GFX_WRITE_CRAM_ADDR(addr);
//
//		*pw = *(colors++);
//	}
//}



void planHide_Ex (  VDPPlan plan )
{
	u16 width = screenWidth / 8 + 1;
	s16 desp  = screenWidth == 320 ? 0 : 4;
	u16 pal   = PAL1;

	if ( plan.value == PLAN_B.value )
	{
		pal = PAL2;
	}

	while ( width-- )
	{
      VDP_clearTileMapRect ( plan, width - 1 + desp, 0, 1, planHeight );

		waitMs ( PLAN_HIDE_MS );
	}
}


void planHide_and_sprites (  )
{
	u16 w, sprite;

	const u16 height = VDP_getPlanHeight();
	const u16 width  = VDP_getScreenWidth()  / 8 + 1;
	const s16 desp   = VDP_getScreenWidth() == 320 ? 0 : 4;

	for ( w = width; w > 0; w-- )
	{
		for ( sprite=0; sprite<MAX_SPRITE; sprite++ )
		{
			if ( vdpSpriteCache[sprite].x/8+2 >= w )
			{
				splist_hide_sprite ( sprite );
			}
		}

		VDP_updateSprites(80,1);

      VDP_clearTileMapRect ( PLAN_B, w-1+desp, 0, 1, height );
      VDP_clearTileMapRect ( PLAN_A, w-1+desp, 0, 1, height );

		waitMs ( PLAN_HIDE_MS );
	}
}



void planHide ( )
{
	u16 sprite;
	u16 width  = VDP_getScreenWidth()  / 8 + 1;
	s16 desp   = VDP_getScreenWidth() == 320 ? 0 : 4;

	for ( ; width > 0; width-- )
	{
		SYS_disableInts();

		bool update = false;
		for ( sprite=0; sprite<MAX_SPRITE; sprite++ )
		{
         // las fuentes 2x2 empiezan en el sprite 4 y terminan en el 15
//         if ( sprite >= 4 && sprite < 15 )
//         {
//            continue;
//         }

			if ( vdpSpriteCache[sprite].x/8+2  - 16 + 1 >= width )
			{
				splist_hide_sprite ( sprite );
				update = true;
			}
		}

		if ( update )
		{
			VDP_updateSprites(80,1);
		}

		VDP_clearTileMapRect ( PLAN_B, width - 1 + desp, 0, 1, planHeight );
		VDP_clearTileMapRect ( PLAN_A, width - 1 + desp, 0, 1, planHeight );

		SYS_enableInts();


		waitMs ( PLAN_HIDE_MS );
	}
}



//
//static u16 _load_black_tile ( u16 pal, u16 pos )
//{
//	const u16 attr    = TILE_ATTR_FULL ( pal, 1, 0, 0, pos );
//	const u32 tile[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
//
//	VDP_loadTileData ( tile, pos, 1, 0 );
//
//	return attr;
//}
//
//void tool_deleteArea ( u16 plan, u8 x, u8 y, u8 width, u8 height )
//{
//	u16 j, i;
//
//	const u16 attr1 = _load_black_tile ( PAL1, 16 );
//	const u16 attr2 = _load_black_tile ( PAL2, 16 );
//
//	for ( i=y; i<height+y; i++ )
//	{
//		for ( j=x; j<width+x; j++ )
//		{
//			VDP_setTileMapXY( BPLAN, attr1, j, i );
//			VDP_setTileMapXY( APLAN, attr2, j, i );
//		}
//	}
//}
//
//void tool_deleteArea ( u16 plan, u8 x, u8 y, u8 width, u8 height )
//{
//	VDP_clearTileMapRect ( BPLAN, x, y, width, height );
//	VDP_clearTileMapRect ( APLAN, x, y, width, height );
//}






void showBmp ( u16 pal, struct genresTiles *grt, u16 tile, VDPPlan plan, u16 x, u16 y, u8 pal_steps )
{
//	SYS_disableInts();
	VDP_loadTileData ( grt->tiles, tile, grt->width * grt->height, 0 );
	VDP_fillTileMapRectInc ( plan, TILE_ATTR_FULL ( pal, 1, 0, 0, tile ), x, y, grt->width, grt->height );
//	SYS_enableInts();
}



void typeText ( u8 *str, u8 x, u8 y, u16 ms )
{
	typeTextHalt ( str, x, y, ms, 0, 0 );
}


u16 typeTextHalt ( u8 *str, u8 x, u8 y, u16 ms, u16 joy, u16 buttons )
{
	u8 i, len = strlen ( str );

	for ( i=0; i<len; i++ )
	{
		u8 chr[2] = { *str++ };

		VDP_drawText ( chr, x++, y );

		//if ( joy1.state & buttons )
		if ( joy1_pressed_abc )
		{
			return 1;
		}

		waitMs(ms);
	}

	return 0;
}




//void tool_reset ()
//{
//	//SYS_disableInts();
//	VDP_setEnable ( FALSE );
//
////	resetVRAM();
////	resetScreen();
////	resetScroll();
////	resetSprites();
//
//	font_init();
////	font_setPalette();
//
//	VDP_setEnable ( TRUE );
//	//SYS_enableInts ( );
//
//
//
////	VDP_setEnable ( FALSE );
////
////	resetVRAM ( ); // reset video memory
////	VDP_waitDMACompletion();            // wait for DMA completion
////
////	font_init();
////	font_setPalette();
////
////	VDP_setEnable ( TRUE );
//
//}











void waitHz ( u16 hz )
{
	while ( hz-- )
	{
		VDP_waitVSync();
	}
}

void waitSc ( u16 sc )
{
	sc *= getHz();

	while ( sc-- )
	{
		VDP_waitVSync();
	}
}

void waitJoy ( )
{
	while ( 1 )
	{
		VDP_waitVSync();

		JoyReader_update();

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			return ;
		}
	}
}

void waitJoyHz ( u16 hz )
{
	while ( hz-- )
	{
		VDP_waitVSync();

		JoyReader_update();

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			return ;
		}
	}
}

void waitJoySc ( u16 sc )
{
	sc *= getHz();

	while ( sc-- )
	{
		VDP_waitVSync();

		JoyReader_update();

		if ( joy1_pressed_abc || joy1_pressed_start )
		{
			return ;
		}
	}
}


static s16 _plan_dir_a = 0;
static s16 _plan_dir_b = 0;

void tool_reset_plan ( VDPPlan plan )
{
    if ( plan.value == PLAN_A.value ) _plan_dir_a = 0;
    else _plan_dir_b = 0;

    VDP_setHorizontalScroll( plan, 0 );
}

void tool_move_plan ( VDPPlan plan, s16 dir )
{
    if ( plan.value == PLAN_A.value )
    {
        _plan_dir_a += dir;
        VDP_setHorizontalScroll( plan, _plan_dir_a );
    }
    else
    {
        _plan_dir_b += dir;
        VDP_setHorizontalScroll( plan, _plan_dir_b );
    }
}



//void tool_waitWhilePessed ( u16 joy, u16 btn )
//{
//   while ( joysticks[joy].state & btn )
//   {
//      vobject_update();
//      VDP_updateSprites();
//      VDP_waitVSync();
//   }
//}




//void resetPalettes ( )
//{
//	VDP_fadeOutAll ( 1, false );
//}


//void tool_clearLinesText ( )
//{
//	VDP_clearTextLine(20);
//	VDP_clearTextLine(22);
//	VDP_clearTextLine(24);
//	VDP_clearTextLine(26);
//}









//
//static const char *uppercase_hexchars = "0123456789ABCDEF";
//static const char *lowercase_hexchars = "0123456789abcdef";
//
//#define isdigit(c) ((c) >= '0' && (c) <= '9')
//
//static u16 skip_atoi(const char **s)
//{
//    u16 i = 0;
//
//    while(isdigit(**s))
//        i = (i * 10) + *((*s)++) - '0';
//
//    return i;
//}
//
//u16 strnlen(const char *str, u16 maxlen)
//{
//    const char *src;
//
//    for (src = str; maxlen-- && *src != '\0'; ++src)
//        /* nothing */;
//
//    return src - str;
//}
//
//static u16 vsprintf(char *buf, const char *fmt, va_list args)
//{
//    char tmp_buffer[12];
//    s16 i;
//    s16 len;
//    s16 *ip;
//    u16 num;
//    char *s;
//    char *hexchars;
//    char *str;
//    s16 left_align;
//    s16 plus_sign;
//    s16 zero_pad;
//    s16 space_sign;
//    s16 field_width;
//    s16 precision;
//
//    for (str = buf; *fmt; ++fmt)
//    {
//        if (*fmt != '%')
//        {
//            *str++ = *fmt;
//            continue;
//        }
//
//        space_sign = zero_pad = plus_sign = left_align = 0;
//
//        // Process the flags
//repeat:
//        ++fmt;          // this also skips first '%'
//
//        switch (*fmt)
//        {
//            case '-':
//                left_align = 1;
//                goto repeat;
//
//            case '+':
//                plus_sign = 1;
//                goto repeat;
//
//            case ' ':
//                if ( !plus_sign )
//                    space_sign = 1;
//
//                goto repeat;
//
//            case '0':
//                zero_pad = 1;
//                goto repeat;
//        }
//
//        // Process field width and precision
//
//        field_width = precision = -1;
//
//        if (isdigit(*fmt))
//            field_width = skip_atoi(&fmt);
//        else if (*fmt == '*')
//        {
//            ++fmt;
//            // it's the next argument
//            field_width = va_arg(args, unsigned int );
//
//            if (field_width < 0)
//            {
//                field_width = -field_width;
//                left_align = 1;
//            }
//        }
//
//        if (*fmt == '.')
//        {
//            ++fmt;
//
//            if (isdigit(*fmt))
//                precision = skip_atoi(&fmt);
//            else if (*fmt == '*')
//            {
//                ++fmt;
//                // it's the next argument
//                precision = va_arg(args, unsigned int );
//            }
//
//            if (precision < 0)
//                precision = 0;
//        }
//
//        if ((*fmt == 'h') || (*fmt == 'l') || (*fmt == 'L'))
//            ++fmt;
//
//        if (left_align)
//            zero_pad = 0;
//
//        switch (*fmt)
//        {
//            case 'c':
//                if (!left_align)
//                    while(--field_width > 0)
//                        *str++ = ' ';
//
//                *str++ = (unsigned char) va_arg(args, unsigned int );
//
//                while(--field_width > 0)
//                    *str++ = ' ';
//
//                continue;
//
//            case 's':
//                s = va_arg(args, char *);
//
//                if (!s)
//                    s = "<NULL>";
//
//                len = strnlen(s, precision);
//
//                if (!left_align)
//                    while(len < field_width--)
//                        *str++ = ' ';
//
//                for (i = 0; i < len; ++i)
//                    *str++ = *s++;
//
//                while(len < field_width--)
//                    *str++ = ' ';
//
//                continue;
//
//            case 'p':
//                if (field_width == -1)
//                {
//                    field_width = 2 * sizeof(void *);
//                    zero_pad = 1;
//                }
//
//                hexchars = (char *) uppercase_hexchars;
//                goto hexa_conv;
//
//            case 'x':
//                hexchars = (char *) lowercase_hexchars;
//                goto hexa_conv;
//
//            case 'X':
//                hexchars = (char *) uppercase_hexchars;
//
//hexa_conv:
//                s = &tmp_buffer[12];
//                *--s = 0;
//                num = va_arg(args, int);
//
//                if (!num)
//                    *--s = '0';
//
//                while(num)
//                {
//                    *--s = hexchars[num & 0xF];
//                    num >>= 4;
//                }
//
//                num = plus_sign = 0;
//
//                break;
//
//            case 'n':
//                ip = va_arg(args, s16*);
//                *ip = (str - buf);
//                continue;
//
//            case 'u':
//                s = &tmp_buffer[12];
//                *--s = 0;
//                num = va_arg(args, unsigned int );
//
//                if (!num)
//                    *--s = '0';
//
//                while(num)
//                {
//                    *--s = (num % 10) + 0x30;
//                    num /= 10;
//                }
//
//                num = plus_sign = 0;
//
//                break;
//
//            case 'd':
//            case 'i':
//                s = &tmp_buffer[12];
//                *--s = 0;
//                i = va_arg(args, unsigned int );
//
//                if (!i)
//                    *--s = '0';
//
//                if (i < 0)
//                {
//                    num = 1;
//
//                    while(i)
//                    {
//                        *--s = 0x30 - (i % 10);
//                        i /= 10;
//                    }
//                }
//                else
//                {
//                    num = 0;
//
//                    while(i)
//                    {
//                        *--s = (i % 10) + 0x30;
//                        i /= 10;
//                    }
//                }
//
//                break;
//
//            default:
//                continue;
//        }
//
//        len = strnlen(s, precision);
//
//        if (num)
//        {
//            *str++ = '-';
//            field_width--;
//        }
//        else if (plus_sign)
//        {
//            *str++ = '+';
//            field_width--;
//        }
//        else if (space_sign)
//        {
//            *str++ = ' ';
//            field_width--;
//        }
//
//        if ( !left_align)
//        {
//            if (zero_pad)
//            {
//                while(len < field_width--)
//                    *str++ = '0';
//            }
//            else
//            {
//                while(len < field_width--)
//                    *str++ = ' ';
//            }
//        }
//
//        for (i = 0; i < len; ++i)
//            *str++ = *s++;
//
//        while(len < field_width--)
//            *str++ = ' ';
//    }
//
//    *str = '\0';
//
//    return str - buf;
//}
//
//u16 sprintf(char *buffer, const char *fmt, ...)
//{
//    va_list args;
//    u16 i;
//
//    va_start(args, fmt);
//    i = vsprintf(buffer, fmt, args);
//    va_end(args);
//
//    return i;
//}


