load "raylib5.ring"

screenWidth 	= 1024
screenHeight 	= 768

InitWindow(screenWidth, screenHeight, "Full Screen")
ToggleFullScreen()

SetTargetFPS(60)

while !WindowShouldClose() 
	BeginDrawing()
		ClearBackground(DARKBLUE)
		DrawText("Count from 1 to 10", 190, 200, 20, Yellow)
		for t = 1 to 10
			DrawText("Number: " + t, 190, 200+(30*t), 20, WHITE)
		next 
        EndDrawing()
end

CloseWindow()

