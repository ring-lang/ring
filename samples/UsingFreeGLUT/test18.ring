/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
	plotting color points and adding Display List by Fuad Omari
	chocolatez@gmail.com
*/

load "freeglut.ring"
load "opengl21lib.ring"

axrng = 10
lst = 0

func main

	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowSize(320,320)
	glutInitWindowPosition(100, 10)
	glutCreateWindow("RingFreeGLUT - with display list")
	glutDisplayFunc(:renderScene)
	buildScene() //build scene and generate Display List
	glutMainLoop()


func buildScene

	r = 0.0 
    	stp = 0.05  x = 0.0  y = 0.0
    	lst = glGenLists(1)
    	glNewList(lst, GL_COMPILE_AND_EXECUTE)
		x = -axrng
		
			While x <= axrng
				x = x + stp
				y = -axrng
				While y <= axrng
					y = y + stp
	                r = Cos(x) + Sin(y)
					red = Cos(y*r)
					green = Cos(x*y*r)
					blue = Sin(r*x)
					glBegin(GL_POINTS)
						glColor3f(red,green,blue)
						glVertex3f(x,y,0.0)

					glEnd()
				end
			end

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