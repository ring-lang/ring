### Planetary Orbits
### Uses Matrix Transform to Tilt and Rotate Elliptical Orbits
### Display single and multiple orbits
### Multiple orbits use Log Scale to place them all on the screen
### Mecury, Venus,Earth,Mars,Jupiter,Saturn,Uranus,Neptune,Pluto
### Ceres, Halley,Icarus
### Bert Mariani  2023-08-16
### -------------------------------------------------

load "stdlibcore.ring"
load "lightguilib.ring"
Load "MatrixLib.ring"
   
//================================================
EN             = 2.71828       // e = Euler's Number
PI             = 3.14159
ImageScale     = 4             // Planet Image 200x200 => 50x5
Inc            = 100           // aSMA / Dots per Orbit. Draw dots of Orbit spacing 0.001
DotsPerOrbit   = 500           // Draw dots of Orbit spacing 0.001
AnimationSpeed = 0.01        // Delay in Secs between moving Image in Orbit
gPositiveLog   = 4           // Mercury and Venus are Negative aSMA in AU. Add 4 to get Positive Log
gPlanetName    = "Mercury"   // Used to save Corner Array for that Planet in DrawOrbit transform calculations

Corners       = list(1,3)                      // Orbit Points to Draw
MC            = list(1,(DotsPerOrbit * 2) +1)    // Matrix Array of Ellipsoid Points

CornerP           = list(1,DotsPerOrbit * 2 +1)    // Panet Current from OneDraw
CornerM           = list(1,DotsPerOrbit * 2 +1)    // Mercury
CornerV           = list(1,DotsPerOrbit * 2 +1)    // Venus
CornerE           = list(1,DotsPerOrbit * 2 +1)
CornerMa          = list(1,DotsPerOrbit * 2 +1)
CornerC           = list(1,DotsPerOrbit * 2 +1)
CornerJ           = list(1,DotsPerOrbit * 2 +1)
CornerSa          = list(1,DotsPerOrbit * 2 +1)
CornerU           = list(1,DotsPerOrbit * 2 +1)
CornerN           = list(1,DotsPerOrbit * 2 +1)    // Neptune
CornerPl          = list(1,DotsPerOrbit * 2 +1)
CornerH           = list(1,DotsPerOrbit * 2 +1)
CornerI           = list(1,DotsPerOrbit * 2 +1)


IncAngleX    = 0        // Rotation Increment
IncAngleY    = 0
IncAngleZ    = 0
RotateAngle  = 45   // =15 Rotation Increment

xPos    = 100   ### Canvas position on Screen
yPos    = 25
xWidth  = 1800  ### Canvas size on Screen
yHeight = 1000  
  
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

tRotXV   = null   // TotalAngle => Rotation + Increment
tRotYV   = null 
tRotZV   = null 

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


eValA    = null   // X - Horz Width
eValB    = null   // Y - Vert Height
eValC    = null   // Z - Depth

eValH    = null   // X - Center Horz
eValV    = null   // Y - Center Vert
eValD    = null   // Z - Center Depth

eValCyl  = null   // Cylinder - multiples
eValInc  = null   // Increament - dots to draw

eCheckOneDraw       = null  // Draw 1 image, no overlaps
eOrbitScale         = null  // Magnify scale of Multi Orbits
eImageScale         = null  // Planet Image 1-Big 10-Small

eCheckInnerPlanets  =  null
eCheckOuterPlanets  =  null
eCheckAllPlanets    =  null

comboShapeType = null
ConicEquation  = "Figure"
imageStockX    = null      // Sun
imageStockP    = null      // Planet


imageStockM    = null      // Mercury
imageStockV    = null      // Venus
imageStockE    = null      // Earth
imageStockMa   = null      // Mars
imageStockC    = null      // Ceres
imageStockJ    = null      // Jupiter
imageStockS    = null      // Saturn
imageStockU    = null      // Uranus
imageStockN    = null      // Neptune
imageStockPl   = null      // Pluto
imageStockH    = null      // Halley
imageStockI    = null      // Icarus


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
        setWindowTitle("Planet Orbits - 3D Rotations: ")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size
        setWinIcon(self,"images/Earth4.png")

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
            
            //-------------------------------------------------
            // SOLARSYSTEM3
            imageStock = new qlabel(win)                              // Place at top center of screen
            {
                    image = new qPixMap("images/SolarSystem4.png")          // image width 1264 height 213
                    AspectRatio = image.width() / image.height()
                    
                    setpixmap(image.scaled(image.Width() , image.Height() ,0,0))   ### Size-H, Siz-V, Aspect, Transform
                                
                    PosLeft =  (xWidth - image.width() )/ 2         // 62  // (imageW ) / 2
                    PosTop  =  00                                   //        (imageH ) / 2
                    setGeometry(PosLeft,PosTop,image.Width(),image.Height())   
            }            

            //-------------------------------------------
            // SUN3 - 200x200
            imageStockX = new qlabel(win) 
            {
                image = new qPixMap("images/Sun4.png")         
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) ) 
            }

            // PLANET Planet - 200x200
            imageStockP = new qlabel(win) 
            {
                image = new qPixMap("images/Mercury4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }

            //----------------------------------------------        
            // PLANET MERCURY3 - 200x200
            imageStockM = new qlabel(win) 
            {
                image = new qPixMap("images/Mercury4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                           
            }
            
            // PLANET VENUS3 - 200x200
            imageStockV = new qlabel(win) 
            {
                image = new qPixMap("images/VENUS4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                           
            }

            // PLANET EARTH3 - 200x200
            imageStockE = new qlabel(win) 
            {
                image = new qPixMap("images/Earth4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                           
            }
            
            // PLANET MARS3 - 200x200
            imageStockMa = new qlabel(win) 
            {
                image = new qPixMap("images/Mars4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }           

            // PLANET Ceres3 - 200x200
            imageStockC = new qlabel(win) 
            {
                image = new qPixMap("images/Ceres4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }
            
            // PLANET Jupiter3 - 200x200
            imageStockJ = new qlabel(win) 
            {
                image = new qPixMap("images/Jupiter4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                           
            }
            
            // PLANET Saturn3 - 200x200
            imageStockS = new qlabel(win) 
            {
                image = new qPixMap("images/Saturn4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }

            // PLANET Uranus3 - 200x200
            imageStockU = new qlabel(win) 
            {
                image = new qPixMap("images/Uranus4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }

            // PLANET Neptune3 - 200x200
            imageStockN = new qlabel(win) 
            {
                image = new qPixMap("images/Neptune4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }

            // PLANET Pluto3 - 200x200
            imageStockPl = new qlabel(win) 
            {
                image = new qPixMap("images/Pluto4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }           
            
            // PLANET HALLEY3
            imageStockH = new qlabel(win) 
            {
                image = new qPixMap("images/Halley4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }           

            // PLANET ICARUS3
            imageStockI = new qlabel(win) 
            {
                image = new qPixMap("images/Icarus4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )                            
            }           

            //-------------------------------
            setPixMap(MonaLisa)   // Draw It
        }  
        
        //=====================================================

        comboShapeType = new QComboBox(win) 
        {
            setgeometry( 0, 2, 100, 20)
            comboList = ["SelectPlanet","Mercury","Venus","Earth","Mars","Ceres",
                         "Jupiter","Saturn","Uranus","Neptune",
                         "Pluto","Halley","Icarus"
                        ]
            for x in comboList additem(x,0) next                    
        }           

        btnCS = new qPushButton(win) { setGeometry( 110, 2, 100, 20)  setText("Start/Calc")  setStyleSheet("background-color: aqua")
                                       setClickEvent("StartCalc()") 
                                     }
        btnDM = new qPushButton(win) { setGeometry( 220, 2, 100, 20)  setText("DrawOrbit")  setStyleSheet("background-color: aqua")
                                       setClickEvent("DrawOrbit(gPlanetName)") 
                                     }
        btnPL = new qPushButton(win) { setGeometry( 330, 2, 80, 20)   setText("DrawAllOrbits")  setStyleSheet("background-color: aqua")
                                       setClickEvent("DrawAllOrbits()")                        
                                     }  
                                     
        btnAT = new qPushButton(win) { setGeometry( 430, 2, 80, 20)   setText("Animation")  setStyleSheet("background-color: aqua")
                                       setClickEvent("Animation()")                          
                                     }                           
                                  
        //===============================================================  
        
         ###--------------------------
         ### ONE-DRAW, MULTI-ORBITS, OVERLAP IMAGE or CLEAR if Set
         eCheckOneDraw      =  new qCheckBox(win)  { setgeometry( 220, 30 , 80, 20) settext("OneDraw") setStyleSheet("background-color: yellow")}         
   
         lOrbitScale        =  new qLabel(win)     { setgeometry( 220, 50 , 50, 20)  settext("MagOrbit")  setStyleSheet("background-color: yellow")}
         eOrbitScale        =  new qlineedit(win)  { setgeometry( 270, 50 , 30, 20)  settext("100") } 
     
         eCheckInnerPlanets =  new qCheckBox(win)  { setgeometry( 330, 30 , 80, 20) settext("InnerPlanets") setStyleSheet("background-color: yellow")}         
         eCheckOuterPlanets =  new qCheckBox(win)  { setgeometry( 330, 50 , 80, 20) settext("OuterPlanets") setStyleSheet("background-color: yellow")}    
    
        //--------------------------------------------
/*      
        lValA  =  new qLabel(win)     { setGeometry(430,  2, 30, 20)  setText("X-a:")  setStyleSheet("background-color: yellow")}
        eValA  =  new qLineEdit(win)  { setGeometry(460,  2, 30, 20)  setText("5") }           
 
        lValB  =  new qLabel(win)     { setGeometry(490,  2, 30, 20)  setText("Y-b:")  setStyleSheet("background-color: yellow")}
        eValB  =  new qLineEdit(win)  { setGeometry(520,  2, 30, 20)  setText("3") }           

        lValC  =  new qLabel(win)     { setGeometry(550,  2, 30, 20)  setText("Z-c:")  setStyleSheet("background-color: yellow")}
        eValC  =  new qLineEdit(win)  { setGeometry(580,  2, 30, 20)  setText("1") }           

        lValH  =  new qLabel(win)     { setGeometry(630,  2, 30, 20)  setText("X-h:")  setStyleSheet("background-color: yellow")}
        eValH =  new qLineEdit(win)   { setGeometry(660,  2, 30, 20)  setText("0") }           
 
        lValV  =  new qLabel(win)     { setGeometry(690,  2, 30, 20)  setText("Y-v:")  setStyleSheet("background-color: yellow")}
        eValV  =  new qLineEdit(win)  { setGeometry(720,  2, 30, 20)  setText("0") }           

        lValD  =  new qLabel(win)     { setGeometry(750,  2, 30, 20)  setText("Z-d:")  setStyleSheet("background-color: yellow")}
        eValD  =  new qLineEdit(win)  { setGeometry(780,  2, 30, 20)  setText("0") }           
    
        lValCyl  =  new qLabel(win)     { setGeometry(830,  2, 30, 20)  setText("Cyl:")  setStyleSheet("background-color: yellow")}
        eValCyl  =  new qLineEdit(win)  { setGeometry(860,  2, 30, 20)  setText("0") }           

        lValInc  =  new qLabel(win)     { setGeometry(890,  2, 30, 20)  setText("Inc:")  setStyleSheet("background-color: yellow")}
        eValInc  =  new qLineEdit(win)  { setGeometry(920,  2, 30, 20)  setText("0.01") }           

*/

        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for ROTATION ANGLES
           
        lRotation =  new qLabel(win)  { setgeometry( 0, 30 , 60, 20) settext("RotateAngle") setStyleSheet("background-color: yellow")}
        lRotX  =  new qLabel(win)     { setgeometry( 0, 50 , 30, 20) settext("X:")   setStyleSheet("background-color: yellow")}
        eRotXV =  new qlineedit(win)  { setgeometry(30, 50 , 30, 20) settext("60") }        
          
        lRotY  =  new qLabel(win)     { setgeometry( 0, 70 , 30, 20) settext("Y:")   setStyleSheet("background-color: yellow")}
        eRotYV =  new qlineedit(win)  { setgeometry(30, 70 , 30, 20) settext("0") }

        lRotZ  =  new qLabel(win)     { setgeometry( 0, 90 , 30, 20) settext("Z:")   setStyleSheet("background-color: yellow")}
        eRotZV =  new qlineedit(win)  { setgeometry(30, 90 , 30, 20) settext("10") }        
           
        ###---------------------
        ### INCREMENT ANGELE EDIT
/*
         iRotation =  new qLabel(win)  { setgeometry( 66, 30 , 80, 20)  settext("Total/IncAngle") setStyleSheet("background-color: yellow")}          

         tRotXV =  new qlineedit(win)  { setgeometry(  66, 50 , 40, 20) settext("0") setStyleSheet("background-color: yellow") }      
         tRotYV =  new qlineedit(win)  { setgeometry(  66, 70 , 40, 20) settext("0") setStyleSheet("background-color: yellow") }   
         tRotZV =  new qlineedit(win)  { setgeometry(  66, 90 , 40, 20) settext("0") setStyleSheet("background-color: yellow") }    
         
         iRotXV =  new qlineedit(win)  { setgeometry( 110, 50 , 30, 20) settext("0") }     
         iRotYV =  new qlineedit(win)  { setgeometry( 110, 70 , 30, 20) settext("0") }  
         iRotZV =  new qlineedit(win)  { setgeometry( 110, 90 , 30, 20) settext("0") }   
*/
 
     
        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for SCALE
        
       
         lScale   =  new qLabel(win)  { setgeometry( 0, 120 , 60, 20)  settext("Scale 0.1-10") setStyleSheet("background-color: yellow")}

         lScaleX  =  new qLabel(win)     { setgeometry( 0, 140 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eScaleXV =  new qlineedit(win)  { setgeometry(30, 140 , 30, 20)  settext("5") }           

         lScaleY  =  new qLabel(win)     { setgeometry( 0, 160 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eScaleYV =  new qlineedit(win)  { setgeometry(30, 160 , 30, 20)  settext("5") }

         lScaleZ  =  new qLabel(win)     { setgeometry( 0, 180 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eScaleZV =  new qlineedit(win)  { setgeometry(30, 180 , 30, 20)  settext("5") }           
               
/*
        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for TRANSLATION
        
         lTranslate  =  new qLabel(win)  { setgeometry( 0, 210 , 60, 20)  settext("Trans 0-400") setStyleSheet("background-color: yellow")}

         lTransX  =  new qLabel(win)     { setgeometry( 0, 230 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eTransXV =  new qlineedit(win)  { setgeometry(30, 230 , 30, 20)  settext("0") }           

         lTransY  =  new qLabel(win)     { setgeometry( 0, 250 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eTransYV =  new qlineedit(win)  { setgeometry(30, 250 , 30, 20)  settext("0") }

         lTransZ  =  new qLabel(win)     { setgeometry( 0, 270 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eTransZV =  new qlineedit(win)  { setgeometry(30, 270 , 30, 20)  settext("0") }           

 
        ###-------------------------------------------------------------      
        ### Draw LABELS and LINEEDIT for REFLECTION
      
         lReflection =  new qLabel(win)    { setgeometry( 0, 300 , 60, 20)  settext("REF:-1,1") setStyleSheet("background-color: yellow")}

         lReflX      =  new qLabel(win)    { setgeometry( 0, 320 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eReflXV     =  new qlineedit(win) { setgeometry(30, 320 , 30, 20)  settext("1") }          
                  
         lReflY      =  new qLabel(win)    { setgeometry( 0, 340 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eReflYV     =  new qlineedit(win) { setgeometry(30, 340 , 30, 20)  settext("1") }
            
         lReflZ      =  new qLabel(win)    { setgeometry( 0, 360 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eReflZV     =  new qlineedit(win) { setgeometry(30, 360 , 30, 20)  settext("1") } 
 
 
        ###-------------------------------------------------------------      
        ###  Draw LABELS and LINEEDIT for SHEAR
      
         lShear   =  new qLabel(win)    { setgeometry( 0, 390 , 60, 20)  settext("SHEAR 0-5") setStyleSheet("background-color: yellow")}

         lShearX  =  new qLabel(win)    { setgeometry( 0, 410 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eShearXV =  new qlineedit(win) { setgeometry(30, 410 , 30, 20)  settext("0") }          
               
         lShearY  =  new qLabel(win)    { setgeometry( 0, 430 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eShearYV =  new qlineedit(win) { setgeometry(30, 430 , 30, 20)  settext("0") }
            
         lShearZ  =  new qLabel(win)    { setgeometry( 0, 450 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eShearZV =  new qlineedit(win) { setgeometry(30, 450 , 30, 20)  settext("0") }             
*/

        //=============================================================    
     

      show()
          
    }
    exec()
 }

return

###==========================================================================
###==========================================================================

//  Click => StartCalc()  START - CLEAR-SCREEN - FIGURE

Func StartCalc()                   // Start/Calc Button

   See "Old MC size: "+ len(MC) +nl  
   for i = 1 to len(MC)              // length of MC matrix list(200,3)
      del(MC,i)
   next
   
   MC = list(1,3)                    // Matrix Array of Ellipsoid Points
   See "New MC size: "+ len(MC) +nl
   
   RotateAngleX = 0
   RotateAngleY = 0
   RotateAngleZ = 0
   
   IncAngleX    = 0
   IncAngleY    = 0
   IncAngleZ    = 0
   
    //------------------------------------------------------------
	// ONE DRAW - Move Planet Images off screen, Blank out screen
	
    if eCheckOneDraw.isChecked() = 1     // Move Planet Image OFF Screen  
       ClearImages()
    ok
        
       
    if eCheckOneDraw.isChecked() = 1      // ONE Orbit - Clear previous
       MonaLisa.fill(colorBlack)          // ===<<< BLANK OUT OLD IMAGE !!!
    ok
   

    //-----------------------------------------------
    // Set SCALE before Single DrawOrbit is CALLED
	
   	if eCheckOneDraw.isChecked() = 1
		 eCheckInnerPlanets.setChecked(0) 
		 eCheckOuterPlanets.setChecked(0) 
         ClearImages() 
	ok
	
	if  eCheckInnerPlanets.isChecked() = 0  AND  eCheckOuterPlanets.isChecked() = 0 
		MagScale = 0 + eOrbitScale.text() 
		if MagScale > 200
		   Magnify  = 100
		   eOrbitScale.setText(""+ Magnify)	
        ok		   
	ok
	
	if  eCheckInnerPlanets.isChecked() = 1  AND  eCheckOuterPlanets.isChecked() = 0 
		MagScale = 0 + eOrbitScale.text() 
		if MagScale < 200
		   Magnify  = 500
		   eOrbitScale.setText(""+ Magnify)	
        ok		   
	ok
	
	if  eCheckOuterPlanets.isChecked() = 1 
		MagScale = 0 + eOrbitScale.text() 
		if MagScale > 200
		   Magnify  = 100
		   eOrbitScale.setText(""+ Magnify)	
		ok   
	ok
		
	

   
    Figure()                               // ===>>> Which Planet or Figure
    
return 

###==========================================================================
###==========================================================================

Func  ClearImages()

  
        imageStockP.setGeometry(-200, -200 , 200, 200 )      // Last PLANET IMAGE displayed - Hide old image
		
        imageStockM.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockV.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockE.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockMa.setGeometry(-200, -200 , 200, 200 )     // PLANET IMAGE - Hide old image
        imageStockC.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockJ.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockS.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockU.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockN.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
        imageStockPl.setGeometry(-200, -200 , 200, 200 )     // PLANET IMAGE - Hide old image
        imageStockH.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image 
        imageStockI.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image 
        
        MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
        Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
        MyApp.ProcessEvents()               ### <<< EXEC the Draw
        
return

###==========================================================================
###==========================================================================
// CALLED by StartCalc()
// comboList = ["Figure","Ellipsoid","Cone","EllipticParaboloid","HyperboloidOneSheet","HyperbolicParaboloid","HyperboloidTwoSheets"]
   
Func Figure()

/*  // Used of Elliptical Equations Offsets
    a   = number( (eValA.text()) )    // = null   // X - Horz Width
    b   = number( (eValB.text()) )    // = null   // Y - Vert Height
    c   = number( (eValC.text()) )    // = null   // Z - Depth
    h   = number( (eValH.text()) )    // = null   // X - Center Horz
    v   = number( (eValV.text()) )    // = null   // Y - Center Vert
    d   = number( (eValD.text()) )    // = null   // Z - Center Depth
    Cyl = number( (eValCyl.text()) )  // = null   // Increament - dots to draw
    Inc = number( (eValInc.text()) )  // = null   // Cylinder - multiples
*/
     
    ConicEquation = comboShapeType.currentText()
    
    if     ConicEquation  = "Mercury"                 GoMercury()
    elseif ConicEquation  = "Venus"                   GoVenus()
    elseif ConicEquation  = "Earth"                   GoEarth()
    elseif ConicEquation  = "Mars"                    GoMars()
    elseif ConicEquation  = "Ceres"                   GoCeres()
    elseif ConicEquation  = "Jupiter"                 GoJupiter()
    elseif ConicEquation  = "Saturn"                  GoSaturn()
    elseif ConicEquation  = "Uranus"                  GoUranus()
    elseif ConicEquation  = "Neptune"                 GoNeptune()
    elseif ConicEquation  = "Pluto"                   GoPluto() 
    elseif ConicEquation  = "Halley"                  GoHalley()
    elseif ConicEquation  = "Icarus"                  GoIcarus()
    else   ConicEquation  = "SelectOrbit"             GoMars()
    ok
 
return

###==========================================================================
###==========================================================================
// CLICK => DrawOrbit()   after Calculations are done for a Planet
// CLICK => DrawAllOrbits
// DRAW-MATRIX Points Generated

Func DrawOrbit(gPlanetName)
     


   PlanetName = comboShapeType.currentText()

  //VShape   = Points
    VShape   = MC
    
    k = 1  // 100  //  K = SCALAr MULTIPLY when Value 0 <--> 1
    ShapeObj  = ScalarMultiply(k,VShape)
    ShapeLen  = len(ShapeObj)               // How many Points to Tranform-Draw
    Corners   = ShapeObj                    // Initial Points allocation for Draw

 
    for i = 1 to ShapeLen
         
        A =[[ ShapeObj[i][1] ],      // X // X Y Z => 4x1  
            [ ShapeObj[i][2] ],      // Y
            [ ShapeObj[i][3] ],      // Z
            [             1  ]]      // 1  Make Sure to put 1 here

            //-------------------------------------
            // SCALE
            
            Sx = eScaleXV.text()  
            Sy = eScaleYV.text()  
            Sz = eScaleZV.text()

            S =[[ Sx,  0,  0, 0 ],      // Scale          
                [  0, Sy,  0, 0 ],
                [  0,  0, Sz, 0 ],
                [  0,  0,  0, 1 ]]

/*
            //-------------------------------------
            // TRANSLATE
            
            Tx = eTransXV.text()  
            Ty = eTransYV.text()  
            Tz = eTransZV.text()    
         
            TA =[[Tx],               // TRANSLATE MatrxAdd  -- String to Mumber: 0+Tx
                 [Ty], 
                 [Tz],
                 [ 1]]               // Put 1 here

            TM =[[ 1, 0, 0, Tx ],    // TRANSLATE MatrxMultiply  -- String to Mumber: 0+Tx
                 [ 0, 1, 0, Ty ], 
                 [ 0, 0, 1, Tz ],
                 [ 0, 0, 0,  1 ]]                

            //-------------------------------------
            // REFLECTION  1 or -1 or 0

            Fx = eReflXV.text()  
            Fy = eReflYV.text()  
            Fz = eReflZV.text()          // Reflect -1,  NoRefect = 1
            
            RF  =  [[  Fx,   0,   0, 0],       // Reflection  x-plane
                    [   0,  Fy,   0, 0],
                    [   0,   0,  Fz, 0],
                    [   0,   0,   0, 1]]

   
            //-------------------------------------
            // SHEAR 
            
            Hx = eShearXV.text()  
            Hy = eShearYV.text()  
            Hz = eShearZV.text()
            
            H = [[  1,  Hx,  Hx, 0],          // Shear XYZ Distort
                 [ Hy,   1,  Hy, 0], 
                 [ Hz,  Hz,   1, 0], 
                 [  0,   0,   0, 1]]

*/
              
            //--------------------------------------
            // ROTATION MATRIX EQUATIONS       

            Rx = (eRotXV.text() * PI/180) +IncAngleX     // EDIT-TEXT => Degrees to Radians 
            Ry = (eRotYV.text() * PI/180) +IncAngleY
            Rz = (eRotZV.text() * PI/180) +IncAngleZ     

            //-------------------------------------
            //-------------------------------------         

            X =[[    1,        0,        0,     0 ],     // Rx Rotation: Matrix * XYZ,  3x3 * 3x1 => 3x1
                [    0,      cos(Rx), -sin(Rx), 0 ],
                [    0,      sin(Rx),  cos(Rx), 0 ],  
                [    0,        0,        0,     1 ]]

            Y =[[  cos(Ry),    0,      sin(Ry), 0 ],     // Ry Rotation
                [    0,        1,        0,     0 ],
                [ -sin(Ry),    0,      cos(Ry), 0 ],
                [    0,        0,        0,     1 ]]

            Z =[[  cos(Rz), -sin(Rz),    0,     0 ],     // Rz Rotation         
                [  sin(Rz),  cos(Rz),    0,     0 ],
                [    0,        0,        1,     0 ],
                [    0,        0,        0,     1 ]]

            //------------------------------------
            //-------------------------------------
            // SRT  Translate, Scale ,, (Shear, Reflextion), ROTATE
            // Any combination of the order S*R*T gives a valid transformation matrix. 
            // However, it is pretty common to first scale the object, then rotate it, then translate it:

            CS = MatrixMultiply(S,A)     // SCALE -- Change Size    

            CX = MatrixMultiply(X,CS)    // ROTATION-3D-Matrix-XYZ x A-Points => C = 3x1 output
            CY = MatrixMultiply(Y,CX)        
            CZ = MatrixMultiply(Z,CY)

/*    
            CH = MatrixMultiply(H,CZ)    // SHEAR -- Distort
            CR = MatrixMultiply(RF,CH)   // REFLECTION -1, 0, 1    
         // CT = MatrixAdd(TA,CR)        // TRANSLATE ADD      -- Change Position
            CT = MatrixMultiply(TM,CR)   // TRANSLATE MULTIPLY -- Change Position              
            FC = CT                      // FINAL FC transform - SRT      
*/
            FC = CZ                      // FINAL FC transform - Scale and Rotate ONLY for Planets 
            
            //---------------------------
            
            Corners[i][1] = FC[1][1]     // Build Corners array for each Point
            Corners[i][2] = FC[2][1]     // Save For each of 8 Points, Each Corner Point after Transform xyz
            Corners[i][3] = FC[3][1]
       
    next
    
    //------------------------------------------------
    // Save for Animation. Calculated Orbits to each Planet

        PlanetName = gPlanetName
        CornerP    = Corners                                     // Planet  Current for OneDraw
        if          PlanetName = "Mercury"   CornerM  = Corners   
            elseif  PlanetName = "Venus"     CornerV  = Corners  
            elseif  PlanetName = "Earth"     CornerE  = Corners  
            elseif  PlanetName = "Mars"      CornerMa = Corners  
            elseif  PlanetName = "Ceres"     CornerC  = Corners
            elseif  PlanetName = "Jupiter"   CornerJ  = Corners  
            elseif  PlanetName = "Saturn"    CornerSa = Corners  
            elseif  PlanetName = "Uranus"    CornerU  = Corners  
            elseif  PlanetName = "Neptune"   CornerN  = Corners  
            elseif  PlanetName = "Pluto"     CornerPl = Corners  
            elseif  PlanetName = "Halley"    CornerH  = Corners  
            elseif  PlanetName = "Icarus"    CornerI  = Corners  
        ok
        
 
        //======================================================
        // DRAW FIGURE at ANGLE XYZ
        // x-axis through  30◦, => 210 tp flip
        // y-axis through −70◦,
        // z-axis through −27◦.

        DoDraw(Corners)           // ===>>>   Comment Out --- stops at 258 iterations -- Stack ???

/*
        RotateAngleX = (iRotXV.text() * PI/180)      // Degrees to Radians INCREMENT-TEXT >
        RotateAngleY = (iRotYV.text() * PI/180)
        RotateAngleZ = (iRotZV.text() * PI/180)

        IncAngleX += RotateAngleX   // Radians: Rotation Increment for NEXT CLICK on MENU
        IncAngleY += RotateAngleY   //          Rotation Increment for NEXT CLICK on MENU
        IncAngleZ += RotateAngleZ   //          Rotation Increment for NEXT CLICK on MENU
        

        tRotXV.settext( string( IncAngleX * 180/PI) )  // TotalAngle: Radian to Angle to String
        tRotYV.settext( string( IncAngleY * 180/PI) )
        tRotZV.settext( string( IncAngleZ * 180/PI) )
*/
        
return



###==========================================================================
###==========================================================================
// CALLED by DrawOrbit()
// Draw CORNER POINTS -- Matrx Array of Points for Orbit of Planet
// Note in Computer Graphics XY-Horz-Vert: Vert-0 is Top of screen, Paper Vert-0 is Bottom  Z is to the BAck
//
// xWidth  = 900   ### Canvas size on Screen
// yHeight = 900 
//--------------------------------------------

Func DoDraw(C)

    //------------------------------------------
    //Draw 3D Axis
    //    MonaLisa.fill(colorBlack)                    // ===<<< BLANK OUT OLD IMAGE !!!
    
    if eCheckOneDraw.isChecked() = 1                   // ONE Orbit - Clear previous
       MonaLisa.fill(colorBlack)                       // ===<<< BLANK OUT OLD IMAGE !!!
    ok
    


    daVinci.setpen(penGreen)
    daVinci.drawLine(   0, -300,    0,  300 )        //  Vert ### Draw NEW Line
    daVinci.drawLine(-300,    0,  300,    0 )        //  Horz
    //daVinci.drawLine( 250, -250, -250,    250 )    // -45  250, -350, -250,  350 

    //----------------------------------------------------
    // DRAW LINE FROM <--> TO 
    daVinci.setpen(penYellow)
    for i = 1 to len(C) -1      
        FlipX1 = -C[i][1]     FlipY1 = -C[i][2]
        FlipX2 = -C[i+1][1]   FlipY2 = -C[i+1][2]
        if ConicEquation  = "Plane"
            daVinci.drawLine( C[i][1] , FlipY1, C[i+1][1] , FlipY2 )       // From xy TO xy  
        ok
    next
    
    //-------------------------
    // PLANE
    for i = 1 to len(C) -4     
        if ConicEquation  = "Plane"
          daVinci.setBrush(brushSM)   // Magenta intersity 64 = Faint
          daVinci.drawPolygon( [ [C[i+0][1], C[i+0][2]], [C[i+1][1], C[i+1][2]], [C[i+2][1], C[i+2][2]], [C[i+3][1], C[i+3][2]] ], 0)  // Yello 14 85
        ok
    next        
    
    //-----------------------------------------------------
    // DRAW POINT AT    
    daVinci.setpen(penYellow)
    for i = 1 to len( C )   
        FlipX1 = - C[i][1]     FlipY1 =  - C[i][2]    
        daVinci.drawPoint( C[i][1], FlipY1)               // Dray XY Point of ellipse
    next

    //-----------------------------------------------------
    // DRAW PLANET ELLIPSE - FOCI POINTS
    if ( (ConicEquation = "SelectPlanet") or
         (ConicEquation = "Mercury") or (ConicEquation = "Earth")   or (ConicEquation = "Venus")   or
         (ConicEquation = "Mars")    or (ConicEquation = "Ceres")   or (ConicEquation = "Jupiter") or 
         (ConicEquation = "Saturn")  or (ConicEquation = "Uranus")  or (ConicEquation = "Neptune") or 
         (ConicEquation = "Pluto")   or (ConicEquation = "Halley")  or (ConicEquation = "Icarus")
        )
        
        daVinci.setpen(penRed)

        Last = len( C )                                       // Array of Orbit Points
        PtE  = floor(Last / 24)                                // Point on Ellipse  ~ 3/4 or  10 oclock

        FocLX  = C[last-1][1]   FocLY = -C[last-1][2]         // FOCI X-Y Points
        FocRX  = C[last-2][1]   FocRY = -C[last-2][2]         // Y-Paper opposite of Y-Screen
        PtEX   = C[PtE][1]      PtEY  = -C[PtE][2]            // Orbit ~ 3/4 of orbit point                 
        
        daVinci.drawPoint( FocLX, FocLY )                     // Foci left   Neg-X     ( Y decrease Up, increses Down)
        daVinci.drawPoint( FocRX, FocRX )                     // Foci right  Pos-X
        daVinci.drawPoint( PtEX,  PtEY  )                     // Foci Orbit Point on Elipse

        daVinci.drawLine( PtEX , PtEY , FocRX, FocRY )         // Foci PtE PointOnEllipse to FOCI-L
        daVinci.drawLine( PtEX , PtEY , FocLX, FocLY )         // Foci-R
 
        Wide = ImageStockX.width()                            //  Alredy scaled by ImageStockX  181 / 3
        High = ImageStockX.height()                           //  181 / 3
        
        PosX  = xWidth/2  - (Wide/2)  //+ FocRX              // Center + FOCI  = Center of Sun Image
        PosY  = yHeight/2 - (High/2)

        PtEX2 = xWidth/2  - (Wide/2)  + PtEx               // Image Planet - Trnslate Co-ordinates
        PtEY2 = yHeight/2 - (High/2)  + PtEY + 

        imageStockX.setGeometry(PosX,  PosY ,  Wide, High)      // SUN3 IMAGE
        imageStockP.setGeometry(PtEX2, PtEY2 , Wide, High)      // PLANET IMAGE 

        //daVinci.drawImage(300,300, ImageX )   // ???
        //-----------------------------------------     

    ok
    //-----------------------------------------------------
    
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw

return


###==============================================================
###==============================================================

// DRAWALLORBITS = Display ALL Planets One by One
// Select Planet.  StartCalc.  DrawOrbit

Func DrawAllOrbits()

    PlanetList = ["Neptune","Pluto","Uranus","Saturn","Jupiter","Ceres","Mars","Earth","Venus","Mercury","Icarus","Halley" ]  // ,"Icarus"]  
    
    //--------------------------------------------------------------

    StartCalc()                       // Initialize Matrix Clear Screen
    ClearImages()                     // CLEAR the Images -- move Off Screen
 
    // Draw Planet Images, Outer then Inner Planets
    for i = 1 to len(PlanetList)
    
        Planet         = PlanetList[i]
        ConicEquation  = Planet        // Simulate DropDown mene 
  

		
        if  eCheckOuterPlanets.isChecked() =1       

            if         ConicEquation  = "Neptune"    GoNeptune()
                elseif ConicEquation  = "Pluto"      GoPluto() 
                elseif ConicEquation  = "Uranus"     GoUranus()
                elseif ConicEquation  = "Saturn"     GoSaturn()
                elseif ConicEquation  = "Jupiter"    GoJupiter()
                elseif ConicEquation  = "Halley"     GoHalley()
                //else   GoJupiter() 
            ok
        ok
                  
 
        if ( eCheckInnerPlanets.isChecked() =1 )                   
                    if ConicEquation  = "Mars"       GoMars()
				elseif ConicEquation  = "Earth"      GoEarth()
				elseif ConicEquation  = "Venus"      GoVenus()		
			    elseif ConicEquation  = "Mercury"    GoMercury()
			    elseif ConicEquation  = "Ceres"      GoCeres() 
                elseif ConicEquation  = "Icarus"     GoIcarus()    
				//else   GoMars() 
            ok          
        ok                      

    
        gPlanetName = ConicEquation        // Global gPlanetNAme used in DrawOrbit Corner Array to Save for that Planet

        DrawOrbit(gPlanetName)

     
    next

return 

###==========================================================================
###==========================================================================
//  Click => Animation()  Move Planet around its Orbit
//  Draw Orbit first. OneDraw Planet || or MulOrbits Planets
//  Rotate Planet Images by Orbital Years Cycle.  Earth = 1 Year

Func Animation()

    MCSteps  =  len(MC) - 2               // 500*2 -1  Last are Foci, Nbr of Points in MC array for Ellipse of Orbit
    Steps    = MCSteps / (DotsPerOrbit * 2)
        
    //               1-Name      2-Image       3- Corners 4-Year   5-StepSize           6-Steps-OneCycle
    PlanetTable = [[ "Mercury" , ImageStockM,  CornerM ,    87 ,  (MCSteps /     87) , (MCSteps - 10) ],  // 1
                   [ "Venus"   , ImageStockV,  CornerV ,   224 ,  (MCSteps /    224) , (MCSteps - 10) ],
                   [ "Earth"   , ImageStockE,  CornerE ,   365 ,  (MCSteps /    365) , (MCSteps - 10) ],
                   [ "Mars"    , ImageStockMa, CornerMa,   686 ,  (MCSteps /    686) , (MCSteps - 10) ],
                   [ "Ceres"   , ImageStockC,  CornerC ,  1680 ,  (MCSteps /   1680) , (MCSteps - 10) ],
                   [ "Jupiter" , ImageStockJ,  CornerJ ,  4332 ,  (MCSteps /   4332) , (MCSteps - 10) ],  // 6
                   [ "Saturn"  , ImageStockS,  CornerSa, 10755 ,  (MCSteps /  10755) , (MCSteps - 10) ],
                   [ "Uranus"  , ImageStockU,  CornerU , 30687 ,  (MCSteps /  30687) , (MCSteps - 10) ],
                   [ "Neptune" , ImageStockN,  CornerN , 60190 ,  (MCSteps /  60190) , (MCSteps - 10) ],
                   [ "Pluto"   , ImageStockPl, CornerPl, 90543 ,  (MCSteps /  90543) , (MCSteps - 10) ],  // 10
                   [ "Halley"  , ImageStockH,  CornerH , 27794 ,  (MCSteps /  27794) , (MCSteps - 10) ],
                   [ "Icarus"  , ImageStockI,  CornerI ,   409 ,  (MCSteps /    409) , (MCSteps - 10) ]   // 12
                  ]
    
    Wide = ImageStockP.width()                                     //  Alredy scaled by ImageStockP   - Planet
    High = ImageStockP.height()                                    //  
   

 
    //--------------------------------------
    // ONE ORBIT - Clear previous 
	 
	if eCheckInnerPlanets.isChecked() = 0  AND  eCheckOuterPlanets.isChecked() = 0  
	
     for OrbitPoint = 1 to MCSteps * 100                                   // 100 Orbits
     
        //Planet Current
		StepSize  = 2 
		i      = 1 + ceil(OrbitPoint * StepSize % MCSteps )            // Point in Orbit, modulo year   
        PtEX   = CornerP[i][1]           PtEY  = -CornerP[i][2]        // Jupiter Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockP.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE 
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
        
        //-------------------------------------     
        Sleep(AnimationSpeed)        
        MyApp.ProcessEvents()               ### <<< EXEC the Draw 
        
     next
    ok
    
    //--------------------------------------
	// MULTI ORBITS
    
    if eCheckInnerPlanets.isChecked() = 1  OR  eCheckOuterPlanets.isChecked() = 1  
     for OrbitPoint = 1 to MCSteps * 100                                    // Orbit Point on Ellipse
     
        //====================================
        if eCheckOuterPlanets.isChecked() =1    
                
        //Jupiter 
        StepSize  = PlanetTable[6][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year   
        PtEX   = CornerJ[i][1]           PtEY  = -CornerJ[i][2]        // Jupiter Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockJ.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE 
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
        
        //Saturn
        StepSize  = PlanetTable[7][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year       
        PtEX   = CornerSa[i][1]          PtEY  = -CornerSa[i][2]       // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockS.setGeometry(PtEX2  , PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
   
        //Uranus
        StepSize  = PlanetTable[8][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps  )        // Point in Orbit, modulo year           
        PtEX   = CornerU[i][1]           PtEY  = -CornerU[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockU.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
 
       //Neptune
        StepSize  = PlanetTable[9][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year   
        PtEX   = CornerN[i][1]           PtEY  = -CornerN[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockN.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)   

       //Pluto
        StepSize  = PlanetTable[10][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )          // Point in Orbit, modulo year           
        PtEX   = CornerPl[i][1]          PtEY  = -CornerPl[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                           // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockPl.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa) 
        
    
        //Halley
        StepSize  = PlanetTable[11][5]                                 // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year          
        PtEX   = CornerH[i][1]           PtEY  = -CornerH[i][2]        // JPlanet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockH.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)      

        ok

        //====================================================
        if eCheckInnerPlanets.isChecked() =1     
                
        //Mercury 
        StepSize  = PlanetTable[1][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year               
        PtEX   = CornerM[i][1]           PtEY  = -CornerM[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockM.setGeometry(PtEX2,   PtEY2 , Wide, High)           // Planet IMAGE 
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
        
        //Venus
        StepSize  = PlanetTable[2][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year               
        PtEX   = CornerV[i][1]           PtEY  = -CornerV[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockV.setGeometry(PtEX2  , PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
   
        //Earth
        StepSize  = PlanetTable[3][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year           
        PtEX   = CornerE[i][1]           PtEY  = -CornerE[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockE.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)                                     ### Need this setPixMap to display imageLabel 
        
        
        //Mars
        StepSize  = PlanetTable[4][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )   // Point in Orbit, modulo year     
        PtEX   = CornerMa[i][1]          PtEY  = -CornerMa[i][2]       // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockMa.setGeometry(PtEX2,  PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)   


       //Ceres
        StepSize  = PlanetTable[5][5]                                  // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year   
        PtEX   = CornerC[i][1]           PtEY  = -CornerC[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockC.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)      

       //ICARUS3
        StepSize  = PlanetTable[12][5]                                 // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year       
        PtEX   = CornerI[i][1]           PtEY  = -CornerI[i][2]        // Planet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockI.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa)  
        
        //Halley
        StepSize  = PlanetTable[11][5]                                 // Planet position  - StepSize  Jupiter=6 StepSize=6
        i         = 1 + ceil(OrbitPoint * StepSize % MCSteps )         // Point in Orbit, modulo year          
        PtEX   = CornerH[i][1]           PtEY  = -CornerH[i][2]        // JPlanet Orbit  point                 
        PtEX2  = xWidth/2  - (Wide/2)  + PtEX                          // Image Planet - Translate Co-ordinates
        PtEY2  = yHeight/2 - (High/2)  + PtEY  
        imageStockH.setGeometry(PtEX2,   PtEY2 , Wide, High)           // PLANET IMAGE  
        Canvas.setPixMap(MonaLisa) 
        
        ok
           
        //=========================================================
        //--------------------------------------------------------
        
        Sleep(AnimationSpeed)        
        MyApp.ProcessEvents()               ### <<< EXEC the Draw   

     next
    ok
    

return

###==========================================================================
###==========================================================================



###==============================================================
// PLANETARY ORBIT VALUES
// au   = 92.956 * (10^^6)  // Miles 92 million 
// c = distance FOCUS to CENTER  of ELLIPSE 'c'
// c = sqrt(a^2 - b^2)
// e = c/a 
// e = sqrt(1 - b2/a2 )  OR  sqrt(a^2 -b^2) / a
// SEMI-MINOR axis : b = a*sqrt(1 - e^2) 
//
// Planet  SemiMajorAxis Eccentricity
// Mercury  0.38709893  0.206   
// Venus    0.72333199  0.007
// Earth    1.00000011  0.017
// Mars     1.52366231  0.093
// Ceres    2.76596     0.07976
// Jupiter  5.20336301  0.048
// Saturn   9.53707032  0.056
// Uranus  19.19126393  0.046
// Neptune 30.06896348  0.010
// Pluto   39.48168677  0.248
// Halley  36.2         0.967   
// Icarus  1.0781       0.8270          Aphelion    1.9697 AU  Perihelion   0.1865 AU Inclination   22.812°
//
//------------------------------------------
// CALLED by DrawAllOrbits()
//           Figure()
  
Func GoMercury()

    PlanetName = "Mercury"
    aSMA  =  0.3871                      // a-Semi-Major-Axis  Mercury
    eCEN  =  0.206  
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockM
    if eCheckOneDraw.isChecked() = 1      // ONE Orbit - Clear previous                      // 0 = BlackOut  1 = Ovelay Orbits
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image  
    ok 
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
    
    gPlanetName = PlanetName             // Use for Animation Multi Orbit points to Corners[] valaues for Planet
    
return PlanetName 


##==============================================================
###==============================================================

Func GoVenus()

    PlanetName = "Venus"
    aSMA  = 0.72333199                   // a-Semi-Major-Axis  Venus
    eCEN  = 0.007                        // eCentricity of Orbit
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockV
    if eCheckOneDraw.isChecked() = 1                      // 0 = BlackOut  1 = Ovelay Orbits
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok  
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
    
    gPlanetName = PlanetName             // Use for Animation 
    
return PlanetName 


##==============================================================
###==============================================================

Func GoEarth()

    PlanetName = "Earth"
    aSMA  = 1.000                       // a-Semi-Major-Axis  Earth
    eCEN  = 0.017                        // eCentricity of Orbit
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
 
    imageStockP = imageStockE 
    if eCheckOneDraw.isChecked() = 1                     // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok  
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)        // MATRIX POINTS of the ORBIT are Calculated
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================

Func GoMars()

    PlanetName = "Mars"
    aSMA  = 1.52366231                   // a-Semi-Major-Axis  Mars
    eCEN  = 0.093                        // eCentricity of Orbit
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockMa
    if eCheckOneDraw.isChecked() = 1                     // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok  
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================


Func GoCeres()

    PlanetName = "Ceres"
    aSMA  = 2.76596                   // a-Semi-Major-Axis  Mars
    eCEN  = 0.07976                        // eCentricity of Orbit
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockC
    if eCheckOneDraw.isChecked() = 1                       // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok  
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================


Func GoJupiter()

    PlanetName = "Jupiter"
    aSMA  = 5.20336301                   // a-Semi-Major-Axis  Jupiter
    eCEN  = 0.048 
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockJ
    if eCheckOneDraw.isChecked() = 1                     // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok  
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================
// Saturn   9.53707032  0.056
// Uranus  19.19126393  0.046
// Neptune 30.06896348  0.010
// Pluto   39.48168677  0.248

Func GoSaturn()

    PlanetName = "Saturn"
    aSMA  =  9.53707032                      // a-Semi-Major-Axis  
    eCEN  =  0.056  
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockS
    if eCheckOneDraw.isChecked() = 1                     // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok 
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================

Func GoUranus()

    PlanetName = "Uranus"
    aSMA  =  19.19126393                      // a-Semi-Major-Axis
    eCEN  =  0.046 
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockU
    if eCheckOneDraw.isChecked() = 1                      // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok 
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================

Func GoNeptune()

    PlanetName = "Neptune"
    aSMA  =  30.06896348                      // a-Semi-Major-Axis  
    eCEN  =  0.010  
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockN
    if eCheckOneDraw.isChecked() = 1                     // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok 
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================

Func GoPluto()

    PlanetName = "Pluto"
    aSMA  =  39.48168677                      // a-Semi-Major-Axis  
    eCEN  =  0.248  
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockPl
    if eCheckOneDraw.isChecked() = 1                     // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok 
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation 
       
return PlanetName 


##==============================================================
###==============================================================

Func GoHalley()

    PlanetName = "Halley"
    aSMA  =  36.2                        // a-Semi-Major-Axis HAlley
    eCEN  =  0.967                       // eCentricity of Orbit
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockH
    if eCheckOneDraw.isChecked() = 1                   // 0 = BlackOut  1 = 
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
    ok
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName             // Use for Animation
       
return PlanetName 


##==============================================================
###==============================================================
// Icarus  1.0781       0.8270          Aphelion    1.9697 AU  Perihelion   0.1865 AU Inclination   22.812°

Func GoIcarus()

    PlanetName = "Icarus"
    aSMA  =  1.0781                      // a-Semi-Major-Axis Icarus
    eCEN  =  0.8270  
    
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)    // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5     // Focus units from CENTER (C,0) (-C,
    
    imageStockP = imageStockI
    if eCheckOneDraw.isChecked() = 1                        // 0 = BlackOut  1 = Overlay orbit ellipses
       imageStockP.setGeometry(-200, -200 , 200, 200 )      // PLANET IMAGE - Hide old image
       imageStockP = imageStockI
    ok  
    
    GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)
     
    gPlanetName = PlanetName                                 // Use for Animation of Orbit
       
return PlanetName 


##==============================================================
###==============================================================
// CALCULATE ORBITS => MATRIX MC, last values oare FOCI
// CALLED by GoPlanetName() -- GoMercury() etc sends the parameters
// Orbits rotate CounterClockWise

Func GoCalcOrbit(aSMA, eCEN, bSma, Focus, PlanetName)

h=0
v=0
Cyl = 0
decimals(6)

See ""+ PlanetName +" Called"+ nl

 // aSMA  =  5.20336301                   // a-Semi-Major-Axis  Jupiter
 // eCEN  =  0.048                        // eCentricity of Orbit
    bSMA  =  aSMA * sqrt(1 - eCEN^^2)     // b-Semi-Minor-Axis
    Focus = (aSMA^^2 - bSMA^^2)^^0.5      // Focus units from CENTER (C,0) (-C,0)  ,

    Inc   =  aSMA / DotsPerOrbit                   // Draw dots of Orbit spacing 0.001
    h     =  Focus                        // Offset from Center, where Sun is

    MC = list(1,3)                        // Matrix Array of Ellipse Points

    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
    
        // Bottom Orbit Left to Right
        for k = -aSMA to aSMA Step inc               // Points per figure. Orbits rotate CounterClockWise

           x =  k + h                                // H - horz offset to center    
           z =  j                                    // Set to 0 for 2D Trace, Flip for Back Perpective        
           y =  v +  ( ( (bSMA^^2) * ( 1  - (( (x-h)^^2 ) / (aSMA^^2))  ) )^^(1/2) )    // Vary X     
           y = -y                                         // Flip Y to do other side
                     
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next    
    
        // Top Orbit Right to Left
        for k = aSMA to -aSMA  Step -Inc             // Points per figure. Orbits rotate CounterClockWise

           x =  k + h                                // H - horz offset to center    
           z =  j                                    // Set to 0 for 2D Trace, Flip for Back Perpective        
           y =  v +  ( ( (bSMA^^2) * ( 1  - (( (x-h)^^2 ) / (aSMA^^2))  ) )^^(1/2) )    // Vary X    
                                                                         
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next
        

        
    next    
           
           // LAST 2 VALUES in MATRIX add FOCI
           MC[i][1] = focus  // FOCUS Right
           MC[i][2] = 0
           MC[i][3] = 0
           
           Add(MC, MC[i])
           i++  
           
           MC[i][1] = -focus  // FOCUS Left
           MC[i][2] = 0
           MC[i][3] = 0
           
           Add(MC, MC[i])
           i++
           
    //See "MC"  MatrixPrint(MC)    // Echo - Debug

    
    //----------------------------------------------------

    MCSteps =  (2 * aSMA / Inc) -2                             // Nbr of Points in MC array for Ellipse of Orbit
    
    See ""+ PlanetName  +" a-Semi-Major-Axis: "+ aSMA +nl
    See ""+ PlanetName  +" a-Semi-Minor-Axis: "+ bSMA +nl
    See ""+ PlanetName  +" eCentricity:       "+ eCEN +nl
    See ""+ PlanetName  +" Focus:             "+ focus +nl
    See ""+ PlanetName  +" Points on Orbit:   "+ MCSteps +nl   
    See ""+ PlanetName  +" Increment:         "+ Inc +nl
    
    win.setWindowTitle("Planet Orbits - 3D Rotations: === "+ PlanetName +"   SemiMAJORAxis: "+ aSMA +"   SemiMINORAxis: "+
                        bSMA +"   eCentricity: "+ eCEN +"   FOCUS: "+ Focus )
    


    Magnify     = 0 + eOrbitScale.text()             // From main screen editText
                              
    laSMA       = aSMA + gPositiveLog                // Log value of Orbit, to fit planets on screen
    orbitSize   =  ""+( Magnify / log(laSMA))        // Magnify=100 , 4,100 | 5,80 ok samll for Mercury, barely fits Neptune and Pluto

    if eCheckInnerPlanets.isChecked() = 0  AND  eCheckOuterPlanets.isChecked() = 0  
       orbitSize =  ""+( Magnify * 3 / aSMA)         // Single planet -- largest size, MAgnify = 100
    ok
    
    eScaleXV.setText(orbitSize)  
    eScaleYV.setText(orbitSize)  
    eScaleZV.setText(orbitSize)
            
    See ""+ PlanetName +" OrbitSize "+ orbitSize +nl
    
    gPlanetName =  PlanetName 
   
return PlanetName

##==============================================================
###==============================================================
/*
// ADD +4 for log
//          aSMA         Focu      Eccentricity
// Mercury  0.38709893   0.079743   0.206000
// Venus    0.72333199   0.005063   0.007000
// Earth    1.00000011   0.017000   0.017000
// Mars     1.52366231   0.141701   0.093000
// Ceres    2.76596      0.220613   0.079760
// Jupiter  5.20336301   0.249761   0.048000
// Saturn   9.53707032   0.534076   0.056000
// Uranus  19.19126393   0.882798   0.046000
// Neptune 30.06896348   0.300690   0.010000
// Pluto   39.48168677   9.791458   0.248000
// Halley  36.2         35.005400   0.967000
// Icarus  1.0781        0.891589   0.827000
*/
/*
https://www.omnicalculator.com/physics/orbital-velocity 
                        
Planet       Semi-major  Eccentricity  Mass 
Name         axis (au)                (Earth's masses)
Mercury      0.387        0.2056      0.0553
Venus        0.723        0.0068      0.815
Earth        1            0.0167      1
Mars         1.524        0.0934      0.107
Jupiter      5.203        0.0484      317.83
Saturn       9.537        0.0542      95.159
Uranus       19.191       0.0472      14.536
Neptune      30.069       0.0086      17.147
Pluto        39.482       0.2488      0.0021


https://rechneronline.de/g-acceleration/orbital-speed.php


Orbital velocities of the Planets[6]
Planet  Orbital
velocity
Mercury 47.9 km/s (29.8 mi/s)
Venus   35.0 km/s (21.7 mi/s)
Earth   29.8 km/s (18.5 mi/s)
Mars    24.1 km/s (15.0 mi/s)
Jupiter 13.1 km/s (8.1 mi/s)
Saturn   9.7 km/s (6.0 mi/s)
Uranus   6.8 km/s (4.2 mi/s)
Neptune  5.4 km/s (3.4 mi/s)
Pluto   17,096      10,623   per/hour 3600 
         4.7488      2.9508  


Mercury:     87.97 days (  0.2 years)
Venus :     224.70 days (  0.6 years)
Earth:      365.26 days (  1 year)
Mars:       686.98 days (  1.9 years)
Jupiter:  4,332.82 days ( 11.9 years)
Saturn:  10,755.70 days ( 29.5 years)
Uranus:  30,687.15 days ( 84 years)
Neptune: 60,190.03 days (164.8 years)
Pluto                    247.9 years 

VelocityOfOrbit = (G*MS/r)^^0.5
G  =  6.67   * 10^^-11          //  Gravity Constant: m3/(kg*s2 )   
MS =  1.9885 * 10^^30           //  Sun Mass: kg 
r  =  1.49   * 10^^11          //  Earth Orbit Radius: m
      
Speed = 29,835 m/s

*/
