#===================================================================#
# Based on Original Sample from RayLib (https://www.raylib.com/)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing")

InitAudioDevice()       

fxWav = LoadSound("sound.wav")         
fxOgg = LoadSound("tanatana.ogg")  


SetTargetFPS(60) 

while !WindowShouldClose()

	if IsKeyPressed(KEY_SPACE) PlaySound(fxWav)  ok  
	if IsKeyPressed(KEY_ENTER) PlaySound(fxOgg)  ok  

	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY)
		DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY)

	EndDrawing()
	
end

UnloadSound(fxWav)
UnloadSound(fxOgg)

CloseAudioDevice() 

CloseWindow()
