# The Escape Game  				   	  
# 2020, Mahmoud Fayed <msfclipper@yahoo.com>

# Game Data 

	# Map Size
		C_LEVEL_ROWSCOUNT = 20
		C_LEVEL_COLSCOUNT = 27

	# Map Items
		C_EMPTY 	= 1
		C_SNAKE  	= 2
		C_FOOD  	= 3
                C_PLAYER        = 4
                C_DIE           = 5
	
	# The Map Data 
		aLevel = list(C_LEVEL_ROWSCOUNT)
		for nRow = 1 to C_LEVEL_ROWSCOUNT
			aLevel[nRow] = list(C_LEVEL_COLSCOUNT)
			for nCol = 1 to C_LEVEL_COLSCOUNT
				aLevel[nRow][nCol] = C_EMPTY
			next
		next

	# Player 
		aPlayer = [ :Row = 13, :Col = 4 ]
		aLevel[13][4] = 4

	# Add the Snake
		aSnake 		= [ [3,3] , [3,4] , [3,5] ]
		aLevel[3][3] 	= C_SNAKE
		aLevel[3][4] 	= C_SNAKE
		aLevel[3][5] 	= C_SNAKE
		cDirection 	= :Right

	# For Game Restart 
		aLevelCopy  	= aLevel 

	# Create the first Food 
		oldY		= 0
		oldX		= 0
		newY		= 0
		newX		= 0
		NewFood()

	# Timers 
		nKeyClock 	= clock()
		nMoveClock 	= clock() 		

	# Game Over
		lGameOver 	= False

	# Speed 
		nKeyboardSpeed  = 15
		nMovementSpeed  = 15

load "gameengine.ring"        	

func main          		

	GE_SCREEN_W = 800
	GE_SCREEN_H = 600

	oGame = New Game      	
	{

		title = "Escape Game"
		icon  = "images/empty.jpg"

		Map {

			name = :Map

			blockwidth  = 30
			blockheight = 30

			aMap = aLevel
	
			aImages = [
				"images/empty.jpg",
				"images/wall.jpg",
				"images/door.jpg",
				"images/player.jpg",                              
				"images/die.jpg"                              
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
						if aPlayer[:col] < C_LEVEL_COLSCOUNT
							nRowDiff = 0   nColDiff = 1
							MovePlayer(oGame,aPlayer[:row],aPlayer[:col]+1)
						ok
					on Key_Left
						if aPlayer[:col] > 1
							nRowDiff = 0   nColDiff = -1
							MovePlayer(oGame,aPlayer[:row],aPlayer[:col]-1)
						ok
					on Key_Up
						if aPlayer[:row] > 1
							nRowDiff = -1   nColDiff = 0
							MovePlayer(oGame,aPlayer[:row]-1,aPlayer[:col])
						ok
					on Key_Down
						if aPlayer[:row] < C_LEVEL_ROWSCOUNT
							nRowDiff = 1   nColDiff = 0
							MovePlayer(oGame,aPlayer[:row]+1,aPlayer[:col])
						ok

				off
 			}

			state = func oGame,oSelf {
				if clock() - nMoveClock >= clockspersecond()/nMovementSpeed
					nMoveClock = clock()
					MoveSnake(oGame,oSelf)
				ok 
				nSnakeY = aSnake[len(aSnake)][1]
				nSnakeX = aSnake[len(aSnake)][2]
				if nSnakeX < newX 
					if cDirection != :Left
						cDirection = :Right
					else 
						cDirection = :Down
						MoveSnake(oGame,oSelf) 
						cDirection = :Right
					ok
				but nSnakeX > newX 
					if cDirection != :Right
						cDirection = :Left
					else 
						cDirection = :Up
						MoveSnake(oGame,oSelf) 
						cDirection = :Left
					ok
				but nSnakeY > newY
					if cDirection != :Down
						cDirection = :UP
					else 
						cDirection = :Left
						MoveSnake(oGame,oSelf) 
						cDirection = :UP						cDirection = :UP
					ok
				but nSnakeY < newY 
					if cDirection != :Up
						cDirection = :Down
					else 
						cDirection = :Right
						MoveSnake(oGame,oSelf) 
						cDirection = :Down
					ok
				ok
			}

		}
	}         

func MoveSnake oGame,oMap
	if lGameOver return ok
	aHead = aSnake[len(aSnake)]
	switch cDirection
		on :right 
			if aHead[2] = C_LEVEL_COLSCOUNT	 cDirection=:Down MoveSnake(oGame,oMap) cDirection=:Left return ok		
			aHead[2]++
		on :left 
			if aHead[2] = 1	 cDirection=:Down  MoveSnake(oGame,oMap)  cDirection=:Right return ok		
			aHead[2]--
		on :up
			if aHead[1] = 1	 cDirection=:Right MoveSnake(oGame,oMap) cDirection=:Down return ok		
			aHead[1]--
		on :down
			if aHead[1] = C_LEVEL_ROWSCOUNT	 cDirection=:Left MoveSnake(oGame,oMap) cDirection=:Up return ok		
			aHead[1]++
	off
	if aLevel[aHead[1]][aHead[2]] = C_EMPTY
		if CheckAnotherCell() = False
			HideCell(aSnake[1])
		ok
		del(aSnake,1)
		# Snake attack the player but the player escaped
			if aHead[1] = newY and aHead[2] = newX 
				newY = oldY
				newX = oldX
			ok
	but (aLevel[aHead[1]][aHead[2]] = C_FOOD) 
		NewFood()
	but aLevel[aHead[1]][aHead[2]] = C_SNAKE
		if CheckAnotherCell() = False
			HideCell(aSnake[1])
		ok
		del(aSnake,1)
	but aLevel[aHead[1]][aHead[2]] = C_PLAYER
		aLevel[aPlayer[:row]][aPlayer[:col]] = C_DIE
		UpdateGameMap(oGame)
		DisplayGameOver(oGame) 
		return
	ok
	aSnake + aHead
	ShowCell(aHead)
	UpdateGameMap(oGame)

func CheckAnotherCell  
	# Check if we don't have another cell in this place 
		for t = 2 to len(aSnake)
			if aSnake[t][1] = aSnake[1][1] and 
			   aSnake[t][2] = aSnake[1][2]
				return True
			ok
		next
	return False 

func NewFood
	# Snake ---> Attack the Star 
		lNewFood = False 
		while lNewFood = False
			newY = 2+random(C_LEVEL_ROWSCOUNT-3)
			newX = 2+random(C_LEVEL_COLSCOUNT-3)
			if aLevel[newY][newX] = C_EMPTY
				aLevel[newY][newX] = C_FOOD
				lNewFood = True 
			ok
		end			
	# Snake ---> Attack the Player 
		if len(aSnake) % 2 = 0
			oldY = newY 
			oldX = newX
			newY = aPlayer[:row]
			newX = aPlayer[:col]
		ok
	
func HideCell aCell
	aLevel[aCell[1]][aCell[2]] = C_EMPTY

func ShowCell aCell
	aLevel[aCell[1]][aCell[2]] = C_SNAKE
	
func UpdateGameMap oGame
	oGame.find(:Map).aMap = aLevel

func DisplayGameOver oGame 
	if lGameOver return ok
	lGameOver = True
	oGame {
		text {
	                point	= 800
	                size	= 30
	                nStep	= 9
	                file	= "fonts/pirulen.ttf"
	                text	= "Game Over !!!"
	                x	= 10  
			y	= 10
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
		lGameOver	= False
		aLevel		= aLevelCopy  
		aSnake 		= [ [3,3] , [3,4] , [3,5] ]
		cDirection	= :Right
		aPlayer		= [ :Row = 13, :Col = 4 ]
		aLevel[13][4]	= 4
		newX		= 0
		newY		= 0
		NewFood()
		UpdateGameMap(oGame)

func MovePlayer oGame,nNewRow,nNewCol
		switch aLevel[nNewRow][nNewCol] 
			on C_EMPTY
				aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
				aLevel[nNewRow][nNewCol] = C_PLAYER
				UpdateGameMap(oGame)
				aPlayer[:row] = nNewRow
				aPlayer[:col] = nNewCol
			on C_FOOD
				aLevel[aPlayer[:row]][aPlayer[:col]] = C_EMPTY
				aLevel[nNewRow][nNewCol] = C_PLAYER
				UpdateGameMap(oGame)
				aPlayer[:row] = nNewRow
				aPlayer[:col] = nNewCol
				NewFood()
				UpdateGameMap(oGame)
			on C_SNAKE
				aLevel[aPlayer[:row]][aPlayer[:col]] = C_DIE
				UpdateGameMap(oGame)
				DisplayGameOver(oGame) 
		off
	return

