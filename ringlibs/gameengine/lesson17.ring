Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	oGame = New Game			# Create the Game Object
	{
		title = "Using Buttons"
		NewButton(oGame,200,200,400,40,"My First Button",:Click)
		NewButton(oGame,200,250,400,40,"My Second Button",:Click)
		NewButton(oGame,200,300,400,40,"My Third Button",:Click)
	}

func NewButton oGame,nX,nY,nWidth,nHeight,cText,cFunc
	oGame {
		Object {
                        x = nX y=nY width = nWidth height=nHeight
			AddAttribute(self,:Text)
			AddAttribute(self,:EventCode)
			AddAttribute(self,:oFont)
			oFont = oResources.LoadFont("fonts/pirulen.ttf",20)
			Text = cText
			EventCode = cFunc
                        draw = func oGame,oSelf {
                                oSelf {
					gl_draw_filled_rectangle(x,y,x+width,y+height,gl_map_rgb(0,100,255))
					gl_draw_rectangle(x,y,x+width,y+height,gl_map_rgb(0,0,0),2)
					gl_draw_text(oFont,gl_map_rgb(0,0,0),x+width/2,y+5,1,Text)
				}
			}
			mouse = func oGame,oSelf,nType,aMouseList {
				if nType = GE_MOUSE_UP
					MouseX = aMouseList[GE_MOUSE_X]
					MouseY = aMouseList[GE_MOUSE_Y]
					oSelf {
						if MouseX >= x and MouseX <= X+270 and
						   MouseY >= y and MouseY <= Y+40		
						       call EventCode(oGame,oSelf)
						ok  
					}
				ok
			}
		}
	}
	return len(oGame.aObjects)

func Click oGame,oSelf 
	oSelf {
		 text = "Click Event"
	}
