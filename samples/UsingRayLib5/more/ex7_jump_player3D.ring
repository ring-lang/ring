#--------------------------------------------------------------
#       jump_player_3D
#	Author : Azzeddine Remmal 
# 	Email : lemsantah.2013@gmail.com
#             02-03-2021
#--------------------------------------------------------------
load "raylib5.ring"

func main
    
         screenWidth = 800
         screenHeight = 500
	

    InitWindow(screenWidth, screenHeight, "raylib jump_player_3D.")

	     myplayer =new player
	   
	     checked = GenImageChecked(2, 2, 1, 1, green, GRAY)
	     texture = LoadTextureFromImage(checked)
	    UnloadImage(checked)
		    
	    model = LoadModelFromMesh(GenMeshCube_2(20.0, 0.2, 20.0))
	    SetModelMaterialTexture(model,0,MAP_DIFFUSE,texture)
	    myplayer.model = LoadModelFromMesh(GenMeshCube_2(1.0, 1.0, 1.0))
	    SetModelMaterialTexture(myplayer.model,0,MAP_DIFFUSE,texture)
	
	     myplayer.position = Vector3(5.0,1,5.0)
       	     myplayer.canjump = true
 	     myplayer.size = Vector3(1.0,1.0,1.0)
	     myplayer.jumpforce = 0.0
	     position= Vector3(1.0,0.0,1.0)
	     ground = Vector3( 0,0.6,0)

	
	    camera = Camera3D(0.0, 5.0, 30.0,
				          20.0, 6.0, 0.0,
				          0.0, 1.0, 0.0, 
				          50.0, CAMERA_PERSPECTIVE )  
	
    SetTargetFPS(30)              
  
    while !WindowShouldClose()  
        
        # Update
       
                UpdateCamera(camera,CAMERA_THIRD_PERSON)    

     
        if IsKeyDown(KEY_SPACE) and  myplayer.canjump

            myplayer.canjump = false 
            myplayer.jumpforce  = 2
        ok
        
        if myplayer.canjump = false
           	
	        myplayer.position.y += myplayer.jumpforce
	       
                if myplayer.position.y < ground.y
	                    myplayer.position.y = ground.y
	                    myplayer.canjump = true
                ok                
                myplayer.jumpforce  -= 0.2          
         ok

		speed = 0.5 

	 if IsKeyDown(KEY_DOWN)
			 myplayer.position.z += speed 
	elseif IsKeyDown(KEY_UP) 
			myplayer.position.z -= speed
	elseif IsKeyDown(KEY_RIGHT)
 			myplayer.position.x += speed
	elseif IsKeyDown(KEY_LEFT) 
			myplayer.position.x -= speed
	
	ok

	 
       
        # Draw
       
        BeginDrawing()

            ClearBackground(RAYWHITE)

             BeginMode3D(camera)
		    DrawModel(model, position, 1.0, WHITE)	
	            DrawModel(myplayer.model, myplayer.position, 1.0, RED)
            EndMode3D()

            DrawText("Press space to Jump.",200,20,40,BLUE)
           
		 DrawFPS(10,10)

        EndDrawing()
       
    end

    # De-Initialization
 
    CloseWindow()
     
   
    UnloadModel(model)
    UnloadModel(myplayer.model)


    # our player struct
class player

     position    =Vector3(0.0,0.0,0.0)
     size          =Vector3(0.0,0.0,0.0) 
     jumpforce = 0.0
     canjump   = false
     model
     

