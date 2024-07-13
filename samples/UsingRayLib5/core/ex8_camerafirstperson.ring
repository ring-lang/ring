#===================================================================#
# Copyright (c) 2015 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

MAX_COLUMNS = 20

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person")

camera = Camera3d(
    4, 2, 4,
    0, 1, 0,
    0, 1, 0,
    60,
    CAMERA_PERSPECTIVE
)

heights = list(MAX_COLUMNS)
positions = list(MAX_COLUMNS)
for item in positions item = vector3(0,0,0) next 
colors = list(MAX_COLUMNS)
for item in colors item = BLACK next

for i = 1 to  MAX_COLUMNS 
	heights[i] = GetRandomValue(1, 12)
	positions[i] = Vector3(GetRandomValue(-15, 15), heights[i]/2, GetRandomValue(-15, 15) )
	colors[i] = RAYLibColor(GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 )
next

SetTargetFPS(60)                     

while !WindowShouldClose()

	UpdateCamera(camera,CAMERA_FIRST_PERSON)
	BeginDrawing()

	ClearBackground(RAYWHITE)

	BeginMode3D(camera)

		DrawPlane(Vector3( 0, 0, 0 ), Vector2(32, 32 ), LIGHTGRAY) // Draw ground
                DrawCube(Vector3( -16, 2.5, 0 ), 1, 5, 32, BLUE)     // Draw a blue wall
                DrawCube(Vector3( 16, 2.5, 0 ), 1, 5, 32, LIME)      // Draw a green wall
                DrawCube(Vector3( 0, 2.5, 16 ), 32, 5, 1, GOLD)      // Draw a yellow wall

                for i = 1 to  MAX_COLUMNS 
			DrawCube(positions[i], 2, heights[i], 2, colors[i])
			DrawCubeWires(positions[i], 2, heights[i], 2, MAROON)
                next

	EndMode3D()

	DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f))
	DrawRectangleLines( 10, 10, 220, 70, BLUE)

	DrawText("First person camera default controls:", 20, 20, 10, BLACK)
	DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY)
	DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY)

        EndDrawing()
end 
    
CloseWindow()
