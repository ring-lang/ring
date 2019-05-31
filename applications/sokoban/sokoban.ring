#---------------#
# Sokoban Game  #
#---------------#

# Game Data 

	aPlayer = [
		:Row = 3,
		:Col = 4
	]
	
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

	C_LEVEL_ROWSCOUNT = 10
	C_LEVEL_COLSCOUNT = 14

	C_EMPTY 	= 1
	C_WALL  	= 2
	C_PLAYER	= 3
	C_DOOR  	= 4
	C_BOX   	= 5
	C_BOXONDOOR 	= 6

	nKeyClock = clock()
	
load "gameengine.ring"        	

func main          		

	oGame = New Game      	
	{

		title = "Sokoban"

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
				"images/boxondoor.jpg"
			]

			keypress = func oGame,oSelf,nkey {
				# Avoid getting many keys in short time 
					if (clock() - nKeyClock) < clockspersecond()/3 return ok
					nKeyClock = Clock()
				Switch nkey 
					on Key_Esc
						oGame.Shutdown()
					on Key_Right
						if aPlayer[:col] < C_LEVEL_COLSCOUNT
							MoveObject(oGame,C_PLAYER,aPlayer[:row],aPlayer[:col]+1)
						ok
					on Key_Left
						if aPlayer[:col] > 1
							MoveObject(oGame,C_PLAYER,aPlayer[:row],aPlayer[:col]-1)
						ok
					on Key_Up
						if aPlayer[:row] > 1
							MoveObject(oGame,C_PLAYER,aPlayer[:row]-1,aPlayer[:col])
						ok
					on Key_Down
						if aPlayer[:row] < C_LEVEL_ROWSCOUNT
							MoveObject(oGame,C_PLAYER,aPlayer[:row]+1,aPlayer[:col])
						ok
				off
			}

		}
	}         

func MoveObject oGame,nObjectType,nNewRow,nNewCol
	? "Move Object"
	? "Object Type : " + nObjectType
	? "New Row     : " + nNewRow
	? "New Col     : " + nNewCol
