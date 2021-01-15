class game from gamebase

	display event_queue ev timeout timer nTimeOut = 0.06
	fps = 60 	redraw = true
	FixedFPS = fps
	gClock = 0
	nid = 0
	key = [false,false,false,false,false]
	nkeycode=0

	aobjects = []
	lbraceend = true
	shutdown = false

	width = screen_w
	height = screen_h

	nBracesCount = 0

	# objects
	sprite text progress animate sound map object

	startup()

	func refresh
		deleteobjs()
		aobjects = []
		lbraceend = true
		shutdown = false

	func settitle cTitle
		title = cTitle
		gl_set_window_title(display,title)

	func seticon cIcon
		icon = cIcon
		gl_set_window_icon(display,oResources.LoadImage(icon))

	func bracestart
		nBracesCount++

	func braceend
		nBracesCount--
		# we check to call start() one time during the program life time
		if lbraceend = true and nBracesCount  = 0
			lbraceend = false
			start()
		ok

	func addobj oobject
		nid++
		oobject.nindex = nid
		add(aobjects , oobject)
	
	func remove nindex
		for x = 1 to len(aobjects)
			if aobjects[x].nindex = nindex				
				del(aobjects,x)
				exit
			ok
		next
		

	func startup

		if GE_FULLSCREEN
			gl_set_new_display_flags(GL_FULLSCREEN)
		ok

		display = gl_create_display(screen_w,screen_h)

		if ISNULL(display)
			gl_errormsg("Can't create the display window!")
			gl_exit()
		ok

		gl_set_window_title(display,title)

		ev = gl_new_glib_event()
		timeout = gl_new_glib_timeout()
		event_queue = gl_create_event_queue()
		timer = gl_create_timer(1.0 / fps)

		gl_events(display,event_queue,ev,timer,timeout)

		
	func start

		gClock = clock()
		lMouseDown = False
		lJoyKey2Down = False
		lJoyKey3Down = False

		while shutdown = false
			gl_init_timeout(timeout, nTimeOut)
			gl_wait_for_event_until(event_queue, ev, timeout)
			switch gl_get_glib_event_type(ev)
					on gl_event_display_close
						shutdown()
					on gl_event_timer
						# keyboard
						if key[key_up]
							for t in aobjects  t.keyboard(self,key_up)  next
						ok
						if key[key_down]
							for t in aobjects  t.keyboard(self,key_down)  next
						ok
						if key[key_left]
							for t in aobjects  t.keyboard(self,key_left)  next
						ok
						if key[key_right]
							for t in aobjects  t.keyboard(self,key_right)  next
						ok
						if key[key_other]
							key[key_other] = false
							for t in aobjects  t.keyboard(self,nkeycode)  next
							nKeyCode = 0
						ok		
						redraw = true
					on GL_event_mouse_axes
						aMouselist = [gl_mouse_x(),gl_mouse_y()]
						for t in aobjects  t.mouse(self,GL_event_mouse_axes,aMouseList)  next						 
					on GL_event_mouse_enter_display
						aMouselist = [gl_mouse_x(),gl_mouse_y()]
						for t in aobjects  t.mouse(self,GL_event_mouse_enter_display,aMouseList)  next 
					on GL_event_mouse_button_down
						aMouselist = [gl_mouse_x(),gl_mouse_y()]
						for t in aobjects  t.mouse(self,GL_event_mouse_button_down,aMouseList)  next
						lMouseDown = True
					on GL_event_mouse_button_up
						if lMouseDown = True
							lMouseDown = False
							aMouselist = [gl_mouse_x(),gl_mouse_y()]
							for t in aobjects  t.mouse(self,GL_event_mouse_button_up,aMouseList)  next					
						ok
					on GL_EVENT_FINGER_DOWN
						for t in aobjects  t.finger(self,GL_EVENT_FINGER_DOWN)  next
					on GL_EVENT_FINGER_UP
						for t in aobjects  t.finger(self,GL_EVENT_FINGER_UP)  next
					on GL_EVENT_FINGER_MOTION
 						for t in aobjects  t.finger(self,GL_EVENT_FINGER_MOTION)  next
					on GL_event_key_down
						nkeycode = gl_get_glib_event_keyboard_keycode(ev)
						switch nkeycode
								on gl_key_up
									key[key_up] = true
								on gl_key_down
									key[key_down] = true
								on gl_key_left
									key[key_left] = true
								on gl_key_right
									key[key_right] = true							
						off
					on GL_event_key_up
						switch gl_get_glib_event_keyboard_keycode(ev)
								on gl_key_up
										key[key_up] = false
								on gl_key_down
										key[key_down] = false
								on gl_key_left
										key[key_left] = false
								on gl_key_right
										key[key_right] = false
								other
										key[key_other] = true
						off
			off

			if GL_LIBNAME = :Allegro and not isAndroid() 
		
				Switch gl_get_glib_event_type(ev)
				on ALLEGRO_EVENT_JOYSTICK_AXIS
					nAxis = al_get_allegro_event_joystick_axis(ev)
					nPos  = al_get_allegro_event_joystick_pos(ev)
					if nAxis = 0
						if nPos = 1	# Right
							Key[KEY_RIGHT] 	= True
						but nPos = -1	# Left
							Key[KEY_LEFT] 	= True
						but nPos = 0
							Key[KEY_LEFT] 	= False
							Key[KEY_Right] 	= False
						ok
					but nAxis = 1 
						if nPos = 1	# Down
							Key[KEY_DOWN] 	= True
						but nPos = -1	# Up
							Key[KEY_UP] 	= True
						but nPos = 0
							Key[KEY_UP] 	= False
							Key[KEY_DOWN] 	= False
						ok
					ok
				on ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN
					nJoyStickButton = al_get_allegro_event_joystick_button(ev)
					switch nJoyStickButton
					on 2
						lJoyKey2Down = True
					on 3
						lJoyKey3Down = True
					off
				on ALLEGRO_EVENT_JOYSTICK_BUTTON_UP
					nJoyStickButton = al_get_allegro_event_joystick_button(ev)
					switch nJoyStickButton
					on 2
						if lJoyKey2Down = True 
							lJoyKey2Down = False
							nKeyCode = GL_SPACE
							for t in aobjects  t.keyboard(self,nkeycode)  next
						ok
					on 3
						if lJoyKey3Down = True 
							lJoyKey3Down = False
							nKeyCode = GL_ESC
							for t in aobjects  t.keyboard(self,nkeycode)  next
						ok
					off
				off
			ok


			drawdone = false
			if redraw and gl_is_event_queue_empty(event_queue)
				redraw = false
				drawobjs()
				drawdone = true
			ok

			nDif = clock() - gclock
			if nDif >= (clockspersecond()/FixedFPS)		
				if drawdone = false	
					drawobjs()
				ok					
				nDif = floor( nDif / (clockspersecond()/FixedFPS) )
				for nTimes = 1 to nDif
					for t=len(aobjects) to 1 step -1 
							aobjects[t].animate(self,aobjects[t]) 
					next	
				next	
				gclock = clock()	 
			ok	 			
		end

	func drawobjs
		gl_set_target_bitmap(gl_get_backbuffer(display))
		# Required for Android/LibSDL and Scaling
			gl_clear_to_color(GE_COLOR_BLACK)  
		gl_draw_filled_rectangle(0,0,screen_w,screen_h,GE_COLOR_WHITE)
		for t in aobjects t.draw(self) next		
		gl_flip_display()

	func shutdown
		delete()
		gl_exit()

	func deleteobjs
		for t in aobjects t.delete() next
		aObjects = []

	func delete
		deleteobjs()
		gl_destroy(display,event_queue,timeout,ev,timer)

	func getsprite	
		addobj(new sprite)
		return aobjects[len(aobjects)]

	func gettext
		addobj(new text)
		return aobjects[len(aobjects)]

	func getprogress
		addobj(new progress)
		return aobjects[len(aobjects)]

	func getanimate
		addobj(new animate)
		return aobjects[len(aobjects)]

	func getsound
		addobj(new sound)
		return aobjects[len(aobjects)]

	func getmap
		addobj(new map)
		return aobjects[len(aobjects)]
		
	func getobject
		addobj(new gameobject)
		return aobjects[len(aobjects)]

	func find cName
		nMax = len(aObjects)
		for x = 1 to nMax
			if aObjects[x].name = cName 
				return aObjects[x]
			ok
		next 
		raise("Can't find the object : " + cName)

	func operator cOperator,cValue
		if cOperator = "[]"
			return find(cValue)
		ok
