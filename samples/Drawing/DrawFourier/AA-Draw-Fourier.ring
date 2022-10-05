# Sample : AA-Draw-Fourier 
# Author : Bert Mariani

load "guilib.ring"
load "stdlib.ring"

PI		  = 3.1415926535	// Circle is 2*PI radians
gDegree = PI / 180		// 2*PI = 360 degrees  Radians to Degrees
gSleepDelay = 0.00		// Animated Delay

///----------------------------
//Parameters

	radiusC = 100		
	xOff	  = 250							// Horizontal for SineWave
	inc	  = 4								// Degrees inc
	nbrSq	  = 20								// Max 0-99 SQUARE count for SineWave
	nbrWaves = 512							// oSinQ Queue size for SineWave
	nbrOfCircles = 10			
	
//----------------------------

initX	 = 0	initY	 = 0 # initial position of cursor
finalX = 0	finalY = 0 # final	position of cursor
oldX	 = 0	oldY	 = 0 # old		position of cursor


width	 = 10
height = 12

xPos	  = 100
yPos	  = 100
xWidth  = 1200
yHeight = 600	 ### Canvas position on Screen

counter = 1		 ### Modulo 3 to change Pen Color

###--------------

colorGreen	= new qcolor() { setrgb(000,255,000,255) }
colorRed		= new qcolor() { setrgb(255,000,000,255) }
colorBlue	= new qcolor() { setrgb(000,000,255,255) }
colorBlack	= new qcolor() { setrgb(000,000,000,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite  = new qcolor() { setrgb(255,255,255,255) }

penGreen		= new qpen() { setcolor(colorGreen)	 setwidth(1) }
penRed		= new qpen() { setcolor(colorRed)	 setwidth(1) }
penBlue		= new qpen() { setcolor(colorBlue)	 setwidth(1) }
penBlack		= new qpen() { setcolor(colorBlack)	 setwidth(1) }
penYellow	= new qpen() { setcolor(colorYellow) setwidth(2) }
penWhite   	= new qpen() { setcolor(colorYellow) setwidth(1) }

curPen		= penGreen

brushS		= new qbrush() { setstyle(1)	setcolor (colorYellow)}		### Yellow
brushSB		= new qbrush() { setstyle(1)	setcolor (colorBlack) }		### Black
brushE		= new qbrush() { setstyle(0)	setcolor (colorYellow)}		### Empty

###-----------------

MyApp = new qApp 
{
	 win = new qWidget()
	 {
		  setWindowTitle("Fourier Series")
		  setGeometry(xPos, yPos, xWidth, yHeight)	 ### Window Position and Size

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
				MonaLisa	 = new qPixMap2( xWidth, yHeight)

				daVinci = new qpainter()
				{
					begin(MonaLisa)
					translate(300,300)			  ### TRANSLATE COORDINATE x,y	 0,0	MAPS TO	300,300
					#endpaint()						  ### This will Stop the Painting		
				}

				setPixMap(MonaLisa)
		  }

		  SliderCircle = new qslider(win) 
		  {
				setGeometry(10, 2, 100, 20)
				setOrientation(Qt_Horizontal)
				setTickInterval(1)								// Count of nbrSq 1...100
				setValue(10)										// 0...50...100
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
				setTickInterval(1)							// Count of Angle  1...10
				setValue(5)										
				setValueChangedEvent("SliderEventAngle()")
		  }		  

		  btnAngle = new qpushbutton(win)
		  {
				setGeometry(350, 2, 100, 20)
				setText("Angle-Incr-"+inc)
				setClickEvent("pDrawObjects()") 
		  }
		  
        
        comboWaveType = new QComboBox(win) 
        {
            setgeometry(470, 2, 100, 20)
            comboList = ["SquareWave","SawTooth","Pulse","Triangle"]
            for x in comboList additem(x,0) next                
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

	  Canvas.setpixmap(MonaLisa)			  ### Need this setpixmap to display imageLabel	  
	  win.setwindowtitle("Fourier Series: Circles: "+ nbrSq  +" Angle: "+ inc  )
	  win.show()								  ### Need this to show		  to display imageLabel
			
	  MyApp.ProcessEvents()					  ###<<< EXEC the Draw
	  //Sleep(gSleepDelay)
					 
return

###------------------------------------------------------

Func pPress
	 win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY )
	 
	 initX = myfilter.getglobalx()		### Screen coordinate, NOT Canvas
	 initY = myfilter.getglobaly()		### Screen coordinate, NOT Canvas

	 //initX = myfilter.getx()				### Screen coordinate, NOT Canvas
	 //initY = myfilter.gety()				### Screen coordinate, NOT Canvas

	 ### Change Pen Color
	 if  counter % 3 = 0	 daVinci.setpen(penRed)		curPen = penRed
	 but counter % 3 = 1	 daVinci.setpen(penGreen)	curPen = penGreen
	 else						 daVinci.setpen(penBlue)	curPen = penBlue
	 ok
	 counter++
	 
	 daVinci.setCompositionMode(26)		###  THIS is the MAGIC - Erase Old Line when Redrawn
	 
	 oldX = initX								### Save Pressed point as OLD points
	 oldY = initY
	 
return

###------------------------------------------------------------------------

Func pRelease
	 win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY +" Width "+ (finalX-initX) + " Height "+ (finalY-initY) )

	 finalX = myfilter.getglobalx()				### Screen coordinate, NOT Canvas
	 finalY = myfilter.getglobaly()

	 pDrawObjects()

	 Canvas.setPixMap(MonaLisa)					### Need this setpixmap to display imageLabel
	 Canvas.show()
	 
return

###------------------------------------------------------------------------

Func pMove
	 win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY +" Width "+ (finalX-initX) + " Height "+ (finalY-initY) )

	 finalX = myfilter.getglobalx()			### Screen coordinate, NOT Canvas getx()  gety()
	 finalY = myfilter.getglobaly()

	 pDrawObjects()
	
	 Canvas.setpixmap(MonaLisa)				### Need this setpixmap to display imageLabel
	 Canvas.show()
	 
	 oldX = finalX	 ### Save OLD points
	 oldY = finalY
	 
return


###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
	 Rec = win.framegeometry()

	 WinWidth  = Rec.width()				 ### Current Values
	 WinHeight = Rec.height()				 ### 
	 
	 WinLeft	  = Rec.left() +8				 ### <<< QT FIX because of Win Title
	 WinTop	  = Rec.top()	+30			 ### <<< QT FIX because of Win Title
	 WinRight  = Rec.right()
	 WinBottom = Rec.bottom()

	 win{ setwindowtitle("Window ReSize: Win " +	 WinWidth + "x" + WinHeight + 
				" --- LT " +  WinLeft + "-"	+ WinTop	 + " --- RB " + WinRight + "-" + WinBottom		) }

return

###---------------------------------------
### Window Moved

Func WhereMoved()

	 xPos = win.x()  +8			  ### <<< QT FIX because of Win Title
	 yPos = win.y() +30			  ### <<< QT FIX because of Win Title

	 win{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }	 

return

###===============================================
###===============================================
### Sin() = Vertical	 Cos() - Horizontal
//
// See "Sin(15) radians = " + sin(15)				 =>  0.65
// See "Sin(15) degree	= " + sin(15 * 3.14/180) =>  0.26
// See "Cos(15) radians = " + cos(15)				 => -0.76
// See "Cos(15) degree	= " + cos(15 * 3.14/180) =>  0.97

// Wave	      Series	Fourier Series                Grapher
// SquareWave:	sin(x) + sin(3x)/3 + sin(5x)/5  + ...	sin((2n-1)*x)/(2n-1)
// SawTooth:	sin(x) + sin(2x)/2 + sin(3x)/3  + ...	sin(n*x)/n
// Pulse:	   sin(x) + sin(2x)   + sin(3x)    + ...	sin(n*x)*0.1
// Triangle:	sin(x) − sin(3x)/9 + sin(5x)/25 − ...	sin((2n-1)*x)*(-1)^n/(2n-1)^2



Func pDrawObjects()

	oSineQ	= new Queue							// oSinQ.add(y) to End,	 oSinQ.remove() from Start
	oSquareQ = new Queue

	X		  = 1		 Y			= 1
	prevX	  = 1		 prevY	= 1
	
	WaveType = comboWaveType.currentText()
	
	for nbrOfCircles = 1 to 10							
		for angle = 0 to 360 step inc			// Around each Circle  
		
			MonaLisa.fill(colorBlack)			// Clear screen

			//------------------------------------------
			// SineWave to SquareWave

			x = 0	 y = 0
			for count = 0 to nbrSq		
				oldX	 = x	oldY = y		
				
										
				   ###--------------
					### SquareWave
					if  WaveType = "SquareWave"
							n = (count * 2) +1							// Circle-N = 1 3 5 7 9
													
							radius = radiusC * (4 / (n * PI))   	// For each Smaller Circle-N
							radian = ( n * ( angle * gDegree ) )	// For Angle in Circle-N
							x += radius * cos(radian)  				// Cos() Horizontal X
							y += radius * sin(radian)  				// Sin() Vertical Y

					###--------------
					### SawTooth
					elseif   WaveType = "SawTooth"
							n = (count * 1) +1							// Circle-N = 1 3 5 7 9
											
							radius = radiusC * (4 / (n * PI))   	// For each Smaller Circle-N
							radian = ( n * ( angle * gDegree ) )	// For Angle in Circle-N
							x += radius * cos(radian)  				// Cos() Horizontal X
							y += radius * sin(radian)  				// Sin() Vertical Y
					
					###--------------
					### Pulse
					elseif   WaveType = "Pulse"
							n = (count * 1) +1							// Circle-N = 1 3 5 7 9
											
                     pulseSize = 10									// Pulse - same small circle		
							radius = radiusC * (4 / ( pulseSize * PI) )   	// For each Smaller Circle-N
							radian = ( n * ( angle * gDegree ) )	// For Angle in Circle-N
							x += radius * cos(radian)  				// Cos() Horizontal X
							y += radius * sin(radian)  				// Sin() Vertical Y		

					###--------------
					### Triangle
					elseif   WaveType = "Triangle"
							n = (count * 2) +1							// Circle-N = 1 3 5 7 9
					
							radius = radiusC * (4 / (n * n * PI))   	// SQUARED-nFor each Smaller Circle-N
							radian = ( n * ( angle * gDegree ) )	// n Squared --For Angle in Circle-N

						
							if (count % 2) = 0
								x += radius * cos(radian)  				// Cos() Horizontal X  PLUS
								y += radius * sin(radian)  				// Sin() Vertical Y	
							else
								x -= radius * cos(radian)  				// Cos() Horizontal X  MINUS
								y -= radius * sin(radian)  				// Sin() Vertical Y								
							ok
					else
							See "Error: Unknown Wave Name: "+ WaveType +nl
							return
					ok			
					
					 
				daVinci.setpen(penYellow)				
				daVinci.drawLine(oldX, -oldY, X, -Y)		// From oldCircle center to newCircle center
				
				daVinci.setpen(curPen)
				DrawCircle(oldX, -oldY, radius)
			
			next

			//---------------------------------------
			// Draw SineWave made from oSinQ Queue
			
			aPos = FindCirclePoint(0,0,radiusC,Angle)		// Circle-Origin
			xVert = aPos[1]  yVert = aPos[2]					// Angle => x,y position on circumference
		
			oSineQ.add(yVert)										// SineWave		Add y-Point to end of Queue
			oSquareQ.add(y)										// SquareWave	Add modified y-Point to end of Queue

			lastPos = len(oSquareQ)
			pos = 1
			prevX =	xOff + pos
			prevY =	0 - oSquareQ[lastPos]
			
			
			for k = lastPos to 1 step -1
				curX =  xOff + pos
				curY =  0 - oSquareQ[k]
				sinY =  0 - oSineQ[k]
				
				daVinci.DrawLine( curX, curY, prevX, prevY)		// SquareWave make solid 
				daVinci.DrawPoint( curX, curY )						// SquareWave Points	 -Y goes up
				
				daVinci.setPen(penWhite)
				daVinci.DrawPoint( curX, sinY )						// SineWave	  Points	 -Y goes up
				
				daVinci.setPen(curPen)
				
				prevX =	curX
				prevY =	curY
				
				pos++
			next

			daVinci.DrawLine(x, -y, xOff, 0 - oSquareQ[lastPos] )	 // SquareWave -Y goes up
			
			if lastPos > nbrWaves
				oSquareQ.remove()		// Remove Start point
				oSineQ.remove()		
			ok		 

			DrawUpdate()				// Animated Delay
			
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
### See "Sin(15) radians = " + sin(15)				  =>	0.65
### See "Sin(15) degree	 = " + sin(15 * 3.14/180) =>	0.26


//------------------------------------------
// DrawCircle using Center-X-Y and Radius

Func DrawCircle(x,y,radius)

	HCenter = x
	VCenter = y
	HWidth  = 2 * radius
	VHeight = 2 * radius

	HCorner = HCenter - (HWidth  /2)
	VCorner = VCenter - (VHeight /2)

	daVinci.drawEllipse(HCorner, VCorner, HWidth, VHeight)	// LeftCorner, HWidth, VHeight

return

//------------------------------------------
// DrawCirclePoint on Circle Circumference


Func DrawCirclePoint(x,y,radius,angle)
	
	HCenter = x
	VCenter = y

	radian = Angle * gDegree
	
	x =  cos(radian)	// Cos() Horizontal X
	y =  sin(radian)	// Sin() Vertical Y

	XPos =  x * radius
	YPos =  y * radius

	daVinci.drawPoint(HCenter + XPos, VCenter - YPos)	// Minus Y goes up screen
	
return [XPos,YPos]

//------------------------------------------
// DrawCircleLines from CenterCircumference

Func DrawCircleLine(x,y,radius,Angle)

	HCenter = x
	VCenter = y
	
	radian = Angle * gDegree
	
	x =  cos(radian)	// Cos() Horizontal X
	y =  sin(radian)	// Sin() Vertical Y

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
	
	x =  cos(radian)	// Cos() Horizontal X
	y =  sin(radian)	// Sin() Vertical Y

	XPos =  x * radius
	YPos =  y * radius

return [XPos,YPos]
//------------------------------------------

###-------------------------------------
### Speed of Move Animation
### Slider Values go from 0 to 100	on the Bar
### Low 1  to	10 High

Func SliderEventCircle()

	nbrSq = SliderCircle.value()					// Max 100/10 = 10  Min 10 / 10 = 1	 
	nbrSq = ceil(nbrSq)

	//See "SliderValueCircle: "+ SliderCircle.value() +" nbrSq "+ nbrSq +nl
	
	nameCircle = "Circle-"+ nbrSq
	btnCircle.setText(nameCircle)	
	DrawUpdate()										 // Refresh screen
	
return

###------------------------------------
### Angle Increment

Func SliderEventAngle()

	inc = SliderAngle.value() / 10				// Max 100/10 = 10  Min 10 / 10 = 1	 
	inc = ceil(inc)
	if inc = 0	inc = 1 ok							// Angle inc by 0 => 1
	
	//See "SliderValueAngle: "+ SliderAngle.value() +" inc "+ inc +nl

	nameAngle = "Angle-Incr-"+ inc
	btnAngle.setText(nameAngle)	
	DrawUpdate()										 // Refresh screen
	
return

###------------------------------------

