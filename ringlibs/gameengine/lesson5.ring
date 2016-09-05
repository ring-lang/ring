Load "gameengine.ring"

oGame = NULL					# Global Variable for our Game

start_playing()					# Give Control to the Game Engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"

		animate {
			file = "images/fire.png"
			x = 100
			y = 200
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
							frame=1    # back to first frame 
							oGame.remove(oself.nIndex)   # remove object
						ok
					ok
				}
			}
		 }		
		

	}					# Start the Events Loop	

