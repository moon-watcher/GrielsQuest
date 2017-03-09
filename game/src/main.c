#include "../inc/include.h"

void monos()
{
   JoyReader_update();

   if ( !joy1_pressed_btn )
   {
      return;
   }

   SYS_disableInts();
   VDP_loadTileSet ( ob_title_monos_mi.tileset, 16, 0 );
   VDP_setPalette ( PAL1, ob_title_monos_mi.palette->data );
   SYS_enableInts();

   u16 x = 0;
   u16 y = 0;

   while ( 1 )
   {
      SYS_disableInts();
      VDP_setMapEx ( PLAN_A, ob_title_monos_mi.map, TILE_ATTR_FULL(PAL1,0,0,0,16), 14, 10, x*13, y*6, 13, 6 );
      SYS_enableInts();

      ++x;

      if ( x == 10 )
      {
         x = 0;
         ++y;
      }

      if ( x == 6 && y == 6 )
      {
         x = 0;
         y = 0;
      }

      JoyReader_update();

      if ( joy1_pressed_btn )
      {
         break;
      }

      VDP_waitVSync();
   }

   VDP_fadeOutAll ( 30, 0 );
}



void conio()
{
   VDP_drawText ( "============", 0, 0 );
   VDP_drawText ( "============", 0, 1 );
   VDP_drawText ( "============", 0, 2 );
   VDP_drawText ( "============", 0, 3 );
   VDP_drawText ( "============", 0, 4 );
   VDP_drawText ( "============", 0, 5 );

   inittextinfo();
   window(1,1,10,4);

   cputsxy(3,0,"AAAAA");
   delay(1000);
   clrscr();
   delay(1000);

   while(!kbhit())
   {
      cputsxy ( 0, 0, "holaaaaajldkj ");
      delay(1000);

//      putch('a'); delay(1000);
//      putch('e'); delay(1000);
//      putch('i'); delay(1000);
//      putch('o'); delay(1000);

      gotoxy(2,2);
      cputs("XXXXXXXXXXXXXXXXXXZ");
      delay(1000);

      clreol();
      delay(1000);

      clrscr();
      delay(1000);
   }
}





/*
 *
 * // FUNCIONA!!!!!!!
 *
 * execl is called by
 * execl(file, arg1, arg2, ..., (char *)(0));
 */
int execl(const char *file, const char *args, ...)
{
   #define  MAXARGS     31

   va_list ap;
   char *array[MAXARGS +1];
   int argno = 0;

   va_start(ap, args);
   while (args != 0 && argno < MAXARGS)
   {
      array[argno++] = (char*) args;
      args = va_arg(ap, const char *);
   }
   array[argno] = (char *) 0;
   va_end(ap);

   drawUInt ( argno, 0,0,4);
   waitMs(2000);

   return argno;
}





void object_viewer()
{
   s16 opcion = 12;

   vram_init ( 16 );
   vobject_init ( );


   while ( 1 )
   {
      JoyReader_update ( );

      if ( opcion == MAX_ANIMATIONS ) opcion = 0;
      if ( opcion == -1             ) opcion = MAX_ANIMATIONS - 1;

      VDP_clearPlan ( PLAN_A, 0 );

      VOBJECT *v = vobject_add ( opcion );
      vobject_reset ( opcion );
		animation_set_raw();
		animation_draw ( opcion, 10, 10, true, PLAN_A, 1, 0, 0, 0, 0 );
      VDP_setPalette ( animation_get ( opcion )->pal, animation_get ( opcion )->res->pal );

      drawUInt ( opcion, 2, 3, 3 );
      VDP_drawText ( v->object->name, 7, 3 );

      while ( 1 )
      {
         JoyReader_update();

         drawUInt( v->frame,5,5,2);
         VDP_drawText( "/", 8, 5);
         drawUInt( v->object->frames,10,5,2);

         if ( joy1_pressed_dir )
         {
            if ( joy1_pressed_right ) ++opcion;
            if ( joy1_pressed_left  ) --opcion;

            break;
         }

         vobject_update();
         VDP_waitVSync();
      }

      vobject_reset(opcion);
      vobject_delete(opcion);

      VDP_waitVSync();
   }


}

void todas_las_pantallas ( )
{
   const u8 * pantallas[] =
   {
      "Sega",
      "Karoshi",
      "Titulo",
      "Opciones",
      "Intro",
      "Passwords",
      "Sound test",
      "Ending",
      "Game over",
      "Credits",
      "Puerta 1",
      "Puerta 2",
      "Puerta 3",
      "Final 1",
      "Final 2",
      "Final 3",
      "Mapa 1",
      "Mapa 2",
   };


   s16 opcion = 0;

   VDP_init();

   while ( 1 )
   {
      music_stop();

      JoyReader_update();



      VDP_drawText ( "Griel's Quest",  12,  1 );
      VDP_drawText ( "-------------",  12,  2 );
      VDP_drawText ( "  Level test ",  12,  5 );
      VDP_drawText ( "  2014-01-27 ",  12,  7 );
      VDP_drawText ( "<            >", 12, 12 );

      if ( opcion < 18 )
      {
         VDP_drawText ( pantallas[opcion], 14, 12 );
      }
      else
      {
         u8 str[4];
         uintToStr ( opcion - 18, str, 2 );
         VDP_drawText ( str, 21, 12 );
         VDP_drawText ( "Level:", 14, 12 );
      }





      if ( joy1_pressed_right ) ++opcion;
      if ( joy1_pressed_left  ) --opcion;

      if ( opcion >= 18 + 59 ) opcion = 18 + 59 - 1;
      if ( opcion <  0 ) opcion = 0;

      if (  joy1_pressed_abc )
      {
         //tool_reset ( );

         if ( opcion == 0 ) screen_sega   ( 0, 0, 0 );
         if ( opcion == 1 ) screen_griels ( 8, 0, 0 );
         if ( opcion == 2 ) screen_title  ( 0 );
         //if ( opcion == 3 ) screen_options ( );
         if ( opcion == 4 ) screen_intro ( 1 );
         if ( opcion == 5 ) pwd8_screen() ;
         if ( opcion == 6 ) screen_sound_test ( );
         //if ( opcion == 7 ) screen_ending ( );
         //if ( opcion == 8 ) screen_gameover ( );
         if ( opcion == 9 ) screen_staff();

         if ( opcion == 10) screen_puerta();
         if ( opcion == 11 )
         {
            gamestate.ambientes [ 0 ] = 0;
            gamestate.ambientes [ 1 ] = level_list [ 1 ] [ 0 ].cuantos;
            gamestate.ambientes [ 2 ] = 0;
            gamestate.ambientes [ 3 ] = level_list [ 3 ] [ 0 ].cuantos;
            screen_puerta();
         }

         if ( opcion == 12 )
         {
            gamestate.ambientes [ 0 ] = level_list [ 0 ] [ 0 ].cuantos;
            gamestate.ambientes [ 1 ] = level_list [ 1 ] [ 0 ].cuantos;
            gamestate.ambientes [ 2 ] = level_list [ 2 ] [ 0 ].cuantos;
            gamestate.ambientes [ 3 ] = level_list [ 3 ] [ 0 ].cuantos;
            screen_puerta();
         }

         if ( opcion == 13 )
         {
            gamestate.dificultad = 0;
            screen_final(0);
         }

         if ( opcion == 14 )
         {
            gamestate.dificultad = 1;
            screen_final(0);
         }

         if ( opcion == 15 )
         {
            gamestate.dificultad = 2;
            screen_final(0);
         }

         if ( opcion == 16 )
         {
            gamestate.visito_la_puerta = true;
            screen_mapa();
         }

         if ( opcion == 17 )
         {
            gamestate.visito_la_puerta = false;
            screen_mapa();
         }


         if ( opcion >= 18 ) game_play ( opcion - 10 );

//         tool_reset ( );
         VDP_init();
         VDP_setPlanSize ( 64, 32 );

//         joy_init ( );
//         joy_enable ( );
//         joy_set_handler ( JOY_HANDLER_COMMON );
      }
   }

}


u16 _check_password ( u8 password[], u16 *ptrLevel )
{
   u16 ret  = SCREEN_JUMP_TO_INTRO;
   u16 play = PSG_WRONG;


//    PENDIENTE DE REVISAR
//   LEVEL *levels = (LEVEL*) level ( );
//   u16 i;
//   for ( i = 1; i <= LEVEL_NB_LEVELS; i++ )
//   {
//      if ( my_strcmp ( password, levels[i].password ) )
//      {
//         *ptrLevel = i;
//         play = PSG_SELECT;
//         ret  = SCREEN_JUMP_TO_NEWGAME;
//      }
//   }

   if ( strcmp ( password, "SOUND"  ) == 0 )
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_SOUND;
   }

   if ( strcmp ( password, "SONIC"  ) == 0 )
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_SONIC;
   }

   if ( strcmp ( password, "KONAMI" ) == 0 )
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_KONAMI;
   }

   if ( strcmp ( password, "STAFF"  ) == 0 )
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_STAFF;
   }

   if ( strcmp ( password, "ENDING" ) == 0 )
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_ENDING;
   }


   psglist_play ( play );

   return ret;
}











int main ( )
{
   dev_init ( 1 );

   JoyReader_init ( 1 );


   monos();

   //object_viewer();
   //conio();



   gamestate.lenguaje = ENGLISH;


   Z80_init();
   Z80_unloadDriver();
	Z80_loadDriver ( Z80_DRIVER_XGM, true );
	SND_setForceDelayDMA_XGM ( true );

   VDP_setPlanSize ( 64, 32 );



   JOY_init ( );
   JOY_setSupport ( PORT_1, DEV ? JOY_SUPPORT_6BTN : JOY_SUPPORT_3BTN ); // JOY_SUPPORT_3BTN
   //JOY_setSupport ( PORT_1, JOY_SUPPORT_6BTN  ); // JOY_SUPPORT_3BTN
   JOY_setSupport ( PORT_2, JOY_SUPPORT_OFF );

   JoyReader_init ( 1 );

   //vram_init ( TILE_USERINDEX );

   vint_init ( );
   vint_setJoyReader ( true );

   SYS_setVIntCallback ( (_voidCallback*) vint_callback );

   font_init ( );
	gamestate_init ( ); // debe estar aqui y tras introducir un password correcto






//         gamestate.dificultad   = 2;
//         gamestate.ambientes[0] = 14;
//         gamestate.ambientes[1] = 14;
//         gamestate.ambientes[2] = 14;
//         gamestate.ambientes[3] = 14;
//         gamestate.ambientes[4] = 6 ;
//         gamestate.visito_la_puerta = true;

//         gamestate.lenguaje   = SPANISH;
//         gamestate.dificultad = 1;
//         gamestate.current_ambiente   = 0;
//         gamestate.current_round      = 0;
//         //screen_mapa();
//         game_ingame ( );
//
//         gamestate.lenguaje = SPANISH;

            //displayInit();
//            drawUInt(VDP_getTextPalette(),0,0,3);
//            waitMs(1000);
//
//            screen_final(0);





   screen_disclaimer ( );
   screen_sega ( 0, BUTTON_BTN, 0 );
   screen_griels ( 4, BUTTON_BTN, 0 ); // solo para Barcelona y demos

   //http://www.dodgycoder.net/2012/02/coding-tricks-of-game-developers.html#
   __builtin_expect ( gamestate.current_ambiente, 0 );


   game_loop();

   return 0;
}







//      // passwords //////////
//
//      if ( to == SCREEN_CHEAT_MUMMY )
//      {
//         // hacer alguna modificacion // algo del oh mummy
//         to = SCREEN_JUMP_TO_NEWGAME ;
//      }
//
//      if ( to == SCREEN_CHEAT_SONIC )
//      {
//         // hacer alguna modificacion // select level
//         to = SCREEN_JUMP_TO_NEWGAME ;
//      }
//
//      if ( to == SCREEN_CHEAT_KONAMI )
//      {
//         // hacer alguna modificacion // change player
//         to = SCREEN_JUMP_TO_NEWGAME ;
//      }
//
//      if ( to == SCREEN_CHEAT_SOUND )
//      {
//         screen_sound_test ( );
//         to = SCREEN_JUMP_TO_INTRO;
//      }
//
//      if ( to == SCREEN_CHEAT_STAFF )
//      {
//         screen_staff ( );
//         to = SCREEN_JUMP_TO_INTRO;
//      }
//
//      if ( to == SCREEN_CHEAT_ENDING )
//      {
//         screen_ending ( );
//         to = SCREEN_JUMP_TO_INTRO;
//      }




/*

   //	prayer_show ( 6 );
   //	prayer_show ( 11 );
   //	prayer_show ( 16 );
   //	prayer_show ( 21 );zz
   //	screen_ending();
//   	u8 pwd[9]; screen_password(pwd);
//   	screen_sound_test();
   //	screen_intro();
   //	screen_oooklab ( 8, BUTTON_BTN, 1 );
   //	screen_staff(); //pendiente
   //	u16 title = screen_title ( );
   //	game ( 58 );
	//	game ( 4 );



//typedef void* VirtualFunction (...);
typedef void (*VirtualFunctionPointer)(u8 a, ...);

// // FUNCIONA!!!
//execl("asd", "d", "asd", "asda","asd", "asda","asd", "asda","asd" );

*/
