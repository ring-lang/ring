/*
* Name: 		Pong
* Last update:	21/10/2018 - 8:42 PM
* Author: 		JustGo
*/

Ball 		= NULL
Paddle 		= NULL
PaddleBot 	= NULL
GameOver 	= NULL
GameRunning = NULL
GameEndText = NULL

load "gameengine.ring"
load "pongpaddle.ring"
load "pongball.ring"

func main

	GameObject = new Game
	Ball = new PongBall { x = GameObject.screen_w/2 y = GameObject.screen_h/2 }
	Paddle = new PongPaddle{ mouseControle = false y = GameObject.screen_h/2 - height/2 }
	PaddleBot = new PongPaddle{ botControle = true x = GameObject.screen_w - ( Paddle.x + Paddle.width ) color = GE_COLOR_RED}

	GameRunning = true
	GameOver = False

	GameObject {
		al_hide_mouse_cursor(display)
		FixedFPS = 180
		title = "Pong"
		Object {
			draw = func GameObject, Self {
				if GameRunning = True
					Self{
						Ball.Draw()
						Paddle.Draw()
						PaddleBot.Draw()
					}
				ok
			}
			state = func GameObject,Self {
				Self {
					if GameRunning = true
						GameRunning = Ball.Move(GameObject, Paddle, PaddleBot)
						PaddleBot.Move(NULL, GameObject)
					else
						if GameOver = false
							GameObject {
								GameEndText = text {
									animate = false
									size = 35
									file = "fonts/pirulen.ttf"
									if Ball.x < ( Paddle.x + Paddle.width + ball.rad )
										text = "Game Over!"
										x = screen_w/2 - size*5
									else
										text = "You Won!"
										x = screen_w/2 - size*3
									ok
									y = screen_h/2
									color = GE_COLOR_BLACK
								}
							}
							GameOver = true
						ok
					ok
				}
			}
			mouse = func GameObject,Self,nType,aMouseList {
				if Paddle.mouseControle = true and GameRunning = true
					Paddle.Move(aMouseList[GE_MOUSE_Y], GameObject)
				ok
			}
			keypress = func GameObject,Self,nKey {
				Self {
					if Paddle.mouseControle = false and GameRunning = true

						if nkey = key_up
							for counter = 1 to Paddle.playerSpeed
								if Paddle.y > 0
									Paddle.y--
								ok
							next
						elseif nkey = key_down
							for counter = 1 to Paddle.playerSpeed
								if Paddle.y + Paddle.height < screen_h 
									Paddle.y++
								ok
							next
						ok

					ok

					if nkey = key_esc or nKey = GE_AC_BACK
						GameObject.shutdown()
					elseif nkey = key_space and GameOver = true
						GameRunning = true
						GameOver = False
						Ball.speed = 2
						Ball.stop = false
						Ball.x = screen_w/2
						Ball.y = screen_h/2
						Paddle.y = screen_h/2 - Paddle.height/2
						PaddleBot.y = screen_h/2 - PaddleBot.height/2
						GameObject.remove(GameEndText.nindex)
					ok
				}
			}
		}
		
		text {
			animate = false
			size = 35
			file = "fonts/pirulen.ttf"
			text = "Pong"
			color = GE_COLOR_BLACK
			x = screen_w/2 - size*2
			y = 0
		}
		
	}
