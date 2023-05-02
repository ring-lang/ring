// Copyright (c) 2015 Ramon Santamaria (@raysan5)
// Ported to RingRayLib by Ring Team

load "raylib.ring"

GLSL_VERSION = 330

func main 

    screenWidth  = 800
    screenHeight = 450

    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - shapes and texture shaders")

    fudesumi = LoadTexture("images/fudesumi.png")
   
    shader   = LoadShader("", "shaders/grayscale.fs")

    SetTargetFPS(60)

    while (!WindowShouldClose())

        BeginDrawing()

            ClearBackground(RAYWHITE)

            DrawText("USING DEFAULT SHADER", 20, 40, 10, RED)

            DrawCircle(80, 120, 35, DARKBLUE)
            DrawCircleGradient(80, 220, 60, GREEN, SKYBLUE)
            DrawCircleLines(80, 340, 80, DARKBLUE)

            // Activate our custom shader to be applied on next shapes/textures drawings
            BeginShaderMode(shader)

                DrawText("USING CUSTOM SHADER", 190, 40, 10, RED)

                DrawRectangle(250 - 60, 90, 120, 60, RED)
                DrawRectangleGradientH(250 - 90, 170, 180, 130, MAROON, GOLD)
                DrawRectangleLines(250 - 40, 320, 80, 60, ORANGE)

            // Activate our default shader for next drawings
            EndShaderMode()

            DrawText("USING DEFAULT SHADER", 370, 40, 10, RED)

            DrawTriangle(Vector2(430, 80),
                         Vector2(430 - 60, 150),
                         Vector2(430 + 60, 150), VIOLET)

            DrawTriangleLines(Vector2(430, 160),
                              Vector2(430 - 20, 230),
                              Vector2(430 + 20, 230), DARKBLUE)

            DrawPoly(Vector2(430, 320), 6, 80, 0, BROWN)

            // Activate our custom shader to be applied on next shapes/textures drawings
            BeginShaderMode(shader)

                DrawTexture(fudesumi, 500, -30, WHITE)

            // Activate our default shader for next drawings
            EndShaderMode()

            DrawText("(c) Fudesumi sprite by Eiden Marsal", 380, screenHeight - 20, 10, GRAY)

        EndDrawing()

    end

    UnloadShader(shader) 
    UnloadTexture(fudesumi)  

    CloseWindow()             