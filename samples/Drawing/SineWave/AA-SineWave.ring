# Sample : Draw Sine wave
# Author : Bert Mariani
# Date : 2020-09-27
#
# http://doc.qt.io/qt-4.8/qpainter.html#CompositionMode-enum
#
Load "guilib.ring"
load "stdlib.ring"

PI      = 3.1415926535  // Circle is 2*PI radians
gDegree = PI / 180      // 2*PI = 360 degrees  Radians to Degrees
gSleepDelay = 0.00      // Animated Delay

///----------------------------
//Parameters

   radiusC    = 100     
   xOff       = 150                   // horizontal for SineWave
   freq       = 5                     // Degrees freq
   nbrSq      = 5                     // Max 0-99 SQUARE count for SineWave
   nbrWaves   = 512                   // oSinQ Queue size for SineWave
   nbrOfCircles = 10       
   
//----------------------------

initX  = 0  initY  = 0 # initial position of cursor
finalX = 0  finalY   = 0 # final position of cursor
oldX   = 0  oldY   = 0 # old     position of cursor


width   = 10
height  = 12

xPos    = 100
yPos    = 100
xWidth  = 1200
yHeight = 600    ### Canvas position on Screen

counter = 1     ### Modulo 3 to change Pen Color

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite  = new qcolor() { setrgb(255,255,255,255) }

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }
penYellow   = new qpen() { setcolor(colorYellow) setwidth(2) }
penWhite    = new qpen() { setcolor(colorYellow) setwidth(1) }

//curPen      = penGreen

brushS      = new qbrush() { setstyle(1)  setcolor (colorYellow)}    ### Yellow
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlack) }    ### Black
brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}    ### Empty

counter = 1     ### Modulo 3 to change Pen Color

###-----------------

MyApp = new qApp 
{
    win = new qWidget()
    {
      setWindowTitle("SineWave ")
      setGeometry(xPos, yPos, xWidth, yHeight)  ### Window Position and Size

      ###------------------------------------------
      ### Mouse Event
      myfilter = new qallevents(win)
      myfilter.setMouseButtonPressEvent("pPress()")
      installeventfilter(myfilter)
        

      Canvas = new qlabel(win)
      {
         ### daVinci paints the MonaLisa on the Canvas
         MonaLisa  = new qPixMap2( xWidth, yHeight)

         daVinci = new qpainter()
         {
            begin(MonaLisa)
            translate(300,300)     ### TRANSLATE COORDINATE x,y -- 0,0 MAPS TO 300,300
            #endpaint()            ### This will Stop the Painting      
         }

         setPixMap(MonaLisa)
      }

      SliderAmplitude = new qslider(win) 
      {
         setGeometry(10, 2, 100, 20)
         setOrientation(Qt_Horizontal)
         setTickInterval(1)                     
         setValue(50)                            
         setValueChangedEvent("SliderEventAmplitude()")
      }

      btnAmplitude = new qpushbutton(win)
      {
         setGeometry(120, 2, 100, 20)
         setText("Amplitude "+nbrSq)
         setClickEvent("pDrawObjects()") 
      }              

      SliderFrequency = new qslider(win) 
      {
         setGeometry(240, 2, 100, 20)
         setOrientation(Qt_Horizontal)
         setTickInterval(1)                     
         setValue(50)                            
         setValueChangedEvent("SliderEventFrequency()")
      }        

      btnFrequency = new qpushbutton(win)
      {
         setGeometry(350, 2, 100, 20)
         setText("Frequency "+freq)
         setClickEvent("pDrawObjects()") 
      }

      btnExit = new qpushbutton(win)
      {
         setGeometry(470, 2, 100, 20)
         setText("Exit")
         setClickEvent("pExit()") 
      }
        
	pPress()        
        pDrawObjects()
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
    
     Canvas.setpixmap(MonaLisa)                                   ### Need this setpixmap to display imageLabel   
     win.setwindowtitle("SineWave: Amplitude: "+ nbrSq  +" Frequency: "+ freq  )
     win.show()                                                   ### Need this to show to display imageLabel
         
     MyApp.ProcessEvents()                                        ###<<< EXEC the Draw
          
return


###===============================================
###===============================================
### Sin() = Vertical  Cos() - Horizontal
//
// See "Sin(15) radians = " + sin(15)            =>  0.65
// See "Sin(15) degree  = " + sin(15 * 3.14/180) =>  0.26
// See "Cos(15) radians = " + cos(15)            => -0.76
// See "Cos(15) degree  = " + cos(15 * 3.14/180) =>  0.97


Func pDrawObjects()
    
   //------------------------------------------------- 
   // oSinQ.add(y) to End,  oSinQ.remove() from Start
   
   oSineQ   = new Queue                   

   X     = 1   Y     = 1
   prevX = 1   prevY = 1
   

   for nbrOfCircles = 1 to 10                   
      for angle = 0 to 360 step freq                   // Around each Circle  
      
         MonaLisa.fill(colorBlack)                    // Clear screen

         //---------------------------------------
         // Draw SineWave made from oSinQ Queue
         
         aPos  = FindCirclePoint(0,0,radiusC,Angle)    // Circle-Origin 
         xVert = aPos[1]  yVert = aPos[2]             // Angle => x,y position on circumference
      
         oSineQ.add(yVert)                            // SineWave    Add y-Point to end of Queue
                                                      // SquareWave  Add modified y-Point to end of Queue
         lastPos = len(oSineQ)
         pos     = 1
         prevX   = xOff + pos
         prevY   = 0 - oSineQ[lastPos]
         
         
         for k = lastPos to 1 step -1
            curX =  xOff + pos
            sinY =  0 - oSineQ[k] * nbrSq / 5            // Amplitude
            
            daVinci.DrawPoint( curX, sinY )            // SineWave   Points  -Y goes up
               
            prevX =  curX
            prevY =  sinY
            
            pos++
         next

         
         if lastPos > nbrWaves
            oSineQ.remove()      
         ok     

         DrawUpdate()            // Animated Delay
         
      next
      
   next

return


//------------------------------------------
//------------------------------------------
// DrawCircleLines from CenterCircumference

Func FindCirclePoint(x,y,radius,Angle)

   HCenter = x
   VCenter = y
   
   radian = Angle * gDegree
   
   x =  cos(radian)  // Cos() Horz X
   y =  sin(radian)  // Sin() Vert Y

   XPos =  x * radius
   YPos =  y * radius

return [XPos,YPos]
//------------------------------------------


###------------------------------------
### Frequency

Func SliderEventFrequency()

   freq = SliderFrequency.value() / 10     // Max 100/10 = 10  Min 10 / 10 = 1  
   freq = ceil(freq)
   
   if freq = 0   freq = 1   ok
  
   nameFrequency = "Frequency "+ freq
   btnFrequency.setText(nameFrequency) 
   DrawUpdate()                           // Refresh screen
   
return

###------------------------------------
###-------------------------------------
### Speed of Move Animation
### Slider Values go from 0 to 100  on the Bar
### Low 1  to  10 High

Func SliderEventAmplitude()

   nbrSq = SliderAmplitude.value()  / 10     // Max 100/10 = 10  Min 10 / 10 = 1  
   nbrSq = ceil(nbrSq)
   
   if nbrSq = 0   nbrSq = 1   ok
   
   nameAmplitude = "Amplitude "+ nbrSq
   btnAmplitude.setText(nameAmplitude) 
   DrawUpdate()                              // Refresh screen
   
return

###--------------------------------------------------------------------

Func pPress

    ### Change Pen Color
    if  counter % 3 = 0  daVinci.setpen(penRed)
    but counter % 3 = 1  daVinci.setpen(penGreen)
    else                 daVinci.setpen(penBlue)
    ok
    counter++

return

###------------------------------------------------------------------------
