#===================================================================#
# Copyright (c) 2015 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free")

camera = Camera3D(
	10, 10, 10,  		// Camera position
        0, 0, 0 ,   		// Camera looking at point
	0, 1, 0,    		// Camera up vector (rotation towards target)
	45,        		// Camera field-of-view Y
    	CAMERA_PERSPECTIVE)	// Camera mode type

cubePosition = Vector3(0, 0, 0)

SetTargetFPS(60)                   

while !WindowShouldClose()

        UpdateCamera(camera,CAMERA_FREE)

        if IsKeyDown("Z") camera.target = Vector3( 0, 0, 0) ok

        BeginDrawing()

            ClearBackground(RAYWHITE)

            BeginMode3D(camera)

                DrawCube(cubePosition, 2, 2, 2, RED)
                DrawCubeWires(cubePosition, 2, 2, 2, MAROON)

                DrawGrid(10, 1)

            EndMode3D()

            DrawRectangle( 10, 10, 320, 133, Fade(SKYBLUE, 0.5))
            DrawRectangleLines( 10, 10, 320, 133, BLUE)

            DrawText("Free camera default controls:", 20, 20, 10, BLACK)
            DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY)
            DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY)
            DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, DARKGRAY)
            DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, DARKGRAY)
            DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, DARKGRAY)

        EndDrawing()
end 

CloseWindow() 
