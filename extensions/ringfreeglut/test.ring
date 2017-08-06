/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
*/

load "freeglut.ring"

func main
	glutInit()
	glutInitDisplayMode(GLUT_SINGLE)
	glutInitWindowSize(800, 600)
	glutInitWindowPosition(100, 10)
	glutCreateWindow("RingFreeGLUT - Test 1")
	glutDisplayFunc(:displayCode)
	glutMainLoop()

func displaycode
