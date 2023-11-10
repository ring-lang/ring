# Sample : Many Cubes
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

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

	TITLE = "Many Cubes"

	bitmap bitmap2 bitmap3
    texture texture2 texture3

	fps = 120
	xrot = 0.0
	yrot = 0.0
	zrot = 0.0

	nPerspective = 100

	func loadresources

		bitmap = al_load_bitmap("sky1.jpg")
		texture = al_get_opengl_texture(bitmap)

		bitmap2 = al_load_bitmap("sky2.jpg")
		texture2 = al_get_opengl_texture(bitmap2)

		bitmap3 = al_load_bitmap("sky3.jpg")
		texture3 = al_get_opengl_texture(bitmap3)

	func destroyResources

		al_destroy_bitmap(bitmap)
		al_destroy_bitmap(bitmap2)
		al_destroy_bitmap(bitmap3)

	func drawScene

		prepare()
		cubes()
		rotate()

	func Prepare
		w = 800 h = 600
		ratio =  w / h
		glViewport(0, 0, w, h)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
		gluPerspective(-nPerspective,ratio,1,nPerspective)
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

	func Cubes
		cube(5,-3.4,-5,:sky1)
		cube(0,-3,-5,:sky1)
		cube(-5,-3,-5,:sky1)
		cube(5,0.5,-5,:sky2)
		cube(0,0.5,-5,:sky2)
		cube(-5,0.5,-5,:sky2)
		cube(5,4,-5,:sky3)
		cube(0,4,-5,:sky3)
		cube(-5,4,-5,:sky3)

	func Rotate 
		xrot += 0.3 * 5
		yrot += 0.2 * 5
		zrot += 0.4 * 5
		nPerspective += 0.5


	func cube(x,y,z,nTexture)
		glLoadIdentity()									
		glTranslatef(x,y,z)
		glRotatef(xrot,1.0,0.0,0.0)
		glRotatef(yrot,0.0,1.0,0.0)
		glRotatef(zrot,0.0,0.0,1.0)
		drawcube(nTexture)

	func drawcube(cTexture) 

		switch cTexture
			on :sky1
				glBindTexture(GL_TEXTURE_2D, texture)
			on :sky2
				glBindTexture(GL_TEXTURE_2D, texture2)
			on :sky3
				glBindTexture(GL_TEXTURE_2D, texture3)
		off


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


class GraphicsAppBase

	display event_queue ev timeout 
	timer  redraw 	= true

	FPS 		= 60 

	SCREEN_W 	= 800
	SCREEN_H 	= 600

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
