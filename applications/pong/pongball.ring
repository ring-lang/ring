/*
* Name: 		Ball
* Last update:	21/10/2018 - 8:42 PM
* Author: 		JustGo
*/

class pongBall
	x = 0
	y = 0
	xVel = 1
	yVel = 1
	rad = 25
	speed = 2
	stop = false
	
	func Move oGame, pPad, bPad
		if stop = true
			return false
		ok
	
		for counter = 1 to speed
		
			if y >= oGame.screen_h-rad ||  y <= rad // Bounce off
				yVel = -yVel
			ok
			
			if Touched(pPad) or TouchedBot(pPad , bPad, oGame)
				speed++
				xVel = -xVel
			ok
			
			x += xVel
			y += yVel
			
			if x < ( pPad.x + pPad.width + rad ) or x > oGame.screen_w - ( pPad.x + pPad.width + rad )
				stop = true
				return false
			ok
			
		next
		return true
		
	func Touched P
		if x = ( P.x + P.width + rad ) and y - rad < P.y + P.height and y + rad > P.y
			return true
		ok

	func TouchedBot pP, bP, oGame
		if x = oGame.screen_w - ( pP.x + pP.width + rad ) and y - rad < bP.y + bP.height and y + rad > bP.y
			return true
		ok
		return false

	func Draw
		gl_draw_filled_circle(x,y,rad,GE_COLOR_BLACK) // x, y, radius, color
