# Sample : Draw Dynamic
#          Lines, Rect, Circle, Ellipse, Arc, Pie 
#          Empty, Solid, Hatch 
#          Using the Mouse
# Author : Bert Mariani
# Date   : 2017.02.04, 2018.07.31
#
# http://doc.qt.io/qt-4.8/qpainter.html#CompositionMode-enum
#
Load "guilib.ring"

flag = 0

nX = 0  nY = 0 # initial position of cursor
fX = 0  fY = 0 # final   position of cursor
oX = 0  oY = 0 # old     position of cursor

width  = 10
height = 12

xPos    = 100
yPos    = 100
xWidth  = 720
yHeight = 600   ### Canvas position on Screen

indent  = 30    ### Make Canvas smaller

counter = 1     ### Modulo 3 to change Pen Color

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorMix    = new qcolor() { setrgb(255,255,000,255) }  ### Yellow

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }

brushS      = new qbrush() { setstyle(1)  setcolor (colorMix)  }   ### Yellow
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlack)}   ### Black
brushE      = new qbrush() { setstyle(0)  setcolor (colorMix)  }   ### Empty

flagFill    = 0   ### Brush Empty

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
            myfilter.setMoveEvent(   "WhereMoved()" )  

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

        btn = new qpushbutton(win)
        {
            setgeometry(20, 500, 90, 20)
            settext("Line")
            setclickevent("pLine()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(120, 500, 90, 20)
            settext("Rectangle")
            setclickevent("pRect()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(220, 500, 90, 20)
            settext("Circle")
            setclickevent("pCircle()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(320, 500, 90, 20)
            settext("Ellipse")
            setclickevent("pEllipse()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(420, 500, 90, 20)
            settext("Arc")
            setclickevent("pArc()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(520, 500, 90, 20)
            settext("Pie")
            setclickevent("pPie()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(620, 500, 90, 20)
            settext("Clear")
            setclickevent("pClear()") 
        }

        ###-----------------------------

        btn = new qpushbutton(win)
        {
            setgeometry(20, 530, 90, 20)
            settext("Empty")
            setclickevent("pEmpty()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(120, 530, 90, 20)
            settext("Solid")
            setclickevent("pSolid()") 
        }

        btn = new qpushbutton(win)
        {
            setgeometry(220, 530, 90, 20)
            settext("Hatch")
            setclickevent("pHatch()") 
        }



        show()
    }
    exec()
}

###--------------------------------------------------------------------

Func pPress
    win.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY )
    
    nX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    ny = myfilter.getglobaly()      ### Screen co-ord, NOT Canvas

    ### Change Pen Color 
    if  counter % 3 = 0  
        daVinci.setpen(penRed)
        brushStyle = new qbrush() { setstyle(flagFill)  setcolor (colorRed) }

    but counter % 3 = 1  
        daVinci.setpen(penGreen)
        brushStyle = new qbrush() { setstyle(flagFill)  setcolor (colorGreen) }

    else                 
        daVinci.setpen(penBlue)
        brushStyle = new qbrush() { setstyle(flagFill)  setcolor (colorBlue) }
    ok

    daVinci.setBrush(brushStyle);  ### Empty, Solid, Hatch

    counter++
    
    daVinci.setCompositionMode(26)  ###  THIS is the MAGIC - Erase Old Line when Redrawn
    
    oX = nX  ### Save Pressed point as OLD points
    oY = nY
return

###------------------------------------------------------------------------

Func pRelease
    win.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY +" Width "+ (fX-nX) + " Height "+ (fY-nY) )

    fX = myfilter.getglobalx()          ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()

    Canvas.setPixMap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
return

###------------------------------------------------------------------------

Func pMove
    win.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY +" Width "+ (fX-nX) + " Height "+ (fY-nY) )

    fX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()

    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
    
    oX = fX  ### Save OLD points
    oY = fY
    
return


###-----------------------------------------
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
            " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }
return

###---------------------------------------
### Window Moved

Func WhereMoved()

    xPos = win.x()  +8          ### <<< QT FIX because of Win Title
    yPos = win.y() +30          ### <<< QT FIX because of Win Title

    win{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }  
return

###---------------

Func pLine()
         flag = 1
return

Func pRect()
         flag = 2
return

Func pCircle()
         flag = 3
return

Func pEllipse()
         flag = 4
return

Func pArc()
         flag = 5
return

Func pPie()
         flag = 6
return

###--------------------

Func pEmpty()
         flagFill = 0
return

Func pSolid()
         flagFill = 1
return

Func pHatch()
         flagFill = 2
return

###--------------------

Func pDrawObjects()

       ### Line     
    if flag = 1
       daVinci.drawLine( nX - xPos, nY - yPos, oX - xPos, oY - yPos )  ### ReDraw OLD Line to Erase
       daVinci.drawLine( nX - xPos, nY - yPos, fX - xPos, fY - yPos )  ### Draw NEW Line
    
        ### Rectangle
    but flag = 2
       daVinci.drawRect( nX - xPos, nY - yPos, oX - nX , oY - nY )
       daVinci.drawRect( nX - xPos, nY - yPos, fX - nX, fY - nY )
 
        ### Circle   
    but flag = 3
        rad1 = sqrt(pow(oX - nX, 2) + pow(oY - nY, 2))
        daVinci.drawellipse(nX - xPos, nY - yPos, rad1, rad1)
          
        rad2 = sqrt(pow(fX - nX, 2) + pow(fY - nY, 2))
        daVinci.drawellipse(nX -xPos, nY - yPos, rad2, rad2)
        
       
        ### Ellipse
    but flag = 4
       daVinci.drawEllipse( nX - xPos, nY - yPos, oX - nX, oY - nY )
       daVinci.drawEllipse( nX - xPos, nY - yPos, fX - nX, fY - nY )  

        ### Arc
    but flag = 5
       daVinci.drawArc( nX - xPos, nY - yPos, (oX - nX), (oY - nY), 16*(oX - nX), 16*(oY - nY) )
       daVinci.drawArc( nX - xPos, nY - yPos, (fX - nX), (fY - nY), 16*(fX - nX), 16*(fY - nY) )


        ### Pie
    but flag = 6
       daVinci.drawPie( nX - xPos, nY - yPos, oX - nX, oY - nY, 16*(oX - nX), 16*(oY - nY) )
       daVinci.drawPie( nX - xPos, nY - yPos, fX - nX, fY - nY, 16*(fX - nX), 16*(fY - nY) )  

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

