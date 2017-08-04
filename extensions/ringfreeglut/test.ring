load "freeglut.ring"

func main
	glutInit()
	glutInitDisplayMode(GLUT_SINGLE)
	glutInitWindowSize(800, 600)
	glutInitWindowPosition(100, 10)
	glutCreateWindow("Learn OpenGL")
	glutDisplayFunc("displayCode()")
	glutMainLoop()

func displaycode
