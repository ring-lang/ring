#=============================================================================#
# Copyright (c) 2018 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
# Ported to RingRayLib by Ring Team
#=============================================================================#

load "raylib5.ring"

screenWidth = 800	screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - draw ring")

center = Vector2((GetScreenWidth() - 300)/2, GetScreenHeight()/2 )

innerRadius = 80	outerRadius = 190
startAngle = 0		endAngle = 360		segments = 0
drawRing = true		drawRingLines = false	drawCircleLines = false

SetTargetFPS(60)

while !WindowShouldClose()

        BeginDrawing()

		ClearBackground(RAYWHITE)

		DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6))
		DrawRectangle(500, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3))

		if drawRing DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3)) ok
		if drawRingLines DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4)) ok
		if drawCircleLines DrawCircleSectorLines(center, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4)) ok

		startAngle = GuiSliderBar(Rectangle( 600, 40, 120, 20 ), "StartAngle", startAngle, -450, 450, true)
		endAngle = GuiSliderBar(Rectangle( 600, 70, 120, 20 ), "EndAngle", endAngle, -450, 450, true)

		innerRadius = GuiSliderBar(Rectangle( 600, 140, 120, 20 ), "InnerRadius", innerRadius, 0, 100, true)
		outerRadius = GuiSliderBar(Rectangle( 600, 170, 120, 20 ), "OuterRadius", outerRadius, 0, 200, true)

		segments = GuiSliderBar(Rectangle( 600, 240, 120, 20 ), "Segments", segments, 0, 100, true)

		drawRing = GuiCheckBox(Rectangle( 600, 320, 20, 20 ), "Draw Ring", drawRing)
		drawRingLines = GuiCheckBox(Rectangle( 600, 350, 20, 20 ), "Draw RingLines", drawRingLines)
		drawCircleLines = GuiCheckBox(Rectangle( 600, 380, 20, 20 ), "Draw CircleLines", drawCircleLines)

		if segments >= 4 	DrawText("MODE: MANUAL", 600, 270, 10, MAROON)
		else			DrawText("MODE: AUTO", 600, 270, 10, DARKGRAY)	ok
		
		DrawFPS(10, 10)

        EndDrawing()
end

CloseWindow()
