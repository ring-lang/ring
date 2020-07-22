Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "Move sprite using the mouse!"
		sprite
		{
			type = GE_TYPE_PLAYER		# Just for our usage
			x=400 y=400 width=100 height=100
			file = "images/player.png"	
			transparent = true			
			Animate=false 
			Move=false			# Custom Movement
			Scaled=true
			mouse = func oGame,oSelf,nType,aMouseList {
				oSelf {
					x = aMouseList[GE_MOUSE_X]
					y = aMouseList[GE_MOUSE_Y]
				}
			}
		}
	}					# Start the Events Loop	

