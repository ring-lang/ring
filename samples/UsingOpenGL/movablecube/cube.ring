# Sample : Movable Cube
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>


# Load Libraries
	load "gamelib.ring"		# RingAllegro Library
	load "opengl21lib.ring"		# RingOpenGL  Library

#==============================================================
# To Support MacOS X
	al_run_main()	
	func al_game_start 	# Called by al_run_main()
		main()		# Now we call our main function
#==============================================================

func main

	new GraphicsApp {
		start()
	}


class GraphicsApp from GraphicsAppBase

	TITLE = "Movable Cube"

	bitmap texture font

	xrot = 0.0
	yrot = 0.0
	zrot = 0.0
	
	v1=0 v2=0 v3=-5


	func loadresources

		bitmap = al_load_bitmap("ring.bmp")
		texture = al_get_opengl_texture(bitmap)
		font = al_load_ttf_font("pirulen.ttf",54,0 )

	func destroyResources

		al_destroy_bitmap(bitmap)
		al_destroy_font(font)

	func drawScene

		w = SCREEN_W h = SCREEN_H
		ratio =  w / h

		glViewport(0, 0, W, H)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()

		gluPerspective(45,ratio,1,100)
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()

		glEnable(GL_TEXTURE_2D)							
		glShadeModel(GL_SMOOTH)							
		glClearColor(0.0, 0.0, 0.0, 0.5)
		glClearDepth(1.0)			
		glEnable(GL_DEPTH_TEST)	
		glEnable(GL_CULL_FACE)
		glDepthFunc(GL_LEQUAL)
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
		glLoadIdentity()									
		glTranslatef(v1,v2,v3)

		glRotatef(xrot,1.0,0.0,0.0)
		glRotatef(yrot,0.0,1.0,0.0)
		glRotatef(zrot,0.0,0.0,1.0)

		glBindTexture(GL_TEXTURE_2D, texture)

		glBegin(GL_QUADS)
			// Front Face
			glTexCoord2f(0.0, 0.0) glVertex3f(-1.0, -1.0,  1.0)
			glTexCoord2f(1.0, 0.0) glVertex3f( 1.0, -1.0,  1.0)
			glTexCoord2f(1.0, 1.0) glVertex3f( 1.0,  1.0,  1.0)
			glTexCoord2f(0.0, 1.0) glVertex3f(-1.0,  1.0,  1.0)
			// Back Face
			glTexCoord2f(1.0, 0.0) glVertex3f(-1.0, -1.0, -1.0)
			glTexCoord2f(1.0, 1.0) glVertex3f(-1.0,  1.0, -1.0)
			glTexCoord2f(0.0, 1.0) glVertex3f( 1.0,  1.0, -1.0)
			glTexCoord2f(0.0, 0.0) glVertex3f( 1.0, -1.0, -1.0)
			// Top Face
			glTexCoord2f(0.0, 1.0) glVertex3f(-1.0,  1.0, -1.0)
			glTexCoord2f(0.0, 0.0) glVertex3f(-1.0,  1.0,  1.0)
			glTexCoord2f(1.0, 0.0) glVertex3f( 1.0,  1.0,  1.0)
			glTexCoord2f(1.0, 1.0) glVertex3f( 1.0,  1.0, -1.0)
			// Bottom Face
			glTexCoord2f(1.0, 1.0) glVertex3f(-1.0, -1.0, -1.0)
			glTexCoord2f(0.0, 1.0) glVertex3f( 1.0, -1.0, -1.0)
			glTexCoord2f(0.0, 0.0) glVertex3f( 1.0, -1.0,  1.0)
			glTexCoord2f(1.0, 0.0) glVertex3f(-1.0, -1.0,  1.0)
			// Right face
			glTexCoord2f(1.0, 0.0) glVertex3f( 1.0, -1.0, -1.0)
			glTexCoord2f(1.0, 1.0) glVertex3f( 1.0,  1.0, -1.0)
			glTexCoord2f(0.0, 1.0) glVertex3f( 1.0,  1.0,  1.0)
			glTexCoord2f(0.0, 0.0) glVertex3f( 1.0, -1.0,  1.0)
			// Left Face
			glTexCoord2f(0.0, 0.0) glVertex3f(-1.0, -1.0, -1.0)
			glTexCoord2f(1.0, 0.0) glVertex3f(-1.0, -1.0,  1.0)
			glTexCoord2f(1.0, 1.0) glVertex3f(-1.0,  1.0,  1.0)
			glTexCoord2f(0.0, 1.0) glVertex3f(-1.0,  1.0, -1.0)
		glEnd()

		xrot += 0.3
		yrot += 0.2
		zrot += 0.4

		set2DMODE()

		al_draw_text(font,al_map_rgb(100,255,100), 100,10,
			ALLEGRO_ALIGN_LEFT,
			"Move Cube Using Arrows")

		if key[key_left]
			v1 -= 0.1
		but key[key_right]
			v1 += 0.1
		but key[key_up]
			v2 += 0.1
		but key[key_down]
			v2 -= 0.1
		ok


	func set2DMode
		glMatrixMode(GL_PROJECTION)
		glPopMatrix()
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()
		glDisable(GL_CULL_FACE) 


class GraphicsAppBase

	display event_queue ev timeout 
	timer  redraw 	= true

	FPS 		= 120 

	SCREEN_W 	= 1200
	SCREEN_H 	= 700

	KEY_UP		= 1
	KEY_DOWN 	= 2
	KEY_LEFT 	= 3
	KEY_RIGHT 	= 4

	Key = [false,false,false,false]

	TITLE = "Graphics Application"

	func start

		SetUp()
		loadResources()
		al_set_display_icon(display,bitmap) 
		eventsLoop()
		destroy()

	func setup

		al_init()
		al_init_image_addon()
		al_init_font_addon()
		al_init_ttf_addon()
		al_set_new_display_flags(ALLEGRO_OPENGL) 
		display = al_create_display(SCREEN_W,SCREEN_H)
		al_set_Window_title(display,TITLE)
		al_clear_to_color(al_map_rgb(0,0,0))
		event_queue = al_create_event_queue()
		al_register_event_source(event_queue, 
			al_get_display_event_source(display))
		ev = al_new_allegro_event()
		timeout = al_new_allegro_timeout()
		al_init_timeout(timeout, 0.06)
		timer = al_create_timer(1.0 / FPS)
		al_register_event_source(event_queue, 
			al_get_timer_event_source(timer))
		al_start_timer(timer)
		al_install_mouse()
		al_register_event_source(event_queue, 
			al_get_mouse_event_source())
		al_install_keyboard()
		al_register_event_source(event_queue, 
			al_get_keyboard_event_source())

	func eventsLoop

		while true
			al_init_timeout(timeout, 0.06)
			al_wait_for_event_until(event_queue, ev, timeout)
			switch al_get_allegro_event_type(ev)
			on ALLEGRO_EVENT_DISPLAY_CLOSE
				exit
			on ALLEGRO_EVENT_TIMER
				redraw = true
			on ALLEGRO_EVENT_MOUSE_AXES
				mouse_x = al_get_allegro_event_mouse_x(ev)
				mouse_y = al_get_allegro_event_mouse_y(ev)
			on ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY
				mouse_x = al_get_allegro_event_mouse_x(ev)
				mouse_y = al_get_allegro_event_mouse_y(ev)
			on ALLEGRO_EVENT_MOUSE_BUTTON_UP
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
				drawScene()
				al_flip_display()
			ok
		end

	func destroy

		destroyResources()
		al_destroy_timer(timer)
		al_destroy_allegro_event(ev)
		al_destroy_allegro_timeout(timeout)
		al_destroy_event_queue(event_queue)
		al_destroy_display(display)
		al_exit()

	func loadresources

	func drawScene

	func destroyResources
