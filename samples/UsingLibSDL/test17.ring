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

# Create window
win = SDL_CreateWindow("Bouncing Balls in Rotating Heptagon", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN)

scaleX = screenWidth / 800.0
scaleY = screenHeight / 600.0

# Create renderer
ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)

# Ball colors
ballColors = [
	[248, 184, 98],
	[255, 0, 0],
	[0, 255, 0],
	[0, 0, 255],
	[255, 255, 0],
	[255, 0, 255],
	[0, 255, 255],
	[255, 128, 0],
	[128, 0, 255],
	[0, 128, 255],
	[255, 0, 128],
	[128, 255, 0],
	[255, 128, 128],
	[128, 255, 128],
	[128, 128, 255],
	[255, 255, 128],
	[255, 128, 255],
	[128, 255, 255],
	[192, 192, 192],
	[255, 215, 0]
]


# Main loop
running = true
frame = 0
centerX = screenWidth / 2
centerY = screenHeight / 2

# Heptagon vars
heptRadius = 200 * scaleX
ballRadius = 15 * scaleX

# Initialize 20 balls
balls = []
for i = 1 to 20

	# Position in a circle within the heptagon
	angle = (i / 20.0) * 2 * PI
	distance = heptRadius * 0.5

	x = centerX + cos(angle) * distance
	y = centerY + sin(angle) * distance
	
	# Varying velocity based on position
	vx = cos(angle + PI/2) * 5 * scaleX
	vy = sin(angle + PI/2) * 5 * scaleY
	
	# Varying angular velocity
	angVel = (i % 3 - 1) * 2
	
	# Add ball to the list
	balls + [
		:id = i,
		:x = x,
		:y = y,
		:vx = vx,
		:vy = vy,
		:angle = 0,
		:angVel = angVel,
		:colorIndex = ((i-1) % len(ballColors)) + 1
	]
next

while running
	myevent = sdl_new_sdl_event()
	while SDL_PollEvent(myevent)
		if sdl_get_sdl_event_type(myevent) = SDL_QUIT
			running = false
		but sdl_get_sdl_event_type(myevent) = SDL_KEYDOWN
			if SDL_GET_SDL_Event_key_keysym_sym(myevent) = SDLK_ESCAPE
				running = false
			ok
		ok
	end

	# Clear screen
	SDL_SetRenderDrawColor(ren, 0, 0, 20, 255)
	SDL_RenderClear(ren)

	# Heptagon rotation - 360 degrees in 5 seconds (1.2 degrees per frame)
	rotation = frame * 1.2

	# Draw rotating heptagon
	for i = 0 to 6
		angle1 = (i * (360/7) + rotation) * PI/180
		angle2 = ((i+1) * (360/7) + rotation) * PI/180

		x1 = centerX + cos(angle1) * heptRadius
		y1 = centerY + sin(angle1) * heptRadius

		x2 = centerX + cos(angle2) * heptRadius
		y2 = centerY + sin(angle2) * heptRadius

		# Lines with dynamic color
		colorShade = ((i * 42) + frame * 10) % 360

		if colorShade < 120
			r = (colorShade * 2)
			g = 0
			b = 255 - (colorShade * 2)
		but colorShade < 240
			r = 255 - (colorShade - 120) * 2
			g = (colorShade - 120) * 2
			b = 0
		else
			r = 0
			g = 255 - (colorShade - 240) * 2
			b = (colorShade - 240) * 2
		ok

		SDL_SetRenderDrawColor(ren, r, g, b, 255)
		SDL_RenderDrawLine(ren, x1, y1, x2, y2)
	next

	# Update balls
	for b in balls

		# Gravity
		# Gravity strength
		b[:vy] += 0.3 * scaleY
		
		# Air friction
		b[:vx] *= 0.995
		b[:vy] *= 0.995
		b[:angVel] *= 0.99

		# Update position
		b[:x] += b[:vx]
		b[:y] += b[:vy]
		b[:angle] += b[:angVel]

		# Check collision with heptagon sides
		collided = false

		for side = 0 to 6

			sideAngle1 = (side * (360/7) + rotation) * PI/180
			sideAngle2 = ((side+1) * (360/7) + rotation) * PI/180

			v1x = centerX + cos(sideAngle1) * heptRadius
			v1y = centerY + sin(sideAngle1) * heptRadius

			v2x = centerX + cos(sideAngle2) * heptRadius
			v2y = centerY + sin(sideAngle2) * heptRadius

			sdx = v2x - v1x
			sdy = v2y - v1y

			sideLength = sqrt(sdx * sdx + sdy * sdy)

			if sideLength > 0

				px = b[:x] - v1x
				py = b[:y] - v1y
				projection = (px * sdx + py * sdy) / (sideLength * sideLength)

				if projection < 0
					projection = 0
				but projection > 1
					projection = 1
				ok

				closex = v1x + projection * sdx
				closey = v1y + projection * sdy
				
				distToSide = sqrt((b[:x] - closex) * (b[:x] - closex) + (b[:y] - closey) * (b[:y] - closey))
				if distToSide < ballRadius
					
					# Normal vector
					nx = -sdy / sideLength
					ny = sdx / sideLength

					# Ensure normal points inside
					dotProduct = (b[:x] - centerX) * nx + (b[:y] - centerY) * ny
					if dotProduct > 0
						nx = -nx
						ny = -ny
					ok
					v_dot_n = b[:vx] * nx + b[:vy] * ny
					
					# Bounce with damping
					b[:vx] = b[:vx] - 2 * v_dot_n * nx * 0.9 
					b[:vy] = b[:vy] - 2 * v_dot_n * ny * 0.9
					b[:x] = closex + nx * ballRadius
					b[:y] = closey + ny * ballRadius
					b[:angVel] += -v_dot_n * nx * 0.5
					collided = true
					exit
				ok
			ok
		next
	next

	# Draw balls
	for b in balls
		color = ballColors[b[:colorIndex]]
		circleRGBA(ren, b[:x], b[:y], ballRadius, color[1], color[2], color[3], 255)
	next

	frame += 1.2

	# Present the renderer
	SDL_RenderPresent(ren)

	SDL_Delay(16)
end

SDL_DestroyRenderer(ren)
SDL_DestroyWindow(win)
SDL_Quit()