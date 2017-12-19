/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
*/

load "freeglut.ring"
load "opengl21lib.ring"


func main
	glutInit()
	glutInitDisplayMode(GLUT_SINGLE)
	glutInitWindowSize(800, 600)
	glutInitWindowPosition(100, 10)
	glutCreateWindow("RingFreeGLUT - Test 2")
	glutDisplayFunc(:displayCode)
	glutMainLoop()

func displaycode

	glClear(GL_COLOR_BUFFER_BIT)
	glColor3f(0,255,0)
	glBegin(GL_POLYGON)
        	glVertex3f(0.0, 0.0, 0.0)
	        glVertex3f(0.5, 0.0, 0.0)
	        glVertex3f(0.5, 0.5, 0.0)
	        glVertex3f(0.0, 0.5, 0.0)
	glEnd()
	glColor3f(255,0,0)
	glBegin(GL_POLYGON)
	        glVertex3f(0.0, 0.0, 0.0)
        	glVertex3f(0.5, 0.0, 0.0)
	        glVertex3f(-0.5,- 1, 0.0)
        	glVertex3f(0.0, -1, 0.0)
	glEnd()
	glColor3f(0,0,255)
	glBegin(GL_POLYGON)
	        glVertex3f(0.0, 0.0, 0.0)
        	glVertex3f(-0.5, 0.0, 0.0)
	        glVertex3f(-0.5,- 0.5, 0.0)
        	glVertex3f(0.0, -0.5, 0.0)
	glEnd()

	glFlush()
