
#======================
# Camera and background
#======================

# Author : Azzeddine Remmal


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

	TITLE = "Camera and Background Sample"

	bitmap1 texture1 bitmap2 texture2 font 
	bitmap3 texture3  bitmap4 texture4  bitmap5 texture5 

	// angle of rotation for the camera direction
		angle=0.0
	// actual vector representing the camera's direction
		lx=0.0
		lz=-1.0
	// XZ position of the camera
		x=0.0
		z=5.0
		xrot = 0.0
       		yrot = 0.0
       		zrot = 0.0
	
	fraction = 0.1
	
	SetCamera()

	func SetCamera

		angle = 0.5
		lx = sin(angle)
		lz = -cos(angle)

	func loadresources

		bitmap1 = al_load_bitmap("wala.jpg")
		texture1= al_get_opengl_texture(bitmap1)
		bitmap2 = al_load_bitmap("skybox_nz.jpg")
		texture2= al_get_opengl_texture(bitmap2)
		bitmap3 = al_load_bitmap("skybox_px.jpg")
		texture3= al_get_opengl_texture(bitmap3)
		bitmap4 = al_load_bitmap("skybox_pz.jpg")
		texture4= al_get_opengl_texture(bitmap4)
		bitmap5 = al_load_bitmap("skybox_nx.jpg")
		texture5= al_get_opengl_texture(bitmap5)
		font = al_load_ttf_font("pirulen.ttf",54,0 )
		
	func destroyResources

                al_destroy_bitmap(bitmap1)
		al_destroy_bitmap(bitmap2)
		al_destroy_bitmap(bitmap3)
		al_destroy_bitmap(bitmap4)
		al_destroy_bitmap(bitmap5)
		
		al_destroy_font(font)

	func drawScene

		w = SCREEN_W h = SCREEN_H
		ratio =  w / h

		glViewport(0, 0, W, H)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()

		gluPerspective(45,ratio,1.0,100)
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

		glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT)
		al_clear_to_color(al_map_rgb(180,230,255))
		
		glLoadIdentity()									
	
		gluLookAt(x, 1.0, z,
                        x+lx, 1.0,  z+lz,
                        0.0, 1.0,  0.0)
		 
          # Draw BackGround

		// Face BackGround
		glBindTexture(GL_TEXTURE_2D, texture3)
		
		glPushMatrix()
			glTranslatef(1.0,1.5,-99.0)
			glBegin(GL_QUADS)	
				glTexCoord2f(0.0, 0.0) glVertex3f(-50.0, -50.0, 50.0)
				glTexCoord2f(1.0, 0.0) glVertex3f( 50.0, -50.0,  50.0)
				glTexCoord2f(1.0, 1.0) glVertex3f( 50.0,  50.0,  50.0)
				glTexCoord2f(0.0, 1.0) glVertex3f(-50.0,  50.0,  50.0)
			glEnd()
	        glPopMatrix()

		// Back BackGround
		glBindTexture(GL_TEXTURE_2D, texture5)
		glPushMatrix()
			glTranslatef(1.0,1.5, 99.0)
			glBegin(GL_QUADS)	
				glTexCoord2f(1.0, 0.0) glVertex3f(-50.0, -50.0, -50.0)
				glTexCoord2f(1.0, 1.0) glVertex3f(-50.0,  50.0, -50.0)
				glTexCoord2f(0.0, 1.0) glVertex3f( 50.0,  50.0, -50.0)
				glTexCoord2f(0.0, 0.0) glVertex3f( 50.0, -50.0, -50.0)
			glEnd()
	        glPopMatrix()

		// Right BackGround
		glBindTexture(GL_TEXTURE_2D, texture4)
		glPushMatrix()
			glTranslatef(-99.0,1.5,1.0)
				glBegin(GL_QUADS)	
					glTexCoord2f(1.0, 0.0) glVertex3f( 50.0, -50.0, -50.0)
					glTexCoord2f(1.0, 1.0) glVertex3f( 50.0,  50.0, -50.0)
					glTexCoord2f(0.0, 1.0) glVertex3f( 50.0,  50.0,  50.0)
					glTexCoord2f(0.0, 0.0) glVertex3f( 50.0, -50.0,  50.0)
				glEnd()
	        glPopMatrix()

		// Left BackGround
		glBindTexture(GL_TEXTURE_2D, texture2)
		glPushMatrix()
			glTranslatef(99.0,1.5,1.0)
			glBegin(GL_QUADS)	
				glTexCoord2f(0.0, 0.0) glVertex3f(-50.0, -50.0, -50.0)
				glTexCoord2f(1.0, 0.0) glVertex3f(-50.0, -50.0,  50.0)
				glTexCoord2f(1.0, 1.0) glVertex3f(-50.0,  50.0,  50.0)
				glTexCoord2f(0.0, 1.0) glVertex3f(-50.0,  50.0, -50.0)
			glEnd()
	        glPopMatrix()

		# Draw Cubes   
	
		glBindTexture(GL_TEXTURE_2D, texture1)
		 for c= -1 to 1
			 for i = -1 to 2
		                for  j= -1 to 2
		                        glPushMatrix()
		                        glTranslatef(i*20.0,c*10,j *20.0)
		                        drawCube()
		                        glPopMatrix()
		                next
		        next
		next
		glflush()

		# Respond to Keyboard

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

	func drawcube
		glTranslatef(0.0,0.2,-5.0)

                glRotatef(xrot,0.0,1.0,0.0)
                glRotatef(yrot,0.0,1.0,0.0)
                glRotatef(zrot,0.0,1.0,0.0)
              
		glBegin(GL_QUADS)
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

		xrot += 0.01
                yrot += 0.01
                zrot +=0.01 

class GraphicsAppBase

	display event_queue ev timeout  
	timer  redraw 	= true
	bitmap3 	= 0
	FPS 		= 120 

	SCREEN_W 	= 1200
	SCREEN_H 	= 700

	KEY_UP		= 1
	KEY_DOWN 	= 2
	KEY_LEFT 	= 3
	KEY_RIGHT 	= 4

	Key 	= [false,false,false,false]

	TITLE 	= "Graphics Application"

	func start

		SetUp()
		loadResources()
		al_set_display_icon(display,bitmap1) 
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
