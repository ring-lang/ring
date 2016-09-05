Load "gameengine.ring"

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"
		for x = 70 to 700 step 50
			for y = 70 to 500 step 50
				showfire(oGame,x,y)
			next
		next

	}					# Start the Events Loop	

func showfire oGame,nX,nY
	oGame {
	           animate {
			file = "images/fire.png"
			x = nX
			y = nY
			framewidth = 40
			height = 42
			nStep = 3			# Used for delay
			transparent = true
			state = func oGame,oSelf {	# Called by engine each frame
				oSelf {
					nStep--
					if nStep = 0
						nStep = 3
						if frame < 13	    # we have 12 frames in animation
							frame++   # move to next frame
						else
							frame=1
						ok
					ok
				}
			}
		 }	
	}
