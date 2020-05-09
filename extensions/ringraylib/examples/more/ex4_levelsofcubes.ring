#1 Sample : Top-Down View - Many Levels of Cubes
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>
# 2020, port to RayLib, Ilir Liburn <iliribur@gmail.com>  


# Load Libraries
load "raylib.ring"		# RingRayLib  Library


TITLE = "Sample : Top-Down View - Many Levels of Cubes"

screenWidth = 1280
screenHeight = 720

#SetConfigFlags(FLAG_FULLSCREEN_MODE) // | FLAG_VSYNC_HINT)
InitWindow(screenWidth, screenHeight, TITLE)

font = LoadFont("resources/pirulen.ttf")
texture = LoadTexture("resources/n1.jpg")
background = LoadTexture("resources/back.jpg")

// angle of rotation for the camera direction
angle=0.0

// XZ position of the camera
cx=0.0
cz=5.0

fraction = 0.09

textPosition = Vector2(400, 400)
cubePosition = new Vector3(0, 0, 0)

mesh = GenMeshCube(1, 1, 1)
cube = LoadModelFromMesh(mesh)
setModelmaterialtexture(cube, 0, 0, texture)

camera = Camera3D(
	cx, 10-cz, cz+2,
	cx, 0.7, cz-1,
	0, 1, 0,
	90, CAMERA_PERSPECTIVE)

SetCameraMode(camera, CAMERA_CUSTOM) 

SetTargetFPS(60)

while !WindowShouldClose()

 	if IsKeyDown(KEY_LEFT)
		angle -= 0.1 
		camera.target.x = sin(angle)
	but IsKeyDown(KEY_RIGHT)
		angle += 0.1
		camera.target.x = sin(angle)
	ok

	if IsKeyDown(KEY_UP)
                cz -= 1
		camera.position.y -= fraction / 4
		camera.position.z = cz + 2
		camera.target.y -= fraction * 2
		camera.target.z = cz - 1
	but IsKeyDown(KEY_DOWN)
                cz += 1
		camera.position.y += fraction / 4
		camera.position.z = cz + 2
		camera.target.y += fraction * 2
		camera.target.z = cz - 1
	ok

	UpdateCamera(camera)

	BeginDrawing()

		DrawTexture(background, 0, 0, WHITE)
		ClearBackground(BLANK)

		BeginMode3D(camera)

		for k = 0 to 40 step 10	
			for  j = 1 to -3 step -1
				cubePosition.z = j - k
				for i = -10 to 10 step 1
					cubePosition.x = i
					DrawModel(cube, cubePosition, 1, WHITE)
				next
			next
		next

		EndMode3D()
 
		DrawTextEx(font, "Ring is fun!", textPosition, 48, 1, GREEN)
		DrawFPS(10, 10);

	EndDrawing()

end

UnloadTexture(texture)
UnloadFont(font)

CloseWindow()
