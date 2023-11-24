# Sample : Discrete Fourier Transform - DFT
# Author : Bert Mariani
# Date   : 2019-09-06

Load "guilib.ring"
load "stdlib.ring"
load "data.ring"

PI       = 3.1415926535  // Circle is 2*PI radians
TWO_PI   = PI * 2
HALF_PI  = PI / 2
gDegree  = PI / 180      // 2*PI = 360 degrees  Radians to Degrees

///----------------------------
//Parameters

    gNbrSteps       = 1    // For Points in Shape Step BY  gNbrSteps
    gGoAroundFigure = 1    // Draw Shape X times

//----------------------------
//DFT - Test Pattern
YY = [100,100,100, -100,-100,-100, 100,100,100, -100,-100,-100]

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
          setGeometry(xPos, yPos, xWidth, yHeight)   ### Window Position and Size

          myfilter = new qallevents(win)

                ###------------------------------------------
                ### Mouse Event

                myfilter.setMouseButtonPressEvent("pPress()")
                myfilter.setMouseButtonReleaseEvent("pRelease()")
                myfilter.setMouseMoveEvent("pMove()")
                myfilter.setCloseEvent("MyApp.Quit()")

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
                    translate(200,300)            ### TRANSLATE COORDINATE x,y   0,0    MAPS TO 300,300
                    #endpaint()                   ### This will Stop the Painting
                }

                setPixMap(MonaLisa)
          }

          //-------------------------------

          sliderNbrSteps = new qslider(win)
          {
                setGeometry(10, 2, 100, 20)
                setOrientation(Qt_Horizontal)
                setTickInterval(10)                              // Count of nbrSteps 1...100
                setValue(1)                                        // 0...50...100
                setValueChangedEvent("eventSliderNbrSteps()")
          }

          btnNbrSteps= new qpushbutton(win)
          {
                setGeometry(120, 2, 100, 20)
                setText("Points-StepBy-"+ gNbrSteps)
                setClickEvent("pDrawObjects()")
          }

          //--------------------------------

          sliderGoAroundFigure = new qslider(win)
          {
                setGeometry(240, 2, 100, 20)
                setOrientation(Qt_Horizontal)
                setTickInterval(10)                          // Count of Angle  1...10
                setValue(1)
                setValueChangedEvent("eventSliderGoAroundFigure()")
          }

          btnGoAroundFigure = new qpushbutton(win)
          {
                setGeometry(350, 2, 100, 20)
                setText("GoAroundFigure-"+ gGoAroundFigure)
                setClickEvent("pDrawObjects()")
          }

          //---------------------------------

          comboShapeType = new QComboBox(win)
          {
            setgeometry(470, 2, 100, 20)
            comboList = ["Shape-PI","Shape-Circle","Shape-Train","Shape-Treble"]
            for x in comboList additem(x,0) next
          }

          //----------------------------------

          btnExit = new qpushbutton(win)
          {
                setGeometry(590, 2, 100, 20)
                setText("Exit")
                setClickEvent("pExit()")
          }

          //----------------------------------

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
      win.setwindowtitle("Discrete Fourier Transform:  PointNbrSteps"+ gNbrSteps  +" GoAroundFigure: "+ gGoAroundFigure  )
      win.show()                              ### Need this to show       to display imageLabel

      MyApp.ProcessEvents()                   ###<<< EXEC the Draw

return

###------------------------------------------------------

Func pPress
     win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY )

     initX = myfilter.getglobalx()      ### Screen coordinate, NOT Canvas
     initY = myfilter.getglobaly()      ### Screen coordinate, NOT Canvas

     //initX = myfilter.getx()              ### Screen coordinate, NOT Canvas
     //initY = myfilter.gety()              ### Screen coordinate, NOT Canvas

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

     finalX = myfilter.getglobalx()             ### Screen coordinate, NOT Canvas
     finalY = myfilter.getglobaly()

     pDrawObjects()

     Canvas.setPixMap(MonaLisa)                 ### Need this setpixmap to display imageLabel
     Canvas.show()

return

###------------------------------------------------------------------------

Func pMove
     win.setWindowTitle("Press: Top " + initX +"-" +initY +" Bottom "+ finalX +"-" +finalY +" Width "+ (finalX-initX) + " Height "+ (finalY-initY) )

     finalX = myfilter.getglobalx()         ### Screen coordinate, NOT Canvas getx()  gety()
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
### Sin() = Vertical     Cos() - Horizontal
//
// See "Sin(15) radians = " + sin(15)                =>  0.65
// See "Sin(15) degree  = " + sin(15 * 3.14/180) =>  0.26
// See "Cos(15) radians = " + cos(15)                => -0.76
// See "Cos(15) degree  = " + cos(15 * 3.14/180) =>  0.97


Func pDrawObjectsXX()   // Draw Image as is
   for i = 1 to len(trainPoints) -1
      daVinci.drawPoint( trainPoints[i][1], -trainPoints[i][2] )
      daVinci.drawLine( trainPoints[i][1], -trainPoints[i][2] ,  trainPoints[i+1][1], -trainPoints[i+1][2] )
   next

return

//------------------------------------------

Func pDrawObjects()

   ShapeType = comboShapeType.currentText()

   if ShapeType    = "Shape-PI"
       ShapePoints =  ShapePI          // Array of X-Y for PI Shape

   but ShapeType   = "Shape-Circle"
       ShapePoints =  ShapeCircle

   but ShapeType   = "Shape-Train"
       ShapePoints =  ShapeTrain
       gNbrSteps   = 7                 // Fast processing
	
   but ShapeType   = "Shape-Treble"
       ShapePoints =  ShapeTreble	

   ok


   oVertQ = new Queue
   oHorzQ = new Queue
   nbrPoints = len(ShapePoints)    ### Nbr of Points in the trainPoints for PI Shape

   for loopAoundFigure = 1 to gGoAroundFigure

      // Discrete Fourier Transform call for the List of X-Y Points
      YY = []
      XX = []

      nbrPoints = 0                 // ===<<<<
      nData = len(ShapePoints)

      //for i = 1 to nbrPoints
      for i = 1 to nData step gNbrSteps
         nbrPoints++
         Add(XX, ShapePoints[i][1])
         Add(YY, ShapePoints[i][2])
      next

      FourierX = DFT(XX)                        ### ===>>> SubRoutine
      FourierY = DFT(YY)

        dt    = TWO_PI / nbrPoints              ### Increment angle amount
      //dt    = 0.051927                        ### Fixed value for test --- 2*PI / nbrPoints = 121

        //-------------------------------------------------------------------
        // Go Around each Circle = TWO_PI or 360 degrees

        for angle = 0 to TWO_PI  step  dt       ### Angle is Radians, Inc by 1 trainPoints, till reach 2*PI = Full Circle

            MonaLisa.fill(colorBlack)           ### Clear screen

            xV     = 1      yV     = 1
            prevXV = 1      prevYV = 1

            xH     = 1      yH     = 1
            prevXH = 1      prevYH = 1
            horz   = 500    vert   = 150   // Draw Horizontal circle offsets
            piH    = 500    piV    = 200   // Draw PI offsets

            //----------------------------
            // EpiCycles - LEFT Vertical Circles

            for i = 1 to nbrPoints

               oldXV = xV
               oldYV = yV

               freq   = fourierY[i][3]
               radius = fourierY[i][4]
               phase  = fourierY[i][5]

               xV += radius * cos(freq * angle + phase + HALF_PI)
               yV += radius * sin(freq * angle + phase + HALF_PI )


                daVinci.setpen(penYellow)
                daVinci.drawLine(oldXV , -oldYV +piV, XV, -YV +piV)  // Draw Line - oldCircleCtr to newCircleCtr

                daVinci.setpen(curPen)
                DrawCircle(oldXV, -oldYV +piV, radius)               // Draw multiple Vertical Circles
                //See "Circle: "+ i +" "+  oldXV +" "+ oldYV  +" "+ piV +" "+ radius   +nl

            next

            //-------------------------------------------
            // EpiCycles - RIGHT Horizontal Circles

            for i = 1 to nbrPoints

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

            //------------------------------------------------------------------
            // VertWave Queue - History - Add modified y-Point to end of Queue
            // QUEUE - FirstIn-FirstOut,  Add to LastIn

            oVertQ.add(yV)    // 1st Set of Circles on Left for vertical
            oHorzQ.add(xH)    // 2nd Set of Circles on Right for horizontal

            lastPos = len(oVertQ)

            //-------------------------
            // Draw PI Shape

            daVinci.setpen(penYellow)
            for k = lastPos to 1 step -1
                curX =   oHorzQ[k]                          // Draw to Right side
                curY =  -oVertQ[k]                          // Y goes up - make negative

                daVinci.DrawLine( curX +piH, curY +piV, prevXV +piH, prevYV +piV)

                prevXV = curX     prevYV  = curY
                prevXH = curX     prevYH  = curY

            next
            daVinci.setpen(curPen)

            //----------------------------------   ----
            // Draw H and V Lines to PI Shape point

            daVinci.setpen(penWhite)

            daVinci.DrawLine(xV ,      -yV +piV,  oHorzQ[lastPos] +horz, -oVertQ[lastPos] +piV )    // Draw Horz Line in Circles to Wave
            daVinci.DrawLine(xH +horz, -yH -vert, oHorzQ[lastPos] +horz, -oVertQ[lastPos] +piV )    // Draw Vert Line in Circles to Wave

            daVinci.setpen(curPen)

            if lastPos > nbrPoints
               oVertQ.remove()          // QUEUE - Remove Start point
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

    x =  cos(radian)    // Cos() - Horizontal X
    y =  sin(radian)    // Sin() - Vertical Y

    XPos =  x * radius
    YPos =  y * radius

return [XPos,YPos]
//------------------------------------------

###-------------------------------------
### Speed of Move Animation
### Slider Values go from 0 to 100  on the Bar
### Low 1  to   10 High

Func eventSliderNbrSteps()

    gNbrSteps = sliderNbrSteps.value()               // Max 100/10 = 10  Min 10 / 10 = 1
    gNbrSteps = ceil( gNbrSteps / 10 )               // 100 / 10 = 10 max
    if gNbrSteps = 0
       gNbrSteps = 1
    ok

    //See "eventSliderNbrSteps: "+ eventSliderNbrSteps.value() +" gNbrSteps "+ gNbrSteps +nl

    nameNbrSteps = "Points-StepBy-"+ gNbrSteps
    btnNbrSteps.setText(nameNbrSteps)
    DrawUpdate()                                    // Refresh screen

return

###------------------------------------
### Angle Increment

Func eventSliderGoAroundFigure()

    gGoAroundFigure = sliderGoAroundFigure.value()     // Max 100/10 = 10  Min 10 / 10 = 1
    gGoAroundFigure = ceil(gGoAroundFigure / 10 )
    if gGoAroundFigure = 0
       gGoAroundFigure = 1
    ok

    //See "SliderGoAroundFigure: "+ SliderGoAroundFigure.value() +" gGoAroundFigure "+ gGoAroundFigure +nl

    nameGoAroundFigure = "GoAroundFigure-"+ gGoAroundFigure
    btnGoAroundFigure.setText(nameGoAroundFigure)
    DrawUpdate()                                       // Refresh screen

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
   See "Return BigX Fourier: "+nl
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

   BigX[k] = [ re, im, freq, amp, phase ]          // <<<=== Add a line of values to [][]

   //Add ( BigX, [ re, im, freq, amp, phase ] )    // Alternate way of adding to array  when BigX = []
   //See "BigX[k]: "+k +tab+ re +tab+ im +tab+ freq +tab+  amp +tab+ phase +nl

  next

return BigX


//===================================================
