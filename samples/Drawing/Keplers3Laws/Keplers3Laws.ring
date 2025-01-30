### Keler's Laws
### Bert Mariani 2025-01-02
/*
In the 16th century, the Polish astronomer Nicolaus Copernicus replaced the traditional Earth-centered view of planetary motion with one in which the Sun is at the center and the planets move around it in circles.  Although the Copernican model came quite close to correctly predicting planetary motion, discrepancies existed.  This became particularly evident in the case of the planet Mars, whose orbit was very accurately measured by the Danish astronomer Tycho Brahe.  The problem was solved by the German mathematician Johannes Kepler.   Kepler found that planetary orbits are not circles, but ellipses.  Kepler described planetary motion according to three laws.  Each of these laws is illustrated by an applet.

LAW I:  Each planet revolves around the Sun in an elliptical path, with the Sun occupying one of the foci of the ellipse.

LAW II: The straight line joining the Sun and a planet sweeps out equal areas in equal intervals of time.
Kepler's second law is a consequence of conservation of angular momentum.

Since the direction of the gravitational force is towards the center of mass (~the sun), it does not exert a torque about the CM.  The angular momentum about the CM, L = r × p is therefore constant.  Since p = mv, we have L = mr × v, and r × v = constant.  The area swept out by the straight line joining the Sun and a planet per unit time is equal to  (1/2)r × v (it is the area of a triangle) and therefore is constant.

LAW III: The squares of the planets' orbital periods are proportional to the cubes of the semi-major axes of their orbits.

Kepler's laws apply not just to planets orbiting the Sun, but to all cases in which one celestial body orbits another under the influence of gravitation -- moons orbiting planets, artificial satellites orbiting the Earth and other solar system bodies, and stars orbiting each other.

The Danish astronomer Tycho Brahe (1546-1601) together with the German astronomer Johannes Kepler (1571-1630). Kepler accepted Brahe's invitation to work together in Prague. Tycho Brahe and Johannes Kepler in the observatory in Prague. Chromolithography. Historia Univesal, by César Cantú. Volume VIII. Published in Barcelona, 1886.

*/

###=============================================================

load "stdlibcore.ring"
load "lightguilib.ring"
// load "C:\\MyStuff\AA-Triangle-Library\TriangleLibrary.ring"

//================================================

decimals(6)  // 4
PI         = 3.14159265
ImageScale = 1

aAngleSide = list(32)                   // GLOBAL for IN 6 --> OUT 32 Values
TriMsg     = "Trangle Library Msg:                   "  // For Angle / Side = 0 invalid

   
aTri    = list(32)   //  Triangle Calculator:  Area for TriangleSAS() = 
xPos    = 100        ### Canvas position on Screen
yPos    = 25
xWidth  = 1600       ### Canvas size on Screen
yHeight = 1000  
  
// Need to define variable when using Func StartApp()
MonaLisa = null 
daVinci  = null 
Canvas   = null
myApp    = null

eScale = 5 ;     // Scale the Triage Size

aTri = list(32)

Table1Gravity      = null
Table1Planet       = null
Table1PeriApHelion = null
Table1Orbital      = null
Table1EqualArea    = null

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
penRed      = new qpen() { setcolor(colorRed)     setwidth(2) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(1) }  //
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(1) } 
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(1) }
penWhite2   = new qpen() { setcolor(colorWhite2)  setwidth(1) }  //
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(1) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(1) }
penAqua     = new qpen() { setcolor(colorAqua)    setwidth(1) }

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
        setWindowTitle("Kepler's Laws ")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        Canvas = new qlabel(win)
        {
            ### daVinci Paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)
            
            daVinci = new qpainter()
            {
               begin(MonaLisa)                       ### Canvas: xWidth=1800  yHeight=1000  
               translate(xWidth/3*2 , yHeight/2)     ### TRANSLATE CO-ORD x,y 0,0 Maps Center OFFSET  TO 900,500
               setCompositionMode(26)                ###  THIS is the MAGIC - Erase Old Line when Redrawn
               //endpaint()                          ### This will Stop the Painting   
               
            }

            //================================================
            // IMAGES 
            
            //------------------------------------
            // Splash on Starting
            imageSplash = new qlabel(win)                             
            {
                image = new qPixMap("TychoBrahe-JohannesKepler.png") 
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2        
                setGeometry( xPos, yPos, image.Width(), image.Height())   
            }  
            
            imageK1 = new qlabel(win)                             
            {
                image = new qPixMap("Kepler-1.png") 
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2        
                setGeometry( -900, -900, image.Width(), image.Height())   
            }           
 
            imageK2 = new qlabel(win)                             
            {
                image = new qPixMap("Kepler-2.png") 
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2        
                setGeometry(  -900, -900, image.Width(), image.Height())   
            }   
            
            imageK3 = new qlabel(win)                             
            {
                image = new qPixMap("Kepler-3.png") 
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  
                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2        
                setGeometry( -900, -900, image.Width(), image.Height())   
            }           
            
            
            //-------------------------------
            setPixMap(MonaLisa)    // Draw It - Black
        }    
        
        //======================================================    
        
        comboKeplersLaw = new QComboBox(win) 
        {
            setgeometry( 2, 2, 95, 20)
            comboList = ["KeplersLaw","FirstLaw","SecondLaw","ThirdLaw"
                        ]
            for x in comboList additem(x,0) next                    
        } 
        
        btnKL  = new qPushButton(win) { setGeometry( 100, 2, 110, 20)   
                                        setText("Keplers Law")  
                                        setStyleSheet("background-color: aqua")
                                        setClickEvent("KeplersLaw()")  
                                      }         
        
        btnTE = new qPushButton(win) { setGeometry( 220, 2, 80, 20)   
                                       setText("TestEllipse")  
                                       setStyleSheet("background-color: aqua")
                                       setClickEvent("TestEllipse(450, 300)")                          
                                     }      
        
        lKepler  =  new qLabel(win) { setgeometry( 2, 30 , 850, 20)  
                                      settext("The Danish astronomer Tycho Brahe (1546-1601) & German astronomer Johannes Kepler (1571-1630). Kepler accepted Brahe's invitation to work together in Prague.")  
                                      setStyleSheet("background-color: white")
                                    }

        lPlanetOrbit  =  new qLabel(win) { setgeometry( xWidth/3*2 -160, 30 , 320, 20)  
                                      settext("Planet Elliptical Orbit ")  
                                      setStyleSheet("background-color: white")
                                    }      

        //------------------
        lPlanetDisplay  =  new qLabel(win) { setgeometry( xWidth/3*2 -160, 60 , 160, 20)  
                                      settext("2ndLaw: Select Planet")  
                                      setStyleSheet("background-color: white")
                                    } 



        comboPlanet = new QComboBox(win) 
        {
            setgeometry( xWidth/3*2 +10 , 60 , 150, 20 )
            setStyleSheet("background-color: aqua")
            comboList = ["Mercury","Venus","Earth","Mars",
                         "Jupiter","Saturn","Uranus","Neptune" 
                        ]
            for x in comboList additem(x,0) next                    
        }

                                    
        //----------------------------------------  
        // TABLES for Parameters and Values
        // To be able to Move them Off Screen
        
        Table1Gravity = new qTableWidget(win) 
        {                   setGeometry( -900, -900, 320, 540)      
        }
        
        Table1Planet = new qTableWidget(win) 
        {                  setGeometry( -900, -900, 320, 350)       
        }
        
        Table1PeriApHelion = new qTableWidget(win) 
        {                        setGeometry( -900, -900, 400, 350)       
        }
        
        Table1Orbital = new qTableWidget(win) 
        {                   setGeometry( -900, -900, 320, 350)    
        }
        
        Table1EqualArea = new qTableWidget(win) 
        {                     setGeometry( -900, -900, 320, 350)    
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
    
    // Move it OFF Screen
    imageSplash.setGeometry( -900, -900, image.Width(), image.Height())
        imageK1.setGeometry( -900, -900, image.Width(), image.Height())
        imageK2.setGeometry( -900, -900, image.Width(), image.Height())
        imageK3.setGeometry( -900, -900, image.Width(), image.Height())
        
     // Move Tables off Screen    
         Table1Gravity.setGeometry( -900, -900, 320, 540)       
          Table1Planet.setGeometry( -900, -900, 320, 350)
    Table1PeriApHelion.setGeometry( -900, -900, 400, 350)
         Table1Orbital.setGeometry( -900, -900, 320, 350)   
       Table1EqualArea.setGeometry( -900, -900, 320, 350)        
        
     
    MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw
        
return

###==========================================================================

Func  KeplersLaw()

    ClearImages()
    
    imageK1.setGeometry(  2, 60, image.Width(), image.Height()) 
    imageK2.setGeometry(432, 60, image.Width(), image.Height()) 
    imageK3.setGeometry(862, 60, image.Width(), image.Height()) 

    KeplersSelect  = comboKeplersLaw.currentText()
    See "KeplersSelect: "+ KeplersSelect +nl
                 
    // Draw Axis
    daVinci.setpen(penWhite) 
    daVinci.drawLine(  -500,   0 , 500,   0 )  // Horz
    daVinci.drawLine(     0,-500 ,   0, 500 )  //   Vert      
       
    //-----------------------------------------------------
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw   
 
    DisplayGravityWidgetTable() 
          
    if KeplersSelect = "FirstLaw"      GoFirstLaw()   ok
    if KeplersSelect = "SecondLaw"     GoSecondLaw()  ok
    if KeplersSelect = "ThirdLaw"      GoThirdLaw()   ok

Return

###==============================================================
###==============================================================

Func GoFirstLaw()

    ClearImages()
    
    lKepler.setText("LAW I:  Each Planet revolves around the Sun in an Elliptical Path, with the Sun occupying one of the Foci of the Ellipse.")
    
    lPlanetOrbit.setText(" Mercury Elliptical Orbit: ECC 0.20564  Diff-AphToPeriH: 52.0% ")
    
    imageK1.setGeometry( 2, 60, image.Width(), image.Height()) 
   
    //---------------------------------------------- 
    // ["Mercury",   57909231,   56671577, 0.20564 
    // ["Mercury",   46003049,   69815301, 0.2060, 52.0000]
    
    aSMA  =  57.909231
    bSMA  =  56.671577
    eCEN  =   0.20564 
    focus = ( (aSMA^^2)- (bSMA^^2) )^^0.5     // Focus units from CENTER (C,0) (-C,0)
    
    aSMAscale  = 57.909231 * 7  // 7 = Scale
    bSMAscale  = 56.671577 * 7
    focusScale = focus     * 7
      
    See "aSMA:"+aSMAscale +" bSMA:"+bSMAscale +" Focus:"+focusScale +nl

    daVinci.setpen(penYellow) 
    daVinci.drawEllipse( -aSMAscale, -bSMAscale, aSMAscale *2, bSMAscale *2)    
    
    daVinci.setpen(penRed)
    drawCircle(  focusScale, 0, 6)
  //drawCircle( -focusScale, 0, 1)
      
    daVinci.setpen(penBlue)
  //DrawCircle(0, 0 , bSMAscale)
     
    //-----------------------------------------------------
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw
     
    TestEllipse(aSMAscale, bSMAscale)   
    DisplayPlanetWidgetTable()  
    DisplayPlanetPeriApHelionWidgetTable()
    

return

###==============================================================
###==============================================================   
// LAW II: The straight line joining the Sun and a planet sweeps out 
//          equal areas in equal intervals of time.
//
// Kepler's second law is a consequence of conservation of angular momentum.
// 
// Since the direction of the gravitational force is towards the center of mass (~the sun), 
// it does not exert a torque about the CM.  
// The angular momentum about the CM, L = r × p is therefore constant.  
// Since p = mv, we have L = mr × v, and r × v = constant.  
// The area swept out by the straight line joining the Sun and a planet
// per unit time is equal to  (1/2)r × v (it is the area of a triangle) and therefore is constant.
//
// The area of such an ellipse is 
// Area = Pi * A * B , a very natural generalization of the formula for a circle! 
//---------------------------------------------
//------------------------------------------------------------------------------------------              

Func GoSecondLaw()
    Scale = 7           // Mercury

    ClearImages()

    lKepler.setText("LAW II: The straight line joining the Sun and a Planet sweeps out Equal Areas in Equal Intervals of Time. Kepler's Second Law is a consequence of Conservation of Angular Momentum.")  
    
    lPlanetOrbit.setText(" Mercury Elliptical Orbit: ECC 0.20564  Diff-AphToPeriH: 52.0% ")
    
    imageK2.setGeometry( 2, 60, image.Width(), image.Height()) 
    
    //-----------------------------------------------------
    //---------------------------------------------- 
    // ["Mercury",   57909231,   56671577, 0.20564           semi-Major semi-Mior
    // ["Mercury",   46003049,   69815301, 0.2060, 52.0000]  Perihelion Aphelion  115,818,350


    //        Planet     Major        Minor      Eccenttricity  PeriHelion  ApHelion      Scale        Diff
    aPlanet = [ ["Mercury",   57.909231,   56.671577, 0.20564,    46.003049,    69.815301, 7.000000000, 52.0000],       
                ["Venus",    108.209525,  108.207038, 0.00678,   107.473109,   108.944751, 3.004291845,  1.4000],       
                ["Earth",    149.598319,  149.577432, 0.01671,   147.099605,   152.096175, 2.194357367,  3.5000],       
                ["Mars",     227.943771,  226.947566, 0.09339,   206.647358,   249.225922, 1.559020045, 21.0000],       
                ["Jupiter",  778.342761,  777.430569, 0.04840,   740.736878,   816.087162, 0.434782609, 10.0000],       
                ["Saturn",  1426.714893, 1424.640932, 0.05390,  1349.396883,  1504.053917, 0.238663484, 12.0000],       
                ["Uranus",  2870.633541, 2867.425958, 0.04726,  2735.462312,  3006.482088, 0.117726202,  9.7000],       
                ["Neptune", 4498.393012, 4498.227045, 0.00859,  4459.567925,  4536.937875, 0.072202166,  1.9000]        
              ] 
              
for i = 1 to 8 
        // Calc Equal Area for 8 Planets
        Planet      = aPlanet[i][1]
        aSMA        = aPlanet[i][2]
        bSMA        = aPlanet[i][3]
        eCEN        = aPlanet[i][4]
        rPeriHelion = aPlanet[i][5] 
        rApHelion   = aPlanet[i][6]
        Scale       = aPlanet[i][7]
        DiffPeriAp  = aPlanet[i][8]
              
        rLenOld    = rPeriHelion   // Focus to Ellipse Point
   
    lPlanetOrbit.setText( Planet +" Elliptical Orbit: ECC "+ (""+eCEN)   +" Diff-AphToPeriH: "+ (""+DiffPeriAp) )
    
    focus = ( (aSMA^^2)- (bSMA^^2) )^^0.5     // Focus units from CENTER (C,0) (-C,0)
    
    aSMAscale  = aSMA  * Scale                // 7 = SCALED SIZE to Draw Mercury = 7
    bSMAscale  = bSMA  * Scale                // Reduce bigger orbits in proportion 
    focusScale = focus * Scale
    
    a = aSMA                                   // Draw ELLIPSE - SCALED  in Proportion
    b = bSMA
    e = eCen
      
    See "aSMA:"+aSMAscale +" bSMA:"+bSMAscale +" Focus:"+focusScale +nl
 
    daVinci.setpen(penYellow)        // ELLIPSE Draw
    daVinci.drawEllipse( -aSMAscale, -bSMAscale, aSMAscale *2, bSMAscale *2)    
    
    daVinci.setpen(penRed)           // Focus
    drawCircle(  focusScale, 0, 6)   // Small Focus Circle
       
    //=================================================
    
    TotalArea        = 0    
    aAngleRadiusArea = list(360,5)             // Each Angle with 3 Parms

    FocusR    = ((a^^2)-(b^^2))^^(1/2)
    FocusL    =  -FocusR                       // 
    
    IncAngle = 1
    for t    = 1 to 360 step IncAngle          // Spacing of Lines    
    
        tDeg = t                               // Degrees  
        tRad = tDeg * PI/180                   // Radian

        x = a*cos(tRad)  // / OrbitScale                       // P(x,y)
        y = b*sin(tRad)  // / OrbitScale  

        rLen   = ( ((x-FocusR)^^2)  +  (y^^2) )^^(1/2)         // rLen + lLen = constant
        lLen   = ( ((x-FocusL)^^2)  +  (y^^2) )^^(1/2)      
               
        //===================================
        // USE TRIANGLE CALCULATOR
        RatioArea = 1.0  // 0.958415724562                     // FIX Discrepancy Mercury
                
        aTri = TriangleSAS( rLen, IncAngle , rLenOld)  // Side-Angle-Side  sb,aA,sC  TWO Sides and ONE Angle BETWEEN
        
        Area       = fabs( 0+ aTri[13] )  * RatioArea  // Neg Sin fix Triabgle Calculator SAS -- aTri[13] = Area
        TotalArea += Area                              // Fix ||Use Triable CalculatorArea
        rLenOld    = rLen
        

        aAngleRadiusArea[t][1] = tDeg  
        aAngleRadiusArea[t][2] = tRad
        aAngleRadiusArea[t][3] = Area        // Fix Discrepancy || arrayTable 1:360 deg
        aAngleRadiusArea[t][4] = rLen 
    
        //See "Planet:"+ Planet +" D:"+tDeg  +" tRad:"+tRad +" Sin:"+sin(tRad) +tab+" rLen:"+ (rLen) +tab+" Area:"+ (Area) +" TotalArea:"+TotalArea  +nl        
        
    next
    
    //=============================================
    // DRAW EQUAL AREA
    // aAngleRadiusArea[t][tDeg, tRad, Area] 
    //
    // 1 MONTH OF ORBIT || TotalArea:10757.442543  1Deg = 29.881785 * 30 = 896.45355  ,   Ratio 0.958415724562
    //                       Formula:10310.102144  /360 = 28.6391726222  / 12 = 859.17517866   Ratio 1.043388557148
    //-----------------------------------------------
    
    AvgArea     = TotalArea / 360      // Triangle Calculator  TotalArea:10757.442543 AvgArea:29.881785
    AreaEllipse = Pi * A * B           //                        Formula:10310.102144         28.6391726222 
    
    See nl+"Planet:"+ Planet +" AreaEllipse Formula:"+AreaEllipse +" TotalArea:"+ TotalArea +" AvgArea:"+  AvgArea +nl
    
    daVinci.setPen(penRed)  
    
    //--------------------------------------
    // REULTS TABLE LIN 1 AND 2  for One Planet
    aResults = list(14,5)           // Planet, rLen, Degree, Area)

    aResults[1][1] = Planet         // First Line 1
    aResults[1][2] = aPlanet[i][5]  // PeriHelion
    aResults[1][3] = aPlanet[i][6]  // ApHelion
    aResults[1][4] = aPlanet[i][8]  // Diff-Peri-Ap
    
    aResults[2][1] = Planet         // Second Line 2
    aResults[2][2] = AreaEllipse
    aResults[2][3] = TotalArea
    aResults[2][4] = AvgArea
    //--------------------------------------
               
    AvgArea30Deg = AvgArea * 30     
    AreaSum      = 0
    IncAngle     = 1
    LineNbr      = 1
    HalfDeg      = 1   //  split area 1/2 above horizontal
    
    //-----------------------------
    // FIND EQUAL AREA FROM Below Perihelion  TO Above Perihelion +  1-360 2-359 3-359  10-352
    
    for t  = 1 to 360 step IncAngle
        AreaSum    +=  aAngleRadiusArea[t][3] 
        AreaSum    +=  aAngleRadiusArea[361-t][3]
        
        if AreaSum >=  AvgArea30Deg     
           HalfDeg = t                // Area 1/2 Above and Below Periheion Horz Line
           See "HalfDeg:"+HalfDeg +nl
           exit
        ok
    next
    
    //------------------------------------------------
    // At each Equal Area change the Color for visual
    // Start Below at HalfDeg -- Below Perihelion and find Equal Areas
    
    AreaSum = AvgArea30Deg / 2
    oldR    = -HalfDeg
    for t  = 1 to 360 step IncAngle      // -24 to 24 first area = 48deg
 
        if (LineNbr % 2) = 0   daVinci.setPen(penGreen)   else   daVinci.setPen(penRed)  ok     

           r = t                           // REplace t with r below
           if t>360   r=t-360  ok
    
           tRad = aAngleRadiusArea[r][2]
           x    = a*cos(tRad) * Scale                     // P(x,y)
           y    = b*sin(tRad) * Scale   
           
           daVinci.DrawLine( focusScale , 0, x, -(y) )   // <<<=== draw Lines for each degree
                 
        AreaSum    +=  aAngleRadiusArea[r][3] 
        if AreaSum >=  AvgArea30Deg * LineNbr       // Cumalative Addition Errors Initial          
           
           See "LineNbr:"+LineNbr +" T:"+t +" R:"+r +" AreaSum:"+AreaSum +nl 
          
          // arrayTable for each EqualArea
          aResults[LineNbr+2][1] = Planet                   // = list(14,4) 
          aResults[LineNbr+2][2] = aAngleRadiusArea[r][4]   // rLen

          aResults[LineNbr+2][3] = r             // aAngleRadiusArea[r][1]   // Deg
          aResults[LineNbr+2][4] = AvgArea30Deg  // aAngleRadiusArea[r][3]   // Area
          nbrDeg = r - oldR                      // Area in Degrees Orbitrd
          aResults[LineNbr+2][5] = nbrDeg        // Area Width in Deg       
          
          LineNbr++ 
          oldR = r        
          
        ok           
    next    
    

    //-----------------------------------------------------------------------
    // AreaEllipse Formula:10310.102144 / 12 = 859.17517866   TotalArea:10757.442543 AvgArea:29.881785  
    // 
    //-----------------------------------------------------------------------    
    //----------------------------------------------------  
    // Display results TABLE
    
    for LineNbr = 1 to len(aResults)
       See " "+aResults[LineNbr][1] +" "+aResults[LineNbr][2] +" "+aResults[LineNbr][3] +" "+aResults[LineNbr][4] +nl   
    next
    
    DisplayPlanetEqualAreaWidgetTable(aResults)     // Create Table
    
    //----------------------------------------  
    
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents() 
    
    PlanetSelect  = comboPlanet.currentText()
        
    if Planet != PlanetSelect  AND             // Leave Neptune on Display
       Planet != "Neptune"
       sleep(1)
       ClearImages()    
    else
      return
    ok
       
    imageK2.setGeometry( 2, 60, image.Width(), image.Height())   // ICON at Top-Left
    
next    

return

//-------------------------------------
// (aResults)
// Mercury 46.003049 69.815301 52
// Mercury 10310.102144 10757.442729 29.881785
//
// Mercury 49.787681 47 21.565129
// Mercury 56.457955 83 27.713260
// Mercury 62.370218 112 33.840069
// Mercury 66.618527 137 38.643966
// Mercury 69.026735 159 41.531772
// Mercury 69.817690 180 42.534858
// Mercury 68.950562 202 41.531772
// Mercury 66.475460 224 38.643966
// Mercury 62.176841 249 33.840069
// Mercury 56.251894 278 27.713260
// Mercury 49.636920 314 21.565129
// Mercury 46.000772 360 18.465994
//---------------------------------------

###==============================================================
###==============================================================   
// LAW III: The squares of the planets' orbital periods are proportional 
//       to the cubes  of the semi-major axes of their orbits.
//
// "Period of Orbit")    "t^2 = k * R^3")           
// "Keplers Constant")   "K = G*(M + m) / 4*Pi^2")       
// "Keplers Constant")   "K = 7.496 * 10E-6 * AU^3 / Days^2") 
//
//  VelocityOfOrbit = (G*MS/r)^^0.5
//  G  =  6.67   * 10^^-11          //  Gravity Constant: m3/(kg*s2 )   
//  MS =  1.9885 * 10^^30           //  Sun Mass: kg 
//  ME =  5.9722 * 10^^24           //  Earth Mass (10^^24kg)
//  r  =  1.49   * 10^^11           //  Earth Orbit Radius: m      
//  Speed = 29,835 m/s
//
//  Kepler K: G:    0.000000 
//            M1:   1988499999999999972408794546176 
//            4PI2: 39.478418 
//            K:    335963187867162880   
//  
//  Kepler K: G:0.000000 M1:1988499999999999972408794546176.000000 4PI2:39.478418 K:335963187867162880.000000
//  Planet: Mercury  R: 0.387099     T:   0.240842 R3:     0.058005 T2:    0.058005
//  Planet: Venus    R: 0.723332     T:   0.615186 R3:     0.378454 T2:    0.378454
//  Planet: Earth    R: 1.000000     T:   1.000000 R3:     1.000000 T2:    1.000000
//  Planet: Mars     R: 1.523662     T:   1.880759 R3:     3.537253 T2:     3.537253
//  Planet: Jupiter  R: 5.203363     T:  11.869330 R3:   140.880984 T2:  140.880984
//  Planet: Saturn   R: 9.537070     T:  29.452521 R3:   867.451005 T2:  867.451005
//  Planet: Uranus   R:19.191264     T:  84.072772 R3:  7068.231001 T2:  7068.231001
//  Planet: Neptune  R:30.068963     T: 164.883686 R3: 27186.629761 T2: 27186.629761
//----------------------------------------------

Func GoThirdLaw()

    ClearImages()
       
    lKepler.setText("LAW III: The Squares of the Planets' Orbital Periods are proportional to the Cubes of the Semi-Major Axes of their Orbits.")    
    
    lPlanetOrbit.setText("  Yel: Mercury  Red: Venus  Blue: Earth  White: Mars")    
    
    imageK3.setGeometry( 2, 60, image.Width(), image.Height()) 
    
    //-----------------------------------------------------
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw
    
    //----------------------------------------------------
    
    DisplayPlanetOrbitalTimeWidgetTable()
    
    //---------------------------------------------------------
    // Axis
    daVinci.setpen(penWhite) 
    daVinci.drawLine(  -500,   0 , 500,   0 )  // Horz
    daVinci.drawLine(     0,-500 ,   0, 500 )  //   Vert    
    
    //-----------------------------------
    // Display Orbits
    // Mercury
    aSMA  =  57.909231
    bSMA  =  56.671577
    eCEN  =   0.20564 
    focus = ( (aSMA^^2)- (bSMA^^2) )^^0.5     // Focus units from CENTER (C,0) (-C,0)
    
    aSMAscale  = 57.909231 * 2  // 7 = Scale
    bSMAscale  = 56.671577 * 2
    focusScale = focus     * 2
                             2
    daVinci.setpen(penYellow)
    daVinci.drawEllipse( -aSMAscale, -bSMAscale, aSMAscale *2, bSMAscale *2)  
    drawCircle(  focusScale, 0, 6)
    
    //-----------------------------------
    // Venus
    aSMA  =  108.209525
    bSMA  =  108.207038
    eCEN  =   0.006780
    focus = ( (aSMA^^2)- (bSMA^^2) )^^0.5     // Focus units from CENTER (C,0) (-C,0)
    
    aSMAscale  = 108.209525 * 2  // 7 = Scale
    bSMAscale  = 108.207038 * 2
    focusScale = focus      * 2
      
    daVinci.setpen(penGreen)
    daVinci.drawEllipse( -aSMAscale, -bSMAscale, aSMAscale *2, bSMAscale *2) 
    drawCircle(  focusScale, 0, 6)

    //-----------------------------------
    //Earth
    aSMA  =  149.598319
    bSMA  =  149.577432
    eCEN  =   0.016710 
    focus = ( (aSMA^^2)- (bSMA^^2) )^^0.5     // Focus units from CENTER (C,0) (-C,0)
    
    aSMAscale  = 149.598319 * 2  // 7 = Scale
    bSMAscale  = 149.577432 * 2
    focusScale = focus      * 2
      
    daVinci.setpen(penBlue)
    daVinci.drawEllipse( -aSMAscale, -bSMAscale, aSMAscale *2, bSMAscale *2) 
    drawCircle(  focusScale, 0, 6)
    
    //-----------------------------------
    // Mars
    aSMA  =  227.943771
    bSMA  =  226.947566
    eCEN  =    0.93390
    focus = ( (aSMA^^2)- (bSMA^^2) )^^0.5     // Focus units from CENTER (C,0) (-C,0)
    
    aSMAscale  = 227.943771 * 2  // 7 = Scale
    bSMAscale  = 226.947566 * 2
    focusScale = focus      * 2
      
    daVinci.setpen(penWhite2)
    daVinci.drawEllipse( -aSMAscale, -bSMAscale, aSMAscale *2, bSMAscale *2)
    drawCircle(  focusScale, 0, 6)

    //-----------------------------------
    //-----------------------------------------------------
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw    
    
       
return

###==============================================================
###==============================================================

###=========================================
// DrawCircle using Center-X-Y and Radius

Func DrawCircle(x,y,radius)

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
// Display Gravity Table

Func DisplayGravityWidgetTable()

    See "DisplayGravityWidgetTable() " +nl
      
    ###--------------------------------
    ### QWidgetTable
    ###--------------------------------
    
    Table1Gravity = new qTableWidget(win) 
    {
        setrowcount(16) setcolumncount(4)    // <<<=== TABLE X-Y Siz
        setGeometry(2, 340, 320,540)          // 330
        setselectionbehavior(QAbstractItemView_SelectRows)
        setSelectionMode(QAbstractItemView_SelectItems) 

        //-----------------------
        // Append TITLES
        
        myCols = new qStringList() 
        {
                append("PARAMETER")    // TopLabel PARAMETER COL 1
                append("Value-A")      // TopLabel Value-A   COL 2
        }
        
        //---------------------------
        
        SetColumnWidth(0,100)    
        SetColumnWidth(1,200)              
        
        //--------------------------
        // Fill R-C in Cells Vert-Horz
                
        for x = 1 to 16             // Vert
            for y = 1 to 2          // Horz
                item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                setitem(x-1,y-1,item1) 
            next
        next
        
        //---------------------------------------
        // Fill TABLE Cells with aTri[] Values
        
                
        item1 = new qtablewidgetitem("Newtons Law" )     setitem( 0, 0, item1)
        item1 = new qtablewidgetitem("Gravitation:  Sun-1 Planet-2 ")     setitem( 0, 1, item1)

        item1 = new qtablewidgetitem("Force")            setitem( 1, 0, item1)
        item1 = new qtablewidgetitem("F = G*m1*m2/R^2")  setitem( 1, 1, item1)

        item1 = new qtablewidgetitem("Gravitation")                  setitem( 2, 0, item1)
        item1 = new qtablewidgetitem("G = 6.67*10E-11 * Nm^2/kg^2")  setitem( 2, 1, item1)
       
        item1 = new qtablewidgetitem("Distance")         setitem( 3, 0, item1)
        item1 = new qtablewidgetitem("R = Radius")       setitem( 3, 1, item1)
 
        item1 = new qtablewidgetitem("Acceleration1")    setitem( 4, 0, item1)
        item1 = new qtablewidgetitem("a1 = G*m2/R^2 ")   setitem( 4, 1, item1)

        item1 = new qtablewidgetitem("Acceleration2")    setitem( 5, 0, item1)
        item1 = new qtablewidgetitem("a2 = G*m1/R^2 ")   setitem( 5, 1, item1)

        item1 = new qtablewidgetitem("Velocity1 ")       setitem( 6, 0, item1)
        item1 = new qtablewidgetitem("v1^2/R1 = a1 ")    setitem( 6, 1, item1)

        item1 = new qtablewidgetitem("Velocity2" )       setitem( 7, 0, item1)
        item1 = new qtablewidgetitem("v2^2/R2 = a2 ")    setitem( 7, 1, item1)

        item1 = new qtablewidgetitem("Center Of Mass")   setitem( 8, 0, item1)
        item1 = new qtablewidgetitem("CM = G*m1/R ")     setitem( 8, 1, item1)

        item1 = new qtablewidgetitem("Center Of Mass")   setitem( 9, 0, item1)   
        item1 = new qtablewidgetitem("G*m1/R  = v2^2 ")  setitem( 9, 1, item1) 

        item1 = new qtablewidgetitem("OrbitalSpeed")     setitem(10, 0, item1)
        item1 = new qtablewidgetitem("v2 = (2*Pi*R/t2)") setitem(10, 1, item1)     

        item1 = new qtablewidgetitem("OrbitalSpeed")             setitem(11, 0, item1)
        item1 = new qtablewidgetitem("G*m1/R = (2*Pi*R/t2)^2 ")  setitem(11, 1, item1)

        item1 = new qtablewidgetitem("OrbitalSpeed")             setitem(12, 0, item1)
        item1 = new qtablewidgetitem("t2^2 = (4*Pi/G*m1)*R^3 ")  setitem(12, 1, item1)

        item1 = new qtablewidgetitem("Period of Orbit")          setitem(13, 0, item1)
        item1 = new qtablewidgetitem("t^2 = k * R^3")            setitem(13, 1, item1)

        item1 = new qtablewidgetitem("Keplers Constant")         setitem(14, 0, item1)
        item1 = new qtablewidgetitem("K = G*(M + m) / 4*Pi^2")   setitem(14, 1, item1)
        
        item1 = new qtablewidgetitem("Keplers Constant")                 setitem(15, 0, item1)
        item1 = new qtablewidgetitem("K = 7.496 * 10E-6 * AU^3 / Days^2")  setitem(15, 1, item1) 
        
        //----------------------------          
                    
        setHorizontalHeaderLabels(myCols)
        setAlternatingRowColors(true)
            
        setStyleSheet("QHeaderView::section { background-color: yellow }")
           
        horizontalHeader().setStyleSheet("color: blue")
          verticalHeader().setStyleSheet("color: red")          
            
        show() // NEEDED to Display Table after it is Populated
    
    }
return

        
//=====================================================
//=====================================================

Func DisplayPlanetWidgetTable()

    See "DisplayPlanetWidgetTable() " +nl

    // Good Table
    //        Planet     Major        Minor      Eccenttricity
    aPlanet = [ ["Mercury",   57909231,   56671577, 0.20564  ],       
                ["Venus",    108209525,  108207038, 0.00678  ],       
                ["Earth",    149598319,  149577432, 0.01671  ],       
                ["Mars",     227943771,  226947566, 0.09339  ],       
                ["Jupiter",  778342761,  777430569, 0.0484   ],       
                ["Saturn",  1426714893, 1424640932, 0.0539   ],       
                ["Uranus",  2870633541, 2867425958, 0.04726  ],       
                ["Neptune", 4498393012, 4498227045, 0.00859  ]        
              ]

    for i = 1 to 8
        // Calc Eccentricity
        MajorA = aPlanet[i][2]
        MinorB = aPlanet[i][3]

        Ecc           = ( 1 - ( (MinorB^^2) / (MajorA^^2) ) )^^(1/2)
        aPlanet[i][4] = Ecc
        See "Planet: "+aPlanet[i][1] +tab+" MajorA: "+MajorA +" MinorB: "+MinorB +" Ecc: "+ Ecc +nl

      // Calc Minor-Axis
      // a = aPlanet[i][2]   
      // e = aPlanet[i][4]
      //
      // b =   ( (a^^2) * ( 1- (e^^2)) )^^(1/2)
      // See "Planet: "+aPlanet[i][1] +" A: "+A +" E: "+E +" B: "+ B +nl
    
    next

        
    ###--------------------------------
    ### QWidgetTable  yHeight
    ###--------------------------------
    
    Table1Planet = new qTableWidget(win) 
    {
        setrowcount(9) setcolumncount(4)    // <<<=== TABLE X-Y Siz
        setGeometry( 2, 330, 400, 320)        // 330
        setselectionbehavior(QAbstractItemView_SelectRows)
        setSelectionMode(QAbstractItemView_SelectItems) 

        //-----------------------
        // Append TITLES
        
        myCols = new qStringList() 
        {
                append("PARAMETER")         // TopLabel PARAMETER COL 1
                append("Value-A")      // TopLabel Value-A   COL 2
                append("Value-B")      // TopLabel Value-A   COL 3
                append("Calc-Ecc")   // TopLabel Value-A   COL 4
        }
        
        //---------------------------
        
        SetColumnWidth(0, 60)    
        SetColumnWidth(1, 80)  
        SetColumnWidth(2, 80)    
        SetColumnWidth(3,100)           
        
        //--------------------------
        // Fill R-C in Cells Vert-Horz
                
        for x = 1 to 9             // Vert
            for y = 1 to 4          // Horz
                item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                setitem(x-1,y-1,item1) 
            next
        next
        
        //---------------------------------------
        // Fill TABLE Cells with aTri[] Values
        
                
        item1 = new qtablewidgetitem("Planet" )          setitem( 0, 0, item1)
        item1 = new qtablewidgetitem("SemiMajor")        setitem( 0, 1, item1)
        item1 = new qtablewidgetitem("SemiMinor" )       setitem( 0, 2, item1)
        item1 = new qtablewidgetitem("Eccentricity")     setitem( 0, 3, item1)  

        item1 = new qtablewidgetitem("Mercury" )          setitem( 1, 0, item1)
        item1 = new qtablewidgetitem("57909231")          setitem( 1, 1, item1)
        item1 = new qtablewidgetitem("56671577" )         setitem( 1, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[1][4])    setitem( 1, 3, item1)        

        item1 = new qtablewidgetitem("Venus" )            setitem( 2, 0, item1)  
        item1 = new qtablewidgetitem("108209525")         setitem( 2, 1, item1) 
        item1 = new qtablewidgetitem("108207038" )        setitem( 2, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[2][4])    setitem( 2, 3, item1)  
                                                                                
        item1 = new qtablewidgetitem("Earth" )            setitem( 3, 0, item1)  
        item1 = new qtablewidgetitem("149598319")         setitem( 3, 1, item1) 
        item1 = new qtablewidgetitem("149577432" )        setitem( 3, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[3][4])    setitem( 3, 3, item1)  


        item1 = new qtablewidgetitem("Mars" )             setitem( 4, 0, item1)  
        item1 = new qtablewidgetitem("227943771")         setitem( 4, 1, item1) 
        item1 = new qtablewidgetitem("226947566" )        setitem( 4, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[4][4])    setitem( 4, 3, item1)  
                                                                                
        item1 = new qtablewidgetitem("Jupiter" )          setitem( 5, 0, item1)  
        item1 = new qtablewidgetitem("778342761")         setitem( 5, 1, item1) 
        item1 = new qtablewidgetitem("777430569" )        setitem( 5, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[5][4])    setitem( 5, 3, item1)  


        item1 = new qtablewidgetitem("Saturn" )           setitem( 6, 0, item1)
        item1 = new qtablewidgetitem("1426714893")        setitem( 6, 1, item1)
        item1 = new qtablewidgetitem("1424640932" )       setitem( 6, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[6][4])       setitem( 6, 3, item1)  


        item1 = new qtablewidgetitem("Uranus" )           setitem( 7, 0, item1)
        item1 = new qtablewidgetitem("2870633541")        setitem( 7, 1, item1)
        item1 = new qtablewidgetitem("2867425958" )       setitem( 7, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[7][4])       setitem( 7, 3, item1)  
        
        item1 = new qtablewidgetitem("Neptune" )          setitem( 8, 0, item1)
        item1 = new qtablewidgetitem("4498393012")        setitem( 8, 1, item1)
        item1 = new qtablewidgetitem("4498227045" )       setitem( 8, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[8][4])       setitem( 8, 3, item1)          

        //----------------------------
 
        //----------------------------          
                    
        setHorizontalHeaderLabels(myCols)
        setAlternatingRowColors(true)
            
        setStyleSheet("QHeaderView::section { background-color: yellow }")
           
        horizontalHeader().setStyleSheet("color: blue")
          verticalHeader().setStyleSheet("color: red")          
            
        show() // NEEDED to Display Table after it is Populated
    
    }
return
        
//=====================================================
//=====================================================

Func DisplayPlanetPeriApHelionWidgetTable()

    See "DisplayPlanetPeriApHelionWidgetTable() " +nl
                                     
                //           EarthAU 149.5980 149.5980   Mercury S:0.774 D:0.16 0.20671             
                //     PerihelionAU) Aphelion(AU) Eccent  Diff(%)
    aPlanet = [ ["Mercury",   46003049,    69815301,   0.2060, 52.0000],   //  52.0000  
                ["Venus",    107473109,   108944751,   0.0070,  1.4000],   //   1.4000
                ["Earth",    147099605,   152096175,   0.0170,  3.5000],   //   3.5000
                ["Mars",     206647358,   249225922,   0.0930, 21.0000],   //  21.0000
                ["Jupiter",  740736878,   816087162,   0.0490, 10.0000],   //  10.0000
                ["Saturn",  1349396883,  1504053917,   0.0570, 12.0000],   //  12.0000
                ["Uranus",  2735462312,  3006482088,   0.0460,  9.7000],   //   9.7000
                ["Neptune", 4459567925,  4536937875,   0.0100,  1.9000]    //   1.9000
              ]
  
    for i = 1 to 8
        // Calc Eccentricity and Diff
        Perihelion = aPlanet[i][2]
        Aphelion   = aPlanet[i][3]
        
        SumPA   =  Aphelion + Perihelion
        DiffPA  =  Aphelion - Perihelion
        Ecc     =  DiffPA / SumPA
        
        DiffPer = (Aphelion / Perihelion) * 100 -100
        
        aPlanet[i][4] = Ecc
        aPlanet[i][5] = DiffPer
        See "Planet: "+aPlanet[i][1] +tab+" Perihelion: "+Perihelion +" Aphelion: "+Aphelion +" Ecc: "+Ecc +" Diff%: "+DiffPer +nl
        
    next    
    
    ###--------------------------------
    ### QWidgetTable yHeight
    ###--------------------------------
    
    Table1PeriApHelion = new qTableWidget(win) 
    {
        setrowcount(9) setcolumncount(5)    // <<<=== TABLE X-Y Siz
        setGeometry( 2, 670, 400, 320)        // 330
        setselectionbehavior(QAbstractItemView_SelectRows)
        setSelectionMode(QAbstractItemView_SelectItems) 

        //-----------------------
        // Append TITLES
        
        myCols = new qStringList() 
        {
                append("PARAMETER")         // TopLabel PARAMETER COL 1
                append("Value-A")           // TopLabel Value-A   COL 2
                append("Value-B")           // TopLabel Value-B   COL 3
                append("Calc-Ecc")              // TopLabel Value-C   COL 4
                append("Calc-Diff")
        }
        
        //---------------------------
        
        SetColumnWidth(0, 60)    
        SetColumnWidth(1, 80)  
        SetColumnWidth(2, 80)    
        SetColumnWidth(3, 80) 
        SetColumnWidth(4, 80)       
        
        //--------------------------
        // Fill R-C in Cells Vert-Horz
                
        for x = 1 to 9             // Vert
            for y = 1 to 5          // Horz
                item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                setitem(x-1,y-1,item1) 
            next
        next
        
        //---------------------------------------
        // Fill TABLE Cells with aTri[] Values
        
                
        item1 = new qtablewidgetitem("Planet" )           setitem( 0, 0, item1)
        item1 = new qtablewidgetitem("Perihelion")        setitem( 0, 1, item1)
        item1 = new qtablewidgetitem("Aphelion" )         setitem( 0, 2, item1)
        item1 = new qtablewidgetitem("Eccentricity")      setitem( 0, 3, item1)  
        item1 = new qtablewidgetitem("DiffPercent")       setitem( 0, 4, item1)     
        

        item1 = new qtablewidgetitem("Mercury" )          setitem( 1, 0, item1)
        item1 = new qtablewidgetitem("46003049")            setitem( 1, 1, item1)
        item1 = new qtablewidgetitem("69815301" )           setitem( 1, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[1][4])    setitem( 1, 3, item1)        
        item1 = new qtablewidgetitem(""+aPlanet[1][5])    setitem( 1, 4, item1)
        
        item1 = new qtablewidgetitem("Venus" )            setitem( 2, 0, item1)      
        item1 = new qtablewidgetitem("107473109")            setitem( 2, 1, item1)  
        item1 = new qtablewidgetitem("108944751" )           setitem( 2, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[2][4])    setitem( 2, 3, item1)  
        item1 = new qtablewidgetitem(""+aPlanet[2][5])    setitem( 2, 4, item1)                                                                                
        item1 = new qtablewidgetitem("Earth" )            setitem( 3, 0, item1)    
        item1 = new qtablewidgetitem("147099605")            setitem( 3, 1, item1)       
        item1 = new qtablewidgetitem("152096" )           setitem( 3, 2, item1)       
        item1 = new qtablewidgetitem(""+aPlanet[3][4])    setitem( 3, 3, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[3][5])    setitem( 3, 4, item1)                                                                                   
                                                                                   
        item1 = new qtablewidgetitem("Mars" )             setitem( 4, 0, item1)    
        item1 = new qtablewidgetitem("206647358")            setitem( 4, 1, item1)       
        item1 = new qtablewidgetitem("249225922" )           setitem( 4, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[4][4])    setitem( 4, 3, item1)  
        item1 = new qtablewidgetitem(""+aPlanet[4][5])    setitem( 4, 4, item1)                                                                                
        item1 = new qtablewidgetitem("Jupiter" )          setitem( 5, 0, item1)  
        item1 = new qtablewidgetitem("740736878")            setitem( 5, 1, item1) 
        item1 = new qtablewidgetitem("816087162" )           setitem( 5, 2, item1) 
        item1 = new qtablewidgetitem(""+aPlanet[5][4])    setitem( 5, 3, item1)  
        item1 = new qtablewidgetitem(""+aPlanet[5][5])    setitem( 5, 4, item1)

        item1 = new qtablewidgetitem("Saturn" )           setitem( 6, 0, item1)
        item1 = new qtablewidgetitem("1349396883")            setitem( 6, 1, item1)
        item1 = new qtablewidgetitem("1504053917" )          setitem( 6, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[6][4])    setitem( 6, 3, item1)  
        item1 = new qtablewidgetitem(""+aPlanet[6][5])    setitem( 6, 4, item1)

        item1 = new qtablewidgetitem("Uranus" )           setitem( 7, 0, item1)
        item1 = new qtablewidgetitem("2735462312")           setitem( 7, 1, item1)
        item1 = new qtablewidgetitem("3006482088" )          setitem( 7, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[7][4])    setitem( 7, 3, item1)  
        item1 = new qtablewidgetitem(""+aPlanet[7][5])    setitem( 7, 4, item1)
        
        item1 = new qtablewidgetitem("Neptune" )          setitem( 8, 0, item1)
        item1 = new qtablewidgetitem("4459567925")           setitem( 8, 1, item1)
        item1 = new qtablewidgetitem("4536937875" )          setitem( 8, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[8][4])    setitem( 8, 3, item1)          
        item1 = new qtablewidgetitem(""+aPlanet[8][5])    setitem( 8, 4, item1)
        
        //----------------------------
        //----------------------------          
                    
        setHorizontalHeaderLabels(myCols)
        setAlternatingRowColors(true)
            
        setStyleSheet("QHeaderView::section { background-color: yellow }")
           
        horizontalHeader().setStyleSheet("color: blue")
          verticalHeader().setStyleSheet("color: red")          
            
        show() // NEEDED to Display Table after it is Populated
    
    }
return  
      
//=====================================================
//=====================================================

Func DisplayPlanetOrbitalTimeWidgetTable()

    See "DisplayPlanetOrbitalWidgetTable() " +nl
    
    
    
    // Good Table
    //           Planet     Semi-Major-AU  Period-Days      //    Semi-Major
    aPlanet = [ ["Mercury",  0.38709893,     87.97, 1.0  ],     //      57909231
                ["Venus",    0.72333199,    224.70, 1.0  ],     //     108209525
                ["Earth",    1.00000011,    365.26, 1.0  ],     //     149598319
                ["Mars",     1.52366231,    686.98, 1.0  ],     //     227943771
                ["Jupiter",  5.20336301,   4332.82, 1.0  ],     //     778342761
                ["Saturn",   9.53707032,  10755.70, 1.0  ],     //    1426714893
                ["Uranus",  19.19126393,  30687.15, 1.0  ],     //    2870633541
                ["Neptune", 30.06896348,  60190.03, 1.0  ]      //    4498393012
              ]             
                            

    G  =  6.67   * (10^^(-11))
    G  =  0.00000000000667
    M1 =  1.9885 * (10^^30)
    K  = (G * M1) /  ( 4 *(Pi^^2))    // (M1 +M2)
    
    See "Kepler K: G:"+G +" M1:"+M1 +" 4PI2:"+ ( 4 * (Pi^^2)) +" K:"+K +nl

    for i = 1 to 8
        // Calc Period of Orbit
        // "Period of Orbit in Time T ")    "t^2 = k * R^3")
        
        R     =  aPlanet[i][2]   // semi-Major Axis radius
        R3    =  R^^3            // Orbit Radius - semiMajor Axis
        T2    =  R^^3            // Orbit Time
        T     = (R^^3)^^(1/2)
        
        EarthDays = T * 365.26   // Used AU=1 for Earth
  
        aPlanet[i][3] = EarthDays           // Period in Days
        aPlanet[i][4] = EarthDays / 365.26  // Period in Years      
        
        See "Planet: "+aPlanet[i][1] +tab+" Edays:"+EarthDays +" R:"+R +tab+" T:"+T +" R3:"+R3 +" T2:"+T2 +nl

    next    
    
    //----------------------------------------------------
    ###--------------------------------
    ### QWidgetTable yHeight
    ###--------------------------------
    
    Table1Orbital = new qTableWidget(win) 
    {
        setrowcount(10) setcolumncount(4)    // <<<=== TABLE X-Y Siz
        setGeometry(2, 340, 420, 350)        // 330
        setselectionbehavior(QAbstractItemView_SelectRows)
        setSelectionMode(QAbstractItemView_SelectItems) 

        //-----------------------
        // Append TITLES
        
        myCols = new qStringList() 
        {
                append("PARAMETER")                 // TopLabel PARAMETER COL 1
                append("Value-A")                   // TopLabel Value-A   COL 2
                append("Calc-Orbit-Days")           // TopLabel Value-B   COL 3
                append("Calc-Years")
        }
        
        //---------------------------
        
        SetColumnWidth(0, 80)    
        SetColumnWidth(1, 100)  
        SetColumnWidth(2, 130)    
        SetColumnWidth(3, 100)     
        
        //--------------------------
        // Fill R-C in Cells Vert-Horz
                
        for x = 1 to 8             // Vert
            for y = 1 to 4         // Horz
                item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                setitem(x-1,y-1,item1) 
            next
        next
        
        //---------------------------------------
        // Fill TABLE Cells with aTri[] Values
        
                
        item1 = new qtablewidgetitem("Planet" )           setitem( 0, 0, item1)
        item1 = new qtablewidgetitem("semiMajor-AU")      setitem( 0, 1, item1)
        item1 = new qtablewidgetitem("Period-Days" )      setitem( 0, 2, item1)
        item1 = new qtablewidgetitem("Period-Years" )     setitem( 0, 3, item1)     
        

        item1 = new qtablewidgetitem("Mercury" )          setitem( 1, 0, item1)
        item1 = new qtablewidgetitem("0.38709893")        setitem( 1, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[1][3])    setitem( 1, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[1][4])    setitem( 1, 3, item1)
        
        item1 = new qtablewidgetitem("Venus" )            setitem( 2, 0, item1)
        item1 = new qtablewidgetitem("0.72333199")        setitem( 2, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[2][3])    setitem( 2, 2, item1)       item1 = new qtablewidgetitem(""+aPlanet[2][4])    setitem( 2, 3, item1)
        
        item1 = new qtablewidgetitem("Earth" )            setitem( 3, 0, item1)
        item1 = new qtablewidgetitem("1.00000011")        setitem( 3, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[3][3])    setitem( 3, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[3][4])    setitem( 3, 3, item1)

        item1 = new qtablewidgetitem("Mars" )             setitem( 4, 0, item1)
        item1 = new qtablewidgetitem("1.52366231")        setitem( 4, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[4][3])    setitem( 4, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[4][4])    setitem( 4, 3, item1)
        
        item1 = new qtablewidgetitem("Jupiter" )          setitem( 5, 0, item1)
        item1 = new qtablewidgetitem("5.20336301")        setitem( 5, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[5][3])    setitem( 5, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[5][4])    setitem( 5, 3, item1)

        item1 = new qtablewidgetitem("Saturn" )           setitem( 6, 0, item1)
        item1 = new qtablewidgetitem("9.53707032")        setitem( 6, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[6][3])    setitem( 6, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[6][4])    setitem( 6, 3, item1)

        item1 = new qtablewidgetitem("Uranus" )           setitem( 7, 0, item1)
        item1 = new qtablewidgetitem("19.19126393")       setitem( 7, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[7][3])    setitem( 7, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[7][4])    setitem( 7, 3, item1)

        item1 = new qtablewidgetitem("Neptune" )          setitem( 8, 0, item1)
        item1 = new qtablewidgetitem("30.06896348")       setitem( 8, 1, item1)
        item1 = new qtablewidgetitem(""+aPlanet[8][3])    setitem( 8, 2, item1)
        item1 = new qtablewidgetitem(""+aPlanet[8][4])    setitem( 8, 3, item1)
        
        //----------------------------
        //----------------------------          
                    
        setHorizontalHeaderLabels(myCols)
        setAlternatingRowColors(true)
            
        setStyleSheet("QHeaderView::section { background-color: yellow }")
           
        horizontalHeader().setStyleSheet("color: blue")
          verticalHeader().setStyleSheet("color: red")          
            
        show() // NEEDED to Display Table after it is Populated
    
    }
return 


//=====================================================
//=====================================================
//  EQUAL AREA TABLE 

Func DisplayPlanetEqualAreaWidgetTable(aResults)

    See "DisplayPlanetEqualAreaWidgetTable() " +nl

    //-------------------------------------
    // (aResults)
    // Name    rLen      Angle  Area
    // Mercury 46.003049    69.815301    52
    // Mercury 10310.102144 10757.442729 29.881785
    //
    // Mercury 49.787681v 47 21.565129
    // Mercury 56.457955v 83 27.713260
    // Mercury 62.370218 112 33.840069
    // Mercury 66.618527 137 38.643966
    // Mercury 69.026735 159 41.531772
    // Mercury 69.817690 180 42.534858
    // Mercury 68.950562 202 41.531772
    // Mercury 66.475460 224 38.643966
    // Mercury 62.176841 249 33.840069
    // Mercury 56.251894 278 27.713260
    // Mercury 49.636920 314 21.565129
    // Mercury 46.000772 360 18.465994
    //---------------------------------------
      
    ###--------------------------------
    ### QWidgetTable  yHeight
    ###--------------------------------
    
    Table1EqualArea = new qTableWidget(win) 
    {
        setrowcount(15) setcolumncount(5)      // <<<=== TABLE X-Y Siz
        setGeometry( 2, 340, 500 , 520)        
        setselectionbehavior(QAbstractItemView_SelectRows)
        setSelectionMode(QAbstractItemView_SelectItems) 

        //-----------------------
        // Append TITLES
        
        myCols = new qStringList() 
        {
                append("PARAM")             // TopLabel PARAMETER COL 1
                append("Calc-rLen")         // TopLabel Value-A   COL 2
                append("Calc-Deg")          // TopLabel Value-A   COL 3
                append("Calc-Area")         // TopLabel Value-A   COL 4
                append("AreaInDeg")         // TopLabel Value-A   COL 5
        }
        
        //---------------------------
        
        SetColumnWidth(0,100)    
        SetColumnWidth(1, 80)  
        SetColumnWidth(2, 80)    
        SetColumnWidth(3,100) 
        SetColumnWidth(4,100)       
        
        //--------------------------
        // Fill R-C in Cells Vert-Horz
                
        for x = 1 to 14             // Vert
            for y = 1 to 5          // Horz
                item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                setitem(x-1,y-1,item1) 
            next
        next
        
        //---------------------------------------
        // Fill TABLE Cells with aTri[] Values
        
                
        item1 = new qtablewidgetitem("Planet" )             setitem( 0, 0, item1)
        item1 = new qtablewidgetitem("LenToFoc")            setitem( 0, 1, item1)
        item1 = new qtablewidgetitem("Degree" )             setitem( 0, 2, item1)
        item1 = new qtablewidgetitem("Area")                setitem( 0, 3, item1)  
        item1 = new qtablewidgetitem("AreaInDeg")           setitem( 0, 4, item1) 
        
        item1 = new qtablewidgetitem("Peri-Aphelion")         setitem( 1, 0, item1)
        item1 = new qtablewidgetitem("P="+ aResults[1][2])    setitem( 1, 1, item1)
        item1 = new qtablewidgetitem("A="+ aResults[1][3])    setitem( 1, 2, item1)
        item1 = new qtablewidgetitem("Diff="+ aResults[1][4] +" %") setitem( 1, 3, item1)        
        item1 = new qtablewidgetitem(" ")                     setitem( 1, 4, item1) 
        
        item1 = new qtablewidgetitem("Area-Calc")  setitem( 2, 0, item1)  
        item1 = new qtablewidgetitem("E="+ aResults[2][2])    setitem( 2, 1, item1) 
        item1 = new qtablewidgetitem("T="+ aResults[2][3])    setitem( 2, 2, item1) 
        item1 = new qtablewidgetitem("Avg="+ aResults[2][4])    setitem( 2, 3, item1)  
        item1 = new qtablewidgetitem(" ")                   setitem( 2, 4, item1)       
                                                                                
        item1 = new qtablewidgetitem(""+ aResults[3][1]+" 1") setitem( 3, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[3][2])      setitem( 3, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[3][3])      setitem( 3, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[3][4])      setitem( 3, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[3][5])      setitem( 3, 4, item1) 

        item1 = new qtablewidgetitem(""+ aResults[4][1]+" 2") setitem( 4, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[4][2])      setitem( 4, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[4][3])      setitem( 4, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[4][4])      setitem( 4, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[4][5])      setitem( 4, 4, item1)                                                                                 
        item1 = new qtablewidgetitem(""+ aResults[5][1]+" 3") setitem( 5, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[5][2])      setitem( 5, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[5][3])      setitem( 5, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[5][4])      setitem( 5, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[5][5])      setitem( 5, 4, item1) 

        item1 = new qtablewidgetitem(""+ aResults[6][1]+" 4") setitem( 6, 0, item1)
        item1 = new qtablewidgetitem(""+ aResults[6][2])      setitem( 6, 1, item1)
        item1 = new qtablewidgetitem(""+ aResults[6][3])      setitem( 6, 2, item1)
        item1 = new qtablewidgetitem(""+ aResults[6][4])      setitem( 6, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[6][5])      setitem( 6, 4, item1) 

        item1 = new qtablewidgetitem(""+ aResults[7][1]+" 5") setitem( 7, 0, item1)
        item1 = new qtablewidgetitem(""+ aResults[7][2])      setitem( 7, 1, item1)
        item1 = new qtablewidgetitem(""+ aResults[7][3])      setitem( 7, 2, item1)
        item1 = new qtablewidgetitem(""+ aResults[7][4])      setitem( 7, 3, item1)         
        item1 = new qtablewidgetitem(""+ aResults[7][5])      setitem( 7, 4, item1) 
        
        item1 = new qtablewidgetitem(""+ aResults[8][1]+" 6") setitem( 8, 0, item1)
        item1 = new qtablewidgetitem(""+ aResults[8][2])      setitem( 8, 1, item1)
        item1 = new qtablewidgetitem(""+ aResults[8][3])      setitem( 8, 2, item1)
        item1 = new qtablewidgetitem(""+ aResults[8][4])      setitem( 8, 3, item1)       
        item1 = new qtablewidgetitem(""+ aResults[8][5])      setitem( 8, 4, item1) 
        
        item1 = new qtablewidgetitem(""+ aResults[9][1]+" 7") setitem( 9, 0, item1)
        item1 = new qtablewidgetitem(""+ aResults[9][2])      setitem( 9, 1, item1)
        item1 = new qtablewidgetitem(""+ aResults[9][3])      setitem( 9, 2, item1)
        item1 = new qtablewidgetitem(""+ aResults[9][4])      setitem( 9, 3, item1)    
        item1 = new qtablewidgetitem(""+ aResults[9][5])      setitem( 9, 4, item1) 
        
        item1 = new qtablewidgetitem(""+ aResults[10][1]+" 8") setitem(10, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[10][2])      setitem(10, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[10][3])      setitem(10, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[10][4])      setitem(10, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[10][5])      setitem(10, 4, item1) 
        
        item1 = new qtablewidgetitem(""+ aResults[11][1]+" 9") setitem(11, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[11][2])      setitem(11, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[11][3])      setitem(11, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[11][4])      setitem(11, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[11][5])      setitem(11, 4, item1) 

        item1 = new qtablewidgetitem(""+ aResults[12][1]+" 10") setitem(12, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[12][2])       setitem(12, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[12][3])       setitem(12, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[12][4])       setitem(12, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[12][5])       setitem(12, 4, item1)                                                                                 
        item1 = new qtablewidgetitem(""+ aResults[13][1]+" 11") setitem(13, 0, item1)  
        item1 = new qtablewidgetitem(""+ aResults[13][2])       setitem(13, 1, item1) 
        item1 = new qtablewidgetitem(""+ aResults[13][3])       setitem(13, 2, item1) 
        item1 = new qtablewidgetitem(""+ aResults[13][4])       setitem(13, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[13][5])       setitem(13, 4, item1) 

        item1 = new qtablewidgetitem(""+ aResults[14][1]+" 12") setitem(14, 0, item1)
        item1 = new qtablewidgetitem(""+ aResults[14][2])       setitem(14, 1, item1)
        item1 = new qtablewidgetitem(""+ aResults[14][3])       setitem(14, 2, item1)
        item1 = new qtablewidgetitem(""+ aResults[14][4])       setitem(14, 3, item1)  
        item1 = new qtablewidgetitem(""+ aResults[14][5])       setitem(14, 4, item1) 
        //----------------------------
        //----------------------------          
                    
        setHorizontalHeaderLabels(myCols)
        setAlternatingRowColors(true)
            
        setStyleSheet("QHeaderView::section { background-color: yellow }")
           
        horizontalHeader().setStyleSheet("color: blue")
          verticalHeader().setStyleSheet("color: red")          
            
        show() // NEEDED to Display Table after it is Populated
    
    }
return
        
//=====================================================
//===================================================== 
    

###==========================================================================
###==========================================================================
    
    


###==========================================================================
###==========================================================================

Func TestEllipse(a, b)
   
    tDeg = 30                    // Degrees  
    tRad = tDeg * PI/180         // Radians 
 
    e = ( 1 -( (b^^2) / (a^^2) ) )^^(1/2)
    
    //--------------------------------------
    
        FocusR    = ((a^^2)-(b^^2))^^(1/2)         //  223.61    +- Focus L R
        FocusL    =  -FocusR                       // -223.61
        BaseLen   = 2*FocusR                       //  447.21
        rTotalLen = 2*a                            //  600
        rFocusToR = a - FocusR                     //   76.39
        rFocusToL = rTotalLen - rFocusToR          //  523.61
    
        See "A: "+a  +" B: "+b +" FocusR: "+FocusR +" FocusL: "+ (-FocusL) +" BaseLen: "+BaseLen +nl

    //--------------------------------------------
    
    for x = a to -a     step -1
       SLP = a + (e*x)   // (-ae,0) --> P(x,y)
       SRP = a - (e*x)   // ( ae,0) --> P(x,y)
       
       Area =  0.5 * (SRP^^2) * 1 
       
       //See " X : "+x +tab+" SLP: "+SLP +tab+" SRP: "+SRP +tab+" Area: "+Area +tab+" SumLR: "+ (SLP +SRP) +nl
       //See "X: "+x  +tab+" SRP.: "+SRP +tab+" Area: "+Area  +nl
    next
    
    //----------------------------------------
 
    daVinci.setPen(penWhite)
    daVinci.drawLine(-800,   0, 800,   0)    // Horz Axis Left to Right
    daVinci.drawLine(   0,-800,   0, 800)    // Vert Axis Top to Bottom 
    
    //daVinci.drawRect( -a, -b, 2*a, 2*b)
    //daVinci.drawLine( a -rFocusToR, -b, a -rFocusToR, b)
    
    //-----------------------------------------
 
    daVinci.setPen(penAqua)
    IncAngle = 30
    for t = 0 to 360 step 30              // Spacing of Lines 180
        tDeg = t                          // Degrees  
        tRad = tDeg * PI/180              // Radian

        x = a*cos(tRad)                   // P(x,y)
        y = b*sin(tRad)

        daVinci.DrawPoint(x, -(y))

        daVinci.setPen(penBlue)
        daVinci.DrawLine(  FocusR, 0, x, -(y) )        // Focus-Left is on Horizontal Line +- Vertical Position

        daVinci.setPen(penGreen)
        daVinci.DrawLine( -FocusR, 0, x, -(y) )        // Focus-Left is on Horizontal Line +- Vertical Position




        rLen   = ( ((x-FocusR)^^2)  +  (y^^2) )^^(1/2) 
        lLen   = ( ((x-FocusL)^^2)  +  (y^^2) )^^(1/2)
        
        Area =  0.5 * (rLen^^2) * 1   // tDeg
        

        //See "tDeg: "+tDeg +tab+" X: "+x +tab+" Y:"+y  +tab+" lLen: "+lLen +tab+" rLen:"+ rLen +tab+" Area: "+Area  +tab+" Sum: "+(rLen + lLen)   +nl
        //See "t: "+tDeg   +tab+" rLen :"+ rLen +tab+" Area: "+Area  +nl
        
    next
     
    Canvas.setPixMap(MonaLisa)                   ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()                        ### <<< EXEC the Draw  


return

//==============================================
//===============================================
// Two Sides and an Angle between
//         aC=?
//         /\
//   sB=5 /   \
//       /      \  sA=?
//      /         \
//   aA=49--------aB=?
//         sC=7
//-------------------------
// To solve an SAS triangle
// Use The Law of Cosines to calculate the unknown side,
// Then use The Law of Sines to find the smaller of the other two angles,
// And then use the three angles add to 180° to find the last angle.
//
// Two Sides and an Angle between
//------------------------------------------------------------------

Func TriangleSAS(sB,aA,sC)


    if !(isnumber(sB))  (0+ sB)  See "Convert to Number sB: "+sB +nl  ok
    if !(isnumber(aA))  (0+ aA)  See "Convert to Number aA: "+aA +nl  ok
    if !(isnumber(sC))  (0+ sC)  See "Convert to Number sC: "+sC +nl  ok

    if sB = 0       TriMsg = "Tri-SAS: Invalid Side-B: 0"   See TriMsg +nl  return 1 ok
    if aA = 0  aA=1 TriMsg = "Tri-SAS: Invalid Angle-A: 0"  See TriMsg +nl  return 1 ok
    if sC = 0    3  TriMsg = "Tri-SAS: Invalid Side-C: 0"   See TriMsg +nl  return 1 ok     
    
   
    arA = aA  * PI/180    
    sA  = ( (sb^^2) + (sC^^2) - 2*sB*sC*cos(arA) )^^(1/2)   

    arB = (sin(arA) * sB) / sA          // Use Rad
    adB = asin(arB) * 180/PI            // Use Rad

    adA = aA    
    adC = 180 - adA  - adB
         
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
    //--------------------------
    
    Area       = sb * sc * sin(arA) / 2       // Area
    Perimeter  = sa + sb + sc                 // Perimeter
    SemiPeri   = Perimeter / 2                // SemiPerimeter  
    
    aAngleSide[13] = Area           // Area
    aAngleSide[14] = Perimeter      // Perimeter
    aAngleSide[15] = SemiPeri       // Semi-Perimeter
    
Return  aAngleSide                   // 22 values   

//=====================================
//=====================================


