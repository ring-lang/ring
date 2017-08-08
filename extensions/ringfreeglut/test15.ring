/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
*/

load "freeglut.ring"
load "opengl21lib.ring"

// angle of rotation for the camera direction
angle = 0.0

// actual vector representing the camera's direction
lx=0.0 lz=-1.0  ly = 0.0

// XZ position of the camera
x=0.0  z=5.0  y = 1.75

// the key states. These variables will be zero
//when no key is being presses
deltaAngle = 0.0
deltaMove = 0
xOrigin = -1

// width and height of the window
h=0
w=0

// variables to compute frames per second
frame=0
time=0
timebase=0
s=""

// variables to hold window identifiers
mainWindow=null subWindow1=null
subWindow2=null subWindow3=null

//border between subwindows
border = 6

func setProjection w1,h1

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	ratio = 1.0 * w1 / h1
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION)
	glLoadIdentity()

	// Set the viewport to be the entire window
        glViewport(0, 0, w1, h1)

	// Set the clipping volume
	gluPerspective(45,ratio,0.1,1000)
	glMatrixMode(GL_MODELVIEW)


func changeSize

	w1 = glutEventWidth()
	h1 = glutEventHeight()

	if h1 = 0
		h1 = 1
	ok

	// we're keeping these values cause we'll need them latter
	w = w1
	h = h1

	// set subwindow 1 as the active window
	glutSetWindow(subWindow1)
	// resize and reposition the sub window
	glutPositionWindow(border,border)
	glutReshapeWindow(w-2*border, h/2 - border*3/2)
	setProjection(w-2*border, h/2 - border*3/2)

	// set subwindow 2 as the active window
	glutSetWindow(subWindow2)
	// resize and reposition the sub window
	glutPositionWindow(border,(h+border)/2)
	glutReshapeWindow(w/2-border*3/2, h/2 - border*3/2)
	setProjection(w/2-border*3/2,h/2 - border*3/2)

	// set subwindow 3 as the active window
	glutSetWindow(subWindow3)
	// resize and reposition the sub window
	glutPositionWindow((w+border)/2,(h+border)/2)
	glutReshapeWindow(w/2-border*3/2,h/2 - border*3/2)
	setProjection(w/2-border*3/2,h/2 - border*3/2)


func drawSnowMan 

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
	glColor3f(1.0, 0.5, 0.5)
	glRotatef(0.0,1.0, 0.0, 0.0)
	glutSolidCone(0.08,0.5,10,2)

	glColor3f(1.0, 1.0, 1.0)

func renderBitmapString(x,y,	z,font,string) 
	glRasterPos3f(x, y,z)
	for c in string
		glutBitmapCharacter(font, ascii(c))
	next

func restorePerspectiveProjection

	glMatrixMode(GL_PROJECTION)
	// restore previous projection matrix
	glPopMatrix()

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW)

func setOrthographicProjection

	// switch to projection mode
	glMatrixMode(GL_PROJECTION)

	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix()

	// reset matrix
	glLoadIdentity()

	// set a 2D orthographic projection
	gluOrtho2D(0, w, h, 0)

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW)

func computePos deltaMove

	x += deltaMove * lx * 0.1
	z += deltaMove * lz * 0.1

// Common Render Items for all subwindows
func renderScene2

// Draw ground

	glColor3f(0.9, 0.9, 0.9)
	glBegin(GL_QUADS)
		glVertex3f(-100.0, 0.0, -100.0)
		glVertex3f(-100.0, 0.0,  100.0)
		glVertex3f( 100.0, 0.0,  100.0)
		glVertex3f( 100.0, 0.0, -100.0)
	glEnd()

// Draw 36 SnowMen
	for i=-3 to 2
		for j=-3 to 2
 			glPushMatrix()
			glTranslatef(i*10.0, 0.0, j * 10.0)
			drawSnowMan()
			glPopMatrix()
		next
	next

// Display func for main window
func renderScene
	glutSetWindow(mainWindow)
	glClear(GL_COLOR_BUFFER_BIT)
	glutSwapBuffers()

// Display func for sub window 1
func renderScenesw1

	glutSetWindow(subWindow1)

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

	glLoadIdentity()
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0,1.0,0.0)

	renderScene2()

	// display fps in the top window
 	frame++

	time=glutGet(GLUT_ELAPSED_TIME)
	if time - timebase > 1000 
		s = "RingFreeGLUT - FPS:" + ( frame*1000.0/(time-timebase))
		timebase = time
		frame = 0
	ok

	setOrthographicProjection()

	glPushMatrix()
	glLoadIdentity()
	renderBitmapString(5,30,0,GLUT_BITMAP_HELVETICA_12,s)
	glPopMatrix()

	restorePerspectiveProjection()

	glutSwapBuffers()

// Display func for sub window 2
func renderScenesw2() 

	glutSetWindow(subWindow2)

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

	glLoadIdentity()
	gluLookAt(x, y+15, z,
		      x ,y - 1,z,
			  lx,0,lz)

	// Draw red cone at the location of the main camera
	glPushMatrix()
	glColor3f(1.0,0.0,0.0)
	glTranslatef(x,y,z)
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0)
	glutSolidCone(0.2,0.8,4,4)
	glPopMatrix()

	renderScene2()

	glutSwapBuffers()

// Display func for sub window 3
func renderScenesw3

	glutSetWindow(subWindow3)

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

	glLoadIdentity()
	gluLookAt(x-lz*10 , y, z+lx*10,
		      x ,y ,z ,
			  0.0,1.0,0.0)

	// Draw red cone at the location of the main camera
	glPushMatrix()
	glColor3f(1.0,0.0,0.0)
	glTranslatef(x,y,z)
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0)
	glutSolidCone(0.2,0.8,4,4)
	glPopMatrix()

	renderScene2()

	glutSwapBuffers()

// Global idle func
func renderSceneAll

	// check for keyboard movement
	if deltaMove
		computePos(deltaMove)
		glutSetWindow(mainWindow)
		glutPostRedisplay()
	ok

	renderScene()
	renderScenesw1()
	renderScenesw2()
	renderScenesw3()



// -----------------------------------
//             KEYBOARD
// -----------------------------------

func processNormalKeys

	key = glutEventKey()

	if key = 27
		glutDestroyWindow(mainWindow)
		shutdown()
	ok


func pressKey

	key = glutEventKey()

	switch key
		on GLUT_KEY_UP 
			 deltaMove = 0.5
		on GLUT_KEY_DOWN 
			 deltaMove = -0.5
	off

	glutSetWindow(mainWindow)
	glutPostRedisplay()

func releaseKey
	key = glutEventKey()

	switch key
		case GLUT_KEY_UP
			deltaMove = 0
		case GLUT_KEY_DOWN 
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

		glutSetWindow(mainWindow)
		glutPostRedisplay()

	ok

func mouseButton 
	button = glutEventButton()
	state = glutEventState()
	xx = glutEventX()

	// only start motion if the left button is pressed
	if button = GLUT_LEFT_BUTTON
		// when the button is released
		if state = GLUT_UP
			angle += deltaAngle
			deltaAngle = 0.0
			xOrigin = -1
		else  
			// state = GLUT_DOWN
			xOrigin = xx
		ok
	ok


// -----------------------------------
//             MAIN and INIT
// -----------------------------------

func init

	glClearColor(0.0, 0.0, 0.0, 0.0)
	glEnable(GL_DEPTH_TEST)
	glEnable(GL_CULL_FACE)

	// register callbacks
	glutIgnoreKeyRepeat(1)
	glutKeyboardFunc(:processNormalKeys)
	glutSpecialFunc(:pressKey)
	glutSpecialUpFunc(:releaseKey)
	glutMouseFunc(:mouseButton)
	glutMotionFunc(:mouseMove)


func main

	// init GLUT and create main window
	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowPosition(100,100)
	glutInitWindowSize(800,800)
	mainWindow = glutCreateWindow("RingFreeGLUT - Test 15")

	// callbacks for main window
	glutDisplayFunc(:renderSceneAll)
	glutReshapeFunc(:changeSize)
	// Removing the idle function to save CPU and GPU
	#glutIdleFunc(:renderSceneAll)
	init()

	// sub windows
	subWindow1 = glutCreateSubWindow(mainWindow, border,border,w-2*border, h/2 - border*3/2)
	glutDisplayFunc(:renderScenesw1)
	init()

	subWindow2 = glutCreateSubWindow(mainWindow, border,(h+border)/2,w/2-border*3/2, h/2 - border*3/2)
	glutDisplayFunc(:renderScenesw2)
	init()

	subWindow3 = glutCreateSubWindow(mainWindow, (w+border)/2,(h+border)/2,w/2-border*3/2,h/2 - border*3/2)
	glutDisplayFunc(:renderScenesw3)
	init()

	glutDisplayFunc(:renderSceneAll)

	// enter GLUT event processing cycle
	glutMainLoop()

