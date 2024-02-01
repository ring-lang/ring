# Pong game
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlibcore.ring"
Load "raylib.ring"

# Raylib window properties
screenWidth 	= 1000
screenHeight 	= 500

MusicOn 	= True
TimePlayed 	= 0
Start		= False

InitWindow(screenWidth, screenHeight, "Pong Ring")
windowIcon = LoadImage("Assets/icon.png")
SetWindowIcon(windowIcon)

# Load game textures
MusicOnImage 	= LoadImage("Assets/musicOn.png")
MusicOffImage 	= LoadImage("Assets/musicOff.png")

MusicOnTex 	= LoadTextureFromImage(musicOnImage)
MusicOffTex 	= LoadTextureFromImage(musicOffImage)

UnloadImage(musicOnImage)
UnloadImage(musicOffImage) 

# Load game sounds
InitAudioDevice()

hitSound = LoadSound("Assets/hurt2.ogg")
music = LoadMusicStream("Assets/FRocks.ogg")

PlayMusicStream(music)

SetTargetFPS(60)

# Create two player

player1 = new Player(){
	setKeyDown(KEY_W)
	setKeyUp(KEY_S)
}

player2 = new Player(){
	setPosition(screenWidth - 100, player1.position.y)
	setKeyDown(KEY_UP)
	setKeyUp(KEY_DOWN)
	Type = 2
}

# Create the main ball
ball = new Ball()

startScene = new StartScene

while !WindowShouldClose()

        BeginDrawing()

        ClearBackground(WHITE)

	# Start Scene
	while not startScene.isDone()
		startScene.draw()
	end
	# End of start Scene

	# Start game scene
	arena = new Arena{
		draw()
	}

	# Check if the user want to restart the game
	listenForRestart()

	# Play main music and ball sound
	musicHandler()

	# Check if the ball intersect with an edge and increment the player score
	if ball.intersectWithEdges(player1, player2)
		restart()
	ok
	
	# Check if the ball hit a player, change ball direction
	if ball.intersectWithPlayer([player1, player2])
		playSound(hitSound)
	ok

	# Draw player1, player1 and the ball
	player1.draw()
	player2.draw()
	ball.draw()

	# Move the ball and show some UI
	if START = True
		ball.move()
	else
		DrawText("WAITING FOR ANY PLAYER TO MOVE", screenWidth / 2 - 180, screenHeight * 0.4, 20, GRAY)			
	ok

	DrawText("SOME GAME ASSETS ARE FROM kenney.nl", screenWidth / 2 - 200, screenHeight * 0.9, 20, GRAY)
	
        EndDrawing()

end

unloadImage(windowIcon)

unloadSound(hitSound)
unloadMusicStream(music)

unloadTexture(MusicOnTex)
unloadTexture(MusicOffTex)

startScene.UnloadTextures()

CloseAudioDevice()
CloseWindow()

# Function to handle game music and sounds
func musicHandler

	uiPosition = new Vector2(screenWidth / 2 - 30, 100)
	timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music)

	if timePlayed > GetMusicTimeLength(music)
		PlayMusicStream(music)
	ok

	if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
		pos = getMousePosition()
		if pos.x >= uiPosition.x - 10 and pos.x <= uiPosition.x + 40 and pos.y >= uiPosition.y - 10 and pos.y <= uiPosition.y + 40
			musicOn = !musicOn
		ok
	ok

	if musicOn
		DrawTexture(musicOnTex, uiPosition.x, uiPosition.y , GRAY)
	else
		DrawTexture(musicOffTex,uiPosition.x, uiPosition.y, GRAY)
	ok

	if musicOn
		UpdateMusicStream(music)
	ok

# Function to check if the user press R key to restart the game
func listenForRestart
	DrawText("PRESS R TO RESTART", screenWidth / 2 - 130, 60, 25, GRAY)

	if IsKeyPressed(KEY_R)
		player1.score = 0
		player2.score = 0
		restart()
	ok

# Function to restart the game
func restart	
	START = False

	ball.init()

	player1	{
		init()
	}

	player2	{
		setPosition(screenWidth - 100, player1.position.y)
	}

# Class to draw the start scene in the game
class StartScene
	isDone = False MARGIN = 30
	images = [
		"Assets/tileW.png",
		"Assets/tileS.png",
		"Assets/tileUp.png",
		"Assets/tileDown.png"
		]

	positions = [
		:tileW = new Vector2(screenWidth * 0.15, screenHeight / 2 + MARGIN),
		:tileS = new Vector2(screenWidth * 0.15 + 68, screenHeight / 2 + MARGIN),
		:tileUp = new Vector2(screenWidth * 0.75, screenHeight / 2 + MARGIN),
		:tileDown = new Vector2(screenWidth * 0.75 + 68, screenHeight / 2 + MARGIN)
		]

	textures = []
	loadTextures()

	func loadTextures
		for image in images
			tileW = LoadImage(image)
			ImageResize(tileW, 64, 64)
			textures + LoadTextureFromImage(tileW)
			UnloadImage(tileW)
		next

	func unloadTextures
		for texture in textures
			UnloadTexture(texture)
		next

	func draw
		ClearBackground(BLACK)

		drawControls()
		DrawText("PONG RING", screenWidth / 2 - 180, screenHeight * 0.05, 72, WHITE)
		DrawText("PLAYER ONE CONTROLS", screenWidth * 0.1, screenHeight / 2 - 45 + MARGIN, 24, WHITE)
		DrawText("PLAYER TWO CONTROLS", screenWidth * 0.65, screenHeight / 2 - 45 + MARGIN, 24, WHITE)
		
		if getTime() >= 3
			isDone = True
		else
			DrawText("" + (floor(getTime() + 1)) ,screenWidth / 2, screenHeight * 0.3, 72, WHITE)
		ok
		EndDrawing()

	func isDone
		return isDone

	func drawControls
		for i=1 to len(images)
			texture = textures[i]
			position = positions[i][2]
			DrawTexture(texture, position.x, position.y, WHITE)
		next

# Class to draw playing area
class Arena

	MARGIN = 40

	func init
		return self

	func draw
		DrawRectangle(20, 20, screenWidth - MARGIN,
			 screenHeight - MARGIN, BLACK)

class Player

	position  w h speed = 4 score = 0 keyUp keyDown Type = 1 

	func init
		position = new Vector2(100, screenHeight / 2 - 50)
		w = 30 h = 100
		return self

	func draw
		DrawRectangle(position.x, position.y, w, h, WHITE)
		
		# Score
		DrawText("SCORE: " + score, position.x - 60, 60, 25, GRAY)

		if IsKeyDown(keyDown)
			START = True
			if position.y >= 30 
				position.y -= speed ok
		ok

		if IsKeyDown(keyUp)
			START = True
			if position.y <= screenHeight - 30 - 100
			position.y += speed ok
		ok

	func setPosition x, y
		position = new Vector2(x, y)

	func setKeyUp key
		keyUp = key

	func setKeyDown key
		keyDown = key

class Ball

	position radius = 20  velocity = new Vector2(6, 6)

	func init
		position = new Vector2(screenWidth / 2, screenHeight / 2)
		DrawCircleV(position, radius, BLUE)
		rand = random(1)
		if rand = 0 velocity.x = -velocity.x ok
		return self

	func draw
		DrawCircleV(position, radius, BLUE)

	func move
		DrawCircleV(position, radius, BLUE)

		position.x += velocity.x
		position.y += velocity.y

	func clamp val, min, max
		return max(min, min(max, val))

	func intersectWithEdges player1, player2
		if position.x <= 0 or position.x > screenWidth - radius
			velocity.x = -velocity.x
			playSound(hitSound)

			# Score
			if position.x <= 0
				player1.score++ return True
			elseif position.x > screenWidth - radius
				player2.score++ return True
			ok
		ok
			
		if position.y <= 0 or position.y > screenHeight - radius
			velocity.y = -velocity.y
			playSound(hitSound)
		ok

		return False

	func intersectWithPlayer players
		for player in players
			closestX = clamp(position.x, player.position.x, player.position.x + player.w)
			closestY = clamp(position.y, player.position.y, player.position.y + player.h)
		
			distanceX = position.x - closestX
			distanceY = position.y - closestY
		
			distance = sqrt(distanceX * distanceX + distanceY * distanceY)
		
			if distance <= radius
				if player.type = 1
					if velocity.x < 0 
						velocity.x = -velocity.x
					ok
				else
					if velocity.x > 0 
						velocity.x = -velocity.x
					ok
				ok
				
				return True
			ok
		next

		return False
