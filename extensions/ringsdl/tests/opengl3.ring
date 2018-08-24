Load "libsdl.ring"
Load "opengl21lib.ring"

SDL_Init(SDL_INIT_EVERYTHING)
win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL)
mainContext = SDL_GL_CreateContext(WIN)
SDL_GL_SetSwapInterval(1)
# OpenGL Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glBegin(GL_TRIANGLES)
                glVertex3f(-0.5,-0.5,0.0)
                glVertex3f(0.5,0.0,0.0)
                glVertex3f(0.0,0.5,0.0)
        glEnd()
SDL_GL_SwapWindow(win);
SDL_Delay(2000)
SDL_DestroyWindow(win)
SDL_Quit()
