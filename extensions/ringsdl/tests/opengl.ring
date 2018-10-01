Load "libsdl.ring"
Load "opengl21lib.ring"

SDL_Init(SDL_INIT_EVERYTHING)
win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL)
mainContext = SDL_GL_CreateContext(WIN);
SDL_GL_SetSwapInterval(1);
# OpenGL Code
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
SDL_GL_SwapWindow(win);
SDL_Delay(2000)
SDL_DestroyWindow(win)
SDL_Quit()
