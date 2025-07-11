### Project : Mandelbrot Set
### Date    : 2019/03-18
###  Mandelbrot - Colorized and Animated
###  2019-02-25  Bert Mariani
###
###  2025-06-07 Use FastPro and DrawBytes()
###--------------------------------------------------------------------
// Location Name          Coordinates (Real, Imag)              What You'll See
// SeahorseValley         -0.75,     0.1                        Spirals and seahorse-like filaments
// ElephantValley          0.285,    0                          Trunk-like curves and bulbous shapes
// TripleSpiralValley     -0.1015,   0.633                     Interloc spirals with high complexity
// MiniMandelbrot         -1.25,     0                         A tiny replica of the full Mandel
// FeigenbaumPoint        -1.401155, 0                         Period-doubling cascade and bifurcations
//
// MainCardioidCenter (~ -0.5    + 0i):
// CuspMainCardioid   (~  0.25   + 0i):
// Period-2BulbCenter (~ -1      + 0i):
// ElephantValley2    (~ 0.1     + 0.5i): xxx
// SpiralCenters      (~ -0.12   + 0.75i):
// BoundarySet        (~  0.25   + 0.0001i):
// MisiurewiczPoints  (~ -0.1011 + 0.9563i):

// Changes in July 11, 2025 by Mounri IDRASSI
// - Added "Reset" button to restore default view and "Save" button to export the current image as PNG with timestamp.
// - Standardized variable naming from ny to nY

//================================

Load "guilib.ring"
load "stdlib.ring"
load "fastpro.ring"
load "matrixlib.ring"

decimals(8)  // 6 (12) 

DrawType      = "Filled By DropDown"
DrawMouseType = "EmptyMouseType"    


###----------------------------------
### ScreenValues

    ScreenX  = 100 // 100  ### Where on Screen
    ScreenY  = 50  // 50

    WinSizeX = 920    // 920  ### Window Size. Mona=>800
    WinSizeY = 950    // 950  ### SQUARE Window Area

    ButtonY  =   5  ### WinSizeY - 35 ### 915  Button Placement on TOP of Window
    ButtonW  =  90
    ButtonH  =  30

    LabelX   = WinSizeX - 20   ### 920-20  Label Area within Window
    LabelY   = WinSizeY - 50   ### 950-50

    MonaX    = WinSizeX - 20      ### 920-20  Canvas Size - drawing
    MonaY    = WinSizeY - 50   ### 950-50

    width    = MonaX - 100    ### 800  Mandelbrot Size MonaX - 100
    height   = MonaY - 100    ### 800                  MonaY - 100


    iter     = 50             ### Iteration of N loops before going into Orbit
    offset   = 50             ### Draw on MonaLisa 50 pixels from border Width & Height
    grid     = offset -2      ### Notched grid
    
    aList = list(width,height)   ### Save X-Y Mandelbrot Point Values here

###--------------------------------------------
### Mandelbrot Min-Max Ranges: 
### I = Imaginary=Vertical  R - Real=Horizontal

    minI = -2.00    # Fill in Text Value  in Label   
    maxI =  2.00    
    minR = -2.00    
    maxR =  2.00    # Default limits
    
    zoomInc   = 0.0005  // 0.0005Inc bwtween images
    zoomLoop  = 300     // 200    // 200 = 0.0005  zoomInc
    zoomRange = 0.1500  // 0.1100 // 0.1100 Start this far out
       
###-------------------------------
### Mouse Pressed Points
    nX = 0          #= myfilter.getglobalx()        ### Screen coordinate, NOT Canvas
    nY = 0          #= myfilter.getglobaly()        ### Screen coordinate, NOT Canvas   
    
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
    penUseBk    = new qpen() { setcolor(colorBlack )  setwidth(1) }
    
    
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
   win1 = new qwidget()
    {
        setwindowtitle("Draw Mandelbrot: USE MOUSE to ZOOM-IN")
        setgeometry(ScreenX, ScreenY, WinSizeX, WinSizeY)      ### On Screen
        
        oFont = new qfont("Calibri",12,90,0)
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
            myfilter.setMoveEvent(   "WhereMoved()") 

        ###===================================


            new qpushbutton(win1)
            {
              setgeometry(10,ButtonY, ButtonW-5, ButtonH)
              settext("Reset")
              setclickevent("ResetView()")
              setStyleSheet("background-color: lightblue")
            }

            new qpushbutton(win1)
            {
              setgeometry(100,ButtonY, ButtonW-5, ButtonH)
              settext("Save")
            //setclickevent("SaveImage()")        // Mounir
			  setclickevent(" pSaveAsFile()")     // Dialog
              setStyleSheet("background-color: violet")
            }      
 
            new qpushbutton(win1)
            {
              setgeometry( 190,ButtonY, ButtonW-10, ButtonH)
              settext("Draw")
              setclickevent("Draw()")
              setStyleSheet("background-color: cyan")
            } 
			
			
            ###-------------------------------
            ### Draw Label and lineEdit
            
            label1 = new qlabel(win1) 
            {
                    setGeometry(280,ButtonY, 60, ButtonH)
                    setText("Min-I")
                    setStyleSheet("background-color: yellow")

            }

            lineEdit1 = new qlineedit(win1) {
                    setGeometry(280,ButtonY +ButtonH, 100, ButtonH)
                    setText(""+minI)
                    setStyleSheet("background-color: lightgray")
                    setalignment(Qt_AlignHCenter) // Right Left HCenter
            }
            ###---------------------
            
            label2 = new qlabel(win1) 
            {
                    setGeometry(390,ButtonY, 60, ButtonH)
                    setText("Max-I")
                    setStyleSheet("background-color: yellow")

            }

            lineEdit2 = new qlineedit(win1) {
                    setGeometry(390,ButtonY +ButtonH, 100, ButtonH)
                    setText(""+maxI)                 ### value = lineedit1.text() ### Read text field 
                    setStyleSheet("background-color: lightgray")
                    setalignment(Qt_AlignHCenter)
            }
            ###---------------------
            
            label3 = new qlabel(win1) 
            {
                    setGeometry(500,ButtonY, 60, ButtonH)
                    setText("Min-R")
                    setStyleSheet("background-color: yellow")

            }

            lineEdit3 = new qlineedit(win1) {
                    setGeometry(500,ButtonY +ButtonH, 100, ButtonH)
                    setText(""+minR)
                    setStyleSheet("background-color: lightgray")
                    setalignment(Qt_AlignHCenter)
            }
            
            ###---------------------
            
            label4 = new qlabel(win1) 
            {
                    setGeometry(610,ButtonY, 60, ButtonH)
                    setText("Max-R")
                    setStyleSheet("background-color: yellow")
            }

            lineEdit4 = new qlineedit(win1) {
                    setGeometry(610,ButtonY +ButtonH, 100, ButtonH)
                    setText(""+maxR)
                    setStyleSheet("background-color: lightgray")
                    setalignment(Qt_AlignHCenter)
            }

           ###---------------------
            
            label5 = new qlabel(win1) 
            {
                    setGeometry(720,ButtonY, 60, ButtonH)
                    setText("Iter")
                    setStyleSheet("background-color: yellow")

            }

            lineEdit5 = new qlineedit(win1) {
                    setGeometry(720,ButtonY +ButtonH, 60, ButtonH)
                    setText(""+iter)
                    setStyleSheet("background-color: lightgray")
                    setalignment(Qt_AlignHCenter)
            }
            
           ###---------------------
            
            label6 = new qlabel(win1) 
            {
                    setGeometry(790,ButtonY, 60, ButtonH)
                    setText("Zoom:")
                    setStyleSheet("background-color: yellow")

            }

            lineEdit6 = new qlineedit(win1) {
                    setGeometry(790,ButtonY +ButtonH, 120, ButtonH)
                    setText(""+1)
                    setStyleSheet("background-color: lightgray")
                    setalignment(Qt_AlignHCenter)
            }
            
            //-------------------------------------
            
            comboCalc = new QComboBox(win1)  // 720
            {
                setgeometry( 10, ButtonY +ButtonH, 260, ButtonH)
				setStyleSheet("background-color: lightgreen")
                comboList = ["DrawPoint","Seahorse","Elephant","Feigenbaum","Misiurewicz","Mariani","MiniMandel","MainCardioid","Period2Bulb","SpiralCenters","Elephant2"]              

                for x in comboList additem(x,0) next 
            }     
                
          
            
        ###==================================

        Canvas = new qlabel(win1)
        {   ### In Black Canvas inside Window, make room for EditText = 60
            setgeometry(10,60,LabelX, LabelY)  ### In Black Canvas inside Window

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

       // USE ReadMinMaxPoints()
        minI = number( lineEdit1.text() )   
        maxI = number( lineEdit2.text() )
        minR = number( lineEdit3.text() )
        maxR = number( lineEdit4.text() )
        
    
    DrawType = comboCalc.currentText()   //DropDown List
    
    if DrawMouseType = "SelectArea"
          See "DrawMouseType: "+ DrawMouseType +nl  

    elseif DrawType = "DrawPoint"
       See "DrawPoint"+nl
          minI = -2.0 - zoomRange   maxI = 2.0 + zoomRange
          minR = -2.0 - zoomRange   maxR = 2.0 + zoomRange  

       
    elseif DrawType = "Mariani"
       See "Mariani"+nl
          minI = -0.2954803125 - zoomRange   maxI = -0.2853637500 + zoomRange
          minR = -1.1664400000 - zoomRange   maxR = -1.1563234375 + zoomRange  
    
    
    elseif DrawType = "Seahorse" 
       See "Seahorse"+nl    
       minI =  0.1   - (zoomRange *1.5)   maxI =  0.1   + (zoomRange *1.5)    
       minR = -0.755 - (zoomRange *1.5)   maxR = -0.755 + (zoomRange *1.5)
 
 
   elseif DrawType = "Elephant" 
       See "Elephant"+nl
       minI = 0.0   - (zoomRange *1.5)  maxI = 0.0   + (zoomRange *1.5)
       minR = 0.285 - (zoomRange *1.5)  maxR = 0.285 + (zoomRange *1.5)   
 
 
   elseif DrawType = "MiniMandel"
       See "MiniMandel"+nl
       minI =  0.0  - (zoomRange *2)  maxI =  0.0  + (zoomRange *2)
       minR = -1.25 - (zoomRange *2)  maxR = -1.25 + (zoomRange *2)
 
 
    elseif DrawType = "Feigenbaum"
       See "Feigenbaum"+nl
       minI =  0.0      - (zoomRange *1.5)  maxI =  0.0      + (zoomRange *1.5)
       minR = -1.401155 - (zoomRange *1.5)  maxR = -1.401155 + (zoomRange *1.5)

    
    elseif DrawType = "MainCardioid"    //  (~ -0.5  + 0i):
       See "MainCardioid"+nl
       minI =  0.0 - (zoomRange*5)  maxI =  0.0 + (zoomRange*5)
       minR = -0.5 - (zoomRange*5)  maxR = -0.5 + (zoomRange*5)
 
 
    elseif DrawType = "Period2Bulb"        //(~ -1  + 0i):      
       See "MainCardioid"+nl
       minI =  0.0 - (zoomRange *5) maxI =  0.0 + (zoomRange *5)
       minR = -1.0 - (zoomRange *5) maxR = -1.0 + (zoomRange *5)

    
    elseif DrawType = "Elephant2"          //(~ 0.1  + 0.5i)
       See "Elephant2"+nl
       minI = 0.65 - (zoomRange *4)  maxI = 0.65 + (zoomRange *4)
       minR = 0.15 - (zoomRange *4)  maxR = 0.15 + (zoomRange *4)
    
    elseif DrawType = "SpiralCenters"   // (~ -0.12   + 0.75i)
       See "SpiralCenters"+nl
       minI =  0.75 - (zoomRange *3)  maxI =  0.75 + (zoomRange *3)
       minR = -0.12 - (zoomRange *3)  maxR = -0.12 + (zoomRange *3)
 
 
    elseif DrawType = "Misiurewicz"   // (~ -0.1011 + 0.9563i):
       See "Misiurewicz"+nl
       minI =  0.9563 - zoomRange   maxI =  0.9563 + zoomRange 
       minR = -0.1011 - zoomRange   maxR = -0.1011 + zoomRange 
  
  
    else    
      // Use Min Max, or DrawPoint in DropDown
      // Mouse sets DrawType = "SelectArea"
      See "Default SelectArea: Use Min Max Values"+nl
    
    ok  
    
    
    //----------------------------
    // SET the Min Max Points
  
      lineEdit1.setText(""+ minI) 
      lineEdit2.setText(""+ maxI)
      lineEdit3.setText(""+ minR)
      lineEdit4.setText(""+ maxR)   
 
for $count = 1 to zoomLoop  // 200 = 0.0005  zoomInc

    MonaLisa.fill(colorBlack)

    ### Get values from edit box on bottom of screen
    minI = number( lineEdit1.text() )   
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
    
        if( MaxI - MinI = 0 ) || (MaxR - MinR = 0 )
            See "Size of Mandelbrot Area too Small  " +nl
            win1.setWindowTitle("Size of Mandelbrot Area too Small")

            //Restore Full Size
            lineEdit1.setText(""+ -2.0) 
            lineEdit2.setText(""+  2.0) 
            lineEdit3.setText(""+ -2.0) 
            lineEdit4.setText(""+  2.0) 
            lineEdit5.setText(""+ 50  )              
     
            return
        ok  
    
    ### Smaller square = bigger magnify
    decimals(0)
    zoom =  ( 16 / (( maxI - minI) * (maxR - minR)))  
    lineEdit6.setText(""+zoom)
    decimals(8) // 3 8
    
            ###-------------------------------------------------------------------------
            ### Range: Imaginary-Vertical and Real-Horizontal. Limits are +-2           
            ### minI = -2.0  maxI = 2.0  minR = -2.0  maxR = 2.0  # Default 

     
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
            
    decimals(8)   // 6 12      

    ###----------------------------------------------------------
    ### CALCULATOR FASTPRO Draw X-Y Mandelbrot Points Values
    ### Imaginary-Vertical and Real-Horizontal. Limits are +-2
    ### minI = -2.0    maxI = 2.0    minR = -2.0    maxR = 2.0  # Default limits 
    
     stepR = (maxR - minR) / width               ### step-Real-horizontal
     stepI = (maxI - minI) / height              ### step-Virtual-vertical
     
 //    See "Values:" +nl +
 //         "minI:  "+minI  +" maxI: "+maxI     +nl +
 //         "minR:  "+minR  +" maxR: "+maxR     +nl +
 //         "iter:  "+iter                      +nl +
 //         "stepI: "+stepI +" stepR: "+stepR   +nl +
 //         "width: "+width +" height: "+height +nl+nl 
    
        
    aList  = list(width, height)     ### Save N value here for each Pixel
            
    aFlatB = [minI, maxI, minR, maxR, iter, stepI, stepR, width, height]  


    //=======================================================  
    //FASTPRO


    ###========================================================
    ###--------------------------------------------------------
    ### FAST DRAW the aList[x][y]  N-values that were calculated
    ###        aList = list(width,height)   
  
            ### DrawBytes() uses 00-ff CHAR value
            ### Table is in FastPro C format with { }   
            
           // aCHR = [[ char(255), char(255), char(255), char(255)], 
           
            aCHR = [   
                    [ 255, 255, 255, 255],   //  0  1 White 
                    [   0, 255, 128, 255],   //  1  0 204,0,0,255 Red
                    [   0, 204,   0, 255],   //  2  3 Green 
                    [   0,   0, 255, 255],   //  3  4 Blue  
                    [ 128, 128, 128, 255],   //  4  5 Gray  
                    [ 153,  76,   0, 255],   //  5  6 Brown 
                    [ 255, 178, 159, 255],   //  6  7 Grape 
                    [ 255, 128,   0, 255],   //  7  8 Orange
                    [ 255, 255,   0, 255],   //  8  9 Yellow
                    [ 153, 153, 255, 255],   //  9 10 Purple
                    [ 255,  51, 255, 255],   // 10 11 Pink  
                    [ 128, 255,   0, 255],   // 11 12 Lime 
                    [   0, 255, 255, 255],   // 12 13 Cyan ---
                    [ 255,   0, 255, 255],   // 13 14 Magenta,Fuschia   
                    [ 255, 127,  80, 255],   // 14 15 Coral 
                    [ 255, 215,   0, 255],   // 15 16 Gold
                    [ 154, 205,  50, 255],   // 16 17 Yellow Green
                    [ 127, 255,   0, 255],   // 17 18 Chartreuse
                    [  64, 224, 208, 255],   // 18 19 Turquoise
                    [   0, 191, 255, 255],   // 19 20 Deep Sky Blue
                    [ 221, 160, 221, 255],   // 20 21 Plum
                    [ 255, 105, 180, 255],   // 21 22 Hot Pink
                    [ 250, 235, 215, 255],   // 22 23 Antique White
                    [ 205, 133,  63, 255],   // 23 24 Peru
                    [ 176, 196, 222, 255],   // 24 25 Light Steel Blue
                    [ 148,   0, 211, 255],   // 25 26 Dark Violet
                    [ 173, 216, 230, 255],   // 26 27 Doger Blue
                    [   0, 255, 127, 255],   // 27 28 Spring Green
                    [ 255,  99,  71, 255],   // 28 29 Tomato
                    [ 240, 230, 140, 255],   // 29 30 Khaki
                    [ 143, 188, 143, 255],   // 30 31 Dark Sea Green
                    [   0, 206, 209, 255]    // 31 32 Dark Turquoise 
                   ]
                 
        //---------------------------------------
                
    //-----------------------------------
    // DISPLAY BYTES

       //--------------------------------
       // Generate FList with FastPro

          startClock1 = clock()  
       Flist = updatelist(aList,:mandelBrot,:matrix,aFlatB )
       
          startClock2 = clock()
       daVinci.DrawBytes( offset, offset, FList, width, height, 4)   // Bytes color array
       
          startClock3 = clock()
 
//       ? " "
//       ? "TimeCalc FList = " + ((startClock2 - startClock1)) + " millisecs" 
//       ? "TimeDraw BYTES = " + ((startClock3 - startClock2)) + " millisecs"

    ###========================================================    
    ###--------------------------------------------------------
    ### Draw center lines
    
    daVinci.drawLine(grid, grid+(height/2), grid+width, grid+(height/2)) ### H
    daVinci.drawLine(grid+(width/2), grid, grid+(width/2), grid+height)  ### V

//  See "FINISHED: |"+ DrawType +"| "+ $count + nl
    win1.setwindowtitle("FINISHED - Use MOUSE to Select Area to Zoom In ")
    
    DrawUpdate()

    sleep(0.02)  // Slow down the animation for better viewing

    ###===========================
    ### ZOOM IN

    minI = number( lineEdit1.text() ) 
    maxI = number( lineEdit2.text() )   
    minR = number( lineEdit3.text() )
    maxR = number( lineEdit4.text() )
    

    minI +=   zoomInc  // -0.0001 = 1000 | 0.0005 = 200
    maxI += - zoomInc
    minR +=   zoomInc
    maxR += - zoomInc  
    
    lineEdit1.setText(""+minI) 
    lineEdit2.setText(""+maxI) 
    lineEdit3.setText(""+minR) 
    lineEdit4.setText(""+maxR) 

    if DrawType = "DrawPoint"  
       exit  // 1 loop
    ok   
	
	// FIX bug where Image Shrinks and then Grows
	if minI >= maxI  or      
       minR >= MaxR
	   See "Exit Image: MinI >= MaxI  minR >= MaxR"+nl
	   exit         // Exit or Imge will reverge and Grow 
	ok   
	
  next
  
  ###===========================
  ### Reset Mouse Select Area  
  
  DrawMouseType = "ResetMouseArea"+nl
  //See "DrawMouseType: Reset: "+ DrawMouseType +nl

return

###===================================================
###===================================================
###===================================================

###--------------------------------------------------------------------

Func pPress
    
    nX = myfilter.getx() -8         ### Screen coordinate, Canvas = myfilter.globalx()
    nY = myfilter.gety() -8 -30     ### Screen coordinate, NOT Canvas
    
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
    
    // DropDown OverRide
    DrawMouseType = "SelectArea"
    See "DrawMouseType: Release: "+DrawMouseType +nl 
    
    
// NEW MIn MAX Values selected by Mouse Release
// MouseRelease: Call  CalculateZoom
//  newMinI:-1.043380000000 newMinR:-0.169625625000
//  newMaxI:-1.040231875000 newMaxR:-0.166477500000
    
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
    
    See "Mouse Selected Area" +nl
    See " newMinI:"+ newMinI +" newMinR:"+ newMinR +nl 
    See " newMaxI:"+ newMaxI +" newMaxR:"+ newMaxR +nl
    See nl+nl
    
    
    ### Put values in edit box on bottom of screen 
    lineEdit1.setText(""+ newMinI)  
    lineEdit2.setText(""+ newMaxI)
    lineEdit3.setText(""+ newMinR)
    lineEdit4.setText(""+ newMaxR)
    
    
return

###-----------------------------------------
Func ReadMinMaxPoints()

        minI = number( lineEdit1.text() )   
        maxI = number( lineEdit2.text() )
        minR = number( lineEdit3.text() )
        maxR = number( lineEdit4.text() )
        
return

###-----------------------------------------
### Mounir

Func SaveImage
    timeList = timeList()
    filename = "mandelbrot_" + timeList[11] + "_" + timeList[2] + timeList[4] + timeList[6] + ".png"  
	
	// date_year_hour_min
    MonaLisa.save(filename, "PNG", 100)
    win1.setWindowTitle("Image saved to " + filename)
return

###-----------------------------------------
### SAVE IMAGE DIALOG - png, jpg

Func pSaveAsFile()

   new qFileDialog(win1) 
   {    
        cFileName = getsavefilename(win1,"SaveAs", ".",
                              "source files(*.jpg | *.png ")
                              
        if cFileName
            fileType = Right(cFileName,4)          
            See "SaveAs ImageFile: "+ cFileName +nl 
    
            //--------------------------
          
            if fileType = ".jpg"
				MonaLisa.save(cFileName, "JPG", 100)
                win1.setWindowTitle("Image saved to " + cFileName)
				       
            elseif fileType = ".png"
				MonaLisa.save(cFileName, "PNG", 100)
                win1.setWindowTitle("Image saved to " + cFileName)
                    
            ok   
        ok          
    }

return

//===================================

Func ResetView
    lineEdit1.setText("-2.00")
    lineEdit2.setText("2.00")
    lineEdit3.setText("-2.00")
    lineEdit4.setText("2.00")
    lineEdit5.setText("50")
    comboCalc.setCurrentIndex(0)  // "DrawPoint"
    DrawType = "DrawPoint"
    Draw()
return

###-----------------------------------------
