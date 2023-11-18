#--------------------------------------------------#
# Sokoban Game  				   #
# 2019, Mahmoud Fayed <msfclipper@yahoo.com>	   #
#--------------------------------------------------#

# Game Data 

	aPlayer = [ :Row = 3, :Col = 4 ]
	
	aLevel = [
		[1,1,1,2,2,2,2,2,1,1,1,1,1,1],
		[1,2,2,2,1,1,1,2,1,1,1,1,1,1],
		[1,2,4,3,5,1,1,2,1,1,1,1,1,1],
		[1,2,2,2,1,5,4,2,1,1,1,1,1,1],
		[1,2,4,2,2,5,1,2,1,1,1,1,1,1],
		[1,2,1,2,1,4,1,2,2,1,1,1,1,1],
		[1,2,5,1,6,5,5,4,2,1,1,1,1,1],
		[1,2,1,1,1,4,1,1,2,1,1,1,1,1],
		[1,2,2,2,2,2,2,2,2,1,1,1,1,1],
		[1,1,1,1,1,1,1,1,1,1,1,1,1,1]
	]

	# For Game Restart 
		aLevelCopy  = aLevel 
		aPlayerCopy = aPlayer 

	C_LEVEL_ROWSCOUNT = 10
	C_LEVEL_COLSCOUNT = 14

	C_EMPTY 	= 1
	C_WALL  	= 2
	C_PLAYER	= 3
	C_DOOR  	= 4
	C_BOX   	= 5
	C_BOXONDOOR 	= 6
	C_PLAYERONDOOR  = 7

	nKeyClock = clock()

	# Will be used when moving a Box
		aCurrentBox = [ :Row = 0, :Col = 0 ]
		nRowDiff = 0
		nColDiff = 0

	# When the player win 
		lPlayerWin = False
		
load "gameengine.ring"        	

func main          		

	oGame = New Game      	
	{

		title = "Sokoban"
		icon  = "images/player.jpg"

		Map {

			blockwidth  = 60
			blockheight = 60

			aMap = aLevel
	
			aImages = [
				"images/empty.jpg",
				"images/wall.jpg",
				"images/player.jpg",
				"images/door.jpg",
				"images/box.jpg",
				"images/boxondoor.jpg",
				"images/player.jpg"	# Player on Door 
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
							MoveObject(oGame,PlayerType(),aPlayer[:row],aPlayer[:col]+1)
						ok
					on Key_Left
						if aPlayer[:col] > 1
							nRowDiff = 0   nColDiff = -1
							MoveObject(oGame,PlayerType(),aPlayer[:row],aPlayer[:col]-1)
						ok
					on Key_Up
						if aPlayer[:row] > 1
							nRowDiff = -1   nColDiff = 0
							MoveObject(oGame,PlayerType(),aPlayer[:row]-1,aPlayer[:col])
						ok
					on Key_Down
						if aPlayer[:row] < C_LEVEL_ROWSCOUNT
							nRowDiff = 1   nColDiff = 0
							MoveObject(oGame,PlayerType(),aPlayer[:row]+1,aPlayer[:col])
						ok
				off
				if lPlayerWin = False
					if CheckWin()
						lPlayerWin = True 
						DisplayYouWin(oGame)
					ok
				ok
			}

		}
	}         

func MoveObject oGame,nObjectType,nNewRow,nNewCol
	lMove = False 
	switch nObjectType
		on  C_PLAYER
			switch aLevel[nNewRow][nNewCol] 
				on C_EMPTY
					aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
					aLevel[nNewRow][nNewCol] = C_PLAYER
					UpdateGameMap(oGame)
					aPlayer[:row] = nNewRow
					aPlayer[:col] = nNewCol
					lMove = True
				on C_DOOR
					aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
					aLevel[nNewRow][nNewCol] = C_PLAYERONDOOR
					UpdateGameMap(oGame)
					aPlayer[:row] = nNewRow
					aPlayer[:col] = nNewCol
					lMove = True
				on C_BOX
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOX,nNewRow+nRowDiff,nNewCol+nColDiff)
						aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
						aLevel[nNewRow][nNewCol] = C_PLAYER
						UpdateGameMap(oGame)
						aPlayer[:row] = nNewRow
						aPlayer[:col] = nNewCol
						lMove = True
					ok
				on C_BOXONDOOR
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOXONDOOR,nNewRow+nRowDiff,nNewCol+nColDiff)
						aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
						aLevel[nNewRow][nNewCol] = C_PLAYERONDOOR
						UpdateGameMap(oGame)
						aPlayer[:row] = nNewRow
						aPlayer[:col] = nNewCol
						lMove = True
					ok
			off
		on  C_PLAYERONDOOR
			switch aLevel[nNewRow][nNewCol] 
				on C_EMPTY
					aLevel[aPlayer[:row]][aPlayer[:col]] = C_DOOR
					aLevel[nNewRow][nNewCol] = C_PLAYER
					UpdateGameMap(oGame)
					aPlayer[:row] = nNewRow
					aPlayer[:col] = nNewCol
					lMove = True
				on C_DOOR
					aLevel[aPlayer[:row]][aPlayer[:col]] = C_DOOR
					aLevel[nNewRow][nNewCol] = C_PLAYERONDOOR
					UpdateGameMap(oGame)
					aPlayer[:row] = nNewRow
					aPlayer[:col] = nNewCol
					lMove = True
				on C_BOX
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOX,nNewRow+nRowDiff,nNewCol+nColDiff)
						aLevel[aPlayer[:row]][aPlayer[:col]] = C_DOOR
						aLevel[nNewRow][nNewCol] = C_PLAYER
						UpdateGameMap(oGame)
						aPlayer[:row] = nNewRow
						aPlayer[:col] = nNewCol
						lMove = True
					ok
				on C_BOXONDOOR
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOXONDOOR,nNewRow+nRowDiff,nNewCol+nColDiff)
						aLevel[aPlayer[:row]][aPlayer[:col]] = C_DOOR
						aLevel[nNewRow][nNewCol] = C_PLAYER
						UpdateGameMap(oGame)
						aPlayer[:row] = nNewRow
						aPlayer[:col] = nNewCol
						lMove = True
					ok
			off
		on  C_BOX
			switch aLevel[nNewRow][nNewCol] 
				on C_EMPTY
					aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_EMPTY
					aLevel[nNewRow][nNewCol] = C_BOX
					UpdateGameMap(oGame)
					lMove = True
				on C_DOOR
					aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_EMPTY
					aLevel[nNewRow][nNewCol] = C_BOXONDOOR
					UpdateGameMap(oGame)
					lMove = True
				on C_BOX
					aOldBox = aCurrentBox
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOX,nNewRow+nRowDiff,nNewCol+nColDiff)
						aCurrentBox = aOldBox
						aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_EMPTY
						aLevel[nNewRow][nNewCol] = C_BOX
						UpdateGameMap(oGame)
						lMove = True
					ok
				on C_BOXONDOOR
					aOldBox = aCurrentBox
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOXONDOOR,nNewRow+nRowDiff,nNewCol+nColDiff)
						aCurrentBox = aOldBox
						aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_EMPTY
						aLevel[nNewRow][nNewCol] = C_BOXONDOOR
						UpdateGameMap(oGame)
						lMove = True
					ok
			off
		on  C_BOXONDOOR
			switch aLevel[nNewRow][nNewCol] 
				on C_EMPTY
					aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_DOOR
					aLevel[nNewRow][nNewCol] = C_BOX
					UpdateGameMap(oGame)
					lMove = True
				on C_DOOR
					aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_DOOR
					aLevel[nNewRow][nNewCol] = C_BOXONDOOR
					UpdateGameMap(oGame)
					lMove = True
				on C_BOX
					aOldBox = aCurrentBox
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOX,nNewRow+nRowDiff,nNewCol+nColDiff)
						aCurrentBox = aOldBox
						aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_DOOR
						aLevel[nNewRow][nNewCol] = C_BOX
						UpdateGameMap(oGame)
						lMove = True
					ok
				on C_BOXONDOOR
					aOldBox = aCurrentBox
					aCurrentBox[:row] = nNewRow
					aCurrentBox[:col] = nNewCol
					if MoveObject(oGame,C_BOXONDOOR,nNewRow+nRowDiff,nNewCol+nColDiff)
						aCurrentBox = aOldBox
						aLevel[aCurrentBox[:row]][aCurrentBox[:col]] = C_DOOR
						aLevel[nNewRow][nNewCol] = C_BOXONDOOR
						UpdateGameMap(oGame)
						lMove = True
					ok

			off
	off
	return lMove

func UpdateGameMap oGame
	# The Map is our first object in Game Objects 
		oGame.aObjects[1].aMap = aLevel

func PlayerType 
	# It could be (Player) or (Player on door)
		return aLevel[aPlayer[:row]][aPlayer[:col]]

func CheckWin 
	for aRow in aLevel
		if find(aRow,C_DOOR) or find(aRow,C_PLAYERONDOOR)
			return False
		ok
	next 
	return True

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
