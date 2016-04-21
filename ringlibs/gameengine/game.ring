# the ring standard library
# game engine for 2d games
# 2016, mahmoud fayed <msfclipper@yahoo.com>

load "gameengine.ring"

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
						}
					}
				but nkey = key_esc ogame.shutdown()
				ok
			}
		}
		for g = 1 to 100
			sprite
			{
				type = ge_type_enemy
				file = "images\back3.jpg"
				x = g y =g width=100 height=100
				animate=true Scaled=true
				direction = ge_direction_random
			}
		next
	}
