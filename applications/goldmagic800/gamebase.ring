# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameBase

	display event_queue ev timeout timer  redraw = true   lFlipDisplay = True 
	lExitFromMainLoop = False

	nFPS = 14 	nRuntimeFPS = nFPS	lCalculateRunTimeFPS = False

	lUseFixedResolution = False
	lFULLSCREEN	= True
	lWindowSize	= 2

	if lFULLSCREEN 
		SCREEN_W 	= 1920
		SCREEN_H 	= 1080
		lGraphicsMode	= ALLEGRO_FULLSCREEN_WINDOW
	else
		Switch lWindowSize 
		on 1
			SCREEN_W = 1280
			SCREEN_H = 1024
		on 2
			SCREEN_W = 1680	
			SCREEN_H = 1050	
		off
		lGraphicsMode	 = ALLEGRO_WINDOWED
	ok

	lClearScreen = True

	bitmapScreen2D
	SCREEN_W_2D	= 1920 
	SCREEN_H_2D	= 1080

	KEY_UP		= 1
	KEY_DOWN 	= 2
	KEY_LEFT 	= 3
	KEY_RIGHT 	= 4
	KEY_SPACE	= 5
	KEY_ESCAPE	= 6
	KEY_ENTER	= 7

	Key 		= [false,false,false,false,false,false,false]

	Mouse_X = 0	Mouse_Y = 0 	Mouse_Button_Down = False
	lMouseMove = False	Last_Mouse_X = 0	Last_Mouse_Y = 0

	lUseJoyStick = True

	COLOR_WHITE 
	COLOR_BLACK
	COLOR_GRAY
	COLOR_ACTIVE
	COLOR_NOTACTIVE
	COLOR_DISABLED

	TITLE = ""

	func Run

		SetUp()
		loadResources()
		Start()
		eventsLoop()
		destroy()


	func Setup

		al_init()
		al_init_image_addon()
		al_init_font_addon()
		al_init_ttf_addon()
		al_install_audio()
		al_init_acodec_addon()
		al_reserve_samples(8)		

		COLOR_WHITE = al_map_rgb(255,255,255)
		COLOR_BLACK = al_map_rgb(0,0,0)
		COLOR_GRAY  = al_map_rgb(128,128,128)
		COLOR_ACTIVE = al_map_rgb(150,255,150)
		COLOR_NOTACTIVE = al_map_rgb(200,200,200)
		COLOR_DISABLED = al_map_rgb(160,160,160)

		al_set_new_display_flags(ALLEGRO_OPENGL | lGraphicsMode)

		ALLEGRO_SUGGEST = 2
		al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 24, ALLEGRO_SUGGEST); 
		
		display = al_create_display(SCREEN_W,SCREEN_H)
		CheckFatalError(display,"Can't create the Game Window!")

		if not lUseFixedResolution
			SCREEN_W = al_get_display_width(display)
			SCREEN_H = al_get_display_height(display)
		ok

		al_set_Window_title(display,TITLE)
		if lClearScreen
			al_clear_to_color(al_map_rgb(0,0,0))
		ok

		event_queue = al_create_event_queue()
		al_register_event_source(event_queue, 
			al_get_display_event_source(display))
		ev = al_new_allegro_event()
		timeout = al_new_allegro_timeout()
		al_init_timeout(timeout, 0.06)
		timer = al_create_timer(1.0 / nFPS)
		al_register_event_source(event_queue, 
			al_get_timer_event_source(timer))
		al_start_timer(timer)
		al_install_mouse()
		al_register_event_source(event_queue, 
			al_get_mouse_event_source())
		al_install_keyboard()
		al_register_event_source(event_queue, 
			al_get_keyboard_event_source())

		if lUseJoyStick
			al_install_joystick()
			if al_is_joystick_installed()
				al_register_event_source(event_queue,
					al_get_joystick_event_source())
			else 
				lUseJoyStick = False
			ok
		ok

	func EventsLoop

		if lCalculateRunTimeFPS 
			t1 = clock()
			nFrames = 0
		ok
		while true
			al_init_timeout(timeout, 0.06)
			al_wait_for_event_until(event_queue, ev, timeout)
			nEventType = al_get_allegro_event_type(ev)
			switch nEventType
			on ALLEGRO_EVENT_DISPLAY_CLOSE
				exit
			on ALLEGRO_EVENT_TIMER
				redraw = true
			on ALLEGRO_EVENT_MOUSE_AXES
				last_mouse_x = mouse_x
				last_mouse_y = mouse_y
				mouse_x = al_get_allegro_event_mouse_x(ev)
				mouse_y = al_get_allegro_event_mouse_y(ev)
				if mouse_x != Last_Mouse_X  or mouse_y != Last_Mouse_y
					lMouseMove = True 
				ok
			on ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY
			on ALLEGRO_EVENT_MOUSE_BUTTON_DOWN
				Mouse_Button_Down = True
			on ALLEGRO_EVENT_MOUSE_BUTTON_UP
				Mouse_Button_Down = False
			on ALLEGRO_EVENT_KEY_DOWN
				switch al_get_allegro_event_keyboard_keycode(ev)
					on ALLEGRO_KEY_UP
						key[KEY_UP] 	= 2 | 1
					on ALLEGRO_KEY_DOWN
						key[KEY_DOWN] 	= 2 | 1
					on ALLEGRO_KEY_LEFT
						key[KEY_LEFT] 	= 2 | 1
					on ALLEGRO_KEY_RIGHT
						key[KEY_RIGHT] 	= 2 | 1
					on ALLEGRO_KEY_W
						key[KEY_UP] 	= 2 | 1
					on ALLEGRO_KEY_S
						key[KEY_DOWN] 	= 2 | 1
					on ALLEGRO_KEY_A
						key[KEY_LEFT] 	= 2 | 1
					on ALLEGRO_KEY_D
						key[KEY_RIGHT] 	= 2 | 1

				off
			on ALLEGRO_EVENT_KEY_UP
				switch al_get_allegro_event_keyboard_keycode(ev)
					on ALLEGRO_KEY_UP
						key[KEY_UP] 	&= 2
					on ALLEGRO_KEY_DOWN
						key[KEY_DOWN] 	&= 2
					on ALLEGRO_KEY_LEFT
						key[KEY_LEFT] 	&= 2
					on ALLEGRO_KEY_RIGHT
						key[KEY_RIGHT] 	&= 2
					on ALLEGRO_KEY_W
						key[KEY_UP] 	&= 2
					on ALLEGRO_KEY_S
						key[KEY_DOWN] 	&= 2
					on ALLEGRO_KEY_A
						key[KEY_LEFT] 	&= 2
					on ALLEGRO_KEY_D
						key[KEY_RIGHT] 	&= 2
					on ALLEGRO_KEY_SPACE
						key[KEY_SPACE] = true
					on ALLEGRO_KEY_ESCAPE
						key[KEY_ESCAPE] = true
					on ALLEGRO_KEY_ENTER
						key[KEY_ENTER] = true
				off
			off
			if lUseJoyStick
				Switch nEventType
				on ALLEGRO_EVENT_JOYSTICK_AXIS
					# Right (Axis = 0 , Pos = 1)
					# Left  (Axis = 0 , Pos = -1)
					# Up    (Axis = 1 , Pos = -1)
					# Down  (Axis = 1 , Pos = 1)
					nAxis = al_get_allegro_event_joystick_axis(ev)
					nPos  = al_get_allegro_event_joystick_pos(ev)
					if nAxis = 0
						if nPos = 1	# Right
							Key[KEY_RIGHT] 	= 2 | 1
						but nPos = -1	# Left
							Key[KEY_LEFT] 	= 2 | 1
						but nPos = 0
							Key[KEY_LEFT] 	&= 2
							Key[KEY_Right] 	&= 2
						ok
					but nAxis = 1 
						if nPos = 1	# Down
							Key[KEY_DOWN] 	= 2 | 1
						but nPos = -1	# Up
							Key[KEY_UP] 	= 2 | 1
						but nPos = 0
							Key[KEY_UP] 	&= 2
							Key[KEY_DOWN] 	&= 2
						ok
					ok
				on ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN
					nJoyStickButton = al_get_allegro_event_joystick_button(ev)
					switch nJoyStickButton
					on 1 
						Key[KEY_ENTER] = True
					on 2
						Key[KEY_SPACE] = True
					on 3
						Key[KEY_ESCAPE]	= True
					off
				on ALLEGRO_EVENT_JOYSTICK_BUTTON_UP
					nJoyStickButton = al_get_allegro_event_joystick_button(ev)
					switch nJoyStickButton
					on 1 
						Key[KEY_ENTER] 	= False
					on 2
						Key[KEY_SPACE] 	= False
					on 3
						Key[KEY_ESCAPE]	= False
					off
				off
			ok
			if redraw and al_is_event_queue_empty(event_queue)
				FrameOperations()
			ok
		end

	func AfterProcessingKeys

		key[KEY_UP] 	&= 1
		key[KEY_DOWN] 	&= 1
		key[KEY_LEFT] 	&= 1
		key[KEY_RIGHT] 	&= 1

	func FrameOperations

		if lClearScreen
			al_clear_to_color(al_map_rgb(0,0,0))
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
			glLoadIdentity()
		ok
		redraw = false
		lFlipDisplay = True 
		PlaySound()
		Update()
		AfterProcessingKeys()
		if lExitFromMainLoop = True
			exit 
		ok
		if lFlipDisplay
			al_flip_display()
		ok
		if lCalculateRunTimeFPS 
			nFrames++
			if (clock()-t1)/clockspersecond() > 1
				nRuntimeFPS = nFrames
				t1 = clock()	
				nFrames = 0
			ok
		ok

	func Destroy

		destroyResources()
		al_destroy_timer(timer)
		al_destroy_allegro_event(ev)
		al_destroy_allegro_timeout(timeout)
		al_destroy_event_queue(event_queue)
		al_destroy_display(display)
		al_exit()

	func set2DMode

		glMatrixMode(GL_PROJECTION)
		glPopMatrix()
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()
		glDisable(GL_CULL_FACE) 

	func Start2DScreen

		if IsNULL(bitmapScreen2D)
			bitmapScreen2D = al_create_bitmap(SCREEN_W_2D,SCREEN_H_2D)			
			CheckFatalError(bitmapScreen2D,"Can't create the Screen Buffer : " + 
					SCREEN_W_2D + " x " + SCREEN_H_2D )
		ok
		if SCREEN_W_2D != SCREEN_W or
		   SCREEN_H_2D != SCREEN_H
			al_set_target_bitmap(bitmapScreen2D)
		ok

	func End2DScreen

		if SCREEN_W_2D != SCREEN_W or
		   SCREEN_H_2D != SCREEN_H
			al_set_target_bitmap(al_get_backbuffer(display))
			al_draw_scaled_bitmap(bitmapScreen2D,0,0,SCREEN_W_2D,SCREEN_H_2D,
				0,0,SCREEN_W,SCREEN_H,0)
		ok

	func Position2D_Y Y
		return Y*(SCREEN_H/SCREEN_H_2D)

	func Position2D_X X
		return X*(SCREEN_W/SCREEN_W_2D)

	func ExitFromMainLoop

		lExitFromMainLoop = True

	func LoadResources
		# The code will be added in the Child Class 

	func DrawScene
		# The code will be added in the Child Class 

	func PlaySound
		# The code will be added in the Child Class 

	func BeforeEventsLoop
		# The code will be added in the Child Class 

	func DestroyResources

		al_destroy_bitmap(bitmapScreen2D)

