### Project : Mandelbrot Set
### Date    : 2019/03-18
###  Mandelbrot - Colorized and Animated
###  2019-02-25  Bert Mariani
###
###  MyApp.ProcessEvents()  ###<<< EXEC the Draw MonaLisa between each step of array sorting
###
###--------------------------------------------------------------------
#
# Use mylibMandel.c  as input to VisualStudio-2019-Community
# Use buildvc-2.bat  batch to Build the mylibMandel.dll required
#
###--------------------------------------------------------------------
### OUTPUT
#
#* *********************************************************************
#  ** Visual Studio 2017 Developer Command Prompt v15.9.9
#  ** Copyright (c) 2017 Microsoft Corporation
#  **********************************************************************
#  Microsoft (R) C/C++ Optimizing Compiler Version 19.16.27027.1 for x86
#  Copyright (C) Microsoft Corporation.  All rights reserved.
#
#  mylibMandel.c
#  Microsoft (R) Incremental Linker Version 14.16.27027.1
#  Copyright (C) Microsoft Corporation.  All rights reserved.
#  
#  Press any key to continue . . .
#  
###--------------------------------------------------------------------
### DIRECTORY
#
#      C:\MyStuff\AA-Mandelbrot-2>dir
#       Volume in drive C has no label.
#       Volume Serial Number is 4EAE-5066
#
#       Directory of C:\MyStuff\AA-Mandelbrot-2
#
#     2020-10-22  06:39 PM    <DIR>          .
#     2020-10-22  06:39 PM    <DIR>          ..
#     2020-10-22  05:50 PM               257 buildvc-2.bat
#     2020-10-22  06:33 PM            19,895 Mandelbrot-10.ring
#     2019-05-25  03:41 PM             6,047 mylibMandel.c
#     2020-10-22  06:28 PM           420,352 mylibMandel.dll
#     2020-10-22  06:28 PM               695 mylibMandel.exp
#     2020-10-22  06:28 PM         1,846,236 mylibMandel.ilk
#     2020-10-22  06:28 PM             1,766 mylibMandel.lib
#     2020-10-22  06:28 PM         6,524,928 mylibMandel.pdb
#                    9 File(s)      8,820,300 bytes
#                    2 Dir(s)  164,299,460,608 bytes free
#
###--------------------------------------------------------------------
###  BATCH Script
###
# :: buildvc-2.bat
# 
# cls
# call c:\ring\language\src\locatevc.bat   
# cl /c /DEBUG mylibMandel.c -I"c:\ring\language\include"
# link /DEBUG mylibMandel.obj c:\ring\lib\ring.lib /DLL /OUT:mylibMandel.dll /SUBSYSTEM:CONSOLE,"5.01"
# del mylibMandel.obj
# pause
#
###--------------------------------------------------------------------

//================================

Load "guilib.ring"
load "stdlib.ring"

? "Loading Library"

if iswindows()
	LoadLib("mylibMandel.dll")
but ismacosx()
	LoadLib("libmylibMandel.dylib")
else
	LoadLib("libmylibMandel.so")
ok


UseCcalculator = 1   ###<<< True-1. Ring-C-Array draws WRONG direction
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


    width    = MonaX - 100    ### 800  Mandelbrot Size
    height   = MonaY - 100    ### 800

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
        
        oFont = new qfont("",8,0,0)
        setFont(oFont)
        
        ###==================================
        
        myfilter = new qallevents(win1)

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
              setgeometry(10,ButtonY, ButtonW, ButtonH)
              settext("Draw")
              setclickevent("Draw()")
        }
        
        
            ###-------------------------------
            ### Draw Label and lineEdit
            
            label1 = new qlabel(win1) 
            {
                    setGeometry(105,ButtonY, 40, ButtonH)
                    setText("Min-I")

            }

            lineEdit1 = new qlineedit(win1) {
                    setGeometry(140,ButtonY, 70, ButtonH)
                    setText(""+minI)
            }
            ###---------------------
            
            label2 = new qlabel(win1) 
            {
                    setGeometry(215,ButtonY, 40, ButtonH)
                    setText("Max-I")

            }

            lineEdit2 = new qlineedit(win1) {
                    setGeometry(250,ButtonY, 70, ButtonH)
                    setText(""+maxI)                 ### value = lineedit1.text() ### Read text field 
            }
            ###---------------------
            
            label3 = new qlabel(win1) 
            {
                    setGeometry(325,ButtonY, 40, ButtonH)
                    setText("Min-R")

            }

            lineEdit3 = new qlineedit(win1) {
                    setGeometry(360,ButtonY, 70, ButtonH)
                    setText(""+minR)
            }
            
            ###---------------------
            
            label4 = new qlabel(win1) 
            {
                    setGeometry(435,ButtonY, 40, ButtonH)
                    setText("Max-R")

            }

            lineEdit4 = new qlineedit(win1) {
                    setGeometry(470,ButtonY, 70, ButtonH)
                    setText(""+maxR)
            }

           ###---------------------
            
            label5 = new qlabel(win1) 
            {
                    setGeometry(545,ButtonY, 40, ButtonH)
                    setText("Iter")

            }

            lineEdit5 = new qlineedit(win1) {
                    setGeometry(580,ButtonY, 50, ButtonH)
                    setText(""+iter)
            }
            
           ###---------------------
            
            label6 = new qlabel(win1) 
            {
                    setGeometry(635,ButtonY, 40, ButtonH)
                    setText("Zoom:")

            }

            lineEdit6 = new qlineedit(win1) {
                    setGeometry(670,ButtonY, 180, ButtonH)
                    setText(""+1)
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
    
        if ( MaxI - MinI = 0 ) || (MaxR - MinR = 0 )
        See "Size of Mandelbrot Area too Small  " +nl
            return
        ok  
    
    decimals(0)
    zoom =  ( 16 / (( maxI - minI) * (maxR - minR)))    ### Smaller square = bigger magnify
    lineEdit6.setText(""+zoom)
    decimals(8)
    
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
            
    decimals(12)        

    ###----------------------------------------------------------
    ### CALCULATOR Draw X-Y Mandelbrot Points Values
    ### Imaginary-Vertical and Real-Horizontal. Limits are +-2
    ### minI = -2.0    maxI = 2.0    minR = -2.0    maxR = 2.0     # Default limits 

    SEE "Range: "+nl +"MinI:"+ minI +" MinR:"+ minR +nl +"MaxI:"+ maxI +" MaxR:"+ maxR +" W: "+width +" H: "+height +nl

    aList  = list(width, height)            ### Save N value here for each Pixel
    
    startCalcClock = clock()
    
    if UseCcalculator = 1
        mandel( minI,maxI,minR, maxR,iter,width,height,aList ) 
    else
    
        ###---------------------------------------------------------
        ### RING CALCULATOR

    stepR = (maxR - minR) / width               ### step-Real-horizontal
    stepI = (maxI - minI) / height              ### step-Virtual-vertical

    for y = 1 to height                         ### Each vertical point Ring at 1
         pointI = minI + stepI * y              ### Imaginary + Step

        for x = 1 to width                      ### Each horizontal point Ring at 1
              pointR = minR + stepR * x         ### Real horizontal + Step

               zR = pointR                      ### Depth - horizontal-real
               zI = pointI                      ### Depth - vertical-imaginary

            for n = 0 to iter                   ### Does it leave Orbit ?
                a = zR * zR                     ###  zR^2  - horizontal-real
                b = zI * zI                     ###  zI^2  - vertical-imaginary

                if a + b > 4 exit ok            ### Beyond boundary limits +-2 

                zI = 2 * zR * zI + pointI       ### Vertical-imaginary + Step
                zR = a - b + pointR             ### Horizontal-real

            next

            aList[x][y] = N
            
        next
    next
    ok
    
    
? "TimeCalc = " + ((clock()-startCalcClock)/clockspersecond()) + " seconds"
    
    ###--------------------------------------------------------
    ### Draw the aList[x][y]  N-values that were calculated

    startDrawClock = clock()
    nLastPenID = 0

    for y = 1 to height
        for x = 1 to width
            N = alist[x][y]
            if N > 0 and N < iter    
                nPenID = N % 12 + 1
                penToUse = penArray[nPenID]

                if nPenID != nLastPenID
                    nLastPenID = nPenID
                    daVinci.setpen(penToUse)
                ok

                if UseCcalculator = 1
                    daVinci.drawpoint(y+offset, x+offset)   ### Ring-C-array WRONG direction
                else
                    daVinci.drawpoint(x+offset, y+offset)
                ok
            ok
       next    

        if y % 5 = 0
               DrawUpdate()
       ok
     next    

    ? "TimeDraw = " + ((clock()-startDrawClock)/clockspersecond()) + " seconds" 
        
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
