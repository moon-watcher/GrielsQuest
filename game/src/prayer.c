#include "../inc/include.h"
//#include "../inc/prayer.h"

static const PRAYER _list [ PRAYER_PRAYERS+1 ] =
{
	{
		"GENESIS",
		{
			"   Behold I am with thee, and   " ,
			"  will keep thee in all places  " ,
			"       whither thou goest       " ,
			"                                " ,
			"                Genesis 28:15.  " ,
			"                                "
		}
	},

	{
		"PSALMS",
		{
			"  For with thee is the fountain ",
			"   of life: in thy light shall  ",
			"          we see light          ",
			"                                ",
			"                  Psalms 36:9.  ",
			"                                "
		}
	},

	{
		"ROMANS",
		{
			"  Suffering produces endurance, ",
			"     and endurance produces     ",
			"    character, and character    ",
			"         produces hope          ",
			"                                ",
			"                 Romans 5:3-4.  "
		}
	},

	{
		"JAMES",
		{
			"   God opposes the proud, but   ",
			"   gives grace to the humble    ",
			"                                ",
			"                    James 4:6.  ",
			"                                ",
			"                                "
		}
	},


	{
		"ECCLESIA",
		{
			"   Whatsoever thy hand findeth  ",
			" to do, do it with all thy might",
			"                                ",
			"            Ecclesiastes 9:10.  ",
			"                                ",
			"                                "
		}
	},

	{
		"HEBREWS",
		{
			"  Let us run with endurance the ",
			"   race that is set before us   ",
			"                                ",
			"                 Hebrews 12:1.  ",
			"                                ",
			"                                "
		}
	},

	{
		"JOHN",
		{
			"  Creater love hath no man than ",
			"  this, that a man lay down his ",
			"      life for his friends      ",
			"                                ",
			"                   John 15:13.  ",
			"                                "
		}
	},

	{
		"PROVERBS",
		{
			" He who ignores discipline des- ",
			"pises himself, but whoever needs",
			" correction gains understanding ",
			"                                ",
			"               Proverbs 15:32.  ",
			"                                "
		}
	},

	{
		"ISAIAH",
		{
			" Behold, God is my salvation; I ",
			" will trust, and not be afraid: ",
			"   for the Lord Jehovah is my   ",
			"     strength and my song       ",
			"                                ",
			"                  Isaiah 12:2.  "
		}
	},

	{
		"MATTHEW",
		{
			"     Judge not, that ye be      ",
			"          not judged            ",
			"                                ",
			"                  Matthew 7:1.  ",
			"                                ",
			"                                "
		}
	},

	{
		"RAYMOND",
		{
			"   Twelve crosses against the   ",
			"  evil. Twelve brothers hid and ",
			"     died here, four changed    ",
			"          their faith.          ",
			"                                ",
			"            Jean Raymond 20:17. "
		}
	},

	{
	    "",
	    {
	    }
	}

};





PRAYER *prayer_get ( u16 i )
{
    return (PRAYER *) &_list[i];
}


void prayer_show ( u16 level )
{
    displayInit();
    displayOff(0);
    resetScreen();
    resetSprites();
    JoyReader_pause();

	u16 i;
	u16 wait1 = ntsc2pal(100);

	prepareColor (  1, 0xfff );
    prepareColor (  2, 0x444 );
    prepareColor ( 17, 0x84f );
    prepareColor ( 18, 0x224 );

	PRAYER *p = (PRAYER *) &_list[level];

	music_stop();

	displayOn(10);
	VDP_setTextPalette(PAL0);

	for ( i=0; i<PRAYER_LINES; i++ )
	{
	    typeText ( (char*) p->pharse[i], 4, 7+i*2, wait1 );
	}

	typeText ( "Holy Pray:", 6, 21, wait1 );
    waitSc(1);

	VDP_setTextPalette(PAL1);
	typeText ( p->keyword, 17, 21, wait1*2 );
	waitSc(2);

	JoyReader_resume();
	waitJoy(); // JOY_waitPress ( JOY_1, BUTTON_BTN );

	planHide ( );
	displayOff ( 0 );
	waitSc ( 1 );
}



static u16 compare ( char *str, PASSWORD8 pwd )
{
    char i, len = strlen(str);

    for ( i=0; i<len; i++ )
    {
        if ( str[i] != pwd[i] )
        {
            return 0;
        }
    }

    return 1;
}

bool prayer_compare ( PASSWORD8 pwd )
{
    void (*function)() = NULL;

    if ( compare ("STAFF",    pwd) ) function = screen_staff;
    if ( compare ("OLDEND",   pwd) ) function = screen_oldending;
    if ( compare ("OLDINTRO", pwd) ) function = screen_oldintro;

    if ( function )
    {
        vdpSpriteCache[0].link = 0;
        vdpSpriteCache[0].x = -50;
        VDP_updateSprites ( 80, 1 );
        function();

        return true;
    }

    u8 i=0;

    while ( 1 )
    {
        char *word = prayer_get ( i )->keyword;

        if ( strcmp ( word, "" ) == 0 )
        {
            break;
        }

        if ( compare ( word, pwd ) )
        {
            displayOff(10);
            vdpSpriteCache[0].link = 0;
            vdpSpriteCache[0].x = -50;
            VDP_updateSprites ( 80, 1 );

            prayer_show ( i );

            return true;
        }

        ++i;
    }

    return false;
}
