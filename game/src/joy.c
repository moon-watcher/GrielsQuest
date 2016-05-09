//#include "../inc/include.h"
//
//
//
//
//
//
//
////static _joyEventCallback *_handler_common ( u16 joy, u16 changed, u16 state )
////{
////   return 0;
////}
//
//
////void joy_set_handler ( u16 hnd )
////{
////   switch ( hnd )
////   {
////      case JOY_HANDLER_COMMON :
////         JOY_setEventHandler ( (_joyEventCallback*) &_handler_common );
////         break;
////
////      default:
////         JOY_setEventHandler ( (_joyEventCallback*) NULL );
////         break;
////   }
////}
//
//
////#include "../inc/include.h"
////
////
////
////static _joyEventCallback *_handler_common ( u16 joy, u16 changed, u16 state )
////{
////   vu16 btn = state & ~joysticks [ joy ].state;
////   //trigger     = (state ^ prev_state) & state;
////   //vu16 btn =    ( state ^ joysticks [ joy ].state ) & state;
////
////
////
////   joysticks [ joy ] = ( JOYSTATE )
////   {
////      state,
////      changed,
////
////      ( btn & BUTTON_UP    ),
////      ( btn & BUTTON_DOWN  ),
////      ( btn & BUTTON_LEFT  ),
////      ( btn & BUTTON_RIGHT ),
////      ( btn & BUTTON_A     ),
////      ( btn & BUTTON_B     ),
////      ( btn & BUTTON_C     ),
////      ( btn & BUTTON_START ),
////      ( btn & BUTTON_X     ),
////      ( btn & BUTTON_Y     ),
////      ( btn & BUTTON_Z     ),
////      ( btn & BUTTON_MODE  ),
////
////      ( btn & BUTTON_DIR   ),
////      ( btn & BUTTON_BTN   ),
////      ( btn & BUTTON_ALL   )
////   };
////
////   return 0;
////}
////
////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////
////
////
////void joy_init ( )
////{
////   joy1 = ( JOYSTATE ) { 0xffff };
////   joy2 = ( JOYSTATE ) { 0xffff };
////}
////
////
////void joy_enable ( )
////{
////   JOY_setSupport ( PORT_1, JOY_SUPPORT_6BTN ); // JOY_SUPPORT_3BTN
////   JOY_setSupport ( PORT_2, JOY_SUPPORT_JUSTIFIER_BLUE );
////}
////
////
////void joy_disable ( )
////{
////   JOY_setSupport ( PORT_1, JOY_SUPPORT_OFF );
////   JOY_setSupport ( PORT_2, JOY_SUPPORT_OFF );
////}
////
////
////void joy_set_handler ( u16 hnd )
////{
////   switch ( hnd )
////   {
////      case JOY_HANDLER_COMMON :
////         JOY_setEventHandler ( (_joyEventCallback*) &_handler_common );
////         break;
////
////      default:
////         JOY_setEventHandler ( (_joyEventCallback*) NULL );
////         break;
////   }
////}
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
//////#include "../inc/include.h"
//////
//////
//////
//////static u16 _buttons, _oldButtons = 0xffff, _pressedButtons;
//////
//////static _joyEventCallback *_handler_common ( u16 joy, u16 changed, u16 state )
//////{
//////   joysticks[joy].state   = state   ;
//////   joysticks[joy].changed = changed ;
//////
//////   _pressedButtons = state & ~_oldButtons;
//////   _oldButtons     = state;
//////
//////   joysticks[joy].up    = ( _pressedButtons & BUTTON_UP    );
//////   joysticks[joy].down  = ( _pressedButtons & BUTTON_DOWN  );
//////   joysticks[joy].left  = ( _pressedButtons & BUTTON_LEFT  );
//////   joysticks[joy].right = ( _pressedButtons & BUTTON_RIGHT );
//////   joysticks[joy].a     = ( _pressedButtons & BUTTON_A     );
//////   joysticks[joy].b     = ( _pressedButtons & BUTTON_B     );
//////   joysticks[joy].c     = ( _pressedButtons & BUTTON_C     );
//////   joysticks[joy].start = ( _pressedButtons & BUTTON_START );
//////   joysticks[joy].x     = ( _pressedButtons & BUTTON_X     );
//////   joysticks[joy].y     = ( _pressedButtons & BUTTON_Y     );
//////   joysticks[joy].z     = ( _pressedButtons & BUTTON_Z     );
//////   joysticks[joy].mode  = ( _pressedButtons & BUTTON_MODE  );
//////
//////   joysticks[joy].dir   = ( _pressedButtons & BUTTON_DIR   );
//////   joysticks[joy].btn   = ( _pressedButtons & BUTTON_BTN   );
//////   joysticks[joy].all   = ( _pressedButtons & BUTTON_ALL   );
//////
////////	if (joy == JOY_1)
////////	{
////////		if (state & BUTTON_START)
////////		{
////////			//player 1 press START button
////////		}
////////		else if (changed & BUTTON_START)
////////		{
////////			//player 1 released START button
////////		}
////////	}
//////
//////
////////   if      ( state   & BUTTON_UP    ) joysticks[joy].up    = JOY_PRESSED;
////////   else if ( changed & BUTTON_UP    ) joysticks[joy].up    = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_DOWN  ) joysticks[joy].down  = JOY_PRESSED;
////////   else if ( changed & BUTTON_DOWN  ) joysticks[joy].down  = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_LEFT  ) joysticks[joy].left  = JOY_PRESSED;
////////   else if ( changed & BUTTON_LEFT  ) joysticks[joy].left  = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_RIGHT ) joysticks[joy].right = JOY_PRESSED;
////////   else if ( changed & BUTTON_RIGHT ) joysticks[joy].right = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_A     ) joysticks[joy].a     = JOY_PRESSED;
////////   else if ( changed & BUTTON_A     ) joysticks[joy].a     = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_B     ) joysticks[joy].b     = JOY_PRESSED;
////////   else if ( changed & BUTTON_B     ) joysticks[joy].b     = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_C     ) joysticks[joy].c     = JOY_PRESSED;
////////   else if ( changed & BUTTON_C     ) joysticks[joy].c     = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_START ) joysticks[joy].start = JOY_PRESSED;
////////   else if ( changed & BUTTON_START ) joysticks[joy].start = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_X     ) joysticks[joy].x     = JOY_PRESSED;
////////   else if ( changed & BUTTON_X     ) joysticks[joy].x     = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_Y     ) joysticks[joy].y     = JOY_PRESSED;
////////   else if ( changed & BUTTON_Y     ) joysticks[joy].y     = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_Z     ) joysticks[joy].z     = JOY_PRESSED;
////////   else if ( changed & BUTTON_Z     ) joysticks[joy].z     = JOY_RELEASED;
////////
////////   if      ( state   & BUTTON_MODE  ) joysticks[joy].mode  = JOY_PRESSED;
////////   else if ( changed & BUTTON_MODE  ) joysticks[joy].mode  = JOY_RELEASED;
//////
//////
//////   return 0;
//////}
//////
//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////
//////
//////
//////void joy_init ( )
//////{
//////   _buttons        = 0;
//////   _oldButtons     = 0xffff;
//////   _pressedButtons = 0;
//////
//////   joy1.state   = 0;
//////   joy1.changed = 0;
//////
//////   joy2.state   = 0;
//////   joy2.changed = 0;
//////}
//////
//////
//////void joy_enable ( )
//////{
//////   JOY_setSupport ( PORT_1, JOY_SUPPORT_6BTN ); // JOY_SUPPORT_3BTN
//////   JOY_setSupport ( PORT_2, JOY_SUPPORT_JUSTIFIER_BLUE );
//////}
//////
//////
//////void joy_disable ( )
//////{
//////   JOY_setSupport ( PORT_1, JOY_SUPPORT_OFF );
//////   JOY_setSupport ( PORT_2, JOY_SUPPORT_OFF );
//////}
//////
//////
//////void joy_set_handler ( u16 hnd )
//////{
//////   switch ( hnd )
//////   {
//////      case JOY_HANDLER_COMMON :
//////         JOY_setEventHandler ( (_joyEventCallback*) &_handler_common );
//////         break;
//////
//////      default:
//////         JOY_setEventHandler ( (_joyEventCallback*) NULL );
//////         break;
//////   }
//////}
