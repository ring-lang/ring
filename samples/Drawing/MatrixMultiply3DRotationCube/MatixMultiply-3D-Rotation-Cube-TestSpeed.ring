### Matrix Multiplication 3D Cube Rotation
### Bert Mariani  2020-10-30
###

Load "guilib.ring"
Load "stdlib.ring"

flag = 0
FlagShowSolution = 0     // 1=Show  0=NoShow
gSleepDelay      = 0.001

xPos    = 100
yPos    = 100
xWidth  = 600
yHeight = 600   ### Canvas position on Screen

counter = 0     ### Modulo 3 to change Pen Color

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorWhite  = new qcolor() { setrgb(255,255,255,048) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }  ### Yellow

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(2) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(2) }
penWhite    = new qpen() { setcolor(colorWhite)  setwidth(1) }
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }
penYellow   = new qpen() { setcolor(colorYellow) setwidth(2) }

brushS      = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlack)}    ### Black
brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty

###-----------------

myApp = new qApp 
{
    win = new qWidget()
    {
        setWindowTitle("Matrix Multiplication 3D Cube Rotation")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size


        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               translate(300,300)           ### TRANSLATE CO-ORD x,y -- 0,0 MAPS TO 300,300
               #endpaint()                  ### This will Stop the Painting

               ###-------------------------------
               ### Drw Yellow Rect in the Middle
                   #setBrush(brushS)             ### Brush - Solid, Yellow    
                   #setpen(penBlue)
                   #drawRect(indent, indent, xWidth - (2*indent), yHeight - (2*indent))    
            }

            setPixMap(MonaLisa)
        }

        btn = new qpushbutton(win)
        {
            setgeometry(20, 20, 100, 20)
            settext("DrawMatrix")
            setclickevent("DrawMatrix()") 
        }
    
        show()
    }
    exec()
}


###==========================================================================
###--------------------------------------------------------------------------
### 360=2PI Radians. 180=PI Radians 90=PI/2 Radians 45=PI/4 Radians  57.2958
###
#   B = [[ cos(R), -sin(R)],  // Rotation Matrix - 2D
#        [ sin(R),  cos(R)]] 
#
#
#  Rx = [[ 1    0        0    ],
#        [ 0  cos(R)  -sin(R) ],
#        [ 0  sin(R)   cos(R) ]]
#
#  Ry = [[  cos(R)  0  sin(R) ],
#        [    0     1    0    ],
#        [ -sin(R)  0  cos(R) ]]
#
#  Rz = [[  cos(R) -sin(R)  0 ],
#        [  sin(R)  cos(R)  0 ],
#        [   0        0     1 ]]
#
# XYZ = [[x],     Rz(90) [[1],     [cos90 -sin90  0]   [ 0 -1  0 ]   [0]
#        [y],             [0],  =  [sin90  cos90  0] = [ 1  0  0 ] = [1]
#        [z]]]            [0]]     [    0      0  1]   [ 0  0  1 ]   [0]
#
###------------------------------------------------------------------------

Func DrawMatrix()

   count = 0
   PI = 3.14159
             
   Points = [[ -100, -100, -100],        // TopRight  x,y,z Cube Shape
             [  100, -100, -100],        // TopLeft
             [  100,  100, -100],        // BottomLeft
             [ -100,  100, -100],        // BottomRight
             [ -100, -100,  100],
             [  100, -100,  100],
             [  100,  100,  100],
             [ -100,  100,  100]]          
                      
             
   Corners = [[  1, 1, 1 ],              // 3x8  x,y,z  Corner Points SAVE
              [  1, 1, 1 ],
              [  1, 1, 1 ],
              [  1, 1, 1 ],
              [  1, 1, 1 ],
              [  1, 1, 1 ],
              [  1, 1, 1 ],
              [  1, 1, 1 ]]        
       
   //--------------------------------------------
   // R = Radians, Rotate 360 degrees, 62 steps 
   
   C = [[ 1, 2, 3 ]]                    // 1x3   Result  
   
   for R = 0.0 to 2*PI  step 0.1
       t1 = Clock()  
       
      // Map the 8 Corners of the Cube Rotation
      for i = 1 to 8
                  
         A = [[ Points[i][1], Points[i][2], Points[i][3] ]]     // 1x3  x.y.z
                 
         X = [[ 1,     0 ,      0  ],          // Rx Rotation   // 3x3  => 1x3 => x.y.z
              [ 0, 0.5, -0.2 ],
              [ 0, 0.2,  0.5 ]]
/*
         
         X = [[ 1,     0 ,      0  ],          // Rx Rotation   // 3x3  => 1x3 => x.y.z
              [ 0, cos(R), -sin(R) ],
              [ 0, sin(R),  cos(R) ]]


         Y = [[  cos(R), 0, sin(R) ],          // Ry Rotation
              [      0 , 1,     0  ],
              [ -sin(R), 0, cos(R) ]]
           
         Z = [[ cos(R), -sin(R), 0 ],          // Rz Rotation         
              [ sin(R),  cos(R), 0 ],
              [     0 ,      0 , 1 ]]         
*/

         C = MatrixMultiply(A,X)               // 3D Rotation X,Y,Z
//         C = MatrixMultiply(C,Y)
//         C = MatrixMultiply(C,Z)
                    
         Corners[i][1] = C[1][1]               // SAVE Each Corner Point for xyz
         Corners[i][2] = C[1][2]
         Corners[i][3] = C[1][3]
         
      next            
   
      t2 = Clock()
      t3 = t2 - t1
      See "Count: " + count +" Time: "+ t3 +nl  count++      // DEBUG

      //DisplayMatrix(Corners)   
      //DoDraw(Corners)   // ===>>>
      
   next 

return

//----------------------------------------------------------
// Draw 8 Corner Points -- 12 Lines of New Position of Cube

Func DoDraw(C)

   MonaLisa.fill(colorBlack)     // Blank out Old Image
   
   daVinci.setpen(penWhite)
   daVinci.drawLine(    0, -200,    0,  200 )  ### Draw NEW Line
   daVinci.drawLine( -200,    0,  200,    0 )  
   daVinci.drawLine(  150, -150, -150,  150 )  
  
   // Draw the 12 Lines between the 8 Corners of the Cube

   daVinci.setpen(penRed)
   daVinci.drawLine( C[1][1], C[1][2], C[2][1], C[2][2] )  ### Draw NEW Line
   daVinci.drawLine( C[2][1], C[2][2], C[3][1], C[3][2] )  
   daVinci.drawLine( C[3][1], C[3][2], C[4][1], C[4][2] )  
   daVinci.drawLine( C[4][1], C[4][2], C[1][1], C[1][2] )  

   daVinci.setpen(penGreen)
   daVinci.drawLine( C[5][1], C[5][2], C[6][1], C[6][2] )  
   daVinci.drawLine( C[6][1], C[6][2], C[7][1], C[7][2] )  
   daVinci.drawLine( C[7][1], C[7][2], C[8][1], C[8][2] )  
   daVinci.drawLine( C[8][1], C[8][2], C[5][1], C[5][2] )  

   daVinci.setpen(penBlue)
   daVinci.drawLine( C[1][1], C[1][2], C[5][1], C[5][2] )  
   daVinci.drawLine( C[2][1], C[2][2], C[6][1], C[6][2] ) 
   
   daVinci.setpen(penYellow) 
   daVinci.drawLine( C[3][1], C[3][2], C[7][1], C[7][2] )  
   daVinci.drawLine( C[4][1], C[4][2], C[8][1], C[8][2] )  

   Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
   MyApp.ProcessEvents()               ### <<< EXEC the Draw
   //Sleep(gSleepDelay)

return

//-----------------------------------------------------------------
// Multiply  Array AxB  Horz-A MUST EQUAL vert-B  Ex A 3x4  B 4x5
// Use [[1,2,3]] for 1 Row matrix
// FlagShowSolution = 0     // 1=Show  0=NoShow

Func MatrixMultiply(A,B)      

   vertA = len(A)    horzA = len(A[1])
   vertB = len(B)    horzB = len(B[1])
   vertC = len(A)    horzC = len(B)
   C     = list(vertA, horzB)         // Make array bigV and bigH
      
   if horzA != vertB 
      See "Error: Matrix dimension: Horz-A:"+horzA +" MUST EQUAL vert-B:"+vertB +nl
      return 1
   ok
   
   
   for vA = 1 to vertA
      for hB = 1 to horzB

         Sum = 0
         for k = 1 to horzA             
            Sum += A[vA][k] * B[k][hB]    

            if FlagShowSolution = 1                  // 0 No Show, 1 = Show Solutio
                See " "+ A[vA][k] +"*"+ B[k][hB]
            ok          
         next
         
         if FlagShowSolution = 1  
             See " = "+ Sum  +"  C"+ vA + hB +nl
         ok
                
         C[va][hB] = Sum          
      
      next
   next

return C

//----------------------------
// Display Matrix

Func DisplayMatrix(M)

   if !IsList(M)
      return 1
   ok
   
   sizeV = len(M)
   sizeH = len(M[1])

   //See nl
   for V = 1 to sizeV
      See ""+V +":"
      for h = 1 to sizeH
         See " "+ M[v][h]
      next
      See nl
   next
return

//----------------------------


