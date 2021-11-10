/*
* Name: 		PongPaddle
* Last update:	22/10/2018 - 8:42 PM
* Author: 		JustGo
*/

class PongPaddle
	mouseControl = true
	botControl = false
	botSpeed = 10
	playerSpeed = 10

	width = 10
	height = 80
	
	x = 10
	y = 10

	color = GE_COLOR_GREEN
	
	func Move yMouse, oGame
		if botControl = false
			y = clamp(yMouse - height/2, 0, oGame.screen_h - height)
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
