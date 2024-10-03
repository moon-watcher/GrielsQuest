#include "../inc/include.h"

void conio()
{
   TEXT_drawText("============", 0, 0);
   TEXT_drawText("============", 0, 1);
   TEXT_drawText("============", 0, 2);
   TEXT_drawText("============", 0, 3);
   TEXT_drawText("============", 0, 4);
   TEXT_drawText("============", 0, 5);

   inittextinfo();
   window(1, 1, 10, 4);

   cputsxy(3, 0, "AAAAA");
   delay(1000);
   clrscr();
   delay(1000);

   while (!kbhit())
   {
      cputsxy(0, 0, "holaaaaajldkj ");
      delay(1000);

      //      putch('a'); delay(1000);
      //      putch('e'); delay(1000);
      //      putch('i'); delay(1000);
      //      putch('o'); delay(1000);

      gotoxy(2, 2);
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
#define MAXARGS 31

   va_list ap;
   char *array[MAXARGS + 1];
   int argno = 0;

   va_start(ap, args);
   while (args != 0 && argno < MAXARGS)
   {
      array[argno++] = (char *)args;
      args = va_arg(ap, const char *);
   }
   array[argno] = (char *)0;
   va_end(ap);

   drawUInt(argno, 0, 0, 4);
   waitMs(2000);

   return argno;
}

void object_viewer()
{
   s16 opcion = 12;

   vram_init(16);
   vobject_init();

   while (1)
   {
      JoyReader_update();

      if (opcion == MAX_ANIMATIONS)
         opcion = 0;
      if (opcion == -1)
         opcion = MAX_ANIMATIONS - 1;

      SYS_disableInts();
      VDP_clearPlane(BG_A, 1);
      SYS_enableInts();

      VOBJECT *v = vobject_add(opcion);
      vobject_reset(opcion);
      animation_set_raw();
      animation_draw(opcion, 10, 10, true, BG_A, 1, 0, 0, 0, 0);
      PAL_setPalette(animation_get(opcion)->pal, animation_get(opcion)->res->pal, CPU);

      drawUInt(opcion, 2, 3, 3);
      TEXT_drawText(v->object->name, 7, 3);

      while (1)
      {
         JoyReader_update();

         drawUInt(v->frame, 5, 5, 2);
         TEXT_drawText("/", 8, 5);
         drawUInt(v->object->frames, 10, 5, 2);

         if (joy1_pressed_dir)
         {
            if (joy1_pressed_right)
               ++opcion;
            if (joy1_pressed_left)
               --opcion;

            break;
         }

         vobject_update();
         vobject_upload();

         SYS_doVBlankProcess();
      }

      vobject_reset(opcion);
      vobject_delete(opcion);

      SYS_doVBlankProcess();
   }
}

void todas_las_pantallas()
{
   const u8 *pantallas[] =
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

   while (1)
   {
      music_stop();

      JoyReader_update();

      TEXT_drawText("Griel's Quest", 12, 1);
      TEXT_drawText("-------------", 12, 2);
      TEXT_drawText("  Level test ", 12, 5);
      TEXT_drawText("  2014-01-27 ", 12, 7);
      TEXT_drawText("<            >", 12, 12);

      if (opcion < 18)
      {
         TEXT_drawText(pantallas[opcion], 14, 12);
      }
      else
      {
         u8 str[4];
         uintToStr(opcion - 18, str, 2);
         TEXT_drawText(str, 21, 12);
         TEXT_drawText("Level:", 14, 12);
      }

      if (joy1_pressed_right)
         ++opcion;
      if (joy1_pressed_left)
         --opcion;

      if (opcion >= 18 + 59)
         opcion = 18 + 59 - 1;
      if (opcion < 0)
         opcion = 0;

      if (joy1_pressed_abc)
      {
         // tool_reset ( );

         if (opcion == 0)
            screen_sega();
         if (opcion == 1)
            screen_griels();
         if (opcion == 2)
            screen_title(0);
         // if ( opcion == 3 ) screen_options ( );
         if (opcion == 4)
            screen_intro(1);
         if (opcion == 5)
            screen_password();
         if (opcion == 6)
            screen_sound_test();
         // if ( opcion == 7 ) screen_ending ( );
         // if ( opcion == 8 ) screen_gameover ( );
         if (opcion == 9)
            screen_staff();

         if (opcion == 10)
            screen_puerta();
         if (opcion == 11)
         {
            gamestate.ambientes[0] = 0;
            gamestate.ambientes[1] = level_list[1][0].cuantos;
            gamestate.ambientes[2] = 0;
            gamestate.ambientes[3] = level_list[3][0].cuantos;
            screen_puerta();
         }

         if (opcion == 12)
         {
            gamestate.ambientes[0] = level_list[0][0].cuantos;
            gamestate.ambientes[1] = level_list[1][0].cuantos;
            gamestate.ambientes[2] = level_list[2][0].cuantos;
            gamestate.ambientes[3] = level_list[3][0].cuantos;
            screen_puerta();
         }

         if (opcion == 13)
         {
            gamestate.dificultad = 0;
            screen_final(0);
         }

         if (opcion == 14)
         {
            gamestate.dificultad = 1;
            screen_final(0);
         }

         if (opcion == 15)
         {
            gamestate.dificultad = 2;
            screen_final(0);
         }

         if (opcion == 16)
         {
            gamestate.visito_la_puerta = true;
            screen_mapa(TRUE);
         }

         if (opcion == 17)
         {
            gamestate.visito_la_puerta = false;
            screen_mapa(TRUE);
         }

         if (opcion >= 18)
            game_play(opcion - 10);

         //         tool_reset ( );
         VDP_init();
         VDP_setPlaneSize(64, 32, false);

         //         joy_init ( );
         //         joy_enable ( );
         //         joy_set_handler ( JOY_HANDLER_COMMON );
      }
   }
}

u16 _check_password(u8 password[], u16 *ptrLevel)
{
   u16 ret = SCREEN_JUMP_TO_INTRO;
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

   if (strcmp(password, "SOUND") == 0)
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_SOUND;
   }

   if (strcmp(password, "SONIC") == 0)
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_SONIC;
   }

   if (strcmp(password, "KONAMI") == 0)
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_KONAMI;
   }

   if (strcmp(password, "STAFF") == 0)
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_STAFF;
   }

   if (strcmp(password, "ENDING") == 0)
   {
      play = PSG_START;
      ret = SCREEN_CHEAT_ENDING;
   }

   psglist_play(play);

   return ret;
}

void jap()
{
   u8 i, ch;
   u8 str1[40] = "鬆";
   u8 str2[40] = "鬆大ｼｵ繧� ・�";
   u8 str3[40] = "輔″蛻・￠";
   u8 str4[40] = "蜍晏茜";
   u8 str5[40] = "蠕礼せ";
   u8 str6[40] = "繧ｳ繧､繝ｳ";

   i = 0;
   ch = str1[i];
   while (ch != '\0')
   {
      drawUInt(ch, 0, i, 3);
      ch = str1[i++];
   }
   drawUInt(i, 0, i, 2);

   i = 0;
   ch = str2[i];
   while (ch != '\0')
   {
      drawUInt(ch, 4, i, 3);
      ch = str2[i++];
   }
   drawUInt(i, 4, i, 2);

   i = 0;
   ch = str3[i];
   while (ch != '\0')
   {
      drawUInt(ch, 8, i, 3);
      ch = str3[i++];
   }
   drawUInt(i, 8, i, 2);

   i = 0;
   ch = str4[i];
   while (ch != '\0')
   {
      drawUInt(ch, 12, i, 3);
      ch = str4[i++];
   }
   drawUInt(i, 12, i, 2);

   i = 0;
   ch = str5[i];
   while (ch != '\0')
   {
      drawUInt(ch, 16, i, 3);
      ch = str5[i++];
   }
   drawUInt(i, 16, i, 2);

   i = 0;
   ch = str6[i];
   while (ch != '\0')
   {
      drawUInt(ch, 20, i, 3);
      ch = str6[i++];
   }
   drawUInt(i, 20, i, 2);

   while (1)
      ;
}
