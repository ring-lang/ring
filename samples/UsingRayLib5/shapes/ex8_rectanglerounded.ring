#===============================================================================#
# Copyright (c) 2018 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===============================================================================#

load "raylib5.ring"

// Initialization
//--------------------------------------------------------------------------------------
screenWidth	= 800
screenHeight	= 450

InitWindow(screenWidth, screenHeight, "Rectangle Rounded")

roundness	= 0.2
width		= 200
height		= 100
segments	= 0
lineThick	= 1

drawRect	= false
drawRoundedRect	= true
drawRoundedLines= false

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while !WindowShouldClose()    // Detect window close button or ESC key

	// Update
	//----------------------------------------------------------------------------------

	rec = Rectangle( (GetScreenWidth() - width - 250)/2, (GetScreenHeight() - height)/2, Width, Height )
	//----------------------------------------------------------------------------------

	// Draw
	//----------------------------------------------------------------------------------
	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawLine(560, 0, 560, GetScreenHeight(), Fade(LIGHTGRAY, 0.6))
		DrawRectangle(560, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3))

		if drawRect
		   DrawRectangleRec(rec, Fade(GOLD, 0.6))
		ok
		if drawRoundedRect
			DrawRectangleRounded(rec, roundness, segments, Fade(MAROON, 0.2))
		ok
		if drawRoundedLines
			DrawRectangleRoundedLines(rec,roundness, segments, lineThick, Fade(MAROON, 0.4))
		ok
		// Draw GUI controls
		//------------------------------------------------------------------------------

		width = GuiSliderBar(Rectangle( 640, 40, 105, 20 ), "Width", width, 0, GetScreenWidth() - 300, true )
		height = GuiSliderBar(Rectangle( 640, 70, 105, 20 ), "Height", height, 0, GetScreenHeight() - 50, true)
		
		roundness = GuiSliderBar(Rectangle( 640, 140, 105, 20 ), "Roundness", roundness, 0, 1, true)
		lineThick = GuiSliderBar(Rectangle( 640, 170, 105, 20 ), "Thickness", lineThick, 0, 20, true)
		segments = GuiSliderBar(Rectangle( 640, 240, 105, 20 ), "Segments", segments, 0, 60, true)

		drawRoundedRect = GuiCheckBox(Rectangle( 640, 320, 20, 20 ), "DrawRoundedRect", drawRoundedRect)
		drawRoundedLines = GuiCheckBox(Rectangle( 640, 350, 20, 20 ), "DrawRoundedLines", drawRoundedLines)
		drawRect = GuiCheckBox(Rectangle( 640, 380, 20, 20 ), "DrawRect", drawRect)
		//------------------------------------------------------------------------------

		if segments >= 4
			text1 = "MANUAL"
			color = MAROON
		else
			text1 = "AUTO"
			color = DARKGRAY
		ok

		DrawText("MODE: " + text1, 640, 280, 10, color)

		DrawFPS(10, 10)

	EndDrawing()
	//----------------------------------------------------------------------------------
end

//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------

