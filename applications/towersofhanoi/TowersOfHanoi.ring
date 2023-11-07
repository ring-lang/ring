### Towers of Hanoi
### Bert Mariani
### 2020/05/27

### Move Sprites -- 3 Towers 5 Disks
### gGlobals First ... before GameEngine


DropX =   50 
DropY = -100      // Initial Drop Down From Sky to Stock

DiskNbr    = [0,0,0,0,1]     // false, true          Disk  1,2,3,4,5
DiskMove   = [0,0,0,0,1]     // Which is active Disk,  1=active
DiskH      =  45
DiskDir    = [0,0,0,0]       // Up Left Right Down

StickPos   = [50,300,550]    // Stick Horizontal Position  Stick A,B,C
StickBase  =  100            // Where to draw Tower vertical point
StickVert  = [480,480,480]   // Stacked Vertical Height of Disks
HorzLine   =  100            // Travel Horizontal Line L-R

GE_TYPE_1 = 1
GE_TYPE_2 = 1
GE_TYPE_3 = 1
GE_TYPE_4 = 1
GE_TYPE_5 = 1
             
GE_TYPE_A = 1
GE_TYPE_B = 1
GE_TYPE_C = 1

Dir      = 'U'       // Direction U L R D
Src      =  50  
Dest     =  550
StickS   =  1
StickD   =  3

MoveNbr  =   0
MoveDo   =  [0,'S','D']     // Which Disk-1-5 to Move from Stick to Stick

MovePlay = [[1,'A','B'], 
            [2,'A','C'],
            [1,'B','C'],
            [3,'A','B'],
            [1,'C','A'],
            [2,'C','B'],
            [1,'A','B'],
            [4,'A','C'],
            [1,'B','C'],
            [2,'B','A'],
            [1,'C','A'],
            [3,'B','C'],
            [1,'A','B'],
            [2,'A','C'],
            [1,'B','C'],
            [5,'A','B'],
            [1,'C','A'],
            [2,'C','B'],
            [1,'A','B'],
            [3,'C','A'],
            [1,'B','C'],
            [2,'B','A'],
            [1,'C','A'],
            [4,'C','B'],
            [1,'A','B'],
            [2,'A','C'],
            [1,'B','C'],
            [3,'A','B'],
            [1,'C','A'],
            [2,'C','B'],
            [1,'A','B']]


//===========================================================================
// Start the GAME ENGINE

Load "gameengine.ring"                      # Give control to the game engine

Func Main                                   # Called by the Game Engine


     GE_SCREEN_W = 850
     GE_SCREEN_H = 600

     oGame = New Game                       # Create the Game Object
     {
          title    = "Towers of Hanoi"
          FixedFPS = 480                    # Very high speed
	  icon     = "images/TowersOfHanoi.jpg"
          //====================================================== SG SB SY
			 // Background images/D1
			 sprite
			 {
				  type = GE_TYPE_BACKGROUND
				  file = "images/TowersOfHanoi.jpg"
				  x = -100                             // Position   
				  y = -100         
				  Animate = false
			 }
			 
          //====================================================== SG SB SY
          // TOWERS
          
          sprite
          {
                type = GE_TYPE_A                    # Just for our usage
                X = StickPos[1] Y = StickBase       //width=100 height=100              
                file = "images/StickG.png"             
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;               
          }

          sprite
          {
                type = GE_TYPE_B                     # Just for our usage
                X = StickPos[2] Y = StickBase        //width=100 height=100            
                file = "images/StickB.png"                  
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;
          }

          sprite
          {
                type = GE_TYPE_C                     # Just for our usage
                X = StickPos[3] Y = StickBase        //width=100 height=100              
                file = "images/StickY.png"                  
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;
          }   

          //====================================================== D1
          // DISKS

          sprite
          {
                type = GE_TYPE_1                    # Just for our usage
                x = DropX y = DropY                 //width=100 height=100
                file = "images/D1.png"   
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;
      
                state = Func oGame,oSelf {
                        oSelf {                     
                                if DiskMove[1] = true;
                                    y = Setup(1,1,y)
                                ok   

                                if MoveDo[1] = 1         // Move DiskNbr-1 Src Dest 
                                    aHorzVert = MoveDisk(1,x,y)
                                    x = aHorzVert[1]
                                    y = aHorzVert[2]
                                ok                       
                        } 
                            
                }  // state            
          }  // sprite           

            //------------------------------------------------ D2
             
          sprite
          {
                type = GE_TYPE_2                        # Just for our usage
                x = DropX y = DropY                     //width=100 height=100

                file = "images/D2.png"                       
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;         
                    
                state = Func oGame,oSelf {
                        oSelf {                     
                                if DiskMove[2] = true;
                                    y = Setup(2,1,y)
                                ok      

                                if MoveDo[1] = 2         // Move DiskNbr-1 Src Dest 
                                    aHorzVert = MoveDisk(2,x,y)
                                    x = aHorzVert[1]
                                    y = aHorzVert[2]
                                ok

                        
                        } 
                }  // state            
          }  // sprite 

            //------------------------------------------------ D3
             
          sprite
          {
                type = GE_TYPE_3                        # Just for our usage
                x = DropX y = DropY                     //width=100 height=100               
                file = "images/D3.png"                  
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;
          
                state = Func oGame,oSelf {
                        oSelf {                     
                                if DiskMove[3]= true;
                                    y = Setup(3,1,y)
                                ok

                                if MoveDo[1] = 3         // Move DiskNbr-1 Src Dest 
                                    aHorzVert = MoveDisk(3,x,y)
                                    x = aHorzVert[1]
                                    y = aHorzVert[2]
                                ok                       
                        } 
                }  // state            
          }  // sprite 

            //------------------------------------------------ D4
             
          sprite
          {
                type = GE_TYPE_4                # Just for our usage
                x = DropX y = DropY              //width=100 height=100
                file = "images/D4.png"         
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;
          
                state = Func oGame,oSelf {
                        oSelf {                     
                                if DiskMove[4] = true;
                                    y = Setup(4,1,y)
                                ok 
                        
                                if MoveDo[1] = 4         // Move DiskNbr-1 Src Dest 
                                    aHorzVert = MoveDisk(4,x,y)
                                    x = aHorzVert[1]
                                    y = aHorzVert[2]
                                ok
                        
                        } 
                }  // state            
          }  // sprite   

          //------------------------------------------------ D2D5
             
          sprite
          {
                type = GE_TYPE_5                # Just for our usage
                x = DropX y = DropY              //width=100 height=100
                file = "images/D5.png"   
                transparent = true ; Animate = false ; Move = false ; Scaled = false ;
          
                state = Func oGame,oSelf {
                        oSelf {                  
                               if DiskMove[5] = true;  
                                    y = Setup(5,1,y)
                               ok  

                                if MoveDo[1] = 5         // Move DiskNbr-1 Src Dest 
                                    aHorzVert = MoveDisk(5,x,y)
                                    x = aHorzVert[1]
                                    y = aHorzVert[2]
                                ok
                        
                        } 
                }  // state            
          }  // sprite 
             
          //------------------------------------------------
             
     }    // Game   # Start the Events Loop 


return    // MAIN

###----------------------------------------------------
### Initial DropDown Move - Animation
### S = Stick-1-3 and D = Disk 1-5, Y = VertPosition

Func Setup(D,S,y)

   if DiskMove[D] = true
   
        if y < StickVert[S]  
            y++   
            return y            
        else                                
            StickVert[S]  -= DiskH;         // Adjust Stack height on Stick
            DiskMove[D]    = false
         
            if D > 1  
                DiskMove[D -1] = true 
            else        
                MoveNbr = 1
                MoveDo  = MovePlay[1]       // Start the Moves    
            ok
            return y
        ok
    ok   

return

###=========================================
### MoveDisk Up L/R Down  D = Disk-1-5
### MoveDo[1,'A',B']      A,B,C = Stick


Func MoveDisk(D,X,Y)
     
    //-------------------------
    // Move disk to Up
    
   if Dir = 'U'
      if Y > HorzLine
         Y--
         return [X,Y]
      else
         StickS =  dec( MoveDo[2] ) -9     // A to 1, B to 2  C to 3
         Src   =  StickPos[StickS] 
         
         StickD =  dec( MoveDo[3] ) - 9
         Dest  =  StickPos[StickD]    
         
         if Src < Dest  Dir = 'R'   ok     // Decide which direction Left or Right
         if Src > Dest  Dir = 'L'   ok     
         
         StickVert[StickS] += DiskH        // Adjust Stack height on Stick
            
         return [X,Y]   
            
      ok
   ok
    //-------------------------
    // Move disk to Right
   
   if Dir = 'R'
   
      if X < Dest
         X++
         return [X,Y]
      else
            Dir = 'D'      
         return [X,Y]         
      ok
   ok

    //-------------------------
    // Move disk to Left
   
   if Dir = 'L' 
   
      if X > Dest
         X--
         return [X,Y]
      else
            Dir = 'D'      
         return [X,Y]         
      ok
   ok       

    //-------------------------
    // Move disk to Down
    
   if Dir = 'D'
   
      StickD =  dec( MoveDo[3] ) - 9              // A to 1, B to 2  C to 3
      if Y < StickVert[StickD]
         Y++
         return [X,Y]
      else
            Dir = 'U'   
            StickD =  dec( MoveDo[3] ) - 9
            StickVert[StickD] -= DiskH            // Adjust Stack height on Stick
            
            MoveNbr++
            if MoveNbr <= len(MovePlay)
                MoveDo  = MovePlay[Movenbr]       // NextMove  
            else
                MoveDo[1] = 0                     // Finished
            ok
            
            See"NextNbr: "+ MoveNbr +" "+MoveDo[1] +" "+MoveDo[2]  +" "+MoveDo[3] +nl
            return [X,Y]         
      ok
   ok    

return "See oh oh"+nl
                           
###=========================================
###=========================================
###=========================================
/*

Start: ...................... A: 1 2 3 4 5
Move disk: 1  from A  to B    A: 2 3 4 5         B: 1    C: ...
Move disk: 2  from A  to C    A: 3 4 5   B: 1    C: 2
Move disk: 1  from B  to C    A: 3 4 5   B: ...  C: 1 2
Move disk: 3  from A  to B    A: 4 5     B: 3    C: 1 2
Move disk: 1  from C  to A    A: 1 4 5   B: 3    C: 2
Move disk: 2  from C  to B    A: 1 4 5   B: 2 3          C: ...
Move disk: 1  from A  to B    A: 4 5     B: 1 2 3        C: ...
Move disk: 4  from A  to C    A: 5       B: 1 2 3        C: 4
Move disk: 1  from B  to C    A: 5       B: 2 3          C: 1 4
Move disk: 2  from B  to A    A: 2 5     B: 3    C: 1 4
Move disk: 1  from C  to A    A: 1 2 5   B: 3    C: 4
Move disk: 3  from B  to C    A: 1 2 5   B: ...  C: 3 4
Move disk: 1  from A  to B    A: 2 5     B: 1    C: 3 4
Move disk: 2  from A  to C    A: 5       B: 1    C: 2 3 4
Move disk: 1  from B  to C    A: 5       B: ...  C: 1 2 3 4
Move disk: 5  from A  to B    A: ...     B: 5    C: 1 2 3 4
Move disk: 1  from C  to A    A: 1       B: 5    C: 2 3 4
Move disk: 2  from C  to B    A: 1       B: 2 5          C: 3 4
Move disk: 1  from A  to B    A: ...     B: 1 2 5        C: 3 4
Move disk: 3  from C  to A    A: 3       B: 1 2 5        C: 4
Move disk: 1  from B  to C    A: 3       B: 2 5          C: 1 4
Move disk: 2  from B  to A    A: 2 3     B: 5    C: 1 4
Move disk: 1  from C  to A    A: 1 2 3   B: 5    C: 4
Move disk: 4  from C  to B    A: 1 2 3   B: 4 5          C: ...
Move disk: 1  from A  to B    A: 2 3     B: 1 4 5        C: ...
Move disk: 2  from A  to C    A: 3       B: 1 4 5        C: 2
Move disk: 1  from B  to C    A: 3       B: 4 5          C: 1 2
Move disk: 3  from A  to B    A: ...     B: 3 4 5        C: 1 2
Move disk: 1  from C  to A    A: 1       B: 3 4 5        C: 2
Move disk: 2  from C  to B    A: 1       B: 2 3 4 5      C: ...
Move disk: 1  from A  to B    A: ...     B: 1 2 3 4 5    C: ...

*/
###===========================================
