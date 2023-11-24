### Matrix Transform -- Draw-Rotation -- Anton p.596
### Rotation, Size, Translate, Shear, Reflection, Speed, Increment Radians
### Bert Mariani  2020-10-30
###
### 

load "stdlibcore.ring"
load "lightguilib.ring"
Load "MatrixLib.ring"
   
// Shape to Draw
//VTest = []

Points = [
    [  1.000,  -0.800,   0.000],       //   P1  = x,y,z
    [  0.500,  -0.800,  -0.866],       //   P2  =
    [ -0.500,  -0.800,  -0.866],       //   P3  =
    [ -1.000,  -0.800,   0.000],       //   P4  =
    [ -0.500,  -0.800,   0.866],       //   P5  =
    [  0.500,  -0.800,   0.866],       //   P6  =
    [  0.840,  -0.400,   0.000],       //   P7  =
    [  0.315,   0.125,  -0.546],       //   P8  =
    [ -0.210,   0.650,  -0.364],       //   P9 =
    [ -0.360,   0.800,   0.000],       //   P10 =
    [ -0.210,   0.650,   0.364],       //   P11 =
    [  0.315,   0.125,   0.546]]       //   P12

Lines = [    
    [1 , 2],         // 1  [P1 , P2], // P <--> Q    
    [2 , 3],         // 2  [P2 , P3], 
    [3 , 4],         // 3  [P3 , P4], 
    [4 , 5],         // 4  [P4 , P5], 
    [5 , 6],         // 5  [P5 , P6], 
    [6 , 1],         // 6  [P6 , P1],
    [7 , 8],         // 7  [P7 , P8], 
    [8 , 9],         // 8  [P8 , P9], 
    [9 , 10],        // 9  [P9 , P10], 
    [10, 11],        // 10 [P10, P11], 
    [11, 12],        // 11 [P11, P12], 
    [12, 7],         // 12 [P12, P7],
    [1 , 7],         // 13 [P1 , P7],
    [2 , 8],         // 14 [P2 , P8], 
    [3 , 9],         // 15 [P3 , P9], 
    [4 , 10],        // 16 [P4 , P10], 
    [5 , 11],        // 17 [P5 , P11], 
    [6 , 12]]        // 18[P6 , P12]]    



PI          = 3.14159
IncAngleX    = 0       // Rotation Increment
IncAngleY    = 0
IncAngleZ    = 0
RotateAngle  = 45   // =15 Rotation Increment

xPos    = 100   ### Canvas position on Screen
yPos    = 100
xWidth  = 900   ### Canvas size on Screen
yHeight = 900   
  
// Need to define variable when using Func StartApp()
MonaLisa = null 
daVinci  = null 
Canvas   = null
myApp    = null

eRotXV   = null   // ROTATION Angle Text
eRotYV   = null
eRotZV   = null  
 
iRotXV   = null   // INCREMENT Angle Test, Repeated Clicks for new image
iRotYV   = null
iRotZV   = null

eScaleXV = null   // SCALE value
eScaleYV = null
eScaleZV = null

eTransXV = null   // Translate value
eTransYV = null
eTransZV = null

eReflXV  = null   // REFLECTION value -1, 0, 1
eReflYV  = null
eReflZV  = null


eShearXV = null   // SHEAR value
eShearYV = null
eShearZV = null


###-------------------------------
### Define Colours, Pens, Brushes

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


//==========================================
//=========================================
// START the APP

Func Main()
     StartApp()
return

//-----------------------------------

Func StartApp()

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
               #endpaint()                         ### This will Stop the Painting   
            }

            setPixMap(MonaLisa)
        }

        btn = new qPushButton(win) { setGeometry(0, 2, 100, 20)  setText("DrawMatrix")  setStyleSheet("background-color: yellow")
                                     setClickEvent("DrawMatrix()") 
                                   }


        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for ROTATION ANGLES
        
        // Rx = (eRotXV.text()
        // Ry = (eRotYV.text()
        // Rz = (eRotZV.text() 
        
        lRotation =  new qLabel(win)  { setgeometry( 0, 30 , 60, 20)  settext("RotateAngle") setStyleSheet("background-color: yellow")}
        lRotX  =  new qLabel(win)     { setgeometry( 0, 50 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
        eRotXV =  new qlineedit(win)  { setgeometry(30, 50 , 30, 20)  settext("210") }           
          
        lRotY  =  new qLabel(win)     { setgeometry( 0, 70 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
        eRotYV =  new qlineedit(win)  { setgeometry(30, 70 , 30, 20)  settext("-70") }

        lRotZ  =  new qLabel(win)     { setgeometry( 0, 90 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
        eRotZV =  new qlineedit(win)  { setgeometry(30, 90 , 30, 20)  settext("-27") }           
           
        ###---------------------
        ### INCREMENT ANGELE EDIT

         iRotation =  new qLabel(win)  { setgeometry( 66, 30 , 60, 20)  settext("IncAngle") setStyleSheet("background-color: yellow")}        
         iRotXV =  new qlineedit(win)  { setgeometry( 66, 50 , 30, 20)  settext("0") }     
         iRotYV =  new qlineedit(win)  { setgeometry( 66, 70 , 30, 20)  settext("0") }  
         iRotZV =  new qlineedit(win)  { setgeometry( 66, 90 , 30, 20)  settext("0") }   

        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for SCALE
        
        //Sx = eScaleXV.text()  
        //Sy = eScaleYV.text()  
        //Sz = eScaleZV.text()
        
         lScale   =  new qLabel(win)  { setgeometry( 0, 120 , 80, 20)  settext("Scale 0.1-10") setStyleSheet("background-color: yellow")}

         lScaleX  =  new qLabel(win)     { setgeometry( 0, 140 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eScaleXV =  new qlineedit(win)  { setgeometry(30, 140 , 30, 20)  settext("1") }           

         lScaleY  =  new qLabel(win)     { setgeometry( 0, 160 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eScaleYV =  new qlineedit(win)  { setgeometry(30, 160 , 30, 20)  settext("1") }

         lScaleZ  =  new qLabel(win)     { setgeometry( 0, 180 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eScaleZV =  new qlineedit(win)  { setgeometry(30, 180 , 30, 20)  settext("1") }           
               
 
        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for TRANSLATION
        
        //Sx = eScaleXV.text()  
        //Sy = eScaleYV.text()  
        //Sz = eScaleZV.text()
        
         lTranslate  =  new qLabel(win)  { setgeometry( 0, 210 , 80, 20)  settext("Trans 0-400") setStyleSheet("background-color: yellow")}

         lTransX  =  new qLabel(win)     { setgeometry( 0, 230 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eTransXV =  new qlineedit(win)  { setgeometry(30, 230 , 30, 20)  settext("0") }           

         lTransY  =  new qLabel(win)     { setgeometry( 0, 250 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eTransYV =  new qlineedit(win)  { setgeometry(30, 250 , 30, 20)  settext("0") }

         lTransZ  =  new qLabel(win)     { setgeometry( 0, 270 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eTransZV =  new qlineedit(win)  { setgeometry(30, 270 , 30, 20)  settext("0") }           

 
        ###-------------------------------------------------------------      
        ### Draw LABELS and LINEEDIT for REFLECTION
      
         lReflection =  new qLabel(win)    { setgeometry( 0, 300 , 80, 20)  settext("REF:-1,1") setStyleSheet("background-color: yellow")}

         lReflX      =  new qLabel(win)    { setgeometry( 0, 320 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eReflXV     =  new qlineedit(win) { setgeometry(30, 320 , 30, 20)  settext("1") }          
                  
         lReflY      =  new qLabel(win)    { setgeometry( 0, 340 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eReflYV     =  new qlineedit(win) { setgeometry(30, 340 , 30, 20)  settext("1") }
            
         lReflZ      =  new qLabel(win)    { setgeometry( 0, 360 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eReflZV     =  new qlineedit(win) { setgeometry(30, 360 , 30, 20)  settext("1") } 
 
 
        ###-------------------------------------------------------------      
        ###  Draw LABELS and LINEEDIT for SHEAR
      
         lShear   =  new qLabel(win)    { setgeometry( 0, 390 , 80, 20)  settext("SHEAR 0-5") setStyleSheet("background-color: yellow")}

         lShearX  =  new qLabel(win)    { setgeometry( 0, 410 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eShearXV =  new qlineedit(win) { setgeometry(30, 410 , 30, 20)  settext("0") }          
               
         lShearY  =  new qLabel(win)    { setgeometry( 0, 430 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eShearYV =  new qlineedit(win) { setgeometry(30, 430 , 30, 20)  settext("0") }
            
         lShearZ  =  new qLabel(win)    { setgeometry( 0, 450 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eShearZV =  new qlineedit(win) { setgeometry(30, 450 , 30, 20)  settext("0") }             
 

        //-------------------------------------------------------------      
        //-------------------------------------------------------------

      show()
          
    }
    exec()
 }

return

###==========================================================================
###==========================================================================

###------------------------------------------------------------------------
// Menu CLICK on DrawMatrix

Func DrawMatrix()           
       
    //-------------------------------------
    // Get 5x3 PARAMETERS for  Rotate, Scale, Translate, Shear, Reflect

    Rx = (eRotXV.text() * PI/180) +IncAngleX     // ROTATE  => Degrees to Radians 
    Ry = (eRotYV.text() * PI/180) +IncAngleY
    Rz = (eRotZV.text() * PI/180) +IncAngleZ 
    
    Sx = eScaleXV.text()   // SCALE - size
    Sy = eScaleYV.text()  
    Sz = eScaleZV.text()
  
    Tx = eTransXV.text()   // TRANSLATE - move
    Ty = eTransYV.text()  
    Tz = eTransZV.text()    
                
    Hx = eShearXV.text()   // SHEAR - distort
    Hy = eShearYV.text()  
    Hz = eShearZV.text()
      
    Fx = eReflXV.text()    // REFLECT - mirror  (+1 or -1)
    Fy = eReflYV.text()  
    Fz = eReflZV.text()    

    //-------------------------------------
    // Matrix Combo Result MT xx4
    
    MT = MatrixTransform(Rx,Ry,Rz, Sx,Sy,Sz, Tx,Ty,Tz, Hx,Hy,Hz, Fx,Fy,Fz )

    //-------------------------------------

    VShape = Points
    
    k = 100                                 //  K = SCALAR MULTIPLY - make shape bigger
    ShapeObj  = ScalarMultiply(k,VShape)
    ShapeLen  = len(ShapeObj)               // How many Points to Tranform-Draw
    Corners   = ShapeObj                    // Initial Points allocation for Draw       
   
    for i = 1 to ShapeLen
         
        A =[[ ShapeObj[i][1] ],             // X // X Y Z => 4x1  (Points convert Horz to Vert)
            [ ShapeObj[i][2] ],             // Y
            [ ShapeObj[i][3] ],             // Z
            [             1  ]]             // MUST =1 for Translate to work.

        FC = MatrixMultiply(MT,A)           // USAGE:  MatrixTranform  MT 4x4 * Points 4x1 (Point Horz to Vert)
   
            Corners[i][1] = FC[1][1]        // Point Result 4x1 - Vert format
            Corners[i][2] = FC[2][1]        // Put them back as Horz format for Image Draw
            Corners[i][3] = FC[3][1]  
            
    next


    //======================================================
    // x-axis through  30◦, => 210 tp flip
    // y-axis through −70◦,
    // z-axis through −27◦.

    DoDraw(Corners)                            // ===>>>   Comment Out --- stops at 258 iterations -- Stack ???

    RotateAngleX = (iRotXV.text() * PI/180)    // INCREMENT-TEXT >
    RotateAngleY = (iRotYV.text() * PI/180)
    RotateAngleZ = (iRotZV.text() * PI/180)

    IncAngleX += RotateAngleX           // Rotation Increment for NEXT CLICK on MENU
    IncAngleY += RotateAngleY           // Rotation Increment for NEXT CLICK on MENU
    IncAngleZ += RotateAngleZ           // Rotation Increment for NEXT CLICK on MENU
 
return

//----------------------------------------------------------
// Draw 8 Corner Points -- 12 Lines of New Position of Cube

Func DoDraw(C)

    //Draw 3D Axis
    MonaLisa.fill(colorBlack)                    // ===<<< BLANK OUT OLD IMAGE !!!

    daVinci.setpen(penGreen)
    daVinci.drawLine(   0, -300,    0,  300 )    //  Vert ### Draw NEW Line
    daVinci.drawLine(-300,    0,  300,    0 )    //  Horz
    daVinci.drawLine( 250, -350, -250,  350 )    // -45 
    //daVinci.drawLine( 250,  250, -250, -250 )  // +45

    //----------------------------------------------------
    // Draw the 12 Lines between the 8 Corners of the Cube

    EPointsTest = Lines                 // From GLOBAL values      
    EP          = EPointsTest           // Shorthand


    daVinci.setpen(penYellow)
    for i = 1 to len(EP)      

        // DRAW FROM <--> TO  
        daVinci.drawLine( C[EP[i][1]][1]  , C[EP[i][1]][2],   // FROM
                          C[EP[i][2]][1]  , C[EP[i][2]][2]    // TO
                        )                 
    next

    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw

return

//-----------------------------------------------------------------
###==========================================================================
###==========================================================================
