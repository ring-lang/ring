Load "gamelib.ring"

al_init()

display = al_create_display(640,480)

BOUNCER_SIZE = 40
bouncer_x = 10
bouncer_y = 20
bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE)
al_set_target_bitmap(bouncer)
al_clear_to_color(al_map_rgb(255,0,255))

al_set_target_bitmap(al_get_backbuffer(display))

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

while true
	al_wait_for_event_until(event_queue, ev, timeout)
	switch al_get_allegro_event_type(ev)
	on ALLEGRO_EVENT_DISPLAY_CLOSE
		exit
	on ALLEGRO_EVENT_MOUSE_AXES
		bouncer_x = al_get_allegro_event_mouse_x(ev)
		bouncer_y = al_get_allegro_event_mouse_y(ev)
		redraw = true
	on ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY
		bouncer_x = al_get_allegro_event_mouse_x(ev)
		bouncer_y = al_get_allegro_event_mouse_y(ev)
		redraw = true
	on ALLEGRO_EVENT_MOUSE_BUTTON_UP
		exit
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
al_destroy_display(display)	

al_exit()
