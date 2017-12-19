/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
*/

load "freeglut.ring"
load "opengl21lib.ring"

// angle of rotation for the camera direction
angle = 0.0

// actual vector representing the camera's direction
lx=0.0 lz=-1.0

// XZ position of the camera
x=0.0  z=5.0

// the key states. These variables will be zero
//when no key is being presses
deltaAngle = 0.0
deltaMove = 0
xOrigin = -1

// Constant definitions for Menus


// for RingFreeGLUT - We must have different ID for each menu item
C_RED = 1
C_GREEN = 2
C_BLUE  = 3
C_ORANGE = 4

C_FILL = 5
C_LINE = 6

C_SHRINK = 7
C_NORMAL = 8

// Pop up menu identifiers
fillMenu= 0  
shrinkMenu= 0
mainMenu=0 
colorMenu=0

// color for the nose
red = 1.0  blue=0.5  green=0.5

// scale of snowman
scale = 1.0

// menu status
menuFlag = 0

func changeSize
	w = glutEventWidth()
	h = glutEventHeight()

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if h = 0
		h = 1
	ok

	ratio =  w * 1.0 / h

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION)

	// Reset Matrix
	glLoadIdentity()

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h)

	// Set the correct perspective.
	gluPerspective(45.0, ratio, 0.1, 100.0)

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW)

func drawSnowMan

	glScalef(scale, scale, scale)
	glColor3f(1.0, 1.0, 1.0)

// Draw Body
	glTranslatef(0.0 ,0.75, 0.0)
	glutSolidSphere(0.75,20,20)

// Draw Head
	glTranslatef(0.0, 1.0, 0.0)
	glutSolidSphere(0.25,20,20)

// Draw Eyes
	glPushMatrix()
	glColor3f(0.0,0.0,0.0)
	glTranslatef(0.05, 0.10, 0.18)
	glutSolidSphere(0.05,10,10)
	glTranslatef(-0.1, 0.0, 0.0)
	glutSolidSphere(0.05,10,10)
	glPopMatrix()

// Draw Nose
	glColor3f(red, green, blue)
	glRotatef(0.0,1.0, 0.0, 0.0)
	glutSolidCone(0.08,0.5,10,2)

	glColor3f(1.0, 1.0, 1.0)


func computePos deltaMove

	x += deltaMove * lx * 0.1
	z += deltaMove * lz * 0.1


func renderScene

	if deltaMove
		computePos(deltaMove)
	ok

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

	// Reset transformations
	glLoadIdentity()
	// Set the camera
	gluLookAt(	x, 1.0, z,
			x+lx, 1.0,  z+lz,
			0.0, 1.0,  0.0)

// Draw ground

	glColor3f(0.9, 0.9, 0.9)
	glBegin(GL_QUADS)
		glVertex3f(-100.0, 0.0, -100.0)
		glVertex3f(-100.0, 0.0,  100.0)
		glVertex3f( 100.0, 0.0,  100.0)
		glVertex3f( 100.0, 0.0, -100.0)
	glEnd()

// Draw 36 SnowMen

	for  i = -3 to 2
		for  j = -3 to 2
			glPushMatrix()
			glTranslatef(i*10.0, 0.0, j * 10.0)
			drawSnowMan()
			glPopMatrix()
		next
	next
	glutSwapBuffers()


// -----------------------------------
//             KEYBOARD
// -----------------------------------

func processNormalKeys
	key = glutEventKey()
	xx = glutEventX()
	yy = glutEventY()

	glutSetMenu(mainMenu)
	switch key
		on 27
			glutDestroyMenu(mainMenu)
			glutDestroyMenu(fillMenu)
			glutDestroyMenu(colorMenu)
			glutDestroyMenu(shrinkMenu)
			shutdown()

		on 's'
			if not menuFlag
			  glutChangeToSubMenu(2,"Shrink",shrinkMenu)
			ok
		on 'c'
			if not menuFlag
				glutChangeToSubMenu(2,"Color",colorMenu)
			ok
	off
	if key = 27
		shutdown()
	ok


func pressKey 

	key = glutEventKey()
	xx = glutEventX()
	yy = glutEventY()

	switch key
		on GLUT_KEY_UP 
			 deltaMove = 0.5
		on GLUT_KEY_DOWN 
 			deltaMove = -0.5
	off


func releaseKey

	key = glutEventKey()

	switch key
		on GLUT_KEY_UP 
			deltaMove = 0 
		on GLUT_KEY_DOWN
			deltaMove = 0  
	off


// -----------------------------------
//             MOUSE
// -----------------------------------

func mouseMove
	xx = glutEventX()
	yy = glutEventY()

	// this will only be true when the left button is down
	if xOrigin >= 0

		// update deltaAngle
		deltaAngle = (xx - xOrigin) * 0.001

		// update camera's direction
		lx = sin(angle + deltaAngle)
		lz = -cos(angle + deltaAngle)
	ok


func mouseButton

	button = glutEventButton()
	state = glutEventState()
	xx = glutEventX()
	yy = glutEventY()

	// only start motion if the left button is pressed
	if button = GLUT_LEFT_BUTTON
		// when the button is released
		if state = GLUT_UP
			angle += deltaAngle
			xOrigin = -1
		else  
			// state = GLUT_DOWN
			xOrigin = xx
		ok
	ok


// -----------------------------------
//             MENUS
// -----------------------------------

func processMenuStatus

	status = glutEventStatus()
	xx = glutEventX()
	yy = glutEventY()

	if  status = GLUT_MENU_IN_USE
		menuFlag = 1
	else
		menuFlag = 0
	ok


func processMainMenu

	// nothing to do in here
	// all actions are for submenus


func processFillMenu

	option = glutEventValue()

	switch option

		on C_FILL
			 glPolygonMode(GL_FRONT, GL_FILL) 
		on C_LINE
			 glPolygonMode(GL_FRONT, GL_LINE) 
	off


func processShrinkMenu

	option = glutEventValue()

	switch option

		on C_SHRINK
			scale = 0.5
		on C_NORMAL
			 scale = 1.0
	off


func processColorMenu

	option = glutEventValue()

	switch option
		on C_RED 
			red = 1.0
			green = 0.0
			blue = 0.0
		on C_GREEN 
			red = 0.0
			green = 1.0
			blue = 0.0
		on C_BLUE 
			red = 0.0
			green = 0.0
			blue = 1.0
		on C_ORANGE 
			red = 1.0
			green = 0.5
			blue = 0.5
	off


func createPopupMenus

	shrinkMenu = glutCreateMenu(:processShrinkMenu)

	glutAddMenuEntry("Shrink",C_SHRINK)
	glutAddMenuEntry("NORMAL",C_NORMAL)

	fillMenu = glutCreateMenu(:processFillMenu)

	glutAddMenuEntry("Fill",C_FILL)
	glutAddMenuEntry("Line",C_LINE)

	colorMenu = glutCreateMenu(:processColorMenu)
	glutAddMenuEntry("Red",C_RED)
	glutAddMenuEntry("Blue",C_BLUE)
	glutAddMenuEntry("Green",C_GREEN)
	glutAddMenuEntry("Orange",C_ORANGE)

	mainMenu = glutCreateMenu(:processMainMenu)

	glutAddSubMenu("Polygon Mode", fillMenu)
	glutAddSubMenu("Color", colorMenu)
	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON)

	// this will allow us to know if the menu is active
	glutMenuStatusFunc(:processMenuStatus)


// -----------------------------------
//             MAIN
// -----------------------------------

func main

	// init GLUT and create window
	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowPosition(100,100)
	glutInitWindowSize(320,320)
	glutCreateWindow("RingFreeGLUT - Test 10")

	// register callbacks
	glutDisplayFunc(:renderScene)
	glutReshapeFunc(:changeSize)
	glutIdleFunc(:renderScene)

	glutIgnoreKeyRepeat(1)
	glutKeyboardFunc(:processNormalKeys)
	glutSpecialFunc(:pressKey)
	glutSpecialUpFunc(:releaseKey)

	// here are the two new functions
	glutMouseFunc(:mouseButton)
	glutMotionFunc(:mouseMove)

	// OpenGL init
	glEnable(GL_DEPTH_TEST)
	glEnable(GL_CULL_FACE)

	// init Menus
	createPopupMenus()

	// enter GLUT event processing cycle
	glutMainLoop()


