# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if isandroid()
	eval('load "gl_libsdl.ring"')
else
	eval('load "gl_allegro.ring"')
ok 

load "gameengine.rh"

oresources = new resources

gl_start_playing()

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
			aimages + [cfilename,gl_load_bitmap(cfilename)]
			npos = len(aimages)
		ok
		return aimages[npos][2]

	func unloadimage cfilename
		npos = find(aimages,cfilename,1)
		if not npos = 0
			gl_destroy_bitmap(aimages[npos][2])
			del(aimages,npos)
		ok

	func loadfont cfilename,nSize
		npos = find(afonts,cfilename,1)
		if npos = 0 or aFonts[nPos][2] != nSize
			afonts + [cfilename,nSize,gl_load_ttf_font(cfilename,nSize,0)]
			npos = len(afonts)
		ok
		return afonts[npos][3]

	func unloadfont cfilename,size
		for x=1 to len(aFonts)
			if aFonts[x][1] = cFileName and aFonts[x][2] = size
				gl_destroy_font(afonts[x][3])
				del(afonts,x)
				exit
			ok
		next

class game from gamebase

	display event_queue ev timeout timer
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
	sprite text progress animate sound map

	startup()

	func refresh
		deleteobjs()
		aobjects = []
		lbraceend = true
		shutdown = false

	func settitle cTitle
		title = cTitle
		gl_set_window_title(display,title)

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

		#gl_set_new_display_flags(GL_FULLSCREEN)

		display = gl_create_display(screen_w,screen_h)
		gl_set_window_title(display,title)

		ev = gl_new_glib_event()
		timeout = gl_new_glib_timeout()
		event_queue = gl_create_event_queue()
		timer = gl_create_timer(1.0 / fps)

		gl_events(display,event_queue,ev,timer,timeout)

		
	func start

		gClock = clock()

		while shutdown = false
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
					on GL_event_mouse_button_up
						aMouselist = [gl_mouse_x(),gl_mouse_y()]
						for t in aobjects  t.mouse(self,GL_event_mouse_button_up,aMouseList)  next					
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
				callgc()		
			ok	 			
		end

	func drawobjs
		gl_set_target_bitmap(gl_get_backbuffer(display))
		gl_clear_to_color(GE_COLOR_WHITE)
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
		

class gameobject from gamebase
	enabled = true
	x=0 y=0	 width=0 height=0 nindex = 0
	animate=true	move=false Scaled=false
	temp = null
	func init
	func draw
	func animate
	func delete
	func keyboard oGame,nkey
	func mouse oGame,nType,aMouseList
	func finger oGame,nType
	func rgb r,g,b
		return gl_map_rgb(r,g,b)

class sprite from gameobject
	image	point=400
	direction = 1	nstep=1
	ncounter = 0
	r = 0
	cimagefile = ""
	keypress = ""
	mouse = ""
	finger = ""
	state = ""
	type = 0
	transparent = false	transparentdone = false
	transparentcolor = GE_COLOR_WHITE

	file=0

	func setfile cfilename
		image = oresources.loadimage(cfilename)
		cimagefile = cfilename

	func dotransparent
		gl_convert_mask_to_alpha(image,transparentcolor)

	func draw oengine
		if not enabled return ok
		if transparent
			if not transparentdone
				transparentdone = true
				dotransparent()
			ok
		ok
		if Scaled
			gl_draw_scaled_bitmap(image,0,0,gl_get_bitmap_width(image),
			gl_get_bitmap_height(image),x,y,width,height,0)
		else
			gl_draw_bitmap(image,x,y,0)
		ok

	func animate oGame,oSelf
		if not enabled return ok
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
		if not enabled return ok
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

	func mouse oGame,nType,aMouseList
		if not enabled return ok
		if not mouse = ""			
			call mouse(oGame,self,nType,aMouseList)
		ok

	func finger oGame,nType
		if not enabled return ok
		if not finger = ""			
			call finger(oGame,self,nType)
		ok

	func delete
		oresources.unloadimage(cimagefile)


class text from sprite

	size = 14
	font  cfontfile  text="" color = GE_COLOR_WHITE
	
	func setfile cfilename
		font = oresources.loadfont(cfilename,size)
		cfontfile = cfilename

	func draw oGame
		gl_draw_text(font, color, x, y,GL_ALIGN_LEFT,text)		

	func delete
		oresources.unloadfont(cfontfile,size)

Class Animate from Sprite

	frames = 0
	frame = 1
	framewidth = 30
	animate = false
	scaled = false

	func draw oengine
		if not enabled return ok
		if transparent
			if not transparentdone
				transparentdone = true
				gl_convert_mask_to_alpha(image,transparentcolor)
			ok
		ok
		if Scaled
			gl_draw_scaled_bitmap(image,(framewidth*(frame-1)),0,framewidth,
			gl_get_bitmap_height(image),x,y,width,height,0)
		else
			gl_draw_bitmap_region(image,(framewidth*(frame-1)),0, framewidth, height, x, y, 0)
		ok


Class Sound from gameobject

	file sample  csoundfile sampleid
	playing = false
	type = 0
	once = false
	func setfile cfilename
		sample = gl_load_sample(cfilename)
		csoundfile = cfilename

	func playSound
		if not playing
			sampleid = gl_new_glib_sample_id()
			if once
				gl_play_sample(sample, 1.0, 0.0,1.0,GL_PLAYMODE_ONCE,sampleid)	
			else
				gl_play_sample(sample, 1.0, 0.0,1.0,GL_PLAYMODE_LOOP,sampleid)
			ok
			playing = true
		ok

	func delete
		if playing 
			playing = false
			gl_destroy_glib_sample_id(sampleid)
			gl_destroy_sample(sample)	
		ok
	func braceend
		playsound()

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
			gl_convert_mask_to_alpha(image,transparentcolor)
		next

	func draw
		nX = X
		nY = Y
		for y1 in aMap
			for x1 in y1
				if  x1 != 0 
					image = aPImages[x1]	
					gl_draw_scaled_bitmap(image,0,0,gl_get_bitmap_width(image),
					gl_get_bitmap_height(image),nX,nY,blockwidth,blockheight,0)
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
		x2 = min(x2, len(aMap[1]) )
		return x2
		
	func getrow x1,y1
		y2 = ceil(((-1*y) + y1)/blockheight)
		y2 = min(y2, len(aMap) )
		return y2
