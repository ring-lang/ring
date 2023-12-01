# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

load "gamelib.ring"

GL_LIBNAME = :Allegro

# Keyboard
GL_SPACE = 75 
GL_ESC = 59 
GL_KEY_RIGHT = ALLEGRO_KEY_RIGHT 
GL_KEY_LEFT = ALLEGRO_KEY_LEFT 
GL_KEY_UP = ALLEGRO_KEY_UP 
GL_KEY_DOWN = ALLEGRO_KEY_DOWN 

# Display
GL_FULLSCREEN = ALLEGRO_FULLSCREEN

# Events
GL_EVENT_DISPLAY_CLOSE = ALLEGRO_EVENT_DISPLAY_CLOSE 
GL_EVENT_TIMER = ALLEGRO_EVENT_TIMER 
GL_EVENT_MOUSE_AXES = ALLEGRO_EVENT_MOUSE_AXES 
GL_EVENT_MOUSE_ENTER_DISPLAY = ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY 
GL_EVENT_MOUSE_BUTTON_DOWN = ALLEGRO_EVENT_MOUSE_BUTTON_DOWN
GL_EVENT_MOUSE_BUTTON_UP = ALLEGRO_EVENT_MOUSE_BUTTON_UP 
GL_EVENT_KEY_DOWN = ALLEGRO_EVENT_KEY_DOWN 
GL_EVENT_KEY_UP = ALLEGRO_EVENT_KEY_UP 

# Text
GL_ALIGN_LEFT = ALLEGRO_ALIGN_LEFT

# Sound
GL_PLAYMODE_ONCE = ALLEGRO_PLAYMODE_ONCE
GL_PLAYMODE_LOOP = ALLEGRO_PLAYMODE_LOOP

# Finger
GL_EVENT_FINGER_DOWN = -1
GL_EVENT_FINGER_UP = -1
GL_EVENT_FINGER_MOTION = -1

# Internal
GL_SYS_EventsQueue = NULL
GL_SYS_Event = NULL

# ANDROID 
GL_AC_BACK = -1 


func gl_start_playing
	al_run_main()

func al_game_start 
	gl_game_start()
    	main()

func gl_game_start
	al_init()
	al_init_font_addon()
	al_init_ttf_addon()
	al_init_image_addon()
	al_install_audio()
	al_init_acodec_addon()
	al_reserve_samples(8)
	al_init_primitives_addon()

	# colors
	GE_COLOR_WHITE = al_map_rgb(255,255,255)
	GE_COLOR_RED = al_map_rgb(255,0,0)
	GE_COLOR_GREEN = al_map_rgb(0,255,0)
	GE_COLOR_BLUE = al_map_rgb(0,0,255)
	GE_COLOR_BLACK = al_map_rgb(0,0,0)

func gl_load_bitmap cFileName
	return al_load_bitmap(cFileName)

func gl_destroy_bitmap pObject
	return al_destroy_bitmap(pObject)

func gl_load_ttf_font cfilename,nSize,p3
	return al_load_ttf_font(cfilename,nSize,p3)

func gl_destroy_font pObject
	al_destroy_font(pObject)

func gl_set_window_title display,title
	al_set_window_title(display,title)

func gl_set_window_icon display,icon
	al_set_display_icon(display,icon)

func gl_create_display screen_w,screen_h
	return al_create_display(screen_w,screen_h)

func gl_set_new_display_flags nFlags
	al_set_new_display_flags(nFlags)

func gl_events display,event_queue,ev,timer,timeout
	al_register_event_source(event_queue, al_get_display_event_source(display))
	al_init_timeout(timeout, 0.06)
	al_register_event_source(event_queue, al_get_timer_event_source(timer))
	al_start_timer(timer)
	al_install_mouse()
	al_register_event_source(event_queue, al_get_mouse_event_source())
	al_install_keyboard()
	al_register_event_source(event_queue, al_get_keyboard_event_source())
	al_install_joystick()
	if al_is_joystick_installed()
		al_register_event_source(event_queue,
		al_get_joystick_event_source())
	ok
	GL_SYS_EventsQueue = event_queue
	GL_SYS_Event = ev

func gl_init_timeout oTimeout,nValue 
	al_init_timeout(oTimeout, nValue)

func gl_new_glib_event
	return al_new_allegro_event()

func gl_new_glib_timeout
	return al_new_allegro_timeout()

func gl_create_event_queue
	return al_create_event_queue()

func gl_create_timer nCount
	return al_create_timer(nCount)

func gl_wait_for_event_until event_queue, ev, timeout
	al_wait_for_event_until(event_queue, ev, timeout)

func gl_get_glib_event_type ev
	return al_get_allegro_event_type(ev)

func gl_get_glib_event_keyboard_keycode ev
	return al_get_allegro_event_keyboard_keycode(ev)

func gl_is_event_queue_empty event_queue
	return al_is_event_queue_empty(event_queue)

func gl_clear_to_color nColor
	al_clear_to_color(nColor)

func gl_flip_display
	al_flip_display()

func gl_exit
	al_exit()

func gl_destroy display,event_queue,timeout,ev,timer
	al_destroy_timer(timer)
	al_destroy_allegro_event(ev)
	al_destroy_allegro_timeout(timeout)
	al_destroy_event_queue(event_queue)	
	al_destroy_display(display)

func gl_map_rgb r,g,b
	return al_map_rgb(r,g,b)

func gl_convert_mask_to_alpha image,transparentcolor
	al_convert_mask_to_alpha(image,transparentcolor)

func gl_draw_bitmap image,x,y,nvalue
	al_draw_bitmap(image,x,y,nvalue)

func gl_get_bitmap_height image
	return al_get_bitmap_height(image)

func gl_get_bitmap_width image
	return al_get_bitmap_width(image)

func gl_draw_scaled_bitmap p1,p2,p3,p4,p5,p6,p7,p8,p9,p10
	al_draw_scaled_bitmap(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)

func gl_draw_text font,color,x,y,nAlign,text
	al_draw_text(font,color,x,y,nAlign,text)

func gl_draw_bitmap_region p1,p2,p3,p4,p5,p6,p7,p8
	al_draw_bitmap_region(p1,p2,p3,p4,p5,p6,p7,p8)

func gl_load_sample cfilename
	return al_load_sample(cfilename)

func gl_get_backbuffer display
	return al_get_backbuffer(display)

func gl_set_target_bitmap oBitmap
	al_set_target_bitmap(oBitmap)

func gl_new_glib_sample_id
	return al_new_allegro_sample_id()

func gl_play_sample p1,p2,p3,p4,p5,p6	
	al_play_sample(p1,p2,p3,p4,p5,p6)	

func gl_destroy_glib_sample_id sampleid
	al_destroy_allegro_sample_id(sampleid)

func gl_destroy_sample sample
	al_destroy_sample(sample)	

func gl_mouse_x 
	return al_get_allegro_event_mouse_x(GL_SYS_Event)

func gl_mouse_y 
	return  al_get_allegro_event_mouse_y(GL_SYS_Event)

func gl_draw_filled_rectangle(x1, y1,x2, y2, color)
	al_draw_filled_rectangle(x1,y1,x2,y2,color)

func gl_draw_line(x1,y1,x2,y2,color,thickness)
	al_draw_line(x1,y1,x2,y2,color,thickness)

func gl_draw_circle cx,cy,r,color,thickness
	al_draw_circle(cx,cy,r,color,thickness)

func gl_draw_filled_circle cx, cy, r, color
	al_draw_filled_circle(cx, cy, r, color)

func gl_draw_rectangle x1,y1,x2,y2,color,thickness 
	al_draw_rectangle(x1,y1,x2,y2,color,thickness)

func gl_draw_ellipse cx, cy, rx, ry,color, thickness
	al_draw_ellipse(cx, cy, rx, ry,color, thickness)

func gl_draw_arc cx,cy,r,start_theta,delta_theta,color,thickness
	al_draw_arc(cx,cy,r,start_theta,delta_theta,color,thickness)

func gl_draw_rounded_rectangle x1,y1,x2,y2,rx,ry,color,thickness
	al_draw_rounded_rectangle(x1,y1,x2,y2,rx,ry,color,thickness)

func gl_draw_filled_rounded_rectangle x1,y1,x2,y2,rx,ry,color
	al_draw_filled_rounded_rectangle(x1,y1,x2,y2,rx,ry,color)

func gl_draw_triangle x1,y1,x2,y2,x3,y3,color,thickness
	al_draw_triangle(x1,y1,x2,y2,x3,y3,color,thickness)

func gl_draw_filled_triangle x1, y1, x2, y2,x3,y3,color
	al_draw_filled_triangle(x1, y1, x2, y2,x3,y3,color)

func gl_draw_point x,y,color
	al_draw_pixel(x,y,color)

func gl_errormsg cMessage 
	al_show_native_message_box(NULL,"Game","Error",cMessage,NULL,ALLEGRO_MESSAGEBOX_ERROR)

func gl_delay x
	al_rest(x/1000)
