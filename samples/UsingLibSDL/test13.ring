load "libsdl.ring"

# Initialize SDL
SDL_Init(SDL_INIT_EVERYTHING)

# Get display information
displayRect = sdl_new_sdl_rect()
SDL_GetDisplayBounds(0, displayRect)
screenWidth = sdl_get_sdl_rect_w(displayRect)
screenHeight = sdl_get_sdl_rect_h(displayRect)
sdl_destroy_sdl_rect(displayRect)

win = SDL_CreateWindow("Advanced Shapes Example", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN)
scaleX = screenWidth / 800.0
scaleY = screenHeight / 600.0

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

CYAN = sdl_new_sdl_color()
sdl_set_sdl_color_r(CYAN, 0)
sdl_set_sdl_color_g(CYAN, 255)
sdl_set_sdl_color_b(CYAN, 255)

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
	SDL_SetRenderDrawColor(ren, 20, 20, 40, 255)
	SDL_RenderClear(ren)

	centerX = (400 * scaleX)
	centerY = (300 * scaleY)

	# Draw animated star patterns
	for i = 1 to 5
		angle = (frame * 2 + i * 72) % 360
		radius = (100 + i * 20) * scaleX
		x = centerX + cos(angle * 3.14159/180) * radius
		y = centerY + sin(angle * 3.14159/180) * radius

		# Draw star points
		SDL_SetRenderDrawColor(ren, 255, 215, 0, 255)
		for r = 1 to 8
			circleRGBA(ren, x, y, r * scaleX, 255, 215, 0, 255)
		next
	next

	# Draw rotating hexagon
	SDL_SetRenderDrawColor(ren, 255, 0, 255, 255)
	hexRadius = 80 * scaleX
	rotation = frame * 3
	for i = 0 to 5
		angle1 = (i * 60 + rotation) * 3.14159/180
		angle2 = ((i+1) * 60 + rotation) * 3.14159/180
		x1 = centerX + cos(angle1) * hexRadius
		y1 = centerY + sin(angle1) * hexRadius
		x2 = centerX + cos(angle2) * hexRadius
		y2 = centerY + sin(angle2) * hexRadius
		SDL_RenderDrawLine(ren, x1, y1, x2, y2)
	next

	# Draw pulsing circles
	pulseRadius = (50 + sin(frame * 0.1) * 30) * scaleX
	SDL_SetRenderDrawColor(ren, 0, 255, 255, 255)
	for r = pulseRadius to pulseRadius + (10 * scaleX) step (2 * scaleX)
		circleRGBA(ren, centerX - (150 * scaleX), centerY, r, 0, 255, 255, 100)
	next

	# Draw bouncing squares
	squareSize = 30 * scaleX
	bounceX = centerX + (150 * scaleX) + sin(frame * 0.05) * (100 * scaleX)
	bounceY = centerY + cos(frame * 0.07) * (80 * scaleY)

	SDL_SetRenderDrawColor(ren, 255, 100, 0, 255)
	squareRect = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(squareRect, bounceX - squareSize/2)
	sdl_set_sdl_rect_y(squareRect, bounceY - squareSize/2)
	sdl_set_sdl_rect_w(squareRect, squareSize)
	sdl_set_sdl_rect_h(squareRect, squareSize)
	SDL_RenderFillRect(ren, squareRect)
	sdl_destroy_sdl_rect(squareRect)

	# Draw spiral pattern
	SDL_SetRenderDrawColor(ren, 255, 0, 128, 255)
	for angle = 0 to 720 step 5
		radius = angle * 0.5 * scaleX
		x = centerX + cos(angle * 3.14159/180) * radius
		y = centerY + sin(angle * 3.14159/180) * radius
		SDL_RenderDrawPoint(ren, x, y)
	next

	# Draw flower pattern
	SDL_SetRenderDrawColor(ren, 255, 192, 203, 255)
	for petal = 0 to 7
		for r = 20 to 60 step 10
			angle = (frame * 2 + petal * 45) * 3.14159/180
			x = centerX + cos(angle) * (r * scaleX)
			y = centerY + sin(angle) * (r * scaleX)
			circleRGBA(ren, x, y, 3 * scaleX, 255, 192, 203, 255)
		next
	next

	# Draw gradient effect (multiple circles)
	for i = 1 to 20
		alpha = 255 - i * 12
		if alpha > 0
			radius = i * 8 * scaleX
			circleRGBA(ren, 100 * scaleX, 100 * scaleY, radius, 100, 149, 237, alpha)
		ok
	next

	# Draw zigzag pattern
	SDL_SetRenderDrawColor(ren, 0, 255, 0, 255)
	x = 50 * scaleX
	y = 500 * scaleY
	direction = 1
	for i = 1 to 15
		nextX = x + (30 * scaleX)
		nextY = y + direction * (20 * scaleY)
		SDL_RenderDrawLine(ren, x, y, nextX, nextY)
		x = nextX
		y = nextY
		direction = -direction
	next

	# Draw concentric rectangles
	for i = 1 to 10
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255 - i * 25)
		rect = sdl_new_sdl_rect()
		sdl_set_sdl_rect_x(rect, centerX - i * (15 * scaleX))
		sdl_set_sdl_rect_y(rect, centerY - i * (10 * scaleY))
		sdl_set_sdl_rect_w(rect, i * (30 * scaleX))
		sdl_set_sdl_rect_h(rect, i * (20 * scaleY))
		SDL_RenderDrawRect(ren, rect)
		sdl_destroy_sdl_rect(rect)
	next

	# Draw moving wave pattern
	SDL_SetRenderDrawColor(ren, 138, 43, 226, 255)
	for x = 0 to (800 * scaleX) step (5 * scaleX)
		y = (450 * scaleY) + sin((x + frame) * 0.02) * (30 * scaleY)
		SDL_RenderDrawPoint(ren, x, y)
	next

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
SDL_Destroy_SDL_Color(CYAN)
SDL_Destroy_SDL_Color(WHITE)
SDL_DestroyRenderer(ren)
SDL_DestroyWindow(win)
SDL_Quit()
