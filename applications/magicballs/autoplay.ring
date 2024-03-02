// Name:   Magic Balls Automated - Random Player
// Author: Bert Mariani
// Date:   2020-03-01
//
// Test Random - List Picker - Shorten List after pick
//
// Func NumberToRowCol(number)            Return [Row,Col]
// Func RowColToNumber( Row, Col)         Return number
// Func BallsToList(myBalls, squareType)  Return aList[]  'Empty', 'Occupied' or 'All'
// Func RandomSqr(myList)                 Return SqrNbr
// Func RandomBallColor()                 Return color
// Func DisplayLinear(myList)             Return -
// Func DisplaySquare(mySquare)           Return -
// Func CheckLineOfColors(mySquare)       Return -
// Func EraseRowOfColors(Row,Col)         Return -
// Func EraseColOfColors(Row,Col)         Return -
// Func EraseDiagDownOfColors(Row,Col)    Return -
// Func EraseDiagUpOfColors(Row,Col)      Return -
// Func MapBallsToButtons(myBalls)        Return -
// Func UserMove(RandomSqr(myBalls)       Return -


load "lightguilib.ring"
load "solveArrayPathDest.ring"

//-------------------------------------------------------
// RANDOM SEED -- based on Seconds from start of day

   myClock    =  TimeList()
   nowSeconds = (myClock[7] * 3600) + (myClock[11] * 60) + myClock[13]
   mySeed     =  srandom(nowSeconds)    

// 2D Ball Array


aBalls = [[ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ],
          [ 0,0,0,0,0,0,0,0,0 ]]

aBallsX = [[ 0,0,0,0,0],
          [ 0,0,0,0,0],
          [ 0,0,0,0,0],
          [ 0,0,0,0,0],
          [ 0,0,0,0,0]]

          
inLineCount = 3
Size        = len(aBalls)

###------------------------------------------------
 

###=================================================

moveX = 400  moveY = 100
sizeX = 800  SizeY = 800
        
oPicColor = new QPixmap("images\red.png")
bWidth    = sizeX / Size                    // oPicColor.width()    ### 80 
bHeight   = sizeY / Size                    // oPicColor.height()   ### 80 

C_Spacing = 1
C_ButtonEmptyStyle  = ' border-radius: 2px; border-width: 2px; border-style: outset; '


Button          = list(Size,Size)
LayoutButtonRow = list(Size)

ballColors = [ "images/red.png",
               "images/yellow.png",
               "images/orange.png",
               "images/green.png", 
               "images/blue.png"          
             ]

emptyColor = "images/empty.png"

RandomColorCount = [0,0,0,0,0]    // How many of each color generated
ScoreColorCount  = [0,0,0,0,0]    // How many of each color in a row,col,diag detected

###=====================================================

###=====================================================

app = new qApp 
{
    win = new qWidget() 
    {
	setWinIcon(win,"images\red.png")
        setWindowTitle('Magic Balls: ')

        move(moveX, moveY)
        reSize(sizeX, sizeY)
        winheight = win.height()
        fontSize = 8 + (winheight / 100)

        ##------------------------------------------------------------------------------
        ### QVBoxLayout lays out Button Widgets in a vertical column, from top to bottom.
        
        LayoutButtonMain = new QVBoxLayout()            ### VERTICAL
        LayoutButtonMain.setSpacing(C_Spacing)
        LayoutButtonMain.setContentsmargins(0,0,0,0)
     
            ###-----------------------------------------------------------------------
            ### QHBoxLayout lays out widgets in a horizontal row, from left to right
                
            for Row = 1 to Size
                LayoutButtonRow[Row] = new QHBoxLayout()    ### Horizontal
                {
                    setSpacing(C_Spacing)
                    setContentsMargins(0,0,0,0)
                } 
          
               for Col = 1 to Size
                    Button[Row][Col] = new QPushButton(win) ### Create PUSH BUTTONS
                    {
                        setStyleSheet(C_ButtonEmptyStyle)
                        setClickEvent("PLAY(" + string(Row) + "," + string(Col) + ")")   ### CLICK PLAY MOVE >>> pPlay
                        setSizePolicy(1,1)
                    }
                    
                    LayoutButtonRow[Row].AddWidget(Button[Row][Col])    ### Widget - Add HORIZONTAL BUTTON
               next
               
               LayoutButtonMain.AddLayout(LayoutButtonRow[Row])         ### Layout - Add ROW of Buttons
            next

            ###------------------------------------------------              

            setLayout(LayoutButtonMain)
            
            ###---------------------------------------------
            
            show()
            
   }
   exec()
 }

    
###=================================================
       
//----------------------------------------------
// Main

Func PLAY(Row,Col)   

   //----------------------------------
   // Used for testing
/* 
   See "Clicked: "+Row +"-"+ Col +nl
   aBalls[Row][Col] = 1
       
   See "Square..: "+nl   DisplaySquare( aBalls)

   See nl+ "Empty...: "  DisplayLinear( BallsToList(aBalls, 'Empty' ) )
   See nl+ "Occupied: "  DisplayLinear( BallsToList(aBalls, 'Occupied' ) )
   See nl+ "ALL.....: "  DisplayLinear( BallsToList(aBalls, 'All') )        
   See nl+nl+nl
*/
   
   //------------------------------------
   // Automation
   
for test = 1 to 200     

      // Linear lists
      aEmpty  = BallsToList(aBalls, 'Empty' )
                //See nl+"Echo: " DisplayLinear( aEmpty )
      
      // Pick random Empty square number
      sqrNbr  = RandomSqr( aEmpty)
                if sqrNbr = 0   See nl+"No Random Square Left"  return  ok
      
      // Number of square to row-col
      aRowCol = NumberToRowCol(sqrNbr) 
                Row = aRowCol[1]
                Col = aRowCol[2]
                //See nl+nl+" Random: RC: "+ Row +"-"+ Col 
                
      // Pick random color           
      color   = RandomBallColor()
                //See " Random Color..: "+ color
      
      // Set Square value to color number 1..5
      aBalls[Row][Col] = color      
                //See nl+"Square..: "+nl   DisplaySquare( aBalls)  
            
      // Check if 5 in a row.col.diag     
      CheckLineOfColors(aBalls)   // Clear Line of Balls
      
      // User move source to destination
      UserMove(aBalls)

      // Image of Balls to Button Display
      MapBallsToButtons(aBalls)   // Draw Balls on Buttons
      
      
      // Display the Board
      Total = ScoreColorCount[1] + ScoreColorCount[2] + ScoreColorCount[3] + ScoreColorCount[4]
      
      win.setWindowTitle("Magic Balls: InLine: "+ inLineCount +"   Colors: R: "+ RandomColorCount[1]+" Y: "+ RandomColorCount[2]+" O: "+ RandomColorCount[3]+" G: "+ RandomColorCount[4]+" B: "+ RandomColorCount[5] +" "+
                                     "   Scores: Row: "+ ScoreColorCount[1]+" Col: "+  ScoreColorCount[2]+" DiagD: "+  ScoreColorCount[3]+" DiagU: "+  ScoreColorCount[4]+" Total: "+ Total   
                        ) 
      
      app.processEvents()   // Update Button Display
      Sleep(0.2)            // Slow down
      
      //---------------------------------------------

next

   See nl+"DONE"+nl
   
return 

###==========================================
// Convert Linear number to Row-Col
// In a 5x5 , 14 = Row 3  Col 4
// Return [Row,Col]

Func NumberToRowCol(number)

   rowSize = len(aBalls)          //  Global  aBalls

   Row =  ceil( number / rowSize )
   Col =  number % rowSize
          if Col = 0   Col = rowSize  ok

return [Row,Col]

###==========================================
// Convert Row-Col to Linear number 
// In a 5x5 , Row-3 Col-4 => 14
// Return number

Func RowColToNumber( Row, Col)

   rowSize = len(aBalls)
   number = ( rowSize * ( Row - 1) ) + Col

return number
    
###==========================================
// Convert 2D 1D Array -- Only Empty squares 
// squareType = 'Empty', 'Occupied' or 'All'
// Return aList[]

Func BallsToList(myBalls, squareType)

   Rows = len(myBalls)
   Cols = len(myBalls[1])
   
   aList = [] 
   for i = 1 to Rows
      for j = 1 to Cols
      
         if squareType = 'Empty'
            if  myBalls[i][j] = 0
                squareNbr = RowColToNumber(i,j)
                Add( aList, squareNbr ) 
            ok
         ok
         
         if squareType = 'Occupied'
            if  myBalls[i][j] > 0
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



//----------------------------------------------------
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

//---------------------------------------------------
// RandomBall pick a Ball Color 1..5

Func RandomBallColor()

   color = 0
   while color = 0
      color  = random(5)                  // Generates 0..5, Loop need 1..5   
   end

   RandomColorCount[color]++
return  color

//==============================
// Display a Linear Array List

Func DisplayLinear(myList)
    
    for i = 1 to len(myList)            
        See " "+ myList[i]
    next
    
return

//----------------------------
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

//=================================
// Test Balls in a Row, Col, Diag
// Erase [Row][Col] of Match to 0

Func CheckLineOfColors(mySquare)

   inLine   = inLineCount -1      // For 3 use 2 ( 5-2=3 )
   colorNbr = 1                   // 1..5
   
   Rows = len(mySquare)
   Cols = len(mySquare[1])
   
   //----------------------------------------
   //ROWS  inPlace->Right  >123  234  345<
   
   for i = 1 to Rows
      for j = 1 to Cols - inLine            
         
         count    = 1
         colorNbr = mySquare[i][j]             // Color to test
         
         for k = 1 to inLine
               if mySquare[i][j+k] = colorNbr  // Col right
                  count++
               ok 
         next
         
         if count = inLineCount AND  colorNbr != 0
            See "RowOfColors: RC: "+ i +"-"+ j + " Color: "+ colorNbr +nl
            EraseRowOfColors(i,j)
         ok
               
      next
   next
   
   //----------------------
   // COLS  Down->InPlace
   
   for i = 1 to Rows - inLine
      for j = 1 to Cols
         
         count    = 1
         colorNbr = mySquare[i][j]             // Color to test
         
         for k = 1 to inLine
               if mySquare[i+k][j] = colorNbr  // Row down
                  count++
               ok 
         next
         
         if count = inLineCount AND  colorNbr != 0
            See "ColOfColors: RC: "+ i +"-"+ j + " Color: "+ colorNbr +nl
            EraseColOfColors(i,j)
         ok
               
      next
   next
   
   //------------------------
   // DIAG Down \ Right-Down
   
   for i = 1 to Rows - inLine 
      for j = 1 to Cols - inLine                                 
         
         count    = 1
         colorNbr = mySquare[i][j]               // Color to test
         
         for k = 1 to inLine                     
               if mySquare[i+k][j+k] = colorNbr  // Row down, Col right
                  count++
               ok 
         next
         
         if count = inLineCount AND  colorNbr != 0
            See "Diag-DN-Col: RC: "+ i +"-"+ j + " Color: "+ colorNbr +nl
            EraseDiagDownOfColors(i,j)
         ok
               
      next
   next
   
   //----------------------
   // DIAG UP / Right-Up
   
   for i = Rows to inLine+1  step -1               // Row from bottom to top
      for j = 1 to Cols - inLine                                
         
         count    = 1
         colorNbr = mySquare[i][j]                  // Color to test
         
         for k = 1 to inLine                        
                  if mySquare[i-k][j+k] = colorNbr  // Row up, Col right
                  count++
               ok 
         next
         
         if count = inLineCount AND  colorNbr != 0
            See "Diag-Up-Col: RC: "+ i +"-"+ j + " Color: "+ colorNbr +nl
            EraseDiagUpOfColors(i,j)
         ok
               
      next
   next
   
   //----------------------

return 

###=================================
// Erase a Row in lone of Colors
// In aBalls array square

Func EraseRowOfColors(Row,Col)

   k = 0
   for i = 1 to inLineCount   
      aBalls[Row][Col +k] = 0
      k++
   next
   
   ScoreColorCount[1]++

return

//------------------------------------
// COLS

Func EraseColOfColors(Row,Col)

   k = 0
   for i = 1 to inLineCount   
      aBalls[Row +k][Col] = 0
      k++
   next

   ScoreColorCount[2]++
   
return

//------------------------------------
// DIAG \ LR Down-Right

Func EraseDiagDownOfColors(Row,Col)

   k = 0
   for i = 1 to inLineCount   
      aBalls[Row +k][Col +k] = 0
      k++
   next

   ScoreColorCount[3]++
   
return

//------------------------------------
// DIAG / RL Up-Right
Func EraseDiagUpOfColors(Row,Col)

   k = 0
   for i = 1 to inLineCount   
      aBalls[Row -k][Col +k] = 0
      k++
   next

   ScoreColorCount[4]++
   
return

//======================================

//--------------------------------------------------
// May image of aBalls value 1..5 to Button Display

Func MapBallsToButtons(myBalls)

   Rows = len(myBalls)
   Cols = len(myBalls[1])
   
      for Row = 1 to Rows
         for Col = 1 to Cols
         
            if myBalls[Row][Col] > 0
                        Button[Row][Col] { 
                           setIcon(new qIcon( new qPixMap( ballColors[ aBalls[Row][Col] ]) ) )  
                           setIconSize(new qSize( bWidth, bHeight)) 
                        }  
            else
                        Button[Row][Col] { 
                           setIcon(new qIcon(new qPixMap(emptyColor) ) )  
                           setIconSize(new qSize( bWidth, bHeight)) 
                        }  
            ok
                        
         next
      next
return

//--------------------------------------
// Random move a Ball to Empty square

Func UserMove(myBalls)

   Rows = len(myBalls)
   Cols = len(myBalls[1])

   // squareType = 'Empty', 'Occupied' or 'All' // Return aList[]

   emptyList      = BallsToList(myBalls, 'Empty')
   occupiedList   = BallsToList(myBalls, 'Occupied')
   
   emptySqrNbr    = RandomSqr(emptyList)
   occupiedSqrNbr = RandomSqr(occupiedList)
   
   if emptySqrNbr = 0  OR  occupiedSqrNbr = 0
      return        // List was Not > 0
   ok
   
   aEmptyRC       = NumberToRowCol(emptySqrNbr)
   aOccupiedRC    = NumberToRowCol(occupiedSqrNbr)
   
   x = aOccupiedRC[1]  y = aOccupiedRC[2]
   s = aEmptyRC[1]     t = aEmptyRC[2]
   
   // Convert myBalls to 0/1 before calling pathSrcDest
   
   myBalls01 = myBalls
   for i = 1 to Rows
      for j = 1 to Cols
         if myBalls[i][j] > 0
               myBalls01[i][j] = 1
         else
               myBalls01[i][j] = 0
         ok
      next
   next
   
   //See "Call.. Ball: "+ x +"-"+ y +" "+ s +"-"+ t +nl  
   pathTF = pathSrcDest( myBalls01, x,y,s,t)
   
   // Move Ball to Empty square if path is true
   color = myBalls[x][y]
   if pathTF = True  
      myBalls[s][t] = color
      myBalls[x][y] = 0
      
      //See "Moved.. Ball: "+ color +" "+ x +"-"+ y +" "+ s +"-"+ t +nl 
   else
      //See "Blocked Ball: "+ color +" "+ x +"-"+ y +" "+ s +"-"+ t +nl
   ok
   

return

//---------------------------------------
