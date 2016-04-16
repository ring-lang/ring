Load "gamelib.ring"

Class GameBase
	Title="My Game!"
	SCREEN_W=800  SCREEN_H=600
	KEY_UP = 1 	KEY_DOWN = 2  KEY_LEFT = 3 	KEY_RIGHT = 4

Class Resources

	aImages = []

	func loadimage cFileName
		nPos = find(aImages,cFileName,1)
		if nPos = 0
			aImages + [cFileName,al_load_bitmap(cFileName)]
			nPos = len(aImages)
		ok
		return aImages[nPos][2]

	func unloadimage cFileName
		nPos = find(aImages,cFileName,1)
		if not nPos = 0
			al_destroy_bitmap(aImages[nPos][2])
			del(aImages,nPos)
		ok

Class Game from GameBase
	display event_queue ev timeout timer
	FPS = 60	redraw = true
	Key = [false,false,false,false]
	aObjects = []
	startup()

	func braceend
		start()

	func add oObject
		aObjects + oObject

	func startup

		al_init()
		al_init_image_addon()

		display = al_create_display(SCREEN_W,SCREEN_H)
		al_set_window_title(display,Title)

		event_queue = al_create_event_queue()
		al_register_event_source(event_queue, al_get_display_event_source(display))

		ev = al_new_allegro_event()
		timeout = al_new_allegro_timeout()
		al_init_timeout(timeout, 0.06)

		timer = al_create_timer(1.0 / FPS)
		al_register_event_source(event_queue, al_get_timer_event_source(timer))
		al_start_timer(timer)

		al_install_mouse()
		al_register_event_source(event_queue, al_get_mouse_event_source())

		al_install_keyboard()
		al_register_event_source(event_queue, al_get_keyboard_event_source())

	func start

		while true
			al_wait_for_event_until(event_queue, ev, timeout)
			switch al_get_allegro_event_type(ev)
					on ALLEGRO_EVENT_DISPLAY_CLOSE
						exit
					on ALLEGRO_EVENT_TIMER
						# Keyboard
						if key[KEY_UP]
							for t in aObjects  t.keyboard(KEY_UP)  next
						ok
						if key[KEY_DOWN]
							for t in aObjects  t.keyboard(KEY_DOWN)  next
						ok
						if key[KEY_LEFT]
							for t in aObjects  t.keyboard(KEY_LEFT)  next
						ok
						if key[KEY_RIGHT]
							for t in aObjects  t.keyboard(KEY_RIGHT)  next
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
				al_set_target_bitmap(al_get_backbuffer(display))
				al_clear_to_color(al_map_rgb(255,255,255))
				for t in aObjects t.Draw() next
				al_flip_display()
				for t in aObjects t.Animate() next				
			ok		
			 
			callgc()
			
		end
		delete()

	func delete
		al_destroy_timer(timer)
		al_destroy_allegro_event(ev)
		al_destroy_allegro_timeout(timeout)
		al_destroy_event_queue(event_queue)
		for t in aObjects t.Delete() next
		al_destroy_display(display)

	func getimage		
		add(new GameImage)
		return aObjects[len(aObjects)]

	Private
		Image
		

Class GameObject from GameBase
	x=0 y=0	 width=0 height=0
	lAnimate=True	lMove=False lScaled=False
	func init
	func draw
	func animate
	func delete
	func keyboard nKey

Class GameImage from GameObject
	Image	nPoint=400
	nDirection = 1	nStep=1
	nCounter = 0
	r = 0
	cImageFile = ""

	Func loadfile cFileName
		Image = oResources.LoadImage(cFileName)
		cImageFile = cFileName

	Func draw
		if lScaled
			al_draw_scaled_bitmap(image,0,0,al_get_bitmap_width(image),
			al_get_bitmap_height(image),x,y,width,height,0)
		else
			al_draw_bitmap(image,x,y,0)
		ok

	Func Animate
		if not lAnimate return ok
		if nDirection = 1
			if x < nPoint
				x++
				y++
			else
				x = 0
				y = 0
			ok
		but nDirection = 2
			if x > nPoint
				x--
				y--
			else
				x = 0
				y = 0
			ok
		but nDirection = 3
			if nCounter = 0
				r = random(7)
				nCounter++
			else
				if nCounter=10
					nCounter=0
				else
					nCounter++
				ok
			ok
			switch r
			on 0	x+=nStep
			on 1	x-=nStep
			on 2	y+=nStep
			on 3	y-=nStep
			on 4	x+=nStep y+=nStep
			on 5	x-=nStep y-=nStep
			on 6	x+=nStep y-=nStep
			on 7	x-=nStep y+=nStep
			off
		ok

	Func Keyboard nKey
		if not lMove return ok
		Switch nKey
		on KEY_UP	y-=10
		on KEY_DOWN	y+=10
		on KEY_LEFT	x-=10
		on KEY_RIGHT	x+=10
		off

	Func Delete
		oResources.unloadImage(cImageFile)
