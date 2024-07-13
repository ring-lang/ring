#--------------------------------------------------------------
#	Sample  : jump_player_3D
#	Author	: Azzeddine Remmal 
# 	Email	: lemsantah.2013@gmail.com
#				02-03-2021
#	Updated by : Ilir Liburn
#--------------------------------------------------------------

load "raylib5.ring"

func main
    
	screenWidth	= 800
	screenHeight	= 500
	PLAYER_HOR_SPD	= 5
	PLAYER_JUMP_SPD	= 0.1
	LO		= 15
	MAX_ITEM	= 5

	InitWindow(screenWidth, screenHeight, "raylib jump_player_3D.")

	myplayer =new player
	myground =new ground
	    
		
	checked = GenImageChecked(2, 2, 1, 1, green, GRAY)
	itemz = GenImageChecked(2, 2, 1, 1, green, RED)
	texture = LoadTextureFromImage(checked)
	texturez = LoadTextureFromImage(itemz) 
	UnloadImage(checked)

	myground.size = Vector3(20.0,0.2,20.0)    
	myground.position = Vector3(0,-0.5,0.0)    
	myground.model = LoadModelFromMesh(GenMeshCube_2(myground.size.x, myground.size.y, myground.size.z))
	SetModelMaterialTexture(myground.model,0,MAP_DIFFUSE,texture)

	myplayer.size = Vector3(1.0,1.0,1.0)
	myplayer.model = LoadModelFromMesh(GenMeshCube_2(myplayer.size.x, myplayer.size.y, myplayer.size.z))
	SetModelMaterialTexture(myplayer.model,0,MAP_DIFFUSE,texture)

	grounditems = list(MAX_ITEM)
	srandom(19)
	/* INITIALIZE ITEMS */
	for item in grounditems
		item = new ground
		item.size = Vector3(1.0,1.0,1.0)
		item.position.x = random()%19 - 9
		item.position.z = random()%19 - 9
		item.model = LoadModelFromMesh(GenMeshCube_2(item.size.x, item.size.y, item.size.z))
		SetModelMaterialTexture(item.model,0,MAP_DIFFUSE,texturez)
	next
	
	lengrounditems = len(grounditems )

	myplayer.position = Vector3(0,0,0)
	myplayer.speed = 0
	    
	hitObstacle = false
	jump = false                

	camera = Camera3D(0.0, 10.0, 15.0,
						0.0, 0.0, 0.0,
						0.0, 1.0, 0.0, 
				        50.0, 0)  
	
	SetTargetFPS(60)  
	SetMousePosition(0,0)

	while !WindowShouldClose()  

		UpdateCamera(camera,CAMERA_THIRD_PERSON)    
		dT = GetFrameTime()
		pos = myplayer.position

		if IsKeyDown(KEY_DOWN)
			myplayer.position.z += PLAYER_HOR_SPD*dT
		elseif IsKeyDown(KEY_UP)
			myplayer.position.z -= PLAYER_HOR_SPD*dT
		elseif IsKeyDown(KEY_RIGHT)
			myplayer.position.x += PLAYER_HOR_SPD *dT
		elseif IsKeyDown(KEY_LEFT)
			myplayer.position.x -= PLAYER_HOR_SPD *dT	
		ok

		if IsKeyDown(KEY_SPACE)
			/* CANJUMP REWORK  */
			jump = true
		ok

	
	# Detect Collision 

		hitObstacle = false

		/* MOVE PLAYER POSITION OUT OF THE LOOP */
			pp = myplayer.position
			rec1 = Rectangle(myplayer.position.x,myplayer.position.z,myplayer.size.x,myplayer.size.z)

		/* USE REFERENCE TO GROUND ITEM */
			for GI in grounditems      
				rec2 = Rectangle(GI.position.x,GI.position.z,GI.size.x,GI.size.z)
				hit = CheckCollisionRecs(rec1,rec2)
				grounded = myplayer.position.y <= GI.size.y
				if hit and grounded
					hitObstacle = true
					exit
				ok
			next

		if myplayer.canjump = false
			if myplayer.position.y > PLAYER_JUMP_SPD
				if not hit
					myplayer.position.y -= PLAYER_JUMP_SPD
				ok
			else
				myplayer.canjump = true
			ok
		else
			if hitObstacle
				myplayer.position = pos
			ok
			if jump
				if grounded
					myplayer.position.y += PLAYER_JUMP_SPD
				else
					myplayer.canjump = false
					jump = false
				ok
			ok
		ok
		
		BeginDrawing()

			ClearBackground(RAYWHITE)

			BeginMode3D(camera)

			/* USE LOOP TO DRAW GROUNDITEMS, NOT GROUND */
				for i = 1 to lengrounditems 
					DrawModel(grounditems[i].model, grounditems[i].position, 1, WHITE)	
				next
	    
			DrawModel(myground.model, myground.position, 1, WHITE)	
			DrawModel(myplayer.model, myplayer.position, 1.0, RED)
			EndMode3D()
			DrawText("Press space to Jump.",200,20,40,BLUE)
			DrawFPS(10,10)

		EndDrawing()       
	end

    	# De-Initialization
 		CloseWindow()     
    		UnloadModel(myplayer.model)


class player

     position	=	Vector3(0.0,0.0,0.0)
     size	=	Vector3(0.0,0.0,0.0) 
     jumpforce	=	0.0
     canjump	=	false
     model
     speed


class ground
	model
	position	=  Vector3(0.0,0.0,0.0)
	size		=  Vector3(0.0,0.0,0.0) 
	blocking	=  false
