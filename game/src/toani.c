/*

toani.c

"toani" means TimeOut Animation

*/

#include "../inc/include.h"





static u16 _cnt_explosion;
static u16 _cnt_dead;
static u16 _cnt_dust;

static u8  _demon_ojos;
static u8  _demon_cola;
static u8  _demon_y;
static s8  _demon_vel;
static s8  _demon_is_hidden;

static u32 _demon_counter;




//////////////////////////////////////////////////////////////////////////////////////////////////////////////


static u16 _draw ( u16 element, s16 x, s16 y, u8 nb_sp )
{
	x = level_hpos_to_pixel(x);
	y = level_vpos_to_pixel(y) + 8;

	vobject_add ( element );
	vobject_reset ( element );

	vsprite_set ( nb_sp, x, y, element );

	return animation_duracion ( element );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


void toani_init ( )
{
	_demon_counter = 0;
	_cnt_explosion = 0;
	_cnt_dead      = 0;
	_cnt_dust      = 0;

	vobject_delete ( REMOVE_OBJECT );
	vobject_delete ( ENEMY_DEAD    );
	vobject_delete ( DUST          );
	vobject_delete ( SLASH_UP      );
}


void toani_remove ( )
{
	if ( _cnt_explosion && --_cnt_explosion == 0 ) { vsprite_animation ( splist_element,   EMPTY_SPRITE ); vobject_delete ( REMOVE_OBJECT ); }
	if ( _cnt_dead      && --_cnt_dead      == 0 ) { vsprite_animation ( splist_explosion, EMPTY_SPRITE ); vobject_delete ( ENEMY_DEAD    ); }
	if ( _cnt_dust      && --_cnt_dust      == 0 ) { vsprite_animation ( splist_dust,      EMPTY_SPRITE ); vobject_delete ( DUST          ); }
}


void toani_draw_explosion ( s16 x, s16 y )
{
	_cnt_explosion = _draw ( REMOVE_OBJECT, x, y, splist_element );
	vobject_add ( REMOVE_OBJECT );
	vobject_reset ( REMOVE_OBJECT );
}


void toani_draw_dead ( s16 x, s16 y )
{
	_cnt_dead = _draw ( ENEMY_DEAD, x, y, splist_explosion ); //OJO al +8
	vobject_add ( ENEMY_DEAD );
	vobject_reset ( ENEMY_DEAD );
}


void toani_draw_undo ( s16 _rest )
{
	_cnt_dead = _draw ( ENEMY_DEAD, 216, -16, splist_explosion );
	vobject_add ( ENEMY_DEAD );
	vobject_reset ( ENEMY_DEAD );

//	_cnt_dead = _draw ( ENEMY_DEAD, ( 8 + _rest ) * 15, -16, splist_explosion );
//	vobject_active  ( ENEMY_DEAD );
}


void toani_draw_dust ( s16 x, s16 y )
{
	_cnt_dust = _draw ( DUST, x, y+8, splist_dust ); //OJO al +8
	vobject_add  ( DUST );
}


void  toani_demon_hide ( u8 val )
{
	_demon_is_hidden = val ;

	if ( val )
	{
		u8 k;

		for ( k=7; k<=10; k++ )
		{
			splist_hide_sprite(k);
		}
	}
}


void toani_demon_update ( )
{
	if ( _demon_is_hidden || ( level_current() != 58 ) )
	{
		return;
	}

	u8 sw1 = 0;
	u8 sw2 = 0;

	_demon_counter++;

	if ( _demon_counter % 103 == 0 )
	{
		sw1 = 1;
		_demon_ojos = _demon_ojos ? 0 : 1;
	}

	if ( _demon_counter % 15 == 0 )
	{
		sw2 = 1;
		_demon_cola = _demon_cola ? 0 : 1;
	}

	if ( sw1 || sw2 )
	{
		if ( _demon_y == 0  ) _demon_y   = +18;
		if ( _demon_y == 18 ) _demon_vel = +1;
		if ( _demon_y == 23 ) _demon_vel = -1;

		if ( sw2 ) _demon_y += _demon_vel;

		level_draw_demon ( 248, _demon_y, _demon_ojos, _demon_cola );
	}
}


void toani_reset_explosion ( )
{
	_cnt_explosion = 0;

	vsprite_animation ( splist_element, EMPTY_SPRITE  );
	vobject_delete ( REMOVE_OBJECT );
}
