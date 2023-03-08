/*
	This sample is based on C Tutorials 
	from : http://www.lighthouse3d.com/tutorials/glut-tutorial/
        Display List added by Fuad Omari
	    chocolatez@gmail.com
*/

load "freeglut.ring"
load "opengl21lib.ring"
load "stdlib.ring"

angle = 0
vertices = nullPointer()
colors = nullPointer()
verts="" 

b = 0
  
i = 1  j = 1  t=0.0  //t=3.1415

inc = 0.01 //arbitrary increment of t
axrng = 2.0
range = axrng * 3.14156 
number_of_points = range/inc
number_of_bytes = number_of_points*4 //every float = 4 bytes

vertPos = list(number_of_bytes) 
vertCol = list(number_of_bytes)
    
i = 1  j = 1
z = 0.0		
		
func main

	glutInit()
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
	glutInitWindowSize(600,600)
	glutInitWindowPosition(10, 10)
	glutCreateWindow("RingFreeGLUT - Math Art")
	glutSetWindowTitle(string(b)+ "   "+string(Number_of_Points))  
	glutDisplayFunc(:display)
	glutIdleFunc(:display)
    
	glutMainLoop()

func Calc

	x = Cos(t) - Cos(6* t)/2 + Sin(14* t)/3
	y = Cos(14* t)/3 + Sin(t)- Sin(6* t)/2 
	z = z+0.005
	b = b + 1
	vertPos[i] = x
	vertPos[i+1] = y
	vertPos[i+2] = z
	vertCol[j] = 1
	vertCol[j+1] =  0
	vertCol[j+2] = 0
		  		
	i = i+3
	j=j+3          
	  
	verts = ""
	for e in vertPos
		verts += float2bytes(e)
	next
	colrs = ""
	for e in vertCol
		colrs += float2bytes(e)
	next
	col_len = len(colrs)
	vert_len = len(verts)
		
	vertices = varptr(:verts, "GLvoid")
	colors = varptr(:colrs, "GLvoid")
	
	t += inc
		
func display

	if t <= range 
		Calc()
	ok

  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	glClearColor(1, 1, 1, 1)
	glLineWidth(3)	
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION)
	// Reset Matrix
	glLoadIdentity()
	glOrtho(-3, 3, -3, 3, -10, 30)
	glViewport(0,0,500,500)
	glPointSize(3)
	glRotatef(angle, 0.0, 1.0, 0.0)
	angle+=1
	glEnableClientState(GL_COLOR_ARRAY)
	glEnableClientState(GL_VERTEX_ARRAY)
	
	//before draw, specify arrays
	glColorPointer(3, GL_FLOAT, 0, colors)
	glVertexPointer(3, GL_FLOAT, 0, vertices)
        
	//glDrawArrays(GL_POINTS, 0, b)
	glDrawArrays(GL_line_strip, 0, b+1)
	glDisableClientState(GL_VERTEX_ARRAY)  // disable vertex arrays
	glDisableClientState(GL_COLOR_ARRAY)
		
	glutSwapBuffers()
