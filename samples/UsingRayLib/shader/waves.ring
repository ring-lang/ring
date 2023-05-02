#========================================================================#
# raylib [shader] example - texture waves
# Copyright (c) 2019 Anata (@anatagawa) and Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#========================================================================#

load "raylib.ring"

func main

	screenWidth  = 800
	screenHeight = 450

	InitWindow(screenWidth, screenHeight, "raylib [shaders] example - texture waves")
	
	texture = LoadTexture("images/space.png")
	
	shader  = LoadShader("", "shaders/wave.fs" )

	secondsLoc = GetShaderLocation(shader, "secondes")
	freqXLoc   = GetShaderLocation(shader, "freqX")
	freqYLoc   = GetShaderLocation(shader, "freqY")
	ampXLoc    = GetShaderLocation(shader, "ampX")
	ampYLoc    = GetShaderLocation(shader, "ampY")
	speedXLoc  = GetShaderLocation(shader, "speedX")
	speedYLoc  = GetShaderLocation(shader, "speedY")

	freqX  = 25.0
	freqY  = 25.0
	ampX   = 5.0
	ampY   = 5.0
	speedX = 8.0
	speedY = 8.0

	screenSize = [ GetScreenWidth() , GetScreenHeight() ]
	SetShaderVec2(shader, GetShaderLocation(shader, "size"), screenSize)

	SetShaderFloat(shader, freqXLoc, freqX)
	SetShaderFloat(shader, freqYLoc, freqY)
	SetShaderFloat(shader, ampXLoc, ampX)
	SetShaderFloat(shader, ampYLoc, ampY)
	SetShaderFloat(shader, speedXLoc, speedX)
	SetShaderFloat(shader, speedYLoc, speedY)

	seconds = 0

	SetTargetFPS(60)

	While (!WindowShouldClose())

		seconds += GetFrameTime()
		SetShaderFloat(shader, secondsLoc, seconds)

		BeginDrawing()

		ClearBackground(RAYWHITE)

			BeginShaderMode(shader)
            
				DrawTexture(texture, 0, 0, WHITE)
				DrawTexture(texture, texture.width, 0, WHITE)
                
			EndShaderMode()

		EndDrawing()

	End

	UnloadShader(shader)    
	UnloadTexture(texture)     
	
	CloseWindow()   