load "libsdl.ring"

PI = 3.14159

# Initialize SDL
SDL_Init(SDL_INIT_EVERYTHING)

# Get display information
displayRect = sdl_new_sdl_rect()
SDL_GetDisplayBounds(0, displayRect)
screenWidth = sdl_get_sdl_rect_w(displayRect)
screenHeight = sdl_get_sdl_rect_h(displayRect)
sdl_destroy_sdl_rect(displayRect)

win = SDL_CreateWindow("Advanced Shapes Example", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN)
scaleX = screenWidth / 640.0
scaleY = screenHeight / 480.0

ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)

# Colors
RED = sdl_new_sdl_color()
sdl_set_sdl_color_r(RED, 255)
sdl_set_sdl_color_g(RED, 0)
sdl_set_sdl_color_b(RED, 0)

GREEN = sdl_new_sdl_color()
sdl_set_sdl_color_r(GREEN, 0)
sdl_set_sdl_color_g(GREEN, 255)
sdl_set_sdl_color_b(GREEN, 0)

BLUE = sdl_new_sdl_color()
sdl_set_sdl_color_r(BLUE, 0)
sdl_set_sdl_color_g(BLUE, 0)
sdl_set_sdl_color_b(BLUE, 255)

YELLOW = sdl_new_sdl_color()
sdl_set_sdl_color_r(YELLOW, 255)
sdl_set_sdl_color_g(YELLOW, 255)
sdl_set_sdl_color_b(YELLOW, 0)

PURPLE = sdl_new_sdl_color()
sdl_set_sdl_color_r(PURPLE, 255)
sdl_set_sdl_color_g(PURPLE, 0)
sdl_set_sdl_color_b(PURPLE, 255)

WHITE = sdl_new_sdl_color()
sdl_set_sdl_color_r(WHITE, 255)
sdl_set_sdl_color_g(WHITE, 255)
sdl_set_sdl_color_b(WHITE, 255)

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
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255)
	SDL_RenderClear(ren)

	# Draw animated shapes
	centerX = 320 * scaleX
	centerY = 240 * scaleY
	radius = (100 + sin(frame * 0.05) * 50) * scaleX

	# Draw filled rectangles
	rect1 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect1, 50 * scaleX)
	sdl_set_sdl_rect_y(rect1, 50 * scaleY)
	sdl_set_sdl_rect_w(rect1, 100 * scaleX)
	sdl_set_sdl_rect_h(rect1, 100 * scaleY)

	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255)
	SDL_RenderFillRect(ren, rect1)

	# Draw rectangle outline
	rect2 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect2, 200 * scaleX)
	sdl_set_sdl_rect_y(rect2, 50 * scaleY)
	sdl_set_sdl_rect_w(rect2, 100 * scaleX)
	sdl_set_sdl_rect_h(rect2, 100 * scaleY)

	SDL_SetRenderDrawColor(ren, 0, 255, 0, 255)
	SDL_RenderDrawRect(ren, rect2)

	# Draw lines
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255)
	SDL_RenderDrawLine(ren, 350 * scaleX, 50 * scaleY, 450 * scaleX, 150 * scaleY)
	SDL_RenderDrawLine(ren, 350 * scaleX, 150 * scaleY, 450 * scaleX, 50 * scaleY)

	# Draw multiple lines (X pattern)
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255)
	SDL_RenderDrawLine(ren, 500 * scaleX, 50 * scaleY, 600 * scaleX, 150 * scaleY)
	SDL_RenderDrawLine(ren, 500 * scaleX, 150 * scaleY, 600 * scaleX, 50 * scaleY)

	# Draw points
	SDL_SetRenderDrawColor(ren, 255, 0, 255, 255)
	for i = 0 to 20
		x = (50 + i * 10) * scaleX
		y = (200 + sin(i * 0.5 + frame * 0.1) * 30) * scaleY
		SDL_RenderDrawPoint(ren, x, y)
	next

	# Draw animated circle using lines
	SDL_SetRenderDrawColor(ren, 0, 255, 255, 255)
	for angle = 0 to 360 step 5
		x1 = centerX + cos(angle * PI/180) * radius
		y1 = centerY + sin(angle * PI/180) * radius
		x2 = centerX + cos((angle+5) * PI/180) * radius
		y2 = centerY + sin((angle+5) * PI/180) * radius
		SDL_RenderDrawLine(ren, x1, y1, x2, y2)
	next

	# Draw rotating square
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255)
	squareSize = 40 * scaleX
	rotation = frame * 2
	for i = 0 to 3
		angle1 = (i * 90 + rotation) * PI/180
		angle2 = ((i+1) * 90 + rotation) * PI/180
		x1 = centerX + cos(angle1) * (150 * scaleX)
		y1 = centerY + sin(angle1) * (150 * scaleY)
		x2 = centerX + cos(angle2) * (150 * scaleX)
		y2 = centerY + sin(angle2) * (150 * scaleY)
		SDL_RenderDrawLine(ren, x1, y1, x2, y2)
	next

	# Draw grid pattern
	SDL_SetRenderDrawColor(ren, 100, 100, 100, 255)
	for x = 0 to (640 * scaleX) step (50 * scaleX)
		SDL_RenderDrawLine(ren, x, 0, x, 480 * scaleY)
	next
	for y = 0 to (480 * scaleY) step (50 * scaleY)
		SDL_RenderDrawLine(ren, 0, y, 640 * scaleX, y)
	next

	# Clean up rectangles
	sdl_destroy_sdl_rect(rect1)
	sdl_destroy_sdl_rect(rect2)

	SDL_RenderPresent(ren)
	SDL_Delay(16)
	frame++
end

# Cleanup
SDL_Destroy_SDL_Color(RED)
SDL_Destroy_SDL_Color(GREEN)
SDL_Destroy_SDL_Color(BLUE)
SDL_Destroy_SDL_Color(YELLOW)
SDL_Destroy_SDL_Color(PURPLE)
SDL_Destroy_SDL_Color(WHITE)
SDL_DestroyRenderer(ren)
SDL_DestroyWindow(win)
SDL_Quit()
