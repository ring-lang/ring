#include "ring.h"


/*
	RingFreeGLUT Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/freeglut.h>


VM *pRingVMObject ;
char cDisplayFunction[250];
char cReshapeFunction[250];
char cIdleFunction[250];
char cKeyboardFunction[250];
char cSpecialFunction[250];
char cSpecialUpFunction[250];
char cMouseFunction[250];
char cMotionFunction[250];
char cMenuStatusFunction[250];
char cCloseFunction[250];
int nGLUTEventWidth ;
int nGLUTEventHeight ;
int nGLUTEventKey ;
int nGLUTEventX ;
int nGLUTEventY ;
int nGLUTEventButton ;
int nGLUTEventState ;
int nGLUTEventValue ;
int nGLUTEventStatus ;
List *pMenuFunctions;

RING_FUNC(ring_get_glut_rgb)
{
	RING_API_RETNUMBER(GLUT_RGB);
}

RING_FUNC(ring_get_glut_rgba)
{
	RING_API_RETNUMBER(GLUT_RGBA);
}

RING_FUNC(ring_get_glut_index)
{
	RING_API_RETNUMBER(GLUT_INDEX);
}

RING_FUNC(ring_get_glut_single)
{
	RING_API_RETNUMBER(GLUT_SINGLE);
}

RING_FUNC(ring_get_glut_double)
{
	RING_API_RETNUMBER(GLUT_DOUBLE);
}

RING_FUNC(ring_get_glut_accum)
{
	RING_API_RETNUMBER(GLUT_ACCUM);
}

RING_FUNC(ring_get_glut_alpha)
{
	RING_API_RETNUMBER(GLUT_ALPHA);
}

RING_FUNC(ring_get_glut_depth)
{
	RING_API_RETNUMBER(GLUT_DEPTH);
}

RING_FUNC(ring_get_glut_stencil)
{
	RING_API_RETNUMBER(GLUT_STENCIL);
}

RING_FUNC(ring_get_glut_multisample)
{
	RING_API_RETNUMBER(GLUT_MULTISAMPLE);
}

RING_FUNC(ring_get_glut_stereo)
{
	RING_API_RETNUMBER(GLUT_STEREO);
}

RING_FUNC(ring_get_glut_luminance)
{
	RING_API_RETNUMBER(GLUT_LUMINANCE);
}

RING_FUNC(ring_get_glut_key_f1)
{
	RING_API_RETNUMBER(GLUT_KEY_F1);
}

RING_FUNC(ring_get_glut_key_f2)
{
	RING_API_RETNUMBER(GLUT_KEY_F2);
}

RING_FUNC(ring_get_glut_key_f3)
{
	RING_API_RETNUMBER(GLUT_KEY_F3);
}

RING_FUNC(ring_get_glut_key_f4)
{
	RING_API_RETNUMBER(GLUT_KEY_F4);
}

RING_FUNC(ring_get_glut_key_f5)
{
	RING_API_RETNUMBER(GLUT_KEY_F5);
}

RING_FUNC(ring_get_glut_key_f6)
{
	RING_API_RETNUMBER(GLUT_KEY_F6);
}

RING_FUNC(ring_get_glut_key_f7)
{
	RING_API_RETNUMBER(GLUT_KEY_F7);
}

RING_FUNC(ring_get_glut_key_f8)
{
	RING_API_RETNUMBER(GLUT_KEY_F8);
}

RING_FUNC(ring_get_glut_key_f9)
{
	RING_API_RETNUMBER(GLUT_KEY_F9);
}

RING_FUNC(ring_get_glut_key_f10)
{
	RING_API_RETNUMBER(GLUT_KEY_F10);
}

RING_FUNC(ring_get_glut_key_f11)
{
	RING_API_RETNUMBER(GLUT_KEY_F11);
}

RING_FUNC(ring_get_glut_key_f12)
{
	RING_API_RETNUMBER(GLUT_KEY_F12);
}

RING_FUNC(ring_get_glut_key_left)
{
	RING_API_RETNUMBER(GLUT_KEY_LEFT);
}

RING_FUNC(ring_get_glut_key_up)
{
	RING_API_RETNUMBER(GLUT_KEY_UP);
}

RING_FUNC(ring_get_glut_key_right)
{
	RING_API_RETNUMBER(GLUT_KEY_RIGHT);
}

RING_FUNC(ring_get_glut_key_down)
{
	RING_API_RETNUMBER(GLUT_KEY_DOWN);
}

RING_FUNC(ring_get_glut_key_page_up)
{
	RING_API_RETNUMBER(GLUT_KEY_PAGE_UP);
}

RING_FUNC(ring_get_glut_key_page_down)
{
	RING_API_RETNUMBER(GLUT_KEY_PAGE_DOWN);
}

RING_FUNC(ring_get_glut_key_home)
{
	RING_API_RETNUMBER(GLUT_KEY_HOME);
}

RING_FUNC(ring_get_glut_key_end)
{
	RING_API_RETNUMBER(GLUT_KEY_END);
}

RING_FUNC(ring_get_glut_key_insert)
{
	RING_API_RETNUMBER(GLUT_KEY_INSERT);
}

RING_FUNC(ring_get_glut_left_button)
{
	RING_API_RETNUMBER(GLUT_LEFT_BUTTON);
}

RING_FUNC(ring_get_glut_middle_button)
{
	RING_API_RETNUMBER(GLUT_MIDDLE_BUTTON);
}

RING_FUNC(ring_get_glut_right_button)
{
	RING_API_RETNUMBER(GLUT_RIGHT_BUTTON);
}

RING_FUNC(ring_get_glut_down)
{
	RING_API_RETNUMBER(GLUT_DOWN);
}

RING_FUNC(ring_get_glut_up)
{
	RING_API_RETNUMBER(GLUT_UP);
}

RING_FUNC(ring_get_glut_left)
{
	RING_API_RETNUMBER(GLUT_LEFT);
}

RING_FUNC(ring_get_glut_entered)
{
	RING_API_RETNUMBER(GLUT_ENTERED);
}

RING_FUNC(ring_get_glut_menu_not_in_use)
{
	RING_API_RETNUMBER(GLUT_MENU_NOT_IN_USE);
}

RING_FUNC(ring_get_glut_menu_in_use)
{
	RING_API_RETNUMBER(GLUT_MENU_IN_USE);
}

RING_FUNC(ring_get_glut_not_visible)
{
	RING_API_RETNUMBER(GLUT_NOT_VISIBLE);
}

RING_FUNC(ring_get_glut_visible)
{
	RING_API_RETNUMBER(GLUT_VISIBLE);
}

RING_FUNC(ring_get_glut_hidden)
{
	RING_API_RETNUMBER(GLUT_HIDDEN);
}

RING_FUNC(ring_get_glut_fully_retained)
{
	RING_API_RETNUMBER(GLUT_FULLY_RETAINED);
}

RING_FUNC(ring_get_glut_partially_retained)
{
	RING_API_RETNUMBER(GLUT_PARTIALLY_RETAINED);
}

RING_FUNC(ring_get_glut_fully_covered)
{
	RING_API_RETNUMBER(GLUT_FULLY_COVERED);
}

RING_FUNC(ring_get_glut_window_x)
{
	RING_API_RETNUMBER(GLUT_WINDOW_X);
}

RING_FUNC(ring_get_glut_window_y)
{
	RING_API_RETNUMBER(GLUT_WINDOW_Y);
}

RING_FUNC(ring_get_glut_window_width)
{
	RING_API_RETNUMBER(GLUT_WINDOW_WIDTH);
}

RING_FUNC(ring_get_glut_window_height)
{
	RING_API_RETNUMBER(GLUT_WINDOW_HEIGHT);
}

RING_FUNC(ring_get_glut_window_buffer_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_BUFFER_SIZE);
}

RING_FUNC(ring_get_glut_window_stencil_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_STENCIL_SIZE);
}

RING_FUNC(ring_get_glut_window_depth_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_DEPTH_SIZE);
}

RING_FUNC(ring_get_glut_window_red_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_RED_SIZE);
}

RING_FUNC(ring_get_glut_window_green_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_GREEN_SIZE);
}

RING_FUNC(ring_get_glut_window_blue_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_BLUE_SIZE);
}

RING_FUNC(ring_get_glut_window_alpha_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ALPHA_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_red_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_RED_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_green_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_GREEN_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_blue_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_BLUE_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_alpha_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_ALPHA_SIZE);
}

RING_FUNC(ring_get_glut_window_doublebuffer)
{
	RING_API_RETNUMBER(GLUT_WINDOW_DOUBLEBUFFER);
}

RING_FUNC(ring_get_glut_window_rgba)
{
	RING_API_RETNUMBER(GLUT_WINDOW_RGBA);
}

RING_FUNC(ring_get_glut_window_parent)
{
	RING_API_RETNUMBER(GLUT_WINDOW_PARENT);
}

RING_FUNC(ring_get_glut_window_num_children)
{
	RING_API_RETNUMBER(GLUT_WINDOW_NUM_CHILDREN);
}

RING_FUNC(ring_get_glut_window_colormap_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_COLORMAP_SIZE);
}

RING_FUNC(ring_get_glut_window_num_samples)
{
	RING_API_RETNUMBER(GLUT_WINDOW_NUM_SAMPLES);
}

RING_FUNC(ring_get_glut_window_stereo)
{
	RING_API_RETNUMBER(GLUT_WINDOW_STEREO);
}

RING_FUNC(ring_get_glut_window_cursor)
{
	RING_API_RETNUMBER(GLUT_WINDOW_CURSOR);
}

RING_FUNC(ring_get_glut_screen_width)
{
	RING_API_RETNUMBER(GLUT_SCREEN_WIDTH);
}

RING_FUNC(ring_get_glut_screen_height)
{
	RING_API_RETNUMBER(GLUT_SCREEN_HEIGHT);
}

RING_FUNC(ring_get_glut_screen_width_mm)
{
	RING_API_RETNUMBER(GLUT_SCREEN_WIDTH_MM);
}

RING_FUNC(ring_get_glut_screen_height_mm)
{
	RING_API_RETNUMBER(GLUT_SCREEN_HEIGHT_MM);
}

RING_FUNC(ring_get_glut_menu_num_items)
{
	RING_API_RETNUMBER(GLUT_MENU_NUM_ITEMS);
}

RING_FUNC(ring_get_glut_display_mode_possible)
{
	RING_API_RETNUMBER(GLUT_DISPLAY_MODE_POSSIBLE);
}

RING_FUNC(ring_get_glut_init_window_x)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_X);
}

RING_FUNC(ring_get_glut_init_window_y)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_Y);
}

RING_FUNC(ring_get_glut_init_window_width)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_WIDTH);
}

RING_FUNC(ring_get_glut_init_window_height)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_HEIGHT);
}

RING_FUNC(ring_get_glut_init_display_mode)
{
	RING_API_RETNUMBER(GLUT_INIT_DISPLAY_MODE);
}

RING_FUNC(ring_get_glut_elapsed_time)
{
	RING_API_RETNUMBER(GLUT_ELAPSED_TIME);
}

RING_FUNC(ring_get_glut_window_format_id)
{
	RING_API_RETNUMBER(GLUT_WINDOW_FORMAT_ID);
}

RING_FUNC(ring_get_glut_has_keyboard)
{
	RING_API_RETNUMBER(GLUT_HAS_KEYBOARD);
}

RING_FUNC(ring_get_glut_has_mouse)
{
	RING_API_RETNUMBER(GLUT_HAS_MOUSE);
}

RING_FUNC(ring_get_glut_has_spaceball)
{
	RING_API_RETNUMBER(GLUT_HAS_SPACEBALL);
}

RING_FUNC(ring_get_glut_has_dial_and_button_box)
{
	RING_API_RETNUMBER(GLUT_HAS_DIAL_AND_BUTTON_BOX);
}

RING_FUNC(ring_get_glut_has_tablet)
{
	RING_API_RETNUMBER(GLUT_HAS_TABLET);
}

RING_FUNC(ring_get_glut_num_mouse_buttons)
{
	RING_API_RETNUMBER(GLUT_NUM_MOUSE_BUTTONS);
}

RING_FUNC(ring_get_glut_num_spaceball_buttons)
{
	RING_API_RETNUMBER(GLUT_NUM_SPACEBALL_BUTTONS);
}

RING_FUNC(ring_get_glut_num_button_box_buttons)
{
	RING_API_RETNUMBER(GLUT_NUM_BUTTON_BOX_BUTTONS);
}

RING_FUNC(ring_get_glut_num_dials)
{
	RING_API_RETNUMBER(GLUT_NUM_DIALS);
}

RING_FUNC(ring_get_glut_num_tablet_buttons)
{
	RING_API_RETNUMBER(GLUT_NUM_TABLET_BUTTONS);
}

RING_FUNC(ring_get_glut_device_ignore_key_repeat)
{
	RING_API_RETNUMBER(GLUT_DEVICE_IGNORE_KEY_REPEAT);
}

RING_FUNC(ring_get_glut_device_key_repeat)
{
	RING_API_RETNUMBER(GLUT_DEVICE_KEY_REPEAT);
}

RING_FUNC(ring_get_glut_has_joystick)
{
	RING_API_RETNUMBER(GLUT_HAS_JOYSTICK);
}

RING_FUNC(ring_get_glut_owns_joystick)
{
	RING_API_RETNUMBER(GLUT_OWNS_JOYSTICK);
}

RING_FUNC(ring_get_glut_joystick_buttons)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_BUTTONS);
}

RING_FUNC(ring_get_glut_joystick_axes)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_AXES);
}

RING_FUNC(ring_get_glut_joystick_poll_rate)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_POLL_RATE);
}

RING_FUNC(ring_get_glut_overlay_possible)
{
	RING_API_RETNUMBER(GLUT_OVERLAY_POSSIBLE);
}

RING_FUNC(ring_get_glut_layer_in_use)
{
	RING_API_RETNUMBER(GLUT_LAYER_IN_USE);
}

RING_FUNC(ring_get_glut_has_overlay)
{
	RING_API_RETNUMBER(GLUT_HAS_OVERLAY);
}

RING_FUNC(ring_get_glut_transparent_index)
{
	RING_API_RETNUMBER(GLUT_TRANSPARENT_INDEX);
}

RING_FUNC(ring_get_glut_normal_damaged)
{
	RING_API_RETNUMBER(GLUT_NORMAL_DAMAGED);
}

RING_FUNC(ring_get_glut_overlay_damaged)
{
	RING_API_RETNUMBER(GLUT_OVERLAY_DAMAGED);
}

RING_FUNC(ring_get_glut_video_resize_possible)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_POSSIBLE);
}

RING_FUNC(ring_get_glut_video_resize_in_use)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_IN_USE);
}

RING_FUNC(ring_get_glut_video_resize_x_delta)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_X_DELTA);
}

RING_FUNC(ring_get_glut_video_resize_y_delta)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_Y_DELTA);
}

RING_FUNC(ring_get_glut_video_resize_width_delta)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_WIDTH_DELTA);
}

RING_FUNC(ring_get_glut_video_resize_height_delta)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_HEIGHT_DELTA);
}

RING_FUNC(ring_get_glut_video_resize_x)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_X);
}

RING_FUNC(ring_get_glut_video_resize_y)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_Y);
}

RING_FUNC(ring_get_glut_video_resize_width)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_WIDTH);
}

RING_FUNC(ring_get_glut_video_resize_height)
{
	RING_API_RETNUMBER(GLUT_VIDEO_RESIZE_HEIGHT);
}

RING_FUNC(ring_get_glut_normal)
{
	RING_API_RETNUMBER(GLUT_NORMAL);
}

RING_FUNC(ring_get_glut_overlay)
{
	RING_API_RETNUMBER(GLUT_OVERLAY);
}

RING_FUNC(ring_get_glut_active_shift)
{
	RING_API_RETNUMBER(GLUT_ACTIVE_SHIFT);
}

RING_FUNC(ring_get_glut_active_ctrl)
{
	RING_API_RETNUMBER(GLUT_ACTIVE_CTRL);
}

RING_FUNC(ring_get_glut_active_alt)
{
	RING_API_RETNUMBER(GLUT_ACTIVE_ALT);
}

RING_FUNC(ring_get_glut_cursor_right_arrow)
{
	RING_API_RETNUMBER(GLUT_CURSOR_RIGHT_ARROW);
}

RING_FUNC(ring_get_glut_cursor_left_arrow)
{
	RING_API_RETNUMBER(GLUT_CURSOR_LEFT_ARROW);
}

RING_FUNC(ring_get_glut_cursor_info)
{
	RING_API_RETNUMBER(GLUT_CURSOR_INFO);
}

RING_FUNC(ring_get_glut_cursor_destroy)
{
	RING_API_RETNUMBER(GLUT_CURSOR_DESTROY);
}

RING_FUNC(ring_get_glut_cursor_help)
{
	RING_API_RETNUMBER(GLUT_CURSOR_HELP);
}

RING_FUNC(ring_get_glut_cursor_cycle)
{
	RING_API_RETNUMBER(GLUT_CURSOR_CYCLE);
}

RING_FUNC(ring_get_glut_cursor_spray)
{
	RING_API_RETNUMBER(GLUT_CURSOR_SPRAY);
}

RING_FUNC(ring_get_glut_cursor_wait)
{
	RING_API_RETNUMBER(GLUT_CURSOR_WAIT);
}

RING_FUNC(ring_get_glut_cursor_text)
{
	RING_API_RETNUMBER(GLUT_CURSOR_TEXT);
}

RING_FUNC(ring_get_glut_cursor_crosshair)
{
	RING_API_RETNUMBER(GLUT_CURSOR_CROSSHAIR);
}

RING_FUNC(ring_get_glut_cursor_up_down)
{
	RING_API_RETNUMBER(GLUT_CURSOR_UP_DOWN);
}

RING_FUNC(ring_get_glut_cursor_left_right)
{
	RING_API_RETNUMBER(GLUT_CURSOR_LEFT_RIGHT);
}

RING_FUNC(ring_get_glut_cursor_top_side)
{
	RING_API_RETNUMBER(GLUT_CURSOR_TOP_SIDE);
}

RING_FUNC(ring_get_glut_cursor_bottom_side)
{
	RING_API_RETNUMBER(GLUT_CURSOR_BOTTOM_SIDE);
}

RING_FUNC(ring_get_glut_cursor_left_side)
{
	RING_API_RETNUMBER(GLUT_CURSOR_LEFT_SIDE);
}

RING_FUNC(ring_get_glut_cursor_right_side)
{
	RING_API_RETNUMBER(GLUT_CURSOR_RIGHT_SIDE);
}

RING_FUNC(ring_get_glut_cursor_top_left_corner)
{
	RING_API_RETNUMBER(GLUT_CURSOR_TOP_LEFT_CORNER);
}

RING_FUNC(ring_get_glut_cursor_top_right_corner)
{
	RING_API_RETNUMBER(GLUT_CURSOR_TOP_RIGHT_CORNER);
}

RING_FUNC(ring_get_glut_cursor_bottom_right_corner)
{
	RING_API_RETNUMBER(GLUT_CURSOR_BOTTOM_RIGHT_CORNER);
}

RING_FUNC(ring_get_glut_cursor_bottom_left_corner)
{
	RING_API_RETNUMBER(GLUT_CURSOR_BOTTOM_LEFT_CORNER);
}

RING_FUNC(ring_get_glut_cursor_inherit)
{
	RING_API_RETNUMBER(GLUT_CURSOR_INHERIT);
}

RING_FUNC(ring_get_glut_cursor_none)
{
	RING_API_RETNUMBER(GLUT_CURSOR_NONE);
}

RING_FUNC(ring_get_glut_cursor_full_crosshair)
{
	RING_API_RETNUMBER(GLUT_CURSOR_FULL_CROSSHAIR);
}

RING_FUNC(ring_get_glut_red)
{
	RING_API_RETNUMBER(GLUT_RED);
}

RING_FUNC(ring_get_glut_green)
{
	RING_API_RETNUMBER(GLUT_GREEN);
}

RING_FUNC(ring_get_glut_blue)
{
	RING_API_RETNUMBER(GLUT_BLUE);
}

RING_FUNC(ring_get_glut_key_repeat_off)
{
	RING_API_RETNUMBER(GLUT_KEY_REPEAT_OFF);
}

RING_FUNC(ring_get_glut_key_repeat_on)
{
	RING_API_RETNUMBER(GLUT_KEY_REPEAT_ON);
}

RING_FUNC(ring_get_glut_key_repeat_default)
{
	RING_API_RETNUMBER(GLUT_KEY_REPEAT_DEFAULT);
}

RING_FUNC(ring_get_glut_joystick_button_a)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_BUTTON_A);
}

RING_FUNC(ring_get_glut_joystick_button_b)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_BUTTON_B);
}

RING_FUNC(ring_get_glut_joystick_button_c)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_BUTTON_C);
}

RING_FUNC(ring_get_glut_joystick_button_d)
{
	RING_API_RETNUMBER(GLUT_JOYSTICK_BUTTON_D);
}

RING_FUNC(ring_get_glut_game_mode_active)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_ACTIVE);
}

RING_FUNC(ring_get_glut_game_mode_possible)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_POSSIBLE);
}

RING_FUNC(ring_get_glut_game_mode_width)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_WIDTH);
}

RING_FUNC(ring_get_glut_game_mode_height)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_HEIGHT);
}

RING_FUNC(ring_get_glut_game_mode_pixel_depth)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_PIXEL_DEPTH);
}

RING_FUNC(ring_get_glut_game_mode_refresh_rate)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_REFRESH_RATE);
}

RING_FUNC(ring_get_glut_game_mode_display_changed)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_DISPLAY_CHANGED);
}

RING_FUNC(ring_get_glut_stroke_roman)
{
	RING_API_RETCPOINTER(GLUT_STROKE_ROMAN,"void");
}

RING_FUNC(ring_get_glut_stroke_mono_roman)
{
	RING_API_RETCPOINTER(GLUT_STROKE_MONO_ROMAN,"void");
}

RING_FUNC(ring_get_glut_bitmap_9_by_15)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_9_BY_15,"void");
}

RING_FUNC(ring_get_glut_bitmap_8_by_13)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_8_BY_13,"void");
}

RING_FUNC(ring_get_glut_bitmap_times_roman_10)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_TIMES_ROMAN_10,"void");
}

RING_FUNC(ring_get_glut_bitmap_times_roman_24)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_TIMES_ROMAN_24,"void");
}

RING_FUNC(ring_get_glut_bitmap_helvetica_10)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_HELVETICA_10,"void");
}

RING_FUNC(ring_get_glut_bitmap_helvetica_12)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_HELVETICA_12,"void");
}

RING_FUNC(ring_get_glut_bitmap_helvetica_18)
{
	RING_API_RETCPOINTER(GLUT_BITMAP_HELVETICA_18,"void");
}


RING_FUNC(ring_glutInit)
{
	VM *pVM ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	pVM = (VM *) pPointer ;
	glutInit( & pVM->pRingState->argc, pVM->pRingState->argv);
}

void displayFunction(void)
{
	ring_vm_callfunction(pRingVMObject,cDisplayFunction) ;
}

RING_FUNC(ring_glutDisplayFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cDisplayFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutDisplayFunc(displayFunction);
	}
}

void closeFunction(void)
{
	ring_vm_callfunction(pRingVMObject,cCloseFunction) ;
}

RING_FUNC(ring_glutCloseFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cCloseFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutCloseFunc(closeFunction);
	}
}

void reshapeFunction(int w, int h)
{
	nGLUTEventWidth = w;
	nGLUTEventHeight = h ;
	ring_vm_callfunction(pRingVMObject,cReshapeFunction) ;
}

RING_FUNC(ring_glutReshapeFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cReshapeFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutReshapeFunc(reshapeFunction);
	}
}

RING_FUNC(ring_glutEventWidth)
{
	RING_API_RETNUMBER(nGLUTEventWidth);
}

RING_FUNC(ring_glutEventHeight)
{
	RING_API_RETNUMBER(nGLUTEventHeight);
}

void IdleFunction(void)
{
	ring_vm_callfunction(pRingVMObject,cIdleFunction) ;
}

RING_FUNC(ring_glutIdleFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cIdleFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutIdleFunc(IdleFunction);
	}
}

void KeyboardFunction(unsigned char key, int x, int y)
{
	nGLUTEventKey = (int) key ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_callfunction(pRingVMObject,cKeyboardFunction) ;
}

RING_FUNC(ring_glutKeyboardFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cKeyboardFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutKeyboardFunc(KeyboardFunction);
	}
}

void SpecialFunction(int key, int x, int y)
{
	nGLUTEventKey = key ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_callfunction(pRingVMObject,cSpecialFunction) ;
}

RING_FUNC(ring_glutSpecialFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cSpecialFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutSpecialFunc(SpecialFunction);
	}
}

void SpecialUpFunction(int key, int x, int y)
{
	nGLUTEventKey = key ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_callfunction(pRingVMObject,cSpecialUpFunction) ;
}

RING_FUNC(ring_glutSpecialUpFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cSpecialUpFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutSpecialUpFunc(SpecialUpFunction);
	}
}

void MouseFunction(int button,int state, int x, int y)
{
	nGLUTEventButton = button ;
	nGLUTEventState = state ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_callfunction(pRingVMObject,cMouseFunction) ;
}

RING_FUNC(ring_glutMouseFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cMouseFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutMouseFunc(MouseFunction);
	}
}

void MotionFunction(int x, int y)
{
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_callfunction(pRingVMObject,cMotionFunction) ;
}

RING_FUNC(ring_glutMotionFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cMotionFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutMotionFunc(MotionFunction);
	}
}

void MenuFunction(int value)
{
	int x;
	nGLUTEventValue = value ;
	for (x = 1 ; x<= ring_list_getsize(pMenuFunctions) ; x ++ )
		ring_vm_callfunction(pRingVMObject,ring_list_getstring(pMenuFunctions, x ) ) ;
}

RING_FUNC(ring_glutCreateMenu) {
	int nMenuID ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		pRingVMObject = (VM *) pPointer ;
		nMenuID = glutCreateMenu(MenuFunction);
		if (nMenuID == 1)
			pMenuFunctions = ring_list_new(0);
		ring_list_addstring(pMenuFunctions, RING_API_GETSTRING(1) ) ;
		RING_API_RETNUMBER( nMenuID ) ;
	}	
}

void MenuStatusFunction(int status,int x, int y)
{
	nGLUTEventStatus = status ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_callfunction(pRingVMObject,cMenuStatusFunction) ;
}

RING_FUNC(ring_glutMenuStatusFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cMenuStatusFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutMenuStatusFunc(MenuStatusFunction);
	}
}

RING_FUNC(ring_glutEventKey) {
	RING_API_RETNUMBER(nGLUTEventKey);
}

RING_FUNC(ring_glutEventX) {
	RING_API_RETNUMBER(nGLUTEventX);
}

RING_FUNC(ring_glutEventY) {
	RING_API_RETNUMBER(nGLUTEventY);
}

RING_FUNC(ring_glutEventButton) {
	RING_API_RETNUMBER(nGLUTEventButton);
}

RING_FUNC(ring_glutEventState) {
	RING_API_RETNUMBER(nGLUTEventState);
}

RING_FUNC(ring_glutEventValue) {
	RING_API_RETNUMBER(nGLUTEventValue);
}

RING_FUNC(ring_glutEventStatus) {
	RING_API_RETNUMBER(nGLUTEventStatus);
}

RING_FUNC(ring_test_draw) {
	// Reserved for Testing
}

RING_FUNC(ring_glutInitWindowPosition)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutInitWindowPosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutInitWindowSize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutInitWindowSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutInitDisplayMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutInitDisplayMode( (unsigned ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutInitDisplayString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutInitDisplayString(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glutCreateWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutCreateWindow(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_glutCreateSubWindow)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutCreateSubWindow( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_glutDestroyWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutDestroyWindow( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutSetWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetWindow( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutGetWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glutGetWindow());
}


RING_FUNC(ring_glutSetWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetWindowTitle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glutSetIconTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetIconTitle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glutReshapeWindow)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutReshapeWindow( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutPositionWindow)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutPositionWindow( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutShowWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutShowWindow();
}


RING_FUNC(ring_glutHideWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutHideWindow();
}


RING_FUNC(ring_glutIconifyWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutIconifyWindow();
}


RING_FUNC(ring_glutPushWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutPushWindow();
}


RING_FUNC(ring_glutPopWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutPopWindow();
}


RING_FUNC(ring_glutFullScreen)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutFullScreen();
}


RING_FUNC(ring_glutPostWindowRedisplay)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutPostWindowRedisplay( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutPostRedisplay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutPostRedisplay();
}


RING_FUNC(ring_glutSwapBuffers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSwapBuffers();
}


RING_FUNC(ring_glutWarpPointer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWarpPointer( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutSetCursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetCursor( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutEstablishOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutEstablishOverlay();
}


RING_FUNC(ring_glutRemoveOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutRemoveOverlay();
}


RING_FUNC(ring_glutUseLayer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutUseLayer( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutPostOverlayRedisplay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutPostOverlayRedisplay();
}


RING_FUNC(ring_glutPostWindowOverlayRedisplay)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutPostWindowOverlayRedisplay( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutShowOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutShowOverlay();
}


RING_FUNC(ring_glutHideOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutHideOverlay();
}


RING_FUNC(ring_glutDestroyMenu)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutDestroyMenu( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutGetMenu)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glutGetMenu());
}


RING_FUNC(ring_glutSetMenu)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetMenu( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutAddMenuEntry)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutAddMenuEntry(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutAddSubMenu)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutAddSubMenu(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutChangeToMenuEntry)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutChangeToMenuEntry( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glutChangeToSubMenu)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutChangeToSubMenu( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glutRemoveMenuItem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutRemoveMenuItem( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutAttachMenu)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutAttachMenu( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutDetachMenu)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutDetachMenu( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutGet( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glutDeviceGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutDeviceGet( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glutGetModifiers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glutGetModifiers());
}


RING_FUNC(ring_glutLayerGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutLayerGet( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glutBitmapCharacter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutBitmapCharacter((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutBitmapWidth)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutBitmapWidth((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutStrokeCharacter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutStrokeCharacter((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutStrokeWidth)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeWidth((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutStrokeLength)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeLength((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_glutStrokeWidthf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeWidthf((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutStrokeLengthf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeLengthf((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_glutBitmapLength)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutBitmapLength((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_glutWireCube)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireCube( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutSolidCube)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidCube( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutWireSphere)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireSphere( (double ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glutSolidSphere)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidSphere( (double ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glutWireCone)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireCone( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutSolidCone)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidCone( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutWireTorus)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireTorus( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutSolidTorus)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidTorus( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutWireDodecahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireDodecahedron();
}


RING_FUNC(ring_glutSolidDodecahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidDodecahedron();
}


RING_FUNC(ring_glutWireOctahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireOctahedron();
}


RING_FUNC(ring_glutSolidOctahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidOctahedron();
}


RING_FUNC(ring_glutWireTetrahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireTetrahedron();
}


RING_FUNC(ring_glutSolidTetrahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidTetrahedron();
}


RING_FUNC(ring_glutWireIcosahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireIcosahedron();
}


RING_FUNC(ring_glutSolidIcosahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidIcosahedron();
}


RING_FUNC(ring_glutWireTeapot)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireTeapot( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutSolidTeapot)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidTeapot( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutGameModeString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutGameModeString(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glutEnterGameMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glutEnterGameMode());
}


RING_FUNC(ring_glutLeaveGameMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutLeaveGameMode();
}


RING_FUNC(ring_glutGameModeGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutGameModeGet( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glutVideoResizeGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutVideoResizeGet( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glutSetupVideoResizing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSetupVideoResizing();
}


RING_FUNC(ring_glutStopVideoResizing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutStopVideoResizing();
}


RING_FUNC(ring_glutVideoResize)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutVideoResize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutVideoPan)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutVideoPan( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutSetColor)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetColor( (int ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutGetColor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutGetColor( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutCopyColormap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutCopyColormap( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutIgnoreKeyRepeat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutIgnoreKeyRepeat( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutSetKeyRepeat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetKeyRepeat( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutForceJoystickFunc)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutForceJoystickFunc();
}


RING_FUNC(ring_glutExtensionSupported)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutExtensionSupported(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_glutReportErrors)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutReportErrors();
}


RING_FUNC(ring_glutMainLoop)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutMainLoop();
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("glutinit",ring_glutInit);
	ring_vm_funcregister("glutdisplayfunc",ring_glutDisplayFunc);
	ring_vm_funcregister("glutclosefunc",ring_glutCloseFunc);
	ring_vm_funcregister("glutreshapefunc",ring_glutReshapeFunc);
	ring_vm_funcregister("gluteventwidth",ring_glutEventWidth);
	ring_vm_funcregister("gluteventheight",ring_glutEventHeight);
	ring_vm_funcregister("glutidlefunc",ring_glutIdleFunc);
	ring_vm_funcregister("glutkeyboardfunc",ring_glutKeyboardFunc);
	ring_vm_funcregister("glutspecialfunc",ring_glutSpecialFunc);
	ring_vm_funcregister("glutspecialupfunc",ring_glutSpecialUpFunc);
	ring_vm_funcregister("glutmousefunc",ring_glutMouseFunc);
	ring_vm_funcregister("glutmotionfunc",ring_glutMotionFunc);
	ring_vm_funcregister("glutcreatemenu",ring_glutCreateMenu);
	ring_vm_funcregister("glutmenustatusfunc",ring_glutMenuStatusFunc);
	ring_vm_funcregister("gluteventkey",ring_glutEventKey);
	ring_vm_funcregister("gluteventx",ring_glutEventX);
	ring_vm_funcregister("gluteventy",ring_glutEventY);
	ring_vm_funcregister("gluteventbutton",ring_glutEventButton);
	ring_vm_funcregister("gluteventstate",ring_glutEventState);
	ring_vm_funcregister("gluteventvalue",ring_glutEventValue);
	ring_vm_funcregister("gluteventstatus",ring_glutEventStatus);
	ring_vm_funcregister("test_draw",ring_test_draw);
	ring_vm_funcregister("glutinitwindowposition",ring_glutInitWindowPosition);
	ring_vm_funcregister("glutinitwindowsize",ring_glutInitWindowSize);
	ring_vm_funcregister("glutinitdisplaymode",ring_glutInitDisplayMode);
	ring_vm_funcregister("glutinitdisplaystring",ring_glutInitDisplayString);
	ring_vm_funcregister("glutcreatewindow",ring_glutCreateWindow);
	ring_vm_funcregister("glutcreatesubwindow",ring_glutCreateSubWindow);
	ring_vm_funcregister("glutdestroywindow",ring_glutDestroyWindow);
	ring_vm_funcregister("glutsetwindow",ring_glutSetWindow);
	ring_vm_funcregister("glutgetwindow",ring_glutGetWindow);
	ring_vm_funcregister("glutsetwindowtitle",ring_glutSetWindowTitle);
	ring_vm_funcregister("glutseticontitle",ring_glutSetIconTitle);
	ring_vm_funcregister("glutreshapewindow",ring_glutReshapeWindow);
	ring_vm_funcregister("glutpositionwindow",ring_glutPositionWindow);
	ring_vm_funcregister("glutshowwindow",ring_glutShowWindow);
	ring_vm_funcregister("gluthidewindow",ring_glutHideWindow);
	ring_vm_funcregister("gluticonifywindow",ring_glutIconifyWindow);
	ring_vm_funcregister("glutpushwindow",ring_glutPushWindow);
	ring_vm_funcregister("glutpopwindow",ring_glutPopWindow);
	ring_vm_funcregister("glutfullscreen",ring_glutFullScreen);
	ring_vm_funcregister("glutpostwindowredisplay",ring_glutPostWindowRedisplay);
	ring_vm_funcregister("glutpostredisplay",ring_glutPostRedisplay);
	ring_vm_funcregister("glutswapbuffers",ring_glutSwapBuffers);
	ring_vm_funcregister("glutwarppointer",ring_glutWarpPointer);
	ring_vm_funcregister("glutsetcursor",ring_glutSetCursor);
	ring_vm_funcregister("glutestablishoverlay",ring_glutEstablishOverlay);
	ring_vm_funcregister("glutremoveoverlay",ring_glutRemoveOverlay);
	ring_vm_funcregister("glutuselayer",ring_glutUseLayer);
	ring_vm_funcregister("glutpostoverlayredisplay",ring_glutPostOverlayRedisplay);
	ring_vm_funcregister("glutpostwindowoverlayredisplay",ring_glutPostWindowOverlayRedisplay);
	ring_vm_funcregister("glutshowoverlay",ring_glutShowOverlay);
	ring_vm_funcregister("gluthideoverlay",ring_glutHideOverlay);
	ring_vm_funcregister("glutdestroymenu",ring_glutDestroyMenu);
	ring_vm_funcregister("glutgetmenu",ring_glutGetMenu);
	ring_vm_funcregister("glutsetmenu",ring_glutSetMenu);
	ring_vm_funcregister("glutaddmenuentry",ring_glutAddMenuEntry);
	ring_vm_funcregister("glutaddsubmenu",ring_glutAddSubMenu);
	ring_vm_funcregister("glutchangetomenuentry",ring_glutChangeToMenuEntry);
	ring_vm_funcregister("glutchangetosubmenu",ring_glutChangeToSubMenu);
	ring_vm_funcregister("glutremovemenuitem",ring_glutRemoveMenuItem);
	ring_vm_funcregister("glutattachmenu",ring_glutAttachMenu);
	ring_vm_funcregister("glutdetachmenu",ring_glutDetachMenu);
	ring_vm_funcregister("glutget",ring_glutGet);
	ring_vm_funcregister("glutdeviceget",ring_glutDeviceGet);
	ring_vm_funcregister("glutgetmodifiers",ring_glutGetModifiers);
	ring_vm_funcregister("glutlayerget",ring_glutLayerGet);
	ring_vm_funcregister("glutbitmapcharacter",ring_glutBitmapCharacter);
	ring_vm_funcregister("glutbitmapwidth",ring_glutBitmapWidth);
	ring_vm_funcregister("glutstrokecharacter",ring_glutStrokeCharacter);
	ring_vm_funcregister("glutstrokewidth",ring_glutStrokeWidth);
	ring_vm_funcregister("glutstrokelength",ring_glutStrokeLength);
	ring_vm_funcregister("glutstrokewidthf",ring_glutStrokeWidthf);
	ring_vm_funcregister("glutstrokelengthf",ring_glutStrokeLengthf);
	ring_vm_funcregister("glutbitmaplength",ring_glutBitmapLength);
	ring_vm_funcregister("glutwirecube",ring_glutWireCube);
	ring_vm_funcregister("glutsolidcube",ring_glutSolidCube);
	ring_vm_funcregister("glutwiresphere",ring_glutWireSphere);
	ring_vm_funcregister("glutsolidsphere",ring_glutSolidSphere);
	ring_vm_funcregister("glutwirecone",ring_glutWireCone);
	ring_vm_funcregister("glutsolidcone",ring_glutSolidCone);
	ring_vm_funcregister("glutwiretorus",ring_glutWireTorus);
	ring_vm_funcregister("glutsolidtorus",ring_glutSolidTorus);
	ring_vm_funcregister("glutwiredodecahedron",ring_glutWireDodecahedron);
	ring_vm_funcregister("glutsoliddodecahedron",ring_glutSolidDodecahedron);
	ring_vm_funcregister("glutwireoctahedron",ring_glutWireOctahedron);
	ring_vm_funcregister("glutsolidoctahedron",ring_glutSolidOctahedron);
	ring_vm_funcregister("glutwiretetrahedron",ring_glutWireTetrahedron);
	ring_vm_funcregister("glutsolidtetrahedron",ring_glutSolidTetrahedron);
	ring_vm_funcregister("glutwireicosahedron",ring_glutWireIcosahedron);
	ring_vm_funcregister("glutsolidicosahedron",ring_glutSolidIcosahedron);
	ring_vm_funcregister("glutwireteapot",ring_glutWireTeapot);
	ring_vm_funcregister("glutsolidteapot",ring_glutSolidTeapot);
	ring_vm_funcregister("glutgamemodestring",ring_glutGameModeString);
	ring_vm_funcregister("glutentergamemode",ring_glutEnterGameMode);
	ring_vm_funcregister("glutleavegamemode",ring_glutLeaveGameMode);
	ring_vm_funcregister("glutgamemodeget",ring_glutGameModeGet);
	ring_vm_funcregister("glutvideoresizeget",ring_glutVideoResizeGet);
	ring_vm_funcregister("glutsetupvideoresizing",ring_glutSetupVideoResizing);
	ring_vm_funcregister("glutstopvideoresizing",ring_glutStopVideoResizing);
	ring_vm_funcregister("glutvideoresize",ring_glutVideoResize);
	ring_vm_funcregister("glutvideopan",ring_glutVideoPan);
	ring_vm_funcregister("glutsetcolor",ring_glutSetColor);
	ring_vm_funcregister("glutgetcolor",ring_glutGetColor);
	ring_vm_funcregister("glutcopycolormap",ring_glutCopyColormap);
	ring_vm_funcregister("glutignorekeyrepeat",ring_glutIgnoreKeyRepeat);
	ring_vm_funcregister("glutsetkeyrepeat",ring_glutSetKeyRepeat);
	ring_vm_funcregister("glutforcejoystickfunc",ring_glutForceJoystickFunc);
	ring_vm_funcregister("glutextensionsupported",ring_glutExtensionSupported);
	ring_vm_funcregister("glutreporterrors",ring_glutReportErrors);
	ring_vm_funcregister("glutmainloop",ring_glutMainLoop);
	ring_vm_funcregister("get_glut_rgb",ring_get_glut_rgb);
	ring_vm_funcregister("get_glut_rgba",ring_get_glut_rgba);
	ring_vm_funcregister("get_glut_index",ring_get_glut_index);
	ring_vm_funcregister("get_glut_single",ring_get_glut_single);
	ring_vm_funcregister("get_glut_double",ring_get_glut_double);
	ring_vm_funcregister("get_glut_accum",ring_get_glut_accum);
	ring_vm_funcregister("get_glut_alpha",ring_get_glut_alpha);
	ring_vm_funcregister("get_glut_depth",ring_get_glut_depth);
	ring_vm_funcregister("get_glut_stencil",ring_get_glut_stencil);
	ring_vm_funcregister("get_glut_multisample",ring_get_glut_multisample);
	ring_vm_funcregister("get_glut_stereo",ring_get_glut_stereo);
	ring_vm_funcregister("get_glut_luminance",ring_get_glut_luminance);
	ring_vm_funcregister("get_glut_key_f1",ring_get_glut_key_f1);
	ring_vm_funcregister("get_glut_key_f2",ring_get_glut_key_f2);
	ring_vm_funcregister("get_glut_key_f3",ring_get_glut_key_f3);
	ring_vm_funcregister("get_glut_key_f4",ring_get_glut_key_f4);
	ring_vm_funcregister("get_glut_key_f5",ring_get_glut_key_f5);
	ring_vm_funcregister("get_glut_key_f6",ring_get_glut_key_f6);
	ring_vm_funcregister("get_glut_key_f7",ring_get_glut_key_f7);
	ring_vm_funcregister("get_glut_key_f8",ring_get_glut_key_f8);
	ring_vm_funcregister("get_glut_key_f9",ring_get_glut_key_f9);
	ring_vm_funcregister("get_glut_key_f10",ring_get_glut_key_f10);
	ring_vm_funcregister("get_glut_key_f11",ring_get_glut_key_f11);
	ring_vm_funcregister("get_glut_key_f12",ring_get_glut_key_f12);
	ring_vm_funcregister("get_glut_key_left",ring_get_glut_key_left);
	ring_vm_funcregister("get_glut_key_up",ring_get_glut_key_up);
	ring_vm_funcregister("get_glut_key_right",ring_get_glut_key_right);
	ring_vm_funcregister("get_glut_key_down",ring_get_glut_key_down);
	ring_vm_funcregister("get_glut_key_page_up",ring_get_glut_key_page_up);
	ring_vm_funcregister("get_glut_key_page_down",ring_get_glut_key_page_down);
	ring_vm_funcregister("get_glut_key_home",ring_get_glut_key_home);
	ring_vm_funcregister("get_glut_key_end",ring_get_glut_key_end);
	ring_vm_funcregister("get_glut_key_insert",ring_get_glut_key_insert);
	ring_vm_funcregister("get_glut_left_button",ring_get_glut_left_button);
	ring_vm_funcregister("get_glut_middle_button",ring_get_glut_middle_button);
	ring_vm_funcregister("get_glut_right_button",ring_get_glut_right_button);
	ring_vm_funcregister("get_glut_down",ring_get_glut_down);
	ring_vm_funcregister("get_glut_up",ring_get_glut_up);
	ring_vm_funcregister("get_glut_left",ring_get_glut_left);
	ring_vm_funcregister("get_glut_entered",ring_get_glut_entered);
	ring_vm_funcregister("get_glut_menu_not_in_use",ring_get_glut_menu_not_in_use);
	ring_vm_funcregister("get_glut_menu_in_use",ring_get_glut_menu_in_use);
	ring_vm_funcregister("get_glut_not_visible",ring_get_glut_not_visible);
	ring_vm_funcregister("get_glut_visible",ring_get_glut_visible);
	ring_vm_funcregister("get_glut_hidden",ring_get_glut_hidden);
	ring_vm_funcregister("get_glut_fully_retained",ring_get_glut_fully_retained);
	ring_vm_funcregister("get_glut_partially_retained",ring_get_glut_partially_retained);
	ring_vm_funcregister("get_glut_fully_covered",ring_get_glut_fully_covered);
	ring_vm_funcregister("get_glut_window_x",ring_get_glut_window_x);
	ring_vm_funcregister("get_glut_window_y",ring_get_glut_window_y);
	ring_vm_funcregister("get_glut_window_width",ring_get_glut_window_width);
	ring_vm_funcregister("get_glut_window_height",ring_get_glut_window_height);
	ring_vm_funcregister("get_glut_window_buffer_size",ring_get_glut_window_buffer_size);
	ring_vm_funcregister("get_glut_window_stencil_size",ring_get_glut_window_stencil_size);
	ring_vm_funcregister("get_glut_window_depth_size",ring_get_glut_window_depth_size);
	ring_vm_funcregister("get_glut_window_red_size",ring_get_glut_window_red_size);
	ring_vm_funcregister("get_glut_window_green_size",ring_get_glut_window_green_size);
	ring_vm_funcregister("get_glut_window_blue_size",ring_get_glut_window_blue_size);
	ring_vm_funcregister("get_glut_window_alpha_size",ring_get_glut_window_alpha_size);
	ring_vm_funcregister("get_glut_window_accum_red_size",ring_get_glut_window_accum_red_size);
	ring_vm_funcregister("get_glut_window_accum_green_size",ring_get_glut_window_accum_green_size);
	ring_vm_funcregister("get_glut_window_accum_blue_size",ring_get_glut_window_accum_blue_size);
	ring_vm_funcregister("get_glut_window_accum_alpha_size",ring_get_glut_window_accum_alpha_size);
	ring_vm_funcregister("get_glut_window_doublebuffer",ring_get_glut_window_doublebuffer);
	ring_vm_funcregister("get_glut_window_rgba",ring_get_glut_window_rgba);
	ring_vm_funcregister("get_glut_window_parent",ring_get_glut_window_parent);
	ring_vm_funcregister("get_glut_window_num_children",ring_get_glut_window_num_children);
	ring_vm_funcregister("get_glut_window_colormap_size",ring_get_glut_window_colormap_size);
	ring_vm_funcregister("get_glut_window_num_samples",ring_get_glut_window_num_samples);
	ring_vm_funcregister("get_glut_window_stereo",ring_get_glut_window_stereo);
	ring_vm_funcregister("get_glut_window_cursor",ring_get_glut_window_cursor);
	ring_vm_funcregister("get_glut_screen_width",ring_get_glut_screen_width);
	ring_vm_funcregister("get_glut_screen_height",ring_get_glut_screen_height);
	ring_vm_funcregister("get_glut_screen_width_mm",ring_get_glut_screen_width_mm);
	ring_vm_funcregister("get_glut_screen_height_mm",ring_get_glut_screen_height_mm);
	ring_vm_funcregister("get_glut_menu_num_items",ring_get_glut_menu_num_items);
	ring_vm_funcregister("get_glut_display_mode_possible",ring_get_glut_display_mode_possible);
	ring_vm_funcregister("get_glut_init_window_x",ring_get_glut_init_window_x);
	ring_vm_funcregister("get_glut_init_window_y",ring_get_glut_init_window_y);
	ring_vm_funcregister("get_glut_init_window_width",ring_get_glut_init_window_width);
	ring_vm_funcregister("get_glut_init_window_height",ring_get_glut_init_window_height);
	ring_vm_funcregister("get_glut_init_display_mode",ring_get_glut_init_display_mode);
	ring_vm_funcregister("get_glut_elapsed_time",ring_get_glut_elapsed_time);
	ring_vm_funcregister("get_glut_window_format_id",ring_get_glut_window_format_id);
	ring_vm_funcregister("get_glut_has_keyboard",ring_get_glut_has_keyboard);
	ring_vm_funcregister("get_glut_has_mouse",ring_get_glut_has_mouse);
	ring_vm_funcregister("get_glut_has_spaceball",ring_get_glut_has_spaceball);
	ring_vm_funcregister("get_glut_has_dial_and_button_box",ring_get_glut_has_dial_and_button_box);
	ring_vm_funcregister("get_glut_has_tablet",ring_get_glut_has_tablet);
	ring_vm_funcregister("get_glut_num_mouse_buttons",ring_get_glut_num_mouse_buttons);
	ring_vm_funcregister("get_glut_num_spaceball_buttons",ring_get_glut_num_spaceball_buttons);
	ring_vm_funcregister("get_glut_num_button_box_buttons",ring_get_glut_num_button_box_buttons);
	ring_vm_funcregister("get_glut_num_dials",ring_get_glut_num_dials);
	ring_vm_funcregister("get_glut_num_tablet_buttons",ring_get_glut_num_tablet_buttons);
	ring_vm_funcregister("get_glut_device_ignore_key_repeat",ring_get_glut_device_ignore_key_repeat);
	ring_vm_funcregister("get_glut_device_key_repeat",ring_get_glut_device_key_repeat);
	ring_vm_funcregister("get_glut_has_joystick",ring_get_glut_has_joystick);
	ring_vm_funcregister("get_glut_owns_joystick",ring_get_glut_owns_joystick);
	ring_vm_funcregister("get_glut_joystick_buttons",ring_get_glut_joystick_buttons);
	ring_vm_funcregister("get_glut_joystick_axes",ring_get_glut_joystick_axes);
	ring_vm_funcregister("get_glut_joystick_poll_rate",ring_get_glut_joystick_poll_rate);
	ring_vm_funcregister("get_glut_overlay_possible",ring_get_glut_overlay_possible);
	ring_vm_funcregister("get_glut_layer_in_use",ring_get_glut_layer_in_use);
	ring_vm_funcregister("get_glut_has_overlay",ring_get_glut_has_overlay);
	ring_vm_funcregister("get_glut_transparent_index",ring_get_glut_transparent_index);
	ring_vm_funcregister("get_glut_normal_damaged",ring_get_glut_normal_damaged);
	ring_vm_funcregister("get_glut_overlay_damaged",ring_get_glut_overlay_damaged);
	ring_vm_funcregister("get_glut_video_resize_possible",ring_get_glut_video_resize_possible);
	ring_vm_funcregister("get_glut_video_resize_in_use",ring_get_glut_video_resize_in_use);
	ring_vm_funcregister("get_glut_video_resize_x_delta",ring_get_glut_video_resize_x_delta);
	ring_vm_funcregister("get_glut_video_resize_y_delta",ring_get_glut_video_resize_y_delta);
	ring_vm_funcregister("get_glut_video_resize_width_delta",ring_get_glut_video_resize_width_delta);
	ring_vm_funcregister("get_glut_video_resize_height_delta",ring_get_glut_video_resize_height_delta);
	ring_vm_funcregister("get_glut_video_resize_x",ring_get_glut_video_resize_x);
	ring_vm_funcregister("get_glut_video_resize_y",ring_get_glut_video_resize_y);
	ring_vm_funcregister("get_glut_video_resize_width",ring_get_glut_video_resize_width);
	ring_vm_funcregister("get_glut_video_resize_height",ring_get_glut_video_resize_height);
	ring_vm_funcregister("get_glut_normal",ring_get_glut_normal);
	ring_vm_funcregister("get_glut_overlay",ring_get_glut_overlay);
	ring_vm_funcregister("get_glut_active_shift",ring_get_glut_active_shift);
	ring_vm_funcregister("get_glut_active_ctrl",ring_get_glut_active_ctrl);
	ring_vm_funcregister("get_glut_active_alt",ring_get_glut_active_alt);
	ring_vm_funcregister("get_glut_cursor_right_arrow",ring_get_glut_cursor_right_arrow);
	ring_vm_funcregister("get_glut_cursor_left_arrow",ring_get_glut_cursor_left_arrow);
	ring_vm_funcregister("get_glut_cursor_info",ring_get_glut_cursor_info);
	ring_vm_funcregister("get_glut_cursor_destroy",ring_get_glut_cursor_destroy);
	ring_vm_funcregister("get_glut_cursor_help",ring_get_glut_cursor_help);
	ring_vm_funcregister("get_glut_cursor_cycle",ring_get_glut_cursor_cycle);
	ring_vm_funcregister("get_glut_cursor_spray",ring_get_glut_cursor_spray);
	ring_vm_funcregister("get_glut_cursor_wait",ring_get_glut_cursor_wait);
	ring_vm_funcregister("get_glut_cursor_text",ring_get_glut_cursor_text);
	ring_vm_funcregister("get_glut_cursor_crosshair",ring_get_glut_cursor_crosshair);
	ring_vm_funcregister("get_glut_cursor_up_down",ring_get_glut_cursor_up_down);
	ring_vm_funcregister("get_glut_cursor_left_right",ring_get_glut_cursor_left_right);
	ring_vm_funcregister("get_glut_cursor_top_side",ring_get_glut_cursor_top_side);
	ring_vm_funcregister("get_glut_cursor_bottom_side",ring_get_glut_cursor_bottom_side);
	ring_vm_funcregister("get_glut_cursor_left_side",ring_get_glut_cursor_left_side);
	ring_vm_funcregister("get_glut_cursor_right_side",ring_get_glut_cursor_right_side);
	ring_vm_funcregister("get_glut_cursor_top_left_corner",ring_get_glut_cursor_top_left_corner);
	ring_vm_funcregister("get_glut_cursor_top_right_corner",ring_get_glut_cursor_top_right_corner);
	ring_vm_funcregister("get_glut_cursor_bottom_right_corner",ring_get_glut_cursor_bottom_right_corner);
	ring_vm_funcregister("get_glut_cursor_bottom_left_corner",ring_get_glut_cursor_bottom_left_corner);
	ring_vm_funcregister("get_glut_cursor_inherit",ring_get_glut_cursor_inherit);
	ring_vm_funcregister("get_glut_cursor_none",ring_get_glut_cursor_none);
	ring_vm_funcregister("get_glut_cursor_full_crosshair",ring_get_glut_cursor_full_crosshair);
	ring_vm_funcregister("get_glut_red",ring_get_glut_red);
	ring_vm_funcregister("get_glut_green",ring_get_glut_green);
	ring_vm_funcregister("get_glut_blue",ring_get_glut_blue);
	ring_vm_funcregister("get_glut_key_repeat_off",ring_get_glut_key_repeat_off);
	ring_vm_funcregister("get_glut_key_repeat_on",ring_get_glut_key_repeat_on);
	ring_vm_funcregister("get_glut_key_repeat_default",ring_get_glut_key_repeat_default);
	ring_vm_funcregister("get_glut_joystick_button_a",ring_get_glut_joystick_button_a);
	ring_vm_funcregister("get_glut_joystick_button_b",ring_get_glut_joystick_button_b);
	ring_vm_funcregister("get_glut_joystick_button_c",ring_get_glut_joystick_button_c);
	ring_vm_funcregister("get_glut_joystick_button_d",ring_get_glut_joystick_button_d);
	ring_vm_funcregister("get_glut_game_mode_active",ring_get_glut_game_mode_active);
	ring_vm_funcregister("get_glut_game_mode_possible",ring_get_glut_game_mode_possible);
	ring_vm_funcregister("get_glut_game_mode_width",ring_get_glut_game_mode_width);
	ring_vm_funcregister("get_glut_game_mode_height",ring_get_glut_game_mode_height);
	ring_vm_funcregister("get_glut_game_mode_pixel_depth",ring_get_glut_game_mode_pixel_depth);
	ring_vm_funcregister("get_glut_game_mode_refresh_rate",ring_get_glut_game_mode_refresh_rate);
	ring_vm_funcregister("get_glut_game_mode_display_changed",ring_get_glut_game_mode_display_changed);
	ring_vm_funcregister("get_glut_stroke_roman",ring_get_glut_stroke_roman);
	ring_vm_funcregister("get_glut_stroke_mono_roman",ring_get_glut_stroke_mono_roman);
	ring_vm_funcregister("get_glut_bitmap_9_by_15",ring_get_glut_bitmap_9_by_15);
	ring_vm_funcregister("get_glut_bitmap_8_by_13",ring_get_glut_bitmap_8_by_13);
	ring_vm_funcregister("get_glut_bitmap_times_roman_10",ring_get_glut_bitmap_times_roman_10);
	ring_vm_funcregister("get_glut_bitmap_times_roman_24",ring_get_glut_bitmap_times_roman_24);
	ring_vm_funcregister("get_glut_bitmap_helvetica_10",ring_get_glut_bitmap_helvetica_10);
	ring_vm_funcregister("get_glut_bitmap_helvetica_12",ring_get_glut_bitmap_helvetica_12);
	ring_vm_funcregister("get_glut_bitmap_helvetica_18",ring_get_glut_bitmap_helvetica_18);
}
