load "Button.ring"

class MainMenuScene from Scene
	startButton
	exitButton
	lCloseGame = False
	func init
		# Start button in the scene
		startButton = new Button("Assets/buttonRed.png",
					 "Assets/buttonBlue.png") {
			text = "Start"
			position = new Vector2 {
				x = screenWidth / 2
				y = screenHeight * 0.4	
			}
			position.x -= w / 2

			cFunction = :startGame

		}
		# Exit button in the scene
		exitButton = new Button("Assets/buttonRed.png",
					 "Assets/buttonBlue.png") {
			text = "Exit"
			position = new Vector2 {
				x = screenWidth / 2
				y = screenHeight * 0.6
			}
			position.x -= w / 2

			cFunction = :exitTheGame

		}

		return self	

	func draw
		DrawText(name, screenWidth / 2 - 200,
		 screenHeight * 0.1, 46, White)
		DrawText("Controls: Space And Arrow keys", screenWidth / 2 - 300,
		 screenHeight * 0.25, 36, White)

		startButton.draw(this)
		exitButton.draw(this)

		DrawText("GAME ASSETS ARE FROM kenney.nl", screenWidth / 2 - 180, screenHeight * 0.9, 20, GRAY)

	func startGame
		isDone = True

	func exitTheGame
		isDone = True
		lCloseGame = True
		
