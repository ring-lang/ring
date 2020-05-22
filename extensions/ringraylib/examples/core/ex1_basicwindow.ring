#===================================================================#
# Based on Original Sample from RayLib (https://www.raylib.com/)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib.ring"

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

