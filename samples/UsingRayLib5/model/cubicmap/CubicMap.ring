#===================================================================#
# Copyright (c) 2015 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth  = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [models] example - cubesmap loading and drawing")

camera = Camera3D( 16.0, 14.0, 16.0,
				 0.0, 0.0, 0.0,
				 0.0, 1.0, 0.0, 
				 45.0, CAMERA_PERSPECTIVE )

image    = LoadImage("cubicmap.png")        
cubicmap = LoadTextureFromImage(image)      

mesh     = GenMeshCubicmap(image, Vector3( 1.0, 1.0, 1.0 ))
model    = LoadModelFromMesh(mesh)

texture  = LoadTexture("cubicmap_atlas.png") 

setmodelmaterialtexture(model,0,MAP_DIFFUSE,texture)

mapPosition = Vector3( -16.0, 0.0, -8.0 )   

UnloadImage(image)                     
SetTargetFPS(60)                       

while !WindowShouldClose()

	UpdateCamera(camera,CAMERA_ORBITAL)
	
	BeginDrawing()

		ClearBackground(RAYWHITE)
		BeginMode3D(camera)
			DrawModel(model, mapPosition, 1.0, WHITE)
		EndMode3D()

		DrawTextureEx(cubicmap, Vector2( screenWidth - cubicmap.width*4 - 20, 20 ),
						0.0, 4.0, WHITE)
		DrawRectangleLines(screenWidth - cubicmap.width*4 - 20, 20, cubicmap.width*4,
						cubicmap.height*4, GREEN)

		DrawText("cubicmap image used to", 658,  90, 10, GRAY)
		DrawText("generate map 3d model",  658, 104, 10, GRAY)
		DrawFPS(10, 10)

	EndDrawing()
	
end

UnloadTexture(cubicmap) 
UnloadTexture(texture)  
UnloadModel(model)      

CloseWindow()
