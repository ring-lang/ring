#--------------------------------------------------#
# Sokoban Game  				   #
# 2019, Mahmoud Fayed <msfclipper@yahoo.com>	   #
# 2019, Gal Zsolt <quiwox@gmail.com>		   #
#--------------------------------------------------#

# Game Data 

	aPlayer = [ :Row = 3, :Col = 4 ]
	
	aLevel1 = [
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

	aLevel2 = [
		[1,1,1,2,2,2,2,2,2,2,2,2,1,1],
		[1,2,2,2,1,5,1,4,1,1,1,2,1,1],
		[1,2,4,3,5,1,1,1,5,1,1,2,1,1],
		[1,2,2,2,1,1,4,1,1,1,1,2,1,1],
		[1,2,4,2,2,1,5,4,1,5,1,2,1,1],
		[1,2,1,2,1,4,1,5,1,1,2,2,1,1],
		[1,2,5,1,6,5,1,4,1,1,1,2,1,1],
		[1,2,1,1,1,4,1,4,1,5,1,2,1,1],
		[1,2,2,2,2,2,2,2,2,2,2,2,1,1],
		[1,1,1,1,1,1,1,1,1,1,1,1,1,1]
	]

        aLevel = aLevel1
	nActiveLevel = 1

	# For Game Restart 
		aLevel1Copy  = aLevel1 
		aLevel2Copy  = aLevel2
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
							if nActiveLevel = 1
								aLevel = aLevel1Copy     
							else 
								aLevel = aLevel2Copy     
							ok
							aPlayer = aPlayerCopy
							UpdateGameMap(oGame)
							lPlayerWin = False
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

		text {
			x = 70	y=550
			animate = false
			size = 20
			file = "fonts/pirulen.ttf"
			text = "Level:"
			color = rgb(0,0,0)	
		} 
                NewButton(oGame,180,550,150,30,"Level 1",:Click1)
                NewButton(oGame,350,550,150,30,"Level 2",:Click2)
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
		state = func ogame,oself {
			if oself.y >= 400
				ogame.remove(oSelf.nIndex)
			ok
		}
          }
        }

func NewButton oGame,nX,nY,nWidth,nHeight,cText,cFunc
    oGame {
        Object {
                        x = nX y=nY width = nWidth height=nHeight
            AddAttribute(self,:Text)
            AddAttribute(self,:EventCode)
            Text = cText
            EventCode = cFunc
                        draw = func oGame,oSelf {
                                oSelf {
                    gl_draw_filled_rectangle(x,y,x+width,y+height,gl_map_rgb(0,100,255))
                    gl_draw_rectangle(x,y,x+width,y+height,gl_map_rgb(0,0,0),2)
                    oFont = oResources.LoadFont("fonts/pirulen.ttf",20)
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

func Click1 oGame,oSelf 
	aLevel = aLevel1
	nActiveLevel = 1
	aPlayer = aPlayerCopy
	UpdateGameMap(oGame)
	lPlayerWin = False
     
func Click2 oGame,oSelf 
	aLevel = aLevel2
	nActiveLevel = 2
	aPlayer = aPlayerCopy
	UpdateGameMap(oGame)
	lPlayerWin = False
