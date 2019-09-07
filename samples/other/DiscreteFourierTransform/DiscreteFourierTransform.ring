# Sample : Discrete Fourier Transform - DFT
# Author : Bert Mariani
# Date   : 2019-09-06

Load "guilib.ring"
load "stdlib.ring"

PI       = 3.1415926535  // Circle is 2*PI radians
TWO_PI   = PI * 2
HALF_PI  = PI / 2
gDegree  = PI / 180      // 2*PI = 360 degrees  Radians to Degrees

///----------------------------
//Parameters

    radiusC      = 100       
    inc          = 4                                // Degrees inc
    nbrSq        = 20                               // Max 0-99 SQUARE count for SineWave
    nbrWaves     = 512                              // Queue size for Wave
    nbrOfCircles = 10           
    
//----------------------------
//DFT - Test Pattern
YY = [100,100,100, -100,-100,-100, 100,100,100, -100,-100,-100]

pointList = [
[ 108, 0 ],
[ 110, 25 ],
[ 112, 50 ],
[ 113.5, 75 ],
[ 115, 100 ],
[ 116, 125 ],
[ 117.5, 150 ],
[ 125, 150 ],
[ 150, 150 ],
[ 175, 150 ],
[ 200, 150 ],
[ 225, 150 ],
[ 225, 175 ],
[ 225, 200 ],
[ 225, 220 ],
[ 200, 220 ],
[ 175, 220 ],
[ 150, 220 ],
[ 125, 220 ],
[ 100, 220 ],
[ 75, 220 ],
[ 50, 220 ],
[ 25, 220 ],
[ 0, 219.5 ],
[ -25, 219 ],
[ -50, 217 ],
[ -75, 215 ],
[ -100, 212 ],
[ -125, 209 ],
[ -150, 203 ],
[ -158, 200 ],
[ -175, 190 ],
[ -190, 175 ],
[ -203, 150 ],
[ -211, 125 ],
[ -220, 100 ],
[ -225, 85 ],
[ -209, 85 ],
[ -200, 100 ],
[ -182, 125 ],
[ -175, 132 ],
[ -150, 145 ],
[ -125, 150 ],
[ -100, 150 ],
[ -87, 150 ],
[ -87.5, 125 ],
[ -89, 100 ],
[ -92, 75 ],
[ -95, 50 ],
[ -100, 25 ],
[ -105, 0 ],
[ -113, -25 ],
[ -122, -50 ],
[ -136, -75 ],
[ -152, -100 ],
[ -170, -125 ],
[ -186, -150 ],
[ -189, -175 ],
[ -178, -200 ],
[ -175, -205 ],
[ -150, -220 ],
[ -125, -220 ],
[ -100, -202 ],
[ -85, -175 ],
[ -77, -150 ],
[ -73, -125 ],
[ -70, -100 ],
[ -67.5, -75 ],
[ -65, -50 ],
[ -62, -25 ],
[ -60, 0 ],
[ -57, 25 ],
[ -54.5, 50 ],
[ -51.5, 75 ],
[ -49, 100 ],
[ -47, 125 ],
[ -45, 150 ],
[ -25, 150 ],
[ 0, 150 ],
[ 25, 150 ],
[ 50, 150 ],
[ 58, 150 ],
[ 55, 125 ],
[ 53, 100 ],
[ 51, 75 ],
[ 49, 50 ],
[ 47, 25 ],
[ 44.5, 0 ],
[ 42, -25 ],
[ 40, -50 ],
[ 38.5, -75 ],
[ 37.5, -100 ],
[ 37, -125 ],
[ 37.5, -150 ],
[ 43, -175 ],
[ 49, -185 ],
[ 66, -200 ],
[ 75, -205 ],
[ 100, -215 ],
[ 125, -218 ],
[ 150, -214 ],
[ 175, -203 ],
[ 179, -200 ],
[ 201.5, -175 ],
[ 213, -150 ],
[ 221, -125 ],
[ 226.5, -100 ],
[ 227.5, -88 ],
[ 210, -88 ],
[ 209, -100 ],
[ 200, -123 ],
[ 197, -125 ],
[ 175, -141 ],
[ 150, -144 ],
[ 125, -134 ],
[ 117, -125 ],
[ 109, -100 ],
[ 106, -75 ],
[ 106, -50 ],
[ 106.5, -25 ],
[ 108, 0 ]
]

//----------------------------

initX  = 0  initY  = 0 # initial position of cursor
finalX = 0  finalY = 0 # final  position of cursor
oldX   = 0  oldY   = 0 # old        position of cursor


width  = 10
height = 12

xPos    = 100
yPos    = 100
xWidth  = 1200
yHeight = 900    ### Canvas position on Screen

counter = 1      ### Modulo 3 to change Pen Color

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite  = new qcolor() { setrgb(  0,255,255,255) }  ### Cyan

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }
penYellow   = new qpen() { setcolor(colorYellow) setwidth(2) }
penWhite    = new qpen() { setcolor(colorWhite)  setwidth(1) }

curPen      = penGreen

###-----------------

MyApp = new qApp 
{
     win = new qWidget()
     {
          setWindowTitle("Discrete Fourier Transform")
          setGeometry(xPos, yPos, xWidth, yHeight)   ### Window Pos and Size

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
                MonaLisa     = new qPixMap2( xWidth, yHeight)

                daVinci = new qpainter()
                {
                    begin(MonaLisa)
                    translate(200,300)            ### TRANSLATE CO-ORD x,y   0,0    MAPS TO 300,300
                    #endpaint()                   ### This will Stop the Painting       
                }

                setPixMap(MonaLisa)
          }

          SliderCircle = new qslider(win) 
          {
                setGeometry(10, 2, 100, 20)
                setOrientation(Qt_Horizontal)
                setTickInterval(1)                              // Count of nbrSq 1...100
                setValue(10)                                        // 0...50...100
                setValueChangedEvent("SliderEventCircle()")
          }

          btnCircle = new qpushbutton(win)
          {
                setGeometry(120, 2, 100, 20)
                setText("Circle-"+nbrSq)
                setClickEvent("pDrawObjects()") 
          }       

          SliderAngle = new qslider(win) 
          {
                setGeometry(240, 2, 100, 20)
                setOrientation(Qt_Horizontal)
                setTickInterval(1)                          // Count of Anble  1...10
                setValue(5)                                     
                setValueChangedEvent("SliderEventAngle()")
          }       

          btnAngle = new qpushbutton(win)
          {
                setGeometry(350, 2, 100, 20)
                setText("Angle-Incr-"+inc)
                setClickEvent("pDrawObjects()") 
          }
          
          
          btnExit = new qpushbutton(win)
          {
                setGeometry(590, 2, 100, 20)
                setText("Exit")
                setClickEvent("pExit()") 
          }
          
          show()
     }
     exec()
}

###--------------------------------------------------------------------

Func pExit()
    MyApp.quit()
return

###------------------------------------------------------

Func DrawUpdate()
                
     ### Draw vertical lines from values[] array
     ### First Black out canvas-picture
     
     //MonaLisa.fill(colorBlack)

      Canvas.setpixmap(MonaLisa)              ### Need this setpixmap to display imageLabel   
      win.setwindowtitle("Discrete Fourier Transform: Circles: "+ nbrSq  +" Angle: "+ inc  )
      win.show()                                  ### Need this to show       to display imageLabel
            
      MyApp.ProcessEvents()                   ###<<< EXEC the Draw
                     
return

###------------------------------------------------------

Func pPress
     win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY )
     
     initX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
     initY = myfilter.getglobaly()      ### Screen co-ord, NOT Canvas

     //initX = myfilter.getx()              ### Screen co-ord, NOT Canvas
     //initY = myfilter.gety()              ### Screen co-ord, NOT Canvas

     ### Change Pen Color
     if  counter % 3 = 0     daVinci.setpen(penRed)     curPen = penRed
     but counter % 3 = 1     daVinci.setpen(penGreen)   curPen = penGreen
     else                        daVinci.setpen(penBlue)    curPen = penBlue
     ok
     counter++
     
     daVinci.setCompositionMode(26)     ###  THIS is the MAGIC - Erase Old Line when Redrawn
     
     oldX = initX                               ### Save Pressed point as OLD points
     oldY = initY
     
return

###------------------------------------------------------------------------

Func pRelease
     win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY +" Width "+ (finalX-initX) + " Height "+ (finalY-initY) )

     finalX = myfilter.getglobalx()             ### Screen co-ord, NOT Canvas
     finalY = myfilter.getglobaly()

     pDrawObjects()

     Canvas.setPixMap(MonaLisa)                 ### Need this setpixmap to display imageLabel
     Canvas.show()
     
return

###------------------------------------------------------------------------

Func pMove
     win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY +" Width "+ (finalX-initX) + " Height "+ (finalY-initY) )

     finalX = myfilter.getglobalx()         ### Screen co-ord, NOT Canvas getx()  gety()
     finalY = myfilter.getglobaly()

     pDrawObjects()
    
     Canvas.setpixmap(MonaLisa)             ### Need this setpixmap to display imageLabel
     Canvas.show()
     
     oldX = finalX   ### Save OLD points
     oldY = finalY
     
return


###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
     Rec = win.framegeometry()

     WinWidth  = Rec.width()                 ### Current Values
     WinHeight = Rec.height()                ### 
     
     WinLeft   = Rec.left() +8               ### <<< QT FIX because of Win Title
     WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
     WinRight  = Rec.right()
     WinBottom = Rec.bottom()

     win{ setwindowtitle("Window ReSize: Win " +     WinWidth + "x" + WinHeight + 
            " --- LT " +  WinLeft + "-" + WinTop     + " --- RB " + WinRight + "-" + WinBottom      ) }

return

###---------------------------------------
### Window Moved

Func WhereMoved()

     xPos = win.x()  +8           ### <<< QT FIX because of Win Title
     yPos = win.y() +30           ### <<< QT FIX because of Win Title

     win{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }  

return

###===============================================
###===============================================
### Sin() = Vertical     Cos() - Horzontal
//
// See "Sin(15) radians = " + sin(15)                =>  0.65
// See "Sin(15) degree  = " + sin(15 * 3.14/180) =>  0.26
// See "Cos(15) radians = " + cos(15)                => -0.76
// See "Cos(15) degree  = " + cos(15 * 3.14/180) =>  0.97


Func pDrawObjectsPI()
	for i = 1 to len(pointList) -1
		daVinci.drawPoint( pointList[i][1], -pointList[i][2] )
		daVinci.drawLine( pointList[i][1], -pointList[i][2] ,  pointList[i+1][1], -pointList[i+1][2] )
	next

return

//------------------------------------------

Func pDrawObjects()

    oVertQ = new Queue    
	oHorzQ = new Queue
	
    for nbrOfCircles = 1 to 2              

		// Discrete Fourier Transform call for the List of X-Y Points
		YY = []
		XX = []
		
		for i = 1 to len(pointList)
			Add(XX, pointList[i][1])
			Add(YY, pointList[i][2])
		next

		FourierX = DFT(XX)
		FourierY = DFT(YY)

		dt    = TWO_PI / len( fourierY)    ### Increment angle amont

        //-------------------------------------------------------------------
        // Around each Circle = TWO_PI or 360 degrees	
			
        for angle = 0 to 360 step  dt      ### Increment by each point in list      
        
            MonaLisa.fill(colorBlack)           // Clear screen

            xV     = 1  	yV     = 1    
			prevXV = 1      prevYV = 1
			
			xH     = 1      yH     = 1   
			prevXH = 1      prevYH = 1
			horz   = 500    vert   = 150   // Draw Horz circle offsets
			piH    = 500    piV    = 200   // Draw PI offsets
			
			//----------------------------
			// EpiCycles - Left Vertical Circles
			
            for i = 1 to len(fourierY)
                                                      			
					oldXV = xV
					oldYV = YV
					
					freq   = fourierY[i][3]
					radius = fourierY[i][4]
					phase  = fourierY[i][5]
										
					xV += radius * cos(freq * angle + phase + HALF_PI)
					yV += radius * sin(freq * angle + phase + HALF_PI )
					      
                     
                daVinci.setpen(penYellow)               
                daVinci.drawLine(oldXV , -oldYV +piV, XV, -YV +piV)  // Draw Line - oldCircleCtr to newCircleCtr 
                
                daVinci.setpen(curPen)
                DrawCircle(oldXV, -oldYV +piV, radius)               // Draw multiple Vertical Circles
            
            next
			
			//-------------------------------------------
			// EpiCycles - Right Horizontal Circles
			
			for i = 1 to len(fourierX)
                                                      			
					oldXH = xH
					oldYH = YH
					
					freq   = fourierX[i][3]
					radius = fourierX[i][4]
					phase  = fourierX[i][5]
										
					xH += radius * cos(freq * angle + phase ) // + HALF_PI)
					yH += radius * sin(freq * angle + phase ) // + HALF_PI )
					      
                     
                daVinci.setpen(penYellow)               
                daVinci.drawLine(oldXH +horz, -oldYH -vert, XH  +horz , -YH -vert)   // Draw Line - oldCircleCtr to newCircleCtr 
                
                daVinci.setpen(curPen)
                DrawCircle(oldXH +horz , -oldYH -vert, radius)             // Draw multiple Horizontal Circles
            
            next

            //---------------------------------------------------
            // VertWave Queue - History - Add modified y-Point to end of Queue
			// QUEUE - FirstIn-FirstOut,  Add to LastIn   
                
            oVertQ.add(yV)    // 1st Set of Circles on Left for vertical
			oHorzQ.add(xH)    // 2nd Set of Circles on Right for horizontal 
			
			lastPos = len(oVertQ)
			
			// Draw PI Shape
			daVinci.setpen(penYellow) 
			for k = lastPos to 1 step -1
                curX =   oHorzQ[k]                                // Draw to Right side
                curY =  -oVertQ[k]							      // Y goes up - make negative
           	 
                 daVinci.DrawLine( curX +piH, curY +piV, prevXV +piH, prevYV +piV)  
				 
                prevXV = curX     prevYV  = curY
                prevXH = curX     prevYH  = curY
				
            next
			daVinci.setpen(curPen)
			 
			// Draw H and V Lines to PI Shape point
			  daVinci.setpen(penWhite)
			  
			  daVinci.DrawLine(xV ,      -yV +piV,  oHorzQ[lastPos] +horz, -oVertQ[lastPos] +piV )    // Draw Horz Line in Circles to Wave
			  daVinci.DrawLine(xH +horz, -yH -vert, oHorzQ[lastPos] +horz, -oVertQ[lastPos] +piV )    // Draw Vert Line in Circles to Wave
			  
			  daVinci.setpen(curPen)
           
            if lastPos > nbrWaves
                oVertQ.remove()       // QUEUE - Remove Start point
				oHorzQ.remove()
            ok       

            DrawUpdate()                // Animated Delay
			
			//------------------------------------------------------
            
        next
        
    next

return

###--------------------------

###=========================================
###=========================================

###-----------------------------------------
### DrawCircle(x,y,radius)
### DrawCirclePoint(x,y,radius,angle
### DrawCircleLine(x,y,radius,angle
###
### See "Sin(15) radians = " + sin(15)                =>    0.65
### See "Sin(15) degree  = " + sin(15 * 3.14/180) =>    0.26


//------------------------------------------
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

//------------------------------------------
// DrawCirclePoint on Circle Circumference


Func DrawCirclePoint(x,y,radius,angle)
    
    HCenter = x
    VCenter = y

    radian = Angle * gDegree
    
    x =  cos(radian)    // Cos() Horz X
    y =  sin(radian)    // Sin() Vert Y

    XPos =  x * radius
    YPos =  y * radius

    daVinci.drawPoint(HCenter + XPos, VCenter - YPos)   // Minus Y goes up screen
    
return [XPos,YPos]

//------------------------------------------
// DrawCircleLines from CenterCircumference

Func DrawCircleLine(x,y,radius,Angle)

    HCenter = x
    VCenter = y
    
    radian = Angle * gDegree
    
    x =  cos(radian)    // Cos() Horz X
    y =  sin(radian)    // Sin() Vert Y

    XPos =  x * radius
    YPos =  y * radius

    daVinci.drawLine(HCenter, VCenter, HCenter + XPos, VCenter - YPos)  // Minus Y goes up screen

return [XPos,YPos]
//------------------------------------------
//------------------------------------------
// DrawCircleLines from CenterCircumference

Func FindCirclePoint(x,y,radius,Angle)

    HCenter = x
    VCenter = y
    
    radian = Angle * gDegree
    
    x =  cos(radian)    // Cos() Horz X
    y =  sin(radian)    // Sin() Vert Y

    XPos =  x * radius
    YPos =  y * radius

return [XPos,YPos]
//------------------------------------------

###-------------------------------------
### Speed of Move Animation
### Slider Values go from 0 to 100  on the Bar
### Low 1  to   10 High

Func SliderEventCircle()

    nbrSq = SliderCircle.value()                    // Max 100/10 = 10  Min 10 / 10 = 1  
    nbrSq = ceil(nbrSq)

    //See "SliderValueCircle: "+ SliderCircle.value() +" nbrSq "+ nbrSq +nl
    
    nameCircle = "Circle-"+ nbrSq
    btnCircle.setText(nameCircle)   
    DrawUpdate()                                         // Refresh screen
    
return

###------------------------------------
### Angle Increment

Func SliderEventAngle()

    inc = SliderAngle.value() / 10              // Max 100/10 = 10  Min 10 / 10 = 1  
    inc = ceil(inc)
    if inc = 0  inc = 1 ok                          // Angle inc by 0 => 1
    
    //See "SliderValueAngle: "+ SliderAngle.value() +" inc "+ inc +nl

    nameAngle = "Angle-Incr-"+ inc
    btnAngle.setText(nameAngle) 
    DrawUpdate()                                         // Refresh screen
    
return

//========================================
### Discrete Fourier Transform
### YY = [100,100,100, -100,-100,-100, 100,100,100, -100,-100,-100]
### dft(YY)

//--------------------------------------------
// Test with these 12 values of a Vert wave -_-_

Func TestFourier()
  y = [100,100,100,-100,-100,-100,100,100,100,-100,-100,-100 ]
  fourierY = dft(y)
  
/*  
	See "Return BigX Fournier: "+nl 
	for i = 1 to len(fourierY)
		See "i: "+ i
		for j = 1 to 5
			See " "+ fourierY[i][j] + tab
		next
			See nl
	next
*/
return

//===========================================
//  Discrete Fourier Transform
//
//  BigXk = SUM from n=0 to N-1 OF ( xn * (cos(2pikn/N) -i*sin(2pikn/N) ) )
//  BigX  = 1 Wave
//
// Pass it a list of values or points

Func DFT(x) 
  
  BigN = len(x)
  BigX = list(BigN)       // The Wave Array output - make it same size of input
      
  for k = 1 to BigN
    re = 0
    im = 0

    for n = 1 to BigN
      phi = (TWO_PI * k * n) / BigN
	  
      re += x[n] * cos(phi)
      im -= x[n] * sin(phi)
    next

    re = re / BigN   // Average
    im = im / BigN   // Average

    freq  = k
    amp   = sqrt((re * re) + (im * im))
    phase = atan2(im, re)
	
	BigX[k] = [ re, im, freq, amp, phase ]    		// <<<=== Add a line of values to [][]
	
    //Add ( BigX, [ re, im, freq, amp, phase ] )   	// Alternate way of adding to array  when BigX = []
	//See "BigX[k]: "+k +tab+ re +tab+ im +tab+ freq +tab+  amp +tab+ phase +nl

  next
  
return BigX


//===================================================

