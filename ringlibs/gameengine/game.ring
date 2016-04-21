# the ring standard library
# game engine for 2d games
# 2016, mahmoud fayed <msfclipper@yahoo.com>

load "gameengine.ring"

$score = 0

func main
	New Game
	{
		sprite
		{
			file = "images\back3.jpg"
			x = 0
			y = 0
			point = -370
			direction = ge_direction_dec
			type = ge_type_background
		}
		sprite
		{
			file = "images\back5.jpg"
			type = ge_type_player
			x = 400 y =400 width=100 height=100
			animate=false move=true Scaled=true
			keypress = func oGame,oself,nkey {
				if nkey = key_space
					ogame {
						sprite {
							type = ge_type_fire
							file  = "images\back4.jpg"
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
										   $score++
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
		}
		for g = 1 to 30 
			sprite
			{
				type = ge_type_enemy
				file = "images\back3.jpg"
				x = g*random(50) y =g width=100 height=100
				animate=true Scaled=true
				direction = ge_direction_random
				state = func oGame,oSelf {
					if random(100) = 1
						ogame {
							sprite {
								type = ge_type_fire
								file  = "images\back4.jpg"
								x = oself.x + 30
								y = oself.y + oself.height+ 30
								width = 30
								height = 30
								point = ogame.screen_h+30
								nstep = 10
								direction = ge_direction_incvertical
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
		}
		text {
			animate = false
			point = 400
			size = 30
			file = "fonts\pirulen.ttf"
			text = "Score : " + $score
			x = 520	y=10
			state = func oGame,oSelf { oSelf { text = "Score : " + $score } }
		}

	}
