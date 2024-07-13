load "raylib5.ring"

screenWidth  = 800
screenHeight = 450
InitWindow(screenWidth, screenHeight, "raylib [core] example - Two Cubes")

camera = Camera3D(
	10, 10, 10,
	0, 0, 0 ,
	0, 1, 0 ,
	45,
	CAMERA_PERSPECTIVE
)

cubePosition1 = Vector3( 0, 1, 4 )
cubePosition2 = Vector3( 0, 1, -4 )
cubeSize = Vector3( 2, 2, 2 )

ray = Ray(0,0,0,0,0,0)

collision1 = false
collision2 = false

SetTargetFPS(60)

while !WindowShouldClose()

        UpdateCamera(camera,CAMERA_FREE)

        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            if !collision1
                ray = GetMouseRay(GetMousePosition(), camera)

                collision1 = GetRayCollisionBox(ray,
 		BoundingBox( cubePosition1.x - cubeSize.x/2, cubePosition1.y - cubeSize.y/2, cubePosition1.z - cubeSize.z/2,
    		cubePosition1.x + cubeSize.x/2, cubePosition1.y + cubeSize.y/2, cubePosition1.z + cubeSize.z/2 ) )
		collision1 = collision1.hit
            else 
                collision1 = false
            ok
            if  !collision2
                ray = GetMouseRay(GetMousePosition(), camera)

                collision2 = GetRayCollisionBox(ray,
 		BoundingBox( cubePosition2.x - cubeSize.x/2, cubePosition2.y - cubeSize.y/2, cubePosition2.z - cubeSize.z/2,
    		cubePosition2.x + cubeSize.x/2, cubePosition2.y + cubeSize.y/2, cubePosition2.z + cubeSize.z/2 ) )
		collision2 = collision2.hit
            else 
                collision2 = false
 	    ok
	ok

        BeginDrawing()

            ClearBackground(RAYWHITE)

            BeginMode3D(camera)

                 if collision1
                    DrawCube(cubePosition1, cubeSize.x, cubeSize.y, cubeSize.z, RED)
                    DrawCubeWires(cubePosition1, cubeSize.x, cubeSize.y, cubeSize.z, MAROON)

                    DrawCubeWires(cubePosition1, cubeSize.x + 0.2f, cubeSize.y + 0.2f, cubeSize.z + 0.2f, GREEN)
                    collision1 = true
                 else
                    DrawCube(cubePosition1, cubeSize.x, cubeSize.y, cubeSize.z, GRAY)
                    DrawCubeWires(cubePosition1, cubeSize.x, cubeSize.y, cubeSize.z, DARKGRAY)
                    collision1 = false
                 ok

                 if collision2
                    DrawCube(cubePosition2, cubeSize.x, cubeSize.y, cubeSize.z, RED)
                    DrawCubeWires(cubePosition2, cubeSize.x, cubeSize.y, cubeSize.z, MAROON)

                    DrawCubeWires(cubePosition2, cubeSize.x + 0.2f, cubeSize.y + 0.2f, cubeSize.z + 0.2f, GREEN)
                    collision2 = true
                 else
                    DrawCube(cubePosition2, cubeSize.x, cubeSize.y, cubeSize.z, GRAY)
                    DrawCubeWires(cubePosition2, cubeSize.x, cubeSize.y, cubeSize.z, DARKGRAY)
                    collision2 = false
                 ok


                DrawRay(ray, MAROON)
                DrawGrid(10, 1)

            EndMode3D()

            DrawText("Try selecting the box with mouse!", 240, 10, 20, DARKGRAY)

            if collision1 or collision2  DrawText("BOX SELECTED", (screenWidth - MeasureText("BOX SELECTED", 30)) / 2, screenHeight * 0.1f, 30, GREEN) ok

            DrawFPS(10, 10)

        EndDrawing()
end

CloseWindow()
