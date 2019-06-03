# The Maze Game  				   	  
# 2019, Mahmoud Fayed <msfclipper@yahoo.com>

# Game Data 

	aPlayer = [ :Row = 3, :Col = 4 ]

	# Get the Level Data ---> List Called aLevel
		load "level.ring"

	# For Game Restart 
		aLevelCopy  = aLevel 
		aPlayerCopy = aPlayer 

	C_LEVEL_ROWSCOUNT = len(aLevel)
	C_LEVEL_COLSCOUNT = len(aLevel[1])

	C_EMPTY 	= 1
	C_WALL  	= 2
	C_PLAYER	= 3
	C_DOOR  	= 4

	nKeyClock = clock()
 		
load "gameengine.ring"        	

func main          		

	GE_SCREEN_W = 1280
	GE_SCREEN_H = 900

	oGame = New Game      	
	{

		title = "Maze"

		Map {

			blockwidth  = 30
			blockheight = 30

			aMap = aLevel
	
			aImages = [
				"images/empty.jpg",
				"images/wall.jpg",
				"images/player.jpg",
				"images/door.jpg"
			]

			keypress = func oGame,oSelf,nkey {
				# Avoid getting many keys in short time 
					if (clock() - nKeyClock) < clockspersecond()/10 return ok
					nKeyClock = Clock()
				Switch nkey 
					on Key_Esc
						oGame.Shutdown()
					on Key_Space 
						# Restart the Level
							aLevel = aLevelCopy     
							aPlayer = aPlayerCopy
							UpdateGameMap(oGame)
					on Key_Right
						if aPlayer[:col] < C_LEVEL_COLSCOUNT
							nRowDiff = 0   nColDiff = 1
							MoveObject(oGame,aPlayer[:row],aPlayer[:col]+1)
						ok
					on Key_Left
						if aPlayer[:col] > 1
							nRowDiff = 0   nColDiff = -1
							MoveObject(oGame,aPlayer[:row],aPlayer[:col]-1)
						ok
					on Key_Up
						if aPlayer[:row] > 1
							nRowDiff = -1   nColDiff = 0
							MoveObject(oGame,aPlayer[:row]-1,aPlayer[:col])
						ok
					on Key_Down
						if aPlayer[:row] < C_LEVEL_ROWSCOUNT
							nRowDiff = 1   nColDiff = 0
							MoveObject(oGame,aPlayer[:row]+1,aPlayer[:col])
						ok
				off
			}

		}
	}         

func MoveObject oGame,nNewRow,nNewCol
		switch aLevel[nNewRow][nNewCol] 
			on C_EMPTY
				aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
				aLevel[nNewRow][nNewCol] = C_PLAYER
				UpdateGameMap(oGame)
				aPlayer[:row] = nNewRow
				aPlayer[:col] = nNewCol
			on C_DOOR
				aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
				aLevel[nNewRow][nNewCol] = C_PLAYER
				UpdateGameMap(oGame)
				aPlayer[:row] = nNewRow
				aPlayer[:col] = nNewCol
				DisplayYouWin(oGame)
		off
	return

func UpdateGameMap oGame
	# The Map is our first object in Game Objects 
		oGame.aObjects[1].aMap = aLevel

func DisplayYouWin oGame 
	oGame {
          text {
                point = 400
                size = 30
                nStep = 9
                file = "fonts/pirulen.ttf"
                text = "You Win !!!"
                x = 500  y=10
          }
        }
