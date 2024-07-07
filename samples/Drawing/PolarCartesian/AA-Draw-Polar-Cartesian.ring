# Sample : Polar-Cartesian Coordinates
# Author : Bert Mariani
# Date   : 2024/07/01
#
# https://mathinsight.org/polar_coordinates#:~:text=One%20might%20neet%20to%20add,2%CE%B8%3Darctanyx
#
#------------------------------------
# We typically restrict θ to be in the interal 0 ≤θ< 2π
#
# 360/(2*PI) = 57.3 = 1 rad
# Degrees to Radians: Degree * PI/180
# Radians to Degrees: Radian * 180/PI
#
#------------------------------

Load "guilib.ring"

flag = 0

nX = 0  nY = 0 # initial position of cursor
fX = 0  fY = 0 # final   position of cursor
oX = 0  oY = 0 # old     position of cursor

width  = 10
height = 12

xPos    =  100
yPos    =  100
xWidth  = 1000
yHeight =  700   ### Canvas position on Screen

indent  = 50    ### Make Canvas smaller

counter = 1     ### Modulo 3 to change Pen Color

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorWhite  = new qcolor() { setrgb(255,255,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorMix    = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorCyan   = new qcolor() { setrgb(000,255,255,255) }

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
penWhite    = new qpen() { setcolor(colorWhite)  setwidth(1) }   // Square point
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }
penCyan     = new qpen() { setcolor(colorCyan)   setwidth(1) }

brushS      = new qbrush() { setstyle(1)  setcolor (colorMix)  }   ### Yellow
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlack)}   ### Black
brushE      = new qbrush() { setstyle(0)  setcolor (colorMix)  }   ### Empty

//----------------------
// Bezier Points
     
W = [ [250,300],  // 2 Points
      [700,300]
    ]        
    
cCartX  = 220    cCartY  = 300  
cPolarX = 640    cPolary = 300

Px   = 50     Py = 100            //  Rect TopLeft 50-100  Px---Py    PxLx---Py
Lx   = 400    Ly = 400            //  Rect Lenght Size     PxLx-Py    PxLx-PyLy
xRf  = Px+Lx  yRf= Py+Ly          //  Final max x y
xRc  = (xRf+Px)/2                 //  MidPoints
yRc  = (yRf+Py)/2                 //  Rect HalfPoint 200+25  200+25

Cx  = 500    Cy = 100             //  Circle TopLeft 500-100
Di  = Cx-Cy                       //  Diameter 400 same as Rect
Cr  = Di / 2                      //  Radius 200 of Circle
xCf = Cx+Di                       //  Bottom X circle
yCf = Cy+Di                       //  Bottom Y circle

xCc = (Cx + Cr)                   // Circle Center X
yCc = (Cy + Cr)                  // Circle Center Y


PI = 3.14159265
     // Degrees to Radians: Degree * PI/180
     // Radians to Degrees: Radian * 180/PI
    

selectBezierPoint = 0  // Select and Move Point for New drawing
oldBezierX = 0
oldBezierY = 0

###-----------------

new qApp 
{
    win = new qWidget()
    {
        setWindowTitle("Draw Lines Using the Mouse")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        myfilter = new qallevents(win)

            ###------------------------------------------
            ### Mouse Event
        
            myfilter.setMouseButtonPressEvent("pPress()")
            myfilter.setMouseButtonReleaseEvent("pRelease()")
            myfilter.setMouseMoveEvent("pMove()")
        
            installeventfilter(myfilter)
        
            ###------------------------------------------
            ### ReSizeEvent ... Call WhereAreWe function

            myfilter.setResizeEvent( "WhereAreWe()")
            myfilter.setMoveEvent( "WhereMoved()" )  

        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( 2000, 2000)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               #endpaint()                  ### This will Stop the Painting

               ###-------------------------------
               ### Draw Yellow Rect in the Middle
                   #setBrush(brushS)             ### Brush - Solid, Yellow    
                   #setpen(penBlue)
                   #drawRect(indent, indent, xWidth - (2*indent), yHeight - (2*indent))    
            }

            setPixMap(MonaLisa)
        }

        ###-----------------------------------
        ### Font Type and Size
        
        oFont = new qfont("Calibri",11,0,0)
        setfont(oFont)
        
              
        btnB = new qpushbutton(win)
        {
            setgeometry(02, 02, 100, 25)
            settext("Polar-Cartesian")
            setclickevent("pBezier()") 
            setStyleSheet("background-color: aqua")
        }           

             
        btnClr = new qpushbutton(win)
        {
            setgeometry(110, 02, 90, 25)
            settext("Clear")
            setclickevent("pClear()") 
            setStyleSheet("background-color: aqua")
        }
        
        labelEqText = new qLabel(win) {
                    setGeometry(210, 02, 650, 25)  
                    setText(" CARTESIAN: X = r*cosθ | Y = r*sinθ  ||  POLAR: (r,θ) |  r = √(x^2 + y^2) | θ = arctan(y/x) | " )  
                    setStyleSheet("background-color: white")
        }

        
        labelEqXY  =  new qLineEdit(win)  { 
                     setGeometry(50, 50, 160, 25)  
                     setText("(X,Y) = (0.0, 0.0)")             
        }   

        labelEqRad  =  new qLineEdit(win)  { 
                     setGeometry(500, 50, 160, 25)  
                     setText("R = 0.0 | θ = 0.0 ")             
        }   

        
     
        show()
    }
    exec()
}

###========================================


Func pPress
    win.setWindowTitle("Press: New-Screen: " + nX +"-" +nY +" Final: "+ fX +"-" +fY + " Window-Getx: "+ myfilter.getx() +"-"+ myfilter.gety() )
    
    nX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    ny = myfilter.getglobaly()      ### Screen co-ord, NOT Canvas
 
//  daVinci.setCompositionMode(26)  ###  THIS is the MAGIC - Erase Old Line when Redrawn
    
    oX = nX                         ### Save Pressed point as OLD points
    oY = nY
     
     //-------------------------------------------------------
     // Select BezierPoint Baser on Co-Ordinate RANGE = Press
     
     if flag = 4                    // Bezier selected
        bX = myfilter.getx()        // Position of Dot
        bY = myfilter.gety()
        
        range = 5
        selectBezierPoint = 0
        
        for i = 1 to 2
            if bX >= W[i][1] - range AND bX <= W[i][1] + range  AND 
               bY >= W[i][2] - range AND bY <= W[i][2] + range 
                  
                  selectBezierPoint = i                         // Point 1 or 2

            ok
        next
		
		Bezier()
        
     ok
     
return

###========================================

Func pRelease
    win.setWindowTitle("Press: New-Screen: " + nX +"-" +nY +" Release: "+ fX +"-" +fY +" Dist: "+ (fX-nX) + "-"+ (fY-nY) + " Window-Getx: "+ myfilter.getx() +"-"+ myfilter.gety() )

     //---------------------------------------------
     // Bezier Release - Update Point
     
     if flag = 4                      // Bezier selected
        //selectBezierPoint = 1 to 2
        
        if selectBezierPoint > 0
            W[selectBezierPoint][1] = myfilter.getx() 
            W[selectBezierPoint][2] = myfilter.gety() 
        ok
        
        Bezier()                      // Update drawing of Bezier Points   
     ok
     


     //----------------------------------------------------------------
    
    fX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()

    Canvas.setPixMap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
     

return

###========================================

Func pMove
    win.setWindowTitle("Press: New-Screen: " + nX +"-" +nY +" Move: "+ fX +"-" +fY +" Dist: "+ (fX-nX) + "-"+ (fY-nY) + " Window-Getx: "+ myfilter.getx() +"-"+ myfilter.gety())

     //-------------------------------------------------
     // Select BezierPoint = Move
     // Point or Dot should be Inside the Rect or Circle
     
     if flag = 4                    // Bezier selected

        if selectBezierPoint > 0
    
            daVinci.setpen(penWhite)
            
            xPoint = myfilter.getx()
            yPoint = myfilter.gety()
            
            if xPoint < Px OR ( xPoint > xRf AND xPoint < Cx )  OR  xPoint > xCf  OR   
               yPoint < Py OR yPoint > yRf
               // Ouside Bounds
               
            else
                W[selectBezierPoint][1] = myfilter.getx() 
                W[selectBezierPoint][2] = myfilter.gety() 
                           
                daVinci.drawPoint( oldBezierX, oldBezierY )           // ERASE Old point
                daVinci.drawPoint( myfilter.getx(), myfilter.gety() )
                
                Bezier()   // Update drawing of Bezier Points
                
                oldBezierX = myfilter.getx()
                oldBezierY = myfilter.gety()
            ok
        ok      
     ok
     
     //-------------------------------------------------------------
     
    fX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()

    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
    
    oX = fX  ### Save OLD points
    oY = fY
         
return


###==========================================
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
    Rec = win.framegeometry()

    WinWidth  = Rec.width()             ### Current Values
    WinHeight = Rec.height()            ### 
    
    WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
    WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
    WinRight  = Rec.right()
    WinBottom = Rec.bottom()

    win{ setwindowtitle("Window ReSize: Win " +  WinWidth + "x" + WinHeight + 
            " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom  ) 
       }
return

###==========================================
### Window Moved

Func WhereMoved()

    xPos = win.x()  +8          ### <<< QT FIX because of Win Title
    yPos = win.y() +30          ### <<< QT FIX because of Win Title

    win{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }  
return

###==========================================

Func pClear()


     
    daVinci.setCompositionMode(0)          ### Put back to default mode 0
    
    daVinci.setBrush(brushSB)              ### Brush - Solid Black  
    daVinci.setPen(penBlack)
    daVinci.drawRect(0, 0, xWidth, yHeight)
    
//  daVinci.setCompositionMode(26)         ### THIS is the MAGIC - Erase Old Line when Redrawn
    
	MonaLisa.fill(colorBlack)              // ===<<< BLANK OUT OLD IMAGE !!!
	
    Canvas.setpixmap(MonaLisa)             ### Need this setpixmap to display imageLabel
    Canvas.show()
return

###========================================
Func pBezier()

    flag = 4
    //ClearButtonColor()
    //btnB.setStyleSheet("background-color: yellow")  // Color the Button
	
	pRelease()  // Force the drawing to appear - Rect and Circle
    
	
return         


###========================================
Func ClearButtonColor()
   
    btnB.setStyleSheet("background-color: lightgray")     
         
return

###========================================
Func pDrawObjects()
  
    if  flag = 4   // Bezier
        Bezier()              
    ok
                 
return



###========================================
### BEZIER
### https://pomax.github.io/bezierinfo/
###

Func Bezier()

pClear()

//---------------------------------------------
// Center of Rect and circle
X1 = W[1][1]  X2 = W[2][1]    // Rect  center
Y1 = W[1][2]  Y2 = W[2][2]    // Cirle center

   
//---------------------------------------------                     
// Draw RECTANGLE

daVinci.setpen(penRed) 
   daVinci.DrawRect( Px,  Py,  Lx,  Ly  ) 
   daVinci.DrawLine( xRc, Py, xRc,  yRF )          // Vertical  line
   daVinci.DrawLine( Px,  yRc, xRf, yRc )          // Horizontal  line

daVinci.setpen(penWhite)
   daVinci.DrawEllipse(W[1][1]-4, W[1][2]-4, 8, 8) // Dot Size at center
   
//---------------------------
// Draw CIRCLE

daVinci.setpen(penGreen)
   daVinci.DrawRect(    Cx, Cy, Lx, Ly  )          // Added for Visual boundary
   daVinci.DrawEllipse( Cx, Cy, Di, Di  ) 
   

   daVinci.DrawLine( xCc, Cy, xCc, yCf )           // Vertical  line
   daVinci.DrawLine( Cx, yCc, xCf, yCc )           // Horizontal  line

daVinci.setpen(penWhite)
   daVinci.DrawEllipse(W[2][1]-4, W[2][2]-4, 8, 8) // Dot at center
   
//---------------------------------------
      
    
cCartX  = xRc    cCartY  = yRc                     // Center Cartsian of Rectanle
cPolarX = xCc    cPolary = yCc                     // Center Polar of Circle
   
//---------------------------------------
// Polar coordinates (r,θ) | r = √(x^2 + y^2) | θ = arctan(y/x) 
// Cartesian coordinates:    x = r*cosθ | y = r*sinθ   

    theta  = 45                                    // degrees
    Xwidth = 50  Yheight = 50                      // Arc Angle Draw Size
    
    // ARC Circles -- can NOT be filled
    // Each step for Angle parameter is 1/16th of a Degree, 
    // void drawArc(x, y, width, height, startAngle, spanAngle)
    // Subtract half of width and height (rectangle QT) 
    
    //------------------------------------
    // CARTESIAN
    
       if selectBezierPoint = 1                // Cartesian -5 to +5 for x and Y
    
        xCart = W[1][1]                        // X dot position
        yCart = W[1][2]                        // X dot position
        
        if xCart < Px OR xCart > xRf OR
           yCart < Py OR yCart > yRf
           
           return   // Out of Bounds
        else
                       // From          To center line of Rect
        daVinci.DrawLine( xCart, yCart, cCartX, yCart )   // Horz Line to Center Vertical
        daVinci.DrawLine( xCart, yCart, xCart,  cCartY)   // Vert Line to Center Horizontal
        
		//----------------------------------------------------
        //Covert Dot position in Pixels to Range -5 to0 to +5
 
        XValue = (xCart - 250  ) / 40   // Convert to -5 to +5
        YValue = (300   - yCart) / 40  
        
        labelEqXY.setText("(X,Y) = "+ XValue +", "+ YValue) 
        
        //------------------------------------------
        // Map it to the Circle side
        
        xL = xCart - xRc                 // xLenght
        yL = yCart - yRc                 // yLenght
        
        if xL=0  xL=1 ok                 // Divide by Zero
        rL      = (xL^^2 + yL^^2)^^(1/2) // rLenght
        rad     = atan(yL/xL)      
        thetaXY = rad * 180/PI           // Plus-Minus Theta
        
        //See "xRc "+ xRc +" yRc "+ yRc +" xCart "+ xCart +" yCart "+ yCart +" xL-yL-rL: "+ xL +" "+ yL +" "+ rL +" Rad "+ rad +" thetaXY "+ thetaXY +nl
       
        if xL >=  0  and yL <= 0   theta =     - thetaXY  ok          
        if xL <=  0  and yL <= 0   theta = 180 - thetaXY  ok          
        if xL <=  0  and yL >= 0   theta = 180 - thetaXY  ok          
        if xL >=  0  and yL >= 0   theta = 360 - thetaXY  ok
       
        daVinci.DrawLine( cPolarX, cPolarY, xCart+cX-pX, yCart+cY-pY  )
        daVinci.drawPie(cPolarX-Xwidth/2+1, cPolarY-Yheight/2+1, Xwidth, Yheight, 16*0, 16*theta)  

        radius = rL / 40
        labelEqRad.setText("R = "+ radius +" | θ = "+ theta )       
       
       ok  // Inbounds
    ok
    
    //-------------------------------------
    // POLAR
    if selectBezierPoint = 2    // Polar
     
		xCart = W[2][1] - cPolarX   
		yCart = W[2][2] - cPolarY

		if xCart = 0  xCart = 1 ok         // Divide by Zero
		rLength  =  (yCart^^2 + xCart^^2)^^(1/2)
		rad      =  aTan(yCart / xCart) 
		thetaXY  =  rad * 180/PI           // Plus-Minus Theta

		if xCart >=  0  and yCart <= 0   theta =     - thetaXY  ok         
		if xCart <=  0  and yCart <= 0   theta = 180 - thetaXY  ok         
		if xCart <=  0  and yCart >= 0   theta = 180 - thetaXY  ok         
		if xCart >=  0  and yCart >= 0   theta = 360 - thetaXY  ok
		  

		daVinci.DrawLine( cPolarX, cPolarY, W[2][1], W[2][2] )      
		daVinci.drawPie(cPolarX-Xwidth/2+1, cPolarY-Yheight/2+1, Xwidth, Yheight, 16*0, 16*theta)

        radius = rLength /40   // 200/40 = 0 to 5 units
        rValue = rad
        tValue = theta
        
        labelEqRad.setText("R = "+ radius +" | θ = "+ theta )
      
		//--------------------------------------
		//Map it to the Rectangle side   
		  
		xCart = W[2][1] -Lx-Px
		yCart = W[2][2]
		  
		//                From Dot       To center line of Rect
		daVinci.DrawLine( xCart, yCart, xRc,   yCart )   // Horz half
		daVinci.DrawLine( xCart, yCart, xCart, yRc   )   // Vert half

		//See"xCart: "+ xCart +" yCart: "+ yCart +nl

		XValue = (xCart - 250  ) / 40                    // Convert to -5 to +5 
		YValue = (300   - yCart) / 40                        
		labelEqXY.setText("(X,Y) = "+ XValue +", "+ YValue)

		//See"xCart: "+ xCart +" yCart: "+ yCart +nl
    
    ok
    
return

###-----------------------------------
/*
Px   = 50     Py = 100          //  Rect TopLeft 50-100  Px---Py    PxLx---Py
Lx   = 400    Ly = 400          //  Rect Lenght Size     PxLx-Py    PxLx-PyLy
xRf  = Px+Lx  yRf= Py+Ly        //  Final max x y
xRc  = (xRf+Px)/2               //  MidPoints
yRc  = (yRf+Py)/2               //  Rect HalfPoint 200+25  200+25

Cx  = 500    Cy = 100           //  Circle TopLeft 500-100
Di  = Cx-Cy                     //  Diameter 400 same as Rect
Cr  = Di / 2                    //  Radius 200 of Circle
xCf = Cx+Di                     //  Bottom X circle
yCf = Cy+Di                     //  Bottom Y circle

xCc = (Cx + Cr)                 // Circle Center X
yCc = (Cy + Cr)                 // Circle Center Y
*/
