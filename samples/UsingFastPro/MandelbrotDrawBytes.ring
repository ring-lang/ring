### Project : Mandelbrot Set
### Date    : 2019/03-18
###  Mandelbrot - Colorized and Animated
###  2019-02-25  Bert Mariani
###
###  2025-06-07 Use FastPro and DrawBytes()
###--------------------------------------------------------------------

//================================

Load "guilib.ring"
load "stdlib.ring"
load "fastpro.ring"
load "matrixlib.ring"

decimals(12) 

###----------------------------------
### ScreenValues

    ScreenX  = 100 // 100  ### Where on Screen
    ScreenY  = 50  // 50

    WinSizeX = 920      // 920  ### Window Size. Mona=>800
    WinSizeY = 920 + 30 // 950  ### SQUARE Window Area

    ButtonY  =   5  ### WinSizeY - 35 ### 915  Button Placement on TOP of Window
    ButtonW  =  90
    ButtonH  =  30

    LabelX   = WinSizeX - 20  ### 900  Label Area within Window
    LabelY   = WinSizeY - 50  ### 900

    MonaX    = WinSizeX - 20  ### 900  Canvas Size - drawing
    MonaY    = WinSizeY - 50  ### 900

    width    = MonaX - 100    ### 800  Mandelbrot Size MonaX - 100
    height   = MonaY - 100    ### 800                  MonaY - 100


    iter     = 50             ### Iteration of N loops before going into Orbit
    offset   = 50             ### Draw on MonaLisa 50 pixels from border Width & Height
    grid     = offset -2      ### Notched grid
    
    aList = list(width,height)   ### Save X-Y Mandelbrot Point Values here

###--------------------------------------------
### Mandelbrot Min-Max Ranges: 
### I = Imaginary=Vertical  R - Real=Horizontal

    minI = -2.00    
    maxI =  2.00    
    minR = -2.00    
    maxR =  2.00     # Default limits
    
###-------------------------------
### Mouse Pressed Points
    nX = 0          #= myfilter.getglobalx()        ### Screen coordinate, NOT Canvas
    ny = 0          #= myfilter.getglobaly()        ### Screen coordinate, NOT Canvas   
    
###---------------------------
### Mouse Move OLD Points
    oX = 0          #= fX  ### Save OLD points
    oY = 0          #= fY
    
###-------------------------------
### Mouse Release Points
    fX = 0          #= myfilter.getglobalx()            ### Screen coordinate, NOT Canvas
    fY = 0          #= myfilter.getglobaly()
    
###-----------------------------------------

    colorBlack  = new qcolor() { setrgb(000,000,000,255) }
    penUseBk    = new qpen()   { setcolor(colorBlack )  setwidth(1) }
    
    
    colorWhite  = new qcolor() { setrgb(255,255,255,255) }
    colorRed    = new qcolor() { setrgb(204,000,000,255) }
    colorGreen  = new qcolor() { setrgb(000,204,000,255) }
    colorBlue   = new qcolor() { setrgb(000,000,255,255) }

    colorGray   = new qcolor() { setrgb(128,128,128,255) }
    colorBrown  = new qcolor() { setrgb(153,076,000,255) }
    colorGrape  = new qcolor() { setrgb(255,178,159,255) }
    colorOrange = new qcolor() { setrgb(255,128,000,255) }

    colorYellow = new qcolor() { setrgb(255,255,000,255) }
    colorPurple = new qcolor() { setrgb(153,153,255,255) }
    colorPink   = new qcolor() { setrgb(255,051,255,255) }
    colorLime   = new qcolor() { setrgb(128,255,000,255) }

    penUseW = new qpen() { setcolor(colorWhite )  setwidth(1) }
    penUseR = new qpen() { setcolor(colorRed   )  setwidth(1) }
    penUseG = new qpen() { setcolor(colorGreen )  setwidth(1) }
    penUseB = new qpen() { setcolor(colorBlue  )  setwidth(1) }

    penUseGr = new qpen() { setcolor(colorGray  )  setwidth(1) }
    penUseBr = new qpen() { setcolor(colorBrown )  setwidth(1) }
    penUseGp = new qpen() { setcolor(colorGrape )  setwidth(1) }
    penUseOr = new qpen() { setcolor(colorOrange)  setwidth(1) }

    penUseYe = new qpen() { setcolor(colorYellow)  setwidth(1) }
    penUsePu = new qpen() { setcolor(colorPurple)  setwidth(1) }
    penUsePi = new qpen() { setcolor(colorPink  )  setwidth(1) }
    penUseLi = new qpen() { setcolor(colorLime  )  setwidth(1) }



    penArray =   [penUseW, penUseR, penUseG, penUseB, PenUseGr, penUseBr, penUseGp, penUseOr, penUseYe, penUsePu, penUsePi, penUseLi]

###===========================================

MyApp = New qapp
{
   win1 =  new qwidget()
    {
        setwindowtitle("Draw Mandelbrot: USE MOUSE to ZOOM-IN")
        setgeometry(ScreenX, ScreenY, WinSizeX, WinSizeY)      ### On Screen
        
        oFont = new qfont("Calibri",14,90,0)
        setFont(oFont)
        
        ###==================================
        
        myfilter = new qallevents(win1)

        myfilter.setCloseEvent("MyApp.Quit()")

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

        ###===================================

        new qpushbutton(win1)
        {
              setgeometry(130,ButtonY, ButtonW, ButtonH)
              settext("Draw")
              setclickevent("Draw()")
        }
        
        
            ###-------------------------------
            ### Draw Label and lineEdit
            
            label1 = new qlabel(win1) 
            {
                    setGeometry(225,ButtonY, 40, ButtonH)
                    setText("Min-I")

            }

            lineEdit1 = new qlineedit(win1) {
                    setGeometry(260,ButtonY, 70, ButtonH)
                    setText(""+minI)
            }
            ###---------------------
            
            label2 = new qlabel(win1) 
            {
                    setGeometry(335,ButtonY, 40, ButtonH)
                    setText("Max-I")

            }

            lineEdit2 = new qlineedit(win1) {
                    setGeometry(370,ButtonY, 70, ButtonH)
                    setText(""+maxI)                 ### value = lineedit1.text() ### Read text field 
            }
            ###---------------------
            
            label3 = new qlabel(win1) 
            {
                    setGeometry(445,ButtonY, 40, ButtonH)
                    setText("Min-R")

            }

            lineEdit3 = new qlineedit(win1) {
                    setGeometry(480,ButtonY, 70, ButtonH)
                    setText(""+minR)
            }
            
            ###---------------------
            
            label4 = new qlabel(win1) 
            {
                    setGeometry(555,ButtonY, 40, ButtonH)
                    setText("Max-R")

            }

            lineEdit4 = new qlineedit(win1) {
                    setGeometry(590,ButtonY, 70, ButtonH)
                    setText(""+maxR)
            }

           ###---------------------
            
            label5 = new qlabel(win1) 
            {
                    setGeometry(665,ButtonY, 40, ButtonH)
                    setText("Iter")

            }

            lineEdit5 = new qlineedit(win1) {
                    setGeometry(700,ButtonY, 50, ButtonH)
                    setText(""+iter)
            }
            
           ###---------------------
            
            label6 = new qlabel(win1) 
            {
                    setGeometry(755,ButtonY, 50, ButtonH)
                    setText("Zoom:")

            }

            lineEdit6 = new qlineedit(win1) {
                    setGeometry(800,ButtonY, 120, ButtonH)
                    setText(""+1)
            }
            
            comboCalc = new QComboBox(win1)  // 720
            {
                setgeometry( 10, ButtonY, 120, ButtonH)
                comboList = ["DisplayBYTES"]
                for x in comboList additem(x,0) next                    
            }
                
          
            
        ###==================================

        Canvas = new qlabel(win1)
        {
            setgeometry(10,40,LabelX, LabelY)  ### In Black Canvas inside Window

            MonaLisa = new qPixMap2( MonaX, MonaY)

            daVinci  = new qpainter()
            {
               begin(MonaLisa)
               setpen(penUseB)
               #endpaint()                      ### This will Stop the Painting
            }

            setpixmap(MonaLisa)
        }
       
       show()   ### Will show Painting ONLY after exec
    }
   exec()
}


###====================================================
### Draw MonaLisa Painting

Func DrawUpdate()

    #MonaLisa.fill(colorBlack)

    Canvas.setpixmap(MonaLisa)              ### Need this setpixmap to display imageLabel
    win1.show()                             ### Need this show to display imageLabel
    MyApp.ProcessEvents()                   ###<<< EXEC the Draw

return

###=============================================================

Func Draw()

    MonaLisa.fill(colorBlack)

    
    minI = number( lineEdit1.text() )   ### Get values from edit box on bottom of screen
    maxI = number( lineEdit2.text() )
    minR = number( lineEdit3.text() )
    maxR = number( lineEdit4.text() )
    iter = number( lineEdit5.text() )
    
    //=== Stay InBounds =============
    if( minI < -2.0 || maxI >  2.0 || minR < -2.0 || maxR >  2.0 || iter > 50 )
        lineEdit1.setText(""+ -2.0) 
        lineEdit2.setText(""+  2.0) 
        lineEdit3.setText(""+ -2.0) 
        lineEdit4.setText(""+  2.0) 
        lineEdit5.setText(""+ 50  )   
    ok  
    
        if ( MaxI - MinI = 0 ) || (MaxR - MinR = 0 )
            See "Size of Mandelbrot Area too Small  " +nl
            return
        ok  
    
    decimals(0)
    zoom =  ( 16 / (( maxI - minI) * (maxR - minR)))    ### Smaller square = bigger magnify
    lineEdit6.setText(""+zoom)
    decimals(3) // 8
    
            ###-------------------------------------------------------------------------
            ### Range: Imaginary-Vertical and Real-Horizontal. Limits are +-2
            
            ### minI = -2.0    maxI = 2.0    minR = -2.0    maxR = 2.0     # Default limits
            ### minI = -0.1    maxI = 0.1    minR = -1.9    maxR = -1.7
            ### minI = -0.03   maxI = 0.03   minR = -1.81   maxR = -1.74   
            ### minI = -0.003  maxI = 0.003  minR = -1.7850 maxR = -1.7820
     
            ###----------------------------
            ### Draw Grid - Notches
    
            daVinci.setpen(penUseW)
            daVinci.drawLine(grid, grid, grid+width, grid)         ### H
            daVinci.drawLine(grid, grid, grid,       grid+height)  ### V
            
            for i = 0 to width step (width / 100)    ### Width 800
                notch = 10
                if i % (width / 10) = 0  
                    notch = 20 
                    incI = (maxI - minI) / height
                    incR = (maxR - minR) / width
                    
                    rI = minI + ( incI * i)
                    rR = minR + ( incR * i)
                    
                    daVinci.drawText(grid+i,          grid-notch , (""+rR) )        ### H
                    daVinci.drawText(grid-notch-notch,    grid+i , (""+rI) )        ### V               
                ok

                    daVinci.drawLine(grid+i, grid, grid+i, grid-notch)      ### H            
                    daVinci.drawLine(grid  , grid+i, grid-notch,   grid+i)  ### V
                     
            next
            
    decimals(12)   // 12      

    ###----------------------------------------------------------
    ### CALCULATOR FASTPRO Draw X-Y Mandelbrot Points Values
    ### Imaginary-Vertical and Real-Horizontal. Limits are +-2
    ### minI = -2.0    maxI = 2.0    minR = -2.0    maxR = 2.0  # Default limits 
    
    // 100x100xx =   40000   40x40x4 = 6400
    // 200x200x4 =  160000
    // 400x400x4 =  640000
    // 800x800x4 = 2560000
    
    
     //width    = 400 // DEBUG 
     //height   = 400 // DEBUG

     stepR = (maxR - minR) / width               ### step-Real-horizontal
     stepI = (maxI - minI) / height              ### step-Virtual-vertical
     
     See "Values:" +nl +
          "minI:  "+minI  +" maxI: "+maxI     +nl +
          "minR:  "+minR  +" maxR: "+maxR     +nl +
          "iter:  "+iter                      +nl +
          "stepI: "+stepI +" stepR: "+stepR   +nl +
          "width: "+width +" height: "+height +nl+nl 
    
        
    aList  = list(width, height)            ### Save N value here for each Pixel
        
//  aFlatB = [-2, 2, -2, 2, 50, 0.005, 0.005, 20, 20]       
    aFlatB = [minI, maxI, minR, maxR, iter, stepI, stepR, width, height]  


    //=======================================================  
    //FASTPRO


    ###========================================================
    ###--------------------------------------------------------
    ### FAST DRAW the aList[x][y]  N-values that were calculated
    ###          aList = list(width,height)   
    ### (1) DrawHSVFList( Ring List of points where each item is a sub list contains x,y,h,s,v,f )
    ### (2) DrawRGBFList( Ring List of points where each item is a sub list contains x,y,r,g,b,f )
  

            ### DrawBytes() uses 00-ff CHAR value
            ### Table is in FastPro C format with { }   
            
            aCHR = [[ char(255), char(255), char(255), char(255)], 
                    [ char(204), char(000), char(000), char(255)], 
                    [ char(000), char(204), char(000), char(255)], 
                    [ char(000), char(000), char(255), char(255)], 
                    [ char(128), char(128), char(128), char(255)], 
                    [ char(153), char(076), char(000), char(255)], 
                    [ char(255), char(178), char(159), char(255)], 
                    [ char(255), char(128), char(000), char(255)], 
                    [ char(255), char(255), char(000), char(255)], 
                    [ char(153), char(153), char(255), char(255)], 
                    [ char(255), char(051), char(255), char(255)], 
                    [ char(128), char(255), char(000), char(255)],
                    [ char(000), char(000), char(000), char(255)]   // Black
                   ]
                 
        //---------------------------------------
        
    DrawType = comboCalc.currentText()   // DisplayRGB  DisplayHSV  DisplayBYTES            
    
    //---------------------------
    // DISPLAY RGB - Removed
 
    //------------------------------
    // DISPLAY HSV - Removed

    //-----------------------------------
    // DISPLAY BYTES
    
    if DrawType = "DisplayBYTES"
       See "DisplayBYTES"+nl         
        
       //--------------------------------
       // Generate FList with FastPro

          startClock1 = clock()  
       Flist = updatelist(aList,:mandelBrot,:matrix,aFlatB )
	   
          startClock2 = clock()
       daVinci.DrawBytes( offset, offset, FList, width, height, 4)   // Bytes color array
	   
          startClock3 = clock()
 
       ? " "
       ? "TimeCalc FList = " + ((startClock2 - startClock1)) + " millisecs" 
       ? "TimeDraw BYTES = " + ((startClock3 - startClock2)) + " millisecs"
         
    ok      
    

    ###========================================================    
    ###--------------------------------------------------------
    ### Draw center lines
    
    daVinci.drawLine(grid,           grid+(height/2), grid+width,     grid+(height/2))  ### H
    daVinci.drawLine(grid+(width/2), grid,            grid+(width/2), grid+height)      ### V

    See "FINISHED: "+ nl
    win1.setwindowtitle("FINISHED - Use MOUSE to Select Area to Zoom In ")
    DrawUpdate()


return

###===================================================
###===================================================
###===================================================

###--------------------------------------------------------------------

Func pPress
    
    nX = myfilter.getx() -8         ### Screen coordinate, Canvas = myfilter.globalx()
    ny = myfilter.gety() -8 -30     ### Screen coordinate, NOT Canvas
    
    win1.setWindowTitle("Press: Top: "+ nX +"-"+ nY +" Bot:"+ fX +"-" +fY )

    daVinci.setCompositionMode(26)      ###  THIS is the MAGIC - Erase Old Line when Redrawn
    
    oX = nX  ### Save Pressed Mouse point as OLD points
    oY = nY
    
return



###------------------------------------------------------------------------

Func pMove


    fX = myfilter.getx() -8         ### Screen coordinate, NOT Canvas
    fY = myfilter.gety() -8 -30  
    
    xWidth  = fX - nX
    yHeight = fY - nY
    
    fX = nX + yHeight   ### make square. = height length

    win1.setWindowTitle("Move: Top:"+ nX +"-"+ nY +" Bot: "+ fX +"-"+ fY +" Width:"+ (xWidth) +" Height:"+ (yHeight) )
    
    pDrawObjects()      ### Draw Mouse Square outline

    DrawUpdate()
    
    oX = fX  ### Save OLD points
    oY = fY
    
return

###------------------------------------------------------------------------

Func pRelease


    fX = myfilter.getx() -8         ### Screen coordinate, NOT Canvas
    fY = myfilter.gety() -8 -30  
    
    xWidth  = fX - nX
    yHeight = fY - nY
    
    fX = nX + yHeight   ### make square. = height length

    win1.setWindowTitle("Release: Top: "+ nX +"-"+ nY +" Bot:"+ fX +"-"+ fY +" Width: "+ (xWidth) + " Height:"+ (yHeight) )
   
    pDrawObjects()

    DrawUpdate()
    CalculateZoom()
    
return

###--------------------------------------------------------------------

###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
    Rec = win1.framegeometry()

    WinWidth  = Rec.width()             ### Current Values
    WinHeight = Rec.height()            ### 
    
    WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
    WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
    WinRight  = Rec.right()
    WinBottom = Rec.bottom()
    
    ### win1{ setwindowtitle("Window ReSize: Width:"+  WinWidth +" Height:"+ WinHeight + 
    ###        " --- LT "+  WinLeft +"-"+ WinTop  +" --- RB "+ WinRight +"-"+ WinBottom + 
    ###        " Width: "+ width +" Height: "+ height ) }
            
return

###---------------------------------------
### Window Moved

Func WhereMoved()

    xPos = win1.x()  +8                 ### <<< QT FIX because of Win Title
    yPos = win1.y() +30                 ### <<< QT FIX because of Win Title

    ### win1{ setwindowtitle("Window Moved: HPos: " + xPos +" VPos: "+ yPos ) }  
    
return

###-----------------------
### Draw the Mouse Square

Func pDrawObjects()
 
    ### Rectangle
    oldLenX = oX - nX                               ### old - new position
    oldLenY = oY - nY
    
    newLenX = fX - nX                               ### final - new position
    newLenY = fY - nY
    
    daVinci.drawRect( nX, nY, oldLenX, oldLenY )    ### ReDraw OLD Line to Erase
    daVinci.drawRect( nX, nY, newLenX, newLenY )    ### Draw NEW Line
    
     
return

###---------------------------

Func pClear()

    daVinci.setCompositionMode(0)       ### Put back to default mode 0     
    MonaLisa.fill(colorBlack)           ### Clear painting canvas
    daVinci.setCompositionMode(26)      ### THIS is the MAGIC - Erase Old Line when Redrawn
    
    DrawUpdate()
    
return

###-------------------------------------------------
### CalculateZoom - Portion of Mandelbrot to expand
### 378-223 to 515-358  areaW   138   areaH 135
###                     MandelW 800 MandelH 800

Func CalculateZoom()

    nMinR = nX  - offset                        ### 378  Horizontal
    nMaxR = fX  - offset                        ### 515
    nMinI = nY  - offset                        ### 223  Vertical
    nMaxI = fY  - offset                        ### 358
    
    if nMaxI < nMinI                            ### nMinI smaller than nMaxI
        nTemp = nMaxI
        nMaxI = nMinI
        nMinI = nTemp
    ok
    
    if nMaxR < nMinR                            ### nMinR smaller than nMaxR
        nTemp = nMaxR
        nMaxR = nMinR
        nMinR = nTemp
    ok

    stepR = fabs(maxR - minR) / (width  )       ### step-Real-horizontal
    stepI = fabs(maxI - minI) / (height )       ### step-Virtual-vertical

    newMinR = minR + (nMinR * stepR )
    newMaxR = minR + (nMaxR * stepR )

    newMinI = minI + (nMinI * stepI ) 
    newMaxI = minI + (nMaxI * stepI ) 
    
    See " newMinI:"+ newMinI +" newMinR:"+ newMinR +nl 
    See " newMaxI:"+ newMaxI +" newMaxR:"+ newMaxR +nl
    See nl+nl
    
 
    
    lineEdit1.setText(""+ newMinI)  ### Put values in edit box on bottom of screen
    lineEdit2.setText(""+ newMaxI)
    lineEdit3.setText(""+ newMinR)
    lineEdit4.setText(""+ newMaxR)
    

return

###-----------------------------------------
