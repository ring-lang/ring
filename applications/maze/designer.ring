# The Maze Game - Level Designer		   	  
# 2019, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdlibcore.ring"
Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	load "level.ring"

	GE_SCREEN_W = 650	GE_SCREEN_H = 460

	oGame = New Game			# Create the Game Object
	{

		title = "Maze - Level Designer"
		icon  = "images/wall.jpg"

		Map {

			blockwidth = 15
			blockheight = 15

			aMap = aLevel 

			aImages = [
				"images/empty.jpg",
				"images/wall.jpg",
				"images/player.jpg",
				"images/door.jpg"
			]

			mouse = func ogame,oself,nType,aMouseList {
				if nType = GE_MOUSE_UP
					oSelf {
						mX = aMouseList[GE_MOUSE_X]
						mY = aMouseList[GE_MOUSE_Y]
						nRow = GetRow(mX,mY) 
						nCol = GetCol(mX,mY)
						aMap[nRow][nCol]++
						if aMap[nRow][nCol] = 5 
							aMap[nRow][nCol] = 1 
						ok
					}
					write("level.ring","aLevel = " + List2Code(oGame.aObjects[1].aMap))
				ok
			}

		}
	}					# Start the Events Loop	
