# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

load "gamelib.ring"
load "gameengine.rh"

oresources = new resources

class gamebase
	title=""
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
		if npos = 0 or aFonts[nPos][2] != nSize
			afonts + [cfilename,nSize,al_load_ttf_font(cfilename,nSize,0)]
			npos = len(afonts)
		ok
		return afonts[npos][3]

	func unloadfont cfilename,size
		for x=1 to len(aFonts)
			if aFonts[x][1] = cFileName and aFonts[x][2] = size
				al_destroy_font(afonts[x][3])
				del(afonts,x)
				exit
			ok
		next

class game from gamebase

	display event_queue ev timeout timer
	fps = 60 	redraw = true
	nid = 0
	key = [false,false,false,false,false]
	nkeycode=0
	aobjects = []
	lbraceend = true
	shutdown = false
	startup()

	func refresh
		deleteobjs()
		aobjects = []
		lbraceend = true
		shutdown = false

	func settitle cTitle
		title = cTitle
		al_set_window_title(display,title)

	func braceend
		# we check to call start() one time during the program life time
		if lbraceend = true
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

		#al_set_new_display_flags(ALLEGRO_FULLSCREEN)
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

		while shutdown = false
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
						 
					on allegro_event_mouse_enter_display
 
					on allegro_event_mouse_button_up
						 
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
				drawobjs()
				for t=len(aobjects) to 1 step -1 
						aobjects[t].animate(self,aobjects[t]) 
				next				
				callgc()
			ok	 			
		end

	func drawobjs
		al_set_target_bitmap(al_get_backbuffer(display))
		al_clear_to_color(GE_COLOR_WHITE)
		for t in aobjects t.draw(self) next
		al_flip_display()

	func shutdown
		delete()
		al_exit()

	func deleteobjs
		for t in aobjects t.delete() next
		aObjects = []

	func delete
		deleteobjs()
		al_destroy_timer(timer)
		al_destroy_allegro_event(ev)
		al_destroy_allegro_timeout(timeout)
		al_destroy_event_queue(event_queue)	
		al_destroy_display(display)

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

	private
		sprite text progress animate sound map
		

class gameobject from gamebase
	lenabled = true
	x=0 y=0	 width=0 height=0 nindex = 0
	animate=true	move=false Scaled=false
	temp = null
	func init
	func draw
	func animate
	func delete
	func keyboard oGame,nkey
	func rgb r,g,b
		return al_map_rgb(r,g,b)

class sprite from gameobject
	image	point=400
	direction = 1	nstep=1
	ncounter = 0
	r = 0
	cimagefile = ""
	keypress = ""
	state = ""
	type = 0
	transparent = false	transparentdone = false
	transparentcolor = GE_COLOR_WHITE

	func setfile cfilename
		image = oresources.loadimage(cfilename)
		cimagefile = cfilename

	func dotransparent
		al_convert_mask_to_alpha(image,transparentcolor)

	func draw oengine
		if not lenabled return ok
		if transparent
			if not transparentdone
				transparentdone = true
				dotransparent()
			ok
		ok
		if Scaled
			al_draw_scaled_bitmap(image,0,0,al_get_bitmap_width(image),
			al_get_bitmap_height(image),x,y,width,height,0)
		else
			al_draw_bitmap(image,x,y,0)
		ok

	func animate oGame,oSelf
		if not lenabled return ok
		if not state = ""				 		
				call state(oGame,oSelf) 
		ok
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

	func keyboard oGame,nkey
		if not lenabled return ok
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

class text from sprite

	size = 14
	font  cfontfile  text="" color = GE_COLOR_WHITE
	
	func setfile cfilename
		font = oresources.loadfont(cfilename,size)
		cfontfile = cfilename

	func draw oGame
		al_draw_text(font, color, x, y,ALLEGRO_ALIGN_LEFT,text)		

	func delete
		oresources.unloadfont(cfontfile,size)

Class Animate from Sprite

	frames = 0
	frame = 1
	framewidth = 30
	animate = false
	scaled = false

	func draw oengine
		if not lenabled return ok
		if transparent
			if not transparentdone
				transparentdone = true
				al_convert_mask_to_alpha(image,transparentcolor)
			ok
		ok
		if Scaled
			al_draw_scaled_bitmap(image,(framewidth*(frame-1)),0,framewidth,
			al_get_bitmap_height(image),x,y,width,height,0)
		else
			al_draw_bitmap_region(image,(framewidth*(frame-1)),0, framewidth, height, x, y, 0)
		ok


Class Sound from gameobject

	file sample  csoundfile sampleid
	playing = false
	type = 0
	once = false
	func setfile cfilename
		sample = al_load_sample(cfilename)
		csoundfile = cfilename

	func playSound
		if not playing
			sampleid = al_new_allegro_sample_id()
			if once
				al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,sampleid)	
			else
				al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,sampleid)
			ok
			playing = true
		ok

	func delete
		if playing 
			playing = false
			al_destroy_allegro_sample_id(sampleid)
			al_destroy_sample(sample)	
		ok

Class Map from Sprite

	aMap = []
	aImages = []
	aPImages = []
	BlockWidth = 32
	BlockHeight = 32
	Animate = false
	width = 800
	height = 600

	lbraceend = true

	func braceend
		if lbraceend 
			lbraceend = false
			loadimages()
		ok

	func loadimages
		for t in aImages
			aPImages + oresources.loadimage(t)
			image = aPImages[len(aPImages)]
			al_convert_mask_to_alpha(image,transparentcolor)
		next

	func draw
		nX = X
		nY = Y
		for y1 in aMap
			for x1 in y1
				if  x1 != 0 
					image = aPImages[x1]	
					al_draw_scaled_bitmap(image,0,0,al_get_bitmap_width(image),
					al_get_bitmap_height(image),nX,nY,blockwidth,blockheight,0)
				ok
				nX += BlockWidth
				if nX > SCREEN_W
					EXIT
				ok
			next
			nY += BlockHeight
			nX = X
			if nY > SCREEN_H
				EXIT
			ok

		next
		
	func animate oGame,oSelf
		if not state = ""				 		
				call state(oGame,oSelf) 
		ok

	func getvalue x1,y1
		x2 = getcol(x1,y1)
		y2 = getrow(x1,y1)
		if y2 > 0 and y2 <= len(aMap)
			aList = aMap[y2]
			if x2 > 0 and x2 <= len(aList)
				return aList[x2]
			ok
		ok
		return 0

	func getcol x1,y1
		x2 = ceil(((-1*x) + x1)/blockwidth)
		return x2
		
	func getrow x1,y1
		y2 = ceil(((-1*y) + y1)/blockheight)
		return y2

