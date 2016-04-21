# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "gameengine.ring"

oGame = New Game

Func Main
	oGame
	{
		Image
		{
			file = "images\back3.jpg"
			x = 0
			y = 0
			nPoint = -370
			nDirection = GE_DIRECTION_DEC
		}
		Image
		{
			file = "images\back5.jpg"
			x = 400 y =400 width=100 height=100
			lAnimate=false lMove=True lScaled=True
			keypress = func oSelf,nKey {
				if nKey = KEY_SPACE
					oGame {
						Image {
							file  = "images\back4.jpg"
							x = oself.x + 30
							y = oself.y - 30
							width = 30
							height = 30
							nPoint = -30
							nStep = 20
							nDirection = GE_DIRECTION_DECVERTICAL
						}
					}
				but nKey = KEY_ESC oGame.shutdown()
				ok
			}
		}
		for g = 1 to 100
			Image
			{
				file = "images\back3.jpg"
				x = g y =g width=100 height=100
				lAnimate=true lScaled=True
				nDirection = GE_DIRECTION_RANDOM
			}
		next
	}
