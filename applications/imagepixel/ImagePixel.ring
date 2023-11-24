//
// Authors: Bert Mariani, Ilir Liburn 
//
// Steps
// (1) Get Screen Shot ---> Image
// (2) Get the pixel color from the Image
// 
// Example : https://github.com/ring-lang/ring/blob/337eb96ac082bed25ce0c9cfe4dfc25847bddf70/samples/other/pixelcolor.ring
//

load "stdlibcore.ring"
load "lightguilib.ring"
load "stbimage.ring"        // Extract Image to RBG

xPos    = 100           ### Canvas position on Screen 
yPos    = 100           ### Window Moved: xPos: 107 yPos: 99  --- Screen getx: 0 gety:  0

xWidth  = 1400          ### Canvas size on Screen
yHeight = 800 

imageStock  = null      // Default image-picture
ImageScale  = 1         // Divide by 4 to reduce image size 


imageOffsetX = 1        // image position displayed on screen
imageOffsetY = 40

colorBlue  = new qcolor() { setrgb(000,000,255,255) }
colorBlack = new qcolor() { setrgb(000,000,000,255) }
penBlue    = new qpen()   { setcolor(colorBlue)   setwidth(1) }
 
MCOrig  = list(10)  // Linear List 1   => 1D list(60000)
MCRgbA  = list(10)  // Linear List 1   => 1D list(60000)

FilePicked = " "    // From FileOpen()

//============================================================

 myApp = new qApp 
 {
    win = new qWidget()
    {
        setWindowTitle("Get Pixel Color")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size
        setStyleSheet("background-color: white")
        
        
        myfilter = new qallevents(win)
       
            ###------------------------------------------
            ### ReSizeEvent ... Call WhereAreWe function

            myfilter.setResizeEvent( "WhereAreWe()")   // Find Window position
            myfilter.setMoveEvent(   "WhereMoved()")   // Find Window position  
    
        installeventfilter(myfilter)    

        //------------------------------

        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( 2000, 2000)
                color = new qcolor(){ setrgb(255,255,255,0) }
                  pen = new qpen()  { setwidth(1) } 

            daVinci = new qpainter()
            {
               begin(MonaLisa)
            }
            
            setPixMap(MonaLisa)
            
            ### Change Pen Color
            daVinci.setpen(penBlue)  
        }
                    

        
        //===================================================
            

        label1 = new qlabel(win)
        {   setgeometry(01, 21, 195, 12)
            settext(" ")                                 // Image File opened goes here
        }
        
        btn3 =  new qPushButton(win) {
                    setGeometry(001,01,95,20)
                    setText("Open file")
                    setStyleSheet("background-color: aqua")
                    setclickevent("pOpenFile()")
        }       

        label2 = new qlabel(win)
        {   setgeometry(200, 21, 95, 12)
            settext(" ")                                 // "Working ...." "Fin .."
        }               
 
        btn1 = new qPushButton(win) { 
                setGeometry(101,01,95,20)  
                setText("GetImagePixels")  
                setStyleSheet("background-color: aqua")
                setClickEvent("GetImagePixels()") 
        }
  

  
        btn2 = new qPushButton(win) { 
                setGeometry(201,01,95,20)  
                setText("ChangeColorValues")  
                setStyleSheet("background-color: aqua")
                setClickEvent("ChangeColorValue()") 
        }     
        

        eCheckGrayScale  =  new qCheckBox(win)  { setgeometry( 700, 01 , 80, 20) settext("GrayScale") setStyleSheet("background-color: yellow")}         
        eCheckColorize   =  new qCheckBox(win)  { setgeometry( 800, 01 , 80, 20) settext("Colorize")  setStyleSheet("background-color: yellow")}         
 
        

            
        //-------------------------------------------------

         lRed   =  new qLabel(win)     { setgeometry(300, 01 , 40, 20)  settext(" Red:")   setStyleSheet("background-color: yellow")}
         eRed   =  new qlineedit(win)  { setgeometry(340, 01 , 50, 20)  settext("100") }           
               
         lGreen =  new qLabel(win)     { setgeometry(400, 01 , 40, 20)  settext(" Green:") setStyleSheet("background-color: yellow")}
         eGreen =  new qlineedit(win)  { setgeometry(440, 01 , 50, 20)  settext("100") }
            
         lBlue  =  new qLabel(win)     { setgeometry(500, 01 , 40, 20)  settext(" Blue:")  setStyleSheet("background-color: yellow")}
         eBlue  =  new qlineedit(win)  { setgeometry(540, 01 , 50, 20)  settext("100") }           

         lAlpha =  new qLabel(win)     { setgeometry(600, 01 , 40, 20)  settext(" Alpha:") setStyleSheet("background-color: yellow")}
         eAlpha =  new qlineedit(win)  { setgeometry(640, 01 , 50, 20)  settext("100") }           

         // Set SCALE SLIDER VALUE to MAX 200, slider to pos 50  value to 100
         sRed   =  new qslider(win)    { setGeometry(300, 22 , 90, 10)  setOrientation(Qt_Horizontal)  setValue(200)  setValueChangedEvent("changeRed()")   setSliderPosition(50)}      
         sGreen =  new qslider(win)    { setGeometry(400, 22 , 90, 10)  setOrientation(Qt_Horizontal)  setValue(200)  setValueChangedEvent("changeGreen()") setSliderPosition(50) }      
         sBlue  =  new qslider(win)    { setGeometry(500, 22 , 90, 10)  setOrientation(Qt_Horizontal)  setValue(200)  setValueChangedEvent("changeBlue()")  setSliderPosition(50)}      
         sAlpha =  new qslider(win)    { setGeometry(600, 21 , 90, 10)  setOrientation(Qt_Horizontal)  setValue(100)  setValueChangedEvent("changeAlpha()") setSliderPosition(100)}      
            
                          
        show()
    }
    
    exec()
}

###==========================================================================
// Max 100/10 = 10 

Func   changeRed()  nbr = floor(  sRed.value() / 0.5)      eRed.setText(""+nbr)    return       // 100 / 0.38824   => 0- 255
Func changeGreen()  nbr = floor(sGreen.value() / 0.5)    eGreen.setText(""+nbr)    return       // 100 / 2         => 0-  50
Func  changeBlue()  nbr = floor( sBlue.value() / 0.5)     eBlue.setText(""+nbr)    return       // 100 / 255       => 0-   0.4
Func changeAlpha()  nbr = floor(sAlpha.value() / 1.0)    eAlpha.setText(""+nbr)    return       // Alpha Max = 1.0       => 0-   2


//===============================================================================

Func pOpenFile()
        new qfiledialog(win) {
             cName = getopenfilename(win,"Open file", ".", "source files(*.jpg | *.png | *.bmp | *.gif)" )
             FilePicked = cName
        }
        
        label1.setText(FilePicked)    // Save Name for loading image later
        
        GetImagePixels()              // Display Image
        
return 

//===============================================================================
// Read Image from Window, Extract the colors
//                                 -----                                 


Func GetImagePixels()

    label2.setText(" Reading ...")

    DisplayImage = FilePicked                       // Image file opened and choosen
      

        imageStock = new qlabel(win)                                        // Place at top center of screen
        {   image = new qPixMap(DisplayImage )                              // Pixel 1x1 black dot       
            setpixmap(image.scaled(image.Width() , image.Height(), 0, 0))   // Display picture. Size-H, Siz-V, Aspect, Transform
            
            PosLeft =  1 
            PosTop  =  imageOffsetY        
	    // Slider value changed for color value                                 // From Top
            setGeometry(PosLeft,PosTop,image.Width(),image.Height())        // Position Display 
        } 
    
    See "Image W-H: "+ image.Width() +"-"+ image.Height() +" Size: "+ (image.Width() * image.Height()) +nl


   #=====================================================================#
   // See "GetPixelColors.....: "
   t1 = clock()
   #=====================================================================#
   
   
           offSetX = imageStock.Width() +10
           offSetY = 40
           
           pixmap = image
           image  = pixmap.toimage()
       

    //-------------------------------
      
    MCOrig = ExtractImageRGB(DisplayImage)   // Extract RGB to aList
  
   #=====================================================================#
   t3 = clock()
   See "GetPixelColors.....:   Total Time: " + ( (t3-t1)/ClocksPerSecond() ) + " seconds " +nl
   #=====================================================================#  
      
    //--------------------------------------------------------------------
    // Draw Original ONCE in TopLeft 1-40 - Black Out background first
    
    MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### EXEC the Draw
       
    DrawRGBAImagePixels(MCOrig,imageOffsetX,imageOffsetY)        // Draw ORIGINAL First - Side by Side  
    
    label2.setText(" Fin ...")
    
return

//================================================================
//================================================================
// daVinci.drawHSVFList(aList)          
// daVinci.drawRGBFList(MCRgbA)    Format x,y, 0.0-1.0 for rgba
// MCOrig[k] = [x, y, R, G, B, A]
// MCRgbA[k] =  x=410 y=338 r=0.78  g=0.66 b=0.44 b  a=1 
// These weights are: 0.2989, 0.5870, 0.1140.
// Gamma Corrected: TotalGray = ((MCRgbA[i][3] * 0.2989) +  (MCRgbA[i][4] * 0.5870) + (MCRgbA[i][5] * 0.1140)) / 3 
//--------------------------------------------                                
                
Func ChangeColorValue()

    if !MCOrig                          // Fails on GIF ,Does NotExist ,  Image W-H: 0-0 Size: 0
       return
    ok
  
    if MCOrig[1] = 0                    // Read Image NOT DONE yet.
       return
    ok

    label2.setText(" Changing Colors")
       
    offSetX = imageStock.Width() +10     // Double Width Position
    offSetY = 40

   #=====================================================================#
   See "Change-ColorValue..: "
   t1 = clock()
   #=====================================================================#

   MCRgbA  = MCOrig          // Do Not modify original
   MCOrigF = MCOrig          // Original in 0.0 -1 ,0 format
  
   Red   = eRed.Text()
   Green = eGreen.Text()
   Blue  = eBlue.Text()
   Alpha = eAlpha.Text()
     
   //-----------------------------------------------------
   // Change RGBA to FRACTION of Original as per Slider
   
 
      
 
    for i = 1 to len( MCRgbA)
       
       //====================================================================
       // FRACTION of COLOR of ORIGINAL -- Display Color RBG 
                                 
       MCRgbA[i][3] = MCOrig[i][3]  * (Red   / 100 )   //  Slider : Fraction of Color   00  100  200
       MCRgbA[i][4] = MCOrig[i][4]  * (Green / 100 )
       MCRgbA[i][5] = MCOrig[i][5]  * (Blue  / 100 )
       MCRgbA[i][6] = MCOrig[i][6]  * (Alpha / 100 )  // Alpha Max 1.0
   
        //====================================================================
        // GRAY SCALE -- Display Color RBG in GRAY Scale  
        // Average looks better brighter than Gamma Corrected
        // Color corrected is for eye sensitivity Red 30%, Green 59% Blue 11%.
        
        if (eCheckGrayScale.isChecked() = 1 )   
              
           AvgGray = ( (0.3 * MCRgbA[i][3]) + (0.59 * MCRgbA[i][4]) + (0.11 * MCRgbA[i][5]) )  // Color Corrected
           
           MCRgbA[i][3] = AvgGray        // RGB set to Same Value => Gray shadeed
           MCRgbA[i][4] = AvgGray
           MCRgbA[i][5] = AvgGray
        ok 
        
        //====================================================================
        // COLORIZE-- Display GrayScale Image in Color 
        // Color corrected is for eye sensitivity Red 30%, Green 59% Blue 11%.
        // Reverse Gray to RGB   1/0.3 R   1/0.59 G  1/0.11 B.  Max value 255
        
        if (eCheckColorize.isChecked() = 1 ) 
        
          AvgGray = MCRgbA[i][3]                       //   Corrected   Reverse       13.819   %Total                                                      
             RC = AvgGray  * 1.2419 * 1.4 * (Red   / 100 )        //   RC = 1 / 0.299    => 3.344    0.2419        
             GC = AvgGray  * 1.1232 * 0.8 * (Green / 100 )        //   GC = 1 / 0.587       1.703    0.1232          
             BC = AvgGray  * 1.6347 * 0.5 * (Blue  / 100 )        //   BC = 1 / 0.114       8.772    0.6347   

            MCRgbA[i][3] = RC
            MCRgbA[i][4] = GC
            MCRgbA[i][5] = BC       

        ok
        
        
    next    

    #=====================================================================#
    t3 = clock()
    See "  Total Time: " + ( (t3-t1)/ClocksPerSecond() ) + " seconds " +nl
    #=====================================================================# 

    //----------------------------
    // Draw UPDATED IMAGE Change Color
    
    if Alpha < 255                         // Alpha Intensity overlays Image, need to blank it out first
       MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
       DrawRGBAImagePixels(MCOrig,imageOffsetX,imageOffsetY)         // RE-DRAWD Orig First (with offsets) - Side by Side
           Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    ok
    
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### EXEC the Draw   
  
    DrawRGBAImagePixels(MCRgbA,imageOffsetX+imageStock.Width()+10,imageOffsetY)         // MCRgbA as per FRACTION of SLIDER Values

    label2.setText(" Fin ....")
    
return

//====================================================

Func DrawRGBAImagePixels(MCImage,nXStart,nYStart)

    
   #=====================================================================#
   See "DrawRBGAImagePixels: "
   t1 = clock()
   #=====================================================================#
   
    daVinci.drawRGBFListAtXY(MCImage,nXStart,nYStart)        // <<<=== DOUBLE OFFSET,i=400,  MCImage Linear List (60000) = list[i,j,R,G,B,V)
    
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### EXEC the Draw

   #=====================================================================#
   t3 = clock()
   See "  Total Time: " + ( (t3-t1)/ClocksPerSecond() ) + " seconds " +nl+nl
   #=====================================================================#  

return


###=========================================================
###=========================================================
###-----------------------------------------
### FUNCTION Where Are We - Window Resized
### Window Moved: xPos: 99 yPos: 98
### Window Resize   LT 107-99: 
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

###=========================================================
###=========================================================
### Window Moved
### Window Moved: xPos: 99 yPos: 98
### Window Resize   LT 107-99: 

Func WhereMoved()

    xPos = win.x() //  +8     ### <<< QT FIX because of Win Title
    yPos = win.y() +30        ### <<< QT FIX because of Win Title

    win{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }  

    fX = myfilter.getx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.gety()
    
return


###=====================================================================================================
### ImageFile = PictureBD = "BlackDot1.png"
//              PicturePG = "PotatoGirl.png"
//              PictureFL = "Flower.png"
//              PictureAG = "AfghanGirl.png"
//              PictureTI = "Tiger.png"
//              PictureTIJ = "Tiger.jpg"
//              PictureBF = "Butterfly.png"
//
//  ring/extensions/ringstbimage/stbimage.cf 
//  ring/samples/UsingStbImage/test3.ring
//--------------------------------------------

Func ExtractImageRGB(ImageFile)

   # Image Information
    width=0 height=0 channels=0
    
    stbi_info(ImageFile,:width,:height,:channels)

   # Ring will Free cData automatically in the end of the program
    if channels = 3
        cData = stbi_load(ImageFile,:width,:height,:channels,STBI_rgb)
    else
        cData = stbi_load(ImageFile,:width,:height,:channels,STBI_rgb_alpha)
    ok
    
   # Display the output
    ? "Size (bytes): " + len(cData)
    ? "Width : " + width
    ? "Height: " + height
    ? "Channels: " + channels
    
   # Convert to [x,y,r,g,b] List

    if channels = 3
        aList = STBI_Bytes2List(cData,width,height)
    else
        size = len(cData)
        cData2 = ""
        for i = 1 to size step 4
            cdata2 += cData[i]
            cdata2 += cData[i+1]
            cdata2 += cData[i+2]
        next
        aList = STBI_Bytes2List(cData2,width,height)
    ok

    for aPoint in aList
        aPoint[3] /= 255
        aPoint[4] /= 255
        aPoint[5] /= 255
    next
    
return aList

//============================================
