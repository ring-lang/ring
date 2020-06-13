/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
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

screenWidth  = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input")
ballPosition = Vector2(screenWidth/2, screenHeight/2)
SetTargetFPS(60)

while !WindowShouldClose()
        if IsKeyDown(KEY_RIGHT)	ballPosition.x += 2 ok
        if IsKeyDown(KEY_LEFT) 	ballPosition.x -= 2 ok
        if IsKeyDown(KEY_UP) 	ballPosition.y -= 2 ok
        if IsKeyDown(KEY_DOWN) 	ballPosition.y += 2 ok
        BeginDrawing()
		ClearBackground(RAYWHITE)
		DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY)
		DrawCircleV(ballPosition, 50, MAROON)
        EndDrawing()
end    

CloseWindow()
