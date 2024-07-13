#===================================================================#
# Based on Original Sample from RayLib (https://www.raylib.com/)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

// Initialization
//--------------------------------------------------------------------------------------
screenWidth  = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [models] example - plane rotations (yaw, pitch, roll)")

texAngleGauge = LoadTexture("angle_gauge.png")
texBackground = LoadTexture("background.png")
texPitch      = LoadTexture("pitch.png")
texPlane      = LoadTexture("plane.png")
framebuffer   = LoadRenderTexture(192, 192)

// Model loading

model = LoadModel("plane.obj")     // Load OBJ model

texture   = LoadTexture("plane_diffuse.png")                         // Set map diffuse texture
resultMT  = SetModelMaterialTexture(model,0,MAP_DIFFUSE,texture)     
GenTextureMipmaps(texture) 

// Define the camera to look into our 3d world
camera = Camera3D(	0, 60, -120,
			0, 12,    0,
			0,  1,    0, 
			30,  CAMERA_PERSPECTIVE )

pitch = 0.0
roll  = 0.0
yaw   = 0.0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second


//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key

	// Update
	//----------------------------------------------------------------------------------

	// Plane roll (x-axis) controls

	if (IsKeyDown(KEY_LEFT)) 
		roll += 1.0
	else 
		if (IsKeyDown(KEY_RIGHT)) 
			roll -= 1.0
		else
		
			if (roll  > 0.0) 
				roll -= 0.5
			else 
				if (roll  < 0.0) 
					roll += 0.5
				ok
			ok
		ok
	ok



	// Plane yaw (y-axis) controls
	
	if (IsKeyDown(KEY_S)) 
		yaw += 1.0
	else 
		if (IsKeyDown(KEY_A)) 
			yaw -= 1.0
		else
			if (yaw  > 0.0) 
				yaw -= 0.5
			else 
				if (yaw  < 0.0) 
					yaw += 0.5
				ok
			ok
		ok
	ok
	
	// Plane pitch (z-axis) controls
	
	if (IsKeyDown(KEY_DOWN)) 
		pitch += 0.6
	else 
		if (IsKeyDown(KEY_UP)) 
			pitch -= 0.6
		else
			if (pitch  > 0.3) 
				pitch -= 0.3
			else 
				if (pitch < -0.3) 
					pitch += 0.3
				ok
			ok
		ok
	ok
	
	// Wraps the phase of an angle to fit between -180 and +180 degrees

	pitchOffset = pitch

	while (pitchOffset > 180)  pitchOffset -= 360  end
	while (pitchOffset < -180) pitchOffset += 360  end
	pitchOffset *= 10

	// matrix created from multiple axes at once
	DEG2RAD = 3.14 / 180
	model.transform = MatrixRotateXYZ(Vector3( DEG2RAD*pitch,DEG2RAD*yaw,DEG2RAD*roll) ) 

	//----------------------------------------------------------------------------------
	// Draw
	//----------------------------------------------------------------------------------

	BeginDrawing()

	ClearBackground(RAYWHITE)

	// Draw framebuffer texture (AHRS Display)

	centerX = framebuffer.texture.width  /2
	centerY = framebuffer.texture.height /2

	scaleFactor = 0.5

	BeginTextureMode(framebuffer)

	BeginBlendMode(BLEND_ALPHA)

	DrawTexturePro(texBackground, Rectangle( 0, 0, texBackground.width, texBackground.height ),
	   Rectangle( centerX, centerY, texBackground.width*scaleFactor, texBackground.height*scaleFactor),
	 Vector2( texBackground.width/2*scaleFactor, texBackground.height/2*scaleFactor + pitchOffset*scaleFactor ), roll, WHITE)

	DrawTexturePro(texPitch, Rectangle( 0, 0, texPitch.width, texPitch.height ),
	   Rectangle( centerX, centerY, texPitch.width*scaleFactor, texPitch.height*scaleFactor ),
	 Vector2( texPitch.width/2*scaleFactor, texPitch.height/2*scaleFactor + pitchOffset*scaleFactor ), roll, WHITE)

	DrawTexturePro(texPlane, Rectangle( 0, 0, texPlane.width, texPlane.height ),
	   Rectangle( centerX, centerY, texPlane.width*scaleFactor, texPlane.height*scaleFactor ),
	 Vector2( texPlane.width/2*scaleFactor, texPlane.height/2*scaleFactor ), 0, WHITE)

	EndBlendMode()

	EndTextureMode()


	// Draw 3D model (recommended to draw 3D always before 2D)
	BeginMode3D(camera)

	DrawModel(model, Vector3( 0, 6.0, 0 ), 1.0, WHITE)   // Draw 3d model with texture
	DrawGrid(10, 10.0)

	EndMode3D()

	// Draw 2D GUI stuff
	DrawAngleGauge(texAngleGauge,  80, 70, roll,  "roll",  RED)
	DrawAngleGauge(texAngleGauge, 190, 70, pitch, "pitch", GREEN)
	DrawAngleGauge(texAngleGauge, 300, 70, yaw,   "yaw",   SKYBLUE)

	DrawRectangle(30, 360, 260, 70, Fade(SKYBLUE,  0.5))
	DrawRectangleLines(30, 360, 260, 70, Fade(DARKBLUE, 0.5))


	DrawText("Pitch controlled with: KEY_UP   / KEY_DOWN",  40, 370, 10, DARKGRAY)
	DrawText("Roll controlled with:  KEY_LEFT / KEY_RIGHT", 40, 390, 10, DARKGRAY)
	DrawText("Yaw controlled with:   KEY_A    / KEY_S",     40, 410, 10, DARKGRAY)

	// Draw framebuffer texture

	DrawTextureRec(framebuffer.texture, Rectangle( 0, 0, framebuffer.texture.width, -framebuffer.texture.height ),
		   Vector2( screenWidth - framebuffer.texture.width - 20, 20 ), Fade(WHITE, 0.8))

	DrawRectangleLines(screenWidth - framebuffer.texture.width - 20, 20, framebuffer.texture.width, framebuffer.texture.height, DARKGRAY)

	EndDrawing()

end


// Unload all loaded data

UnloadTexture(texture)

UnloadModel(model)

UnloadRenderTexture(framebuffer)

UnloadTexture(texAngleGauge)
UnloadTexture(texBackground)
UnloadTexture(texPitch)
UnloadTexture(texPlane)

CloseWindow()        // Close window and OpenGL context

func DrawAngleGauge(angleGauge, x, y, angle, title, color)

	srcRec = Rectangle( 0, 0, angleGauge.width, angleGauge.height )
	dstRec = Rectangle( x, y, angleGauge.width, angleGauge.height )
	origin = Vector2( angleGauge.width/2, angleGauge.height/2 )
	textSize = 20

	DrawTexturePro(angleGauge, srcRec, dstRec, origin, angle, color)

	DrawText(""+angle, x - MeasureText(""+angle, textSize) / 2, y + 10, textSize, DARKGRAY)
	DrawText(title, x - MeasureText(title, textSize) / 2, y + 60, textSize, DARKGRAY)

