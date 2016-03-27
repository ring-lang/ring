Load "gamelib.ring"

al_init()
al_init_image_addon()

display = al_create_display(640,480)

al_show_native_message_box(display, "Hello", "Welcome", "Using Allegro from the Ring programming language", 
                                 "", 0);

al_clear_to_color(al_map_rgb(0,0,255))

BOUNCER_SIZE = 40
bouncer_x = 10
bouncer_y = 20
bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE)
al_set_target_bitmap(bouncer)
al_clear_to_color(al_map_rgb(255,0,255))

for x = 1 to 30
	bouncer_x += x 
	bouncer_y += x
	al_set_target_bitmap(al_get_backbuffer(display))
	al_clear_to_color(al_map_rgb(0,0,0))
	al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0)
	al_draw_bitmap(bouncer, 200+bouncer_x,200+ bouncer_y, 0)
	al_flip_display()
	al_rest(0.1)
next

al_clear_to_color(al_map_rgb(255,255,255))
image = al_load_bitmap("man2.jpg")
al_draw_bitmap(image,200,200,0)
al_flip_display()
al_rest(2)

event_queue = al_create_event_queue()
al_register_event_source(event_queue, al_get_display_event_source(display))

ev = al_new_allegro_event()
timeout = al_new_allegro_timeout()
al_init_timeout(timeout, 0.06)

FPS = 60
timer = al_create_timer(1.0 / FPS)
al_register_event_source(event_queue, al_get_timer_event_source(timer))
al_start_timer(timer)
redraw = true

SCREEN_W = 640
SCREEN_H = 480
BOUNCER_SIZE = 32
bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0
bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0
bouncer_dx = -4.0
bouncer_dy = 4.0

al_install_mouse()
al_register_event_source(event_queue, al_get_mouse_event_source())

al_install_keyboard()
al_register_event_source(event_queue, al_get_keyboard_event_source())

KEY_UP = 1
KEY_DOWN = 2
KEY_LEFT = 3
KEY_RIGHT = 4
Key = [false,false,false,false]

while true
	al_wait_for_event_until(event_queue, ev, timeout)
	switch al_get_allegro_event_type(ev)
	on ALLEGRO_EVENT_DISPLAY_CLOSE
		exit
	on ALLEGRO_EVENT_TIMER
		# Animation
		if bouncer_x < 0 or bouncer_x > SCREEN_W - BOUNCER_SIZE
	            	bouncer_dx = -bouncer_dx
         	ok
 
         	if bouncer_y < 0 or bouncer_y > SCREEN_H - BOUNCER_SIZE
	            bouncer_dy = -bouncer_dy
        	ok
 
 	        bouncer_x += bouncer_dx
         	bouncer_y += bouncer_dy
		# Keyboard
		if key[KEY_UP] and bouncer_y >= 4.0
	            bouncer_y -= 4.0
        	ok 
 	        if key[KEY_DOWN] and bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0
        	    bouncer_y += 4.0
         	ok 
 	        if key[KEY_LEFT] and bouncer_x >= 4.0
        	    bouncer_x -= 4.0
         	ok 
 	        if key[KEY_RIGHT] and bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0
        	    bouncer_x += 4.0
         	ok
 
 	        redraw = true
	on ALLEGRO_EVENT_MOUSE_AXES
		bouncer_x = al_get_allegro_event_mouse_x(ev)
		bouncer_y = al_get_allegro_event_mouse_y(ev)
	on ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY
		bouncer_x = al_get_allegro_event_mouse_x(ev)
		bouncer_y = al_get_allegro_event_mouse_y(ev)
	on ALLEGRO_EVENT_MOUSE_BUTTON_UP
		exit
	on ALLEGRO_EVENT_KEY_DOWN
		switch al_get_allegro_event_keyboard_keycode(ev)
			on ALLEGRO_KEY_UP
		               key[KEY_UP] = true
	   	        on ALLEGRO_KEY_DOWN
		               key[KEY_DOWN] = true
	            	on ALLEGRO_KEY_LEFT
		               key[KEY_LEFT] = true
            		on ALLEGRO_KEY_RIGHT
		               key[KEY_RIGHT] = true
		off
	on ALLEGRO_EVENT_KEY_UP
		switch al_get_allegro_event_keyboard_keycode(ev)
			on ALLEGRO_KEY_UP
		               key[KEY_UP] = false
	   	        on ALLEGRO_KEY_DOWN
		               key[KEY_DOWN] = false
	            	on ALLEGRO_KEY_LEFT
		               key[KEY_LEFT] = false
            		on ALLEGRO_KEY_RIGHT
		               key[KEY_RIGHT] = false
			on ALLEGRO_KEY_ESCAPE
				exit
		off
	off
	if redraw and al_is_event_queue_empty(event_queue)
		redraw = false		
		al_clear_to_color(al_map_rgb(0,0,0))
		al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0)
		al_flip_display()
	ok
	callgc()
end

al_destroy_timer(timer)
al_destroy_allegro_event(ev)
al_destroy_allegro_timeout(timeout)
al_destroy_event_queue(event_queue)
al_destroy_bitmap(bouncer)
al_destroy_bitmap(image)
al_destroy_display(display)	

al_exit()
