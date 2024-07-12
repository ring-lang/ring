#===================================================================#
# Copyright (c) 2016 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth  = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - image drawing")

cat = LoadImage("cat.png")                              

ImageCrop( cat,  Rectangle( 100, 10, 280, 380 ))        
ImageFlipHorizontal( cat)                               
ImageResize( cat, 150, 200)                             

parrots = LoadImage("parrots.png")                      

ImageDraw( parrots, cat, Rectangle( 0, 0, cat.width, cat.height ), Rectangle( 30, 40, cat.width*1.5, cat.height*1.5 ))
ImageCrop( parrots, Rectangle( 0, 50, parrots.width, parrots.height - 100 )) 

UnloadImage(cat)       

font = LoadFont("custom_jupiter_crash.png")

ImageDrawTextEx(parrots, Vector2( 300, 230 ), font, "PARROTS & CAT", font.baseSize, -2, WHITE)
UnloadFont(font);                              

texture = LoadTextureFromImage(parrots)        

UnloadImage(parrots)                           

SetTargetFPS(60)

while !WindowShouldClose()
	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, WHITE)
		DrawRectangleLines(screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, texture.width, texture.height, DARKGRAY)

		DrawText("We are drawing only one texture from various images composed!", 240, 350, 10, DARKGRAY)
		DrawText("Source images have been cropped, scaled, flipped and copied one over the other.", 190, 370, 10, DARKGRAY)

	EndDrawing()
end

UnloadTexture(texture)       

CloseWindow()                


