# Load SDL2 library
load "libsdl.ring"

PI = 3.14159

# Initialize SDL
SDL_Init(SDL_INIT_EVERYTHING)

# Colors
RED = [255, 0, 0, 255]
GREEN = [0, 255, 0, 255]
BLUE = [0, 0, 255, 255]
WHITE = [255, 255, 255, 255]
BLACK = [0, 0, 0, 255]
YELLOW = [255, 255, 0, 255]
CYAN = [0, 255, 255, 255]
MAGENTA = [255, 0, 255, 255]
ORANGE = [255, 165, 0, 255]
PURPLE = [128, 0, 128, 255]

# Get display information
displayRect = sdl_new_sdl_rect()
SDL_GetDisplayBounds(0, displayRect)
screenWidth = sdl_get_sdl_rect_w(displayRect)
screenHeight = sdl_get_sdl_rect_h(displayRect)
sdl_destroy_sdl_rect(displayRect)

scaleX = screenWidth / 1024.0
scaleY = screenHeight / 768.0
	
# Create window
window = SDL_CreateWindow("Advanced Shapes 3", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN)
	
# Create renderer
ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)
	
# Main loop
quit = false
frame = 0
	
# Create SDL event
myevent = sdl_new_sdl_event()

while not quit
	# Handle events
	sdl_pollevent(myevent)
	switch sdl_get_sdl_event_type(myevent)
		on SDL_QUIT
			quit = true
		on SDL_KEYDOWN
			key = SDL_GET_SDL_Event_key_keysym_sym(myevent)
			if key = SDLK_ESCAPE
				quit = true
			ok
	off
		
	# Clear screen
	setRenderColor(ren, BLACK)
	SDL_RenderClear(ren)
		
	# Draw various advanced shapes
	drawAnimatedSpiral(ren, frame)
	drawFractalTree(ren, screenWidth/2, screenHeight - 50 * scaleY, 100 * scaleX, -90, 8, frame)
	drawAnimatedPolygons(ren, frame)
	drawMandalas(ren, frame)
	drawParticleSystem(ren, frame)
	drawBezierCurves(ren, frame)
	drawAnimatedStars(ren, frame)
	drawGeometricPatterns(ren, frame)

	# Present the renderer
	SDL_RenderPresent(ren)
		
	SDL_Delay(16)
	frame++
end
	
# Cleanup
SDL_Destroy_SDL_Event(myevent)
SDL_DestroyRenderer(ren)
SDL_DestroyWindow(window)
SDL_Quit()

# Helper function to set render color
func setRenderColor(ren, color)
	SDL_SetRenderDrawColor(ren, color[1], color[2], color[3], color[4])

# Draw animated spiral
func drawAnimatedSpiral(ren, frame)
	centerX = 200 * scaleX
	centerY = 150 * scaleY
	maxRadius = 80 * scaleX
	
	for angle = 0 to 720 step 2
		radians = (angle + frame) * PI / 180
		radius = (angle / 720) * maxRadius
		
		x = centerX + radius * cos(radians)
		y = centerY + radius * sin(radians)
		
		# Color changes based on angle
		r = (sin(radians) + 1) * 127
		g = (cos(radians) + 1) * 127
		b = (sin(radians * 2) + 1) * 127
		
		SDL_SetRenderDrawColor(ren, r, g, b, 255)
		SDL_RenderDrawPoint(ren, x, y)
	next

# Draw fractal tree
func drawFractalTree(ren, x, y, length, angle, depth, frame)
	if depth = 0
		return
	ok
	
	# Calculate end point
	radians = angle * PI / 180
	endX = x + length * cos(radians)
	endY = y + length * sin(radians)
	
	# Set color based on depth
	greenValue = 255 - (depth * 30)
	SDL_SetRenderDrawColor(ren, 139, greenValue, 69, 255)
	
	# Draw branch
	SDL_RenderDrawLine(ren, x, y, endX, endY)
	
	# Recursive branches with animation
	branchAngle = 25 + sin(frame * 0.02) * 10
	newLength = length * 0.7
	
	drawFractalTree(ren, endX, endY, newLength, angle - branchAngle, depth - 1, frame)
	drawFractalTree(ren, endX, endY, newLength, angle + branchAngle, depth - 1, frame)

# Draw animated polygons
func drawAnimatedPolygons(ren, frame)
	centerX = 800 * scaleX
	centerY = 150 * scaleY

	# Draw rotating hexagon
	drawPolygon(ren, centerX, centerY, 60 * scaleX, 6, frame * 2, CYAN)

	# Draw pulsating octagon
	radius = (40 + sin(frame * 0.05) * 20) * scaleX
	drawPolygon(ren, centerX, centerY, radius, 8, -frame, MAGENTA)

# Draw regular polygon
func drawPolygon(ren, centerX, centerY, radius, sides, rotation, color)
	setRenderColor(ren, color)
	
	points = []
	
	for i = 0 to sides - 1
		angle = (360 / sides) * i + rotation
		radians = angle * PI / 180
		
		x = centerX + radius * cos(radians)
		y = centerY + radius * sin(radians)
		
		points + [x, y]
	next
	
	# Draw polygon edges
	for i = 0 to len(points) - 1
		next_i = (i + 1) % len(points)
		SDL_RenderDrawLine(ren, points[i+1][1], points[i+1][2], 
						  points[next_i+1][1], points[next_i+1][2])
	next

# Draw mandalas
func drawMandalas(ren, frame)
	centerX = 500 * scaleX
	centerY = 400 * scaleY

	# Draw multiple layers of rotating patterns
	for layer = 1 to 5
		radius = layer * 15 * scaleX
		petals = layer * 6
		rotation = frame * layer

		for i = 0 to petals - 1
			angle = (360 / petals) * i + rotation
			radians = angle * PI / 180

			x1 = centerX + radius * cos(radians)
			y1 = centerY + radius * sin(radians)

			x2 = centerX + (radius + 20 * scaleX) * cos(radians)
			y2 = centerY + (radius + 20 * scaleX) * sin(radians)
			
			# Color based on layer
			r = (layer * 50) % 255
			g = (255 - layer * 40) % 255
			b = (layer * 70) % 255
			
			SDL_SetRenderDrawColor(ren, r, g, b, 255)
			SDL_RenderDrawLine(ren, x1, y1, x2, y2)
		next
	next

# Draw particle system
func drawParticleSystem(ren, frame)
	centerX = 200 * scaleX
	centerY = 400 * scaleY

	for i = 0 to 100
		# Calculate particle position
		angle = i * 3.6 + frame
		radians = angle * PI / 180

		distance = (frame + i * 2) % (150 * scaleX)
		x = centerX + distance * cos(radians)
		y = centerY + distance * sin(radians)
		
		# Check bounds
		if x >= 0 and x < screenWidth and y >= 0 and y < screenHeight
			# Color based on distance
			intensity = 255 - (distance * 255 / 150)
			SDL_SetRenderDrawColor(ren, intensity, intensity/2, 255, 255)
			
			# Draw particle as small cross
			SDL_RenderDrawPoint(ren, x, y)
			SDL_RenderDrawPoint(ren, x+1, y)
			SDL_RenderDrawPoint(ren, x-1, y)
			SDL_RenderDrawPoint(ren, x, y+1)
			SDL_RenderDrawPoint(ren, x, y-1)
		ok
	next

# Draw Bezier curves
func drawBezierCurves(ren, frame)
	# Animated control points
	p0x = 700 * scaleX; p0y = 500 * scaleY
	p1x = 650 * scaleX + sin(frame * 0.02) * 50 * scaleX
	p1y = 400 * scaleY + cos(frame * 0.03) * 30 * scaleY
	p2x = 850 * scaleX + cos(frame * 0.025) * 40 * scaleX
	p2y = 400 * scaleY + sin(frame * 0.04) * 35 * scaleY
	p3x = 800 * scaleX; p3y = 500 * scaleY
	
	setRenderColor(ren, YELLOW)
	
	# Draw Bezier curve using parametric equation
	for t = 0 to 100
		param = t / 100.0
		
		# Cubic Bezier formula
		x = pow(1-param, 3) * p0x + 
			3 * pow(1-param, 2) * param * p1x +
			3 * (1-param) * pow(param, 2) * p2x +
			pow(param, 3) * p3x
			
		y = pow(1-param, 3) * p0y + 
			3 * pow(1-param, 2) * param * p1y +
			3 * (1-param) * pow(param, 2) * p2y +
			pow(param, 3) * p3y
			
		SDL_RenderDrawPoint(ren, x, y)
	next

# Draw animated stars
func drawAnimatedStars(ren, frame)
	centerX = 800 * scaleX
	centerY = 600 * scaleY

	# Draw multiple rotating stars
	for starNum = 0 to 2
		outerRadius = (40 + starNum * 20) * scaleX
		innerRadius = outerRadius * 0.5
		points = 5
		rotation = frame * (starNum + 1)

		# Star color
		colors = [RED, GREEN, BLUE]
		setRenderColor(ren, colors[starNum + 1])

		drawStar(ren, centerX + starNum * 100 * scaleX - 100 * scaleX, centerY,
				outerRadius, innerRadius, points, rotation)
	next

# Draw star shape
func drawStar(ren, centerX, centerY, outerRadius, innerRadius, points, rotation)
	vertices = []
	
	for i = 0 to points * 2 - 1
		angle = (360 / (points * 2)) * i + rotation
		radians = angle * PI / 180
		
		if i % 2 = 0
			radius = outerRadius
		else
			radius = innerRadius
		ok
		
		x = centerX + radius * cos(radians)
		y = centerY + radius * sin(radians)
		
		vertices + [x, y]
	next
	
	# Draw star edges
	for i = 0 to len(vertices) - 1
		next_i = (i + 1) % len(vertices)
		SDL_RenderDrawLine(ren, vertices[i+1][1], vertices[i+1][2], 
						  vertices[next_i+1][1], vertices[next_i+1][2])
	next

# Draw geometric patterns
func drawGeometricPatterns(ren, frame)
	# Draw grid-based pattern
	spacing = 30 * scaleX
	startX = 50 * scaleX
	startY = 550 * scaleY

	for row = 0 to 5
		for col = 0 to 8
			x = startX + col * spacing
			y = startY + row * spacing

			# Animated wave effect
			phase = (row + col + frame * 0.1) * 0.5
			intensity = (sin(phase) + 1) * 127

			SDL_SetRenderDrawColor(ren, intensity, 100, 255 - intensity, 255)

			# Draw diamond shape
			SDL_RenderDrawLine(ren, x, y - 10 * scaleY, x + 10 * scaleX, y)
			SDL_RenderDrawLine(ren, x + 10 * scaleX, y, x, y + 10 * scaleY)
			SDL_RenderDrawLine(ren, x, y + 10 * scaleY, x - 10 * scaleX, y)
			SDL_RenderDrawLine(ren, x - 10 * scaleX, y, x, y - 10 * scaleY)
		next
	next
