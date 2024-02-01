// Name:   MirrorLaser.ring
// Author: Bert Mariani
// Date:   2020-03-07
//

load "stdlibcore.ring"
load "lightguilib.ring"

//-------------------------------------
// 2D Square Array

aSq    = [[ '0','0','0','0','0','0','0','0','0' ],  // 
          [ '0','0','0','/','0','0','0','0','0' ],  // 
          [ '/','\','0','0','0','0','T','0','0' ],  //  /3-4   T3-7
          [ '\','/','0','0','0','0','0','0','0' ],  //
          [ '0','0','0','\','0','0','\','0','0' ],  //  \5-4   \5-7
          [ '0','0','0','0','0','0','0','0','0' ],  //
          [ '0','0','G','0','0','0','/','0','0' ],  //  G7-3   /7-7
          [ '0','0','0','0','0','0','0','0','0' ],  //
          [ '0','0','0','0','0','0','0','0','0' ]]  //

Dir       = 'E'  // N E S W
gunRow    = 7  gunCol    = 3
targetRow = 3  targetCol = 7
semaphore = 0                 ### Traffic Light  1=Running  0=Stopped 

//-----------------------------------
          
Size        = len(aSq)
SleepDelay  = 0.01
SleepRed    = 0.9

RandomMin   = 10           // Gun, Target + 8 Mirrors
RandomInc   = 8
RandomMax   = (Size * Size ) - RandomMin
RandomCur   = 10
LaserSqCount = 1

TitleMirrors       = null
TitleLaserSquares  = null
TitleSemaphore     = null

SrcDest = 'S'               // S-D  Source/Destination Pick
SrcX    = 0  SrcY  = 0      // Filled when User Picks a Ball
DestX   = 0  DestY = 0      // Filled when User Picks an Empty Square

C_ButtonInvalidStyle= 'border-radius:1px; color:black; background-color: rgb(255,102,102); '        ### Light Pink
C_ButtonPickStyle   = 'border-radius:1px; color:black; background-color: rgb(255,255,93); '         ### Yellow           
C_ButtonDestStyle   = 'border-radius:1px; color:black; background-color: rgb(204,255,204); '        ### Cyan

C_Spacing = 0.5 # 1
C_ButtonEmptyStyle  = ' background-color: black; color: blue; border-style: outset; '

// Out Of Bounds
outRow = 0
outCol = 0

###------------------------------------------------
 
moveX = 400  moveY = 100
sizeX = 600  SizeY = 600
        
oPicColor = new QPixmap("images/MirrorBlack.png")
bWidth    = sizeX / Size                    // oPicColor.width()    ### 80 
bHeight   = sizeY / Size                    // oPicColor.height()   ### 80 

Button          = list(Size,Size)
LayoutButtonRow =    list(Size)

LaserGun    = "images/LaserGun.png"     # G
TargetT     = "images/TargetT.png"      # Transparent
TargetS     = "images/TargetS.png"      # Small
TargetBlack = "images/TargetBlack.png"  # Big on Black


MirrorBlack = "images/MirrorBlack.png"  # 0
Mirror1F    = "images/Mirror1F.png"     # /    Forward  none
Mirror1B    = "images/Mirror1B.png"     # \    Backward none


Mirror2DR   = "images/Mirror2DR.png"    #  /p  Forward  right hit
Mirror2UL   = "images/Mirror2UL.png"    # d/   Forward  left  hit 
Mirror2UR   = "images/Mirror2UR.png"    #  \b  Backward right hit
Mirror2DL   = "images/Mirror2DL.png"    # q\   Backward left  hit

Mirror4F    = "images/Mirror4F.png"     # d/p => Z   Forward  both
Mirror4B    = "images/Mirror4B.png"     # q\b => X   Backward both


LineH       = "images/LineH.png"        # -
LineV       = "images/LineV.png"        # |
LineX       = "images/LineX.png"        # +  H->V   V->H

emptyColor  = "images/empty.png"


###=====================================================
###=====================================================

app = new qApp 
{
    win = new qWidget() 
    {
        setWindowTitle('Mirror Laser: ')
        setWinIcon(self,"images/LaserGun.png")
        reSize(sizeX, sizeY)
        winheight = win.height()
        fontSize  = 8 + (winheight / 200)
      
      ###=============================================================================
        ###----------------------------------------------
        ### Title Top Row - Moves Count
            
                            
            TitleMirrors = new qLineEdit(win) 
            {
                setFont(new qFont("Calibri",fontsize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText(" Mirrors: "+ (RandomCur -2) )
            }   

            TitleLaserSquares = new qLineEdit(win) 
            {
                setFont(new qFont("Calibri",fontsize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText(" LaserSquares: "+ LaserSqCount)
            }       
       
            TitleSemaphore = new qLineEdit(win) 
            {
                setFont(new qFont("Calibri",fontsize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText(" State: Start: "+ semaphore)
            }       
         
            NewGame  = new QPushButton(win) 
            {
                //setStyleSheet("background-color:rgb(255,204,229)")
                setFont(new qFont("Calibri",fontsize,100,0))
                setText(" New Game ")
                setClickEvent("NewGameStart()")   
            }               

        ###------------------------------------------------    
      
      ###=============================================================================

        ###-----------------------------------------------------------------------------
        ### QVBoxLayout lays out Button Widgets in a vertical column, from top to bottom.
        
        LayoutButtonMain = new QVBoxLayout()            ### VERTICAL
        LayoutButtonMain.setSpacing(C_Spacing)
        LayoutButtonMain.setContentsmargins(0,0,0,0)
      
      
         ###==================================================
         ### Horizontal - TOP ROW
            LayoutTitleRow = new QHBoxLayout()              
            {  setSpacing(C_Spacing)
               setContentsMargins(0,0,0,0)
            }
                        
            LayoutTitleRow.AddWidget(TitleMirrors)
            LayoutTitleRow.AddWidget(TitleLaserSquares)
            LayoutTitleRow.AddWidget(TitleSemaphore)
            LayoutTitleRow.AddWidget(NewGame)       
                           
            LayoutButtonMain.AddLayout(LayoutTitleRow)            
         
         ###==================================================
     
            ###-----------------------------------------------------------------------
            ### QHBoxLayout lays out widgets in a horizontal row, from left to right
                
            for Row = 1 to Size
                LayoutButtonRow[Row] = new QHBoxLayout()    ### Horizontal
                {   setSpacing(C_Spacing)
                    setContentsMargins(0,0,0,0)
                } 
          
               for Col = 1 to Size
                    Button[Row][Col] = new QPushButton(win) ### Create PUSH BUTTONS
                    {
                        setStyleSheet(C_ButtonEmptyStyle)
                        setIcon(new qIcon(new qPixMap(MirrorBlack) ) )                    
                        setIconSize(new qSize( bWidth, bHeight)) 
                        setClickEvent("UserLeftMouse(" + string(Row) + "," + string(Col) + ")")   ### CLICK PLAY MOVE >>> pPlay
                        setSizePolicy(1,1)
                    }
                    
                    LayoutButtonRow[Row].AddWidget(Button[Row][Col])    ### Widget - Add Horizontal Button
               next
               
               LayoutButtonMain.AddLayout(LayoutButtonRow[Row])         ### Layout - Add ROW of Buttons
            next

            ###------------------------------------------------              

            setLayout(LayoutButtonMain)
            
            ###---------------------------------------------
            
            Play()
         
            show()
            
   }
   exec()
 }

    
###=================================================

Func NewGameStart()

   if semaphore = 1        ### Traffic Light  1=Running  0=Stop
      return               ### No New Game, Until current Game Over
   ok
       
   semaphore = 1           ### Traffic Light  1=Running  0=Stop
   TitleSemaphore.setText(" State: Running: "+ semaphore)
   
   RandomPlacement()
   Play()

   
return
   
###=================================================
// Draw the Mirrors, Gun, Target
// Stop after 81 moves or Target Hit

Func PLAY()   

    size  = len(aSq)
   size2 = size * size
   
   See ">==============<" +nl
   See "PLAY: Start"+ nl
   DisplaySquare(aSq) See nl
   MapSqToImage()
   app.processevents()
   
   Row = gunRow
   Col = gunCol
   Dir = 'E'
   
   for i = 1 to (size2 * 2)   // 81 +9 max
   
       //---------------------------------------------
       // Start from Gun, Move 1 Square in Direction
       
       if Row = 0 OR Col = 0
         See "Play: Call MoveDir: "+i + " "+ Row +"-"+ Col +" Call: "+ outRow +"-"+ outCol+nl
         return
       ok
       
      aRC = MoveDir( Row, Col)                    
      Row = aRC[1]
      Col = aRC[2]
  
      //--------------
      // Hit Target  
      if Row = targetRow AND Col = targetCol
         semaphore = 0        ### Traffic Light  1=Running  0=Stop
         TitleSemaphore.setText(" State: Hit Target: "+ semaphore)
         
         Button[targetRow][targetCol] { setIcon(new qIcon(new qPixMap(TargetBlack) ) )  } 
         
         See nl+"TARGET HIT: "+i +" "+ Row +"-"+ Col +nl
         See "Play: Target"+ nl
         
         DisplaySquare(aSq) See nl
         exit
      
      
      //-------------
      // Out of Bounds
      but Row = 0
         semaphore = 0        ### Traffic Light  1=Running  0=Stop
         TitleSemaphore.setText(" State: OutBounds: "+ semaphore) 
         
         See nl+"OUT Bounds HIT.: "+i +" "+ outRow +"-"+ outCol +nl  // old Row and col
         See "Play: Out of Bounds"+ nl
         
         DisplaySquare(aSq) See nl
         exit     

      //--------------
      // Hit GUN  
      but Row = gunRow AND Col = gunCol
         semaphore = 0        ### Traffic Light  1=Running  0=Stop 
         TitleSemaphore.setText(" State: Hit Gun: "+ semaphore)   
         
         Button[gunRow][gunCol]   { setStyleSheet(C_ButtonInvalidStyle) } 
         app.processEvents()
         Sleep(SleepRed)
         Button[gunRow][gunCol]   { setStyleSheet(C_ButtonEmptyStyle) } 
         
         See nl+"GUN HIT: "+i +" "+ Row +"-"+ Col +nl
         See "Play: GUN"+ nl
         
         DisplaySquare(aSq) See nl  
         exit
      ok



      TitleLaserSquares.setText(" LaserSquares: "+ i)
  
      Sleep(sleepDelay) 
      MapSqToImage()
      app.processevents()
      
   next
   
   See "PLAY: End"+ nl +"<==============>" +nl +nl
   semaphore = 0        ### Traffic Light  1=Start  0=Stop

return         

###=================================================
// Display Gun and Target, Mirrors and Empty
// Based on aSq Array contents

Func MapSqToImage()

   //-------------------------
   
   size = len(aSq)
   for i = 1 to size
      for j = 1 to size
      
      //-----------------------
      // EMPTY SQUARE
      
      if aSq[i][j] = '0'
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(MirrorBlack) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok 

      //-----------------------
      // MIRROR - PLAIN
      
      if aSq[i][j] = '\'
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror1B) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok    

      if aSq[i][j] = '/'
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror1F) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok    

      //---------------
      // GUN and TARGET
      
      if aSq[i][j] = 'G'   
         gunRow = i
         gunCol = j
         
         Button[i][j] { 
            setIcon(new qIcon(new qPixMap(LaserGun) ) )  
            setIconSize(new qSize( bWidth, bHeight)) 
         } 
      ok
      
      if aSq[i][j] = 'T'   
         targetrow = i
         targetCol = j
         Button[i][j] { 
            setIcon(new qIcon(new qPixMap(TargetS) ) )  
            setIconSize(new qSize( bWidth, bHeight)) 
         }     
      ok
      
      //-------------------------
      // MIRROR-4-WAY  4B-X  4F-Z

      if aSq[i][j] = 'Z'   # /
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror4F) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok 
      if aSq[i][j] = 'X'   # \
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror4B) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok 


      //-----------------------------------------------------
      // MIRROR-2-WAY 2UL-d/  2DR-/p  2UR-\b  2DL-q\  
      
      if aSq[i][j] = 'd'  # d/
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror2UL) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok 
      
      if aSq[i][j] = 'p'  # /p
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror2DR) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok
      
      
      if aSq[i][j] = 'b'  # \b
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror2UR) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok 
      
      if aSq[i][j] = 'q'  # q\
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(Mirror2DL) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 
         }
      ok 

         

      //-------------------------------------------
      // LINES Horz -  Vert |   H->V = +   V+H = +

      if aSq[i][j] = '-'
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(LineH) ) )  
         setIconSize(new qSize( bWidth, bHeight))  

         }
      ok 

      if aSq[i][j] = '|'
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(LineV) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 

         }
      ok 

      if aSq[i][j] = '+'
         Button[i][j] { 
         setIcon(new qIcon(new qPixMap(LineX) ) )  
         setIconSize(new qSize( bWidth, bHeight)) 

         }
      ok       
      
      //----------------------
      
      next
   next

   
return
   
###=================================================
// Move Dir N S E W
// Move till a Mirror Hit

Func MoveDir( Row, Col)

   sizeRow = len(aSq)
   outRow  = Row
   outCol  = Col

   //------------------------
   // Check Direction
   
   if  Dir = 'N'     Row = Row -1   // ^
   but Dir = 'S'     Row = Row +1   // v   
   but Dir = 'E'     Col = Col +1   // >
   but Dir = 'W'     Col = Col -1   // <   
   ok

   //----------------------
   // Check out of Bounds
    
   FlagBounds = 0
   
   if Row < 1        Row = 1        FlagBounds = 1 ok    // To far North   
   if Row > sizeRow  Row = sizeRow  FlagBounds = 1 ok    // To far South
   if Col < 1        Col = 1        FlagBounds = 1 ok    // To far West
   if Col > sizeRow  Col = sizeRow  FlagBounds = 1 ok    // To far East
      
   if FlagBounds = 1 
      See "MoveDir: OutBounds: "+ Row +"-"+ Col +" Call: "+ outRow +"-"+ outCol +nl
      
      Button[Row][Col]   { setStyleSheet(C_ButtonInvalidStyle) } 
      app.processEvents()
      sleep( SleepRed)
      Button[Row][Col]   { setStyleSheet(C_ButtonEmptyStyle) }

      return [0,0]      // Bad out of Bounds
   ok

   CheckMirror(Row,Col)

return [Row,Col]

###=================================================
// Check if this Sq has a Mirror
// called by MoveDir()
//           M    M2U    M2D   M4
// Empty 0   \    \b     q\    X      Mirror Backward
//       0   /    d/     /p    Z      Mirror Forward
//
// Direction change to  N->E->S->W->N       <-N<-E<-S<-W<-N 

Func CheckMirror(Row,Col)

   //See nl+"CheckMirror.: "+ Row +"-"+ Col +" Dir: "+ Dir +nl

   Tilt = aSq[Row][Col]
   
   //===========
   
   //------------------------------
   // EMPTY SQ  -- Add Horz -  or Vert |  Line
   
   if Tilt = '0'   
       // Horizontal Line
      if Dir = 'E' OR Dir = 'W'     
         aSq[Row][Col] = '-'         
      ok
      
      // Vertical Line
      if Dir = 'N' OR Dir = 'S'     
         aSq[Row][Col] = '|'        
      ok
      
      return 0
   ok
   
   //------------------------------------------
   // LINE already Horz or Vert -- Add Cross +
   
   if Tilt = '-' AND ( Dir = 'N' OR Dir = 'S' )  
      aSq[Row][Col] = '+' 
      return 0
   ok 
   
   if Tilt = '|' AND ( Dir = 'E' OR Dir = 'W' )  
      aSq[Row][Col] = '+' 
      return 0
   ok 
   
    //===========
   
   //-------------------------------------
   // ONE Mirror Backward  \ \ \ \ \
   // Clock        : N->E  E->S  S->W  W->N
   // Counter-Clock: N<-E  E<-S  S<-W  W<-N 
   
   if Tilt = '\'   
   
       // \b  UP  WS  
       
      if Dir = 'W' OR Dir = 'S' 
         aSq[Row][Col] = 'b'
               
         if  Dir = 'W'  Dir =  'N'           // Clockwise
         but Dir = 'S'  Dir =  'E'    ok     // Counter-Clock
      
        // \q  Down NE
        
      but Dir = 'N' OR Dir = 'E' 
         aSq[Row][Col] = 'q'  
      
         if  Dir = 'N'  Dir =  'W'           // Counter-Clock
         but Dir = 'E'  Dir =  'S'    ok     // Clockwise

      ok
   ok 
   
   //---------------------------------------
   // ONE Mirror Forward / / / / / 
   
   if Tilt = '/'   
   
       // d/ Up   SE
       
      if Dir = 'E' OR Dir = 'S' 
         aSq[Row][Col] = 'd'
         
         if  Dir = 'E'  Dir =  'N'            // Counter-Clock
         but Dir = 'S'  Dir =  'W'    ok      // Clockwise

         
      // /p Down  NW
      
      but Dir = 'N' OR Dir = 'W' 
         aSq[Row][Col] = 'p'
         
         if  Dir = 'N'  Dir =  'E'             // Clockwise
         but Dir = 'W'  Dir =  'S'    ok       // Counter-Clock
         
      ok
   ok

    //===========

   //------------------------------------------
   // TWO Mirror Backward Dn -----q\ q\ q\ q\ q\
   // Clock        : N->E  E->S  S->W  W->N
   // Counter-Clock: N<-E  E<-S  S<-W  W<-N 
   
   if Tilt = 'q'  
   
      // q\ Up side  SW
      
      if Dir = 'S' OR Dir = 'W' 
         aSq[Row][Col] = 'X'
      ok 
      
         if  Dir = 'S'  Dir =  'E'             // Counter-Clock
         but Dir = 'W'  Dir =  'N'             // Clockwise
         
         but Dir = 'N'  Dir =  'W'             // path already taken
         but Dir = 'E'  Dir =  'S'    ok       // path already taken

   ok
   
   //-----------------------------------------
   // TWO Mirror Backward Up -----\b \b \b \b \b
   
   if Tilt = 'b'   
   
       // \b  Down side  EN
       
      if Dir = 'E' OR Dir = 'N' 
         aSq[Row][Col] = 'X'
      ok
      
         if  Dir = 'E'  Dir =  'S'                 // Clockwise
         but Dir = 'N'  Dir =  'W'                 // Counter-Clock

         but  Dir = 'S'  Dir =  'E'                // path already taken
         but Dir = 'W'  Dir =  'N'    ok           // path already taken

    ok
    
    //===========
   
   //-----------------------------------------
   // Mirror Forward Up -----d/ d/ d/ d/ d/
   // Clock        : N->E  E->S  S->W  W->N
   // Counter-Clock: N<-E  E<-S  S<-W  W<-N 
   
   if Tilt = 'd'   
   
       // d/  Down side  WN
       
      if Dir = 'W' OR Dir = 'N' 
         aSq[Row][Col] = 'Z'
      ok 
      
         if  Dir = 'W'  Dir =  'S'                  // Counter-Clock
         but Dir = 'N'  Dir =  'E'                  // Clockwise
         
          but Dir = 'E'  Dir =  'N'                 // path already taken
         but Dir = 'S'  Dir =  'W'    ok            // path already taken   
      
   ok 

   //-----------------------------------------
    // Mirror Forward Dn -----/p /p /p /p / p
   
   if Tilt = 'p'   
   
        // /p   Up side  ES
        
      if Dir = 'S' OR Dir = 'E'   
         aSq[Row][Col] = 'Z'  
      ok
      
         if  Dir = 'S'  Dir =  'W'                  // Clockwise
         but Dir = 'E'  Dir =  'N'                  // Counter-Clock
         
         but Dir = 'N'  Dir =  'E'                  // path already taken
         but Dir = 'W'  Dir =  'S'    ok            // path already taken
         
   ok 
   
   //-----------------------  

    //===========

   //-----------------------------------------
   // Mirror X Backward ----- X X X X X 
   // Counter      : N->E  E->S  S->W  W->N
   // Counter-Clock: N<-E  E<-S  S<-W  W<-N 
   
   if Tilt = 'X'   
   
       // \X  
       
         aSq[Row][Col] = 'X'
               
         if  Dir = 'E'  Dir =  'S'                  // Clockwise
         but Dir = 'N'  Dir =  'W'                  // Counter-Clock
         but Dir = 'S'  Dir =  'E'                  // Counter-Clock
         but Dir = 'W'  Dir =  'N'    ok            // Clockwise
          
   ok 

   //-----------------------------------------
    // Mirror Z Forward ----- Z Z Z Z Z 
   
   if Tilt = 'Z'   
   
        // Z/   Up side  ES
        
         aSq[Row][Col] = 'Z'  
      
         if  Dir = 'E'  Dir =  'N'                  // Counter-Clock
         but Dir = 'S'  Dir =  'W'                  // Clockwise
         but Dir = 'N'  Dir =  'E'                  // Clockwise
         but Dir = 'W'  Dir =  'S'    ok            // Counter-Clock

   ok 
   
    //-----------------------  

    //===========
   
return  



###=================================================
// UserSrcDest = 'S'         //  S/D  Source/Destination Pick
// SrcX  = 0  SrcY  = 0      // Filled when User Picks a Ball
// DestX = 0  DextY = 0      // Filled when User Picks an Empty Square


Func UserLeftMouse(Row,Col)

    if  semaphore = 1         ### Traffic Light  1=Running  0=Stop
        SrcDest = 'S'
        TitleSemaphore.setText(" State: Running: "+ semaphore)
      
      return                  ### No change allowed until Game Over
   ok
       
    //-------------------------
    // SOURCE -- BALL Pick - 

    if SrcDest = 'S'
        SrcX = Row  SrcY = Col
            
        if aSq[Row][Col] != '0'                                          ### GOOD Source is Ball
            Button[SrcX][SrcY] { setStyleSheet(C_ButtonPickStyle) }      ### Yellow From-Square
            SrcDest = 'D'                                                ### Reset to Next Pick to Destination
            return
        ok     

        if aSq[Row][Col] = '0'                                           ### BAD Source is Empty Sq
            SrcDest = 'S'                                                ### Reset to Next Pick to Source
            return
        ok   
        
    ok
    
    //----------------------------------
    // DESTINATION -- EMPTY Square Pick - 
    
    if SrcDest = 'D'
        DestX = Row  DestY = Col
        
        EraseLines()
        
        if aSq[Row][Col] = '0'                                           ### GOOD Dest is Empty Sq
            Button[SrcX][SrcY] { setStyleSheet(C_ButtonPickStyle) }      ### Yellow From-Square
            SrcDest = 'S'                                                ### Reset to Next Pick to Source
        ok
        
        if aSq[Row][Col] != '0'                                          ### BAD Dest is Ball       
            Button[SrcX][SrcY]   { setStyleSheet(C_ButtonEmptyStyle) }   ### Changed Pick   
            Button[DestX][DestY] { setStyleSheet(C_ButtonPickStyle) }    ### Yellow New Source 
            SrcX = DestX  SrcY = DestY                                   ### Change Dest to Src 
            
            SrcDest = 'D'                                                ### Look for New Destination
            return
        ok          
    ok
 
    //--------------------------
    // Check if Valid Move

    #See "aSq: Src: "+SrcX +"-"+ SrcY +" = "+  aSq[SrcX][SrcY] +" Dest: "+ DestX +"-"+ DestY +" = "+ aSq[DestX][DestY]
   
   
    aSq[DestX][DestY] =  aSq[SrcX][SrcY]        // Move Contents to Dest
    aSq[SrcX][SrcY]   = '0'                     // Blank to Source
       
    //------------------
    // Reset Move
    Button[SrcX][SrcY]   { setStyleSheet(C_ButtonEmptyStyle) }   ### Changed Pick
    SrcX  = 0  SrcY  = 0   DestX = 0  DestY = 0 

    semaphore = 1                               ### Traffic Light  1=Running  0=Stop
    TitleSemaphore.setText(" State: Running: "+ semaphore)
   
    Play()


    
return

###=================================================
// Erase Lines Horz -  Vert |  Cross +
// Moving mirror, new path calc.
//           M    M2U   M2D  M4
// 0-Empty   \    b     q    X      MirBack
//           /    d     p    Z      MirFwd

Func EraseLines()
   size = len(aSq)
   
   Button[targetRow][targetCol] { setStyleSheet(C_ButtonEmptyStyle) }   // Clear Target Hit
   Button[gunRow][gunCol]       { setStyleSheet(C_ButtonEmptyStyle) }   // Clear Gun    Hit
   
   for i = 1 to size
      for j = 1 to size
         
         if aSq[i][j] = '-' OR aSq[i][j] = '|' OR aSq[i][j] = '+' 
            aSq[i][j] = '0'
         ok 

         if aSq[i][j] = 'b' OR aSq[i][j] = 'q' OR aSq[i][j] = 'X' 
            aSq[i][j] = '\'
         ok    
         
         if aSq[i][j] = 'd' OR aSq[i][j] = 'p' OR aSq[i][j] = 'Z' 
            aSq[i][j] = '/'
         ok       
         

         
      next
   next  


###=================================================
// Display a Square Array List

Func DisplaySquare(mySquare)
    
   Rows = len(mySquare)
   Cols = len(mySquare[1])
    
   for i = 1 to Rows        
      for j = 1 to Cols
         See " "+ mySquare[i][j]
      next
      See nl
   next
        
return

//==============================
// Display a Linear Array List

Func DisplayLinear(myList)
    
    for i = 1 to len(myList)            
        See " "+ myList[i]
    next
    
return

###=================================================

Func RandomPlacement()

      //----------------------
      // Test New play layout
      aSq2    = [[ '0','0','0','0','0','0','0','0','0' ],  // 
              [ '0','0','0','0','0','0','0','/','0' ],  // 
              [ '0','0','0','/','T','0','0','0','0' ],  //  /3-4   T3-7
              [ '/','0','\','0','0','0','0','0','\' ],  //
              [ '0','0','0','\','0','0','\','0','0' ],  //  \5-4   \5-7
              [ '0','/','0','0','0','0','0','\','0' ],  //
              [ '0','0','\','0','0','0','/','0','0' ],  //  G7-3   /7-7
              [ 'G','0','0','0','0','/','0','0','0' ],  //
              [ '0','0','0','0','0','0','0','0','0' ]]  //
        
      //-----------------------
      
      
   RandomCur = RandomCur + RandomInc   
   if RandomCur  > RandomMax - RandomMin  
      RandomCur = RandomMax - RandomMin
   ok 
   
   TitleMirrors.setText(" Mirrors: "+ (RandomCur) )

    //--------------------------------------------
   
   aMirrors = list(Size,Size)   // Zeros - 0 -
   
   for playRandomMirror = 1 to RandomCur
   
      // Linear lists   
      aEmpty  = SquaresToList(aMirrors, 'Empty' )
            //See nl+"Echo: " DisplayLinear( aEmpty )

      // Pick random Empty square number
      sqrNbr  = RandomSqr( aEmpty)
            if sqrNbr = 0   See nl+"No Random Square Left"  return  ok

      // Number of square to row-col
      aRowCol = NumberToRowCol(sqrNbr) 
            Row = aRowCol[1]
            Col = aRowCol[2]
            //See nl+nl+" Random: RC: "+ Row +"-"+ Col 
            
      
      // Set Square to Mirror / or \  G  T
      
      if playRandomMirror = 1
         if Col = len(aSq)           // Gun at Extreme Right, move it Left
            Col = Col -1
         ok
            
         aMirrors[Row][Col] = 'G'
      but playRandomMirror  = 2
         aMirrors[Row][Col] = 'T'
      
      but playRandomMirror % 2 = 0
         aMirrors[Row][Col] = '/'
      else
         aMirrors[Row][Col] = '\'
      ok     
         
   next
   
   //See nl+"Square..: "+nl   DisplaySquare( aMirrors)
   
   aSq = aMirrors
   
return


###==========================================
// Convert Linear number to Row-Col
// In a 5x5 , 14 = Row 3  Col 4
// Return [Row,Col]

Func NumberToRowCol(number)

   rowSize = len(aSq)          //  Global  aMirrors

   Row =  ceil( number / rowSize )
   Col =  number % rowSize
          if Col = 0   Col = rowSize  ok

return [Row,Col]

###==========================================
// Convert Row-Col to Linear number 
// In a 5x5 , Row-3 Col-4 => 14
// Return number

Func RowColToNumber( Row, Col)

   rowSize = len(aSq)
   number = ( rowSize * ( Row - 1) ) + Col

return number
    
###==========================================

###==========================================
// Convert 2D to 1D Array -- Only Empty squares 
// squareType = 'Empty', 'Occupied' or 'All'
// Return aList[]

Func SquaresToList(myMirrors, squareType)

   Rows = len(myMirrors)
   Cols = len(myMirrors[1])
   
   
   aList = [] 
   for i = 1 to Rows
      for j = 1 to Cols
      
         if squareType = 'Empty'
            if  myMirrors[i][j] = '0'
                squareNbr = RowColToNumber(i,j)
                Add( aList, squareNbr ) 
            ok
         ok
         
         if squareType = 'Occupied'
            if  myMirrors[i][j] != '0'
                squareNbr = RowColToNumber(i,j)
                Add( aList, squareNbr )
            ok
         ok
         
         if squareType = 'All'
             squareNbr = RowColToNumber(i,j)
             Add( aList, squareNbr )      
         ok
         
      next
   next  
   
return aList



//======================================================
// Random from a Linear List pick a Square number 
// Return Empty Square number to than can be Occupied
// Return 0 when List Size = 0  BAD

Func RandomSqr(myList)

   if len(myList) > 0
      pick = 0
      while pick = 0
          pick  = random(len(myList))        // Ring random uses Index 0   
      end    
      sqrNbr = myList[pick]              // Contents of square picked
   else
       return 0                           // List Size 0 ???
   ok

return  sqrNbr

//======================================================
