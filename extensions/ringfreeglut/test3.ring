/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
*/

load "freeglut.ring"

func main
	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowSize(320,320)
	glutInitWindowPosition(100, 10)
	glutCreateWindow("Lighthouse3D - GLUT Tutorial")
	glutDisplayFunc("renderScene()")
	glutMainLoop()

func renderScene

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

	glBegin(GL_TRIANGLES)
		glVertex3f(-0.5,-0.5,0.0)
		glVertex3f(0.5,0.0,0.0)
		glVertex3f(0.0,0.5,0.0)
	glEnd()

        glutSwapBuffers()
