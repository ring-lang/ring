# Gold Magic 800 3D Game
# 2018, Etqan Company

class GameCamera

	# General Information about the Screen 

		SCREEN_W	SCREEN_H
		SCREEN_W_2D	SCREEN_H_2D

	# Camera Settings

		angle lx lz x z fraction 

		C_VIEWTYPE_CAMERA  	= 1
		C_VIEWTYPE_MAP		= 2
		nViewType		= 0

	# Camera Movement 

		nSpeedRightLeft = 5
		nSpeedUpDown 	= 16

		# How many times the (UP Arrow) is pressed!		

			nUPTimes = 0

		# Slow Camera Movement 
			lSlowMotion 	= True
			nToMoveUp 	= 0
			nToMoveDown 	= 0

	# Play 2D 
		lPlay2D = False

	DefaultCameraData()

	func DefaultCameraData()

		# View Type 

			nViewType		= 0

		# Angle of rotation for the camera direction

			angle=0

		# Actual vector representing the camera's direction

			lx=0
			lz=-1

		# XZ position of the camera

			x=0
			z=5
	
		fraction = 0.1
	
		# How many times the (UP Arrow) is pressed!	
	
			nUPTimes = 0

		# Slow Motion

			nToMoveUp 	= 0
			nToMoveDown 	= 0

	func GameLevelCameraView

		nViewType = C_VIEWTYPE_CAMERA

		w = SCREEN_W h = SCREEN_H
		ratio =  w / h

		glViewport(0, 0, W, H)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()

		gluPerspective(110,ratio,1,50)
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

		glClear( GL_DEPTH_BUFFER_BIT)	 

		glLoadIdentity()									

		gluLookAt(x, 10, z+5,
                        x+lx, 1.0,  z+lz,
                        0.0, 1.0,  0.0)

		if lPlay2D 
			GameLevel2DCameraView() 
		ok

	func GameMapCameraView

		nViewType = C_VIEWTYPE_MAP

		C_MAP_SIZE_WIDTH = SCREEN_W_2D / 5
		C_MAP_SIZE_HEIGHT = SCREEN_H_2D / 3
		glViewport(SCREEN_W-C_MAP_SIZE_WIDTH, SCREEN_H-C_MAP_SIZE_HEIGHT-20,
			 C_MAP_SIZE_WIDTH, C_MAP_SIZE_HEIGHT)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()

		gluPerspective(100,1,1,100)
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()

		glClearColor(0.0, 0.0, 0.0, 0.0)
		glClearDepth(1)			

		glClear( GL_DEPTH_BUFFER_BIT)	 

		glLoadIdentity()									

		gluLookAt(0, 25, 0,
                        0, 0,  0,
                        0, 0,  1)

		glRotatef(-180, 0, 1, 0);

	func GameLevel2DCameraView

		nViewType = C_VIEWTYPE_MAP

		C_MAP_SIZE_WIDTH = SCREEN_W 
		C_MAP_SIZE_HEIGHT = SCREEN_H 
		glViewport(0, 0,
			 C_MAP_SIZE_WIDTH, C_MAP_SIZE_HEIGHT)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()

		ratio = C_MAP_SIZE_WIDTH / C_MAP_SIZE_HEIGHT
		gluPerspective(110,ratio,1,50)
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()

		glClearColor(0.0, 0.0, 0.0, 0.0)
		glClearDepth(1)			

		glClear( GL_DEPTH_BUFFER_BIT)	 

		glLoadIdentity()									



		gluLookAt(0, 20, 0,
                        0, 0,  0,
                        0, 0,  1)

		gltranslatef(0,5,-10)

		glRotatef(-180, 0, 1, 0);

	func moveup

                z += lz * fraction
		nUPTimes++

	func movedown

		if nUPTimes > 0
			nUPTimes--
			z -= lz * fraction
		ok

	func moveleft 

		angle -= 0.01
		lx = sin(angle)

	func moveright 

		angle += 0.01
		lx = sin(angle)

	func FastMoveLeft

		for t = 1 to nSpeedRightLeft
			moveleft() 
		next

	func FastMoveRight

		for t = 1 to nSpeedRightLeft
			moveRight() 
		next

	func FastMoveUp
		if lSlowMotion
			nToMoveUp += nSpeedUpDown return 
		ok
		for t = 1 to nSpeedUpDown
			moveup()
		next

	func FastMoveDown
		if lSlowMotion
			nToMoveDown += nSpeedUpDown return 
		ok
		for t = 1 to nSpeedUpDown
			movedown()
		next

	func Update 

		if lSlowMotion
			if nToMoveUp
				nStep = (nToMoveUp*2)/5
				nToMoveUp-= nStep
				for t = 1 to nStep
					moveup()
				next
			ok
			if nToMoveDown
				nStep = (nToMoveDown*2)/5
				nToMoveDown-= nStep
				for t = 1 to nStep
					movedown()
				next
			ok
		ok
