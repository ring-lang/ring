#===================================================================#
# Copyright (c) 2019 Berni (@Berni8k) and Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - input multitouch")

ballPosition = Vector2(-100, -100)
ballColor = BEIGE

touchCounter = 0
touchPosition = vector2(0,0)

MAX_TOUCH_POINTS = 5

SetTargetFPS(60)

while !WindowShouldClose()

        ballPosition = GetMousePosition()

        ballColor = BEIGE

        if IsMouseButtonDown(MOUSE_LEFT_BUTTON) ballColor = MAROON ok
        if IsMouseButtonDown(MOUSE_MIDDLE_BUTTON) ballColor = LIME ok
        if IsMouseButtonDown(MOUSE_RIGHT_BUTTON) ballColor = DARKBLUE ok

        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) touchCounter = 10 ok
        if IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON) touchCounter = 10 ok
        if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) touchCounter = 10 ok

        if touchCounter > 0 touchCounter-- ok

        BeginDrawing()

            ClearBackground(RAYWHITE)

            for i = 0 to MAX_TOUCH_POINTS-1
                touchPosition = GetTouchPosition(i)  

                if touchPosition.x >= 0 && touchPosition.y >= 0
                    DrawCircleV(touchPosition, 34, ORANGE)
                    DrawText(""+ i, touchPosition.x - 10, touchPosition.y - 70, 40, BLACK)
                ok
            next

            DrawCircleV(ballPosition, 30 + (touchCounter*3), ballColor)

            DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY)
            DrawText("touch the screen at multiple locations to get multiple balls", 10, 30, 20, DARKGRAY)

        EndDrawing()

end

CloseWindow()     
