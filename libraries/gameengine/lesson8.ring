Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"
		sprite
		{
			type = GE_TYPE_PLAYER		# Just for our usage
			x=400 y=400 width=100 height=100
			file = "images/player.png"	
			transparent = true			
			Animate=false 
			Move=false			# Custom Movement
			Scaled=true
			keypress = func oGame,oSelf,nKey {
				oSelf { 
					Switch nKey	
					on KEY_LEFT	
						x -= 10			
					on KEY_RIGHT
						x += 10
					on KEY_UP
						y -= 10
					on KEY_DOWN
						y += 10
					off
				}
			}
		}
	}					# Start the Events Loop	

