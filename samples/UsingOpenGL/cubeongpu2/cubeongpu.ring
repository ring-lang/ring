# ---------------------------------------------------------------------
#	2020, Ilir Liburn <iliribur@gmail.com>
#
#	This sample is based on C++ Tutorials 
#	from : 
#		http://www.songho.ca/opengl/gl_vbo.html
// ---------------------------------------------------------------------

load "freeglut.ring"
load "opengl21lib.ring"
load "stbimage.ring"

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------

// false to send data to GPU each frame
accelerate = true	// true to accelerate by loading data on GPU once

cube = new Cube()

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
	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST)

	// Reset transformations
	glMatrixMode(GL_MODELVIEW)
	glLoadIdentity()

	displayString(fps, 20, screen_height - 40, 8,  [255, 255, 255, 0])

	glTranslatef(0, 0.1, -2)

	// Rotate when user changes rotate_x and rotate_y
	glRotatef( rotate_x, 1.0, 0.0, 0.0 )
	glRotatef( rotate_y, 0.0, 1.0, 0.0 )

	cube.display(accelerate)

	if accelerate = true
		displayString("Press space to send cube data to GPU each frame", screen_width/50, 50, 12,  [255, 255, 255, 0])
	else
		displayString("Press space for cube data sent to GPU only once", screen_width/50, 50, 12,  [255, 255, 255, 0])
	ok

	time = glutGet(GLUT_ELAPSED_TIME)

	if time - start_time >= 1000 
		fps = "FPS: " + (frame*1000.0/(time-start_time))
		start_time = time
		frame = 0
	ok

	frame += 1
	glutSwapBuffers()

// takes a color list of 4 elements: red, green, blue and alpha (transparency)
func displayString str, x, y, size, color_list

	if len(color_list) < 4 return ok

	glMatrixMode(GL_PROJECTION)	// switch to projection matrix
	glPushMatrix()	// save current projection matrix
	glLoadIdentity()	// reset projection matrix

	gluOrtho2D(0, screen_width, 0, screen_height)  // set to orthogonal projection
	glTranslated(x, y, 0)
	glScaled(1.0/(16 * 3/ size), 1.0/(16 * 3/ size), 0)

	glLineWidth(3)
	glColor4f(color_list[1]/255.0, color_list[2]/255.0, color_list[3]/255.0, color_list[4]/255.0)

	glutStrokeString(GLUT_STROKE_MONO_ROMAN, str)
	glLineWidth(1)

	// reset FOV, AspectRatio, NearClip, FarClip
	gluPerspective(60.0, screen_width/screen_height, 0.1, 100.0)
	glPopMatrix()
	glMatrixMode(GL_MODELVIEW)	// switch back to modelview


func lightsOn

	// set up light colors (ambient, diffuse, specular)
	lightKa = [ 0.3, 0.3, 0.3, 1.0 ]	// ambient light
	lightKd = [ 0.7, 0.7, 0.7, 1.0 ]	// diffuse light
	lightKs = [ 1, 1, 1, 1 ]			// specular light

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
	ok


func leave

	// remove VRAM buffers, texture, etc
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

	// set cube size, texture, colors, etc
	cube.setup(0.5, 0.5, 0.5, "grid512.bmp", true, [ // RGB color list
		 [1.0, 1.0, 1.0],	// v0 - front right up color
		 [1.0, 1.0, 0.0],	// v1 - front left up color
		 [1.0, 0.0, 0.0],	// v2 - front left down color
		 [1.0, 0.0, 1.0],	// v3 - front right down color
		 [0.0, 0.0, 1.0],	// v4 - back right down color
		 [0.0, 1.0, 1.0],	// v5 - back left down color
		 [0.0, 1.0, 0.0],	// v6 - back left up color
		 [0.0, 0.0, 0.0]		// v7 - back right up color
	])

	// activate lights
	lightsOn()

	//  Pass control to GLUT for events
	glutMainLoop()

	//  Return to OS


class Cube

	vertices=nullPointer() normals=nullPointer() colors=nullPointer() coords=nullPointer() indices=nullPointer()
	vboid=nullPointer() iboid=nullPointer() vbo_id=0 ibo_id=0
	vert_len=0 norm_len=0 col_len=0 coor_len=0 ind_len=0
	verts="" norms="" colos="" cords="" indis="" colrs=""
	cube_size=0 texture=0 wh=0.0 ht=0.0 dh=0.0

	C_INTSIZE = len(int2bytes(1))
	txc = space(C_INTSIZE)
	txptr = NULLPointer()
	ptr = NULLPointer()
	ptr[2] = "GLvoid"

	func init

		cube_vertices = [
			1.0, 1.0, 1.0,  -1.0, 1.0, 1.0,  -1.0, -1.0, 1.0,  1.0, -1.0, 1.0,	// v0,v1,v2,v3 (front)
			1.0, 1.0, 1.0,   1.0, -1.0, 1.0,   1.0, -1.0, -1.0,  1.0, 1.0, -1.0,	// v0,v3,v4,v5 (right)
			1.0, 1.0, 1.0,   1.0, 1.0, -1.0,  -1.0, 1.0, -1.0,  -1.0, 1.0, 1.0,	// v0,v5,v6,v1 (top)
			-1.0, 1.0, 1.0,  -1.0, 1.0, -1.0,  -1.0, -1.0,-1.0 ,  -1.0 ,-1.0, 1.0,	// v1,v6,v7,v2 (left)
			-1.0, -1.0, -1.0,   1.0, -1.0, -1.0,  1.0, -1.0, 1.0,  -1.0, -1.0, 1.0,	// v7,v4,v3,v2 (bottom)
			 1.0, -1.0, -1.0,  -1.0, -1.0, -1.0,  -1.0, 1.0, -1.0,  1.0, 1.0, -1.0 ]// v4,v7,v6,v5 (back)

		cube_normals = [
			0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,		// v0,v1,v2,v3 (front)
			1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,		// v0,v3,v4,v5 (right)
			0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,		// v0,v5,v6,v1 (top)
			-1.0, 0.0, 0.0,  -1.0, 0.0, 0.0,  -1.0, 0.0, 0.0,  -1.0, 0.0, 0.0,	// v1,v6,v7,v2 (left)
			 0.0,-1.0, 0.0,   0.0,-1.0, 0.0,   0.0,-1.0, 0.0,   0.0,-1.0, 0.0,	// v7,v4,v3,v2 (bottom)
			 0.0, 0.0,-1.0,   0.0, 0.0,-1.0,   0.0, 0.0,-1.0,   0.0, 0.0, -1.0]	// v4,v7,v6,v5 (back)

		cube_colors = [
			1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,		// v0,v1,v2,v3 (front)
			1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,		// v0,v3,v4,v5 (right)
			1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,		// v0,v5,v6,v1 (top)
			1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,		// v1,v6,v7,v2 (left)
			1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,		// v7,v4,v3,v2 (bottom)
			1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, 1.0 ]	// v4,v7,v6,v5 (back)

		cube_tex_coords = [
			1.0, 0.0,   0.0, 0.0,   0.0, 1.0,   1.0, 1.0,		// v0,v1,v2,v3 (front)
			0.0, 0.0,   0.0, 1.0,   1.0, 1.0,   1.0, 0.0,		// v0,v3,v4,v5 (right)
			1.0, 1.0,   1.0, 0.0,   0.0, 0.0,   0.0, 1.0,		// v0,v5,v6,v1 (top)
			1.0, 0.0,   0.0, 0.0,   0.0, 1.0,   1.0, 1.0,		// v1,v6,v7,v2 (left)
			0.0, 1.0,   1.0, 1.0,   1.0, 0.0,   0.0, 0.0,		// v7,v4,v3,v2 (bottom)
			0.0, 1.0,   1.0, 1.0,   1.0, 0.0,   0.0, 0.0 ]		// v4,v7,v6,v5 (back)

		// A cube has 36 indices = 6 sides * 2 tris * 3 verts
		cube_indices = [
			0, 1, 2,   2, 3, 0,		// v0-v1-v2, v2-v3-v0 (front)
			4, 5, 6,   6, 7, 4,		// v0-v3-v4, v4-v5-v0 (right)
			 8, 9,10,  10,11, 8,		// v0-v5-v6, v6-v1-v0 (top)
			12,13,14,  14,15,12,	// v1-v6-v7, v7-v2-v1 (left)
			16,17,18,  18,19,16,	// v7-v4-v3, v3-v2-v7 (bottom)
			20,21,22,  22,23,20 ]	// v4-v7-v6, v6-v5-v4 (back)

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
		colos = ""

		for e in cube_colors
			colos += float2bytes(e)
		next

		col_len = len(colos)
		cube_size += col_len
		cords = ""

		for e in cube_tex_coords
			cords += float2bytes(e)
		next

		coor_len = len(cords)
		cube_size += coor_len

		indis = ""

		for e in cube_indices
			indis += int2bytes(e)
		next

		ind_len = len(indis)


	// takes a color list in [[R, G, B], ...] form for each corner of the cube
	// color list can be in [R, G, B] form, single color for each corner of the cube
	// list argument can be null, making cube entirely white
	// image makes a texture, can be null for no texture
	// if lights is true, cube accepts lights, otherwise not
	// lights argument is having effect only if texture is used
	func setup width, height, depth, image, lights, color_list

		wh = width
		ht = height
		dh = depth

		texture = 0

		try
			data = stbi_load(image, :width, :height, :depth, STBI_default)
 			txptr = varptr(:txc, "GLuint")
			glGenTextures(1, txptr)
			texture = bytes2int(txc)
			glBindTexture(GL_TEXTURE_2D, texture)
			// if image contains alpha channel, otherwise defaults to RGB
			if depth = STBI_rgb_alpha
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
						GL_RGBA, GL_UNSIGNED_BYTE, varptr(:data, "GLvoid"))
			else
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
						GL_RGB, GL_UNSIGNED_BYTE, varptr(:data, "GLvoid"))
			ok
			if lights = false				
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL)
			ok
			//scale linearly when image smaller than texture
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR)
			glEnable(GL_TEXTURE_2D)

		catch
			? stbi_failure_reason()
		done


		colrs = ""

		if len(color_list) >= 8
			for e in color_list
				for i = 1 to 3
					e[i] = float2bytes(e[i])
				next
			next	
			c0 = color_list[1][1] + color_list[1][2] + color_list[1][3]
			c1 = color_list[2][1] + color_list[2][2] + color_list[2][3]
			c2 = color_list[3][1] + color_list[3][2] + color_list[3][3]
			c3 = color_list[4][1] + color_list[4][2] + color_list[4][3]
			c4 = color_list[5][1] + color_list[5][2] + color_list[5][3]
			c5 = color_list[6][1] + color_list[6][2] + color_list[6][3]
			c6 = color_list[7][1] + color_list[7][2] + color_list[7][3]
			c7 = color_list[8][1] + color_list[7][2] + color_list[8][3]
			colrs += c0 + c1 + c2 + c3	// v0,v1,v2,v3 (front)
			colrs += c0 + c3 + c4 + c5	// v0,v3,v4,v5 (right)
			colrs += c0 + c5 + c6 + c1	// v0,v5,v6,v1 (top)
			colrs += c1 + c6 + c7 + c2	// v1,v6,v7,v2 (left)
			colrs += c7 + c4 + c3 + c2	// v7,v4,v3,v2 (bottom)
			colrs += c4 + c7 + c6 + c5	// v4,v7,v6,v5 (back)
		but len(color_list) >= 3
			color1 =  float2bytes(color_list[1])
			color2 =  float2bytes(color_list[2])
			color3 =  float2bytes(color_list[3])
			for i = 1 to col_len step 9
				colrs + = color1
				colrs + = color2
				colrs + = color3
			next
		else
			color =  float2bytes(1.0)
			for i = 1 to col_len step 3
				colrs + = color
			next
		ok

		vertices = varptr(:verts, "GLvoid")
		normals = varptr(:norms, "GLvoid")
		colors = varptr(:colrs, "GLvoid")
		coords = varptr(:cords, "GLvoid")
		indices = varptr(:indis, "GLvoid")

		// allocate space for one integer holding VBO id
		// first argument to glGenBuffers -> number of ints
		vbosp = space(C_INTSIZE) 
		vboid = varptr(:vbosp, "GLuint")
		glGenBuffers(1, vboid)
		vbo_id = bytes2int(vbosp)
	
		glBindBuffer(GL_ARRAY_BUFFER, vbo_id)
			glBufferData(GL_ARRAY_BUFFER, cube_size, NULL, GL_STATIC_DRAW)
			// copy vertices starting from 0 offset to VRAM
			glBufferSubData(GL_ARRAY_BUFFER, 0, vert_len, vertices)
			// copy normals after vertices to VRAM
			glBufferSubData(GL_ARRAY_BUFFER, vert_len, norm_len, normals)
			// copy colours after vertices+normals to VRAM
			glBufferSubData(GL_ARRAY_BUFFER, vert_len+norm_len, col_len, colors)
			// copy texture coords after vertices+normals+colors
			glBufferSubData(GL_ARRAY_BUFFER, vert_len+norm_len+col_len, coor_len, coords) 
		glBindBuffer(GL_ARRAY_BUFFER, 0)  // unbind
	
		// allocate space for one integer holding IBO id
		ibosp = space(C_INTSIZE) 
		iboid = varptr(:ibosp, "GLuint")
		glGenBuffers(1, iboid)
		ibo_id = bytes2int(ibosp)
	
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_id)
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_len, indices, GL_STATIC_DRAW)
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0) // unbind
	

	// mode = false will send data to GPU on each frame, from RAM to VRAM
	// mode = true will use data sent to GPU only once, stored on VRAM
	func display mode

		glMatrixMode(GL_MODELVIEW)
		glPushMatrix()
		glScalef(wh, ht, dh)

		if mode and vbo_id > 0 // if we have buffers in VRAM

			glBindTexture(GL_TEXTURE_2D, texture)
			glBindBuffer(GL_ARRAY_BUFFER, vbo_id)
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_id)

			glEnableClientState(GL_NORMAL_ARRAY)
			glEnableClientState(GL_COLOR_ARRAY)
			glEnableClientState(GL_TEXTURE_COORD_ARRAY)
			glEnableClientState(GL_VERTEX_ARRAY)

			// before draw, specify array offsets
			setPointer(ptr, vert_len)
			glNormalPointer(GL_FLOAT, 0, ptr)
			setPointer(ptr, vert_len+norm_len)
			glColorPointer(3, GL_FLOAT, 0, ptr)
			setPointer(ptr, vert_len+norm_len+col_len)
			glTexCoordPointer(2, GL_FLOAT, 0, ptr)
			glVertexPointer(3, GL_FLOAT, 0, NULL)

			glDrawElements(GL_TRIANGLES,	// primitive type
						36,					// # of indices
						GL_UNSIGNED_INT,	// data type
						NULL)				// ptr to indices

			glDisableClientState(GL_VERTEX_ARRAY)  // disable vertex arrays
			glDisableClientState(GL_TEXTURE_COORD_ARRAY)
			glDisableClientState(GL_COLOR_ARRAY)
			glDisableClientState(GL_NORMAL_ARRAY)

			glBindTexture(GL_TEXTURE_2D, 0) // unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0)
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)

		else // use buffers in RAM
			
			glBindTexture(GL_TEXTURE_2D, texture)
			glEnableClientState(GL_NORMAL_ARRAY)
			glEnableClientState(GL_COLOR_ARRAY)
			glEnableClientState(GL_TEXTURE_COORD_ARRAY)
			glEnableClientState(GL_VERTEX_ARRAY)

			// before draw, specify arrays
			glNormalPointer(GL_FLOAT, 0, normals)
			glColorPointer(3, GL_FLOAT, 0, colors)
			glTexCoordPointer(2, GL_FLOAT, 0, coords)
			glVertexPointer(3, GL_FLOAT, 0, vertices)

			glDrawElements(GL_TRIANGLES,	// primitive type
						36,					// # of indices
						GL_UNSIGNED_INT,	// data type
						indices)				// ptr to indices

			glDisableClientState(GL_VERTEX_ARRAY)  // disable arrays
			glDisableClientState(GL_TEXTURE_COORD_ARRAY)
			glDisableClientState(GL_COLOR_ARRAY)
			glDisableClientState(GL_NORMAL_ARRAY)
			
			glBindTexture(GL_TEXTURE_2D, 0) // unbind
		ok

		glPopMatrix()


	// destroy VRAM buffers, reset RAM buffers to default
	func destroy

		glDeletebuffers(1, vboid)
		glDeletebuffers(1, iboid)

		if (texture > 0)
			glDeleteTextures(1, txptr) 
		ok

		colors = varptr(:colos, "GLvoid")
		vbo_id = 0  ibo_id = 0
		texture = 0 
