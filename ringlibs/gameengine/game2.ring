Load "gameengine.ring"

$down = 3
$gameresult = false
$Score = 0

func main

	oGame = New Game

	oGame {

		Title = "Bird Fighter"
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
			aImages = ["images/fbwall.png","images/fbwallup.png",
					"images/fbwalldown.png"]
			state = func oGame,oSelf {			
				if $gameresult = false
				oSelf {
					x -=  3
					if x < - 2100
						x = 0
						newmap(aMap)
					ok				
				}
				ok
					if  oGame.aObjects[2].getvalue(oGame.aObjects[3].x+40,oGame.aObjects[3].y) != 0 and $gameresult = false
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
								}
							}
						}
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

				$down --
				if $down = 0
					$down = 3
					oself { 
						y += 25 
						if y > 550 y=550 ok
					}
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
				if not $gameresult  $Score++  ok
			}
		}
	}

func newmap aMap
	v1 = [
		1,
		1,
		3,
		0,
		0,
		2,
		1,
		1
	]
	v2 = [
		1,
		3,
		0,
		0,
		0,
		2,
		1,
		1
	]
	v3 = [
		1,
		1,
		1,
		3,
		0,
		2,
		1,
		1
	]
	v4 = [
		1,
		1,
		1,
		3,
		0,
		0,
		0,
		0
	]
	v5 = [
		0,
		0,
		0,
		0,
		2,
		1,
		1,
		1
	]
	v6 = [
		0,
		0,
		2,
		1,
		1,
		1,
		1,
		1
	]
	v7 = [
		0,
		0,
		2,
		1,
		1,
		1,
		1,
		1
	]
	v8 = [
		1,
		1,
		1,
		3,
		0,
		2,
		1,
		1
	]
	v9 = [
		1,
		1,
		1,
		1,
		1,
		3,
		0,
		0
	]
	for x = 10 to 24 step 4
		cVar = "v" + (random(8)+1)
		eval("aVar ="+cVar)

		for y = 1 to 8
			aMap[y][x] = aVar[y]
		next
	next
