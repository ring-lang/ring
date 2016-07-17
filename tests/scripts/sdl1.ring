load "libsdl.ring"
sdl_init(SDL_INIT_EVERYTHING)
win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN)
FOR X = 1 TO 10
	SDL_Delay(200)
NEXT
SDL_DestroyWindow(win)
SDL_Quit()