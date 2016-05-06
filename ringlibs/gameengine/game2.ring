Load "gameengine.ring"

func main

	oGame = New Game

	oGame {

		Sprite {
			file = "images/stars4.jpg"
			x = 0 y=0 width=800 height = 600 scaled = true animate = false
			keypress = func ogame,oself,nKey {
				if nkey = key_esc 
					ogame.shutdown()
				ok
			}
		}

		Map {
			aMap = [
				 	[0,0,0,1,0,0,0,0],
					[0,0,0,1,0,0,0,0],
					[0,0,0,1,0,0,0,0],
					[0,0,0,1,0,0,0,0]
				]
			aImages = ["images/t1.bmp"]
			LoadImages()
			Draw()
		}


	}
