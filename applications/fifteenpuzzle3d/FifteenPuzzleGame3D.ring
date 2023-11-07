/*
**
**	Game  	: CalmoSoft Fifteen Puzzle Game 3D 
**	Date   	: 2017/09/01
**  	Author 	: CalmoSoft <calmosoft@gmail.com>
**
*/

# Load Libraries
load "gamelib.ring"		# RingAllegro Library
load "opengl21lib.ring"		# RingOpenGL  Library

butSize = 3
texture = list(9)
cube = list(9)
rnd = list(9)
rndok = 0

for n=1 to 9
     rnd[n] = 0
next 

for n=1 to 9
     while true
               rndok = 0
               ran = random(8) + 1
               for nr=1 to 9
                     if rnd[nr] = ran
                        rndok = 1
                     ok
               next  
               if rndok = 0
                  rnd[n] = ran
                  exit
               ok 
     end
next 

for n=1 to 9
     if rnd[n] = 9
        empty = n
     ok
next 

#==============================================================
# To Support MacOS X
	al_run_main()	
	func al_game_start 	# Called by al_run_main()
		main()		# Now we call our main function
#==============================================================

func main
	new FifteenPuzzle3D {
		start()
	}

class FifteenPuzzle3D from GameLogic

	FPS	= 120
	TITLE	= "CalmoSoft Fifteen Puzzle Game 3D"
	ICON	= "image/n1.jpg"

	oBackground	= new GameBackground
	oGameSound	= new GameSound
	oGameCube	= new GameCube
	oGameInterface	= new GameInterface 

	func loadresources
		oGameSound.loadresources()
		oBackGround.loadresources()
		oGameCube.loadresources()

	func drawScene
		oBackground.update()
		oGameInterface.update(self)

	func MouseClickEvent
		oGameInterface.MouseClickEvent(self)

class GameInterface 

	func Update oGame
		prepare()
		cubes(oGame)

	func Prepare 
		w = 1024 h = 768
		ratio =  w / h
		glViewport(0, 0, w, h)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
		gluPerspective(-120,ratio,1,120)
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()
		glEnable(GL_TEXTURE_2D)							
		glShadeModel(GL_SMOOTH)		
		glClearColor(0.0, 0.0, 0.0, 0.5)
		glClearDepth(1.0)			
		glEnable(GL_CULL_FACE)
		glDepthFunc(GL_LEQUAL)
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)

	func Cubes oGame
		oGame.oGameCube {
		aGameMap = oGame.aGameMap 
                cube[1] = cube( 5  , -3 , -5  , texture[rnd[1]] )
		cube[2] = cube( 0  , -3 , -5  , texture[rnd[2]] )
		cube[3] = cube( -5 , -3 , -5  , texture[rnd[3]] )
		cube[4] = cube( 5  , 1  , -5  , texture[rnd[4]] )
		cube[5] = cube( 0  , 1  , -5  , texture[rnd[5]] )
		cube[6] = cube( -5 , 1  , -5  , texture[rnd[6]] )
		cube[7] = cube( 5  , 5  , -5  , texture[rnd[7]] )
		cube[8] = cube( 0  , 5  , -5  , texture[rnd[8]] )
		cube[9] = cube( -5 , 5  , -5  , texture[rnd[9]] )
 		rotate()
		}

	func MouseClickEvent oGame
		oGame {
			aBtn = Point2Button(Mouse_X,Mouse_Y)
                        move = 0
			nRow = aBtn[1]
			nCol = aBtn[2]
                        tile = (nRow-1)*3 + nCol
                        up = (empty = (tile - butSize))
                        down = (empty = (tile + butSize))
                        left = ((empty = (tile- 1)) and ((tile % butSize) != 1))
                        right = ((empty = (tile + 1)) and ((tile % butSize) != 0))
                        move = up or down or left  or right
                        if move = 1 
                           temp = rnd[empty]
                           rnd[empty] = rnd[tile] 
                           rnd[tile] = temp
                           empty = tile
                           oGame.oGameCube {
		                      aGameMap = oGame.aGameMap 
                                      cube[1] = cube( 5  , -3 , -5  , texture[rnd[1]] )
		                      cube[2] = cube( 0  , -3 , -5  , texture[rnd[2]] )
		                      cube[3] = cube( -5 , -3 , -5  , texture[rnd[3]] )
		                      cube[4] = cube( 5  , 1  , -5  , texture[rnd[4]] )
		                      cube[5] = cube( 0  , 1  , -5  , texture[rnd[5]] )
	                              cube[6] = cube( -5 , 1  , -5  , texture[rnd[6]] )
		                      cube[7] = cube( 5  , 5  , -5  , texture[rnd[7]] )
	                              cube[8] = cube( 0  , 5  , -5  , texture[rnd[8]] )
		                      cube[9] = cube( -5 , 5  , -5  , texture[rnd[9]] )
 		                      rotate()
		           }
                        ok
		}

Class GameLogic from GraphicsAppBase

	aGameMap = [
		[ :n , :n , :n ] ,
		[ :n , :n , :n ] ,
		[ :n , :n , :n ]
	]

	aGameButtons = [			# x1,y1,x2,y2
 		[176,88,375,261],		# [1,1]
		[423,88,591,261],		# [1,2]
		[645,88,876,261],		# [1,3]
 		[176,282,375,428],		# [2,1]
		[423,282,591,428],		# [2,2]
		[645,282,876,428],		# [2,3]
 		[176,454,375,678],		# [3,1]
		[423,454,591,678],		# [3,2]
		[645,454,876,678]		# [3,3]
	]

	cActivePlayer = :x

	func point2button x,y
		nRow = 0
		nCol = 0
		for t = 1 to len(aGameButtons) 
			rect = aGameButtons[t]
			if x >= rect[1] and x <= rect[3] and
			   y >= rect[2] and y <= rect[4] 
					switch t
						on 1  nRow = 1  nCol = 1
						on 2  nRow = 1  nCol = 2
						on 3  nRow = 1 	nCol = 3
						on 4  nRow = 2  nCol = 1
						on 5  nRow = 2  nCol = 2
						on 6  nRow = 2  nCol = 3
						on 7  nRow = 3 	nCol = 1
						on 8  nRow = 3  nCol = 2
						on 9  nRow = 3  nCol = 3
					off
					exit 
			ok
		next 
		return [nRow,nCol]

class GameCube

	bitmap bitmap2 bitmap3 
	textureX textureO textureN

	xrot = 0.0
	yrot = 0.0
	zrot = 0.0

	func loadresources
		bitmp1 = al_load_bitmap("image/n1.jpg")
		texture[1] = al_get_opengl_texture(bitmp1)
		bitmp2 = al_load_bitmap("image/n2.jpg")
		texture[2] = al_get_opengl_texture(bitmp2)
		bitmp3 = al_load_bitmap("image/n3.jpg")
		texture[3] = al_get_opengl_texture(bitmp3)
		bitmp4 = al_load_bitmap("image/n4.jpg")
		texture[4] = al_get_opengl_texture(bitmp4)
		bitmp5 = al_load_bitmap("image/n5.jpg")
		texture[5] = al_get_opengl_texture(bitmp5)
		bitmp6 = al_load_bitmap("image/n6.jpg")
		texture[6] = al_get_opengl_texture(bitmp6)
		bitmp7 = al_load_bitmap("image/n7.jpg")
		texture[7] = al_get_opengl_texture(bitmp7)
		bitmp8 = al_load_bitmap("image/n8.jpg")
		texture[8] = al_get_opengl_texture(bitmp8)
		bitmp9 = al_load_bitmap("image/empty.png")
		texture[9] = al_get_opengl_texture(bitmp9)

	func cube(x,y,z,nTexture)
		glLoadIdentity()									
		glTranslatef(x,y,z)
		glRotatef(xrot,1.0,0.0,0.0)
		glRotatef(yrot,0.0,1.0,0.0)
		glRotatef(zrot,0.0,0.0,1.0)
		setCubeTexture(nTexture)
		drawCube()

	func setCubeTexture cTexture
		glBindTexture(GL_TEXTURE_2D, cTexture)

	func Rotate 
		xrot += 0.3 * 5
		yrot += 0.2 * 5
		zrot += 0.4 * 5

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


class GameBackground 

	nBackX = 0
	nBackY = 0
	nBackDiffx = -1
	nBackDiffy = -1
	nBackMotion = 1
	aBackMotionList = [
		[ -1, -1 ] ,		# Down - Right
		[ 0 , 1  ] ,		# Up
		[ -1, -1 ] , 		# Down - Right
		[ 0 , 1  ] ,		# Up
		[ 1 , -1 ] ,		# Down - Left
		[ 0 , 1  ] ,		# Up
		[ 1 , -1 ] , 		# Down - Left
		[ 0 , 1  ]			# Up
	]

	bitmap

	func Update 
		draw()
		motion()

	func draw
		al_draw_bitmap(bitmap,nBackX,nBackY,1)

	func motion
		nBackX += nBackDiffx
		nBackY += nBackDiffy
		if (nBackY = -350) or (nBackY = 0)
			nBackMotion++
			if nBackMotion > len(aBackMotionList)
				nBackMotion = 1
			ok
			nBackDiffx  = aBackMotionList[nBackMotion][1]
			nBackDiffy  = aBackMotionList[nBackMotion][2]
		ok

	func loadResources
		bitmap = al_load_bitmap("image/back.jpg")

class GameSound

	sample sampleid

	func loadresources
		sample = al_load_sample( "sound/music1.wav" )
		sampleid = al_new_allegro_sample_id()
		al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,sampleid)

class GraphicsAppBase

	display event_queue ev timeout 
	timer  
	redraw 			= true
	FPS 			= 60 
	SCREEN_W 		= 1024
	SCREEN_H 		= 700
	KEY_UP			= 1
	KEY_DOWN 		= 2
	KEY_LEFT 		= 3
	KEY_RIGHT 		= 4
	Key 			= [false,false,false,false]
	Mouse_X 		= 0
	Mouse_Y			= 0
	TITLE 			= "Graphics Application"
	ICON			= ""
	PRINT_MOUSE_XY 	= False

	func start
		SetUp()
		loadResources()
		eventsLoop()
		destroy()

	func setup
		al_init()
		al_init_font_addon()
		al_init_ttf_addon()
		al_init_image_addon()
		al_install_audio()
		al_init_acodec_addon()
		al_reserve_samples(1)
		al_set_new_display_flags(ALLEGRO_OPENGL) 
		display = al_create_display(SCREEN_W,SCREEN_H)
		al_set_window_title(display,TITLE)
		if icon != NULL
			al_set_display_icon(display,al_load_bitmap(icon))
		ok
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
				CloseEvent()
			on ALLEGRO_EVENT_TIMER
				redraw = true
			on ALLEGRO_EVENT_MOUSE_AXES
				mouse_x = al_get_allegro_event_mouse_x(ev)
				mouse_y = al_get_allegro_event_mouse_y(ev)
				if PRINT_MOUSE_XY
					see "x = " + mouse_x + nl
					see "y = " + mouse_y + nl
				ok
			on ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY
				mouse_x = al_get_allegro_event_mouse_x(ev)
				mouse_y = al_get_allegro_event_mouse_y(ev)
			on ALLEGRO_EVENT_MOUSE_BUTTON_UP
				MouseClickEvent()
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

	func MouseClickEvent
		exit 			# Exit from the Events Loop 

	func CloseEvent
		exit 			# Exit from the Events Loop 
