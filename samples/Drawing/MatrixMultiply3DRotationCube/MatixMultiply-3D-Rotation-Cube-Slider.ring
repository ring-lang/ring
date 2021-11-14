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

colorGreen   = new qcolor() { setrgb(000,255,000,255) }
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ### 64 faint line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,255) }  ### 

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(2) }
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

ShapeCube = [[ -100, -100, -100],        // TopRight  x,y,z Cube Shape
             [  100, -100, -100],        // TopLeft
             [  100,  100, -100],        // BottomLeft
             [ -100,  100, -100],        // BottomRight      
             
             [ -100, -100,  100],
             [  100, -100,  100],
             [  100,  100,  100],
             [ -100,  100,  100]]          


ShapeTriangle =  [[ -100, -100, 000],
                  [  100, -100, 000],
                  [  000,  100, 000],
                  [  000,  000, 100]] 

ShapePI = [
[  106,   25, 100, 0],
[  106,   50, 100, 0],
[  106,   75, 100, 0],
[  109,  100, 100, 0],
[  117,  125, 100, 0],
[  125,  134, 100, 0],
[  150,  144, 100, 0],
[  175,  141, 100, 0],
[  197,  125, 100, 0],
[  200,  123, 100, 0],
[  209,  100, 100, 0],
[  210,   88, 100, 0],
[  227,   88, 100, 0],
[  226,  100, 100, 0],
[  221,  125, 100, 0],
[  213,  150, 100, 0],
[  201,  175, 100, 0],
[  179,  200, 100, 0],
[  175,  203, 100, 0],
[  150,  214, 100, 0],
[  125,  218, 100, 0],
[  100,  215, 100, 0],
[   75,  205, 100, 0],
[   66,  200, 100, 0],
[   49,  185, 100, 0],
[   43,  175, 100, 0],
[   37,  150, 100, 0],
[   37,  125, 100, 0],
[   37,  100, 100, 0],
[   38,   75, 100, 0],
[   40,   50, 100, 0],
[   42,   25, 100, 0],
[   44,    0, 100, 0],
[   47,  -25, 100, 0],
[   49,  -50, 100, 0],
[   51,  -75, 100, 0],
[   53, -100, 100, 0],
[   55, -125, 100, 0],
[   58, -150, 100, 0],
[   50, -150, 100, 0],
[   25, -150, 100, 0],
[    0, -150, 100, 0],
[  -25, -150, 100, 0],
[  -45, -150, 100, 0],
[  -47, -125, 100, 0],
[  -49, -100, 100, 0],
[  -51,  -75, 100, 0],
[  -54,  -50, 100, 0],
[  -57,  -25, 100, 0],
[  -60,    0, 100, 0],
[  -62,   25, 100, 0],
[  -65,   50, 100, 0],
[  -67,   75, 100, 0],
[  -70,  100, 100, 0],
[  -73,  125, 100, 0],
[  -77,  150, 100, 0],
[  -85,  175, 100, 0],
[ -100,   202, 100, 0],
[ -125,   220, 100, 0],
[ -150,   220, 100, 0],
[ -175,   205, 100, 0],
[ -178,   200, 100, 0],
[ -189,   175, 100, 0],
[ -186,   150, 100, 0],
[ -170,   125, 100, 0],
[ -152,   100, 100, 0],
[ -136,    75, 100, 0],
[ -122,    50, 100, 0],
[ -113,    25, 100, 0],
[ -105,     0, 100, 0],
[ -100,   -25, 100, 0],
[  -95,   -50, 100, 0],
[  -92,   -75, 100, 0],
[  -89,  -100, 100, 0],
[  -87,  -125, 100, 0],
[  -87,  -150, 100, 0],
[ -100,  -150, 100, 0],
[ -125,  -150, 100, 0],
[ -150,  -145, 100, 0],
[ -175,  -132, 100, 0],
[ -182,  -125, 100, 0],
[ -200,  -100, 100, 0],
[ -209,   -85, 100, 0],
[ -225,   -85, 100, 0],
[ -220,  -100, 100, 0],
[ -211,  -125, 100, 0],
[ -203,  -150, 100, 0],
[ -190,  -175, 100, 0],
[ -175,  -190, 100, 0],
[ -158,  -200, 100, 0],
[ -150,  -203, 100, 0],
[ -125,  -209, 100, 0],
[ -100,  -212, 100, 0],
[  -75,  -215, 100, 0],
[  -50,  -217, 100, 0],
[  -25,  -219, 100, 0],
[    0,  -219, 100, 0],
[   25,  -220, 100, 0],
[   50,  -220, 100, 0],
[   75,  -220, 100, 0],
[  100,  -220, 100, 0],
[  125,  -220, 100, 0],
[  150,  -220, 100, 0],
[  175,  -220, 100, 0],
[  200,  -220, 100, 0],
[  225,  -220, 100, 0],
[  225,  -200, 100, 0],
[  225,  -175, 100, 0],
[  225,  -150, 100, 0],
[  200,  -150, 100, 0],
[  175,  -150, 100, 0],
[  150,  -150, 100, 0],
[  125,  -150, 100, 0],
[  117,  -150, 100, 0],
[  116,  -125, 100, 0],
[  115,  -100, 100, 0],
[  113,   -75, 100, 0],
[  112,   -50, 100, 0],
[  110,   -25, 100, 0],
[  108,     0, 100, 0],
[  106,    25, 100, 0]]
           
ShapeType =  "ShapeCube"			  
ShapeLen  =  len(ShapePI)					
Corners   =  ShapePI        //  Biggest Shape, Use for Cube and Triangle

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

        comboShapeType = new QComboBox(win) 
        {
            setgeometry(110, 2, 100, 20)
            comboList = ["ShapeCube","ShapeSolid","ShapeTriangle","ShapeSolidTriangle","ShapePI"]
            for x in comboList additem(x,0) next         			
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
   ShapeType = comboShapeType.currentText()  
  
//    if   ShapeType  = "ShapeCube"      ShapeLen = len(ShapeCube)          
//    but  ShapeType  = "ShapeSolid"     ShapeLen = len(ShapeCube)    
//    but  ShapeType  = "ShapePI"        ShapeLen = len(ShapePI)     
//    but  ShapeType  = "ShapeTriangle"  ShapeLen = len(ShapeTriangle) 
//    ok
             
    
   //--------------------------------------------
   // R = Radians, Rotate 360 degrees, 62 steps   
   // for R = 0.0 to NbrRotation  step IncRotation    // 8.2*PI
   
   Count = 0
   R = 0
   while R <= NbrRotation
      t1 = Clock()
   
      
     for i = 1 to ShapeLen
         
         if ShapeType = "ShapeCube" || ShapeType = "ShapeSolid"
			   ShapeLen = len(ShapeCube)               // USER changes on the fly.
          
            A = [[ ShapeCube[i][1] ],               // X Y Z = 4x1  ==> Clockwise Rotation
                 [ ShapeCube[i][2] ], 
                 [ ShapeCube[i][3] ],
                 [              1  ]]   
         ok
       
                 
         if ShapeType = "ShapePI"
			   ShapeLen = len(ShapePI)

           A = [[ ShapePI[i][1] ],             
                [ ShapePI[i][2] ], 
                [ ShapePI[i][3] ],
                [            1  ]]         
         ok

         if ShapeType = "ShapeTriangle" || ShapeType = "ShapeSolidTriangle"
			   ShapeLen = len(ShapeTriangle)

           A = [[ ShapeTriangle[i][1] ],             
                [ ShapeTriangle[i][2] ], 
                [ ShapeTriangle[i][3] ],
                [                  1  ]]         
         ok

         //-------------------------------
			
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

         CallGC()                  // FIX SPEED SLOWING DOWN         
                      
         Corners[i][1] = C[1][1]               // Save Each Corner Point for xyz
         Corners[i][2] = C[2][1]
         Corners[i][3] = C[3][1]
         
      next            
   
      t2 = Clock()
      t3 = t2 - t1
      eTimeXV.setText(""+ t3)
      eCountXV.setText(""+ Count++)
      
      // See "Time for Iteration: "+ Count +" msec: "+ t3 +nl
      // DisplayMatrix(Corners)   // Debug for coordinate numbers 
      
      t11 = Clock()
      DoDraw(Corners)           // ===>>>   Comment Out --- stops at 258 iterations -- Stack ???
      
      t12 = Clock()
      t13 = t12 - t11
      //See "Time for Iteration: "+ Count +" msec: "+ t3  +" DrawTime: "+ t13  +nl
      
      R = R + IncRotation       // Rotation Steps increase by:  WhileLoop
		
		
      
   end
   
return

//----------------------------------------------------------
// Draw 8 Corner Points -- 12 Lines of New Position of Cube

Func DoDraw(C)

   ShapeType = comboShapeType.currentText()
	
   MonaLisa.fill(colorBlack)     // Blank out Old Image
   
   daVinci.setpen(penWhite)
   daVinci.drawLine(    0, -200,    0,  200 )  ### Draw NEW Line
   daVinci.drawLine( -200,    0,  200,    0 )  
   daVinci.drawLine(  150, -150, -150,  150 )  
  
   // Draw the 12 Lines between the 8 Corners of the Cube


   if ShapeType = "ShapeCube"
      daVinci.setpen(penRed)
      daVinci.drawLine( C[1][1], C[1][2], C[2][1], C[2][2] )  ### 1 2 > Draw NEW Line
      daVinci.drawLine( C[2][1], C[2][2], C[3][1], C[3][2] )  #   2 3
      daVinci.drawLine( C[3][1], C[3][2], C[4][1], C[4][2] )  #   3 4 >
      daVinci.drawLine( C[4][1], C[4][2], C[1][1], C[1][2] )  #   4 1


      daVinci.setpen(penGreen)
      daVinci.drawLine( C[5][1], C[5][2], C[6][1], C[6][2] )  #   5 6 >
      daVinci.drawLine( C[6][1], C[6][2], C[7][1], C[7][2] )  #   6 7
      daVinci.drawLine( C[7][1], C[7][2], C[8][1], C[8][2] )  #   7 8 >
      daVinci.drawLine( C[8][1], C[8][2], C[5][1], C[5][2] )  #   8 1

      daVinci.setpen(penBlue)
      daVinci.drawLine( C[1][1], C[1][2], C[5][1], C[5][2] )  
      daVinci.drawLine( C[2][1], C[2][2], C[6][1], C[6][2] ) 
     
      daVinci.setpen(penYellow) 
      daVinci.drawLine( C[3][1], C[3][2], C[7][1], C[7][2] )  
      daVinci.drawLine( C[4][1], C[4][2], C[8][1], C[8][2] )  
   ok
   

  
   if ShapeType = "ShapeSolid"
      daVinci.setBrush(brushSY)
      daVinci.drawPolygon( [ [C[5][1], C[5][2]], [C[8][1], C[8][2]], [C[4][1], C[4][2]], [C[1][1], C[1][2]] ], 0)  // Yellow 14 85

      daVinci.setBrush(brushSR)
      daVinci.drawPolygon( [ [C[1][1], C[1][2]], [C[4][1], C[4][2]], [C[3][1], C[3][2]], [C[2][1], C[2][2]] ], 0)  // Red   12 34
    
      daVinci.setBrush(brushSM)
      daVinci.drawPolygon( [ [C[2][1], C[2][2]], [C[3][1], C[3][2]], [C[7][1], C[7][2]], [C[6][1], C[6][2]] ], 0)  // Cyan 23 76

      daVinci.setBrush(brushSG)
      daVinci.drawPolygon( [ [C[6][1], C[6][2]], [C[7][1], C[7][2]], [C[8][1], C[8][2]], [C[5][1], C[5][2]] ], 0)  // Green 56 79
      
      
      daVinci.setBrush(brushSB)
      daVinci.drawPolygon( [ [C[1][1], C[1][2]], [C[2][1], C[2][2]], [C[6][1], C[6][2]], [C[5][1], C[5][2]] ], 0)  // Blue  12 65
      
      daVinci.setBrush(brushSGR)
      daVinci.drawPolygon( [ [C[3][1], C[3][2]], [C[4][1], C[4][2]], [C[8][1], C[8][2]], [C[7][1], C[7][2]] ], 0)  // Gray  34 87

   ok
 
   if ShapeType = "ShapeTriangle"
      daVinci.setpen(penRed)
      daVinci.drawLine( C[1][1], C[1][2], C[2][1], C[2][2] )  ### 1 2 > Draw NEW Line
      daVinci.drawLine( C[1][1], C[1][2], C[3][1], C[3][2] )  #   5 6 >
      daVinci.drawLine( C[1][1], C[1][2], C[4][1], C[4][2] )  #   5 6 >
      
      daVinci.setpen(penGreen)
      daVinci.drawLine( C[2][1], C[2][2], C[3][1], C[3][2] )  #   2 3
      daVinci.drawLine( C[2][1], C[2][2], C[4][1], C[4][2] )  #   6 7
      daVinci.drawLine( C[3][1], C[3][2], C[4][1], C[4][2] )  #   3 4 > 
   ok 
   
 
  if ShapeType = "ShapeSolidTriangle"
      daVinci.setBrush(brushSY)
      daVinci.drawPolygon( [ [C[1][1], C[1][2]], [C[2][1], C[2][2]], [C[3][1], C[3][2]] ], 0)  // Yellow 14 85

      daVinci.setBrush(brushSR)
      daVinci.drawPolygon( [ [C[1][1], C[1][2]], [C[3][1], C[3][2]], [C[4][1], C[4][2]] ], 0)  // Red   12 34
    
      daVinci.setBrush(brushSM)
      daVinci.drawPolygon( [ [C[1][1], C[1][2]], [C[4][1], C[4][2]], [C[2][1], C[2][2]] ], 0)  // Cyan 23 76

      daVinci.setBrush(brushSG)
      daVinci.drawPolygon( [ [C[2][1], C[2][2]], [C[3][1], C[3][2]], [C[4][1], C[4][2]] ], 0)  // Green 56 79
  ok 
   
   

   if ShapeType = "ShapePI"
      daVinci.setpen(penYellow) 
      for i = 1 to len(ShapePI) -1
            daVinci.drawLine( C[i][1], C[i][2], C[i+1][1], C[i+1][2] ) 
      next
   ok

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
