#===================================================================#
# Copyright (c) 2O17 Wilhem Barbier (@nounoursheureux)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

NUM_TEXTURES = 7
textures     = list(7)

screenWidth  = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - procedural images generation")

verticalGradient = GenImageGradientLinear(screenWidth, screenHeight, 0, RED, BLUE);
horizontalGradient = GenImageGradientLinear(screenWidth, screenHeight, 90, RED, BLUE);
diagonalGradient = GenImageGradientLinear(screenWidth, screenHeight, 45, RED, BLUE);
radialGradient = GenImageGradientRadial(screenWidth, screenHeight, 0.0f, WHITE, BLACK);
squareGradient = GenImageGradientSquare(screenWidth, screenHeight, 0.0f, WHITE, BLACK);
checked = GenImageChecked(screenWidth, screenHeight, 32, 32, RED, BLUE);
whiteNoise = GenImageWhiteNoise(screenWidth, screenHeight, 0.5f);
perlinNoise = GenImagePerlinNoise(screenWidth, screenHeight, 50, 50, 4.0f);
cellular = GenImageCellular(screenWidth, screenHeight, 32);

/*
verticalGradient   = GenImageGradientV(screenWidth, screenHeight, RED, BLUE)
horizontalGradient = GenImageGradientH(screenWidth, screenHeight, RED, BLUE)
radialGradient     = GenImageGradientRadial(screenWidth, screenHeight, 0.0, WHITE, BLACK)
checked            = GenImageChecked(screenWidth, screenHeight, 32, 32, RED, BLUE)
whiteNoise         = GenImageWhiteNoise(screenWidth, screenHeight, 0.5)
perlinNoise        = GenImagePerlinNoise(screenWidth, screenHeight, 50, 50, 4.0)
cellular           = GenImageCellular(screenWidth, screenHeight, 32)
*/
textures[NUM_TEXTURES] =  0 
		   
textures[1] = LoadTextureFromImage(verticalGradient)
textures[2] = LoadTextureFromImage(horizontalGradient)
textures[3] = LoadTextureFromImage(radialGradient)
textures[4] = LoadTextureFromImage(checked)
textures[5] = LoadTextureFromImage(whiteNoise)
textures[6] = LoadTextureFromImage(perlinNoise)
textures[7] = LoadTextureFromImage(cellular)

UnloadImage(verticalGradient)
UnloadImage(horizontalGradient)
UnloadImage(radialGradient)
UnloadImage(checked)
UnloadImage(whiteNoise)
UnloadImage(perlinNoise)
UnloadImage(cellular)

currentTexture = 1  

SetTargetFPS(10)
 
while !WindowShouldClose()

	if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_RIGHT)
		currentTexture++
		if currentTexture > NUM_TEXTURES  currentTexture = 1 ok
	ok

	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawTexture(textures[currentTexture], 0, 0, WHITE)

		DrawRectangle(30, 400, 325, 30, Fade(SKYBLUE, 0.5))
		DrawRectangleLines(30, 400, 325, 30, Fade(WHITE, 0.5))
		DrawText("MOUSE LEFT BUTTON to CYCLE PROCEDURAL TEXTURES", 40, 410, 10, WHITE)

		switch(currentTexture)
			on 1  DrawText("VERTICAL GRADIENT", 560, 10, 20, RAYWHITE)  
			on 2  DrawText("HORIZONTAL GRADIENT", 540, 10, 20, RAYWHITE)
			on 3  DrawText("RADIAL GRADIENT", 580, 10, 20, LIGHTGRAY)   
			on 4  DrawText("CHECKED", 680, 10, 20, RAYWHITE)            
			on 5  DrawText("WHITE NOISE", 640, 10, 20, RED)             
			on 6  DrawText("PERLIN NOISE", 630, 10, 20, RAYWHITE)       
			on 7  DrawText("CELLULAR", 670, 10, 20, RAYWHITE)           
		off 

	EndDrawing()

end

for i = 1 to  NUM_TEXTURES
	UnloadTexture( textures[i] )
next 

CloseWindow()
