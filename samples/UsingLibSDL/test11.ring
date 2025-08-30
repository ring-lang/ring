load "libsdl.ring"

# Initialize SDL and SDL_mixer
SDL_Init(SDL_INIT_AUDIO)
Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG)
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)

win = SDL_CreateWindow("Audio Example", 100, 100, 400, 200, SDL_WINDOW_SHOWN)
ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED)

# Load and play sound
sound = Mix_LoadWAV("sound.wav")
if sound = NULL
	? "Failed to load sound.wav"
else
	? "Playing sound..."
	Mix_PlayChannel(-1, sound, 0)
ok

# Create colors
WHITE = sdl_new_sdl_color()
sdl_set_sdl_color_r(WHITE, 255)
sdl_set_sdl_color_g(WHITE, 255)
sdl_set_sdl_color_b(WHITE, 255)

BLACK = sdl_new_sdl_color()
sdl_set_sdl_color_r(BLACK, 0)
sdl_set_sdl_color_g(BLACK, 0)
sdl_set_sdl_color_b(BLACK, 0)

# Load font for instructions
# Initialize SDL2_ttf
TTF_Init()
font = TTF_OpenFont("Roboto-Italic.ttf", 20)

# Main loop
running = true
while running
	event = sdl_new_sdl_event()
	while SDL_PollEvent(event) != 0
		if sdl_get_sdl_event_type(event) = SDL_QUIT
			running = false
		but sdl_get_sdl_event_type(event) = SDL_KEYDOWN
			key = SDL_GET_SDL_Event_key_keysym_sym(event)
			if key = SDLK_ESCAPE
				running = false
			but key = SDLK_SPACE
				Mix_PlayChannel(-1, sound, 0)
				? "Replaying sound..."
			ok
		
		but sdl_get_sdl_event_type(event) = SDL_FINGERDOWN
			Mix_PlayChannel(-1, sound, 0)
			? "Replaying sound..."
		ok
	end

	# Clear screen
	SDL_SetRenderDrawColor(ren, 50, 50, 50, 255)
	SDL_RenderClear(ren)

	# Draw instructions
	if font != NULL
		if isAndroid()
			textSurface = TTF_RenderText_Solid(font, "TOUCH to replay sound", WHITE)
		else
			textSurface = TTF_RenderText_Solid(font, "Press SPACE to replay sound", WHITE)
		ok
		textTexture = SDL_CreateTextureFromSurface(ren, textSurface)
		SDL_FreeSurface(textSurface)

		textRect = sdl_new_sdl_rect()
		sdl_set_sdl_rect_x(textRect, 50)
		sdl_set_sdl_rect_y(textRect, 80)
		sdl_set_sdl_rect_w(textRect, 300)
		sdl_set_sdl_rect_h(textRect, 20)

		SDL_RenderCopy(ren, textTexture, NULL, textRect)
		SDL_DestroyTexture(textTexture)
		sdl_destroy_sdl_rect(textRect)
	ok

	SDL_RenderPresent(ren)
	SDL_Delay(16)
end

# Cleanup
if sound != NULL
	Mix_FreeChunk(sound)
ok

if font != NULL
	TTF_CloseFont(font)
ok

SDL_Destroy_SDL_Color(WHITE)
SDL_Destroy_SDL_Color(BLACK)
SDL_DestroyRenderer(ren)
SDL_DestroyWindow(win)
Mix_CloseAudio()
Mix_Quit()
TTF_Quit()
SDL_Quit()
