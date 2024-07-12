#===================================================================#
# Copyright (c) 2O17 Wilhem Barbier (@nounoursheureux)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 600

InitWindow(screenWidth, screenHeight, "raylib [textures] examples - texture source and destination rectangles")

// NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

scarfy = LoadTexture("RingLogo.png")        // Texture loading

frameWidth = scarfy.width
frameHeight = scarfy.height

// Source rectangle (part of the texture to use for drawing)
sourceRec = Rectangle( 0.0, 0.0, frameWidth, frameHeight )

// Destination rectangle (screen rectangle where drawing part of texture)
destRec = Rectangle( screenWidth/2, screenHeight/2, frameWidth*2, frameHeight*2 )

// Origin of the texture (rotation/scale point), it's relative to destination rectangle size
origin = Vector2( frameWidth, frameHeight )

rotation = 0

SetTargetFPS(60)

while !WindowShouldClose()

	rotation = rotation+1

	BeginDrawing()

		ClearBackground(RAYWHITE)

		// NOTE: Using DrawTexturePro() we can easily rotate and scale the part of the texture we draw
		// sourceRec defines the part of the texture we use for drawing
		// destRec defines the rectangle where our texture part will fit (scaling it to fit)
		// origin defines the point of the texture used as reference for rotation and scaling
		// rotation defines the texture rotation (using origin as rotation point)
		DrawTexturePro(scarfy, sourceRec, destRec, origin, rotation, WHITE)

		DrawLine(destRec.x, 0, destRec.x, screenHeight, GRAY)
		DrawLine(0, destRec.y, screenWidth, destRec.y, GRAY)

		DrawText("(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY)

	EndDrawing()

end

UnloadTexture(scarfy)        // Texture unloading

CloseWindow()
