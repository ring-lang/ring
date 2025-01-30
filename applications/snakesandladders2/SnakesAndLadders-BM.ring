### SnakesAndLadders
### Bert Mariani  2024-12-09
### -------------------------------------------------

load "stdlibcore.ring"
load "lightguilib.ring"

//================================================
// Square = Top-Left 250- 10  Top-Right  1050- 10     800 
//          Bot-Left 250-790  Bot-Right  1050-790     780


aBoard     = list(10,10)   // 2D Squares of X,Y

ImageScale  = 1                       // Scale Image 200x200 => 50x5       
imageDiceY  = null
imageDiceW  = null

WhoseTurn   = "Red"                  // Red or Yellow

NextTurnRed = "Next Turn: Red "
NextTurnYel = "Next Turn: Yellow "

PosRed     = 0
PosYel     = 0

oldPosRed  = 1
oldPosYel  = 1

msgPosRed  = "Position Red: "+    PosRed      
msgPosYel  = "Position Yellow: "+ PosYel     

DiceNumber = 1  // Returned by Throw Dice

//-----------------------------
// Slide Up/Down  Ladder/Snake
aFromTo = [ 1,2 ]      // Pos to Slide for Ladder or Snake 

aSlide  = [ [ 6,27],   // Ladder UP
		    [ 9,50],
		    [20,39],
		    [25,57],
		    [53,72],
		    [54,85],
		    [61,82],
		    [43,16],   // Snake DOWN
		    [55,34],
		    [70,48],
		    [78,42],
		    [95,73],
		    [96,82]
		 ]  

//===============================================

xPos    = 100   ### Canvas position on Screen
yPos    = 25
xWidth  = 1400  ### Canvas size on Screen
yHeight = 1000  

width   = 800   ### For  Window Moved
height  = 800   ### 
  
// Need to define variable when using Func StartApp()
MonaLisa = null 
daVinci  = null 
Canvas   = null
myApp    = null


###-------------------------------
### Define Colours, Pens, Brushes

colorGreen   = new qcolor() { setrgb(000,255,000,128) }  ### faint
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ### 64 faint line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(2) }
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(1) }
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(2) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(2) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(2) }

brushSR     = new qbrush() { setstyle(1)  setcolor (colorRed)}      ### Red
brushSG     = new qbrush() { setstyle(1)  setcolor (colorGreen)}    ### Green
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlue)}     ### Blue
brushSY     = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSGR    = new qbrush() { setstyle(1)  setcolor (colorGray)}     ### 
brushSW     = new qbrush() { setstyle(1)  setcolor (colorWhite)}    ### 
brushSM     = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  ### 

brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty


//==========================================
//=========================================
// START the APP

 myApp = new qApp 
 {
    win = new qWidget()
    {
        setWindowTitle("Snakes and Ladders: ")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size
		reSize(xWidth, yHeight)
		winheight = win.height()
		fontSize = 8+(winheight/100)
		

        ###===================================		

        Canvas = new qlabel(win)
        {
            ### daVinci Paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)
            
            daVinci = new qpainter()
            {
               begin(MonaLisa)
               translate(xWidth/2 , yHeight/2)       ### TRANSLATE CO-ORD x,y -- 0,0 MAPS TO 300,300
               #endpaint()                           ### This will Stop the Painting   
            }
            

            //================================================
            // IMAGES 
			
            //-------------------------------------------------
            // GAME BOARD IMAGE
            imageGB = new qlabel(win)                             
			{
				image = new qPixMap("GameImage-900.png")                          
				setpixmap(image.scaled(image.Width() , image.Height() ,0,0))   ### Size-H, Siz-V, Aspect, Transform
				setGeometry( 250, 20,image.Width(),image.Height())   
            }  			
		

		    //----------------------------------------------	
            // DRAW MONA-LISA PixMap

            setPixMap(MonaLisa)   // Draw It
        } 

		
		//===================================================
		
            // DISK RED  - 200x200
            imageDiskRed = new qlabel(win) 
            {
                image = new qPixMap("RedT.png")
                setpixmap( image.scaled(image.width(), image.height(), 0, 0) )  
                setGeometry(-200,-250, 220, 220)				
            }

            // DISK YELLOW  - 200x200
            imageDiskYel = new qlabel(win) 
            {
                image = new qPixMap("YellowT.png")
                setpixmap( image.scaled(image.width(), image.height(), 0, 0) )  
                setGeometry(-200,-250, 220, 220)				
            }

 	    //=====================================================
		
		//----------------------------------------------
		// DICE -- YELLOW Dice - 200x200
		//setGeometry( 10, 340, image.Width(), image.Height())
					  
            imageDiceY1 = new qlabel(win) 
            {
                image = new qPixMap("DiceYel1.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)			
            }
			
            imageDiceY2 = new qlabel(win) 
            {
                image = new qPixMap("DiceYel2.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  	
				setGeometry( 10, 340, 220, 220)				
            }

            imageDiceY3 = new qlabel(win) 
            {
                image = new qPixMap("DiceYel3.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)				
            }

            imageDiceY4 = new qlabel(win) 
            {
                image = new qPixMap("DiceYel4.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)				
            }			
			
            imageDiceY5 = new qlabel(win) 
            {
                image = new qPixMap("DiceYel5.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  	
				setGeometry( 10, 340, 220, 220)				
            }

            imageDiceY6 = new qlabel(win) 
            {
                image = new qPixMap("DiceYel6.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)				
            }			
       
		//----------------------------------------------
		// DICE -- RED Dice - 200x200
		//setGeometry( 10, 340, image.Width(), image.Height())
					  
            imageDiceR1 = new qlabel(win) 
            {
                image = new qPixMap("DiceRed1.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)
				
            }
			
            imageDiceR2 = new qlabel(win) 
            {
                image = new qPixMap("DiceRed2.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  	
				setGeometry( 10, 340, 220, 220)				
            }

            imageDiceR3 = new qlabel(win) 
            {
                image = new qPixMap("DiceRed3.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)				
            }

            imageDiceR4 = new qlabel(win) 
            {
                image = new qPixMap("DiceRed4.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)				
            }			
			
            imageDiceR5 = new qlabel(win) 
            {
                image = new qPixMap("DiceRed5.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  	
				setGeometry( 10, 340, 220, 220)				
            }

            imageDiceR6 = new qlabel(win) 
            {
                image = new qPixMap("DiceRed6.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, 340, 220, 220)				
            }	
			
			
            imageWinner = new qlabel(win) 
            {
                image = new qPixMap("Winner.png")
                setpixmap( image.scaled(image.width() / 2, image.height() / 2 , 0, 0) )  
				setGeometry( 10, -340, 314, 220)				
            }			
			
			
			
        //=================================================================	
		// BUTTONS

		C_ButtonEmptyStyl   = "border-radius:8px;color:black; background-color: rgb(34,177,76)"     // PaleGreen
		C_ButtonRedStyle    = "border-radius:6px;color:black; background-color: Pink"
		C_ButtonBlueStyle   = "border-radius:6px;color:black; background-color: Cyan"
		C_ButtonYellowStyle = "border-radius:6px;color:black; background-color: Yellow"
		C_ButtonOrangeStyle = "border-radius:6px;color:black; background-color: Orange"
		C_ButtonGrayStyle   = "border-radius:6px;color:black; background-color: rgb(213, 245, 227)" // Pale Yellow
		

		//----------------------------------------------				
		PlayPosRed = new QLabel(win)
		{
			setFont( new qFont("Cambria",fontSize,50,0))
		    setStyleSheet(C_ButtonRedStyle)
			//setAlignment(Qt_AlignHCenter|Qt_AlignVCenter)
			setText("Position Red: 0")
			setGeometry(  10, 20 , 200, 30)
		}
		
		//----------------------------------------------
		PlayPosYel = new QLabel(win)
		{
			setFont( new qFont("Cambria",fontSize,50,0))
			setStyleSheet(C_ButtonYellowStyle)
			//setAlignment(Qt_AlignHCenter|Qt_AlignVCenter)
			setText("Position Yel: ")
			setGeometry(  10, 55 , 200, 30)
		}
		
		//----------------------------------------------				
		StatusBar = new qstatusbar(win)
		{
			setstylesheet(C_ButtonGrayStyle)
			setFont( new qFont("Cambria",fontSize,50,0))
			setGeometry(  10, 90 , 200, 30)
			showMessage("Msg:",0)
		}
		
		//----------------------------------------------				
		NewGame = new QPushButton(win)
		{
			setFont( new qFont("Cambria",fontSize,50,0))
			setStyleSheet("background-color: rgb(215, 189, 226)")
			setText("New Game:")
			setClickEvent("pStart()")
			setGeometry(  10, 250 , 200, 30)
		}
		
		//----------------------------------------------								
		//-----------------------------------------------
		NextMove = new QLabel(win)
		{
			setFont( new qFont("Cambria",fontSize,50,0))
			setStyleSheet(C_ButtonOrangestyle)
			setAlignment(Qt_AlignHCenter|Qt_AlignVCenter)
			setText("Next Turn: Red ")
			setGeometry(  10, 285 , 200, 30)
		}
		
		//----------------------------------------------
		ThrowDice = new QPushButton(win)
		{
			setFont( new qFont("Cambria",fontSize,50,0))
			setStyleSheet("background-color: aqua")
			setText("Throw Dice:")
			setClickEvent("ThrowDice()")
			setGeometry(  10, 320 , 200, 30)
		}
        
        //=============================================================
        //=============================================================    
     
      show()        
      Main()	  
    }
    exec()
 }


###==========================================================================
###==========================================================================

Func Main()

   AssignBoard()        // Sq 1-100 assigned Co-ordinates
   SRandom(10)
	
   // VerifyMoveCoord()           // Move the DiskRed around the Board
   // DiceNumber = ThrowDice()    // Throws Dice, Draws Dice, Returns Number
     
   // DeclareWinner("Red", 100)   // Test Winner Image
	
Return

//========================================================
// NEW GAME

Func pStart()

	WhoseTurn   = "Red"                  // Red or Yellow

	NextTurnRed = "Next Turn: Red "
	NextTurnYel = "Next Turn: Yellow "

	PosRed     = 0
	PosYel     = 0

	oldPosRed  = 1
	oldPosYel  = 1
	
	SRandom(10)

Return



###=======================================================
### DICE -THROW -- RANDOM Nbr

Func ThrowDice()

//See "ThrowDice()"+nl

	Dice  =  6                            // How many Dice 6  to use 
	nbr   =  0
	
	while nbr = 0  
		  nbr = random(dice)              // 0-6  ignore 0
	end
		//See "Dice Nbr: "+nbr +nl
	
    //-----------------------
    // Show New Dice Color Value	
	
	DrawDiceImage(nbr)                    // <===////
	   
	//----------------------------
	// CURRENT TURN --  PLAYER-Color -- Add Position Number
	
	if WhoseTurn  = "Red"               // HANDLE RED
	   oldPosRed  = PosRed
	      PosRed += nbr
		  
			if PosRed > 100   // Need to Land exactly on 100 to Win
			   PosRed = oldPosRed 
			   Msg = "Red: Not on 100"
			   StatusBar.showMessage(Msg, 0) 	

	           WhoseTurn = "Yellow"                         // SWITCH TO YELLOW
	           NextMove.setText(NextTurnYel )	
	           NextMove.setStyleSheet(C_ButtonYellowStyle)
			   
			   Return
			ok
		  
		  
	      PlayPosRed.setText("Pos Red: "+ oldPosRed +" -> "+ PosRed )
		  
		  MoveDiskStep("Red",oldPosRed,PosRed)
	   
	else 
	   oldPosYel = PosYel               // HANDLE YELLOW
	     PosYel += nbr

			if PosYel > 100   // Need to Land exactly on 100 to Win
			   PosYel = oldPosYel 
			   Msg = "Yel: Not on 100"
			   StatusBar.showMessage(Msg, 0) 

	           WhoseTurn = "Red"                             // SWITCH TO RED
	           NextMove.setText(NextTurnRed )   
	           NextMove.setStyleSheet(C_ButtonRedStyle)
			   
			   Return
			ok		 
		 
		 
	     PlayPosYel.setText("Pos Yel: "+ oldPosYel +" -> "+ PosYel )
		 
		 MoveDiskStep("Yellow",oldPosYel,PosYel)
	ok
	
	
    //-------------------------------	
    // NEXT-TURN -- Change colors to match NextPlayer Turn and Dice
	
	if WhoseTurn  = "Red"
	    WhoseTurn = "Yellow"                         // SWITCH TO YELLOW
	    NextMove.setText(NextTurnYel )	
	    NextMove.setStyleSheet(C_ButtonYellowStyle)	
	else
	    WhoseTurn = "Red"                             // SWITCH TO RED
	     NextMove.setText(NextTurnRed )   
	   NextMove.setStyleSheet(C_ButtonRedStyle)
	ok
	
	//---------------------------------
	
	
	//MoveDisk()        // Red and Yellow New Positions
	
Return nbr

###==========================================================================
// Clear Images
Func  ClearImages()

//See "ClearImages()"+nl
        
	MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
	Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
	MyApp.ProcessEvents()               ### <<< EXEC the Draw
        
return

###==========================================================================
// Draw IMAGES

Func DrawDiceImage(nbr)

//See "DrawDiceImage()"+nl

	//-------------------------------------------------
	// DICE  -- On Game Board Image
	// Put them ALL-12  OFF the Board

		imageDiceY1.setGeometry( -200,-250, 220, 220)
		imageDiceY2.setGeometry( -200,-250, 220, 220)
		imageDiceY3.setGeometry( -200,-250, 220, 220)
		imageDiceY4.setGeometry( -200,-250, 220, 220)
		imageDiceY5.setGeometry( -200,-250, 220, 220)
		imageDiceY6.setGeometry( -200,-250, 220, 220)
		
		imageDiceR1.setGeometry( -200,-250, 220, 220)
		imageDiceR2.setGeometry( -200,-250, 220, 220)
		imageDiceR3.setGeometry( -200,-250, 220, 220)
		imageDiceR4.setGeometry( -200,-250, 220, 220)
		imageDiceR5.setGeometry( -200,-250, 220, 220)
		imageDiceR6.setGeometry( -200,-250, 220, 220)		
		
		
    //--------------------------------
	// DICE -- Display Proper Color and Number
		if WhoseTurn = "Yellow"
			if nbr=1 imageDiceY1.setGeometry( 10, 340, 220, 220) ok
			if nbr=2 imageDiceY2.setGeometry( 10, 340, 220, 220) ok
			if nbr=3 imageDiceY3.setGeometry( 10, 340, 220, 220) ok
			if nbr=4 imageDiceY4.setGeometry( 10, 340, 220, 220) ok
			if nbr=5 imageDiceY5.setGeometry( 10, 340, 220, 220) ok
			if nbr=6 imageDiceY6.setGeometry( 10, 340, 220, 220) ok
		ok	
			
		if WhoseTurn = "Red"	
			if nbr=1 imageDiceR1.setGeometry( 10, 340, 220, 220) ok
			if nbr=2 imageDiceR2.setGeometry( 10, 340, 220, 220) ok
			if nbr=3 imageDiceR3.setGeometry( 10, 340, 220, 220) ok
			if nbr=4 imageDiceR4.setGeometry( 10, 340, 220, 220) ok
			if nbr=5 imageDiceR5.setGeometry( 10, 340, 220, 220) ok
			if nbr=6 imageDiceR6.setGeometry( 10, 340, 220, 220) ok		
		ok
		

    //--------------------------------         		
	Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
	MyApp.ProcessEvents()               ### <<< EXEC the Draw
	
	
return 

//===========================================================================
// Board Dimensions --   Sq= 80 x 80
//   X 01-10 => 250 + X*80 + 40   1045-250 = 795    >> 645
//   Y 01-10 => 790 - Y*80 + 40    790-10  = 780    >> 400
//

Func AssignBoard()

//See "AssignBoard()"+nl

	aBoard = list(10,10)   // 2D Squares of X,Y
	
    //-----------------------------------
    // Fill in square co=ordinates 
	
	for X = 1 to 10		
		H = floor( 250 + (X-1)*88.5 +12)
		 
		for Y = 1 to 10
			V = floor( 785 - (Y-1)*88.5 +45)	
			aBoard[X][Y] = ""+H +","+ V	     // Horz, Vert -- alpha to numeric				
		next
	next

	
	//------------------------------------
	// FIX Even X-Rows go from Right<--Left
	
	for y = 2 to 10 step 2
		aList = list(10)
			
		for x = 1 to 10                      // Horz
			aList[x] = aBoard[x][y]
		next
		
		z = 10
		for x = 1 to 10 
			aBoard[z][y] = aList[x]		
			z--
		next	
	next
	
	//---------------------------------

Return

//=========================================
//=========================================	
// Used for Debug Verification 	
	
Func VerifyMoveCoord()	

//See "VerifyMoveCoord()"+nl

	//----------------------------------
	// MOVES Verify Visual Position and Left-->Right<---Left Movement
	 
	for Y = 1 to 10
	for X = 1 to 10

		aValue =  split( aBoard[X][Y], ',')
		H      =  0+ aValue[1]
		V      =  0+ aValue[2]
	  
		imageDiskRed.setGeometry(H, V, 200, 200)	

		Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
		MyApp.ProcessEvents()               ### <<< EXEC the Draw	
		sleep(1)
		
	next    
	next
 
	sleep(3.0)	
	

return

//=========================================
// SKIP Turn

Func pSkipTurn()

return

//================================


//===========================================		
//===========================================
// MOVE Disk Piece One Square at a Time

Func MoveDiskStep(DiskColor, OldPos, NewPos)

    See "MovDiskStep(): "+(NewPos - OldPos) +" "+DiskColor +" "+OldPos +" - "+NewPos +nl

    if OldPos =0  OldPos =1  ok       // Ring uses 1

if DiskColor  = "Red"
    PosRedCur =  OldPos	
	
		for PosRedCur =  OldPos to NewPos     
		
			//--- Figure Co-ord--------
			UsePosRed = PosRedCur -1
			
			X =  floor( UsePosRed / 10 )              // 45 / 10 = 4
			Y =  UsePosRed - (X *10)                  // 45 -40 = 5		
			X++                                       // Ring 1
			Y++		
			
			aValue =  split( aBoard[Y][X], ',')       // NEW Position
			H      =  0+ aValue[1]
			V      =  0+ aValue[2] 
			imageDiskRed.setGeometry(H, V, 80, 80)
			
			Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
		    MyApp.ProcessEvents()               ### <<< EXEC the Draw	
		    sleep(0.5)	
        next		
		
		    //--------------------------------------------------------
            // CHECK --Landed on Snale or Ladder - Update MSG Boxes
			
			aSnakeLadder =  SlideUpDown(PosRedCur-1)  // Slide or Climb		
			
			if aSnakeLadder[1] != aSnakeLadder[2]            // Jump
			   PosRedCur = aSnakeLadder[2]
		       PosRed    = PosRedCur
			   PlayPosRed.setText("Pos Red: "+ oldPosRed +" -> "+ PosRed )
			   
			   Msg = "Msg: Red "+aSnakeLadder[1] +"-"+  aSnakeLadder[2] 
			   StatusBar.showMessage(Msg, 0) 
			  
			    //-----------------------------------------------
				// MOVE PIECE Up/Down --Figure Co-ord
				
				UsePosRed = PosRedCur -1                  // Ring 1
				
				X =  floor( UsePosRed / 10 )              // 45 / 10 = 4
				Y =  UsePosRed - (X *10)                  // 45 -40 = 5		
				X++                                       // Ring 1
				Y++		
				
				aValue =  split( aBoard[Y][X], ',')       // NEW Position
				H      =  0+ aValue[1]
				V      =  0+ aValue[2] 
				imageDiskRed.setGeometry(H, V, 80, 80)
				
				Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
				MyApp.ProcessEvents()               ### <<< EXEC the Draw	
				sleep(0.5)		   

			ok
			
	if NewPos = 100
	   DeclareWinner(DiskColor, NewPos)
	   Return
	ok
			
ok
    //--------------------------------

if DiskColor   = "Yellow"	
    PosYelCur = OldPos  

		for PosYelCur =  OldPos to NewPos 	
		
			//----------------------------
			// Figure C-ord
			UsePosYel = PosYelCur -1                     // Ring 1
			
			X =  floor( UsePosYel / 10 )                 // 45 / 10 = 4
			Y =  UsePosYel - (X *10)                     // 45 -40 = 5	
			X++                                          // Ring 1
			Y++		
		
			aValue =  split( aBoard[Y][X], ',')    
			H      =  0+ aValue[1]
			V      =  0+ aValue[2]  
			imageDiskYel.setGeometry(H, V, 80, 80)
			
			
			Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
			MyApp.ProcessEvents()               ### <<< EXEC the Draw	
			sleep(0.5)			
		next	

		    //--------------------------------------------------------
            // CHECK --Landed on Snale or Ladder - Update MSG Boxes
			
			aSnakeLadder =  SlideUpDown(PosYelCur-1)  // Slide or Climb		
			
			if aSnakeLadder[1] != aSnakeLadder[2]            // Jump
		       //See "PosYelCur: "+(PosYelCur-1)  +" aSnakeLadder: "+aSnakeLadder[1] +" "+  aSnakeLadder[2] +nl
			   PosYelCur = aSnakeLadder[2]
               PosYel    = PosYelCur
			   PlayPosYel.setText("Pos Yel: "+ oldPosYel+" -> "+ PosYel )
			   
			   Msg = "Msg: Yel "+aSnakeLadder[1] +"-"+  aSnakeLadder[2] 
			   StatusBar.showMessage(Msg, 0)  

			    //-----------------------------------------------
				// MOVE PIECE Up/Down --Figure Co-ord
				
				UsePosYel = PosYelCur -1                  // Ring 1
				
				X =  floor( UsePosYel / 10 )              // 45 / 10 = 4
				Y =  UsePosYel - (X *10)                  // 45 -40 = 5		
				X++                                       // Ring 1
				Y++		
				
				aValue =  split( aBoard[Y][X], ',')       // NEW Position
				H      =  0+ aValue[1]
				V      =  0+ aValue[2] 
				imageDiskYel.setGeometry(H, V, 80, 80)
				
				Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
				MyApp.ProcessEvents()               ### <<< EXEC the Draw	
				sleep(0.5)		   
			ok
			
				
    if NewPos = 100
	   DeclareWinner(DiskColor, NewPos)
	   Return
	ok	

ok		

		
Return

//===================================
// SLIDE-UP-Down
// aSlideUpDn =[ [ 6,27], ....


Func SlideUpDown(PosNbr)

//See "SlideUpDown: Pos: "+ PosNbr +nl

    Landed = PosNbr
	JumpTo = PosNbr
	
	for k = 1 to len(aSlide)
		if PosNbr   = aSlide[k][1]
		   Landed   = aSlide[k][1]
		   JumpTo   = aSlide[k][2]
		   exit
		ok	
	next
	
	//See "SlideUpDown: Landed: "+Landed + " JumpTo: "+JumpTo +nl
	
	aFromTo[1] = Landed
	aFromTo[2] = JumpTo

return	aFromTo	

//=================================
// Landed on Square 100 - WINNER

Func DeclareWinner(color, Position)

    Msg = "WINNER: "+color  
	StatusBar.showMessage(Msg, 0) 
	
	imageWinner.setGeometry( 10, 35 , 400, 300)		// 10, 90 , 200, 30		645,400  645-155 >> 590
    
	Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
	MyApp.ProcessEvents()               ### <<< EXEC the Draw	
	sleep(0.5)			

Return

//=================================
