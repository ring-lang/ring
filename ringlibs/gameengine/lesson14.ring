Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "My First Game"
		Object {
			x = 100 y=100 width = 200 height=200
			draw = func oGame,oSelf {
				oSelf {
					gl_draw_filled_rectangle(x, y,x+width, y+height, gl_map_rgb(0,0,255))
					gl_draw_line(x, y,x+width, y+height, gl_map_rgb(0,255,255),1)
				}
			}
			state = func oGame,oSelf {
				oSelf { 
					if x <= 550 {
						x+= 10 
					else
						x=100
					}
				}
			}
		}

	}					# Start the Events Loop	

