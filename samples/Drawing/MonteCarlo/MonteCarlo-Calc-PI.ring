# Sample : Draw MonteCarlo Circle Square Random PI
# Author : Bert Mariani
# Date :   2021-May-09
##
# Basic principles of Monte-Carlo methods, a class of computational algorithms. 
# A simple example of estimating value of pi is discussed. 
# Monte-carlo techniques are widely used in the areas of modern physics, nuclear simulation, astro-physics and many other areas 
# of science and engineering where direct computation or analytical solutions are impossible or too difficult to obtain. 
# The name comes from a top secret nuclear project during world war II. 
# A scientist in the project group suggested a name Monte-Carlo which is a casino in Monaco. 
# Monte-Carlo methods make use of probability and probability distributions play a major role in the outcome of the algorithm. 
#

Load "guilib.ring"

###===============================================
### MonteCarlo constants for Square and Circle

decimals(6)

nInCircle = 0
nInSquare = 0
radius    = 1000
diameter  = radius * 2
r2        = radius * radius
aXY       = [0,0]

balls     = 1
ballLimit = 100000  # 100k
PI        = 1

###================================================
### Drawing constants

flag = 0

nX = 0  nY = 0 # initial position of cursor
fX = 0  fY = 0 # final   position of cursor
oX = 0  oY = 0 # old     position of cursor

width  = 10
height = 12

xPos    = 100
yPos    = 100
xWidth  = 800
yHeight = 800   ### Canvas position on Screen

indent  = 30    ### Make Canvas smaller
counter = 1     ### Modulo 3 to change Pen Color

rad1 = 1
rad2 = 1

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }  ### Yellow

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
penYellow   = new qpen() { setcolor(colorYellow) setwidth(1) }
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }

brushS      = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlack) }   ### Black
brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty

###-----------------

MyApp = new qApp 
{
    win = new qWidget()
    {
        setWindowTitle("MonteCarlo: Click on Button-Circle, then use the Mouse, to Draw any Size Circle ")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        myfilter = new qallevents(win)

            ###------------------------------------------
            ### Mouse Event
        
            myfilter.setMouseButtonPressEvent("pPress()")
            myfilter.setMouseButtonReleaseEvent("pRelease()")
            myfilter.setMouseMoveEvent("pMove()")
            myfilter.setCloseEvent("MyApp.Quit()")
            installeventfilter(myfilter)


        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               #endpaint()                  ### This will Stop the Painting
   
            }

            setPixMap(MonaLisa)
        }


        btn1 = new qpushbutton(win)
        {
            setgeometry(260, 00, 100, 20)
            settext("Circle")
            setclickevent("pCircle()") 
        }

        btn2 = new qpushbutton(win)
        {
            setgeometry(380, 00, 100, 20)
            settext("Clear")
            setclickevent("pClear()") 
        }
        
		  btn3 = new qpushbutton(win)
        {
				setgeometry(500, 00, 100, 20)
				settext("PI")        
        }
        
        show()
    }
    exec()
}

###==============================================================

###==============================================================
### Calculate if random point falls inside or outside the Circle 

Func MonteCarlo()



while balls < ballLimit
   aXY = dropRandom(diameter)       // Array Returned -- Up to size of square
   
   nInSquare++                      // Count balls inside Square
   daVinci.setPen(penRed)
   
   x = fabs( radius - aXY[1] )     // adjust for center of circle 50,50
   y = fabs( radius - aXY[2] ) 
  
   
   if x*x + y*y <= r2
      nInCircle++                   // Count balls inside Circle
      daVinci.setPen(penGreen)
   end
   
   posX = aXY[1] 
   posY = aXY[2]
   
   DrawDot(posX, posY)
   
   balls++  
   if balls % 1000 = 0
      P  = nInCircle / nInSquare    // Ratios of Balls in Circle to Square 
      PI = 4 * P
      See "Balls: "+ balls +" nInCircle: "+ nInCircle +" nInSquare: "+ nInSquare +" P: "+ P +" PI: "+ PI +nl
      
      btn3.settext("PI calc = "+ PI) 
   
      win.setWindowTitle("MonteCarlo: InCircle: "+ nInCircle +" InSquare: "+ nInSquare +" PI: "+ PI )
		
   Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
   MyApp.ProcessEvents()               ### <<< EXEC the Draw
      
   end
   
end

P  = nInCircle / nInSquare     
PI = 4 * P
     
See "Balls: "+ balls +" nInCircle: "+ nInCircle +" nInSquare: "+ nInSquare +" P: "+ P +" PI: "+ PI +nl

btn3.settext("PI calc = "+ PI)

balls = 1                           // For new Circle

###========================

Func dropRandom(limit)
   
   aHV = [0,0]
   
   aHV[1] = random(limit -1) +1   // Random 0 99
   aHV[2] = random(limit -1) +1   // Ring   1 100
   
return aHV 


###--------------------
### Draw the Random MonteCarlo Dots

Func DrawDot(x,y)
     
   scale = rad2 / diameter         // Width of SquareCircle / 100
   
   x = (x * scale) +nX - xPos      // Screen  position
   y = (y * scale) +nY - yPos
        
   daVinci.drawPoint( x, y  )    // nX nY are TopLeft corner of SquarCircle 
              
return

###---------------------------

###===================================================
###===================================================


Func pPress
    //win.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY  +" Width "+ (rad2) )
    
    nX = myfilter.getglobalx()      ### Screen coordinate, NOT Canvas
    ny = myfilter.getglobaly()      ### Screen coordinate, NOT Canvas

    ### Change Pen Color
    if  counter % 3 = 0  daVinci.setpen(penRed)
    but counter % 3 = 1  daVinci.setpen(penGreen)
    else                 daVinci.setpen(penBlue)
    ok
    counter++
    
    daVinci.setCompositionMode(26)  ###  THIS is the MAGIC - Erase Old Line when Redrawn
    
    oX = nX  ### Save Pressed point as OLD points
    oY = nY
return

###------------------------------------------------------------------------

Func pRelease
    //win.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY +" Width "+ (rad2) )
	 
    fX = myfilter.getglobalx()          ### Screen coordinate, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()                      ### Circle and Square combo
    
    MonteCarlo()   ### Draw Dots

    Canvas.setPixMap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
return

###------------------------------------------------------------------------

Func pMove
    //win.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY +" Width "+ (rad2)  )

    fX = myfilter.getglobalx()      ### Screen coordinate, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()                  ### Circle and Square combo

    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
    
    oX = fX  ### Save OLD points
    oY = fY
    
return

###--------------------------

Func pCircle()
         flag = 3
return

###--------------------
### Flag 3 is Circle

Func pDrawObjects()

    
    if flag = 3
        # Circle
        rad1 = sqrt(pow(oX - nX, 2) + pow(oY - nY, 2))            // r2 = x2 + y2 
        daVinci.drawellipse(nX - xPos, nY - yPos, rad1, rad1)
          
        rad2 = sqrt(pow(fX - nX, 2) + pow(fY - nY, 2))
        daVinci.drawellipse( nX - xPos, nY - yPos, rad2, rad2)
        
        # Square
           daVinci.drawRect( nX - xPos -1, nY - yPos -1, rad1 +2, rad1 +2 )
           daVinci.drawRect( nX - xPos -1, nY - yPos -1, rad2 +2, rad2 +2)
        
        # Center
           daVinci.drawPoint( nX - xPos + (rad1/2), nY - yPos + (rad1/2) )
           daVinci.drawPoint( nX - xPos + (rad2/2), nY - yPos + (rad2/2) ) 
        
        
    ok
              
return

###---------------------------

Func pClear()

    daVinci.setCompositionMode(0)   ### Put back to default mode 0
    
    daVinci.setBrush(brushSB)       ### Brush - Solid Black  
    daVinci.setPen(penBlack)
    daVinci.drawRect(0, 0, xWidth, yHeight)
    
    daVinci.setCompositionMode(26)  ### THIS is the MAGIC - Erase Old Line when Redrawn
    
    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
return

###---------------------------

