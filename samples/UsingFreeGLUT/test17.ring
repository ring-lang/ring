/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
        Display List added by Fuad Omari
	    chocolatez@gmail.com
*/

load "freeglut.ring"
load "opengl21lib.ring"

axrng = 1
lst = 0

func main

	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowSize(320,320)
	glutInitWindowPosition(100, 10)
	glutCreateWindow("RingFreeGLUT - Test 3")
	glutDisplayFunc(:renderScene)
	buildScene() //build scene and generate Display List
	glutMainLoop()

func buildScene

	lst = glGenLists(1)
	glNewList(lst, GL_COMPILE_AND_EXECUTE)
	glColor3f(1,1,0)
	glutSolidSphere(0.35,20,20)
	glBegin(GL_TRIANGLES)
		glColor3f(1,0,0)
		glVertex3f(-0.5,-0.5,0.0)
		glColor3f(0,1,0)
		glVertex3f(0.5,0.0,0.0)
		glColor3f(0,0,1)
		glVertex3f(0.0,0.5,0.0)		
	glEnd()
	glEndList()

func renderScene

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	glLoadIdentity()
	glPushMatrix()
	gluOrtho2D(-axrng, axrng, -axrng, axrng)
	glViewport(0,0,320,320)
	glCallList(lst)
	glPopMatrix()
	glutSwapBuffers()
