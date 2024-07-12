#===================================================================#
# Copyright (c) 2015 Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#===================================================================#

load "raylib5.ring"

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [audio] example - music playing (streaming)")

InitAudioDevice()               

music = LoadMusicStream("guitar_noodling.ogg")

PlayMusicStream(music)

timePlayed = 0.0
pause = false

SetTargetFPS(60)


while !WindowShouldClose()

	UpdateMusicStream(music)  

	if IsKeyPressed(KEY_SPACE)   
		StopMusicStream(music)
		PlayMusicStream(music)
	ok

	if IsKeyPressed(KEY_P)
		pause = !pause

		if pause 
			PauseMusicStream(music)
		else 
			ResumeMusicStream(music)
		ok
	ok

	timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music) *400

	if timePlayed > 400 
		StopMusicStream(music)
	ok

	BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawText("MUSIC SHOULD BE PLAYING!", 255, 150, 20, LIGHTGRAY)

			 DrawRectangle(200, 200, 400, 12, LIGHTGRAY)
			 DrawRectangle(200, 200, timePlayed, 12, MAROON)
		DrawRectangleLines(200, 200, 400, 12, GRAY)

		DrawText("PRESS SPACE  TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY)
		DrawText("PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY)

	EndDrawing()

end 

UnloadMusicStream(music)

CloseAudioDevice()

CloseWindow()
