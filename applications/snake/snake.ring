# The Snake Game  				   	  
# 2019, Mahmoud Fayed <msfclipper@yahoo.com>

# Game Data 

	# Map Size
		C_LEVEL_ROWSCOUNT = 20
		C_LEVEL_COLSCOUNT = 27

	# Map Items
		C_EMPTY 	= 1
		C_WALL  	= 2
		C_DOOR  	= 3
	
	# The Map Data 
		aLevel = list(C_LEVEL_ROWSCOUNT)
		for nRow = 1 to C_LEVEL_ROWSCOUNT
			aLevel[nRow] = list(C_LEVEL_COLSCOUNT)
			for nCol = 1 to C_LEVEL_COLSCOUNT
				aLevel[nRow][nCol] = C_EMPTY
			next
		next

	# Add the Snake
		aSnake 		= [ [3,3] , [3,4] , [3,5] ]
		aLevel[3][3] 	= C_WALL
		aLevel[3][4] 	= C_WALL
		aLevel[3][5] 	= C_WALL
		cDirection 	= :Right

	# Create the first Door 
		NewDoor()

	# For Game Restart 
		aLevelCopy  	= aLevel 

	# Timers 
		nKeyClock 	= clock()
		nMoveClock 	= clock() 		

	# Game Over
		lGameOver 	= False

	# Speed 
		nKeyboardSpeed  = 10
		nMovementSpeed  = 15

load "gameengine.ring"        	

func main          		

	GE_SCREEN_W = 800
	GE_SCREEN_H = 600

	oGame = New Game      	
	{

		title = "Snake"

		Map {

			blockwidth  = 30
			blockheight = 30

			aMap = aLevel
	
			aImages = [
				"images/empty.jpg",
				"images/wall.jpg",
				"images/door.jpg"
			]

			keypress = func oGame,oSelf,nkey {
				if lGameOver return ok
				# Avoid getting many keys in short time 
					if (clock() - nKeyClock) < clockspersecond()/nKeyboardSpeed return ok
					nKeyClock = Clock()
				Switch nkey 
					on Key_Esc
						oGame.Shutdown()
					on Key_Space 
						Restart(oGame)
					on Key_Right
						if cDirection = :UP or cDirection = :Down
							cDirection = :Right
						ok
					on Key_Left
						if cDirection = :UP or cDirection = :Down
							cDirection = :Left
						ok
					on Key_Up
						if cDirection = :Left or cDirection = :Right
							cDirection = :Up
						ok
					on Key_Down
						if cDirection = :Left or cDirection = :Right
							cDirection = :Down
						ok
				off
			}

			state = func oGame,oSelf {
				if clock() - nMoveClock >= clockspersecond()/nMovementSpeed
					nMoveClock = clock()
					MoveSnake(oGame,oSelf)
				ok 
			}

		}
	}         

func MoveSnake oGame,oMap
	if lGameOver return ok
	aHead = aSnake[len(aSnake)]
	switch cDirection
		on :right 
			if aHead[2] = C_LEVEL_COLSCOUNT	 DisplayGameOver(oGame) return ok		
			aHead[2]++
		on :left 
			if aHead[2] = 1	 DisplayGameOver(oGame) return ok		
			aHead[2]--
		on :up
			if aHead[1] = 1	 DisplayGameOver(oGame) return ok		
			aHead[1]--
		on :down
			if aHead[1] = C_LEVEL_ROWSCOUNT	 DisplayGameOver(oGame) return ok		
			aHead[1]++
	off
	if aLevel[aHead[1]][aHead[2]] = C_EMPTY
		HideCell(aSnake[1])
		del(aSnake,1)
	but aLevel[aHead[1]][aHead[2]] = C_DOOR
		NewDoor()
	else  
		DisplayGameOver(oGame) 
		return
	ok
	aSnake + aHead
	ShowCell(aHead)
	UpdateGameMap(oGame)

func NewDoor
	lNewDoor = False 
	while lNewDoor = False
		newY = 2+random(C_LEVEL_ROWSCOUNT-3)
		newX = 2+random(C_LEVEL_COLSCOUNT-3)
		if aLevel[newY][newX] = C_EMPTY
			aLevel[newY][newX] = C_DOOR
			lNewDoor = True 
		ok
	end			


func HideCell aCell
	aLevel[aCell[1]][aCell[2]] = C_EMPTY

func ShowCell aCell
	aLevel[aCell[1]][aCell[2]] = C_WALL
	
func UpdateGameMap oGame
	# The Map is our first object in Game Objects 
		oGame.aObjects[1].aMap = aLevel

func DisplayGameOver oGame 
	if lGameOver return ok
	lGameOver = True
	oGame {
          text {
                point = 800
                size = 30
                nStep = 9
                file = "fonts/pirulen.ttf"
                text = "Game Over !!!"
                x = 10  y=10
		state = func oGame,oSelf {
			if oSelf.y >= 800
				oGame.Remove(oSelf.nIndex)
				Restart(oGame)
			ok
		}
          }
        }

func Restart oGame
	# Restart the Level
		aLevel = aLevelCopy  
		aSnake 		= [ [3,3] , [3,4] , [3,5] ]
		cDirection = :Right
		UpdateGameMap(oGame)
		lGameOver = False
