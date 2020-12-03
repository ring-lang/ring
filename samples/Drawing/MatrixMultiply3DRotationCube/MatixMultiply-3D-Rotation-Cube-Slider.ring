### Matrix Multiplication 3D Cube Rotation - Slider
### Bert Mariani  2020-10-30
###
### Rotation, Size, Translate, Shear, Reflection, Speed, Increment Radians

Load "guilib.ring"
Load "stdlib.ring"

flag = 0
gSleepDelay = 0.1
//eSpeedV.text() = 0.25

PI = 3.14159
NbrRotation = 8.2 * PI
IncRotation = 0.1       ### 0.1
//eIncrXV.text()  = 0.1 ### Increment rotation by:

t1 = 2    ### Time per Iteration
t2 = 3
t3 = 1

xPos    = 100
yPos    = 100
xWidth  = 800
yHeight = 800   ### Canvas position on Screen

  
###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorWhite  = new qcolor() { setrgb(255,255,255,064) }  ### 64 faint line
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
               translate(xWidth/2 +100, yHeight/2) ### TRANSLATE CO-ORD x,y -- 0,0 MAPS TO 300,300
               #endpaint()                    ### This will Stop the Painting   
            }

            setPixMap(MonaLisa)
        }

        btn = new qPushButton(win) { setGeometry(0, 2, 100, 20)  setText("DrawMatrix")  setStyleSheet("background-color: yellow")
                                     setClickEvent("DrawMatrix()") 
                                   }

  
      //-------------------------------------------------------------
      // ROTATION
      
         lRotation =  new qLabel(win)  { setgeometry( 0, 30 , 60, 20)  settext("ROTATON") setStyleSheet("background-color: yellow")}

         lRotX  =  new qLabel(win)     { setgeometry( 0, 50 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eRotXV =  new qlineedit(win)  { setgeometry(30, 50 , 30, 20)  settext("1.0") }           
               
         lRotY  =  new qLabel(win)     { setgeometry( 0, 70 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eRotYV =  new qlineedit(win)  { setgeometry(30, 70 , 30, 20)  settext("1.0") }
            
         lRotZ  =  new qLabel(win)     { setgeometry( 0, 90 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eRotZV =  new qlineedit(win)  { setgeometry(30, 90 , 30, 20)  settext("1.0") }           

         sRotXV =  new qslider(win)    { setGeometry(60, 50 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fRotXV()") }      
         sRotYV =  new qslider(win)    { setGeometry(60, 70 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fRotYV()") }      
         sRotZV =  new qslider(win)    { setGeometry(60, 90 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fRotZV()") }      
    
      //-------------------------------------------------------------
      // SCALE
      
         lScale   =  new qLabel(win)    { setgeometry( 0, 120 , 60, 20)  settext("SCALE") setStyleSheet("background-color: yellow")}

         lScaleX  =  new qLabel(win)    { setgeometry( 0, 140 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eScaleXV =  new qlineedit(win) { setgeometry(30, 140 , 30, 20)  settext("1.0") }          
         
         
         lScaleY  =  new qLabel(win)    { setgeometry( 0, 160 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eScaleYV =  new qlineedit(win) { setgeometry(30, 160 , 30, 20)  settext("1.0") }
            
         lScaleZ  =  new qLabel(win)    { setgeometry( 0, 180 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eScaleZV =  new qlineedit(win) { setgeometry(30, 180 , 30, 20)  settext("1.0") }             

         sScaleXV =  new qslider(win)   { setGeometry(60, 140 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fScaleXV()") }      
         sScaleYV =  new qslider(win)   { setGeometry(60, 160 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fScaleYV()") }      
         sScaleZV =  new qslider(win)   { setGeometry(60, 180 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fScaleZV()") }      
        
      //-------------------------------------------------------------
      // TRANSLATE
      
         lTranslate =  new qLabel(win)    { setgeometry( 0, 210 , 60, 20)  settext("TRANSLATE") setStyleSheet("background-color: yellow")}

         lTransX    =  new qLabel(win)    { setgeometry( 0, 230 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eTransXV   =  new qlineedit(win) { setgeometry(30, 230 , 30, 20)  settext("0.0") }          
               
         lTransY    =  new qLabel(win)    { setgeometry( 0, 250 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eTransYV   =  new qlineedit(win) { setgeometry(30, 250 , 30, 20)  settext("0.0") }
            
         lTransZ    =  new qLabel(win)    { setgeometry( 0, 270 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eTransZV   =  new qlineedit(win) { setgeometry(30, 270 , 30, 20)  settext("0.0") }             

         sTransXV   =  new qslider(win)   { setGeometry(60, 230 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fTransXV()") }      
         sTransYV   =  new qslider(win)   { setGeometry(60, 250 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fTransYV()") }      
         sTransZV   =  new qslider(win)   { setGeometry(60, 270 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fTransZV()") }      
   
   
      //-------------------------------------------------------------      
      // SHEAR
      
         lShear   =  new qLabel(win)    { setgeometry( 0, 300 , 60, 20)  settext("SHEAR") setStyleSheet("background-color: yellow")}

         lShearX  =  new qLabel(win)    { setgeometry( 0, 320 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eShearXV =  new qlineedit(win) { setgeometry(30, 320 , 30, 20)  settext("0.0") }          
               
         lShearY  =  new qLabel(win)    { setgeometry( 0, 340 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eShearYV =  new qlineedit(win) { setgeometry(30, 340 , 30, 20)  settext("0.0") }
            
         lShearZ  =  new qLabel(win)    { setgeometry( 0, 360 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eShearZV =  new qlineedit(win) { setgeometry(30, 360 , 30, 20)  settext("0.0") }             
 
         sShearXV =  new qslider(win)   { setGeometry(60, 320 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fShearXV()") }      
         sShearYV =  new qslider(win)   { setGeometry(60, 340 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fShearYV()") }      
         sShearZV =  new qslider(win)   { setGeometry(60, 360 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(50)  setValueChangedEvent("fShearZV()") }      
  
 
      //-------------------------------------------------------------      
      // REFLECTION
      
         lReflection =  new qLabel(win)    { setgeometry( 0, 390 , 60, 20)  settext("REFLECTION") setStyleSheet("background-color: yellow")}

         lReflX      =  new qLabel(win)    { setgeometry( 0, 410 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eReflXV     =  new qlineedit(win) { setgeometry(30, 410 , 30, 20)  settext("1") }          
                  
         lReflY      =  new qLabel(win)    { setgeometry( 0, 430 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eReflYV     =  new qlineedit(win) { setgeometry(30, 430 , 30, 20)  settext("1") }
            
         lReflZ      =  new qLabel(win)    { setgeometry( 0, 450 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eReflZV     =  new qlineedit(win) { setgeometry(30, 450 , 30, 20)  settext("1") } 

         sReflXV     =  new qslider(win)   { setGeometry(60, 410 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("fReflXV()") }      
         sReflYV     =  new qslider(win)   { setGeometry(60, 430 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("fReflYV()") }      
         sReflZV     =  new qslider(win)   { setGeometry(60, 450 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("fReflZV()") }      
  
      //-------------------------------------------------------------      
      // SPEED and INCREMENT
      
         lSpeed      =  new qLabel(win)    { setgeometry( 0, 480 , 60, 20)  settext("SPEED") setStyleSheet("background-color: yellow")}

         lSpeedX    =  new qLabel(win)    { setgeometry( 0, 500 , 30, 20)  settext("Delay:")  setStyleSheet("background-color: yellow")}
         eSpeedXV   =  new qlineedit(win) { setgeometry(30, 500 , 30, 20)  settext("0.00") }                           
         sSpeedXV   =  new qslider(win)   { setGeometry(60, 500 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(99)  setValueChangedEvent("fSpeedXV()") }      
          
         lIncrX     =  new qLabel(win)    { setgeometry( 0, 520 , 30, 20)  settext("Inc:")  setStyleSheet("background-color: yellow")}
         eIncrXV    =  new qlineedit(win) { setgeometry(30, 520 , 30, 20)  settext("0.01") }                           
         sIncrXV    =  new qslider(win)   { setGeometry(60, 520 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(1)  setValueChangedEvent("fIncrXV()") }      
 
      //-------------------------------------------------------------      
      // TIMER per Cycle
      
         lTime     =  new qLabel(win)    { setgeometry( 0, 550 , 60, 20)  settext("TimeCycle:") setStyleSheet("background-color: yellow")}

         lTimeX    =  new qLabel(win)    { setgeometry( 0, 570 , 30, 20)  settext("MSec::")  setStyleSheet("background-color: yellow")}
         eTimeXV   =  new qlineedit(win) { setgeometry(30, 570 , 30, 20)  settext("0.00") }                           

         lCountX    =  new qLabel(win)    { setgeometry( 0, 590 , 30, 20)  settext("Count::")  setStyleSheet("background-color: yellow")}
         eCountXV   =  new qlineedit(win) { setgeometry(30, 590 , 30, 20)  settext("0") }                           


         //-----------------------------------------------------------
  
        //--------------------
        show()
    }
    exec()
}


###==========================================================================
### Max 100/10 = 10  Min 10 / 10 = 1 

Func fScaleXV()   nbr = sScaleXV.value() / 50    eScaleXV.setText(""+nbr)   return       // 0.1 to 2.0
Func fScaleYV()   nbr = sScaleYV.value() / 50    eScaleYV.setText(""+nbr)   return 
Func fScaleZV()   nbr = sScaleZV.value() / 50    eScaleZV.setText(""+nbr)   return 

Func fRotXV()     nbr = sRotXV.value()   / 50    eRotXV.setText(""+nbr)     return       // 0.1 to 2.0
Func fRotYV()     nbr = sRotYV.value()   / 50    eRotYV.setText(""+nbr)     return 
Func fRotZV()     nbr = sRotZV.value()   / 50    eRotZV.setText(""+nbr)     return 

Func fTransXV()   nbr = sTransXV.value() * 2 -100    eTransXV.setText(""+nbr)   return   // -100 to +100
Func fTransYV()   nbr = sTransYV.value() * 2 -100    eTransYV.setText(""+nbr)   return 
Func fTransZV()   nbr = sTransZV.value() * 2 -100    eTransZV.setText(""+nbr)   return 

Func fShearXV()   nbr = sShearXV.value() / 50 -1   eShearXV.setText(""+nbr)   return     // -1 to +`1
Func fShearYV()   nbr = sShearYV.value() / 50 -1   eShearYV.setText(""+nbr)   return
Func fShearZV()   nbr = sShearZV.value() / 50 -1   eShearZV.setText(""+nbr)   return

Func fReflXV()    nbr = sReflXV.value()  / 50 -1  if nbr < 0 nbr = -1    else nbr = 1    ok   eReflXV.setText(""+nbr)   return        // -1 OR +1
Func fReflYV()    nbr = sReflYV.value()  / 50 -1  if nbr < 0 nbr = -1    else nbr = 1    ok   eReflYV.setText(""+nbr)   return
Func fReflZV()    nbr = sReflZV.value()  / 50 -1  if nbr < 0 nbr = -1    else nbr = 1    ok   eReflZV.setText(""+nbr)   return

Func fSpeedXV()   nbr = (100 - sSpeedXV.value()) / 200  if nbr <=0.01 nbr = 0.0 ok  eSpeedXV.setText(""+nbr)     return    ### Value 0.5 to 0.0

Func fIncrXV()    nbr = sIncrXV.value()  / 400      eIncrXV.setText(""+nbr)     return    ### 0.0 to 0.25



###==========================================================================
###--------------------------------------------------------------------------
### 360=2PI Radians. 180=PI Radians 90=PI/2 Radians 45=PI/4 Radians  57.2958
### For vertices use (x,y,z,1), which allows for scaling, rotation, and translation.
### For vectors use <dx,dy,dz,0>, which allows for scaling and rotation (but not translation).
#
#   B = [[ cos(R), -sin(R)],  // Rotation Matrix - 2D
#        [ sin(R),  cos(R)]] 
#
#
#  Rx = [[ 1    0        0     0],   [x]    [x']
#        [ 0  cos(R)  -sin(R)  0], * [y] =  [y']
#        [ 0  sin(R)   cos(R)  0],   [z]    [z']
#        [ 0    0        0     1]]   [1]    [1 ]
#
#  Ry = [[  cos(R)  0  sin(R)  0],   [x]    [x']
#        [    0     1    0     0], * [y] =  [y']
#        [ -sin(R)  0  cos(R)  0],   [z]    [z']
#        [   0        0     0  1]]   [1]    [1 ]  
#
#  Rz = [[  cos(R) -sin(R)  0  0],   [x]    [x']
#        [  sin(R)  cos(R)  0  0], * [y] =  [y']
#        [   0        0     1  0],   [z]    [z']
#        [   0        0     0  1]]   [1]    [1 ]
#
#
#  Scale  =  [   Sx   0    0   0],   [x]    [x']
#            [   0    Sy   0   0], * [y] =  [y']
#            [   0    0    Sz  0],   [z]    [z']
#            [   0    0    0   1]]   [1]    [1 ]
#        
#  Translate [   1    0    0  Tx],   [x]    [x']
#            [   0    1    0  Ty], * [y] =  [y']
#            [   0    0    1  Tz],   [z]    [z']
#            [   0    0    0   1]]   [1]    [1 ]      
#
#                     Xcol Ycol  Zcol
#  Direction 0        yz   xz   xy
#  Shear  =       [   1    Syx  Szx  0],   [x]    [x']
#                 [   Sxy  1    Szy  0], * [y] =  [y']
#                 [   Sxz  Syz  1    0],   [z]    [z']
#                 [   0    0    0    1]]   [1]    [1 ]
#
#
#                     Xcol Ycol Zcol
#  Plane -1           yz   xz   xy
#  Reflection  =  [  -x    0    0    0],   [x]    [x']
#                 [   0   -y    0    0], * [y] =  [y']
#                 [   0    0   -z    0],   [z]    [z']
#                 [   0    0    0    1]]   [1]    [1 ]

#
#  http://learnwebgl.brown37.net/transformations2/transformations_matrices.html
#  http://www.f-lohmueller.de/pov_tut/trans/trans_450e.htm
#  http://web.iitd.ac.in/~hegde/cad/lecture/L6_3dtrans.pdf
#  https://www.gatevidyalay.com/tag/3d-reflection-matrix/
#
###------------------------------------------------------------------------

Func DrawMatrix()

   count = 0

             
   Points = [[ -100, -100, -100],        // TopRight  x,y,z Cube Shape
             [  100, -100, -100],        // TopLeft
             [  100,  100, -100],        // BottomLeft
             [ -100,  100, -100],        // BottomRight      
             
             [ -100, -100,  100],
             [  100, -100,  100],
             [  100,  100,  100],
             [ -100,  100,  100]]          


   Triangle = [[ -100, -100, 000],
               [  100, -100, 000],
               [  000,  100, 000],
               [  000,  000, 100]]           
             
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
   // for R = 0.0 to NbrRotation  step IncRotation    // 8.2*PI
	
	Count = 0
	R = 0
   while R <= NbrRotation
		t1 = Clock()
	
      // Map the 8 Corners of the Cube Rotation
      for i = 1 to 8 //  Cube-8
                  
         A = [[ Points[i][1] ],               // X Y Z = 3x1  ==> Clockwise Rotation
              [ Points[i][2] ], 
              [ Points[i][3] ],
              [ 1 ]]              


         Rx = R * eRotXV.text()  Ry = R * eRotYV.text()  Rz = R * eRotZV.text()        // Multiple to speed up
         X = [[ 1,       0,        0, 0 ],    // Rx Rotation: Matrix * XYZ,  3x3 * 3x1 => 3x1
              [ 0, cos(Rx), -sin(Rx), 0 ],
              [ 0, sin(Rx),  cos(Rx), 0 ],
              [ 0,       0,        0, 1 ]]

         Y = [[  cos(Ry), 0, sin(Ry), 0 ],    // Ry Rotation
              [        0, 1,       0, 0 ],
              [ -sin(Ry), 0, cos(Ry), 0 ],
              [        0, 0,       0, 1 ]]
           
         Z = [[ cos(Rz), -sin(Rz), 0, 0 ],    // Rz Rotation         
              [ sin(Rz),  cos(Rz), 0, 0 ],
              [       0,        0, 1, 0 ],
              [       0,        0, 0, 1 ]]



         Sx = eScaleXV.text()  Sy = eScaleYV.text()  Sz = eScaleZV.text()
         S = [[ Sx,  0,  0, 0 ],             // Scale
              [  0, Sy,  0, 0 ],
              [  0,  0, Sz, 0 ],
              [  0,  0,  0, 1 ]]

         
         Tx = eTransXV.text()  Ty = eTransYV.text()  Tz = eTransZV.text()       
         T = [[ 1, 0, 0, Tx],               // Translate
              [ 0, 1, 0, Ty], 
              [ 0, 0, 1, Tz], 
              [ 0, 0, 0,  1]] 


         Hx = eShearXV.text()  Hy = eShearYV.text()  Hz = eShearZV.text()
         H = [[  1,  Hx,  Hx,  0],         // Shear XZ
              [ Hy,   1,  Hy,  0], 
              [ Hz,  Hz,   1,  0], 
              [  0,   0,   0,  1]] 

         Fx = eReflXV.text()  Fy = eReflYV.text()  Fz = eReflZV .text()      // Reflect -1,  NoRefect = 1
         F  = [[  Fx,   0,   0,  0],      // Reflection  x-plane
               [   0,  Fy,   0,  0],
               [   0,   0,  Fz,  0],
               [   0,   0,   0,  1]]

             
      
         C = MatrixMultiply(X,A)   // Rotation: 3D Matrix * XYZ , C = 3x1 output
         C = MatrixMultiply(Y,C)               
         C = MatrixMultiply(Z,C)
         C = MatrixMultiply(S,C)   // Scale
         C = MatrixMultiply(T,C)   // Translate
         C = MatrixMultiply(H,C)   // Shear
         C = MatrixMultiply(F,C)   // Reflection                    
                      
	 callgc()
	
         Corners[i][1] = C[1][1]               // Save Each Corner Point for xyz
         Corners[i][2] = C[2][1]
         Corners[i][3] = C[3][1]
         
      next            
   
		t2 = Clock()
      t3 = t2 - t1
		eTimeXV.setText(""+ t3)
		eCountXV.setText(""+ Count++)
      
      See "Time for Iteration: "+ Count +" msec: "+ t3 +nl
		
      // DisplayMatrix(Corners)   // Debug for coordinate numbers 
		
       DoDraw(Corners)           // ===>>>   Comment Out --- stops at 258 iterations -- Stack ???
      
		R = R + IncRotation       // Rotation Steps increase by:  WhileLoop
	
   ? " R : " + R
	 ? " NbrRotation : " + NbrRotation

	end

? "out of the loop"
   ? " R : " + R
	 ? " NbrRotation : " + NbrRotation


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
   
   Sleep(eSpeedXV.text())              ### Slider Sleep 
   IncRotation = eIncrXV.text()        ### Increment rotation by:
   

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
         next
             
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


