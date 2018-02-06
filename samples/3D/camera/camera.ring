# Sample : Camera
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>


# Load Libraries
	load "gamelib.ring"		# RingAllegro Library
	load "opengl32lib.ring"		# RingOpenGL  Library

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

	TITLE = "Camera"

	bitmap texture font
	bitmap2 texture2

	// angle of rotation for the camera direction
		angle=0.0
	// actual vector representing the camera's direction
		lx=0.0
		lz=-1.0
	// XZ position of the camera
		x=0.0
		z=5.0

	fraction = 0.1



	func loadresources

		bitmap = al_load_bitmap("n1.jpg")
		texture = al_get_opengl_texture(bitmap)
		font = al_load_ttf_font("pirulen.ttf",54,0 )
		bitmap2 = al_load_bitmap("sky3.jpg")
		texture2 = al_get_opengl_texture(bitmap2)


	func destroyResources

		al_destroy_bitmap(bitmap)
		al_destroy_font(font)
		al_destroy_bitmap(bitmap2)


	func drawScene

		w = SCREEN_W h = SCREEN_H
		ratio =  w / h

		glViewport(0, 0, W, H)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()

		gluPerspective(15,ratio,1,50)
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()

		glEnable(GL_TEXTURE_2D)							
		glshademodel(gl_SMOOTH)

		glClearColor(0.0, 0.0, 0.0, 0.0)
		glClearDepth(1)			

		glEnable(GL_DEPTH_TEST)	

		glEnable(GL_CULL_FACE)

		glDepthFunc(GL_LEQUAL)
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
		al_clear_to_color(al_map_rgb(255,255,255))

		glLoadIdentity()									

		gluLookAt(x, 1.0, z,
                        x+lx, 1.0,  z+lz,
                        0.0, 1.0,  0.0)

		glBindTexture(GL_TEXTURE_2D, texture2)

	     	glColor4f(1, 1, 1,1)
	        glBegin(GL_QUADS)
		glTexCoord2f(0.0, 1.0)  
			glVertex3f(-100.0, 0.0, -100.0)
		glTexCoord2f(0.0, 1.0)  
			glVertex3f(-100.0, 0.0,  100.0)
		glTexCoord2f(1.0, 0.0)  
			glVertex3f( 100.0, 0.0,  100.0)
		glTexCoord2f(1.0, 0.0)  
			glVertex3f( 100.0, 0.0, -100.0)
	        glEnd()

		glBindTexture(GL_TEXTURE_2D, texture)


		 for i = -3 to 2
	                for  j=-3 to 2
	                        glPushMatrix()
	                        glTranslatef(i*10.0,0,j * 10.0)
	                        drawCube()
	                        glPopMatrix()
	                next
	        next

		glflush()

		if key[key_left]
			moveleft()
		but key[key_right]
			moveright()
		but key[key_up]
			moveup()
		but key[key_down]
			movedown()
		ok

	func moveup
			x += lx * fraction
                        z += lz * fraction

	func movedown
			x -= lx * fraction
                        z -= lz * fraction

	func moveleft 
			angle -= 0.01
                        lx = sin(angle)
                        lz = -cos(angle)

	func moveright 
			angle += 0.01
                        lx = sin(angle)
                        lz = -cos(angle)

	func drawsphere
		gl_quad_obj=gluNewQuadric();
		gluQuadricTexture(gl_quad_obj, GL_TRUE);
		gluSphere(gl_quad_obj,1.0f,4,4);

	func drawcube

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


	func drawcube2

		 //Multi-colored side - FRONT
		  glBegin(GL_POLYGON)
		
		  glColor3f( 1.0, 0.0, 0.0 )     glVertex3f(  0.5, -0.5, -0.5 )      # P1 is red
		  glColor3f( 0.0, 1.0, 0.0 )     glVertex3f(  0.5,  0.5, -0.5 )      # P2 is green
		  glColor3f( 0.0, 0.0, 1.0 )     glVertex3f( -0.5,  0.5, -0.5 )      # P3 is blue
		  glColor3f( 1.0, 0.0, 1.0 )     glVertex3f( -0.5, -0.5, -0.5 )      # P4 is purple
		
		  glEnd()
		
		  // White side - BACK
		  glBegin(GL_POLYGON)
		  glColor3f(   1.0,  1.0, 1.0 )
		  glVertex3f(  0.5, -0.5, 0.5 )
		  glVertex3f(  0.5,  0.5, 0.5 )
		  glVertex3f( -0.5,  0.5, 0.5 )
		  glVertex3f( -0.5, -0.5, 0.5 )
		  glEnd()
		
		  // Purple side - RIGHT
		  glBegin(GL_POLYGON)
		  glColor3f(  1.0,  0.0,  1.0 )
		  glVertex3f( 0.5, -0.5, -0.5 )
		  glVertex3f( 0.5,  0.5, -0.5 )
		  glVertex3f( 0.5,  0.5,  0.5 )
		  glVertex3f( 0.5, -0.5,  0.5 )
		  glEnd()
		
		  // Green side - LEFT
		  glBegin(GL_POLYGON)
		  glColor3f(   0.0,  1.0,  0.0 )
		  glVertex3f( -0.5, -0.5,  0.5 )
		  glVertex3f( -0.5,  0.5,  0.5 )
		  glVertex3f( -0.5,  0.5, -0.5 )
		  glVertex3f( -0.5, -0.5, -0.5 )
		  glEnd()
		
		  // Blue side - TOP
		  glBegin(GL_POLYGON)
		  glColor3f(   0.0,  0.0,  1.0 )
		  glVertex3f(  0.5,  0.5,  0.5 )
		  glVertex3f(  0.5,  0.5, -0.5 )
		  glVertex3f( -0.5,  0.5, -0.5 )
		  glVertex3f( -0.5,  0.5,  0.5 )
		  glEnd()
		
		  // Red side - BOTTOM
		  glBegin(GL_POLYGON)
		  glColor3f(   1.0,  0.0,  0.0 )
		  glVertex3f(  0.5, -0.5, -0.5 )
		  glVertex3f(  0.5, -0.5,  0.5 )
		  glVertex3f( -0.5, -0.5,  0.5 )
		  glVertex3f( -0.5, -0.5, -0.5 )
		  glEnd()
		

	func drawcube3

		 //Multi-colored side - FRONT
		  glBegin(GL_POLYGON)
		
		  glColor4f( 1.0, 0.0, 0.0 ,0.0 )     glVertex3f(  0.5, -0.5, -0.5 )      # P1 is red
		  glColor4f( 0.0, 1.0, 0.0 ,0.0)     glVertex3f(  0.5,  0.5, -0.5 )      # P2 is green
		  glColor4f( 0.0, 0.0, 1.0 ,0.0)     glVertex3f( -0.5,  0.5, -0.5 )      # P3 is blue
		  glColor4f( 1.0, 0.0, 1.0 ,0.0)     glVertex3f( -0.5, -0.5, -0.5 )      # P4 is purple
		
		  glEnd()
		
		  // White side - BACK
		  glBegin(GL_POLYGON)
		  glColor4f(   1.0,  1.0, 1.0 ,0.0)
		  glVertex3f(  0.5, -0.5, 0.5 )
		  glVertex3f(  0.5,  0.5, 0.5 )
		  glVertex3f( -0.5,  0.5, 0.5 )
		  glVertex3f( -0.5, -0.5, 0.5 )
		  glEnd()
		
		  // Purple side - RIGHT
		  glBegin(GL_POLYGON)
		  glColor4f(  1.0,  0.0,  1.0 ,0.0 )
		  glVertex3f( 0.5, -0.5, -0.5 )
		  glVertex3f( 0.5,  0.5, -0.5 )
		  glVertex3f( 0.5,  0.5,  0.5 )
		  glVertex3f( 0.5, -0.5,  0.5 )
		  glEnd()
		
		  // Green side - LEFT
		  glBegin(GL_POLYGON)
		  glColor4f(   0.0,  1.0,  0.0 ,0.0 )
		  glVertex3f( -0.5, -0.5,  0.5 )
		  glVertex3f( -0.5,  0.5,  0.5 )
		  glVertex3f( -0.5,  0.5, -0.5 )
		  glVertex3f( -0.5, -0.5, -0.5 )
		  glEnd()
		
		  // Blue side - TOP
		  glBegin(GL_POLYGON)
		  glColor4f(   0.0,  0.0,  1.0  ,0.0)
		  glVertex3f(  0.5,  0.5,  0.5 )
		  glVertex3f(  0.5,  0.5, -0.5 )
		  glVertex3f( -0.5,  0.5, -0.5 )
		  glVertex3f( -0.5,  0.5,  0.5 )
		  glEnd()
		
		  // Red side - BOTTOM
		  glBegin(GL_POLYGON)
		  glColor4f(   1.0,  0.0,  0.0 ,0.0 )
		  glVertex3f(  0.5, -0.5, -0.5 )
		  glVertex3f(  0.5, -0.5,  0.5 )
		  glVertex3f( -0.5, -0.5,  0.5 )
		  glVertex3f( -0.5, -0.5, -0.5 )
		  glEnd()
		

	func set2DMode
		glMatrixMode(GL_PROJECTION)
		glPopMatrix()
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()
		glDisable(GL_CULL_FACE) 


	//func glTexCoord2f a,b

class GraphicsAppBase

	display event_queue ev timeout 
	timer  redraw 	= true

	FPS 		= 120 

	SCREEN_W 	= 1280
	SCREEN_H 	= 800

	KEY_UP		= 1
	KEY_DOWN 	= 2
	KEY_LEFT 	= 3
	KEY_RIGHT 	= 4

	Key = [false,false,false,false]

	TITLE = "Graphics Application"

	func start

		SetUp()
		loadResources()
		eventsLoop()
		destroy()

	func setup

		al_init()
		al_init_image_addon()
		al_init_font_addon()
		al_init_ttf_addon()
		al_set_new_display_flags(ALLEGRO_OPENGL) 
		ALLEGRO_SUGGEST = 2
		al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 16, ALLEGRO_SUGGEST); 
		display = al_create_display(SCREEN_W,SCREEN_H)
		al_set_Window_title(display,TITLE)
		al_clear_to_color(al_map_rgb(0,0,255))
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
			callgc()
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
