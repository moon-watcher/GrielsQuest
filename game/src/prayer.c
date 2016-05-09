//#include "../inc/include.h"
//#include "../inc/prayer.h"
//
//static const PRAYER _list [ PRAYER_PRAYERS ] =
//{
//	{
//		7,
//		{
//			"   Behold I am with thee, and   " ,
//			"  will keep thee in all places  " ,
//			"       whither thou goest       " ,
//			"                                " ,
//			"                Genesis 28:15.  " ,
//			"                                "
//		}
//	},
//
//	{
//		13,
//		{
//			"  For with thee is the fountain ",
//			"   of life: in thy light shall  ",
//			"          we see light          ",
//			"                                ",
//			"                  Psalms 36:9.  ",
//			"                                "
//		}
//	},
//
//	{
//		16,
//		{
//			"  Suffering produces endurance, ",
//			"     and endurance produces     ",
//			"    character, and character    ",
//			"         produces hope          ",
//			"                                ",
//			"                 Romans 5:3-4.  "
//		}
//	},
//
//	{
//		21,
//		{
//			"   God opposes the proud, but   ",
//			"   gives grace to the humble    ",
//			"                                ",
//			"                    James 4:6.  ",
//			"                                ",
//			"                                "
//		}
//	},
//
//
//	{
//		26,
//		{
//			"   Whatsoever thy hand findeth  ",
//			" to do, do it with all thy might",
//			"                                ",
//			"            Ecclesiastes 9:10.  ",
//			"                                ",
//			"                                "
//		}
//	},
//
//	{
//		31,
//		{
//			"  Let us run with endurance the ",
//			"   race that is set before us   ",
//			"                                ",
//			"                 Hebrews 12:1.  ",
//			"                                ",
//			"                                "
//		}
//	},
//
//	{
//		37,
//		{
//			"  Creater love hath no man than ",
//			"  this, that a man lay DOWN2 his ",
//			"      life for his friends      ",
//			"                                ",
//			"                   Jonh 15:13.  ",
//			"                                "
//		}
//	},
//
//	{
//		43,
//		{
//			" He who ignores discipline des- ",
//			"pises himself, but whoever needs",
//			" correction gains understanding ",
//			"                                ",
//			"               Proverbs 15:32.  ",
//			"                                "
//		}
//	},
//
//	{
//		49,
//		{
//			" Behold, God is my salvation; I ",
//			" will trust, and not be afraid: ",
//			"   for the Lord Jehovah is my   ",
//			"     strength and my song       ",
//			"                                ",
//			"                  Isaiah 12:2.  "
//		}
//	},
//
//	{
//		55,
//		{
//			"     Judge not, that ye be      ",
//			"          not judged            ",
//			"                                ",
//			"                  Matthew 7:1.  ",
//			"                                ",
//			"                                "
//		}
//	},
//
//	{
//		58,
//		{
//			"   Twelve crosses against the   ",
//			"  evil. Twelve brothers hid and ",
//			"     died here, four changed    ",
//			"          their faith.          ",
//			"                                ",
//			"            Jean Raymond 20:14. "
//		}
//	}
//};
//
//
//
//
//static const u16 _pal_password [ 16 ] =
//{
//	0x0000,
//	0x00FF,
//	0x0044,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000,
//	0x0000
//};
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////"13th century. The Cathars were being expelled by the Catholic Church out of the Languedoc
////##
////The Cathar Jean Raymond runs to escape the crusaders..."
//
////text = "Glide through#the beast cage";
////text = "An invisible path#over a wood bridge";
////text = "Four brothers#changed their faith";
////text = "Jump to death#and prove your faith";
////text = "Twelve brothers#hid and died here";
////text = "Twelve crosses#against the evil";
//
//
//PRAYER *prayer ( )
//{
//	return (PRAYER*) &_list;
//}
//
//
//PRAYER *prayer_get ( u16 level )
//{
//	u8 i;
//
//	for ( i=0; i<PRAYER_PRAYERS; i++ )
//	{
//		if ( level == _list[i].level )
//		{
//			return (PRAYER*) &_list[i];
//		}
//	}
//
//	static PRAYER _empty = { 0, { NULL } };
//
//	return (PRAYER*) &_empty;
//}
//
//
//void prayer_show ( u16 level )
//{
//	PRAYER *p = prayer_get ( level );
//
//	if ( ! p->level )
//	{
//		return;
//	}
//
//	u16 i, text_palette = VDP_getTextPalette();
//
//	VDP_setPalette ( text_palette, palette_black );
//
//
//	for ( i=0; i<PRAYER_LINES; i++ )
//	{
//		VDP_drawText ( (u8*) p->pharse[i], 4, 7 + i*2 );
//	}
//
//	VDP_drawText ( "  Holy Pray:", 4, 21 );
//
//
//	VDP_fadePalIn ( text_palette, (u16*)font_getPalette(), 60, 0 );
//
//	waitMs(1000);
//
//	VDP_setPalette ( PAL1, _pal_password );
//	VDP_setTextPalette(PAL1);
//
//	//tool_typeText ( level_get(level)->password, 17, 21, 100 );
//
//	waitMs(5000);
//
//	JOY_waitPress ( JOY_1, BUTTON_BTN );
//
//	tool_planHide();
//	waitMs(500);
//}
