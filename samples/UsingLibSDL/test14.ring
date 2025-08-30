load "libsdl.ring"

# Initialize SDL and SDL_ttf
SDL_Init(SDL_INIT_EVERYTHING)
TTF_Init()

# Get display information
displayRect = sdl_new_sdl_rect()
SDL_GetDisplayBounds(0, displayRect)
screenWidth = sdl_get_sdl_rect_w(displayRect)
screenHeight = sdl_get_sdl_rect_h(displayRect)
sdl_destroy_sdl_rect(displayRect)

win = SDL_CreateWindow("Text Effects Example", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN)
scaleX = screenWidth / 800.0
scaleY = screenHeight / 600.0
fontSize = 32 * scaleY

ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)

# Load font
font = TTF_OpenFont("Roboto-Italic.ttf", fontSize)

# Colors
WHITE = sdl_new_sdl_color()
sdl_set_sdl_color_r(WHITE, 255)
sdl_set_sdl_color_g(WHITE, 255)
sdl_set_sdl_color_b(WHITE, 255)

BLACK = sdl_new_sdl_color()
sdl_set_sdl_color_r(BLACK, 0)
sdl_set_sdl_color_g(BLACK, 0)
sdl_set_sdl_color_b(BLACK, 0)

RED = sdl_new_sdl_color()
sdl_set_sdl_color_r(RED, 255)
sdl_set_sdl_color_g(RED, 0)
sdl_set_sdl_color_b(RED, 0)

BLUE = sdl_new_sdl_color()
sdl_set_sdl_color_r(BLUE, 0)
sdl_set_sdl_color_g(BLUE, 100)
sdl_set_sdl_color_b(BLUE, 255)

GREEN = sdl_new_sdl_color()
sdl_set_sdl_color_r(GREEN, 0)
sdl_set_sdl_color_g(GREEN, 200)
sdl_set_sdl_color_b(GREEN, 0)

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

slideRect = sdl_new_sdl_rect()
charRect = sdl_new_sdl_rect()
pulseRect = sdl_new_sdl_rect()
typingRect = sdl_new_sdl_rect()
bounceRect = sdl_new_sdl_rect()
rotRect = sdl_new_sdl_rect()
instRect = sdl_new_sdl_rect()

# Text animation data
messages = [
	"HELLO WORLD!",
	"SDL GRAPHICS",
	"TEXT EFFECTS",
	"ANIMATION DEMO",
	"RING LANGUAGE",
	"FUN WITH SDL"
]

currentMessage = 1
textOffset = 0
waveOffset = 0
rainbowOffset = 0

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
			but SDL_GET_SDL_Event_key_keysym_sym(event) = SDLK_SPACE
				currentMessage++
				if currentMessage > len(messages)
					currentMessage = 1
				ok
				textOffset = 0
			ok
		but sdl_get_sdl_event_type(event) = SDL_FINGERDOWN
			currentMessage++
			if currentMessage > len(messages)
				currentMessage = 1
			ok
			textOffset = 0
		ok
	end

	# Clear screen
	SDL_SetRenderDrawColor(ren, 20, 20, 40, 255)
	SDL_RenderClear(ren)

	if font != NULL
		message = messages[currentMessage]

		# Effect 1: Sliding text from left
		if textOffset < (400 * scaleX)
			textOffset += (3 * scaleX)
		ok

		slideSurface = TTF_RenderText_Solid(font, message, WHITE)
		slideTexture = SDL_CreateTextureFromSurface(ren, slideSurface)
		SDL_FreeSurface(slideSurface)

		sdl_set_sdl_rect_x(slideRect, textOffset - (200 * scaleX))
		sdl_set_sdl_rect_y(slideRect, 50 * scaleY)
		sdl_set_sdl_rect_w(slideRect, 200 * scaleX)
		sdl_set_sdl_rect_h(slideRect, 40 * scaleY)
		SDL_RenderCopy(ren, slideTexture, NULL, slideRect)
		SDL_DestroyTexture(slideTexture)

		# Effect 2: Wavy text
		waveOffset += 0.1
		for i = 1 to len(message)
			char = substr(message, i, 1)
			charSurface = TTF_RenderText_Solid(font, char, CYAN)
			charTexture = SDL_CreateTextureFromSurface(ren, charSurface)
			SDL_FreeSurface(charSurface)

			waveY = (120 * scaleY) + sin(waveOffset + i * 0.5) * (20 * scaleY)
			sdl_set_sdl_rect_x(charRect, (100 * scaleX) + (i - 1) * (30 * scaleX))
			sdl_set_sdl_rect_y(charRect, waveY)
			sdl_set_sdl_rect_w(charRect, 25 * scaleX)
			sdl_set_sdl_rect_h(charRect, 35 * scaleY)
			SDL_RenderCopy(ren, charTexture, NULL, charRect)
			SDL_DestroyTexture(charTexture)
		next

		# Effect 3: Rainbow text
		rainbowOffset += 0.05
		for i = 1 to len(message)
			char = substr(message, i, 1)

			# Calculate rainbow color
			hue = (rainbowOffset + i * 0.3) % 6
			if hue < 1
				r = 255
				g = hue * 255
				b = 0
			but hue < 2
				r = (2 - hue) * 255
				g = 255
				b = 0
			but hue < 3
				r = 0
				g = 255
				b = (hue - 2) * 255
			but hue < 4
				r = 0
				g = (4 - hue) * 255
				b = 255
			but hue < 5
				r = (hue - 4) * 255
				g = 0
				b = 255
			else
				r = 255
				g = 0
				b = (6 - hue) * 255
			ok

			tempColor = sdl_new_sdl_color()
			sdl_set_sdl_color_r(tempColor, r)
			sdl_set_sdl_color_g(tempColor, g)
			sdl_set_sdl_color_b(tempColor, b)
			charSurface = TTF_RenderText_Solid(font, char, tempColor)
			charTexture = SDL_CreateTextureFromSurface(ren, charSurface)
			SDL_FreeSurface(charSurface)
			SDL_Destroy_SDL_Color(tempColor)

			sdl_set_sdl_rect_x(charRect, (100 * scaleX) + (i - 1) * (30 * scaleX))
			sdl_set_sdl_rect_y(charRect, 190 * scaleY)
			sdl_set_sdl_rect_w(charRect, 25 * scaleX)
			sdl_set_sdl_rect_h(charRect, 35 * scaleY)
			SDL_RenderCopy(ren, charTexture, NULL, charRect)
			SDL_DestroyTexture(charTexture)
		next

		# Effect 4: Pulsing text
		pulseScale = 1.0 + sin(frame * 0.1) * 0.3
		pulseSurface = TTF_RenderText_Solid(font, message, YELLOW)
		pulseTexture = SDL_CreateTextureFromSurface(ren, pulseSurface)
		SDL_FreeSurface(pulseSurface)

		sdl_set_sdl_rect_x(pulseRect, 200 * scaleX)
		sdl_set_sdl_rect_y(pulseRect, 260 * scaleY)
		sdl_set_sdl_rect_w(pulseRect, (200 * scaleX) * pulseScale)
		sdl_set_sdl_rect_h(pulseRect, (40 * scaleY) * pulseScale)
		SDL_RenderCopy(ren, pulseTexture, NULL, pulseRect)
		SDL_DestroyTexture(pulseTexture)

		# Effect 5: Typing effect
		typingLength = (frame / 3) % (len(message) + 10)
		if typingLength <= len(message)
			typingText = substr(message, 1, typingLength)
			typingSurface = TTF_RenderText_Solid(font, typingText, GREEN)
			typingTexture = SDL_CreateTextureFromSurface(ren, typingSurface)
			SDL_FreeSurface(typingSurface)

			sdl_set_sdl_rect_x(typingRect, 100 * scaleX)
			sdl_set_sdl_rect_y(typingRect, 330 * scaleY)
			sdl_set_sdl_rect_w(typingRect, 300 * scaleX)
			sdl_set_sdl_rect_h(typingRect, 40 * scaleY)
			SDL_RenderCopy(ren, typingTexture, NULL, typingRect)
			SDL_DestroyTexture(typingTexture)

			# Cursor blink
			if (frame / 15) % 2 = 0
				cursorX = (100 * scaleX) + typingLength * (18 * scaleX)
				SDL_SetRenderDrawColor(ren, 0, 255, 0, 255)
				SDL_RenderDrawLine(ren, cursorX, 330 * scaleY, cursorX, 370 * scaleY)
			ok
		ok

		# Effect 6: Bouncing text
		bounceY = (400 * scaleY) + fabs(sin(frame * 0.08)) * (60 * scaleY)
		bounceSurface = TTF_RenderText_Solid(font, message, PURPLE)
		bounceTexture = SDL_CreateTextureFromSurface(ren, bounceSurface)
		SDL_FreeSurface(bounceSurface)

		sdl_set_sdl_rect_x(bounceRect, 150 * scaleX)
		sdl_set_sdl_rect_y(bounceRect, bounceY)
		sdl_set_sdl_rect_w(bounceRect, 250 * scaleX)
		sdl_set_sdl_rect_h(bounceRect, 40 * scaleY)
		SDL_RenderCopy(ren, bounceTexture, NULL, bounceRect)
		SDL_DestroyTexture(bounceTexture)

		# Effect 7: Rotating text (simulated with multiple renders)
		for angle = 0 to 30 step 10
			rotX = (400 * scaleX) + cos(angle * 3.14159/180) * (120 * scaleX)
			rotY = (490 * scaleY) + sin(angle * 3.14159/180) * (40 * scaleY)
			rotSurface = TTF_RenderText_Solid(font, message, RED)
			rotTexture = SDL_CreateTextureFromSurface(ren, rotSurface)
			SDL_FreeSurface(rotSurface)

			sdl_set_sdl_rect_x(rotRect, rotX)
			sdl_set_sdl_rect_y(rotRect, rotY)
			sdl_set_sdl_rect_w(rotRect, 180 * scaleX)
			sdl_set_sdl_rect_h(rotRect, 25 * scaleY)
			SDL_RenderCopy(ren, rotTexture, NULL, rotRect)
			SDL_DestroyTexture(rotTexture)
		next

		# Instructions
		if isAndroid()
			instSurface = TTF_RenderText_Solid(font, "TOUCH for next message", WHITE)
		else
			instSurface = TTF_RenderText_Solid(font, "Press SPACE for next message, ESC to quit", WHITE)
		ok
		instTexture = SDL_CreateTextureFromSurface(ren, instSurface)
		SDL_FreeSurface(instSurface)

		instRect = sdl_new_sdl_rect()
		sdl_set_sdl_rect_x(instRect, 100 * scaleX)
		sdl_set_sdl_rect_y(instRect, 530 * scaleY)
		sdl_set_sdl_rect_w(instRect, 400 * scaleX)
		sdl_set_sdl_rect_h(instRect, 30 * scaleY)
		SDL_RenderCopy(ren, instTexture, NULL, instRect)
		SDL_DestroyTexture(instTexture)
		sdl_destroy_sdl_rect(instRect)
	ok

	SDL_RenderPresent(ren)
	SDL_Delay(16)
	frame++
end

# Cleanup
SDL_Destroy_SDL_Color(WHITE)
SDL_Destroy_SDL_Color(BLACK)
SDL_Destroy_SDL_Color(RED)
SDL_Destroy_SDL_Color(BLUE)
SDL_Destroy_SDL_Color(GREEN)
SDL_Destroy_SDL_Color(YELLOW)
SDL_Destroy_SDL_Color(PURPLE)
SDL_Destroy_SDL_Color(CYAN)
if font != NULL
	TTF_CloseFont(font)
ok
SDL_DestroyRenderer(ren)
SDL_DestroyWindow(win)
TTF_Quit()
SDL_Quit()
