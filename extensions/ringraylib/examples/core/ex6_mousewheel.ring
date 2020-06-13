/*******************************************************************************************
*
*   raylib [core] examples - Mouse wheel input
*
*   This test has been created using raylib 1.1 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#===================================================================#
# Based on Original Sample from RayLib (https://www.raylib.com/)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib.ring"

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
