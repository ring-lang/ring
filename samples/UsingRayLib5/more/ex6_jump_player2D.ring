#--------------------------------------------------------------
#       jump_player_2D
#	Author : Azzeddine Remmal 
# 	Email : lemsantah.2013@gmail.com
#             02-03-2021
#--------------------------------------------------------------
load "raylib5.ring"

func main
    #---------------------------------------------------------------------------------
    # Initialization
    #---------------------------------------------------------------------------------
     screenWidth = 800
     screenHeight = 450

    InitWindow(screenWidth, screenHeight, "raylib jump_player_2D.")

	    ground = 200.0
	 
	     myplayer =new player
	    myplayer.position = Vector2(400,200)
	    myplayer.canjump = true
	    myplayer.width = 30
	    myplayer.height = 60
	    myplayer.jumpforce = 0.0
	 
    SetTargetFPS(60)             
  
    while !WindowShouldClose()   
    
        # Update
       
       
        if IsKeyDown(KEY_SPACE) and myplayer.canjump
            myplayer.canjump = false 
            myplayer.jumpforce = -5.0 
        ok
       
        if myplayer.canjump=false
      
	            for i=1 to fabs(myplayer.jumpforce)
	              
		                if myplayer.canjump = false 
					myplayer.position.y += myplayer.jumpforce 
				ok		             
		                if myplayer.position.y>ground
			                    myplayer.position.y = ground
			                    myplayer.canjump = true
			                    exit
		                ok                
	            next
            
            myplayer.jumpforce += 0.2           
        ok
        #----------------------------------------------------------------------------------
        # Draw
        #----------------------------------------------------------------------------------
        BeginDrawing()

            ClearBackground(RAYWHITE)
            
            DrawText("Press space to Jump.",200,240,40,DARKGRAY)
            # Draw our player.
            DrawRectangle(myplayer.position.x,myplayer.position.y,myplayer.width,myplayer.height,BLACK)   
            DrawCircle(myplayer.position.x+4,myplayer.position.y+6,4,WHITE)    
            DrawCircle(myplayer.position.x+myplayer.width-4,myplayer.position.y+6,4,WHITE)    

          EndDrawing()
        
    end
  
    CloseWindow()        # Close window and OpenGL context
   
class player
     position=Vector2(0,0)
     width=0
     height=0
     jumpforce=0
     canjump=false

