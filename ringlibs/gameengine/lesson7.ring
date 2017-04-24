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
			Move=true 	# we can move it using keyboard arrows
			Scaled=true
		}
	}					# Start the Events Loop	

