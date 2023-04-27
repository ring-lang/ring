#========================================================================#
# raylib [shader] example - texture waves
# Copyright (c) 2019 Anata (@anatagawa) and Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#========================================================================#

load "raylib.ring"

func main

	screenWidth = 800
	screenHeight = 450

	InitWindow(screenWidth, screenHeight, "raylib [shaders] example - texture waves")
	
	texture = LoadTexture("space.png")
	
	shader = LoadShader("", "wave.fs" )

	secondsLoc = GetShaderLocation(shader, "secondes")
	freqXLoc = GetShaderLocation(shader, "freqX")
	freqYLoc = GetShaderLocation(shader, "freqY")
	ampXLoc = GetShaderLocation(shader, "ampX")
	ampYLoc = GetShaderLocation(shader, "ampY")
	speedXLoc = GetShaderLocation(shader, "speedX")
	speedYLoc = GetShaderLocation(shader, "speedY")

	freqX  = float2bytes(25.0)
	freqY  = float2bytes(25.0)
	ampX   = float2bytes(5.0)
	ampY   = float2bytes(5.0)
	speedX = float2bytes(8.0)
	speedY = float2bytes(8.0)

	screenSize = float2bytes( GetScreenWidth()) + float2bytes(GetScreenHeight())
	SetShaderValue(shader, GetShaderLocation(shader, "size"), varptr(:screenSize,:void), UNIFORM_VEC2)

	SetShaderValue(shader, freqXLoc, varptr(:freqX,:void), UNIFORM_FLOAT)
	SetShaderValue(shader, freqYLoc, varptr(:freqY,:void), UNIFORM_FLOAT)
	SetShaderValue(shader, ampXLoc, varptr(:ampX,:void), UNIFORM_FLOAT)
	SetShaderValue(shader, ampYLoc, varptr(:ampY,:void), UNIFORM_FLOAT)
	SetShaderValue(shader, speedXLoc, varptr(:speedX,:void), UNIFORM_FLOAT)
	SetShaderValue(shader, speedYLoc, varptr(:speedY,:void), UNIFORM_FLOAT)

	seconds = 0

	SetTargetFPS(60)

	While (!WindowShouldClose())

		seconds += GetFrameTime()
        	seconds2 = float2bytes(seconds)
		SetShaderValue(shader, secondsLoc, varptr(:seconds2,:void), UNIFORM_FLOAT)

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
