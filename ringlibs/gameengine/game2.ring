# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>
Load "gameengine.ring"

$down = 3
$gameresult = false
$Score = 0
$startplay=false
$lastcol = 0
$playerwin = false

al_run_main() 
func al_game_start 
	 main()

func main

	oGame = New Game

	while true

	$down = 3
	$gameresult = false
	$Score = 0
	$startplay=false
	$lastcol = 0
	$playerwin = false

	oGame {
		title = "Flappy Bird 3000"
		sprite
		{
			file = "images/fbback.png"
			x = 0 y=0 width=800 height = 600 scaled = true animate = false
			keypress = func ogame,oself,nKey {
				if nkey = key_esc
					ogame.shutdown()
				but nKey = key_space
					$startplay=true
					ogame.shutdown=true
				ok
			}
		}
		text {
			animate = false
			size = 35
			file = "fonts/pirulen.ttf"
			text = "Flappy Bird 3000"
			x = 150	y=50
		}
		text {
			animate = false
			size = 25
			file = "fonts/pirulen.ttf"
			text = "Version 1.0"
			x = 280	y=100
		}
		text {
			animate = false
			size = 16
			file = "fonts/pirulen.ttf"
			text = "(C) 2016, Mahmoud Fayed"
			x = 245	y=140
		}

		text {
			animate = false
			size = 25
			file = "fonts/pirulen.ttf"
			text = "To Win Get Score = 3000"
			x = 150	y=270
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
			file = "images/fbbird.png"
			x = 200
			y = 200
			framewidth = 20
			scaled = true
			height = 50
			width = 50
			nStep = 3
			transparent = true
			animate = true
			direction = ge_direction_random
			state = func oGame,oSelf {
				oSelf {
					nStep--
					if nStep = 0
						nStep = 3
						if frame < 3
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
			playSound()
		}
	}
	if $startplay
		oGame.refresh()
		playstart(oGame)
		oGame.refresh()
	ok

	end


func playstart oGame

	oGame {

		Title = "Flappy Bird 3000"
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
				 	[0,0,0,0,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0],
					[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0],
					[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0],
					[0,0,0,0,0,0,0,0,0,1,0,0,0,2,0,0,0,3,0,0,0,1,0,0,0,1,0,0,0],
					[0,0,0,0,0,0,0,0,0,3,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,3,0,0,0],
					[0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0]
				]
			newmap(aMap)
			aImages = ["images/fbwall.png","images/fbwallup.png",
					"images/fbwalldown.png"]
			state = func oGame,oSelf {
				if $gameresult = false
					px = oGame.aObjects[3].x
					py = oGame.aObjects[3].y
					oSelf {
						x -=  3
						if x < - 2100
							x = 0
							newmap(aMap)
						ok
						nCol =  getcol(px,0)
						if nCol=11 or nCol=15 or nCol=19 or nCol=23 or nCol=27
							if nCol != $lastcol
								$lastcol = nCol
								$Score += 100
								oGame { Sound {
									once = true
									file = "sound/sfx_point.wav"
									playSound()
								} }
								checkwin(oGame)
							ok
						ok
					}
					if  oSelf.getvalue(px+40,py) != 0 or
					    oSelf.getvalue(px+40,py+40) != 0 or
					    oSelf.getvalue(px,py) != 0 or
					    oSelf.getvalue(px,py+40) != 0
						$gameresult = true
						oGame {
							text {
								point = 550
								size = 30
								nStep = 3
								file = "fonts/pirulen.ttf"
								text = "Game Over !!!"
								x = 500	y=10
								state = func ogame,oself {
									if oself.y >= 550
											ogame.shutdown = true
									ok
										if oself.y = 90
										ogame {
											Sound {
												once = true
												file = "sound/sfx_die.wav"
												playSound()
											}
										}
									ok
								}
							}
							Sound {
								once = true
								file = "sound/sfx_hit.wav"
								playSound()
							}
						}
					ok
				ok
			}
		}

		animate {
			file = "images/fbbird.png"
			x = 10
			y = 10
			framewidth = 20
			scaled = true
			height = 50
			width = 50
			nStep = 3
			transparent = true
			state = func oGame,oSelf {
				oSelf {
					nStep--
					if nStep = 0
						nStep = 3
						if frame < 3
							frame++
						else
							frame=1
						ok
					ok
				}

				if not $playerwin
					$down --
					if $down = 0
						$down = 3
						oself {
							y += 25
							if y > 550 y=550 ok
						}
					ok
				ok

			}
			keypress = func ogame,oself,nKey {
				if $gameresult = false
					oself {
						if nkey = key_space
							y -= 55
							$down = 60
							if y<=0 y=0 ok
						ok
					}
				ok
			}
		}

		text {
			animate = false
			point = 400
			size = 30
			file = "fonts/pirulen.ttf"
			text = "Score : " + $score
			x = 500	y=10
			state = func oGame,oSelf {
				oSelf { text = "Score : " + $score }
			}
		}

	}

func newmap aMap
	aV = [
	[1,1,3,0,0,2,1,1],
	[1,3,0,0,0,2,1,1],
	[1,1,1,3,0,2,1,1],
	[1,1,1,3,0,0,0,0],
	[0,0,0,0,2,1,1,1],
	[0,0,2,1,1,1,1,1],
	[0,0,0,2,1,1,1,1],
	[1,1,1,3,0,2,1,1],
	[1,1,1,1,1,3,0,0],
	[3,0,0,2,1,1,1,1],
	[3,0,0,2,3,0,0,2]
	]
	for x = 10 to 24 step 4
		aVar = aV[ (random(10)+1) ]
		for y = 1 to 8
			aMap[y][x] = aVar[y]
		next
	next

func checkwin ogame
	if $score = 3000
		$gameresult = true
		$playerwin = true
		oGame {
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
						$value = 0
					ok
				}
			}
		}
	ok
