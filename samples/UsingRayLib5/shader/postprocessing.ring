// Copyright (c) 2015 Ramon Santamaria (@raysan5)
// Ported to RingRayLib by Ring Team

load "raylib5.ring"

MAX_POSTPRO_SHADERS = 12

FX_GRAYSCALE = 1
FX_POSTERIZATION = 2
FX_DREAM_VISION = 3
FX_PIXELIZER = 4
FX_CROSS_HATCHING = 5
FX_CROSS_STITCHING = 6
FX_PREDATOR_VIEW = 7
FX_SCANLINES = 8
FX_FISHEYE = 9
FX_SOBEL = 10
FX_BLOOM = 11
FX_BLUR = 12

postproShaderText = [
    "GRAYSCALE",
    "POSTERIZATION",
    "DREAM_VISION",
    "PIXELIZER",
    "CROSS_HATCHING",
    "CROSS_STITCHING",
    "PREDATOR_VIEW",
    "SCANLINES",
    "FISHEYE",
    "SOBEL",
    "BLOOM",
    "BLUR"
]

func main

    screenWidth = 800
    screenHeight = 450

    SetConfigFlags(FLAG_MSAA_4X_HINT)      // Enable Multi Sampling Anti Aliasing 4x (if available)

    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - postprocessing shader")

    // Define the camera to look into our 3d world
    camera = Camera3D( 2.0f, 3.0f, 2.0f ,
	      0.0f, 1.0f, 0.0f , 
	      0.0f, 1.0f, 0.0f , 
              45.0f, 0 )

    model = LoadModel("models/church.obj")                 		// Load OBJ model
    texture = LoadTexture("models/church_diffuse.png") 	// Load model texture (diffuse map)
    setmodelmaterialtexture(model,0,MAP_DIFFUSE,texture)
    position = Vector3( 0.0f, 0.0f, 0.0f )                             // Set model position

    // Load all postpro shaders
    // NOTE 1: All postpro shader use the base vertex shader (DEFAULT_VERTEX_SHADER)
    // NOTE 2: We load the correct shader depending on GLSL version

    shaders = list(MAX_POSTPRO_SHADERS)

    // NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
    shaders[FX_GRAYSCALE] = LoadShader("", "shaders/grayscale.fs")
    shaders[FX_POSTERIZATION] = LoadShader("", "shaders/posterization.fs")
    shaders[FX_DREAM_VISION] = LoadShader("", "shaders/dream_vision.fs")
    shaders[FX_PIXELIZER] = LoadShader("", "shaders/pixelizer.fs")
    shaders[FX_CROSS_HATCHING] = LoadShader("", "shaders/cross_hatching.fs")
    shaders[FX_CROSS_STITCHING] = LoadShader("", "shaders/cross_stitching.fs")
    shaders[FX_PREDATOR_VIEW] = LoadShader("", "shaders/predator.fs")
    shaders[FX_SCANLINES] = LoadShader("", "shaders/scanlines.fs")
    shaders[FX_FISHEYE] = LoadShader("", "shaders/fisheye.fs")
    shaders[FX_SOBEL] = LoadShader("", "shaders/sobel.fs")
    shaders[FX_BLOOM] = LoadShader("", "shaders/bloom.fs")
    shaders[FX_BLUR] = LoadShader("", "shaders/blur.fs")

    currentShader = FX_GRAYSCALE

    // Create a RenderTexture2D to be used for render to texture
    target = LoadRenderTexture(screenWidth, screenHeight)

    SetTargetFPS(60)                       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while !WindowShouldClose()            // Detect window close button or ESC key

        UpdateCamera(camera,CAMERA_ORBITAL)              // Update camera

        if (IsKeyPressed(KEY_RIGHT)) 
		currentShader++
        elseif (IsKeyPressed(KEY_LEFT)) 
		currentShader--
	ok

        if (currentShader >= MAX_POSTPRO_SHADERS) 
		currentShader = 1
        elseif (currentShader < 1) 
		currentShader = MAX_POSTPRO_SHADERS - 1
	ok

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing()

            ClearBackground(RAYWHITE)

            BeginTextureMode(target)       // Enable drawing to texture

                ClearBackground(RAYWHITE)  // Clear texture background

                BeginMode3D(camera)        // Begin 3d mode drawing

                    DrawModel(model, position, 0.1f, WHITE)   // Draw 3d model with texture

                    DrawGrid(10, 1.0f)     // Draw a grid

                EndMode3D()                // End 3d mode drawing, returns to orthographic 2d mode

            EndTextureMode()               // End drawing to texture (now we have a texture available for next passes)

            // Render previously generated texture using selected postpro shader
            BeginShaderMode(shaders[currentShader])

                // NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
                DrawTextureRec(target.texture, 
				Rectangle( 0, 0, target.texture.width,-target.texture.height)
				, Vector2( 0, 0 ), WHITE)

            EndShaderMode()

            // Draw 2d shapes and text over drawn texture
            DrawRectangle(0, 9, 580, 30, Fade(LIGHTGRAY, 0.7f))

            DrawText("(c) Church 3D model by Alberto Cano", screenWidth - 200, screenHeight - 20, 10, GRAY)

            DrawText("CURRENT POSTPRO SHADER:", 10, 15, 20, BLACK)
            DrawText(postproShaderText[currentShader], 330, 15, 20, RED)
            DrawText("< >", 540, 10, 30, DARKBLUE)

            DrawFPS(700, 15)

        EndDrawing()
        //----------------------------------------------------------------------------------
    end

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // Unload all postpro shaders
    for i = 1 to MAX_POSTPRO_SHADERS
	UnloadShader(shaders[i])
    next

    UnloadTexture(texture)         // Unload texture
    UnloadModel(model)             // Unload model
    UnloadRenderTexture(target)    // Unload render texture

    CloseWindow()                  // Close window and OpenGL context
