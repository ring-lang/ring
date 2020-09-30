Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"

		animate {

			file = "images/fbbird.png"
			x = 10
			y = 10
			framewidth = 20
			scaled = true
			height = 50
			width = 50
			nStep = 3
			transparent = true

			state = func oGame,oSelf {
				oSelf {

					# Animation
						nStep--
						if nStep = 0
							nStep = 3
							if frame < 3
								frame++
							else
								frame=1
							ok
						ok

					# Move Down
						y += 3
						if y > 550 y=550 ok

				}

			}

			keypress = func ogame,oself,nKey {
				oself {
					if nkey = key_space
						y -= 55
						if y<=0 y=0 ok
					ok
				}
			}

			mouse = func ogame,oself,nType,aMouseList {
				if nType = GE_MOUSE_UP
					cFunc = oself.keypress
					call cFunc(oGame,oSelf,Key_Space)
				ok
			}
		}
	}					# Start the Events Loop	

