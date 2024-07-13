#===================================================================#
# Copyright (c) 2013-2019 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - following eyes")

scleraLeftPosition = Vector2( GetScreenWidth()/2 - 100, GetScreenHeight()/2 )
scleraRightPosition = Vector2( GetScreenWidth()/2 + 100, GetScreenHeight()/2 )
scleraRadius = 80

irisLeftPosition = Vector2( GetScreenWidth()/2 - 100, GetScreenHeight()/2 )
irisRightPosition = Vector2( GetScreenWidth()/2 + 100, GetScreenHeight()/2 )
irisRadius = 24

angle = 0.0
dx = 0.0 dy = 0.0 dxx = 0.0 dyy = 0.0

SetTargetFPS(60) 

while !WindowShouldClose()

	irisLeftPosition = GetMousePosition()
	irisRightPosition = GetMousePosition()

	// Check not inside the left eye sclera
	if !CheckCollisionPointCircle(irisLeftPosition, scleraLeftPosition, scleraRadius - 20)
		dx = irisLeftPosition.x - scleraLeftPosition.x
		dy = irisLeftPosition.y - scleraLeftPosition.y

		angle = atan2(dy, dx)

		dxx = (scleraRadius - irisRadius)*cos(angle)
		dyy = (scleraRadius - irisRadius)*sin(angle)

		irisLeftPosition.x = scleraLeftPosition.x + dxx
		irisLeftPosition.y = scleraLeftPosition.y + dyy
	ok

	// Check not inside the right eye sclera
	if !CheckCollisionPointCircle(irisRightPosition, scleraRightPosition, scleraRadius - 20)
		dx = irisRightPosition.x - scleraRightPosition.x
		dy = irisRightPosition.y - scleraRightPosition.y

		angle = atan2(dy, dx)

		dxx = (scleraRadius - irisRadius)*cos(angle)
		dyy = (scleraRadius - irisRadius)*sin(angle)

		irisRightPosition.x = scleraRightPosition.x + dxx
		irisRightPosition.y = scleraRightPosition.y + dyy
	ok

	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawCircleV(scleraLeftPosition, scleraRadius, LIGHTGRAY)
		DrawCircleV(irisLeftPosition, irisRadius, BROWN)
		DrawCircleV(irisLeftPosition, 10, BLACK)

		DrawCircleV(scleraRightPosition, scleraRadius, LIGHTGRAY)
		DrawCircleV(irisRightPosition, irisRadius, DARKGREEN)
		DrawCircleV(irisRightPosition, 10, BLACK)

		DrawFPS(10, 10)

	EndDrawing()

end

CloseWindow()
