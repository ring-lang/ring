### "Calculus - Conics, Parametric Equations and Polar Coordinates"
### Bert Mariani  2024-02-16
###
### IMPORTANT (^^) brakets around the ^^ Power for precedence , 
### Ring not following Bermuda = Brackets Multi Div Add Sub
//-----------------------------------------------------------------
// ELLIPSE                 +(x^2/a^2) + (y^2/b^2) = 1      
// HYPERBOLA               +(x^2/a^2) - (y^2/b^2) = 1      
//
// PARABOLA                  y = a(x-h)^2 + k              
// PARABOLA                  x = a(y-k)^2 + h              
//
// ELLIPSOID               +(x^2/a^2) + (y^2/b^2) + (z^2/c^2) = 1
// HYPERBOLOID-ONE-SHEET   +(x^2/a^2) + (y^2/b^2) - (z^2/c^2) = 1
// HYPERBOLOID-TWO-SHEET   -(x^2/a^2) - (y^2/b^2) + (z^2/c^2) = 1
// ELLIPTIC-CONE           +(x^2/a^2) + (y^2/b^2) - (z^2)     = 0
// ELLIPTIC-PARABOLOID     +(x^2/a^2) + (y^2/b^2) - (z)       = 0
// HYPERBOLIC-PARABOLID    -(x^2/a^2) + (y^2/b^2) - (z)       = 0
//
//---------------------------------------------------------------


load "stdlibcore.ring"
load "lightguilib.ring"
Load "MatrixLib.ring"
   
//================================================
decimals(4) 
EN           = 2.71828  // e = Euler's Number
PI           = 3.14159
IncAngleX    = 0       // Rotation Increment
IncAngleY    = 0
IncAngleZ    = 0
RotateAngle  = 45   // =15 Rotation Increment

xPos    = 100   ### Canvas position on Screen
yPos    = 25
xWidth  = 1200  ### Canvas size on Screen
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

ePolA    = null   // Polar Eq text
eSinB    = null   // Sin Eq text
eCosC    = null   // Cos Eq text

eCheckDraw     = null  // Draw 1 image, no overlaps
eCheckDefaults = null  // Default Parameters for Figures Drawn

MC     = list(1,3)     // Matrix Array of Ellipsoid Points
Points = list(1,3)

comboShapeType = null
ConicEquation  = "Figure"

ImageScale     = 1
PosFigX        = 0 
PosFigY        = 500


imageStockP    = null      // Figure
imageCircle    = null
imageEllipse   = null
imageParabola  = null
imageHyperbola = null
imageCone      = null
imageCylinder  = null

imageBlank     = null
imageConics    = null

imageEllipsoid            = null
imageSpheroid             = null
imageEllipticalCone       = null     
imageEllipticalParaboloid = null

imageHyperbolicParaboloid = null
imageHyperboloidOneSheet  = null
imageHyperboloidTwoSheet  = null


###-------------------------------
### Define Colours, Pens, Brushes

colorGreen   = new qcolor() { setrgb(000,255,000,255) }
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ### 64 faint line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave

penWhiteThin  = new qpen() { setcolor(colorWhite)   setwidth(2) }
penGreen     = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed       = new qpen() { setcolor(colorRed)     setwidth(2) }
penBlue      = new qpen() { setcolor(colorBlue)    setwidth(2) }
penWhite     = new qpen() { setcolor(colorWhite)   setwidth(2) }
penYellow    = new qpen() { setcolor(colorYellow)  setwidth(2) }
penGray      = new qpen() { setcolor(colorGray)    setwidth(2) }
penMagenta   = new qpen() { setcolor(colorMagenta) setwidth(2) }
penBlack     = new qpen() { setcolor(colorBlack)   setwidth(2) }

brushSR     = new qbrush() { setstyle(1)  setcolor (colorRed)}      ### Red
brushSG     = new qbrush() { setstyle(1)  setcolor (colorGreen)}    ### Green
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlue)}     ### Blue
brushSY     = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSGR    = new qbrush() { setstyle(1)  setcolor (colorGray)}     ### 
brushSW     = new qbrush() { setstyle(1)  setcolor (colorWhite)}    ### 
brushSM     = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  ### 

brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty

penArray   = [penYellow,  penRed, penBlue, penGreen]
penPointer = 0   // Which color to cycle next to draw figure


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
        setWindowTitle("Calculus -Conics, Parametric Equations and Polar Coordinates")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size
        setWinIcon(self,"EllipticalCone.png")

        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               translate(xWidth/2 , yHeight/2)     ### TRANSLATE CO-ORD x,y -- 0,0 MAPS TO 300,300
               #endpaint()                         ### This will Stop the Painting   
            }

            setPixMap(MonaLisa)
        }
	
        //-----------------------------------
		
             // Figure - 200x200
            imageStockP = new qlabel(win) 
            {   image = new qPixMap("Conics.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
 				setGeometry( 150, 135, image.Width(),image.Height() )   // INITAIL STARTING SCREEN
            }	
			
            imageBlank = new qlabel(win) 
            {   image = new qPixMap("Blank.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
 				setGeometry( -250, -250, image.Width(),image.Height() )
            }			
			
            imageConics = new qlabel(win) 
            {   image = new qPixMap("QuadraticSurface.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
 				setGeometry( -800, -800, image.Width(),image.Height() )
            }
			
            imageCircle = new qlabel(win) 
            {   image = new qPixMap("Circle.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
 				setGeometry( -250, -250, image.Width(),image.Height() )
            }				

            imageEllipse = new qlabel(win) 
            {   image = new qPixMap("Ellipse.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			

           imageCone = new qlabel(win) 
            {   image = new qPixMap("Cone.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			
			
            imageEllipsoid = new qlabel(win) 
            {   image = new qPixMap("Ellipsoid.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			

            imageSpheroid = new qlabel(win) 
            {   image = new qPixMap("Spheroid.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }
			
            imageEllipticalCone = new qlabel(win) 
            {   image = new qPixMap("EllipticalCone.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			

            imageCylinder = new qlabel(win) 
            {   image = new qPixMap("Cylinder.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }	

            imageEllipticalParaboloid = new qlabel(win) 
            {   image = new qPixMap("EllipticalParaboloid.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			
				

            imageHyperbola = new qlabel(win) 
            {   image = new qPixMap("Hyperbola.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			
		

            imageHyperbolicParaboloid = new qlabel(win) 
            {   image = new qPixMap("HyperbolicParaboloid.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			
		

            imageHyperboloidOneSheet = new qlabel(win) 
            {   image = new qPixMap("HyperboloidOneSheet.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			


            imageHyperboloidTwoSheet = new qlabel(win) 
            {   image = new qPixMap("HyperboloidTwoSheet.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }		

            imageParabola = new qlabel(win) 
            {   image = new qPixMap("Parabola.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -250, -250, image.Width(),image.Height() )				
            }			
	
			
			

        //-------------------------------------
		
        comboShapeType = new QComboBox(win) 
        {
            setgeometry( 0, 2, 140, 20)
            comboList = ["Figure",
			             "Ellipse","Circle","Parabola","Hyperbola",
						 
			             "C-Ellipsoid","P-Ellipsoid2",
						 "C-Spheroid","P-Spheroid2",
						 "P-Cylinder2",
						 "P-EllipticalCone2",
						 "P-EllipticalParaboloid2",
						 
                         "P-HyperbolicParaboloid2",
						 "P-HyperbolicOneSheet2",
						 "P-HyperbolicTwoSheet2",
						 
                         "P-Circle","P-Signature","P-Square","P-SunPoints",
                         "P-Umbrella","P-PinWheel","P-Turbine","P-Butterfly",
						 
						 
						 
                         "Plane"
                        ]
            for x in comboList additem(x,0) next   			
        }
        
        btnCS = new qPushButton(win) { setGeometry( 150, 2, 90, 20)  setText("Start/Clear")  setStyleSheet("background-color: aqua")
                                     setClickEvent("StartClearScreen()") 
                                   }
        btnDM = new qPushButton(win) { setGeometry( 250, 2, 70, 20)  setText("DrawMatrix") setStyleSheet("background-color: aqua")
                                     setClickEvent("DrawMatrix()") 
                                   }

        //-----------                
        lValA  =  new qLabel(win)     { setGeometry(330,  2, 70, 20)  setText("X-a-Width")  setStyleSheet("background-color: yellow")}
        eValA  =  new qLineEdit(win)  { setGeometry(330, 20, 70, 20)  setText("5") }          
 
        lValB  =  new qLabel(win)     { setGeometry(410,  2, 70, 20)  setText("Y-b-Height")  setStyleSheet("background-color: yellow")}
        eValB  =  new qLineEdit(win)  { setGeometry(410, 20, 70, 20)  setText("3") }           

        lValC  =  new qLabel(win)     { setGeometry(490,  2, 70, 20)  setText("Z-c-Depth")  setStyleSheet("background-color: yellow")}
        eValC  =  new qLineEdit(win)  { setGeometry(490, 20, 70, 20)  setText("1") }           
        //-----------
        lValH  =  new qLabel(win)     { setGeometry(570,  2, 70, 20)  setText("X-h-CenterH")  setStyleSheet("background-color: yellow")}
        eValH  =  new qLineEdit(win)  { setGeometry(570, 20, 70, 20)  setText("0") }           
 
        lValV  =  new qLabel(win)     { setGeometry(650,  2, 70, 20)  setText("Y-k-CenterV")  setStyleSheet("background-color: yellow")}
        eValV  =  new qLineEdit(win)  { setGeometry(650, 20, 70, 20)  setText("0") }           

        lValD  =  new qLabel(win)     { setGeometry(730,  2, 70, 20)  setText("Z-d-CenterD:")  setStyleSheet("background-color: yellow")}
        eValD  =  new qLineEdit(win)  { setGeometry(730, 20, 70, 20)  setText("0") }           
        //-----------
        lValCyl  =  new qLabel(win)     { setGeometry(810,  2, 70, 20)  setText("Cylinders")  setStyleSheet("background-color: yellow")}
        eValCyl  =  new qLineEdit(win)  { setGeometry(810, 20, 70, 20)  setText("0") }           

        lValInc  =  new qLabel(win)     { setGeometry(890,  2, 70, 20)  setText("Inc-Space")  setStyleSheet("background-color: yellow")}
        eValInc  =  new qLineEdit(win)  { setGeometry(890, 20, 70, 20)  setText("0.008") }          
    
        //------------
        // EQUATION label boxed: Polar, Sine, Cos formats
        
        lPolA  =  new qLabel(win)     { setGeometry(150, 60,  100, 20)  setText("Polar-Equation")  setStyleSheet("background-color: yellow")}
        ePolA  =  new qLineEdit(win)  { setGeometry(240, 60, 280, 20)  setText("r = ---") }          
 
        lSinB  =  new qLabel(win)     { setGeometry(150, 80,  100, 20)  setText("Sin-Equation")    setStyleSheet("background-color: yellow")}
        eSinB  =  new qLineEdit(win)  { setGeometry(240, 80, 280, 20)  setText("s = ---") }           

        lCosC  =  new qLabel(win)     { setGeometry(150, 100,  100, 20)  setText("Cos-Equation")   setStyleSheet("background-color: yellow")}
        eCosC  =  new qLineEdit(win)  { setGeometry(240, 100, 280, 20)  setText("m = ---") }           
        

        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for ROTATION ANGLES
        
        // Rx = (eRotXV.text()
        // Ry = (eRotYV.text()
        // Rz = (eRotZV.text() 
        
        lRotation =  new qLabel(win)  { setgeometry( 0, 30 , 60, 20) settext("Rotate") setStyleSheet("background-color: yellow")}
        lRotX  =  new qLabel(win)     { setgeometry( 0, 50 , 30, 20) settext("X:")   setStyleSheet("background-color: yellow")}
        eRotXV =  new qlineedit(win)  { setgeometry(30, 50 , 30, 20) settext("0") }        
          
        lRotY  =  new qLabel(win)     { setgeometry( 0, 70 , 30, 20) settext("Y:")   setStyleSheet("background-color: yellow")}
        eRotYV =  new qlineedit(win)  { setgeometry(30, 70 , 30, 20) settext("0") }

        lRotZ  =  new qLabel(win)     { setgeometry( 0, 90 , 30, 20) settext("Z:")   setStyleSheet("background-color: yellow")}
        eRotZV =  new qlineedit(win)  { setgeometry(30, 90 , 30, 20) settext("0") }        
           
        ###---------------------
        ### INCREMENT ANGELE EDIT

        iRotation =  new qLabel(win)  { setgeometry( 70, 30 , 45, 20)   settext("Inc") setStyleSheet("background-color: yellow")}       
         
         iRotXV =  new qlineedit(win)  { setgeometry( 70, 50 , 45, 20)  settext("0") }     // was 110
         iRotYV =  new qlineedit(win)  { setgeometry( 70, 70 , 45, 20)  settext("0") }  
         iRotZV =  new qlineedit(win)  { setgeometry( 70, 90 , 45, 20)  settext("0") }   

         eCheckDefaults =  new qCheckBox(win)  { setgeometry( 150, 30 , 90, 20) settext("Default")     setStyleSheet("background-color: yellow") setchecked(true)}         
         eCheckDraw     =  new qCheckBox(win)  { setgeometry( 250, 30 , 70, 20) settext("1 Draw")      setStyleSheet("background-color: yellow") }         
                                                          
        ###------------------------------------------------
        ### Draw LABELS and LINEEDIT for SCALE
        
        //Sx = eScaleXV.text()  
        //Sy = eScaleYV.text()  
        //Sz = eScaleZV.text()
        
         lScale   =  new qLabel(win)  { setgeometry( 0, 120 , 80, 20)  settext("Scale 0.1-10") setStyleSheet("background-color: yellow")}

         lScaleX  =  new qLabel(win)     { setgeometry( 0, 140 , 30, 20)  settext("X:")  setStyleSheet("background-color: yellow")}
         eScaleXV =  new qlineedit(win)  { setgeometry(30, 140 , 30, 20)  settext("50") }           

         lScaleY  =  new qLabel(win)     { setgeometry( 0, 160 , 30, 20)  settext("Y:")  setStyleSheet("background-color: yellow")}
         eScaleYV =  new qlineedit(win)  { setgeometry(30, 160 , 30, 20)  settext("50") }

         lScaleZ  =  new qLabel(win)     { setgeometry( 0, 180 , 30, 20)  settext("Z:")  setStyleSheet("background-color: yellow")}
         eScaleZV =  new qlineedit(win)  { setgeometry(30, 180 , 30, 20)  settext("50") }           
               
 
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
// START - CLEAR-SCREEN - FIGURE

Func StartClearScreen() 

   for i = 1 to len(MC)  // lenght of MC matrix list(200,3)
      del(MC,i)
   next
   
   Points = list(1,3)
   MC     = list(1,3)      // Matrix Array of Ellipsoid Points 
   Points = MC
   
  
   RotateAngleX = 0
   RotateAngleY = 0
   RotateAngleZ = 0
   
   IncAngleX    = 0
   IncAngleY    = 0
   IncAngleZ    = 0
   
   
   Figure()                            // <<<=== CALL,  Draw Mini-Conic
   
   MonaLisa.fill(colorBlack)           // <<<=== BLANK OUT OLD IMAGE !!!
   Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
   MyApp.ProcessEvents()               ### <<< EXEC the Draw
   
   DrawMAtrix()                        // <<<=== CALL
   
return 

###==========================================================================
###==========================================================================
// Called by ClearScreen()
// comboList = ["Figure","Ellipsoid","Cone","EllipticParaboloid","HyperboloidOneSheet","HyperbolicParaboloid","HyperboloidTwoSheet"]
   
Func Figure()

    Wide = ImageStockP.width()                               //  Alredy scaled by ImageStockP   - Planet
    High = ImageStockP.height()
    imageStockP.setGeometry( -800, -800 , Wide, High)        // BLANK OUT OLD Figure IMAGE 

    a   = number( (eValA.text()) )    // = null   // X - Horz Width
    b   = number( (eValB.text()) )    // = null   // Y - Vert Height
    c   = number( (eValC.text()) )    // = null   // Z - Depth
    h   = number( (eValH.text()) )    // = null   // X - Center Horz
    k   = number( (eValV.text()) )    // = null   // Y - Center Vert
    d   = number( (eValD.text()) )    // = null   // Z - Center Depth
    Cyl = number( (eValCyl.text()) )  // = null   // Increament - dots to draw
    Inc = number( (eValInc.text()) )  // = null   // Cylinder - multiples
     
    ConicEquation = comboShapeType.currentText()
    
    if     ConicEquation  = "Figure"              GoEllipsoid(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageEllipse   
	elseif ConicEquation  = "Ellipse"               GoEllipse(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageEllipse
    elseif ConicEquation  = "Circle"                 GoCircle(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageCircle
    elseif ConicEquation  = "Parabola"             GoParabola(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageParabola           
	elseif ConicEquation  = "Hyperbola"           GoHyperbola(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageHyperbola
	
	elseif ConicEquation  = "C-Spheroid"           GoSpheroid(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageSpheroid
	elseif ConicEquation  = "P-Spheroid2"        GoPSpheroid2(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageSpheroid
	elseif ConicEquation  = "P-Cylinder2"        GoPCylinder2(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageCylinder
	
    elseif ConicEquation  = "C-Ellipsoid"         GoEllipsoid(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageEllipsoid
    elseif ConicEquation  = "P-Ellipsoid2"      GoPEllipsoid2(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageEllipsoid	
	elseif ConicEquation  = "P-EllipticalCone2"      GoPCone2(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageEllipticalCone

	elseif ConicEquation  = "P-EllipticalParaboloid2"    GoPEllipticalParaboloid2(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageEllipticalParaboloid	  
	elseif ConicEquation  = "P-HyperbolicParaboloid2"    GoPHyperbolicParaboloid2(a,b,c,h,k,d,Cyl,Inc)	 imageStockP = imageHyperbolicParaboloid	
    elseif ConicEquation  = "P-HyperbolicOneSheet2"        GoPHyperbolicOneSheet2(a,b,c,h,k,d,Cyl,Inc)	 imageStockP = imageHyperboloidOneSheet
	elseif ConicEquation  = "P-HyperbolicTwoSheet2"        GoPHyperbolicTwoSheet2(a,b,c,h,k,d,Cyl,Inc)	 imageStockP = imageHyperboloidTwoSheet
	
    elseif ConicEquation  = "P-Circle"              GoPCircle(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-Signature"        GoPSignature(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-Square"              GoPSquare(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-SunPoints"        GoPSunPoints(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-Umbrella"          GoPUmbrella(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-PinWheel"          GoPPinWheel(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-Turbine"            GoPTurbine(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    elseif ConicEquation  = "P-Butterfly"        GoPButterfly(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
																					 
    elseif   ConicEquation  = "Plane"                 GoPlane(a,b,c,h,k,d,Cyl,Inc)   imageStockP = imageBlank
    ok
    	
    //------------------------------
    Wide = ImageStockP.width()                               //  Alredy scaled by ImageStockP   - Planet
    High = ImageStockP.height()
  
    imageStockP.setGeometry( PosFigX, PosFigY , Wide, High)  // Figure IMAGE 
    Canvas.setPixMap(MonaLisa)                               ### Need this setPixMap to display imageLabel        
    MyApp.ProcessEvents()                                    ### <<< EXEC the Draw 	
    
return

###==========================================================================
###==========================================================================
// Click Button

Func DrawMatrix()

    DrawMatrixRepeat()
	
	//--------------------------------------------
	// "ELLIPSOID" or "SPHEROID"
	
	if ConicEquation  = "C-Ellipsoid" || ConicEquation  = "C-Spheroid"
	   eRotXV.setText("90")  eRotYV.setText("0")  // eRotZV.setText("0")
	   iRotXV.setText("10")  iRotYV.setText("0")  // iRotZV.setText("0")
	   times = 90 / 10
	   for i = 1 to times       
	      DrawMatrixRepeat()
	   next
	   
	   eRotXV.setText("90")  eRotYV.setText("90")  // eRotZV.setText("0")
	   iRotXV.setText("0")   iRotYV.setText("10")  // iRotZV.setText("0")
	   times = 90 / 10
	   for i = 1 to times       
	      DrawMatrixRepeat()
	   next
	   
	   return
	ok	
     
	//-----------------------------------------
	
return


//=================================================
// DRAW-MATRIX Points Generated

Func DrawMatrixRepeat()           

    VShape   = Points
    
    m = 1                                   // 100 //  m = SCALAr MULTIPLY when Value 0 <--> 1
    ShapeObj  = ScalarMultiply(m,VShape)
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

            //-------------------------------------
            // SCALE
            
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
            // REFLECTION  
            
            Hx = eShearXV.text()  
            Hy = eShearYV.text()  
            Hz = eShearZV.text()
            
            H = [[  1,  Hx,  Hx, 0],          // Shear XYZ Distort
                 [ Hy,   1,  Hy, 0], 
                 [ Hz,  Hz,   1, 0], 
                 [  0,   0,   0, 1]]
             
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
    
            CH = MatrixMultiply(H,CZ)    // SHEAR -- Distort
            CR = MatrixMultiply(RF,CH)   // REFLECTION -1, 0, 1
    
         // CT = MatrixAdd(TA,CR)        // TRANSLATE ADD      -- Change Position
            CT = MatrixMultiply(TM,CR)   // TRANSLATE MULTIPLY -- Change Position
                
            FC = CT                      // FINAL FC transform - SRT        
            //---------------------------
            
            Corners[i][1] = FC[1][1]     // Build Corners array for each Point
            Corners[i][2] = FC[2][1]     // Save For each of 8 Points, Each Corner Point after Transform xyz
            Corners[i][3] = FC[3][1]
         
    next

        //======================================================
        // x-axis through  30◦, => 210 tp flip
        // y-axis through −70◦,
        // z-axis through −27◦.


        DoDraw(Corners)           // ===>>>   Comment Out --- stops at 258 iterations -- Stack ???

        RotateAngleX = (iRotXV.text() * PI/180)      // Degrees to Radians INCREMENT-TEXT >
        RotateAngleY = (iRotYV.text() * PI/180)
        RotateAngleZ = (iRotZV.text() * PI/180)

        IncAngleX += RotateAngleX   // Radians: Rotation Increment for NEXT CLICK on MENU
        IncAngleY += RotateAngleY   //          Rotation Increment for NEXT CLICK on MENU
        IncAngleZ += RotateAngleZ   //          Rotation Increment for NEXT CLICK on MENU
        

        //tRotXV.settext( string( IncAngleX * 180/PI) )  // TotalAngle: Radian to Angle to String
        //tRotYV.settext( string( IncAngleY * 180/PI) )
        //tRotZV.settext( string( IncAngleZ * 180/PI) )
        	
return


###==========================================================================
###==========================================================================
//
// Draw 8 Corner Points -- 12 Lines of New Position of Cube
// Note in Computer Graphics XY-Horz-Vert: Vert-0 is Top of screen, Paper Vert-0 is Bottom  Z is to the BAck
//
// xWidth  = 900   ### Canvas size on Screen
// yHeight = 900 
//--------------------------------------------

Func DoDraw(Corn)

    //------------------------------------------
    //Draw 3D Axis
    //    MonaLisa.fill(colorBlack)                    // ===<<< BLANK OUT OLD IMAGE !!!
    
    if eCheckDraw.isChecked() = 1
       MonaLisa.fill(colorBlack)                       // ===<<< BLANK OUT OLD IMAGE !!!
    ok

    daVinci.setpen(penWhiteThin)
    daVinci.drawLine(   0, -300,    0,  300 )    //  Vert ### Draw NEW Line
    daVinci.drawLine(-300,    0,  300,    0 )    //  Horz
    daVinci.drawLine( 250, -250, -250,  250 )    // -45  250, -350, -250,  350 
    //daVinci.drawLine( 250,  250, -250, -250 )    // +45

    //----------------------------------------------------
    // DRAW LINE FROM <--> TO 
    
    
    penPointer++
    if penPointer > 4  
       penPointer = 1 
    ok
    usePen = penArray[penPointer]
    
    daVinci.setpen(usePen)         // penYellow)
    for i = 1 to len(Corn) -1      
        FlipX1 = -Corn[i][1]     FlipY1 = -Corn[i][2]
        FlipX2 = -Corn[i+1][1]   FlipY2 = -Corn[i+1][2]
        if ConicEquation  = "Plane"
           daVinci.drawLine( Corn[i][1] , FlipY1, Corn[i+1][1] , FlipY2 )       // From xy TO xy  
        ok
            
        

    next
    
    for i = 1 to len(Corn) -4  
    
        if ConicEquation  = "Plane"
          daVinci.setBrush(brushSM)   // Magenta intersity 64 = Faint
          daVinci.drawPolygon( [ [Corn[i+0][1], Corn[i+0][2]], [Corn[i+1][1], Corn[i+1][2]], [Corn[i+2][1], Corn[i+2][2]], [Corn[i+3][1], Corn[i+3][2]] ], 0)  // Yello 14 85
        ok
    next        
    
    //-----------------------------------------------------
    // DRAW POINT AT    
    daVinci.setpen(usePen)       // penYellow)
    for i = 1 to len( Corn )   
        FlipX1 = -Corn[i][1]     FlipY1 =  -Corn[i][2]    
        daVinci.drawPoint( Corn[i][1], FlipY1)   // Dray XY Point
    next

    //-----------------------------------------------------
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw
	


return

###==========================================================================
###==========================================================================

###==========================================================================
###==========================================================================
/// DefaultParameters for Figure to look reasonable

Func GoDefaultParams(a2,b2,c2, h2,v2,d2, Cyl2,Inc2, sx2,sy2,sz2)

    if eCheckDefaults.isChecked() = 1
    
        a   =  a2    //  5     //  (eValA.text()) )    // X - Horz Width
        b   =  b2    //  3     //  (eValB.text()) )    // Y - Vert Height
        c   =  c2    //  1     //  (eValC.text()) )    // Z - Depth
        h   =  h2    //  0     //  (eValH.text()) )    // X - Center Horz
        k   =  v2    //  0     //  (eValV.text()) )    // Y - Center Vert
        d   =  d2    //  0     //  (eValD.text()) )    // Z - Center Depth
        Cyl =  Cyl2  //  0     //  (eValCyl.text()) )  // Increament - dots to draw
        Inc =  Inc2  //  0.01  //  (eValInc.text()) )  // = null   // Cylinder - multiples
        sx  =  sx2   //  0     //   Scale X
        sy  =  sy2   //  0     //   Scale y
        sz  =  sz2   //  0     //   Scale Z
    
        eValA.setText(""+a)     eValB.setText(""+b)     eValC.setText(""+c)         // X-a-Width        
        eValH.setText(""+h)     eValV.setText(""+k)     eValD.setText(""+d)         // X-h-Center
        eValCyl.setText(""+Cyl) eValInc.setText(""+Inc)                             // CylMultiple, Inc-Space   
        eScaleXV.setText(""+sx) eScaleYV.setText(""+sy) eScaleZV.setText(""+sz)     // Scale X
    ok

return

###==========================================================================
###==========================================================================
###==========================================================================
 
###==========================================================================
###==========================================================================
// ELLIPSE    +(x^2/a^2) + (y^2/b^2) = 1      // +((x-h)^2/a^2) + ((y-k)^2/b^2) = 1
//
//             ( (y^2)/(b^2) )   =       1 - ( (x^2)/(a^2) )
//			   (y^^2)/(b^^2)   =       1 - ( (x^^2)/(a^^2) )
//			   (y^^2)          =     ( 1 - ( (x^^2)/(a^^2) ) ) * (b^^2)
//			    y              =   ( ( 1 - ( (x^^2)/(a^^2) ) ) * (b^^2) )^^(1/2)
//				y              = ( ( ( 1 - ( (x^^2)/(a^^2) ) ) * (b^^2) )^^(1/2) )
//  
//-------------------------------------------------------------------------------------                                      a                    b                      									 

Func GoEllipse(a,b,c,h,k,d,Cyl,Inc)     
		
    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			
			if eCheckDefaults.isChecked() = 1  &&        
			   ConicEquation  != "Circle"      &&        
			   ConicEquation  != "C-Spheroid"  &&
			   ConicEquation  != "C-Ellipsoid"
			
			    //---------------------------
				a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.004             // eValCyl eValInc
				sx =  50 sy = 50    sz  = 50     // Scale   X,Y,Z
				
	            eRotXV.setText("0")  eRotYV.setText("0")   eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")   iRotZV.setText("0")				
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
			
			
                // Display Equation
                ePolA.setText("(x^2/a^2) + (y^2/b^2) - (z/c) = 1")
                eSinB.setText("---")
                eCosC.setText("y = ((((-(x^^2)/( a^^2)) + 1 + z/c )*(b^^2))^^(1/2)) ") 	
	
                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok
    
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1                          // Number of cyclinder 5
        for  period = -a to a Step inc               // Points per figure
              
           x =  period                               // h - horz offset to center    
           z =  j                                    // Set to 0 for 2D Trace, Flip for Back Perpective          
		   y = k + ( ( ( 1 - ( (x^^2)/(a^^2) ) ) * (b^^2) )^^(1/2) )
		  
		   x = period +h                             // X offset by h
		   
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next
		
        //------------------------------------------
        for  period = -a to a  Step inc              // Points per figure

           x =  period                               // H - horz offset to center       
           z =  j    
		   y = -k + ( ( ( 1 - ( (x^^2)/(a^^2) ) ) * (b^^2) )^^(1/2) )
		   y = -y                                    // Flip Y to do other side
                    
		   x = period +h                             // X offset by h		

           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next
        //-----------------
		
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return

//===========================================================================
//===========================================================================
// CIRCLE is an Ellipse with a = b

Func GoCircle(a,b,c,h,k,d,Cyl,Inc)     
		

			if eCheckDefaults.isChecked() = 1  
			
				a  =  4  b  =  4     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.004              // eValCyl eValInc
				sx =  50 sy = 50    sz  = 50    // Scale   X,Y,Z

	            eRotXV.setText("0")  eRotYV.setText("0")   eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")   iRotZV.setText("0")	
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
			
			
                // Display Equation
                ePolA.setText("(x^2/a^2) + (y^2/b^2) = 1")
                eSinB.setText("---")
                eCosC.setText("y = ((((1 -(x^^2)/( a^^2)))*(b^^2))^^(1/2)) ") 	
	
                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok
			
    GoEllipse(a,b,c,h,k,d,Cyl,Inc) 
	
return
 
###==========================================================================
###==========================================================================
//
// PARABOLA: The general equation of a Parabola is: 
//    y = a(x-h)^2 + k    or 
//    x = a(y-k)^2 + h    where (h,k) denotes the vertex. 
//
// The standard equation of a regular parabola is
//    y^2 = 4ax.
//
//   y^2 = 4px           p=Point
//   y  = (4 * p * x)^^(1/2)
//   y  = (4 * a * x)^^(1/2)
//
//-----------------------------------------
 
Func GoParabola(a,b,c,h,k,d,Cyl,Inc)     

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1 &&  ConicEquation != "EllipticalParaboloid"
			
				a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  1     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.004              // eValCyl eValInc
				sx =  150 sy = 50    sz  = 50    // Scale   X,Y,Z

	            eRotXV.setText("0")  eRotYV.setText("0")   eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")   iRotZV.setText("0")	
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
			ok
			
                // Display Equation
                ePolA.setText("y^2 = 4px ")
                eSinB.setText("x = b*(y-k)^2 + h")
                eCosC.setText("y = a*(x-h)^2 + k") 	
	
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

    
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step inc                    // Points per figure
              
           x =  period                               // h - horz offset to center    
           z =  j                                    // Set to 0 for 2D Trace, Flip for Back Perpective         
		   y =  k + a*(x^^2)
		  
		   x = period +h
		  
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next
		
  
        //------------------------------------------
        for  period = -a to a  Step inc               // Points per figure

           x =  period                                // H - horz offset to center       
           z =  j                   
		   y =  k + a*(x^^2)
		   y = -y                                     // Flip Y to do other side
                     
           x = period +h
		   
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                        // Index counter
        next
    //--------------------------------------------
     
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return


###==========================================================================
###==========================================================================
// HYPERBOLA: The standard form of the equation of a Hyperbola with center (0,0) 
// Transverse axis on the X-axis->  Transverse axis on the Y-axis-^ is
//      x^2 - y^2 = 1              y^2 - x^2= 1
//      a^2   b^2                  b^2   a^2
// 
//	 c2 = a^2 + b^2    Asymtotes X-axis  y = +- bx    Y-axis  y = +- ax
//
//  (y^2/b^2) - (x^2/a^2) = 1 + (z/c)              
//                                                                                          
//  (y^^2/b^^2) =    ((x^^2)/(a^^2))  + 1 + z/c 
//  (y^^2)      =   (((x^^2)/( a^^2)) + 1 + z/c )*(b^^2)      
//   y          = (((((x^^2)/( a^^2)) + 1 + z/c )*(b^^2))^^(1/2)) 
//
//   x=0   (c/b^2)*(y^2) = z
//   y=0   (c/a^2)*(x^2) = z 
//                                            a                    b                      									 
//-------------------------------------
 
Func GoHyperbola(a,b,c,h,k,d,Cyl,Inc)     

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
			
				a  =  3  b  =  4     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.004             // eValCyl eValInc
				sx =  50 sy = 50    sz  = 50     // Scale   X,Y,Z

	            eRotXV.setText("0")  eRotYV.setText("0")   eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")   iRotZV.setText("0")	
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
			ok
			
                // Display Equation
                ePolA.setText("x^2/a^2 - y^2/b^2  -z/c = 1")
                eSinB.setText("---")
                eCosC.setText("y = ((((x^^2)/( a^^2)) +1 + z/c )*(b^^2))^^(1/2)") 	
	
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

    
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step inc                    // Points per figure
              
           x =  period                               // h - horz offset to center    
           z =  j                                    // Set to 0 for 2D Trace, Flip for Back Perpective           
		   y =  k + (((((x^^2)/( a^^2)) + 1 + z/c )*(b^^2))^^(1/2)) 
		  
		   x = period +h 
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next
		
        //------------------------------------------
        for  period = -a to a  Step inc              // Points per figure

           x =  period                               // H - horz offset to center       
           z =  j                    
		   y =  k + (((((x^^2)/( a^^2)) + 1 + z/c )*(b^^2))^^(1/2)) 
		   y = -y                                    // Flip Y to do other side
                     
           x = period +h
		   
           MC[i][1] = x
           MC[i][2] = y
           MC[i][3] = z
           
           Add(MC, MC[i])
           i++                                       // Index counter
        next
        //-----------------
		
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return


###==========================================================================
###==========================================================================
// ELLIPSOID  +(x^2/a^2) + (y^2/b^2) + (z^2/c^2) = 1
//.CALL Elipse then use TRANSFORM to rotate about the X and Y Axis
//----------------------------------


Func GoEllipsoid(a,b,c,h,k,d,Cyl,Inc)

			if eCheckDefaults.isChecked() = 1
			
				a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.01              // eValCyl eValInc
				sx =  50  sy = 50    sz  = 50    // Scale   X,Y,Z

	            eRotXV.setText("0")  eRotYV.setText("0")   eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")   iRotZV.setText("0")	
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
			
			
                // Display Equation
                ePolA.setText("x^2/a^2 + y^2/b^2 + z^2/c^2 =1 ")
                eSinB.setText("---")
                eCosC.setText("y = k +(((1 -(x^^2/a^^2) - (z^^2/c^^2) +1 ) * b^^2 )^^(1/2)") 	
	
                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok
			

     GoEllipse(a,b,c,h,k,d,Cyl,Inc)

return



//===========================================================================
//===========================================================================
// SPHEROID -- SAME AS Ellipsoid, a = b = c  ALL radius are Equal

Func GoSpheroid(a,b,c,h,k,d,Cyl,Inc)


			if eCheckDefaults.isChecked() = 1
			
				a  =  4  b  =  4     c   =  4    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.01              // eValCyl eValInc
				sx =  50  sy = 50    sz  = 50    // Scale   X,Y,Z

	            eRotXV.setText("0")  eRotYV.setText("0")   eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")   iRotZV.setText("0")	
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			
                // Display Equation
                ePolA.setText("x^2/a^2 + y^2/b^2 + z^2/c^2 = 1 ")
                eSinB.setText("---")
                eCosC.setText("y = k +(((1 -(x^^2/a^^2) - (z^^2/c^^2) +1 ) * b^^2 )^^(1/2)") 	
	
                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

            ok
			
    GoEllipse(a,b,c,h,k,d,Cyl,Inc)

return


###==============================================================
###==============================================================

###==============================================================
###==============================================================

###==============================================================
// POLAR COORDINATES - Notes
// 
// Theta   r = 2*cos(Theta)  PI/180 Degrees to Radians , 180/PI  Radians to Degrees
//     0   2         00
//  Pi/6   s3  sqrt  30
//  Pi/4   s2        45
//  Pi/3   1         60
//  Pi/2   0         90
// 2Pi/3  -1        120
// 3Pi/4  -s2       135
// 5Pi/6  -s3       150
//  Pi 2  -2        180
//
//  x 0-13 y=0-13       x -1to+1  y -1to+1    x -3.5to+3,5  y -3.5to3.5
//  x = t + sin(5*t)    x = sin(9*t)          x = 2.3 * cos(10*t) + cos(23*t)
//  y = t + sin(6*t)    y = sin(10*t)         y = 2.3 * sin(10*t) - sin(23*t)
//
//
//  Polar:      r = sin(8*t/5)          n-revolutions = 5 0< t < 10PI
//  Cartesian:  x = r*cos(t)            y = r*sin(t)
//              x = sin(8*t/5)*cos(t)   y = sin(8*t/5)*sin(t)
//
//----------------------------------------------------------------


//=================================================================
// ConicEquation  = "P-Circle" 
// Figure 8 p661 Stewart Calculus -CIRCLE

Func GoPCircle(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			    if eCheckDefaults.isChecked() = 1
				
					a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  v  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.01              // eValCyl eValInc
					sx = 100 sy = 100    sz  = 100    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,v,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok			
				
			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")				

                // Display Equation Parameters
                ePolA.setText("r = a*cos(t)  // a=radius, t=theta")
                eSinB.setText("x = 2*cos(t)")
                eCosC.setText("y = 2*sin(t)")
				
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for period = -a to a  Step Inc                    // Points per figure
            
            t = period 
            x = 2*cos(t)    // a*cos(t) // a=b circle
            y = 2*sin(t)    // b*sin(t) // a>b ellipse horz  // a<b allipse vert
            z = j

             x = x + h
			 y = y + k
			 
            //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return

//=================================================================
// ConicEquation  = "P-Signature" 
// Figure 10 p643 Stewart Calculus ----------- 

Func GoPSignature(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			    if eCheckDefaults.isChecked() = 1				
					a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.01              // eValCyl eValInc
					sx = 50  sy = 50     sz  = 50    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok						
  
			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.setText("---")
                eSinB.setText("x = t + sin(5*t)")
                eCosC.setText("y = t + sin(6*t)")

    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure
		              
            t =  period
            x = t + sin(5*t) 
            y = t + sin(6*t)
            z = j
			
            x = x + k
			y = y + h
			
            //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

     
    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   

//=================================================================
// ConicEquation  = "P-Square"
// Figure 11 p643 Stewart Calculus 

Func GoPSquare(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points
	
			    if eCheckDefaults.isChecked() = 1
				
					a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.002              // eValCyl eValInc
					sx = 150 sy = 150    sz  = 150    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok				
 
			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.setText("---")
                eSinB.setText("x = sin(9*t)")
                eCosC.setText("y = sin(10*t)")

    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	

    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure
				        
            t = period
            x = sin(9*t)
            y = sin(10*t)
            z = j

            x = x + k
			y = y + h
			
           //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
	See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return    

//================================================================
// ConicEquation  = "P-SunPoints"
// Figure 11 p643 Stewart Calculus 

Func GoPSunPoints(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			    if eCheckDefaults.isChecked() = 1
				
					a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.002             // eValCyl eValInc
					sx = 100 sy = 100    sz  = 100    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok				
 
			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.setText("---")
                eSinB.setText("x = 2.3 * cos(10*t) + cos(23*t)")
                eCosC.setText("y = 2.3 * sin(10*t) - sin(23*t)")
				
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

					
				
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure
			             
            t =  period
            x = 2.3 * cos(10*t) + cos(23*t)
            y = 2.3 * sin(10*t) - sin(23*t)
            z = j

            x = x + k
			y = y + h
			
           //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return   	


//========================================================================           
// Figure 16 p665 Stewart Calculus  
// ConicEquation  = "P-Umbrella" 

Func GoPUmbrella(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			    if eCheckDefaults.isChecked() = 1
				
					a  =  7  b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.002              // eValCyl eValInc
					sx = 250 sy = 250    sz  = 250    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok				
 
			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.setText("r =    sin(2.5t)^^3   +  cos(2.5t)^^3 ")
                eSinB.setText("x = ( (sin(2.5*t)^^3) + (cos(2.5*t)^^3) ) *cos(t) ")
                eCosC.setText("y = ( (sin(2.5*t)^^3) + (cos(2.5*t)^^3) ) *sin(t)")

    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure
	   
            t = period
            x = ( (sin(2.5*t)^^3) + (cos(2.5*t)^^3) ) *cos(t) 
            y = ( (sin(2.5*t)^^3) + (cos(2.5*t)^^3) ) *sin(t)
            z = j		

            x = x + k
			y = y + h
			
           //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	


//========================================================================
// Figure 17 p665 Stewart Calculus
// ConicEquation  = "P-PinWheel" 
 
Func GoPPinWheel(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			   if eCheckDefaults.isChecked() = 1
				
					a  =  16 b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.005              // eValCyl eValInc
					sx = 100 sy = 100    sz  = 100    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok	

			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.setText("r =  2 + sin(2.4*t)^^3)")
                eSinB.setText("x = (2 + sin(2.4*t)^^3) * cos(t)")
                eCosC.setText("y = (2 + sin(2.4*t)^^3) * sin(t)")
 
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	 
				
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure 
	
            t = period
            x = (2 + sin(2.4*t)^^3)*cos(t) 
            y = (2 + sin(2.4*t)^^3)*sin(t)
            z = j      

            x = x + k
			y = y + h
			
           //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return 			

//========================================================================
// p-686 Figure-18 Stewart Calculus 7th-----------
// ConicEquation  = "P-Turbine" 

Func GoPTurbine(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			   if eCheckDefaults.isChecked() = 1
				
					a  =  16 b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.005              // eValCyl eValInc
					sx = 200 sy = 200    sz  = 200    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok			
 
			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.setText("r = sin(8t/5)")
                eSinB.setText("x = sin(8*t/5) * cos(t)")
                eCosC.setText("y = sin(8*t/5) * sin(t)")
 
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	 
				
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure 
			
            t = period
            x = sin(8*t/5)*cos(t) 
            y = sin(8*t/5)*sin(t)
            z = j 

            x = x + k
			y = y + h
			
           //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return 			

//======================================================================== 
// Figure 10-2-18 p717-ex56 Anton Calculus-10th   //  EN EulersNumbere = 2.71828 
// ConicEquation  = "P-Butterfly"  
 
Func GoPButterfly(a,b,c,h,k,d,Cyl,Inc)

    EN = 2.71828
    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			    if eCheckDefaults.isChecked() = 1
				
					a  =  16 b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.005              // eValCyl eValInc
					sx = 100 sy = 100    sz  = 100    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok	

			    eRotXV.setText("0")  eRotYV.setText("0")  eRotZV.setText("0")
	            iRotXV.setText("0")  iRotYV.setText("0")  iRotZV.setText("0")	
				
                // Display Equation
                ePolA.settext("r =  e^^cost     − 2*cos(4*t) + sin(t/4)^^3 ")
                eSinB.setText("x = EN^^(cos(t)) − 2*cos(4*t) + sin(t/4)^^3  * cos(t)")
                eCosC.setText("y = EN^^(cos(t)) − 2*cos(4*t) + sin(t/4)^^3  * sin(t)")
 
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	 

    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
        for  period = -a to a  Step Inc                    // Points per figure 
			 
            t = period

            // Simplify complex equation into small parts
			//     p              q            r               s / m
			// x = EN^^(cos(t)) − 2*cos(4*t) + sin(t/4)^^3   * cos(t)  
			// y = EN^^(cos(t)) − 2*cos(4*t) + sin(t/4)^^3   * sin(t) 
         
            p = EN^^(cos(t))
            q = 2*cos(4*t)
            
            r = sin(t/4)^^3 
            s = sin(t)
            m = cos(t)          
            
            x = (p - q + r) * m     
            y = (p - q + r) * s
            
            z = j   		

            x = x + k
			y = y + h
			
          //----------------------------------

			MC[i][1] = x
			MC[i][2] = y
			MC[i][3] = z
           
			Add(MC, MC[i])
			i++                                       // Index counter
        next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return 		

###==============================================================
###==============================================================

//---------------------------------------
// https://mathworld.wolfram.com/Two-SheetedHyperboloid.html
//  
//  A two-sheeted circular hyperboloid oriented along the z-axis has Cartesian coordinates equation
// 
//  (x^2)/(a^2)+(y^2)/(a^2)-(z^2)/(c^2)= -1
//  
//  The parametric equations of the top sheet are
//
//   x	=	a sinh u cos v	 (2)
//   y	=	a sinh u sin v	 (3)
//   z	=	c cosh u	     (4)
// for u in (-infty,infty) and v in [0,pi) (Gray 1997, p. 406).
//
// RING
// sin(x) Returns the sine of an angle of x radians
// cos(x) Returns the cosine of an angle of x radians
//
// sinh(x) Returns the hyperbolic sine of x radians
// cosh(x) Returns the hyperbolic cosine of x radians
//------------------------------------------------------ 	

Func GoPHyperboloidTwoSheets(a,b,c,h,k,d,Cyl,Inc)


    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			   if eCheckDefaults.isChecked() = 1
				
					a  =  16 b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.005              // eValCyl eValInc
					sx = 200 sy = 200    sz  = 200    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok			
            
                // Display Equation
                ePolA.setText("r = x^2)/(a^2)+(y^2)/(a^2)-(z^2)/(c^2)= -1")
                eSinB.setText("x = a * sinh(u) * cos(v)")
                eCosC.setText("y = a * sinh(u) * sin(v)")
 
    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl

	 			
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
	 for v = 0 to PI Step 0.2
        for  period = -a to a  Step Inc                    // Points per figure 
		

				u = period
				x = a * sinh(u) * cos(v)
				y = a * sinh(u) * sin(v)
			//	z = j 
				z =	c *cosh(u)

				x = x + k
				y = y + h
			
				//----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
           
				Add(MC, MC[i])			
			i++                                       // Index counter
        next
		
	  next  // v	
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl	
    Points = MC

return 			

//===========================================================================
//===========================================================================
// https://sites.science.oregonstate.edu/math/home/programs/undergrad/CalculusQuestStudyGuides/vcalc/parsurf/parsurf.html
//
// SPHEROID -- SAME AS Ellipsoid, a = b = c
//   r(u,v) =  < x(u,v), y(u,v), z(u,v) >
//   r(t)   =  < x(t),   y(t),   z(t)   >   where a<=t<=b
//   
// ----------------------------------
//   A natural example is a SPHERE. 
//   It takes two pieces of information to describe a point on a sphere: 
//   the latitude and longitude. 

//   Let u, with 0<=u<=2*pi  be the longitude. 
//   Let v, with 0<=v<=  pi  be the latitude. 
````````
//   Here u and v correspond, respectively, to the the spherical coordinates theta and phi. 
//   Using the formulas for spherical coordinates we have
//
//   x = a*sin(v)*cos(u)    into paper
//   y = a*sin(v)*sin(u)    horz paper
//   z = a*cos(v)           vert paper
//   
//   This is an example of surface that CANNOT be described by a single function z=f(x,y). 
//   A sphere of radius a centered at the origin can be defined by the relationship
//   x^2 + y^2 +Z^2 = a^2
//
//   The top half of the sphere is defined by the surface
//   z  = +( a^2 -x^2 -y^2)^1/2
//
//   and the bottom half is the defined by the surface
//   z  = -( a^2 -x^2 -y^2)^1/2
// ------------------------------------------  
//
//   A second example is a cone, as shown in the figure CONE
//	 The height is 3, the base radius is 2, and the cone is centered at the origin.
//
//   Two parameters are required to define a point on the surface.
//	 We choose them to be u, the height from the base, and v, the angle with respect to the x-axis. 
//	 v is the same as the polar angle theta. We can describe any point on the surface by:
//
//   x = r*cos(v)    0<=v<=2*pi
//	 y = r*sin(v)    0<=v<=2*pi
//	 z = u           0<=u<=3
//	 
//	 For a cone the radius and the height from the base are related by a linear function. 
//	 In this example, 
//	 the radius is 2 when the height is 0 
//	 and radius is 0 when the height is 3. 
//	 If we let u denote the height, r=2-2u/3. Hence, we have
//
//   x = (2 - 2u/3)*cos(v)
//	 y = (2 - 2u/3)*sin(v)
//	 z =  u
//
//-------------------------------------

Func GoPSpheroid2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  3  b  =  3     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 100 sy = 100    sz  = 100    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("50")  eRotYV.setText("60")  eRotZV.setText("135")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z = a*cos(v)")
                eSinB.setText("x = a*sin(v)*cos(u)")
                eCosC.setText("y = a*sin(v)*sin(u)")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok

//   Let u, with 0<=u<=2*pi  be the longitude. 
//   Let v, with 0<=v<=  pi  be the latitude. 
	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
	
          for u = 0 to 2*PI Step Inc	
             for v = 0 to PI Step Inc * 2	  
				x = a*sin(v)*cos(u)
				y = a*sin(v)*sin(u)
				z = a*cos(v)
			
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	

//================================================================
//================================================================
// Parameterization:
// The parametric equations for a hyperbolic paraboloid are:
// (x(u,v) = u)
// (y(u,v) = v)
// (z(u,v) = uv)
// Choose a Range:
// Select appropriate ranges for the parameters (u) and (v). 
// For example, you might choose (u) and (v) to vary from -2 to 2.
//-----------------------------------------------------------------

Func GoPCylinder2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 50  sy = 50     sz  =  50    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("35")  eRotYV.setText("45")  eRotZV.setText("135")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z =  u")
                eSinB.setText("x = a*cos(v)")
                eCosC.setText("y = b*sin(v) ")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok

	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
			
          for u = 0 to 2*PI Step Inc * 2	
             for v = 0 to 2* PI Step Inc 	
			 
				x = a*cos(v)                 // cylinder
				y = b*sin(v)                 // 
				z = u                        //
						
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	


###==========================================================================
###==========================================================================


Func GoPCone2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  2  b  =  2     c   =  2    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 100 sy = 100    sz  = 50    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("50")  eRotYV.setText("60")  eRotZV.setText("135")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z =  c * u")
                eSinB.setText("x = (a - (a*u/3)) * cos(v)")
                eCosC.setText("y = (b - (b*u/3)) * sin(v)")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok
           
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5

          for v = 0 to 2*PI Step Inc	  
			 for u = 0 to 3 Step Inc
				
				x = (a - (a*u/3))*cos(v)       // Cone v, 3 is fixed
			    y = (b - (b*u/3))*sin(v)
				z =  c*u
				
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	


//================================================================
//================================================================
// Parameterization:
// The parametric equations for a hyperbolic paraboloid are:
// (x(u,v) = u)
// (y(u,v) = v)
// (z(u,v) = uv)
// Choose a Range:
// Select appropriate ranges for the parameters (u) and (v). 
// For example, you might choose (u) and (v) to vary from -2 to 2.
//----------------------------------------------------------------

Func GoPHyperbolicParaboloid2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  1  b  =  1     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 100 sy =  50    sz  =  50    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("240") eRotYV.setText("45")  eRotZV.setText("330")
	            iRotXV.setText("0")   iRotYV.setText("0")   iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z = c*(u^^2 - v^^2)")
                eSinB.setText("x = a*u ")
                eCosC.setText("y = b*v")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok

	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
			
          for v = -2 to 2 Step Inc * 2	  
			 for u = -2 to 2 Step Inc * 2
				
			//	x = a * u              // saddle 4 points
			//  y = a * v
			//	z = a * (u * v)
			
			//  x = a/2*(u+v)          // the double family of straight lines
            //  y = b/2*(u-v)
			//	z = c  *(u*v)
			    
				x = a*u                // the double family of generatrix parabolas 
				y = b*v
				z = c*((u^^2) - (v^^2) )
			
							
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	


//================================================================
//================================================================


Func GoPHyperbolicOneSheet2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  2  b  =  2     c   =  2    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 50  sy =  50    sz  = 50    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("50")  eRotYV.setText("60")  eRotZV.setText("135")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z = c * u")
                eSinB.setText("x = a * ((1 + (u^^2))^^(1/2)) * cos(v)")
                eCosC.setText("y = b * ((1 + (u^^2))^^(1/2)) * sin(v)")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok


	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5

          for u = -PI to PI     Step Inc * 2	
             for v = -PI to PI  Step Inc                    // To complete the rotation 
				
				x = a * ( (1 + (u^^2))^^(1/2) ) * cos(v)  // Alt 1 Range u -2 to 2 , v -4 to 4
			    y = b * ( (1 + (u^^2))^^(1/2) ) * sin(v)
				z = c * u
				
			//	x = a * (cos(v) / cos(u))                  // Alt2
			//	y = b * (sin(v) / cos(u))
			//	z = c * (tan(u))
				
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	


###==========================================================================
###==========================================================================

Func GoPHyperbolicTwoSheet2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  2  b  =  2     c   =  2    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 50  sy =  50    sz  = 50    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("50")  eRotYV.setText("60")  eRotZV.setText("135")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z = c * u")
                eSinB.setText("x = a * (((u^^2)-1)^^(1/2)) * cos(v)")
                eCosC.setText("y = b * (((u^^2)-1)^^(1/2)) * sin(v)")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok


	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
	
          for u = -PI to PI     Step Inc * 2	
             for v = -PI to PI  Step Inc                    // To complete the rotation 
				
				x = a * ( ((u^^2)-1)^^(1/2) ) * cos(v)  // Alt 1 Range u -2 to 2 , v -4 to 4
			    y = b * ( ((u^^2)-1)^^(1/2) ) * sin(v)
				z = c * u
				
			//	x = a * (tan(u) * cos(v))                  // Alt2
			//	y = b * (tan(u) * sin(v))
			//	z = c / (cos(u))
				
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	

###==========================================================================
###==========================================================================

Func GoPEllipticalParaboloid2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  2  b  =  2     c   =  2    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 50  sy =  50    sz  = 50    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("50")  eRotYV.setText("60")  eRotZV.setText("135")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z =   c*u")
                eSinB.setText("x = ((a*u)^^(1/2)) * cos(v)")
                eCosC.setText("x = ((b*u)^^(1/2)) * sin(v)")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok


	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5

          for u = -PI to PI     Step Inc * 2	
             for v = -PI to PI  Step Inc                    // To complete the rotation 
				
                x = ((a*u)^^(1/2)) * cos(v)
				y = ((b*u)^^(1/2)) * sin(v)
				z =   c*u
				
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	

###==========================================================================
###==========================================================================

Func GoPEllipsoid2(a,b,c,h,k,d,Cyl,Inc)     // GoPUmbrella

    MC = list(1,3)   // Matrix Array of Ellipsoid Points

			if eCheckDefaults.isChecked() = 1
				
				a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
				h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
				Cyl=  0  Inc=  0.04              // eValCyl eValInc
				sx = 100 sy =  100    sz  = 100    // Scale   X,Y,Z
				
				GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
	
			    eRotXV.setText("45")  eRotYV.setText("60")  eRotZV.setText("330")
	            iRotXV.setText("0")  iRotYV.setText("0")    iRotZV.setText("0")	
            
                // Display Equation
                ePolA.setText("z = c*sin(v)")
                eSinB.setText("x = a*cos(v) * cos(u)")
                eCosC.setText("y = b*cos(v) * sin(u)")

                See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl
            ok


	                
    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1 // (5*inc )              // Number of cyclinder 5
	
          for u = -PI to PI     Step Inc 	
             for v = -PI to PI  Step Inc * 4                   // To complete the rotation 
				
                x = a*cos(v) * cos(u)
				y = b*cos(v) * sin(u)
				z = c*sin(v)
				
     			x = x + k
				y = y + h
				
			   //----------------------------------

				MC[i][1] = x
				MC[i][2] = y
				MC[i][3] = z
			   
				Add(MC, MC[i])
				i++                                       // Index counter
			next
		  next
		
	    //--------------------------------------
           
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC

return   	


###==========================================================================
###==========================================================================

// PLANE SHEET 4 CORNER POINTS

Func GoPlane(a,b,c,h,k,d,Cyl,Inc)

    MC = list(1,3)   // Matrix Array of Ellipsoid Points
	MP = list(1,3)   // Points x,y,z
	
			    if eCheckDefaults.isChecked() = 1
				
					a  =  5  b  =  3     c   =  1    // eValA   X,Y,Z
					h  =  0  k  =  0     d   =  0    // eValH   X,Y,Z
					Cyl=  0  Inc=  0.01              // eValCyl eValInc
					sx = 30  sy = 30     sz  =  30    // Scale   X,Y,Z
					
					GoDefaultParams(a,b,c, h,k,d, Cyl,Inc,  sx,sy,sz)   // Update Display Values
				ok
				
                // Display Equation
                ePolA.setText("---")
                eSinB.setText("x = -a to +a + h")
                eCosC.setText("y = -a to +a + v")				

    See "ConicEq: "+ ConicEquation +" a= "+ a +" b= "+  b +" c= "+ c +" h= "+ h +" k= "+ k +" d= "+ d +" C= "+ Cyl +" I= "+ Inc  +nl


    i = 1                                            // Index counter
    for j = 0 to Cyl Step 1                          // Number of cyclinder 5
        for  period = -a to a  Step inc              // Points per figure

           //-1-----------------
           z =  j
           x =  ( period )                              // H - horz offset to center      
           y =  ( period )                              // (1,1)          

           x = x + h
           y = y + k		   

           MP[i][1] = x
           MP[i][2] = y
           MP[i][3] = z
           
           Add(MC, MP[i])
           //i++                                       // Index counter
           //-2-----------------
		   
           z =  j
           x = -( period )                            // H - horz offset to center       
           y =  ( period )                             // (-1,1)
 
           x = x + h
           y = y + k
		   
           MP[i][1] = x
           MP[i][2] = y
           MP[i][3] = z
           
           Add(MC, MP[i])
           //i++                                       // Index counter

           //-3------------------
		   
           z =  j
           x = -( period )                               // H - horz offset to center       
           y = -( period )                              // (-1,-1)
 
           x = x + h
           y = y + k 

           MP[i][1] = x
           MP[i][2] = y
           MP[i][3] = z
           
           Add(MC, MP[i])
           //i++                                       // Index counter

           //-4-------------------
		   
           z =  j
           x =  ( period )                           // H - horz offset to center       
           y = -( period )                            // (1,-1)
 
           x = x + h
           y = y + k
		   
           MP[i][1] = x
           MP[i][2] = y
           MP[i][3] = z
           
           Add(MC, MP[i])
           //i++   
           //-------------------                         // Index counter
		   
        next            
         
    next

    //See "MC"  MatrixPrint(MC)    // Echo - Debug
    See "New MC size: "+ len(MC) +nl+nl
    Points = MC


return

###==============================================================
###==============================================================
//
// ELLIPSOID               +(x^2/a^2) + (y^2/b^2) + (z^2/c^2) = 1
// HYPERBOLOID-ONE-SHEET   +(x^2/a^2) + (y^2/b^2) - (z^2/c^2) = 1
// HYPERBOLOID-TWO-SHEET   -(x^2/a^2) - (y^2/b^2) + (z^2/c^2) = 1
// ELLIPTIC-CONE           +(x^2/a^2) + (y^2/b^2) - (z^2)     = 0
// ELLIPTIC-PARABOLOID     +(x^2/a^2) + (y^2/b^2) - (z)       = 0
// HYPERBOLIC-PARABOLID    -(x^2/a^2) + (y^2/b^2) - (z)       = 0
//
//
//-----------------
//
////Parabolas with vertex (h, k) and axis parallel to x-axis
//(y − k)^2 =  4p(x − h) [Opens right] (12)
//(y − k)^2 = −4p(x − h) [Opens left]  (13)
//
//
//Parabolas with vertex (h, k) and axis parallel to y-axis
//(x − h)^2 =  4p(y − k) [Opens up]   (14)
//(x − h)^2 = −4p(y − k) [Opens down] (15)
//
//-----------------
//
//Ellipse with center (h, k) and major axis parallel to x-axis
//(x − h)^2  +  (y − k)^2  = 1    [b < a] (16)
//  a^2           b^2 
//
//
//Ellipse with center (h, k) and major axis parallel to y-axis
//(x − h)^2  +  (y − k)^2  = 1    [b < a] (17)
//  b^2           a^2
//
//-----------------
//
//Hyperbola with center (h, k) and focal axis parallel to x-axis
//(x − h)^2  -  (y − k)^2  = 1    (18)
//  a^2           b^2
// 
// 
//Hyperbola with center (h, k) and focal axis parallel to y-axis
//(y − k)^2  -  ( x − h)^2  = 1    (19)
//  a^2            b^2          
//  
//---------------------  
//  
//
//
////=======================================================================
//// Parabolic cylinders
////      z = x^2                         Doesn’t involve y. 
////                                      This means that any vertical plane with 
////                                      equation y − k (parallel to the xz-plane) 
////                                      intersects the graph in a curve with equation z − x2.
////
////
////      x^2 + y^2 =1                    When you are dealing with surfaces, 
////      y^2 + z^2 =1                    it is important to recognize that an equation like x^2 + y2^ = 1 
////                                      represents a CYLINDER and not a CIRCLE. The trace of the cylinder
////                                      x^2 + y2 = 1 in the xy-plane is the circle 
////                                      with equations x^2 + y2 = 1, z − 0.
////
////-----------------------------------
//// Elliptic Cone  (Traianle Cone)
//     z^2/c^2 = x^2/a^2 + y^2/b^2      Horizontal traces are Ellipses.
//                                      Vertical traces in the planes x − k and y − k 
//                                      are Hyperbolas if k ± 0 
//                                      but are pairs of Lines if m = 0.
//          
//----------------------------------         
// Elliptic Paraboloid  (Rounded Ice Cream Cone)
//      x^2/a^2 + y^2/b^2   = z/c       Horizontal traces are Ellipses.
//                                      Vertical traces are Parabolas.
//                                      The variable raised to the first power 
//                                      indicates the axis of the Paraboloid.    
//  
// **
// Hyperbolic Paraboloid (Saddle)       Horizontal traces are Hyperbolas.   
//      x^2/a^2 - y^2/b^2   = z/c       Vertical traces are Parabolas
//                                      The case where c , 0 is illustrated.
//
//                           
//-----------------------------------                           
// Ellipsoid   (Football)
//      x^2/a^2 + y^2/b^2 + z^2/c^2 = 1  All traces are Ellipses. 
//                                       If a − b − c, the ellipsoid is a Sphere. 
//
// **                                      
// Hyperboloid of One Sheet ( Nuclear Cooling Tower)
//      x^2/a^2 + y^2/b^2 - z^2/c^2 = 1  Horizontal traces are Ellipses.                          
//                                       Vertical traces are Hyperbolas.
//                                       The axis of symmetry corresponds to the 
//                                       variable whose coefficient is negative.
//
// **     
// Hyperboloid of Two Sheets  ( 2 Saucers )
//      -x^2/a^2 - y^2/b^2 + z^2/c^2 = 1 Horizontal traces in z − k are Ellipses 
//                                       if k > c or k , 2c.
//                                       Vertical traces are Hyperbolas.     
//                                       The two minus signs indicate two sheets.
//
//
//
//
// https://mathcurve.com/surfaces.gb/paraboloidhyperbolic/paraboloidhyperbolic.shtml
//
// https://mathcurve.com/surfaces.gb/hyperboloid/hyperboloid1.shtml   OneSheet
//
// https://mathcurve.com/surfaces.gb/ellipsoid/ellipsoidrevol.shtml
//
// https://mathcurve.com/surfaces.gb/ellipsoid/ellipsoid.shtml
//
//https://mathcurve.com/surfaces.gb/cylindrederevolution/cylindrederevolution.shtml
//
// https://mathcurve.com/surfaces.gb/conederevolution/conederevolution.shtml
//
// https://mathcurve.com/surfaces.gb/coneelliptique/coneelliptique.shtml
//
// https://mathcurve.com/surfaces.gb/hyperboloid/hyperboloid2.shtml
//
// https://mathcurve.com/surfaces.gb/paraboloidelliptic/paraboloidelliptic.shtml
//
// https://mathcurve.com/surfaces.gb/ellipsoid/ellipsoid.shtml
