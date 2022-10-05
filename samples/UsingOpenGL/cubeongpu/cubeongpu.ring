# ---------------------------------------------------------------------
#	2020, Ilir Liburn <iliribur@gmail.com>
#
#	This sample is based on C++ Tutorials 
#	from : 
#		http://www.songho.ca/opengl/gl_vbo.html
// ---------------------------------------------------------------------

load "freeglut.ring"
load "opengl21lib.ring"

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------

// false to send data to GPU each frame
accelerate = true	// true to accelerate by loading data on GPU once

cube = new Cube(accelerate)

start_time = 0 time = 0 frame = 0

screen_width = 1280
screen_height = 720

rotate_y=45
rotate_x=30

fps=""

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
func display

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

	// Reset transformations
	glMatrixMode(GL_MODELVIEW)
	glLoadIdentity()

	displayString(fps, 20, screen_height - 40, 8,  [255, 255, 255, 0])
	glLoadIdentity()
	glTranslatef(0, 0.1, -2)

	// Rotate when user changes rotate_x and rotate_y
	glRotatef( rotate_x, 1.0, 0.0, 0.0 )
	glRotatef( rotate_y, 0.0, 1.0, 0.0 )
 
	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST)

	cube.display()

	if accelerate = true
		displayString("Press space to send cube data to GPU each frame", 20, 50, 12,  [255, 255, 255, 0])
	else
		displayString("Press space for cube data sent to GPU only once", 20, 50, 12,  [255, 255, 255, 0])
	ok

	time = glutGet(GLUT_ELAPSED_TIME)

	if time - start_time > 1000 
		fps = "FPS: " + (frame*1000.0/(time-start_time))
		start_time = time
		frame = 0
	ok

	frame += 1
	glutSwapBuffers()


func displayString str, x, y, size, color

	if len(color) < 4 return ok

	glMatrixMode(GL_PROJECTION)	// switch to projection matrix
	glPushMatrix()	// save current projection matrix
	glLoadIdentity()	// reset projection matrix

	gluOrtho2D(0, screen_width, 0, screen_height)  // set to orthogonal projection
	glTranslated(x, y, 0)
	glScaled(1.0/(16 * 3/ size), 1.0/(16 * 3/ size), 0)

	glLineWidth(3)
	glColor4f(color[1]/255.0, color[2]/255.0, color[3]/255.0, color[4]/255.0)

	glutStrokeString(GLUT_STROKE_MONO_ROMAN, str)
	glLineWidth(1)
 
	// reset FOV, AspectRatio, NearClip, FarClip
	gluPerspective(60.0, screen_width/screen_height, 0.1, 100.0)
	glPopMatrix()
	glMatrixMode(GL_MODELVIEW)	// switch back to modelview


func reshape

	w = glutEventWidth()
	h = glutEventHeight()

	screen_width = w
	screen_height = h

	// set viewport to be the entire window
	glViewport(0, 0, w, h)

	// set perspective viewing frustum
	glMatrixMode(GL_PROJECTION)
	glLoadIdentity()
	gluPerspective(60.0, w/h, 0.1, 100.0) // FOV, AspectRatio, NearClip, FarClip


// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
func specialKeys

	key = glutEventKey()

	//  Right arrow - increase rotation by 5 degree
	switch Key

	on GLUT_KEY_RIGHT
		rotate_y -= 5
 
	//  Left arrow - decrease rotation by 5 degree
	on GLUT_KEY_LEFT
		rotate_y += 5
 
	on GLUT_KEY_UP
		rotate_x -= 5

	on GLUT_KEY_DOWN
		rotate_x += 5

	off


func regularKeys

	key = glutEventKey()

	if key = 32
		if accelerate = true accelerate = false
		else accelerate = true ok
		cube.setMode(accelerate)
	ok


func leave

	// remove lights, buffers, etc
	cube.destroy()

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
func main

	//  Initialize GLUT and process user parameters
	glutInit()

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL)
 
	// Create window
	glutInitWindowSize(screen_width, screen_height)
	glutInitWindowPosition(0, 0)
	glutCreateWindow("Awesome Cube")
 
	// Callback functions
	glutDisplayFunc(:display)
	glutIdleFunc(:display)
	glutReshapeFunc(:reshape)
	glutSpecialFunc(:specialKeys)
	glutKeyboardFunc(:regularKeys)
	glutCloseFunc(:leave)
 
	// initialize glew for extensions
	glewInit()

	// set lights, buffers, etc
	cube.setup()

	//  Pass control to GLUT for events
	glutMainLoop()

	//  Return to OS


class Cube

	vertices=nullPointer() normals=nullPointer() colors=nullPointer() indices=nullPointer()
	vboid=nullPointer() iboid=nullPointer() vbo_id=0 ibo_id=0
	vert_len=0 norm_len=0 col_len=0 ind_len=0
	verts="" norms="" colrs="" coors="" indis=""
	cube_size = 0

	C_INTSIZE = len(int2bytes(1))
	spc = space(C_INTSIZE)
	ptr = varptr(:spc, "GLvoid")

	GPU_FAST = true		// acceleration

	func init mode

		cube_vertices = [
			0.5f, 0.5f, 0.5f,  -0.5f, 0.5f, 0.5f,  -0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f,   // v0,v1,v2,v3 (front)
			0.5f, 0.5f, 0.5f,   0.5f,-0.5f, 0.5f,   0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,   // v0,v3,v4,v5 (right)
			0.5f, 0.5f, 0.5f,   0.5f, 0.5f,-0.5f,  -0.5f, 0.5f,-0.5f, -0.5f, 0.5f, 0.5f,   // v0,v5,v6,v1 (top)
			-0.5f, 0.5f, 0.5f,  -0.5f, 0.5f,-0.5f,  -0.5f,-0.5f,-0.5f, -0.5f,-0.5f, 0.5f,   // v1,v6,v7,v2 (left)
			-0.5f,-0.5f,-0.5f,   0.5f,-0.5f,-0.5f,   0.5f,-0.5f, 0.5f, -0.5f,-0.5f, 0.5f,   // v7,v4,v3,v2 (bottom)
			 0.5f,-0.5f,-0.5f,  -0.5f,-0.5f,-0.5f,  -0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f ]	// v4,v7,v6,v5 (back)

		cube_normals = [
			0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,  // v0,v1,v2,v3 (front)
			1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,  // v0,v3,v4,v5 (right)
			0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,  // v0,v5,v6,v1 (top)
			-1, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,  // v1,v6,v7,v2 (left)
			 0,-1, 0,   0,-1, 0,   0,-1, 0,   0,-1, 0,  // v7,v4,v3,v2 (bottom)
			 0, 0,-1,   0, 0,-1,   0, 0,-1,   0, 0,-1 ]	// v4,v7,v6,v5 (back)

		cube_colors = [
			1, 1, 1,   1, 1, 0,   1, 0, 0,   1, 0, 1,  // v0,v1,v2,v3 (front)
			1, 1, 1,   1, 0, 1,   0, 0, 1,   0, 1, 1,  // v0,v3,v4,v5 (right)
			1, 1, 1,   0, 1, 1,   0, 1, 0,   1, 1, 0,  // v0,v5,v6,v1 (top)
			1, 1, 0,   0, 1, 0,   0, 0, 0,   1, 0, 0,  // v1,v6,v7,v2 (left)
			0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,  // v7,v4,v3,v2 (bottom)
			0, 0, 1,   0, 0, 0,   0, 1, 0,   0, 1, 1 ]	// v4,v7,v6,v5 (back)

		// A cube has 36 indices = 6 sides * 2 tris * 3 verts
		cube_indices = [
			0, 1, 2,   2, 3, 0,    // v0-v1-v2, v2-v3-v0 (front)
			4, 5, 6,   6, 7, 4,    // v0-v3-v4, v4-v5-v0 (right)
			 8, 9,10,  10,11, 8,    // v0-v5-v6, v6-v1-v0 (top)
			12,13,14,  14,15,12,    // v1-v6-v7, v7-v2-v1 (left)
			16,17,18,  18,19,16,    // v7-v4-v3, v3-v2-v7 (bottom)
			20,21,22,  22,23,20 ]   // v4-v7-v6, v6-v5-v4 (back)

		GPU_FAST = mode
	
		verts = ""
	
		for e in cube_vertices
			verts += float2bytes(e)
		next

		vert_len = len(verts)
		cube_size = vert_len
		norms = ""

		for e in cube_normals
			norms += float2bytes(e)
		next

		norm_len = len(norms)
		cube_size += norm_len
		colrs = ""
	
		for e in cube_colors
			colrs += float2bytes(e)
		next
	
		col_len = len(colrs)
		cube_size += col_len
		coors = ""

		indis = ""

		for e in cube_indices
			indis += int2bytes(e)
		next
	
		ind_len = len(indis)


	func setup

			vertices = varptr(:verts, "GLvoid")
			normals = varptr(:norms, "GLvoid")
			colors = varptr(:colrs, "GLvoid")
			indices = varptr(:indis, "GLvoid")

			// set up light colors (ambient, diffuse, specular)
			lightKa = [ 0.3, 0.3, 0.3, 1.0 ]  // ambient light
			lightKd = [ 0.7, 0.7, 0.7, 1.0 ]  // diffuse light
			lightKs = [ 1, 1, 1, 1 ]           	// specular light

			lKa = ""
			for e in lightKa
				lKa += float2bytes(e)
			next
			lKd = ""
			for e in lightKd
				lKd += float2bytes(e)
			next
			lKs = ""
			for e in lightKs
				lKs += float2bytes(e)
			next

			glLightfv(GL_LIGHT0, GL_AMBIENT, varptr(:lKa, "GLfloat"))
			glLightfv(GL_LIGHT0, GL_DIFFUSE, varptr(:lKd, "GLfloat"))
			glLightfv(GL_LIGHT0, GL_SPECULAR, varptr(:lKs, "GLfloat"))

			// position the light
			lightPos = [ 0, 0, 1, 0 ] // directional light

			lPos = ""
			for e in lightPos
				lPos += float2bytes(e)
			next

			glLightfv(GL_LIGHT0, GL_POSITION, varptr(:lPos, "GLfloat"))
			glEnable(GL_LIGHT0)	// MUST enable each light source after configuration

			if GPU_FAST	
				// allocate space for one integer holding VBO id
				// first argument to glGenBuffers -> number of ints
				vbosp = space(C_INTSIZE) 
				vboid = varptr(:vbosp, "GLuint")
				glGenBuffers(1, vboid)
				vbo_id = bytes2int(vbosp)

				glBindBuffer(GL_ARRAY_BUFFER, vbo_id)
					glBufferData(GL_ARRAY_BUFFER, cube_size, NULL, GL_STATIC_DRAW)
				// copy vertices starting from 0 offset
					glBufferSubData(GL_ARRAY_BUFFER, 0, vert_len, vertices)
				// copy normals after vertices
					glBufferSubData(GL_ARRAY_BUFFER, vert_len, norm_len, normals)
				// copy colours after vertices+normals
					glBufferSubData(GL_ARRAY_BUFFER, vert_len+norm_len, col_len, colors)
				glBindBuffer(GL_ARRAY_BUFFER, 0)  // unbind

				// allocate space for one integer holding IBO id
				ibosp = space(C_INTSIZE) 
				iboid = varptr(:ibosp, "GLuint")
				glGenBuffers(1, iboid)
				ibo_id = bytes2int(ibosp)

					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_id)
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_len, indices, GL_STATIC_DRAW)
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0) // unbind
			ok


	func display

		if GPU_FAST	  
			glBindBuffer(GL_ARRAY_BUFFER, vbo_id)
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_id)

			glEnableClientState(GL_NORMAL_ARRAY)
			glEnableClientState(GL_COLOR_ARRAY)
			glEnableClientState(GL_VERTEX_ARRAY)

				// before draw, specify array offsets
			setPointer(ptr, vert_len)
			glNormalPointer(GL_FLOAT, 0, ptr)
			setPointer(ptr, vert_len+norm_len)
			glColorPointer(3, GL_FLOAT, 0, ptr)
			glVertexPointer(3, GL_FLOAT, 0, NULL)

			glDrawElements(GL_TRIANGLES,	// primitive type
						36,                      		// # of indices
						GL_UNSIGNED_INT, 	// data type
						NULL) 				// ptr to indices

			glDisableClientState(GL_VERTEX_ARRAY)  // disable vertex arrays
			glDisableClientState(GL_COLOR_ARRAY)
			glDisableClientState(GL_NORMAL_ARRAY)

			glBindBuffer(GL_ARRAY_BUFFER, 0) // unbind
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)

		else

			glEnableClientState(GL_NORMAL_ARRAY)
			glEnableClientState(GL_COLOR_ARRAY)
			glEnableClientState(GL_VERTEX_ARRAY)

			// before draw, specify arrays
			glNormalPointer(GL_FLOAT, 0, normals)
			glColorPointer(3, GL_FLOAT, 0, colors)
			glVertexPointer(3, GL_FLOAT, 0, vertices)

			glDrawElements(GL_TRIANGLES,	// primitive type
						36,                      		// # of indices
						GL_UNSIGNED_INT, 	// data type
						indices) 				// ptr to indices

			glDisableClientState(GL_VERTEX_ARRAY)  // disable vertex arrays
			glDisableClientState(GL_COLOR_ARRAY)
			glDisableClientState(GL_NORMAL_ARRAY)

		ok

	// to enable or disable acceleration
	func setMode mode

		GPU_FAST = mode


	func destroy

		glDisable(GL_LIGHT0)

		if GPU_FAST
			glDeletebuffers(1, vboid)
			glDeletebuffers(1, iboid)
		ok
