// raylib [textures] example - Procedural images generation

load "raylib.ring"

NUM_TEXTURES = 8      // Currently we have 7 generation algorithms
textures     = [ 0,0,0,0,0,0,0,0 ]

    // Initialization
    //--------------------------------------------------------------------------------------
	 screenWidth  = 800
	 screenHeight = 450

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - procedural images generation")

    verticalGradient   = GenImageGradientV(     screenWidth, screenHeight, RED, BLUE)
    horizontalGradient = GenImageGradientH(     screenWidth, screenHeight, RED, BLUE)
    radialGradient     = GenImageGradientRadial(screenWidth, screenHeight, 0.0, WHITE, BLACK)
    checked            = GenImageChecked(       screenWidth, screenHeight, 32, 32, RED, BLUE)
    whiteNoise         = GenImageWhiteNoise(    screenWidth, screenHeight, 0.5)
    perlinNoise        = GenImagePerlinNoise(   screenWidth, screenHeight, 50, 50, 4.0)
    cellular           = GenImageCellular(      screenWidth, screenHeight, 32)
	 
See nl+"verticalGradient ===== GenImageGradientV"+nl    See verticalGradient    See nl
See nl+"horizontalGradient ===== GenImageGradientH"+nl  See horizontalGradient  See nl
See nl+"radialGradient ===== GenImageGradientRadial"+nl See radialGradient      See nl
See nl+"checked ===== GenImageChecked"+nl               See checked             See nl
See nl+"whiteNoise ===== GenImageWhiteNoise"+nl         See whiteNoise          See nl
See nl+"perlinNoise ===== GenImagePerlinNoise"+nl       See perlinNoise         See nl
See nl+"cellular ===== GenImageCellular"+nl             See cellular            See nl


    // Texture2D textures[NUM_TEXTURES] = { 0 };
    textures[NUM_TEXTURES] =  0 
               
    textures[1] = LoadTextureFromImage(verticalGradient)
    textures[2] = LoadTextureFromImage(horizontalGradient)
    textures[3] = LoadTextureFromImage(radialGradient)
    textures[4] = LoadTextureFromImage(checked)
    textures[5] = LoadTextureFromImage(whiteNoise)
    textures[6] = LoadTextureFromImage(perlinNoise)
    textures[7] = LoadTextureFromImage(cellular)

See nl+"textures: 0-8"+nl  See textures  See nl
	 
    // Unload image data (CPU RAM)
    UnloadImage(verticalGradient)
    UnloadImage(horizontalGradient)
    UnloadImage(radialGradient)
    UnloadImage(checked)
    UnloadImage(whiteNoise)
    UnloadImage(perlinNoise)
    UnloadImage(cellular)

    currentTexture = 1   // 0

    SetTargetFPS(10)
	 
 
    //---------------------------------------------------------------------------------------

    // Main game loop
    while ( !WindowShouldClose() )
    
        // Update
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_RIGHT))
        {
            currentTexture = (currentTexture + 1) % NUM_TEXTURES    //--- Cycle between the textures
        
		      if currentTexture = 0
					currentTexture++     //===<<< 1 for RING
				ok
				
		  }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing()

            ClearBackground(RAYWHITE)

            DrawTexture(textures[currentTexture], 0, 0, WHITE)

            DrawRectangle(30, 400, 325, 30, Fade(SKYBLUE, 0.5))
            DrawRectangleLines(30, 400, 325, 30, Fade(WHITE, 0.5))
            DrawText("MOUSE LEFT BUTTON to CYCLE PROCEDURAL TEXTURES", 40, 410, 10, WHITE);

//See nl+"currentTextures: "+ currentTexture +nl


            switch(currentTexture)
            
                case 1  DrawText("VERTICAL GRADIENT", 560, 10, 20, RAYWHITE)  
                case 2  DrawText("HORIZONTAL GRADIENT", 540, 10, 20, RAYWHITE)
                case 3  DrawText("RADIAL GRADIENT", 580, 10, 20, LIGHTGRAY)   
                case 4  DrawText("CHECKED", 680, 10, 20, RAYWHITE)            
                case 5  DrawText("WHITE NOISE", 640, 10, 20, RED)             
                case 6  DrawText("PERLIN NOISE", 630, 10, 20, RAYWHITE)       
                case 7  DrawText("CELLULAR", 670, 10, 20, RAYWHITE)           
             
				 off  // off or end
            

        EndDrawing()
        //----------------------------------------------------------------------------------
    end

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // Unload textures data (GPU VRAM)
	 See nl+"Num_Tuextures: "+ NUM_TEXTURES +nl
    for i = 1 to  NUM_TEXTURES
		UnloadTexture( textures[2] )
	 next 

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
