# Author: Fuad Omari

load "libsdl.ring"
load "opengl21lib.ring"
load "stdlibcore.ring"

decimals(6)
angle=0
SDL_Init(SDL_INIT_EVERYTHING)
win = SDL_CreateWindow("Points Cloud = Mug", 100, 100, 800, 600, SDL_WINDOW_OPENGL)
mainContext = SDL_GL_CreateContext(WIN)
SDL_GL_SetSwapInterval(1)

# OpenGL Code
	lst = glGenLists(1)
	glNewList(lst, GL_COMPILE_AND_EXECUTE)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	myfile  = read("mug.txt")
	mylines = str2list(myfile)
	glBegin(GL_points)
	nMax = len(mylines)
	for i=1 to nMax
		vertArray = split(mylines[i], " ")
		x = number(vertArray[1]) / 100 
		y = number(vertArray[2]) / 100
		z = number(vertArray[3]) / 100
		glVertex3f(x, y, z)
		glColor3f(1, random(255)/255, 1) 
	next
	glEnd()
	glEndList()

myevent = sdl_new_sdl_event()
glPointSize(1)

v = 1
inc = 0.1
t1 = clock()
while true
if clock() - t1 > 10
	v += inc
	if v > 6 
		inc = -0.01 
	but v < 1
		inc = 0.01 
	ok
	t1 = clock()
ok

glMatrixMode(GL_PROJECTION)
glLoadIdentity();
glOrtho(-v, v, -2, 2.0, -30.0, 30.0)
glulookat(-3, 10, -10, 0,0,0, 0,1,0)
glPushMatrix()  	
glRotatef(angle, 0.0, 1.0, 0.0)
angle+=1
glCallList(lst)
glPopMatrix()

SDL_GL_SwapWindow(win);

thevent = sdl_pollevent(myevent)
        switch sdl_get_sdl_event_type(myevent)
                on sdl_get_sdl_quit()
                        exit
                on sdl_get_sdl_keydown()
                        Key = SDL_GET_SDL_Event_key_keysym_sym(myevent)
                        if key = 27 exit ok

        off
end

SDL_DestroyWindow(win)
SDL_Quit()
