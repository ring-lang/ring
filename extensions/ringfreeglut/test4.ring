load "freeglut.ring"

func main

	// init GLUT and create window
	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowPosition(100,100)
	glutInitWindowSize(320,320)
	glutCreateWindow("Lighthouse3D - GLUT Tutorial")

	glutDisplayFunc("renderScene()")
	glutReshapeFunc("changeSize()")

	glutMainLoop()

func renderScene

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

	glBegin(GL_TRIANGLES)
		glVertex3f(-2,-2,-5.0)
		glVertex3f(2,0.0,-5.0)
		glVertex3f(0.0,2,-5.0)
	glEnd()

	glutSwapBuffers()

func changesize

	h = glutReshapeHeight()
	w = glutReshapeWidth()

		// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h = 0)
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
	gluPerspective(45,ratio,1,100)

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW)
