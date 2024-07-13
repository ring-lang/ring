#===================================================================#
# Copyright (c) 2014 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse wheel")

boxPositionY = screenHeight/2 - 40
scrollSpeed = 4            

SetTargetFPS(60)  

while !WindowShouldClose()
        boxPositionY -= (GetMouseWheelMove()*scrollSpeed)

        BeginDrawing()

            ClearBackground(RAYWHITE)

            DrawRectangle(screenWidth/2 - 40, boxPositionY, 80, 80, MAROON)

            DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, GRAY)
            DrawText("Box position Y: "+boxPositionY, 10, 40, 20, LIGHTGRAY)

        EndDrawing()
end

CloseWindow()
