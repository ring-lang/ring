### Mug Rotation using Matrix Multiplication 3D with Sliders
### Bert Mariani  2023-07-30
###
### Rotation, Size, Translate, Shear, Reflection, Speed, Increment Radians

Load "guilib.ring"
Load "stdlibcore.ring"
load "fastpro.ring"

//----------------------------------

flag = 0
gSleepDelay = 0.0       // 0.1

PI = 3.14159
NbrRotation = 8.2 * PI
IncRotation = 0.15         ### 0.1 Increment rotation by: in seconds

t1 = 2                    ### Time per Iteration
t2 = 3
t3 = 1

xPos    = 100
yPos    = 100
xWidth  = 1000
yHeight = 800             ### Canvas Position on Screen

###--------------

colorGreen   = new qcolor() { setrgb(000,255,000,255) }
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorWhite   = new qcolor() { setrgb(255,255,255,255) }  ### 064 faint line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,255) }  ### 

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(2) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(2) }
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(2) } // 1
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



//=============================================
//  Mug.txt 12890
//  27.937 8.027 13.927
//  28.403 8.933 14.851
//  27.550 8.500 15.673
// ....
//  30.188 12.352 -15.273
//  30.481 11.814 -14.139
// -49.211 101.800 -5.088
//

ShapeMug = list(12890,4)    // Rows-Cols

fp = fopen("mug.txt","r")

    for i=1 to 12890         
      vertex    = Readline(fp)
      vertArray = split(vertex, " ")
      
      ShapeMug[i][1] = Number(vertArray[1])
      ShapeMug[i][2] = Number(vertArray[2])
      ShapeMug[i][3] = Number(vertArray[3])
      ShapeMug[i][4] = 0    
    next
    
ShapeType =  "Mug"           
ShapeLen  =  len(ShapeMug)                  
Corners   =  ShapeMug        //  Size of Shape array of Mug

###======================================

myApp = new qApp 
{
    win = new qWidget()
    {

        oFilter = new qallevents(win)
        oFilter.setCloseEvent("MyApp.Quit()")
        installEventFilter(oFilter)


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
               #endpaint()                         ### This will Stop the Painting   
            }

            setPixMap(MonaLisa)
        }

        btn = new qPushButton(win) { setGeometry(0, 2, 80, 20)  setText("Draw")  setStyleSheet("background-color: yellow")
                                     setClickEvent("DrawMatrix()") 
                                   }

        comboShapeType = new QComboBox(win) 
        {
            setgeometry(80, 2, 70, 20)
            comboList = ["Mug"]
            for x in comboList additem(x,0) next                    
        }

  
      //-------------------------------------------------------------
      // ROTATION
      
         lRotation =  new qLabel(win)  { setgeometry( 0, 30 , 80, 20)  settext("ROTATON") setStyleSheet("background-color: yellow")}

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
      
         lScale   =  new qLabel(win)    { setgeometry( 0, 120 , 80, 20)  settext("SCALE") setStyleSheet("background-color: yellow")}

         lScaleX  =  new qLabel(win)    { setgeometry( 0, 140 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eScaleXV =  new qlineedit(win) { setgeometry(30, 140 , 30, 20)  settext("3.0") }          
         
         
         lScaleY  =  new qLabel(win)    { setgeometry( 0, 160 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eScaleYV =  new qlineedit(win) { setgeometry(30, 160 , 30, 20)  settext("3.0") }
            
         lScaleZ  =  new qLabel(win)    { setgeometry( 0, 180 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eScaleZV =  new qlineedit(win) { setgeometry(30, 180 , 30, 20)  settext("3.0") }             
                                                                                                       // Orig 50                     
         sScaleXV =  new qslider(win)   { setGeometry(60, 140 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("fScaleXV()") }      
         sScaleYV =  new qslider(win)   { setGeometry(60, 160 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("fScaleYV()") }      
         sScaleZV =  new qslider(win)   { setGeometry(60, 180 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("fScaleZV()") }      
        
      //-------------------------------------------------------------
      // TRANSLATE
      
         lTranslate =  new qLabel(win)    { setgeometry( 0, 210 , 80, 20)  settext("TRANSLATE") setStyleSheet("background-color: yellow")}

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
      
         lShear   =  new qLabel(win)    { setgeometry( 0, 300 , 80, 20)  settext("SHEAR") setStyleSheet("background-color: yellow")}

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
      
         lReflection =  new qLabel(win)    { setgeometry( 0, 390 , 80, 20)  settext("REFLECTION") setStyleSheet("background-color: yellow")}

         lReflX      =  new qLabel(win)    { setgeometry( 0, 410 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eReflXV     =  new qlineedit(win) { setgeometry(30, 410 , 30, 20)  settext("-1") }          
                  
         lReflY      =  new qLabel(win)    { setgeometry( 0, 430 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eReflYV     =  new qlineedit(win) { setgeometry(30, 430 , 30, 20)  settext("-1") }
            
         lReflZ      =  new qLabel(win)    { setgeometry( 0, 450 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eReflZV     =  new qlineedit(win) { setgeometry(30, 450 , 30, 20)  settext("-1") } 
                                                                                                          //  Orig 100     
         sReflXV     =  new qslider(win)   { setGeometry(60, 410 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(1)  setValueChangedEvent("fReflXV()") }      
         sReflYV     =  new qslider(win)   { setGeometry(60, 430 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(1)  setValueChangedEvent("fReflYV()") }      
         sReflZV     =  new qslider(win)   { setGeometry(60, 450 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(1)  setValueChangedEvent("fReflZV()") }      
  
      //-------------------------------------------------------------      
      // SPEED and INCREMENT
      
         lSpeed      =  new qLabel(win)    { setgeometry( 0, 480 , 80, 20)  settext("SPEED") setStyleSheet("background-color: yellow")}

         lSpeedX    =  new qLabel(win)    { setgeometry( 0, 500 , 30, 20)  settext("Delay:")  setStyleSheet("background-color: yellow")}
         eSpeedXV   =  new qlineedit(win) { setgeometry(30, 500 , 30, 20)  settext("0.00") }                           
         sSpeedXV   =  new qslider(win)   { setGeometry(60, 500 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(99)  setValueChangedEvent("fSpeedXV()") }      
          
         lIncrX     =  new qLabel(win)    { setgeometry( 0, 520 , 30, 20)  settext("Inc:")  setStyleSheet("background-color: yellow")}
         eIncrXV    =  new qlineedit(win) { setgeometry(30, 520 , 30, 20)  settext("0.10") }                           
         sIncrXV    =  new qslider(win)   { setGeometry(60, 520 , 90, 20)  setOrientation(Qt_Horizontal)  setValue(1)  setValueChangedEvent("fIncrXV()") }      
 
      //-------------------------------------------------------------      
      // TIMER per Cycle
      
         lTime     =  new qLabel(win)    { setgeometry( 0, 550 , 80, 20)  settext("TimeCycle:") setStyleSheet("background-color: yellow")}

         lTimeX    =  new qLabel(win)    { setgeometry( 0, 570 , 30, 20)  settext("MSec::")  setStyleSheet("background-color: yellow")}
         eTimeXV   =  new qlineedit(win) { setgeometry(30, 570 , 30, 20)  settext("0.00") }                           

         lCountX    =  new qLabel(win)    { setgeometry( 0, 590 , 30, 20)  settext("Count::")  setStyleSheet("background-color: yellow")}
         eCountXV   =  new qlineedit(win) { setgeometry(30, 590 , 30, 20)  settext("0") }                           


      //-----------------------------------------------------------


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



   startClock = clock()
   iteration  = 0
   count      = 0
   ShapeType  = comboShapeType.currentText()  
          
    
   //--------------------------------------------
   // R = Radians, Rotate 360 degrees, 62 steps   
   // for R = 0.0 to NbrRotation  step IncRotation    // 8.2*PI
   // Two Comple Rotations = 88PI
   
   Count = 0
   R=1
   while R <= NbrRotation     // 8Pi = 2 comple rotations
      t1 = Clock()
            
         //--------------------------------------------------
         // Transformation Matrices, with Angles and Offsets
            
        Rx = R * Number(eRotXV.text())  
        Ry = R * Number(eRotYV.text())  
        Rz = R * Number(eRotZV.text())               
         
         X = [[ 1,       0,        0, 0 ],    // Rx Rotation: 
              [ 0, cos(Rx), -sin(Rx), 0 ],    // Matrix * XYZ, 3x3*3x1 => 3x1
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


         Sx = Number(eScaleXV.text())  
         Sy = Number(eScaleYV.text())  
         Sz = Number(eScaleZV.text())
         
         S = [[ Sx,  0,  0, 0 ],     // Scale          
              [  0, Sy,  0, 0 ],
              [  0,  0, Sz, 0 ],
              [  0,  0,  0, 1 ]]

         
         Tx = Number(eTransXV.text())  
         Ty = Number(eTransYV.text())  
         Tz = Number(eTransZV.text())    
         
         T = [[ 1, 0, 0, Tx],        // Translate
              [ 0, 1, 0, Ty], 
              [ 0, 0, 1, Tz], 
              [ 0, 0, 0,  1]] 


         Hx = Number(eShearXV.text())  
         Hy = Number(eShearYV.text())  
         Hz = Number(eShearZV.text())
         
         H = [[  1,  Hx,  Hx,  0],    // Shear X-Y-Z
              [ Hy,   1,  Hy,  0], 
              [ Hz,  Hz,   1,  0], 
              [  0,   0,   0,  1]] 

         Fx = Number(eReflXV.text())  
         Fy = Number(eReflYV.text())  
         Fz = Number(eReflZV.text())         // Reflect -1,  NoRefect = 1
         
         F  = [[  Fx,   0,   0,  0],  // Reflection  X-Y-Z plane
               [   0,  Fy,   0,  0],
               [   0,   0,  Fz,  0],
               [   0,   0,   0,  1]]
               
            //----------------------------------------------------------
            // Do ALL the Transformation Matrix Multiplications at Once
            // Speeds up next section that Draws Each Point
        
           CY = MatrixMultiply(Y,X)    // Rotation Y:           
           CZ = MatrixMultiply(Z,CY)   // Rotation Z:
           CS = MatrixMultiply(S,CZ)   // Scale      -- make bigger/smaller size drawing
		   
         //CT = MatrixMultiply(T,CS)   // Translate  -- move drawing to different position
         //CH = MatrixMultiply(H,CT)   // Shear      -- distort drawing in X or Y or Z direction
         //FC = MatrixMultiply(F,CH)   // Reflection -- mirror image of drawing 
		 
		  FC = CS

            //------------------------------------------------------------------
            // Apply the Transformation Matrix  to Each New Point in Mug Array

                ###----------------------------------------------------------
                ### CALCULATOR Ring calls C-Calculator
                ### buildvc.bat = mylib.c   
                ### mylib.c     = myfunction -- RING_FUNC(ring_myfunction) 
                      
                RC  = ShapeMug           // Keep ShapeMug Array as is 12890x4 * 4x4 
				
	
 	        RC =  updateList(RC, :mul,:matrix, FC)	 // FastPro 
 			
    
      //------------------------------------
      // DRAW IMAGE and Time It   
   
      t2 = Clock()                    // Timing to clock speed
      t3 = t2 - t1
      eTimeXV.setText(""+ t3)         // TimeCycle: MSec:
      eCountXV.setText(""+ Count++)   // TimeCycle: Count:
    
     
      t11 = Clock()
	            
    DoDraw(RC) // ===>>> DRAW IMAGE in NEW POSITION  

     
      t12 = Clock()
      t13 = t12 - t11                 // Timing to clock speed
      
      R = R + IncRotation             // Rotation STEPS increased by:  While-Loop
      iteration++
	  See "Time: iter: "+ iteration +" "+ t3 +nl             // Inbetween Iteration
	
     // callGC() 	 // Call Garbage Collector - Faster
	
   end
   
   stopClock  = clock()
   elapseTime = stopClock - startClock  
   See "Completed Rotations: "+ elapseTime +" msec  iter: "+ iteration +nl
    
   win.setWindowTitle("Matrix Multiply 3D Cube Rotation: "+ elapseTime +" msec iter: "+ iteration  )
   
   

return

//=============================================================
//=============================================================
// Draw ALL the NEW POINTS of the IMAGE

Func DoDraw(C)      // Called by DoDraw(Corners) 

   ShapeType = comboShapeType.currentText()
    
   MonaLisa.fill(colorBlack)                      // Blank out Old Image
   
   daVinci.setpen(penWhite)
   daVinci.drawLine(    0, -400,    0,  400 )     //  Draw NEW Cartesian Lines X-Y-Z
   daVinci.drawLine( -400,    0,  400,    0 )  
   daVinci.drawLine(  300, -300, -300,  300 )  
  

   if ShapeType = "Mug"
      daVinci.setpen(penYellow) 
      for i = 1 to len(ShapeMug) -1
            daVinci.drawPoint( C[i][1], C[i][2])  // Dray X-Y Point
      next
   ok
   
   Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
   MyApp.ProcessEvents()               ### <<< EXEC the DRAW
   
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

Func MatrixPrint(U)

 See "      MatrixPrint:"
 Row = len(U)     See " "+ Row      // Rows 
 Col = len(U[1])  See "x"+ Col +nl  // Cols 
 
 See "[[ "
 for h = 1 to Row
   if h != 1
      See " [ "    // Line 2 etc
   ok  
   for v = 1 to Col
     Num = U[h][v]
     if (Num >= 0) See " " ok       // 2 places
     See Num 
	 
     if v != Col   See "," ok       // Comma between numbers
   next
   See " ]"
   
   if h != Row
    See ","+nl    // ],
   ok
 next
  See "] "+nl     // ]]
   
return

//=============================================

//----------------------------


