load "libsdl.ring"

# Initialize SDL and SDL_image
SDL_Init(SDL_INIT_EVERYTHING)
IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)

displayRect = sdl_new_sdl_rect()
SDL_GetDisplayBounds(0, displayRect)
screenWidth = sdl_get_sdl_rect_w(displayRect)
screenHeight = sdl_get_sdl_rect_h(displayRect)
sdl_destroy_sdl_rect(displayRect)

win = SDL_CreateWindow("Image Display Example", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN)
scaleX = screenWidth / 800.0
scaleY = screenHeight / 600.0
ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)

# Colors
WHITE = sdl_new_sdl_color()
sdl_set_sdl_color_r(WHITE, 255)
sdl_set_sdl_color_g(WHITE, 255)
sdl_set_sdl_color_b(WHITE, 255)

BLACK = sdl_new_sdl_color()
sdl_set_sdl_color_r(BLACK, 0)
sdl_set_sdl_color_g(BLACK, 0)
sdl_set_sdl_color_b(BLACK, 0)

# Load images
image1 = NULL
image2 = NULL
image3 = NULL

image1 = IMG_Load("hello2.bmp")
image2 = IMG_Load("stars.jpg")
image3 = IMG_Load("hello3.png")

# Create textures from surfaces
texture1 = NULL
texture2 = NULL
texture3 = NULL

texture1 = SDL_CreateTextureFromSurface(ren, image1)
SDL_FreeSurface(image1)

texture2 = SDL_CreateTextureFromSurface(ren, image2)
SDL_FreeSurface(image2)

texture3 = SDL_CreateTextureFromSurface(ren, image3)
SDL_FreeSurface(image3)

# Animation variables
angle1 = 0
angle2 = 0
angle3 = 0
scale1 = 1.0
scale2 = 1.0
scale3 = 1.0

# Main loop
running = true
frame = 0
while running
	event = sdl_new_sdl_event()
	while SDL_PollEvent(event) != 0
		if sdl_get_sdl_event_type(event) = SDL_QUIT
			running = false
		but sdl_get_sdl_event_type(event) = SDL_KEYDOWN
			if SDL_GET_SDL_Event_key_keysym_sym(event) = SDLK_ESCAPE
				running = false
			ok
		but sdl_get_sdl_event_type(event) = SDL_FINGERDOWN
			running = false
		ok
	end

	# Clear screen
	SDL_SetRenderDrawColor(ren, 30, 30, 50, 255)
	SDL_RenderClear(ren)

	# Update animations
	angle1 += 1
	angle2 -= 0.5
	angle3 += 2

	scale1 = 1.0 + sin(frame * 0.02) * 0.3
	scale2 = 1.0 + cos(frame * 0.03) * 0.2
	scale3 = 1.0 + sin(frame * 0.025) * 0.4

	# Draw first image (rotating)
	rect1 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect1, 100 * scaleX)
	sdl_set_sdl_rect_y(rect1, 100 * scaleY)
	sdl_set_sdl_rect_w(rect1, 150 * scale1 * scaleX)
	sdl_set_sdl_rect_h(rect1, 100 * scale1 * scaleY)

	SDL_RenderCopy(ren, texture1, NULL, rect1)
	sdl_destroy_sdl_rect(rect1)

	# Draw second image (pulsing)
	rect2 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect2, 300 * scaleX)
	sdl_set_sdl_rect_y(rect2, 150 * scaleY)
	sdl_set_sdl_rect_w(rect2, 200 * scale2 * scaleX)
	sdl_set_sdl_rect_h(rect2, 150 * scale2 * scaleY)

	SDL_RenderCopy(ren, texture2, NULL, rect2)
	sdl_destroy_sdl_rect(rect2)

	# Draw third image (spinning fast)
	rect3 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect3, 500 * scaleX)
	sdl_set_sdl_rect_y(rect3, 200 * scaleY)
	sdl_set_sdl_rect_w(rect3, 180 * scale3 * scaleX)
	sdl_set_sdl_rect_h(rect3, 120 * scale3 * scaleY)

	SDL_RenderCopy(ren, texture3, NULL, rect3)
	sdl_destroy_sdl_rect(rect3)

	# Draw decorative elements
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255)
	for i = 0 to 50
		x = (50 + i * 5) * scaleX
		y = (50 + sin((frame + i) * 0.1) * 20) * scaleY
		SDL_RenderDrawPoint(ren, x, y)
	next

	# Draw connecting lines
	SDL_SetRenderDrawColor(ren, 0, 255, 255, 255)
	SDL_RenderDrawLine(ren, 175 * scaleX, 150 * scaleY, 400 * scaleX, 225 * scaleY)

	SDL_SetRenderDrawColor(ren, 255, 0, 255, 255)
	SDL_RenderDrawLine(ren, 500 * scaleX, 225 * scaleY, 590 * scaleX, 260 * scaleY)

	SDL_RenderPresent(ren)
	SDL_Delay(16)
	frame++
end

# Cleanup
SDL_DestroyTexture(texture1)
SDL_DestroyTexture(texture2)
SDL_DestroyTexture(texture3)
SDL_Destroy_SDL_Color(WHITE)
SDL_Destroy_SDL_Color(BLACK)
SDL_DestroyRenderer(ren)
SDL_DestroyWindow(win)
IMG_Quit()
SDL_Quit()
