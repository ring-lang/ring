#=====================================================#
# Copyright (c) 2020  Ramon Santamaria (@raysan5)
# Ported to RingRayLib by (Azzeddine Remmal) 
#=====================================================#

load "raylib5.ring"

screenWidth = 640
screenHeight = 360

// can't query this so track it.
fullScreen = false

path = [Vector3(-20,2,20),Vector3(20,12,15),Vector3(20,2,-15),Vector3(-20,8,-14) ]
start = Vector3(0.0,0.0,0.0)
ond = Vector3(0.0,0.0,0.0)
velocity = 0

// given a start and end point calculate frame increment
// to move between the points at the given velocity
// i.e. create a velocity vector
Func calcInc  start,ond,velocity
	v = Vector3Subtract(ond, start)
	v = Vector3Normalize(v)
	v = Vector3Scale(v, velocity)
	return v


Func main

	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "raylib - Aiming at 3d moving targets")

	// Define the camera to look into our 3d world
	camera = Camera3D(0.0, 20.0, -40.0,
			  0.0, 0.0, 0.0,
			  0.0, 1.0, 0.0, 
			  45.0, CAMERA_PERSPECTIVE )  

	frame = 0 // frame counter
	ang = 0 // camera rotation
    
	targetSpeed = 0.2
	shotSpeed = 0.6
    
	// could build these vectors into a struct...
	targetPos = path[1]
	targetDest = path[2]
	targetInc = calcInc(targetPos, targetDest, targetSpeed)
	lastTarget = Vector3(0.0,0.0,0.0) // so velocity vector can be calculated
	targetPathPos = 1
    
	shootWait = 10
	shotActive = false
	shotStart= Vector3(0.0,0.0,0.0)
	shotPos= Vector3(0.0,0.0,0.0)
	shotDest= Vector3(0.0,0.0,0.0)
	shotInc= Vector3(0.0,0.0,0.0)

	SetTargetFPS(60)               // Set  to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while !WindowShouldClose()   // Detect window close button or ESC key
    
        // Update
        //----------------------------------------------------------------------------------

		frame ++
		ang += 0.0025

		camera.position.x = cos(ang) * 50.0
		camera.position.z = sin(ang) * 50.0

		UpdateCamera(camera,CAMERA_FIRST_PERSON)
        
               if IsKeyPressed(KEY_F)
			ToggleFullscreen()
			fullScreen = !fullScreen
			if fullScreen
				screenWidth = 1920
				screenHeight = 1080
				SetWindowSize(screenWidth, screenHeight)
			else 
				screenWidth = 1920/3
				screenHeight = 1080/3
				SetWindowSize(screenWidth, screenHeight)
			ok
		ok
		
		// update target position
		lastTarget = targetPos
		targetPos = Vector3Add(targetPos, targetInc)
		
		// get new path destination
		if Vector3Distance(targetPos, targetDest) < targetSpeed
			targetPathPos++
			if targetPathPos = 4  targetPathPos = 1 ok
			targetPos = targetDest
			targetDest = path[targetPathPos]
			targetInc = calcInc(targetPos, targetDest, targetSpeed)			
		ok
		
		// update shot
		
		if shotActive
			// if the shot has reached its destination
			// deactivate it and wait for a random interval
			// before shooting again
			if Vector3Distance(shotPos,shotDest) < shotSpeed
				shotActive = false
				shootWait = GetRandomValue(30,120)
			ok

			// update shot position
			shotPos = Vector3Add(shotPos, shotInc)
		ok
		
		if !shotActive
			if shootWait>0
				shootWait--
			else
				shotActive = true
				// random start point
				shotStart = Vector3( GetRandomValue(-40,40)/10.0, 0 , GetRandomValue(-40,40)/10.0 )
				shotPos = shotStart
				
				// vector to target and targets velocity vector
				totarget =  Vector3Subtract( targetPos, shotPos )
				targVel = Vector3Subtract( targetPos, lastTarget)

				// quadratic terms
				a = Vector3DotProduct(targVel, targVel) - (shotSpeed * shotSpeed)
				b = 2.0 * Vector3DotProduct(targVel, totarget)
				c = Vector3DotProduct(totarget, totarget)

				// quadratic formula simplified down to this...
				p = -b / (2.0 * a)
				q = sqrt((b * b) - 4.0 * a * c) / (2.0 * a)				
				
				t = p - q
				
				// target velocity  t + target pos = aim point (t = time or steps till hit)
				targVel = Vector3Scale(targVel, t)
				shotDest = Vector3Add(targetPos, targVel)
				
				shotInc = calcInc(shotPos, shotDest, shotSpeed)
			ok
		ok

        // Draw
      
        	BeginDrawing()

			ClearBackground(BLACK)

			BeginMode3D(camera)

			DrawGrid(10, 10.0f)        // Draw a grid
                
			DrawLine3D(path[1], path[2], RED)
                	DrawLine3D(path[2], path[3], RED)
                	DrawLine3D(path[3], path[4], RED)
                	DrawLine3D(path[4], path[1], RED)
                
                	DrawSphere(targetPos, 0.8, WHITE)
                	if shotActive
				DrawSphere(shotPos, 0.6, RED)
				DrawSphere(shotDest, 0.6, GREEN)
				DrawLine3D(shotStart, shotDest, BLUE)
			ok

			EndMode3D()

			DrawFPS(10, 10)

			DrawText("Frame %i"+ frame, 8, screenHeight-24, 20, WHITE)
			DrawText("Press f to toggle fullscreen", 200, screenHeight-24, 20, WHITE)

        	EndDrawing()
      
	end

	// De-Initialization

	CloseWindow()        // Close window and OpenGL context
  
