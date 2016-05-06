Load "gameengine.ring"

func main

	oGame = New Game

	oGame {

		Title = "Bird Fighter"
		Sprite {
			file = "images/fbback.png"
			x = 0 y=0 width=800 height = 600 scaled = true animate = false
			keypress = func ogame,oself,nKey {
				if nkey = key_esc 
					ogame.shutdown()
				ok
			}
		}

		Map {
			blockwidth = 80
			blockheight = 80
			aMap = [
				 	[0,0,0,2,0,0,0,3,0,0,1,0,0,0,0,0,0,0,1,0,0,0],
					[0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0],
					[0,0,0,1,0,0,0,2,0,0,1,0,0,0,2,0,0,0,1,0,0,0],
					[0,0,0,1,0,0,0,1,0,0,3,0,0,0,1,0,0,0,1,0,0,0],
					[0,0,0,3,0,0,0,1,0,0,0,0,0,0,1,0,0,0,3,0,0,0],
					[0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0]
				]
			aImages = ["images/fbwall.png","images/fbwallup.png",
					"images/fbwalldown.png"]
			state = func oGame,oSelf {			
				oSelf {
					x -=  3
					if x < - 1500
						x = 0
					ok
				}
				
			}
		}


	}
