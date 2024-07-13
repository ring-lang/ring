#===================================================================#
# raylib [core] example - Basic window
# Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth 	= 800
screenHeight 	= 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window")

SetTargetFPS(60)

while !WindowShouldClose() 
	BeginDrawing()
		ClearBackground(RED)
		DrawText("Congrats! You created your first window!", 190, 200, 20, WHITE)
        EndDrawing()
end

CloseWindow()

