#===================================================================#
# Copyright (c) 2015 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d picking")

camera = Camera3D(
	10, 10, 10,
	0, 0, 0 ,
	0, 1, 0 ,
	45,
	CAMERA_PERSPECTIVE
)

cubePosition = Vector3( 0, 1, 0 )
cubeSize = Vector3( 2, 2, 2 )

ray = Ray(0,0,0,0,0,0)

collision = false

SetTargetFPS(60)

while !WindowShouldClose()

        UpdateCamera(camera,CAMERA_FREE)

        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            if !collision
                ray = GetMouseRay(GetMousePosition(), camera)

                collision = GetRayCollisionBox(ray,
 		BoundingBox( cubePosition.x - cubeSize.x/2, cubePosition.y - cubeSize.y/2, cubePosition.z - cubeSize.z/2,
    		cubePosition.x + cubeSize.x/2, cubePosition.y + cubeSize.y/2, cubePosition.z + cubeSize.z/2 ) )
		collision = collision.hit
            else collision = false
 	    ok
	ok

        BeginDrawing()

            ClearBackground(RAYWHITE)

            BeginMode3D(camera)

                if collision
                    DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RED)
                    DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, MAROON)

                    DrawCubeWires(cubePosition, cubeSize.x + 0.2f, cubeSize.y + 0.2f, cubeSize.z + 0.2f, GREEN)
                else
                    DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, GRAY)
                    DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, DARKGRAY)
                ok

                DrawRay(ray, MAROON)
                DrawGrid(10, 1)

            EndMode3D()

            DrawText("Try selecting the box with mouse!", 240, 10, 20, DARKGRAY)

            if collision  DrawText("BOX SELECTED", (screenWidth - MeasureText("BOX SELECTED", 30)) / 2, screenHeight * 0.1f, 30, GREEN) ok

            DrawFPS(10, 10)

        EndDrawing()
end

CloseWindow()
