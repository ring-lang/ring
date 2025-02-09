### Planet Retrograde Patterns of Orbits
### Bert Mariani 2025-01-31
###
### Pattern of Planets' Orbit around the Sun
###=============================================================

load "stdlibcore.ring"
load "lightguilib.ring"

//================================================

decimals(6)  // 4
PI         = 3.14159265
ImageScale = 1

xPos    = 100        ### Canvas position on Screen
yPos    = 25
xWidth  = 1600       ### Canvas size on Screen
yHeight = 1000  
  
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
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ###  64 faint  line
colorWhite2  = new qcolor() { setrgb(255,255,255,255) }  ### 255 bright line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave
colorAqua    = new qcolor() { setrgb(000,255,255,255) }  ### 255 full

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(2) }  //
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(2) } 
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(1) }
penWhite2   = new qpen() { setcolor(colorWhite2)  setwidth(2) }  //
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(1) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(1) }
penAqua     = new qpen() { setcolor(colorAqua)    setwidth(1) }
penBlue4    = new qpen() { setcolor(colorBlue)    setwidth(4) }  //

brushSR     = new qbrush() { setstyle(1)  setcolor (colorRed)}      ### Red
brushSG     = new qbrush() { setstyle(1)  setcolor (colorGreen)}    ### Green
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlue)}     ### Blue
brushSY     = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSGR    = new qbrush() { setstyle(1)  setcolor (colorGray)}     ### 
brushSW     = new qbrush() { setstyle(1)  setcolor (colorWhite)}    ### 
brushSM     = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  ### 

brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty

//=========================================
// START the APP

 myApp = new qApp 
 {
    win = new qWidget()
    {
        setWindowTitle("   Planet Retrograde Patterns of Orbits")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        Canvas = new qlabel(win)
        {
            ### daVinci Paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)
            
            daVinci = new qpainter()
            {
               begin(MonaLisa)                       ### Canvas: xWidth=1800  yHeight=1000  
               translate(xWidth/2 , yHeight/2)       ### TRANSLATE CO-ORD x,y 0,0 Maps Center OFFSET  TO 900,500
               //setCompositionMode(26)              ###  THIS is the MAGIC - Erase Old Line when Redrawn
               //endpaint()                          ### This will Stop the Painting   
               
            }

            //================================================
            // IMAGES 
            
            //------------------------------------
            // Splash on Starting
            imageSplash = new qlabel(win)                             
            {
                image = new qPixMap("Sun-75.png")
                
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2        
                setGeometry( xPos, yPos, image.Width(), image.Height())   
            }  
            
            
            imageE = new qlabel(win)                             
            {  
                image = new qPixMap("Earth50.png")
                
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2        
                setGeometry( xPos, yPos, image.Width(), image.Height())   
            } 

            imageM = new qlabel(win)                             
            { 
               image = new qPixMap("Mercury50.png")
                
               setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
               xPos = (xWidth  - image.width()  ) / 2  
               yPos = (yHeight - image.height() ) / 2        
               setGeometry( xPos, yPos, image.Width(), image.Height())   
           }   

            imageX = new qlabel(win)                             
            { 
               image = new qPixMap("Mercury50.png")
                
               setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
               xPos = (xWidth  - image.width()  ) / 2  
               yPos = (yHeight - image.height() ) / 2        
               setGeometry( xPos, yPos, image.Width(), image.Height())   
           }		   
            
            //-------------------------------
            setPixMap(MonaLisa)    // Draw It - Black
        }    
        
        //======================================================    
        
        comboPlanets = new QComboBox(win) 
        {
            setgeometry( 2, 2, 95, 20)
            comboList = ["Mercury","Venus","Mars","Jupiter","Saturn","Uranus","Neptune",
                         "Saturn-Neptune","Jupiter-Mars-Earth",
                        ]
            for x in comboList additem(x,0) next                    
        } 
        
        btnKL  = new qPushButton(win) { setGeometry( 100, 2, 110, 20)   
                                        setText("Draw-Orbits")  
                                        setStyleSheet("background-color: aqua")
                                        setClickEvent("DrawOrbits()")  
                                      }     
        ###-----------------------------------
        ### Font Type and Size

            oFont = new qfont("Calibri",12,0,0)
            setfont(oFont)
		
        //------------------------------		

        lTitle  =  new qLabel(win) { setgeometry( 420, 2 , 500, 30)  
                                     settext("   Pattern of Planet Orbits around the Sun")  
                                     setStyleSheet("background-color: white")
									 setFont(new qFont("Calibri",14,100,0))
                                    }	

        lPlanet  =  new qLabel(win) { setgeometry( 940, 2, 240, 30)  
                                     settext("   Planet Name")  
                                     setStyleSheet("background-color: white")
									 setFont(new qFont("Calibri",14,100,0))
                                    }									
        //----------------------------------------------------------------                                                              
      show()        
    }
    exec()
 }

return

###==============================================================
###==============================================================       

###==========================================================================
// Clear Images
Func  ClearImages()

    See "ClearImages() "+nl
	
   imageE.setGeometry(-900, -900, 50, 50 )  // Move Off Screen
   imageM.setGeometry(-900, -900, 50, 50 )  // 
   imageX.setGeometry(-900, -900, 50, 50 )  // 

    MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw
        
return

###==========================================================================

###==============================================================
###==============================================================   
//    Planet      E-Days      Radius -AU  E-Years   DegreesPerDay
//    Mercury     87.970097   0.387099    0.240842  4.092299682
//    Venus      224.702872   0.723332    0.615186  1.602115704
//    Earth      365.260060   1.000000    1.000000  0.985599137
//    Mars       686.965935   1.523662    1.880759  0.524043452
//    Jupiter   4335.391310   5.203363   11.869330  0.083037487
//    Saturn   10757.827893   9.537070   29.452521  0.033464004
//    Uranus   30708.420720  19.191264   84.072772  0.011723169
//    Neptune  60225.414984  30.068963  164.883686  0.005977543
// 
//    Planet     Major        Minor      Eccenttricit
//  ["Mercury",   57.909231,   56.671577, 0.20564,   
//  ["Venus",    108.209525,  108.207038, 0.00678,  
//  ["Earth",    149.598319,  149.577432, 0.01671,   
//  ["Mars",     227.943771,  226.947566, 0.09339,   
//  ["Jupiter",  778.342761,  777.430569, 0.04840,   
//  ["Saturn",  1426.714893, 1424.640932, 0.05390,  
//  ["Uranus",  2870.633541, 2867.425958, 0.04726,  
//  ["Neptune", 4498.393012, 4498.227045, 0.00859,  

//========================================================
//========================================================

Func DrawOrbits()

See "DrawOrbits():" +nl

   ClearImages()

   PlanetName = comboPlanets.currentText()
   See "comboPanets: "+PlanetName +nl
   
//          Planet,     E-Days       Radius -AU   E-Years    DegreesPerDay  DaysPerDeg   NbrOrbits 
Planet = [[ "Mercury",    87.970097,   0.387099,    0.240842,  4.092299682,   0.244361381,  365 ],   
          [ "Venus",     224.702872,   0.723332,    0.615186,  1.602115704,   0.624174644,  365 ],   
          [ "Earth",     365.260060,   1.000000,    1.000000,  0.985599137,   1.014611278,  365 ],   
          [ "Mars",      686.965935,   1.523662,    1.880759,  0.524043452,   1.908238708,  668 ],   
          [ "Jupiter",  4335.391310,   5.203363,   11.869330,  0.083037487,  12.04275364,  4335 ],   
          [ "Saturn",  10757.827893,   9.537070,   29.452521,  0.033464004,  29.88285526, 10757 ],   
          [ "Uranus",  30708.420720,  19.191264,   84.072772,  0.011723169,  85.30116867, 30708 ],   
          [ "Neptune", 60225.414984,  30.068963,  164.883686,  0.005977543, 167.2928194,  60225 ]]   
          
  //---------------------------------------------------------------------
  //  
  if PlanetName = "Mercury"    PNbrE = 1   PNbrM = 3       NbrOrbits =   365 *6 ok
  if PlanetName = "Venus"      PNbrE = 2   PNbrM = 3       NbrOrbits =   365 *8 ok
  if PlanetName = "Earth"      PNbrE = 3   PNbrM = 4       NbrOrbits =   365    ok
  if PlanetName = "Mars"       PNbrE = 3   PNbrM = 4       NbrOrbits =   668 *8 ok
  if PlanetName = "Jupiter"    PNbrE = 3   PNbrM = 5       NbrOrbits =  4335    ok
  if PlanetName = "Saturn"     PNbrE = 3   PNbrM = 6       NbrOrbits = 10757    ok
  if PlanetName = "Uranus"     PNbrE = 3   PNbrM = 7       NbrOrbits = 30708    ok
  if PlanetName = "Neptune"    PNbrE = 3   PNbrM = 8       NbrOrbits = 60225    ok
  if PlanetName = "Saturn-Neptune"  PNbrE = 6   PNbrM = 8  NbrOrbits = 60225 *5 ok
  if PlanetName = "Jupiter-Mars-Earth"    PNbrE = 3   PNbrM = 5  NbrOrbits =  4335    ok
  lPlanet.setText("   "+PlanetName)    // Label at botttom
  
     MRadius = Planet[PNbrM][3]        // Larger Orbit
     ERadius = Planet[PNbrE][3]        // Smaller Orbit
     
     IncDays = Planet[PNbrE][6] * 10     // 365.26     // DAysPerDeg  365 / 10
     EDegs   = Planet[PNbrE][5]                        // EDegs     = 360 / 365
     MDegs   = Planet[PNbrM][5]                        // MDegs     = 360 / 686
	 
	 // "Jupiter-Mars Earth"
	    PNbrX   = 4
	    XRadius = Planet[PNbrX][3]     // Mars
		XDegs   = Planet[PNbrX][5] 
	 
    
     See "Planet:"+PlanetName +" ERad:"+Eradius +" MRad:"+MRadius +" IncD:"+IncDays +" EDeg:"+Edegs +" MDeg:"+MDegs +nl
     
   //------------------------------
   MaxOrbit = 450                   // Size of Orbit in pixels           
   Scale    = MaxOrbit / MRadius    // Larget orbit
      
   ERadius  = ERadius * Scale        // 1.000000 * Scale  //  = 300
   MRadius  = MRadius * Scale        // 1.523662 * Scale  //  = 450
   XRadius  = XRadius * Scale        // Mars : Jupiter Mars Earth

   daVinci.setpen(penBlue4)            // Small orbit
   DrawCircle(0, 0, Eradius)
   
   daVinci.setpen(penBlue4)            // Large Orbit      
   DrawCircle(0, 0, Mradius)
   
   If PlanetNAme = "Jupiter-Mars-Earth"    // Mars in Jupiter-Mars Earth
      daVinci.setpen(penBlue4)
      DrawCircle(0, 0, Xradius)
   ok
   
   
   daVinci.setpen(penRed)  // Lines between planets
 
   xPos = (xWidth ) / 2   // Center of Window
   yPos = (yHeight) / 2 
   
   imageE.setGeometry(xPos +Eradius -25, yPos +0 -25, 50, 50 )  // image.Width(), image.Height()) 
   imageM.setGeometry(xPos +Mradius -25, yPos +0 -25, 50, 50 )  // image.Width(), image.Height()) 
 
    //-----------------------------------
    //-----------------------------------------------------
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw    

    //===============================
    //===============================
    
    count = 1
    for t = 0 to NbrOrbits step IncDays        // DegPerDAy * 10   
        count++
        
		//---------------------
        tDeg = t * EDegs                       // Degrees  
        tRad = tDeg * PI/180                   // Radian

        Ex = Eradius*cos(tRad)                 // P(x,y)
        Ey = Eradius*sin(tRad)
        
        //----------------------
        tDeg = t * MDegs                       // Degrees  
        tRad = tDeg * PI/180                   // Radian

        Mx = Mradius*cos(tRad)                 // P(x,y)
        My = Mradius*sin(tRad)
 
        //----------------------
		// Mars in Jupiter-Mars-Earth
        tDeg = t * XDegs                       // Degrees  
        tRad = tDeg * PI/180                   // Radian

        Xx = Xradius*cos(tRad)                 // P(x,y)
        Xy = Xradius*sin(tRad)
        
        //------------------------
        //------------------------
        // Image = 30 pixels use 1/2 = 15 offset

        imageE.setGeometry( xPos+Ex-15, yPos-Ey-15, image.Width(), image.Height())  
        imageM.setGeometry( xPos+Mx-15, yPos-My-15, image.Width(), image.Height())        
        //--------------------

        daVinci.DrawLine( Ex, -Ey, Mx, -My ) 
		
		If PlanetNAme = "Jupiter-Mars-Earth"          
           daVinci.DrawLine( Xx, -Xy, Mx, -My )	// Mars in Jupiter MArs Earth	
		   imageX.setGeometry( xPos+Xx-15, yPos-Xy-15, image.Width(), image.Height()) 
		ok
            
        //-----------------------------------------------------
        Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
        MyApp.ProcessEvents()               ### <<< EXEC the Draw   
        
        sleep(0.02)   // Delay Speed
        
    next
	
    
Return  

//==========================================================
//==========================================================

###=========================================
// DrawCircle using Center-X-Y and Radius

Func DrawCircle(x,y,radius)

//See "DrawCircle: x:"+x +" y:"+y +" rad:"+radius +nl

    HCenter = x
    VCenter = y
    HWidth  = 2 * radius
    VHeight = 2 * radius

    HCorner = HCenter - (HWidth  /2)
    VCorner = VCenter - (VHeight /2)

    daVinci.drawEllipse(HCorner, VCorner, HWidth, VHeight)  // LeftCorner, HWidth, VHeight

return

###==============================================================
###==============================================================




