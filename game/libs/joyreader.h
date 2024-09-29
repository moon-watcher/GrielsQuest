#pragma once

typedef struct
{
   u16 active;
   u16 changed;
}
JoyReader;


#define JOY_MAX 1
#define joy1 joysticks [ JOY_1 ]


#define joy1_active               ( ( joy1.active ) )
#define joy1_active_up            ( ( joy1_active   >>  0 ) & 1 )
#define joy1_active_down          ( ( joy1_active   >>  1 ) & 1 )
#define joy1_active_left          ( ( joy1_active   >>  2 ) & 1 )
#define joy1_active_right         ( ( joy1_active   >>  3 ) & 1 )
#define joy1_active_a             ( ( joy1_active   >>  6 ) & 1 )
#define joy1_active_b             ( ( joy1_active   >>  4 ) & 1 )
#define joy1_active_c             ( ( joy1_active   >>  5 ) & 1 )
#define joy1_active_x             ( ( joy1_active   >> 10 ) & 1 )
#define joy1_active_y             ( ( joy1_active   >>  9 ) & 1 )
#define joy1_active_z             ( ( joy1_active   >>  8 ) & 1 )
#define joy1_active_start         ( ( joy1_active   >>  7 ) & 1 )
#define joy1_active_mode          ( ( joy1_active   >> 11 ) & 1 )
#define joy1_active_vertical      ( ( joy1_active_up       | joy1_active_down  ) )
#define joy1_active_horizontal    ( ( joy1_active_left     | joy1_active_right ) )
#define joy1_active_dir           ( ( joy1_active_vertical | joy1_active_horizontal ) )
#define joy1_active_abc           ( ( joy1_active_a        | joy1_active_b | joy1_active_c ) )
#define joy1_active_abcs          ( ( joy1_active_a        | joy1_active_b | joy1_active_c | joy1_active_start) )
#define joy1_active_xyz           ( ( joy1_active_x        | joy1_active_y | joy1_active_z ) )
#define joy1_active_btn           ( ( joy1_active_abc      | joy1_active_xyz  ) )

#define joy1_changed              ( ( joy1.changed ) )
#define joy1_changed_up           ( ( joy1_changed  >>  0 ) & 1 )
#define joy1_changed_down         ( ( joy1_changed  >>  1 ) & 1 )
#define joy1_changed_left         ( ( joy1_changed  >>  2 ) & 1 )
#define joy1_changed_right        ( ( joy1_changed  >>  3 ) & 1 )
#define joy1_changed_a            ( ( joy1_changed  >>  6 ) & 1 )
#define joy1_changed_b            ( ( joy1_changed  >>  4 ) & 1 )
#define joy1_changed_c            ( ( joy1_changed  >>  5 ) & 1 )
#define joy1_changed_x            ( ( joy1_changed  >> 10 ) & 1 )
#define joy1_changed_y            ( ( joy1_changed  >>  9 ) & 1 )
#define joy1_changed_z            ( ( joy1_changed  >>  8 ) & 1 )
#define joy1_changed_start        ( ( joy1_changed  >>  7 ) & 1 )
#define joy1_changed_mode         ( ( joy1_changed  >> 11 ) & 1 )
#define joy1_changed_vertical     ( ( joy1_changed_up       | joy1_changed_down  ) )
#define joy1_changed_horizontal   ( ( joy1_changed_left     | joy1_changed_right ) )
#define joy1_changed_dir          ( ( joy1_changed_vertical | joy1_changed_horizontal ) )
#define joy1_changed_abc          ( ( joy1_changed_a        | joy1_changed_b | joy1_changed_c ) )
#define joy1_changed_abcs         ( ( joy1_changed_a        | joy1_changed_b | joy1_changed_c | joy1_changed_start) )
#define joy1_changed_xyz          ( ( joy1_changed_x        | joy1_changed_y | joy1_changed_z ) )
#define joy1_changed_btn          ( ( joy1_changed_abc      | joy1_changed_xyz  ) )

#define joy1_inactive             ( ( ~joy1.active ) )
#define joy1_inactive_up          ( ( joy1_inactive >>  0 ) & 1 )
#define joy1_inactive_down        ( ( joy1_inactive >>  1 ) & 1 )
#define joy1_inactive_left        ( ( joy1_inactive >>  2 ) & 1 )
#define joy1_inactive_right       ( ( joy1_inactive >>  3 ) & 1 )
#define joy1_inactive_a           ( ( joy1_inactive >>  6 ) & 1 )
#define joy1_inactive_b           ( ( joy1_inactive >>  4 ) & 1 )
#define joy1_inactive_c           ( ( joy1_inactive >>  5 ) & 1 )
#define joy1_inactive_x           ( ( joy1_inactive >> 10 ) & 1 )
#define joy1_inactive_y           ( ( joy1_inactive >>  9 ) & 1 )
#define joy1_inactive_z           ( ( joy1_inactive >>  8 ) & 1 )
#define joy1_inactive_start       ( ( joy1_inactive >>  7 ) & 1 )
#define joy1_inactive_mode        ( ( joy1_inactive >> 11 ) & 1 )
#define joy1_inactive_vertical    ( ( joy1_inactive_up       | joy1_inactive_down  ) )
#define joy1_inactive_horizontal  ( ( joy1_inactive_left     | joy1_inactive_right ) )
#define joy1_inactive_dir         ( ( joy1_inactive_vertical | joy1_inactive_horizontal ) )
#define joy1_inactive_abc         ( ( joy1_inactive_a        | joy1_inactive_b | joy1_inactive_c ) )
#define joy1_inactive_abcs        ( ( joy1_inactive_a        | joy1_inactive_b | joy1_inactive_c | joy1_inactive_start) )
#define joy1_inactive_xyz         ( ( joy1_inactive_x        | joy1_inactive_y | joy1_inactive_z ) )
#define joy1_inactive_btn         ( ( joy1_inactive_abc      | joy1_inactive_xyz  ) )

#define joy1_pressed              ( ( joy1.active & joy1.changed ) )
#define joy1_pressed_up           ( ( joy1_pressed  >>  0 ) & 1 )
#define joy1_pressed_down         ( ( joy1_pressed  >>  1 ) & 1 )
#define joy1_pressed_left         ( ( joy1_pressed  >>  2 ) & 1 )
#define joy1_pressed_right        ( ( joy1_pressed  >>  3 ) & 1 )
#define joy1_pressed_a            ( ( joy1_pressed  >>  6 ) & 1 )
#define joy1_pressed_b            ( ( joy1_pressed  >>  4 ) & 1 )
#define joy1_pressed_c            ( ( joy1_pressed  >>  5 ) & 1 )
#define joy1_pressed_x            ( ( joy1_pressed  >> 10 ) & 1 )
#define joy1_pressed_y            ( ( joy1_pressed  >>  9 ) & 1 )
#define joy1_pressed_z            ( ( joy1_pressed  >>  8 ) & 1 )
#define joy1_pressed_start        ( ( joy1_pressed  >>  7 ) & 1 )
#define joy1_pressed_mode         ( ( joy1_pressed  >> 11 ) & 1 )
#define joy1_pressed_vertical     ( ( joy1_pressed_up       | joy1_pressed_down  ) )
#define joy1_pressed_horizontal   ( ( joy1_pressed_left     | joy1_pressed_right ) )
#define joy1_pressed_dir          ( ( joy1_pressed_vertical | joy1_pressed_horizontal ) )
#define joy1_pressed_abc          ( ( joy1_pressed_a        | joy1_pressed_b | joy1_pressed_c ) )
#define joy1_pressed_abcs         ( ( joy1_pressed_a        | joy1_pressed_b | joy1_pressed_c | joy1_pressed_start) )
#define joy1_pressed_xyz          ( ( joy1_pressed_x        | joy1_pressed_y | joy1_pressed_z ) )
#define joy1_pressed_btn          ( ( joy1_pressed_abc      | joy1_pressed_xyz  ) )

#define joy1_released             ( ( ~joy1.active & joy1.changed ) )
#define joy1_released_up          ( ( joy1_released >>  0 ) & 1 )
#define joy1_released_down        ( ( joy1_released >>  1 ) & 1 )
#define joy1_released_left        ( ( joy1_released >>  2 ) & 1 )
#define joy1_released_right       ( ( joy1_released >>  3 ) & 1 )
#define joy1_released_a           ( ( joy1_released >>  6 ) & 1 )
#define joy1_released_b           ( ( joy1_released >>  4 ) & 1 )
#define joy1_released_c           ( ( joy1_released >>  5 ) & 1 )
#define joy1_released_x           ( ( joy1_released >> 10 ) & 1 )
#define joy1_released_y           ( ( joy1_released >>  9 ) & 1 )
#define joy1_released_z           ( ( joy1_released >>  8 ) & 1 )
#define joy1_released_start       ( ( joy1_released >>  7 ) & 1 )
#define joy1_released_mode        ( ( joy1_released >> 11 ) & 1 )
#define joy1_released_vertical    ( ( joy1_released_up       | joy1_released_down  ) )
#define joy1_released_horizontal  ( ( joy1_released_left     | joy1_released_right ) )
#define joy1_released_dir         ( ( joy1_released_vertical | joy1_released_horizontal ) )
#define joy1_released_abc         ( ( joy1_released_a        | joy1_released_b | joy1_released_c ) )
#define joy1_released_abcs        ( ( joy1_released_a        | joy1_released_b | joy1_released_c | joy1_released_start) )
#define joy1_released_xyz         ( ( joy1_released_x        | joy1_released_y | joy1_released_z ) )
#define joy1_released_btn         ( ( joy1_released_abc      | joy1_released_xyz  ) )


//Public data
JoyReader joysticks [ JOY_MAX ];


//Public Functions
void      JoyReader_init   ( u8 joys );
void      JoyReader_update ( void );
void      JoyReader_reset  ( );
void      JoyReader_pause  ( );
void      JoyReader_resume ( );