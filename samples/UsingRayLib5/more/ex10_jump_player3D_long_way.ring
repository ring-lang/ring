#--------------------------------------------------------------
#	jump_player_3D
#	Author : Azzeddine Remmal 
# 	Email  : lemsantah.2013@gmail.com
#			 02-03-2021
#	Updated by Ilir Liburn
#--------------------------------------------------------------

load "raylib5.ring"
Load "stdlib.ring"

SCREENWIDTH = 800
SCREENHEIGHT = 500
PLAYER_HOR_SPD  = 10
PLAYER_JUMP_SPD  = 10
LO = 12
MAX_ITEM =10

func main
    
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib jump_player_3D.")

	myplayer =new player
	myground =new ground
	
	checked = GenImageChecked(2, 2, 1, 1, green, GRAY)
	itemz = GenImageChecked(2, 2, 1, 1, green, RED)
	texture = LoadTextureFromImage(checked)
	texturez = LoadTextureFromImage(itemz)
	UnloadImage(checked)
	
	myground.size = Vector3(20.0,0.5,20.0)    
	myground.model = LoadModelFromMesh(GenMeshCube_2(myground.size.x, myground.size.y, myground.size.z))
	SetModelMaterialTexture(myground.model,0,MAP_DIFFUSE,texture)

	myplayer.size = Vector3(1.0,1.0,1.0)
	myplayer.model = LoadModelFromMesh(GenMeshCube_2(myplayer.size.x, myplayer.size.y, myplayer.size.z))
	SetModelMaterialTexture(myplayer.model,0,MAP_DIFFUSE,texture)

	grounditems = list(MAX_ITEM)
	  
	for item in grounditems 	
		item =  new ground 
		item.size = Vector3(20.0,0.3,20.0) 	
		item.position.x = 1
		item.model = LoadModelFromMesh(GenMeshCube_2(item.size.x, item.size.y, item.size.z))
	        SetModelMaterialTexture(item.model,0,MAP_DIFFUSE,texturez)
	next
       
	lengrounditems = len(grounditems )
	for i=1 to lengrounditems 
		grounditems[1].position.z =1
		grounditems[2].position.z =grounditems[1].position.z+30
		grounditems[3].position.z =grounditems[2].position.z+30
		grounditems[4].position.z =grounditems[3].position.z+30
		grounditems[5].position.z =grounditems[4].position.z+30
		grounditems[6].position.z =grounditems[5].position.z+30
		grounditems[7].position.z =grounditems[6].position.z+30
		grounditems[8].position.z =grounditems[7].position.z+30  
		grounditems[9].position.z =grounditems[8].position.z+30
		grounditems[10].position.z =grounditems[9].position.z+30	
	next
	
	myplayer.position = Vector3(0,1,0)
	myplayer.canjump = true
	myplayer.speed = 0
	Win = false
	GameOver = false
	hitObstacle = false
                
	camera = Camera3D(0.0, 5.0, 20.0,
		          20.0, 9.0, 0.0,
		          0.0, 1.0, 0.0, 
		          50.0, 0)  

	SetTargetFPS(60)              
  
	while !WindowShouldClose()  
        
	# Update
       
                UpdateCamera(camera,CAMERA_THIRD_PERSON)    

     		DT = GetFrameTime()
		camera.target = Vector3( myplayer.Position.x, myplayer.Position.y+2,myplayer.Position.z-5)
		camera.Position = Vector3( myplayer.Position.x, myplayer.Position.y+3,myplayer.Position.z-10)

		myplayer.UpdatePlayer(myplayer, grounditems, DT)

		if myplayer.position.z > grounditems[10].position.z  Win = true    ok
		if IsKeyPressed(KEY_R) myplayer.position = Vector3(0,0,0) ok
        	if myplayer.position.y < myground.position.y - 15 GameOver = true    ok
        	if myplayer.position.y < myground.position.y - 45 CloseWindow()    ok
       
        # Draw
       
		BeginDrawing()

		ClearBackground(RAYWHITE)

		BeginMode3D(camera)

		for i = 1 to len(grounditems ) 
		  
			grounditems[i].position.z -= 0.04
		
			DrawModel(grounditems[i].model, grounditems[i].position, 1, WHITE)
		     
		next

		DrawModel(myplayer.model, myplayer.position, 1.0, RED)
		EndMode3D()

		if GameOver DrawText("GAME OVER",200,200,40,RED) ok
		if Win DrawText("YOU NEVER WIN",200,200,40,BLACK) ok
		DrawFPS(10,10)
		
		EndDrawing()
       
	end

	# De-Initialization
 
		CloseWindow()
     
		UnloadModel(myground.model)
		UnloadModel(myplayer.model)

class player

     position	=  Vector3(0.0,0.0,0.0)
     size	= Vector3(0.0,0.0,0.0) 
     jumpforce	=   0.0
     canjump	=   false
     model
     speed



func UpdatePlayer myplayer, grounditems, DT
    
	myPlayerLastPositionZ = myplayer.position.z

        if IsKeyDown(KEY_DOWN)
		myplayer.position.z -= PLAYER_HOR_SPD*DT ok
	if IsKeyDown(KEY_UP) 
		myplayer.position.z += PLAYER_HOR_SPD*DT ok
	if IsKeyDown(KEY_RIGHT)
		myplayer.position.x -= PLAYER_HOR_SPD *DT ok
	if IsKeyDown(KEY_LEFT) 
		myplayer.position.x += PLAYER_HOR_SPD *DT ok

	if IsKeyDown(KEY_SPACE) and myplayer.canjump
		myplayer.speed = - PLAYER_JUMP_SPD
	        myplayer.canjump = false
	ok 

	ps = myplayer.size
	pp = myplayer.position
	rec1 = Rectangle(pp.x,pp.z,ps.x,ps.z)

	hitObstacle = false
	# Detect Collision 
	it = 0
        for GI in grounditems   
		rec2 = Rectangle(GI.position.x - 9,GI.position.z-10,GI.size.x,GI.size.z)
		hit = CheckCollisionRecs(rec1,rec2)          	       
		if hit and myplayer.position.y >= GI.position.y and
			GI.position.y + GI.size.y*3 > myplayer.position.y - myplayer.speed*dT
				hitObstacle = true
				myplayer.speed =0
				myplayer.position.y  = GI.position.y + GI.size.y*3
			exit
	        ok
		it++
	next

	if !hitObstacle
		myplayer.position.y -= myplayer.speed*dT
		myplayer.speed += LO*dT
		myplayer.canjump = false
	else
		if it != 0 
			itemslen = len(grounditems)
			if myplayer.position.z < myPlayerLastPositionZ
				if grounditems[it].position.z > GI.position.z
					grounditems[it].position.z -= 300
				ok
			else
				if grounditems[it].position.z < GI.position.z
					grounditems[it].position.z += 300
				ok
			ok
		ok
		myplayer.canjump = true   
         ok

class ground
	model
	position	=  Vector3(0.0,0.0,0.0)
	size		=  Vector3(0.0,0.0,0.0) 
