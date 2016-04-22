# the ring standard library
# game engine for 2d games
# 2016, mahmoud fayed <msfclipper@yahoo.com>

load "gameengine.ring"

$score = 0
$enemies = 30
$value = 90
$playerindex = 2
$gameresult = false

func main
	New Game
	{
		title = "Stars Fighter!"
		sprite
		{
			file = "images\stars.jpg"
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
			file = "images\player.png"
			transparent = true
			type = ge_type_player
			x = 400 y =400 width=100 height=100
			animate=false move=true Scaled=true
			keypress = func oGame,oself,nkey {
				if nkey = key_space
					ogame {
						sprite {
							type = ge_type_fire
							file  = "images\back4.png"
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
										   ogame.remove(x.nindex)
										   $score+=100
										   $enemies--
										   checkwin(oGame)
										   exit	
										ok			
									ok
								next
							}
						}
					}
				but nkey = key_esc ogame.shutdown()
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
		for g = 1 to $enemies
			sprite
			{
				type = ge_type_enemy
				file = "images\enemy.png"
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
								file  = "images\back6.png"
								transparent = true
								x = oself.x + 30
								y = oself.y + oself.height+ 30
								width = 30
								height = 30
								point = ogame.screen_h+30
								nstep = 10
								direction = ge_direction_incvertical
								state = func oGame,oSelf {
									x =  oGame.aObjects[$playerindex]
									if oself.x >= x.x and oself.y >= x.y and
									   oself.x <= x.x + x.width and  
									   oself.y <= x.y + x.height
									   $value-=20
									   ogame.remove(oself.nindex)
									   checkgameover(oGame)
									   exit	
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
			file = "fonts\pirulen.ttf"
			text = "Destroy All Enemies!"
			color = rgb(255,0,0)
			x = 100	y=50
			direction = ge_direction_incvertical
			point = 500
		}
		text {
			animate = false
			point = 400
			size = 30
			file = "fonts\pirulen.ttf"
			text = "Score : " + $score
			x = 500	y=10
			state = func oGame,oSelf { oSelf { text = "Score : " + $score } }
		}
		text {
			animate = false
			point = 400
			size = 30
			file = "fonts\pirulen.ttf"
			text = "Energy : " + $value
			value = $value
			x = 500	y=50
			state = func oGame,oSelf { oSelf { text = "Energy : " + $value } }
		}

	}

func checkwin ogame
	if $gameresult  return ok
	if $enemies = 0
		$gameresult = true
		oGame {
			text {
				point = 400
				size = 30
				file = "fonts\pirulen.ttf"
				text = "You Win!!!!"
				x = 500	y=10	
			}			
		}
	ok

func checkgameover ogame
	if $gameresult  return ok
	if $value <= 0
		$gameresult = true
		oGame {
			text {
				point = 400
				size = 30
				file = "fonts\pirulen.ttf"
				text = "Game Over !!!"
				x = 500	y=10	
			}			
		}
	ok
