Load "gameengine.ring"

start_playing()					# Give Control to the Game Engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"
		text {
			x = 10	y=50
			animate = false
			size = 20
			file = "fonts/pirulen.ttf"
			text = "game development using ring is very fun!"
			color = rgb(0,0,0)	
		}
	}					# Start the Events Loop	

