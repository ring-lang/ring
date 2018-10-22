class PongPaddle
	mouseControle = true
	botControle = false
	botSpeed = 10
	playerSpeed = 10

	width = 10
	height = 80
	
	x = 10
	y = 10

	color = GE_COLOR_GREEN
	
	func Move yMouse, oGame
		if botControle = false
			// NEW method
			y = clamp(yMouse, height/2, oGame.screen_h - height/2) - height/2
		else
			for counter = 1 to botSpeed
				if Ball.y > y + height/2 and y + height < oGame.screen_h
					y++
				elseif Ball.y < y + height/2  and y > 0
					y--
				ok
			next
		ok
			
	func Draw
		gl_draw_filled_rectangle(x,y,x+width,y+height,color)
		
func clamp val, vMin, vMax
	if val > vMax
		return vMax
	elseif val < vMin
		return vMin
	else
		return val
	ok