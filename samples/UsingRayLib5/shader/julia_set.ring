// Copyright (c) 2019 eggmund (@eggmund) and Ramon Santamaria (@raysan5)
// Ported to RingRayLib by Ring Team

load "raylib.ring"

POINTS_OF_INTEREST = [
    [ -0.348827, 0.607167 ],
    [ -0.786268, 0.169728 ],
    [ -0.8, 0.156 ],
    [ 0.285, 0.0 ],
    [ -0.835, -0.2321 ],
    [ -0.70176, -0.3842 ]
]

func main

    screenWidth = 800
    screenHeight = 450

    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - julia sets")

    // Load julia set shader
    // NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
    shader = LoadShader(NULL, "shaders/julia_set.fs")

    // c constant to use in z^2 + c
    c = [ POINTS_OF_INTEREST[1][1], POINTS_OF_INTEREST[1][2] ]

    // Offset and zoom to draw the julia set at. (centered on screen and default size)
    offset = [ - screenWidth/2, -screenHeight/2 ]
    zoom = 1.0f

    offsetSpeed = Vector2( 0.0f, 0.0f )

    // Get variable (uniform) locations on the shader to connect with the program
    // NOTE: If uniform variable could not be found in the shader, function returns -1
    cLoc = GetShaderLocation(shader, "c")
    zoomLoc = GetShaderLocation(shader, "zoom")
    offsetLoc = GetShaderLocation(shader, "offset")

    // Tell the shader what the screen dimensions, zoom, offset and c are
    screenDims = [ screenWidth, screenHeight ]
    SetShaderVec2(shader, GetShaderLocation(shader, "screenDims"), screenDims)

    SetShaderVec2(shader, cLoc, c)
    SetShaderFloat(shader, zoomLoc, zoom)
    SetShaderVec2(shader, offsetLoc, offset)

    // Create a RenderTexture2D to be used for render to texture
    target = LoadRenderTexture(screenWidth, screenHeight)

    incrementSpeed = 0        // Multiplier of speed to change c value
    showControls = true       // Show controls
    pause = false             // Pause animation

    SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while !WindowShouldClose()    // Detect window close button or ESC key

        // Press [1 - 6] to reset c to a point of interest
        if  IsKeyPressed(KEY_ONE) ||
            IsKeyPressed(KEY_TWO) ||
            IsKeyPressed(KEY_THREE) ||
            IsKeyPressed(KEY_FOUR) ||
            IsKeyPressed(KEY_FIVE) ||
            IsKeyPressed(KEY_SIX)

            if IsKeyPressed(KEY_ONE) 
                 c[1] = POINTS_OF_INTEREST[1][1] 
                 c[2] = POINTS_OF_INTEREST[1][2]
            elseif IsKeyPressed(KEY_TWO) 
                 c[1] = POINTS_OF_INTEREST[2][1]
                 c[2] = POINTS_OF_INTEREST[2][2]
            elseif IsKeyPressed(KEY_THREE)
                 c[1] = POINTS_OF_INTEREST[3][1]
                 c[2] = POINTS_OF_INTEREST[3][2]
            elseif IsKeyPressed(KEY_FOUR) 
                 c[1] = POINTS_OF_INTEREST[4][1]
                 c[2] = POINTS_OF_INTEREST[4][2]
            elseif IsKeyPressed(KEY_FIVE) 
                 c[1] = POINTS_OF_INTEREST[5][1]
                 c[2] = POINTS_OF_INTEREST[5][2]
            elseif IsKeyPressed(KEY_SIX) 
                 c[1] = POINTS_OF_INTEREST[6][1]
                 c[2] = POINTS_OF_INTEREST[6][2]
            ok

            SetShaderVec2(shader, cLoc, c)
        ok

        if IsKeyPressed(KEY_SPACE) 
           pause = !pause                 // Pause animation (c change)
        ok

        if IsKeyPressed(KEY_F1) 
           showControls = !showControls  // Toggle whether or not to show controls
        ok

        if !pause

            if IsKeyPressed(KEY_RIGHT)
                incrementSpeed++ 
            elseif  IsKeyPressed(KEY_LEFT) 
                incrementSpeed-- 
            ok

            // TODO: The idea is to zoom and move around with mouse
            // Probably offset movement should be proportional to zoom level
            if IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
                if IsMouseButtonDown(MOUSE_LEFT_BUTTON) zoom += zoom*0.003f ok
                if IsMouseButtonDown(MOUSE_RIGHT_BUTTON) zoom -= zoom*0.003f ok

                mousePos = GetMousePosition()

                offsetSpeed.x = mousePos.x - screenWidth/2
                offsetSpeed.y = mousePos.y - screenHeight/2

                // Slowly move camera to targetOffset
                offset[1] += GetFrameTime()*offsetSpeed.x*0.8f
                offset[2] += GetFrameTime()*offsetSpeed.y*0.8f
            else 
                offsetSpeed = Vector2( 0.0f, 0.0f )
            ok

            SetShaderFloat(shader, zoomLoc, zoom)
            SetShaderVec2(shader, offsetLoc, offset)

            // Increment c value with time
            amount = GetFrameTime()*incrementSpeed*0.0005f
            c[1] += amount
            c[2] += amount

            SetShaderVec2(shader, cLoc, c)
        ok
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing()

            ClearBackground(BLACK)         // Clear the screen of the previous frame.

            // Using a render texture to draw Julia set
            BeginTextureMode(target)       // Enable drawing to texture
                ClearBackground(BLACK)     // Clear the render texture

                // Draw a rectangle in shader mode to be used as shader canvas
                // NOTE: Rectangle uses font white character texture coordinates,
                // so shader can not be applied here directly because input vertexTexCoord
                // do not represent full screen coordinates (space where want to apply shader)
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK)
            EndTextureMode()

            // Draw the saved texture and rendered julia set with shader
            // NOTE: We do not invert texture on Y, already considered inside shader
            BeginShaderMode(shader)
                DrawTexture(target.texture, 0, 0, WHITE)
            EndShaderMode()

            if showControls
                DrawText("Press Mouse buttons right/left to zoom in/out and move", 10, 15, 10, RAYWHITE)
                DrawText("Press KEY_F1 to toggle these controls", 10, 30, 10, RAYWHITE)
                DrawText("Press KEYS [1 - 6] to change point of interest", 10, 45, 10, RAYWHITE)
                DrawText("Press KEY_LEFT | KEY_RIGHT to change speed", 10, 60, 10, RAYWHITE)
                DrawText("Press KEY_SPACE to pause movement animation", 10, 75, 10, RAYWHITE)
            ok

        EndDrawing()
        //----------------------------------------------------------------------------------
    end

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadShader(shader)           // Unload shader
    UnloadRenderTexture(target)    // Unload render texture

    CloseWindow()                  // Close window and OpenGL context

