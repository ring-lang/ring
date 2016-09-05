Load "gameengine.ring"

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
			color = rgb(0,0,0)				# Color = black	
		}
		text {
			x = 10	y=150
			# Animation Part =====================================
			animate = true					# Use Animation
			direction = GE_DIRECTION_INCVERTICAL		# Increase y
			point = 400				  	# Continue until y=400
			nStep = 3					# Each time y+= 3
			#===============================================
			size = 20
			file = "fonts/pirulen.ttf"
			text = "welcome to the real world!"
			color = rgb(0,0,255)				# Color = Blue 	
		}
		Sound {							# Play Sound
			file = "sound/music1.wav"			# Sound File Name
		}		
	}					# Start the Events Loop	

