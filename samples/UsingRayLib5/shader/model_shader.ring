// Copyright (c) 2014 Ramon Santamaria (@raysan5)
// Ported to RingRayLib by Ring Team

load "raylib5.ring"

func main

    screenWidth = 800
    screenHeight = 450

    SetConfigFlags(FLAG_MSAA_4X_HINT)      // Enable Multi Sampling Anti Aliasing 4x (if available)

    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - model shader")

    // Define the camera to look into our 3d world
    camera = camera3D(
	4.0f, 4.0f, 4.0f,
	0.0f, 1.0f, -1.0f,
	0.0f, 1.0f, 0.0f,
	45.0f,CAMERA_PERSPECTIVE)

    model = LoadModel("models/watermill.obj")                   // Load OBJ model
    texture = LoadTexture("models/watermill_diffuse.png")   // Load model texture

    // Load shader for model
    // NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
    shader = LoadShader(NULL, "shaders/grayscale.fs")

    setmodelmaterialshader(model,0,shader)    // Set shader effect to 3d model
    setmodelmaterialtexture(model,0,MAP_DIFFUSE,texture)

    position = Vector3( 0.0f, 0.0f, 0.0f )    // Set model position

    SetTargetFPS(60)                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while !WindowShouldClose()                // Detect window close button or ESC key

        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(camera,CAMERA_FREE)                  // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing()

            ClearBackground(RAYWHITE)

            BeginMode3D(camera)

                DrawModel(model, position, 0.2f, WHITE)   // Draw 3d model with texture

                DrawGrid(10, 1.0f)     // Draw a grid

            EndMode3D()

            DrawText("(c) Watermill 3D model by Alberto Cano", screenWidth - 210, screenHeight - 20, 10, GRAY)

            DrawFPS(10, 10)

        EndDrawing()
        //----------------------------------------------------------------------------------
    end

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadShader(shader)       // Unload shader
    UnloadTexture(texture)     // Unload texture
    UnloadModel(model)         // Unload model

    CloseWindow()              // Close window and OpenGL context

