#===================================================================#
# Copyright (c) 2017 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

SetConfigFlags(FLAG_MSAA_4X_HINT)
InitWindow(screenWidth, screenHeight, "raylib [shapes] example - cubic-bezier lines")

start = Vector2(0,0)
endvec = Vector2(screenWidth,screenHeight)

SetTargetFPS(60)  

while (!WindowShouldClose())  

	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		start = GetMousePosition() 
	else (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		  endvec = GetMousePosition()
	ok
	

	BeginDrawing()

		ClearBackground(RAYWHITE)
		DrawText("USE MOUSE LEFT-RIGHT CLICK to DEFINE LINE START and END POINTS", 15, 20, 20, GRAY)
		DrawLineBezier(start, endvec, 2.0, RED)

	EndDrawing()

end

CloseWindow()
