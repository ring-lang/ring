#===================================================================#
# Copyright (c) 2013 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

// Initialization
//---------------------------------------------------------
screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "Bouncing Ball")

ballPosition = Vector2( GetScreenWidth()/2, GetScreenHeight()/2 )
ballSpeed = Vector2( 5.0, 4.0 )
ballRadius = 20

pause = 0
framesCounter = 0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//----------------------------------------------------------

// Main game loop
while !WindowShouldClose()    // Detect window close button or ESC key

	// Update
	//-----------------------------------------------------
	if IsKeyPressed(KEY_SPACE)
		pause = !pause
	ok

	if !pause

		ballPosition.x += ballSpeed.x
		ballPosition.y += ballSpeed.y

		// Check walls collision for bouncing
		if (ballPosition.x >= (GetScreenWidth() - ballRadius)) or
			(ballPosition.x <= ballRadius)
			ballSpeed.x *= -1.0
		ok
		if (ballPosition.y >= (GetScreenHeight() - ballRadius)) or
			(ballPosition.y <= ballRadius)
			ballSpeed.y *= -1.0 
		ok       
	else 
		framesCounter++
	ok
	//-----------------------------------------------------

	// Draw
	//-----------------------------------------------------
	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawCircleV(ballPosition, ballRadius, MAROON)
		DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY)

		// On pause, we draw a blinking message
		if pause & ((framesCounter/30)%2)
			DrawText("PAUSED", 350, 200, 30, GRAY)
		ok

		DrawFPS(10, 10)

	EndDrawing()
	//-----------------------------------------------------
end

//---------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//----------------------------------------------------------
