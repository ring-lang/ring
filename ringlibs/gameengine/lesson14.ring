Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"
		Object {
			x = 0 y=300 width = 200 height=200
			draw = func oGame,oSelf {
				oSelf {
					for t = 1 to 210
						gl_draw_circle(x,y,t,gl_map_rgb(t*random(255),t*2,t*3),1)
					next
				}
			}
			state = func oGame,oSelf {
				oSelf { 
					if x <= 800 
						x+= 3 
					else
						x=0
					ok
				}
			}
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

