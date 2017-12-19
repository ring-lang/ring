/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
*/

load "freeglut.ring"
load "opengl21lib.ring"

// angle of rotation for the camera direction
angle=0.0
// actual vector representing the camera's direction
lx=0.0
lz=-1.0
// XZ position of the camera
x=0.0
z=5.0

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
	glColor3f(1.0, 0.5 , 0.5)
	glutSolidCone(0.08,0.5,10,2)


func changeSize
	w = glutEventWidth()
	h = glutEventHeight()

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if h = 0
		h = 1
	ok

	ratio =  w * 1.0  / h 

        // Use the Projection Matrix
	glMatrixMode(GL_PROJECTION)

        // Reset Matrix
	glLoadIdentity()


	// Set the viewport to be the entire window
	glViewport(0, 0, w, h)

	// Set the correct perspective.
	gluPerspective(45.0, ratio, 0.1, 100.0);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW)


func processNormalKeys
	key = glutEventKey()

	if key = 27
		shutdown()
	ok



func renderScene

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
	for i = -3 to 2
		for  j=-3 to 2
			glPushMatrix()
			glTranslatef(i*10.0,0,j * 10.0)			
			drawSnowMan()
			glPopMatrix()
		next
	next
	glutSwapBuffers()




func processSpecialKeys 

	key = glutEventKey()

	fraction = 0.1

	switch key 
		on GLUT_KEY_LEFT 
			angle -= 0.01
			lx = sin(angle)
			lz = -cos(angle)
		on GLUT_KEY_RIGHT 
			angle += 0.01
			lx = sin(angle)
			lz = -cos(angle)
		on GLUT_KEY_UP 
			x += lx * fraction
			z += lz * fraction
		on GLUT_KEY_DOWN 
			x -= lx * fraction
			z -= lz * fraction
	off


func main

	// init GLUT and create window

	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)

	glutInitWindowPosition(100,100)
	glutInitWindowSize(320,320)
	glutCreateWindow("RingFreeGLUT - Test 7")

	// register callbacks
	glutDisplayFunc(:renderScene)
	glutReshapeFunc(:changeSize)
	glutIdleFunc(:renderScene)
	glutKeyboardFunc(:processNormalKeys)
	glutSpecialFunc(:processSpecialKeys)

	// OpenGL init
	glEnable(GL_DEPTH_TEST)

	// enter GLUT event processing cycle
	glutMainLoop()


