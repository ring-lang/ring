# the ring standard library
# game engine for 2d games
# 2016, mahmoud fayed <msfclipper@yahoo.com>

load "gamelib.ring"
load "gameengine.rh"

oresources = new resources

class gamebase
	title="my game!"
	screen_w=800  screen_h=600
	key_up = 1 	key_down = 2  key_left = 3 	key_right = 4 key_other = 5

class resources

	aimages = []
	afonts = []

	func loadimage cfilename
		npos = find(aimages,cfilename,1)
		if npos = 0
			aimages + [cfilename,al_load_bitmap(cfilename)]
			npos = len(aimages)
		ok
		return aimages[npos][2]

	func unloadimage cfilename
		npos = find(aimages,cfilename,1)
		if not npos = 0
			al_destroy_bitmap(aimages[npos][2])
			del(aimages,npos)
		ok

	func loadfont cfilename,nSize
		npos = find(afonts,cfilename,1)
		if npos = 0
			afonts + [cfilename,nSize,al_load_ttf_font(cfilename,nSize,0)]
			npos = len(afonts)
		ok
		return afonts[npos][3]

	func unloadfont cfilename,nsize
		for x=1 to len(aFonts)
			if aFonts[x][1] = cFileName and
			aFont[x][2] = nSize
				al_destroy_font(afonts[x][3])
				del(afonts,x)
				exit
			ok
		next



class game from gamebase
	display event_queue ev timeout timer
	fps = 60	redraw = true
	nid = 0
	key = [false,false,false,false,false]
	nkeycode=0
	aobjects = []
	lbraceend = true
	startup()

	func braceend
		# we check to call start() one time during the program life time
		if lbraceend = true
			lbraceend = false
			start()
		ok

	func add oobject
		nid++
		oobject.nindex = nid
		aobjects + oobject
	
	func remove nindex
		for x = 1 to len(aobjects)
			if aobjects[x].nindex = nindex
				del(aobjects,x)
				exit
			ok
		next
		

	func startup

		al_init()
		al_init_font_addon()
		al_init_ttf_addon()
		al_init_image_addon()

		display = al_create_display(screen_w,screen_h)
		al_set_window_title(display,title)

		event_queue = al_create_event_queue()
		al_register_event_source(event_queue, al_get_display_event_source(display))

		ev = al_new_allegro_event()
		timeout = al_new_allegro_timeout()
		al_init_timeout(timeout, 0.06)

		timer = al_create_timer(1.0 / fps)
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
					on allegro_event_display_close
						exit
					on allegro_event_timer
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
						ok		
						redraw = true
					on allegro_event_mouse_axes
						bouncer_x = al_get_allegro_event_mouse_x(ev)
						bouncer_y = al_get_allegro_event_mouse_y(ev)
					on allegro_event_mouse_enter_display
						bouncer_x = al_get_allegro_event_mouse_x(ev)
						bouncer_y = al_get_allegro_event_mouse_y(ev)
					on allegro_event_mouse_button_up
						#exit
					on allegro_event_key_down
						nkeycode = al_get_allegro_event_keyboard_keycode(ev)
						switch nkeycode
								on allegro_key_up
									key[key_up] = true
								on allegro_key_down
									key[key_down] = true
								on allegro_key_left
									key[key_left] = true
								on allegro_key_right
									key[key_right] = true									
						off

					on allegro_event_key_up
						switch al_get_allegro_event_keyboard_keycode(ev)
								on allegro_key_up
										key[key_up] = false
								on allegro_key_down
										key[key_down] = false
								on allegro_key_left
										key[key_left] = false
								on allegro_key_right
										key[key_right] = false
								other
										key[key_other] = true
						off
					off
			if redraw and al_is_event_queue_empty(event_queue)
				redraw = false
				al_set_target_bitmap(al_get_backbuffer(display))
				al_clear_to_color(al_map_rgb(255,255,255))
				for t in aobjects t.draw(self) next
				al_flip_display()
				for t=len(aobjects) to 1 step -1 aobjects[t].animate(self,aobjects[t]) next				
			ok		
			 
			callgc()
			
		end
		delete()

	func shutdown
		delete()
		al_exit()

	func delete
		al_destroy_timer(timer)
		al_destroy_allegro_event(ev)
		al_destroy_allegro_timeout(timeout)
		al_destroy_event_queue(event_queue)
		for t in aobjects t.delete() next
		al_destroy_display(display)

	func getsprite	
		add(new sprite)
		return aobjects[len(aobjects)]

	private
		sprite
		

class gameobject from gamebase
	x=0 y=0	 width=0 height=0 nindex = 0
	animate=true	move=false Scaled=false
	func init
	func draw
	func animate
	func delete
	func keyboard nkey

class sprite from gameobject
	image	point=400
	direction = 1	nstep=1
	ncounter = 0
	r = 0
	cimagefile = ""
	keypress = ""
	nStateClock = clock()
	state = ""
	type = 0

	func setfile cfilename
		image = oresources.loadimage(cfilename)
		cimagefile = cfilename

	func draw oengine
		if Scaled
			al_draw_scaled_bitmap(image,0,0,al_get_bitmap_width(image),
			al_get_bitmap_height(image),x,y,width,height,0)
		else
			al_draw_bitmap(image,x,y,0)
		ok

	func animate oGame,oSelf
		if not animate return ok
		if direction = ge_direction_inc
			if x < point
				x+=nstep
				y+=nstep
			else
				x = 0
				y = 0
			ok
		but direction = ge_direction_dec
			if x > point
				x-=nstep
				y-=nstep
			else
				x = 0
				y = 0
			ok
		but direction = ge_direction_incvertical
			if y < point				
				y+=nstep
			else
				oGame.remove(nindex)
			ok
		but direction = ge_direction_decvertical
			if y > point				
				y-=nstep
			else
				oGame.remove(nindex)
			ok
		but direction = ge_direction_random
			if ncounter = 0
				r = random(7)
				ncounter++
			else
				if ncounter=10
					ncounter=0
				else
					ncounter++
				ok
			ok
			switch r
			on 0	x+=nstep
			on 1	x-=nstep
			on 2	y+=nstep
			on 3	y-=nstep
			on 4	x+=nstep y+=nstep
			on 5	x-=nstep y-=nstep
			on 6	x+=nstep y-=nstep
			on 7	x-=nstep y+=nstep
			off
		ok
		if not state = ""				 		
				call state(oGame,oSelf) 
		ok

	func keyboard oGame,nkey
		if not keypress = ""			
			call keypress(oGame,self,nkey)
		ok
		if not move return ok
		switch nkey
		on key_up	y-=10
		on key_down	y+=10
		on key_left	x-=10
		on key_right	x+=10
		off

	func delete
		oresources.unloadimage(cimagefile)

	private
		file=0
