/*
**
**	Game  			 : TicTacToe 3D 
**	Date   			 : 2017/08/30
**  	Author 			 : Mahmoud Fayed <msfclipper@yahoo.com>
**
**	Note :  The CheckWinner() function is 
**			written by Abdulrahman Mahmoud 
**			See ring/applications/tictactoe
**
*/

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
	new TicTacToe3D {
		start()
	}

class TicTacToe3D from GameLogic

	FPS = 60
	TITLE = "TicTacToe 3D"

	oBackground = new GameBackground
	oGameSound = new GameSound
	oGameCube = new GameCube
	oGameOver = new GameOver
	oGameInterface = new GameInterface 

	func loadresources
		oGameOver.loadresources()
		oGameSound.loadresources()
		oBackGround.loadresources()
		oGameCube.loadresources()

	func destroyResources
		oGameOver.destroyResources()
		oGameSound.destroyResources()
		oBackGround.destroyResources()
		oGameCube.destroyResources()

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
		glEnable(GL_DEPTH_TEST)	
		glEnable(GL_CULL_FACE)
		glDepthFunc(GL_LEQUAL)
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)

	func Cubes oGame
		oGame.oGameCube {
			aGameMap = oGame.aGameMap 
			cube( 5  , -3 , -5  , aGameMap[1][1] )
			cube( 0  , -3 , -5  , aGameMap[1][2] )
			cube( -5 , -3 , -5  , aGameMap[1][3] )
			cube( 5  , 1  , -5  , aGameMap[2][1] )
			cube( 0  , 1  , -5  , aGameMap[2][2] )
			cube( -5 , 1  , -5  , aGameMap[2][3] )
			cube( 5  , 5  , -5  , aGameMap[3][1] )
			cube( 0  , 5  , -5  , aGameMap[3][2] )
			cube( -5 , 5  , -5  , aGameMap[3][3] )
			rotate()
		}

	func MouseClickEvent oGame
		oGame {
			aBtn = Point2Button(Mouse_X,Mouse_Y)
			nRow = aBtn[1]
			nCol = aBtn[2]
			if nRow != 0 and nCol != 0	
				if aGameMap[nRow][nCol] = :n
					aGameMap[nRow][nCol] = cActivePlayer
					ChangeActivePlayer()
					CheckGameOver()
				ok 			
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

	func ChangeActivePlayer()
		if cActivePlayer = :x
			cActivePlayer = :o
		else 
			cActivePlayer = :x
		ok

	func CheckGameOver
		aList = [
			aGameMap[1][1],
			aGameMap[1][2],
			aGameMap[1][3],
			aGameMap[2][1],
			aGameMap[2][2],
			aGameMap[2][3],
			aGameMap[3][1],
			aGameMap[3][2],
			aGameMap[3][3]
		]
		for item in aList 
			switch item 
				on :x	item = 1
				on :o	item = 2
				on :n	item = 0
			off
		next
		nStatus = CheckWinner(aList)
		if nStatus 
			oGameOver {
				Switch nStatus
					on 1 Player1Win(this)  
					on 2 Player2Win(this)  
					on 3 NoOneWin(this)   
				off
			}
			refreshGame()
		ok

	func refreshGame
		aGameMap = [
			[ :n , :n , :n ] ,
			[ :n , :n , :n ] ,
			[ :n , :n , :n ]
		]
		cActivePlayer = :x

	func CheckWinner lst
        //vertical check
        for v=1 to 9 step 3
            if lst[v]!=0 and lst[v+1]!=0 and lst[v+2]!=0
				if lst[v]=lst[v+1] and lst[v+1]=lst[v+2]
                    return lst[v]
                ok
            ok
        next
        //horzintal
        for h=1 to 3
            if lst[h]!=0 and lst[h+3]!=0 and lst[h+6]!=0
                if lst[h]=lst[h+3] and lst[h+3]=lst[h+6]
                    return lst[h]
                ok
            ok
        next
        //Cross
        if lst[1]!=0 and lst[5]!=0 and lst[9]!=0
            if lst[1]=lst[5] and lst[5]=lst[9] return lst[1] ok
        ok
        if lst[3]!=0 and lst[5]!=0 and lst[7]!=0
            if lst[3]=lst[5] and lst[5]=lst[7] return lst[3] ok
        ok
        //tie
        tie=true
        for i=1 to 9
            if lst[i]=0 tie=false exit ok
        next
        if tie=true return 3 ok return 0



class GameOver

	font bitmap lNewWindow = False

	func loadresources
		font = al_load_ttf_font("font/pirulen.ttf",54,0 )
		bitmap = al_load_bitmap("image/ballon.png")

	func destroyResources
		al_destroy_bitmap(bitmap)
		al_destroy_font(font)

	func Player1Win oGame
		showMsg(oGame,80,430,"Good job X you won!")
		
	func Player2Win oGame
		showMsg(oGame,80,430,"Good job O you won!")
	
	func NoOneWin oGame
		showMsg(oGame,150,430,"Oh no it's a tie!")
		
	func ShowMsg oGame,x,y,cMsg
		oGame {
			drawScene()
			al_flip_display()
			al_rest(0.3)
			
			if this.lNewWindow
 				newdisplay = al_create_display(SCREEN_W,SCREEN_H)
				al_set_window_title(newdisplay,TITLE)
			else 
				this.set2DMODE()
			ok
 			al_clear_to_color(al_map_rgb(255,255,255))
			al_draw_bitmap(this.bitmap,200,50,1)
			al_draw_text(this.font,
				 al_map_rgb(0,0,255), x,y,
				 ALLEGRO_ALIGN_LEFT,cMsg)
			al_flip_display()
			al_rest(2)
			if this.lNewWindow
				al_destroy_display(newdisplay)
			ok
			al_set_target_backbuffer(display)
		}

	func set2DMode
		glMatrixMode(GL_PROJECTION)
		glPopMatrix()
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()
		glDisable(GL_CULL_FACE) 

class GameCube

	bitmap bitmap2 bitmap3 
	textureX textureO textureN

	xrot = 0.0
	yrot = 0.0
	zrot = 0.0

	func loadresources
		bitmap = al_load_bitmap("image/o.png")
		textureO = al_get_opengl_texture(bitmap)
		bitmap2 = al_load_bitmap("image/x.png")
		textureX = al_get_opengl_texture(bitmap2)
		bitmap3 = al_load_bitmap("image/empty.png")
		textureN = al_get_opengl_texture(bitmap3)

	func destroyResources
		al_destroy_bitmap(bitmap)
		al_destroy_bitmap(bitmap2)
		al_destroy_bitmap(bitmap3)

	func cube(x,y,z,nTexture)
		glLoadIdentity()									
		glTranslatef(x,y,z)
		glRotatef(xrot,1.0,0.0,0.0)
		glRotatef(yrot,0.0,1.0,0.0)
		glRotatef(zrot,0.0,0.0,1.0)
		setCubeTexture(nTexture)
		drawCube()

	func setCubeTexture cTexture
		switch cTexture
			on :x
				glBindTexture(GL_TEXTURE_2D, textureX)
			on :o
				glBindTexture(GL_TEXTURE_2D, textureO)
			on :n
				glBindTexture(GL_TEXTURE_2D, textureN)
		off

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

	func destroyResources
		al_destroy_bitmap(bitmap)


class GameSound

	sample sampleid

	func loadresources
		sample = al_load_sample( "sound/music1.wav" )
		sampleid = al_new_allegro_sample_id()
		al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,sampleid)

	func destroyResources
		al_destroy_allegro_sample_id(sampleid)
		al_destroy_sample(sample)


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
