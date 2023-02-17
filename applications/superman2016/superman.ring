# The Ring Standard Library
# Game Engine for 2D Games
# SuperMan Game
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

oGameState = NULL

Load "gameengine.ring"

func main

	oGame = New Game

	while true

	oGameState = new GameState

	oGame {
		title = "Super Man 2016"
		icon  = "images/superman.jpg"
		sprite
		{
			file = "images/superman.jpg"
			x = 0 y=0 width=800 height = 600 scaled = true animate = false
			keypress = func ogame,oself,nKey {
				if nkey = key_esc or nKey = GE_AC_BACK
					ogame.shutdown()
				but nKey = key_space
					oGameState.startplay=true
					ogame.shutdown=true
				ok
			}
			mouse = func ogame,oself,nType,aMouseList {		
				if nType = GE_MOUSE_UP
					oGameState.startplay=true 
					ogame.shutdown=true 
				ok
			}
			state = func ogame,oself {
				oself {
					if x > -500
						x-=1
						y-=1
						width +=1
						height +=4
					ok
				}
			}
		}
		text {
			animate = false
			size = 35
			file = "fonts/pirulen.ttf"
			text = "Super Man 2016"
			x = 20	y=30
		}
		text {
			animate = false
			size = 25
			file = "fonts/pirulen.ttf"
			text = "Version 1.0"
			x = 20	y=80
		}
		text {
			animate = false
			size = 16
			file = "fonts/pirulen.ttf"
			text = "(C) 2016, Mahmoud Fayed"
			x = 20	y=120
		}

		text {
			animate = false
			size = 25
			file = "fonts/pirulen.ttf"
			text = "Press Space to start"
			x = 190	y=470
		}
		text {
			animate = false
			size = 20
			file = "fonts/pirulen.ttf"
			text = "Press Esc to Exit"
			x = 260	y=510
		}

		animate {
			file = "images/superman.png"
			x = 200
			y = 200
			framewidth = 68
			scaled = true
			height = 86
			width = 60
			nStep = 10
			transparent = true
			animate = true
			direction = ge_direction_random
			state = func oGame,oSelf {
				oSelf {
					nStep--
					if nStep = 0
						nStep = 10
						if frame < 1
							frame++
						else
							frame=1
						ok
					ok
					if x <= 0 x=0 ok
					if y <= 0 y=0 ok
					if x >= 750 x= 750 ok
					if y > 550 y=550 ok
				}
			}
		}

		Sound {
			file = "sound/music2.wav"
		}
	}
	if oGameState.startplay
		oGame.refresh()
		playstart(oGame)
		oGame.refresh()
	ok

	end


func playstart oGame

	oGame {
		FPS = 15
		FixedFPS = 15
		nTimeOut = 0
		Title = "Super Man 2016"
		Sprite {
			file = "images/supermancity.jpg"
			x = 0 y=0 width=800 height = 600 scaled = true animate = false
		}
		Map {
			blockwidth = 80
			blockheight = 80
			aMap = [
				 	[0,0,0,4,4,4,0,0,0,1,0,0,0,1,4,4,0,1,0,0,0,0,4,4,0,1,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0,0,0,1,0,0,0,1,0,3,3,3,5,3,3,3,3,0],
					[0,0,4,0,4,0,4,0,0,1,0,0,0,3,4,4,4,1,0,0,0,0,4,4,0,1,4,4,4,0,0,4,4,4,4,4,4,4,4,4,4,4,4,1,4,1,0,0,0,1,0,0,0,1,0,4,4,4,4,4,4,4,4,0],
					[0,0,0,4,4,4,0,0,0,1,0,0,0,4,4,4,4,1,0,0,0,0,0,0,0,3,4,4,4,0,0,4,0,0,0,0,0,0,4,2,0,0,4,1,4,1,4,2,4,1,0,2,0,1,0,4,4,4,4,4,4,4,4,0],
					[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1,0,0,4,1,4,1,4,1,4,1,0,1,0,1,0,2,2,2,2,2,2,2,2,0],
					[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,3,0,0,0,1,4,1,4,1,4,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,4,3,4,1,4,3,0,1,0,3,0,1,0,0,0,0,0,0,0,0],
					[0,0,2,0,0,2,0,0,2,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0],
					[0,0,1,0,0,1,0,0,1,3,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0]
				]
			aImages = ["images/smwall.png","images/smwallup.png",
					"images/smwalldown.png","images/smstar.png",
					"images/smkey.png","images/smstar2.png"]
		}

		sprite {
			type = ge_type_enemy
			animate = false
			file  = "images/smhome.png"
			x = 5000
			y = 400
			width = 290
			height = 200
			transparent = true

			state = func oGame,oSelf {
				oself {
					x = 5000 +  oGame.aObjects[2].x
					if x < 0 or x > SCREEN_W return ok
				}
				if oGameState.gameresult or oGameState.DoorKey = false  return ok
				if oGame.aObjects[oGameState.playerindex].x > oself.x + 100 and
					oGame.aObjects[oGameState.playerindex].y > oself.y + 50
					oGameState.gameresult = true
					oGame {
						sprite {
							file = "images/smwin.jpg"
							x=0 y=0 width=800 height=600
							scaled = true animate=false
							state = func ogame,oself {
								oself {
									x-=5
									y-=5
									width +=10
									height +=10
									if x = -100
										ogame.shutdown = true
									ok
								}
							}
						}
					}
				ok
			}

		}

		animate {
			file = "images/superman.png"
			x = 0
			y = 0
			framewidth = 60
			scaled = true
			height = 86
			width = 60
			nStep = 3
			transparent = true
			state = func oGame,oSelf {

				checkstarskeycol(oGame,oSelf)

				if not oGameState.playerwin
						oself {
							file = "images/superman.png"
							height = 86
							width = 60
							for t=1 to 8
								if checkwall2(oGame,oSelf,0,5,[2,1])
									y += 5
								else
									exit
								ok
							next
							if y > 500 y=500 ok
						}
				ok

			}
			keypress = func ogame,oself,nKey {
				if oGameState.gameresult = false

					oself {
						if nkey = key_up and checkwall(oGame,oSelf,0,-40)
							oGameState.value -= 1
							checkgameover(oGame)
							file = "images/supermanup.png"
							height = 123
							dotransparent()
							y -= 40
							oGameState.down = 10
							if y<=0 y=0 ok
						but nkey = key_down and checkwall(oGame,oSelf,0,40)
							file = "images/supermandown.png"
							dotransparent()
							y += 40
							if y>=500 y=500 ok
						but nKey = key_right and checkwall(oGame,oSelf,10,0)
							file = "images/supermanright.png"
							dotransparent()
							x += 10
							if x >= 440
								if oGame.aObjects[2].x > -4500
									oGame.aObjects[2].x -= 50
									callenemystate(oGame)
								else
									if x <= 750
										if  checkwall(oGame,oSelf,10,0)
											x += 10
										ok
									else
										if  checkwall(oGame,oSelf,-10,0)
											x -= 10
										ok
									ok
									return
								ok
								x=400
							ok
						but nKey = key_left and checkwall(oGame,oSelf,-10,0)
							file = "images/supermanleft.png"
							dotransparent()
							x -= 10
							if x <= 0
								x += 10
								if oGame.aObjects[2].x != 0
									oGame.aObjects[2].x += 50
									callenemystate(oGame)
									x += 50
								ok
							ok
						but nkey = key_esc or nKey = GE_AC_BACK
							ogame.shutdown()
						ok
					}
				ok
			}
			mouse = func ogame,oself,nType,aMouseList {	
				if nType = GE_MOUSE_DOWN
					oGameState.moveplayer = TRUE
				But nType = GE_MOUSE_UP
					oGameState.moveplayer = FALSE
				ok
				if oGameState.moveplayer = TRUE
					if aMouseList[GE_MOUSE_X] < oSelf.X  # left
						call oself.keypress(oGame,oSelf,Key_left)
					else
						call oself.keypress(oGame,oSelf,Key_right)
					ok
					if aMouseList[GE_MOUSE_Y] < oSelf.Y  # up
						call oself.keypress(oGame,oSelf,Key_up)
					else
						call oself.keypress(oGame,oSelf,Key_down)
					ok
				ok				
			}
		}

		addenemy(oGame,600)
		addenemy(oGame,900)
		addenemy(oGame,1550)
		addenemy(oGame,2350)
		addenemy(oGame,3350)
		addenemy(oGame,3500)
		addenemy(oGame,3670)
		addenemy(oGame,3840)

		text {
			animate = false
			point = 400
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Score : " + oGameState.score
			x = 500	y=0
			state = func oGame,oSelf {
				oSelf { text = "Score : " + oGameState.score }
			}
		}

		text {
			animate = false
			point = 400
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Energy : " + oGameState.value
			x = 10	y=0
			state = func oGame,oSelf { oSelf { text = "Energy : " + oGameState.value } }
		}
	}


func inlist nValue,aList 
	if find(aList,nValue) return True ok 
	return False

func checkwall oGame,oself,diffx,diffy
	alist = [1,2,3]
	return checkwall2(oGame,oself,diffx,diffy,aList)

func checkpoint oGame,xPos,yPos,aList 
	nValue = oGame.aObjects[2].getvalue(xPos,yPos)
	return inlist(nValue,aList)


func checkwall2 oGame,oself,diffx,diffy,aList
	xPos = oSelf.x + diffx
	yPos = oSelf.y + diffy
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	xPos = oSelf.x + diffx
	yPos = oSelf.y + diffy + oSelf.height
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	xPos = oSelf.x + diffx + oSelf.width
	yPos = oSelf.y + diffy
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	xPos = oSelf.x + diffx + oSelf.width
	yPos = oSelf.y + diffy + oSelf.height
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	xPos = oSelf.x + diffx
	yPos = oSelf.y + diffy + oSelf.height / 2
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	xPos = oSelf.x + diffx + oSelf.width / 2
	yPos = oSelf.y + diffy
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	xPos = oSelf.x + diffx + oSelf.width / 2
	yPos = oSelf.y + diffy + oSelf.height / 2
	if checkPoint(oGame,xPos,yPos,aList) return False ok
	return True

func checkopenwall oGame
	if oGameState.score = 900
		oGame.aObjects[2].aMap[3][10] = 3
		oGame.aObjects[2].aMap[4][10] = 0
		oGame.aObjects[2].aMap[5][10] = 0
		oGame.aObjects[2].aMap[6][10] = 0
		oGame.aObjects[2].aMap[7][10] = 0
		oGame.aObjects[2].aMap[8][10] = 0
	but oGameState.score = 1800
		oGame.aObjects[2].aMap[3][18] = 3
		oGame.aObjects[2].aMap[4][18] = 0
		oGame.aObjects[2].aMap[5][18] = 0
		oGame.aObjects[2].aMap[6][18] = 0
		oGame.aObjects[2].aMap[7][18] = 0
		oGame.aObjects[2].aMap[8][18] = 0
	but oGameState.score = 5500
		oGame.aObjects[2].aMap[1][44] = 0
		oGame.aObjects[2].aMap[2][44] = 0
		oGame.aObjects[2].aMap[3][44] = 2
	ok


func checkgameover ogame 
	if oGameState.gameresult  return ok
	if oGameState.value <= 0
		oGameState.value = 0
		oGameState.gameresult = true
		oGame {
			text {
				point = 400
				size = 30
				nStep = 20
				file = "fonts/pirulen.ttf"
				text = "Game Over !!!"
				x = 500	y=10
				state = func ogame,oself {
					if oself.y >= 400
						ogame.shutdown = true
					ok
				}
			}
		}
		showfire(oGame,oGame.aObjects[oGameState.PlayerIndex].x+40,oGame.aObjects[oGameState.PlayerIndex].y+40)
		oGame.aObjects[oGameState.PlayerIndex].enabled = false
		oGame.remove(oGameState.PlayerIndex)
	ok


func showfire oGame,nX,nY
	oGame {
		animate {
			file = "images/fire.png"
			x = nX
			y = nY
			framewidth = 40
			height = 42
			transparent = true
			state = func oGame,oSelf {
				oSelf {
					if frame < 13
						frame++
					else
						frame=1
						oGame.remove(oself.nIndex)
					ok
				}
			}
		}
	}

func addenemy oGame,xPos
	oGame {
		lbraceend = false
		sprite {
				type = ge_type_enemy
				file = "images/smenemy.png"
				transparent = true
				x = xPos y =10 width=100 height=100
				animate=true Scaled=true
				direction = GE_DIRECTION_NOMOVE
				temp = xPos
				state = func oGame,oSelf {
					oself {
						x = oSelf.temp +  oGame.aObjects[2].x
						if y < 0 y = 0 ok
						if y > 100 y=100 ok
						if x > SCREEN_W or x < 0 return ok
					}

					if random(10) = 1
						if oGameState.gameresult return ok
						ogame {
							sprite {
								type = ge_type_fire
								file  = "images/smrocket.png"
								scaled  = true
								transparent = true
								x = oself.x + 30
								y = oself.y + oself.height+ 30
								width = 30
								height = 30
								point = ogame.screen_h+30
								nstep = 30
								direction = ge_direction_incvertical
								xvalue =  oGame.aObjects[2].x
								temp = oself.x + 30 - xvalue
								state = func oGame,oSelf {
									oself { x = oSelf.temp +  oGame.aObjects[2].x  }
									x =  oGame.aObjects[oGameState.playerindex]
									if oself.x >= x.x and oself.y >= x.y and
									   oself.x <= x.x + x.width and
									   oself.y <= x.y + x.height
									   if oGameState.value > 0
									   	oGameState.value-=1000
									   ok
									   ogame.remove(oself.nindex)
									   checkgameover(oGame)
									ok
								}
							}
						}
					ok
				}
			}
	}
	ogame.lbraceend = true


func checkstarskey oGame,oSelf,nValue,nRow,nCol
	switch nValue
		on 4
			oGame.aObjects[2].aMap[nRow][nCol] = 6
			oGameState.Score += 100
			checkopenwall(oGame)
			oGame { Sound {
				once = true
				file = "sound/sfx_point.wav"
			} }
		on 5
			oGame.aObjects[2].aMap[nRow][nCol] = 0
			oGameState.DoorKey = true
			oGameState.Score += 500
			checkopenwall(oGame)
			oGame { Sound {
				once = true
				file = "sound/sfx_point.wav"
			} }
	off

func checkstarskeycol oGame,oSelf
	nValue = oGame.aObjects[2].getvalue(oSelf.x,oSelf.y)
	nRow = oGame.aObjects[2].getrow(oSelf.x,oSelf.y)
	nCol = oGame.aObjects[2].getcol(oSelf.x,oSelf.y)
	checkstarskey(oGame,oSelf,nValue,nRow,nCol)

	nValue = oGame.aObjects[2].getvalue(oSelf.x+oSelf.width,oSelf.y+oSelf.height)
	nRow = oGame.aObjects[2].getrow(oSelf.x+oSelf.width,oSelf.y+oSelf.height)
	nCol = oGame.aObjects[2].getcol(oSelf.x+oSelf.width,oSelf.y+oSelf.height)
	checkstarskey(oGame,oSelf,nValue,nRow,nCol)

	nValue = oGame.aObjects[2].getvalue(oSelf.x+oSelf.width,oSelf.y)
	nRow = oGame.aObjects[2].getrow(oSelf.x+oSelf.width,oSelf.y)
	nCol = oGame.aObjects[2].getcol(oSelf.x+oSelf.width,oSelf.y)
	checkstarskey(oGame,oSelf,nValue,nRow,nCol)

	nValue = oGame.aObjects[2].getvalue(oSelf.x,oSelf.y+oSelf.height)
	nRow = oGame.aObjects[2].getrow(oSelf.x,oSelf.y+oSelf.height)
	nCol = oGame.aObjects[2].getcol(oSelf.x,oSelf.y+oSelf.height)
	checkstarskey(oGame,oSelf,nValue,nRow,nCol)

func callenemystate oGame
	for t in oGame.aObjects
		t {
			if type = GE_TYPE_ENEMY
				call state(oGame,t)
			ok
		}
	next

Class GameState

	down = 3
	gameresult = false
	Score = 0
	startplay=false
	lastcol = 0
	playerwin = false
	DoorKey = false
	playerindex = 4
	value = 1000
	moveplayer = false
