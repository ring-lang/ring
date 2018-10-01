# The Ring Standard Library
# Game Engine for 2D Games
# Stars Fighter Game
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

oGameState = NULL

Load "gameengine.ring"

func main

	oGame = New Game

	while true

	oGameState = new GameState

	oGame {
		title = "Stars Fighter!"
		sprite
		{
			file = "images/menu1.jpg"
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
		}
		text {
			animate = false
			size = 35
			file = "fonts/pirulen.ttf"
			text = "Stars Fighter"
			x = 10	y=50
		}
		text {
			animate = false
			size = 25
			file = "fonts/pirulen.ttf"
			text = "Version 1.0"
			x = 80	y=100
		}
		text {
			animate = false
			size = 16
			file = "fonts/pirulen.ttf"
			text = "(C) 2016, Mahmoud Fayed"
			x = 45	y=140
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
		Sound {
			file = "sound/music1.wav"
		}
	}

	if oGameState.startplay
		oGame.refresh()
		playstart(oGame)
		oGame.refresh()
	ok

	end

func playstart oGame

	oSound = New Sound {
		file = "sound/music2.wav"
	}

	while true
		play(oGame)
		if ogame.shutdown = true and oGameState.value = 0
			exit
		ok
		ogame.refresh()
	end

	oSound.Delete()

func play oGame

	oGame
	{
		FPS = 60
		FixedFPS = 120
		nTimeOut = 0.01
		title = "Stars Fighter!"
		sprite
		{
			file = "images/stars.jpg"
			x = 0
			y = 0
			point = -370
			direction = ge_direction_dec
			type = ge_type_background
			state = func ogame,oself {
					oself {
						if x < -350
							direction = ge_direction_inc
							point = 370
						but x = 0 and direction = ge_direction_inc
							direction = ge_direction_dec
							point = -370
						ok
					}
				}
		}
		sprite
		{
			file = "images/player.png"
			transparent = true
			type = ge_type_player
			x = 400 y =400 width=100 height=100
			animate=false move=true Scaled=true
			mouse = func ogame,oself,nType,aMouseList {

				if not ( aMouseList[GE_MOUSE_X] >= oSelf.x and aMouseList[GE_MOUSE_X] <= oSelf.x+oSelf.width and
					aMouseList[GE_MOUSE_Y] >= oself.y and aMouseList[GE_MOUSE_Y] <= oSelf.y+oSelf.height )

					if nType = GE_MOUSE_DOWN
						if aMouseList[1] < oSelf.X  # left
							oSelf.X -= 100
						else
							oSelf.X += 100
						ok
						if aMouseList[2] < oSelf.Y  # up
							oSelf.Y -= 100
						else
							oSelf.Y += 100
						ok
					ok

				else
					if nType = GE_MOUSE_UP
						call oself.keypress(oGame,oSelf,Key_Space)
					ok
				ok
			}
			keypress = func oGame,oself,nkey {
				if nkey = key_space
					ogame {
						sprite {
							type = ge_type_fire
							file  = "images/rocket.png"
							transparent = true
  							x = oself.x + 30
							y = oself.y - 30
							width = 30
							height = 30
							point = -30
							nstep = 20
							direction = ge_direction_decvertical
							state = func oGame,oSelf {
								for x in oGame.aObjects
									if x.type = ge_type_enemy
										if oself.x >= x.x and oself.y >= x.y and
											oself.x <= x.x + x.width and
											oself.y <= x.y + x.height
											showfire(oGame,x.x+40,x.y+40)
											ogame.remove(x.nindex)
											oGameState.score+=10
											oGameState.enemies--
											checkwin(oGame)
											exit
										ok
									ok
								next
							}
						}
					}
				but nkey = key_esc or nKey = GE_AC_BACK ogame.shutdown()
				ok
			}
			state = func oGame,oSelf {
				oself {
					if x < 0 x = 0 ok
					if y < 0 y = 0 ok
					if x > ogame.screen_w-width  x= ogame.screen_w - width ok
					if y > ogame.screen_h-height y=ogame.screen_h-height ok
				}
			}
		}
		for g = 1 to oGameState.enemies
			sprite
			{
				type = ge_type_enemy
				file = "images/enemy.png"
				transparent = true
				x = g*random(50) y =g width=100 height=100
				animate=true Scaled=true
				direction = ge_direction_random
				state = func oGame,oSelf {
					oself {
						if x < 0 x = 0 ok
						if y < 0 y = 0 ok
						if x > ogame.screen_w-width  x= ogame.screen_w - width ok
						if y > ogame.screen_h-height y=ogame.screen_h-height ok
					}
					if random(100) = 1
						ogame {
							sprite {
								type = ge_type_fire
								file  = "images/rocket2.png"
								transparent = true
								x = oself.x + 30
								y = oself.y + oself.height+ 30
								width = 30
								height = 30
								point = ogame.screen_h+30
								nstep = 10
								direction = ge_direction_incvertical
								state = func oGame,oSelf {
									x =  oGame.aObjects[oGameState.playerindex]
									if oself.x >= x.x and oself.y >= x.y and
									   oself.x <= x.x + x.width and
									   oself.y <= x.y + x.height
									   if oGameState.value > 0
									   	oGameState.value-=10
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
		next
		text {
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Destroy All Enemies!"
			nstep = 3
			color = GE_COLOR_GREEN
			x = 100	y=50
			direction = ge_direction_incvertical
			point = 500
		}
		text {
			animate = false
			point = 400
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Score : " + oGameState.score
			x = 500	y=10
			state = func oGame,oSelf { oSelf { text = "Score : " + oGameState.score } }
		}
		text {
			animate = false
			point = 400
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Energy : " + oGameState.value
			x = 500	y=50
			state = func oGame,oSelf { oSelf { text = "Energy : " + oGameState.value } }
		}
		text {
			animate = false
			point = 400
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Level : " + oGameState.level
			x = 500	y=90
		}
	}


func checkwin ogame
	if oGameState.gameresult  return ok
	if oGameState.enemies = 0
		oGameState.gameresult = true
		oGame {
			if oGameState.level < 30
			text {
				point = 400
				size = 30
				file = "fonts/pirulen.ttf"
				text = "Level Completed!"
				nStep = 3
				x = 500	y=10
				state = func ogame,oself {
					if oself.y >= 400
						ogame.shutdown = true
						oGameState.level++
						oGameState.enemies = oGameState.level
						oGameState.gameresult = false
					ok
				}
			}
			else
			text {
				point = 400
				size = 30
				nStep = 3
				file = "fonts/pirulen.ttf"
				text = "You Win !!!"
				x = 500	y=10
				state = func ogame,oself {
					if oself.y >= 400
						ogame.shutdown = true
						oGameState.value = 0
					ok
				}
			}
			ok
		}
	ok

func checkgameover ogame
	if oGameState.gameresult  return ok
	if oGameState.value <= 0
		oGameState.gameresult = true
		oGame {
			text {
				point = 400
				size = 30
				nStep = 3
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
			nStep = 3
			transparent = true
			state = func oGame,oSelf {
				oSelf {
					nStep--
					if nStep = 0
						nStep = 3
						if frame < 13
							frame++
						else
							frame=1
							oGame.remove(oself.nIndex)
						ok
					ok
				}
			}
		}
	}


class gamestate
	score = 0
	level = 1
	enemies = 1
	value = 100
	playerindex = 2
	gameresult = false
	startplay=false
