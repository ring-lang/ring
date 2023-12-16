//
// Authors: Bert Mariani & Ilir Liburn 
// Added some UI/Performance improvements by Mahmoud Fayed
//

load "stdlibcore.ring"
load "lightguilib.ring"
load "stbimage.ring"           // Extract Image to RBG
load "fastpro.ring"            // Contains updateBytesColumn() functions 

xPos           = 100           ### Canvas position on Screen 
yPos           = 100           ### Window Moved: xPos: 107 yPos: 99  --- Screen getx: 0 gety:  0

xWidth         = 1400          ### Canvas size on Screen
yHeight        = 800 

imageStock     = NULL          // Default image-picture

imageOffsetX   = 1             // image position displayed on screen
imageOffsetY   = 40

colorBlue      = new QColor() { setRGB(000,000,255,255) }
colorBlack     = new QColor() { setRGB(000,000,000,255) }
penBlue        = new QPen()   { setColor(colorBlue)   setWidth(1) }
 
MCOrig         = NULL          

FilePicked     = " "           // From FileOpen()

oPixMap        = NULL          // Used for storing the selected image
cImageData     = ""            // Image Bytes
nImageWidth    = 0
nImageHeight   = 0
nImageChannels = 0

RVALUE         = 1
GVALUE         = 2
BVALUE         = 3
AVALUE         = 4

MCImage        = NULL
cNewData       = NULL

//============================================================

myApp = new QApp 
{
    win = new QWidget()
    {
        setWindowTitle("Image Pixel")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size
        setStyleSheet("background-color: white")
        setWinIcon(self,"resources/colors.png")
        
        
        myfilter = new QAllevents(win)
       
            ###------------------------------------------
            ### ReSizeEvent ... Call WhereAreWe function

            myfilter.setResizeEvent( "WhereAreWe()")   // Find Window position
            myfilter.setMoveEvent(   "WhereMoved()")   // Find Window position  
    
        installEventFilter(myfilter)    

        //------------------------------

        oScroll = new QScrollArea(win) {
            move(0,0)
            resize(xWidth,yHeight-40)
            Canvas = new QLabel(win)
            {
                ### daVinci paints the MonaLisa on the Canvas
                MonaLisa  = new QPixMap2( 6000, 6000)
                    color = new QColor(){ setrgb(255,255,255,0) }
                      pen = new QPen()  { setwidth(1) } 

                daVinci = new QPainter()
                {
                   begin(MonaLisa)
                }
            
                setPixMap(MonaLisa)
            
                ### Change Pen Color
                daVinci.setPen(penBlue)  
            }
            setWidget(Canvas)
        }
                          
        //===================================================
            

        label1 = new Qlabel(win)
        {   setgeometry(01, 21, 195, 12)
            settext(" ")                                 // Image File opened goes here
        }
        
        btnOpenFile =  new QPushButton(win) {
                    setGeometry(001,01,95,20)
                    setText("Open file")
                    setStyleSheet("background-color: aqua")
                    setClickEvent("pOpenFile()")
        }  

        btnSaveAsFile =  new QPushButton(win) {
                    setGeometry(100,01,95,20)
                    setText("SaveAs file")
                    setStyleSheet("background-color: aqua")
                    setClickEvent("pSaveAsFile()")
        }       

        label2 = new QLabel(win)
        {   setGeometry(200, 21, 95, 12)
            setText(" ")                                 // "Working ...." "Fin .."
        }               
 
        btnChangeColors = new QPushButton(win) { 
            setGeometry(201,01,95,20)  
            setText("Change Colors")  
            setStyleSheet("background-color: aqua")
            setClickEvent("ChangeColorValue()") 
            setEnabled(False)
        }     
        

        eCheckGrayScale  =  new QCheckBox(win)  { 
            setCheckState(2) 
            setGeometry( 700, 01 , 80, 20) 
            settext("GrayScale") setStyleSheet("background-color: yellow")
        }         

        eCheckColorize   =  new QCheckBox(win)  { 
            setGeometry( 800, 01 , 80, 20) 
            setText("Colorize")  setStyleSheet("background-color: yellow")
        }         
 
                  
        //-------------------------------------------------

         lRed   =  new QLabel(win)     { setGeometry(300, 01 , 40, 20)  setText(" Red:")
                                         setStyleSheet("background-color: yellow") }

         eRed   =  new QLineEdit(win)  { setGeometry(340, 01 , 50, 20)  setText("100") }           
               
         lGreen =  new QLabel(win)     { setGeometry(400, 01 , 40, 20)  setText(" Green:")
                                         setStyleSheet("background-color: yellow")}

         eGreen =  new QLineEdit(win)  { setGeometry(440, 01 , 50, 20)  setText("100") }
            
         lBlue  =  new QLabel(win)     { setGeometry(500, 01 , 40, 20)  setText(" Blue:") 
                                         setStyleSheet("background-color: yellow")}

         eBlue  =  new QLineEdit(win)  { setGeometry(540, 01 , 50, 20)  setText("100") }           

         lAlpha =  new QLabel(win)     { setGeometry(600, 01 , 40, 20)  setText(" Alpha:") 
                                         setStyleSheet("background-color: yellow")}

         eAlpha =  new QLineEdit(win)  { setGeometry(640, 01 , 50, 20)  setText("100") }           

         // Set SCALE SLIDER VALUE to MAX 200, slider to pos 50  value to 100
         sRed   =  new QSlider(win)    { setGeometry(300, 22 , 90, 10)  setOrientation(Qt_Horizontal) 
                                         setValue(200)  setValueChangedEvent("changeRed()")
                                         setSliderPosition(50) }
      
         sGreen =  new QSlider(win)    { setGeometry(400, 22 , 90, 10)  setOrientation(Qt_Horizontal)
                                         setValue(200)  setValueChangedEvent("changeGreen()")
                                         setSliderPosition(50) }     
 
         sBlue  =  new QSlider(win)    { setGeometry(500, 22 , 90, 10)  setOrientation(Qt_Horizontal)
                                         setValue(200)  setValueChangedEvent("changeBlue()")
                                         setSliderPosition(50) }
      
         sAlpha =  new QSlider(win)    { setGeometry(600, 21 , 90, 10)  setOrientation(Qt_Horizontal)
                                         setValue(100)  setValueChangedEvent("changeAlpha()")
                                         setSliderPosition(100) }      
                          
        show()

    }
    
    exec()
}

###==========================================================================
// Max 100/10 = 10 

Func   changeRed()  nbr = floor(  sRed.value() / 0.5)      eRed.setText(""+nbr)    return       
Func changeGreen()  nbr = floor(sGreen.value() / 0.5)    eGreen.setText(""+nbr)    return       
Func  changeBlue()  nbr = floor( sBlue.value() / 0.5)     eBlue.setText(""+nbr)    return       
Func changeAlpha()  nbr = floor(sAlpha.value() / 1.0)    eAlpha.setText(""+nbr)    return       

//===============================================================================

Func pOpenFile()

    new QFileDialog(win) {
         FilePicked = getopenfilename(win,"Open file", ".",
                                      "source files(*.jpg | *.png | *.bmp | *.gif)" )
    }
        
    if FilePicked 
        See"Open ImageFile: "+ FilePicked +nl
        chdir(JustFilePath(FilePicked))
            label1.setText(JustFileName(FilePicked))    // Save Name for loading image later
        btnChangeColors.setEnabled(False)
        btnOpenFile.setEnabled(False)
        
            getImagePixels()                            // Display Image
            
        btnChangeColors.setEnabled(True)
        btnOpenFile.setEnabled(True)
    ok
        
return 

//==========================================================================================
//
// int stbi_write_jpg(char const *filename, int w, int h, int comp, const void *data, int quality)
// int stbi_write_png(char const *filename, int w, int h, int comp, const void *data, int stride_in_bytes)
// int stbi_write_bmp(char const *filename, int w, int h, int comp, const void *data)
// int stbi_write_tga(char const *filename, int w, int h, int comp, const void *data)
//
//-----------------------

Func pSaveAsFile()

   new qFileDialog(win) 
   {	
        cFileName = getsavefilename(win,"SaveAs", ".",
                              "source files(*.jpg | *.png | *.bmp | *.gif | *.tga)")
                              
        if cFileName
            fileType = Right(cFileName,4)          
            See "SaveAs ImageFile: "+ cFileName +nl	
	
			//--------------------------
          
            if fileType = ".jpg"
                stbi_write_jpg(cFileName, nImageWidth, nImageHeight, nImageChannels, MCOrig, 100)   // 100 = Quality
          
            elseif fileType = ".png"
                stbi_write_png(cFileName, nImageWidth, nImageHeight, nImageChannels, MCOrig, nImageWidth * nImageChannels) // Stride_in_bytes
          
            elseif fileType = ".bmp"
                stbi_write_bmp(cFileName, nImageWidth, nImageHeight, nImageChannels, MCOrig)    
             
            elseif fileType = ".tga"
                stbi_write_tga(cFileName, nImageWidth, nImageHeight, nImageChannels, MCOrig)
          
            elseif fileType = ".gif"
                stbi_write_png(cFileName, nImageWidth, nImageHeight, nImageChannels, MCOrig, nImageWidth * nImageChannels)
            ok   
        ok          
    }

return

//===============================================================================
// Read Image from Window, Extract the colors
//===============================================================================                                                              


Func GetImagePixels()

    label2.setText(" Reading ...")

    DisplayImage = FilePicked                       // Image file opened and choosen
      

        imageStock = new qlabel(win)                                        // Place at top center of screen
        {   
            oPixMap = new qPixMap(DisplayImage )                            // Pixel 1x1 black dot       
            setpixmap(oPixMap.scaled(oPixMap.Width() , 
                      oPixMap.Height(), 0, 0))         // Display picture. Size-H, Siz-V, Aspect, Transform
            
            PosLeft =  1 
            PosTop  =  imageOffsetY        
        // Slider value changed for color value                             // From Top
            setGeometry(PosLeft,PosTop,oPixMap.Width(),oPixMap.Height())        // Position Display 
        } 
    
    See "Image W-H: "+ oPixMap.Width() +"-"+ oPixMap.Height() +
        " Size: "+ (oPixMap.Width() * oPixMap.Height()) + nl

    MonaLisa.fill(colorBlack)                               // ===<<< BLANK OUT OLD IMAGE !!!
    daVinci.drawPixMap(imageOffsetX,imageOffsetY,oPixMap)        
    Canvas.setPixMap(MonaLisa)                              ### Need this setPixMap to display imageLabel               

   #=====================================================================#
   // See "GetPixelColors.....: "
   t1 = clock()
   #=====================================================================#
   
           offSetX = imageStock.Width() +10
           offSetY = 40
                 
   //---------------------------------------------------------------------
      
   ExtractImageRGB(DisplayImage)   // Extract RGB to aList
  
   #=====================================================================#
   t3 = clock()
   See "GetPixelColors.....:   Total Time: " +
       ( (t3-t1)/ClocksPerSecond() ) + " seconds " + nl
   #=====================================================================#  
          
   label2.setText(" Fin ...")
    
return




//================================================================
//================================================================
                
Func ChangeColorValue()

    btnOpenFile.setEnabled(False)
    btnChangeColors.setEnabled(False)
    label2.setText(" Changing Colors")
    win.repaint()
  
    MCOrig = cImageData
    if MCOrig = NULL                        // Fails on GIF ,Does NotExist ,  Image W-H: 0-0 Size: 0
        label2.setText(" Fail ....")
        btnOpenFile.setEnabled(True)
        btnChangeColors.setEnabled(True)
       return
    ok
  
    offSetX = imageStock.Width() +10     // Double Width Position
    offSetY = 40

    #=====================================================================#
    See "Change-ColorValue..: "
    t1 = clock()
    #=====================================================================#

    Red   = eRed.Text()
    Green = eGreen.Text()
    Blue  = eBlue.Text()
    Alpha = eAlpha.Text()
     
    //-----------------------------------------------------
    // Change RGBA to FRACTION of Original as per Slider
    
    nNewRed   = Red   / 100
    nNewGreen = Green / 100
    nNewBlue  = Blue  / 100
    nNewAlpha = Alpha / 100   

    lColorize = (eCheckColorize.isChecked()  = 1 ) 
    lGray     = (eCheckGrayScale.isChecked() = 1 )   

    //====================================================================
    // FRACTION of COLOR of ORIGINAL -- Display Color RBG 

    MCOrig = updateBytesColumn(MCOrig,nImageChannels,nImageWidth*nImageHeight,255,
                        :mul,RVALUE,nNewRed,          # R *= nNewRed
                        :mul,GVALUE,nNewGreen,        # G *= nNewGreen
                        :mul,BVALUE,nNewBlue)         # B *= nNewBlue

    if nImageChannels=4             // OR  nImageChannels=3   // Alpha Intensity
    MCOrig = updateBytesColumn(
            MCOrig,nImageChannels,
            nImageWidth*nImageHeight,255,
            :mul,AVALUE,nNewAlpha)
    ok

    //====================================================================
    // COLORIZE-- Display GrayScale Image in Color 
    // Color corrected is for eye sensitivity Red 30%, Green 59% Blue 11%.
    // Reverse Gray to RGB   1/0.3 R   1/0.59 G  1/0.11 B.  Max value 255
    
    if lColorize

        nRedUpdate   = 1.2419 * 1.4 * nNewRed   
        nGreenUpdate = 1.1232 * 0.8 * nNewGreen
        nBlueUpdate  = 1.6347 * 0.5 * nNewBlue   

        MCOrig = updateBytesColumn(MCOrig,nImageChannels,nImageWidth*nImageHeight,255,
                            :copy,RVALUE,GVALUE,          # G  = R
                            :copy,RVALUE,BVALUE,          # B  = R
                             :mul,RVALUE,nRedUpdate,      # R *= nRedUpdate
                             :mul,GVALUE,nGreenUpdate,    # G *= nGreenUpdate
                             :mul,BVALUE,nBlueUpdate)     # B *= nBlueUpdate

    //====================================================================
    // GRAY SCALE -- Display Color RBG in GRAY Scale  
    // Average looks better brighter than Gamma Corrected
    // Color corrected is for eye sensitivity Red 30%, Green 59% Blue 11%.
        
    elseif lGray  
           
        MCOrig = updateBytesColumn(MCOrig,nImageChannels,nImageWidth*nImageHeight,255,
                              :mul,RVALUE,0.3,             # R *= 0.3
                              :mul,GVALUE,0.59,            # G *= 0.59
                              :mul,BVALUE,0.11,            # B *= 0.11
                            :merge,RVALUE,GVALUE,          # R += G
                            :merge,RVALUE,BVALUE,          # R += B
                             :copy,RVALUE,GVALUE,          # G  = R
                             :copy,RVALUE,BVALUE)          # B  = R

    ok

			
    #=====================================================================#
    t3 = clock()
    See "  Total Time: " + ( (t3-t1)/ClocksPerSecond() ) + " seconds " +nl
    #=====================================================================# 

    //----------------------------
    // Draw UPDATED IMAGE Change Color

    MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
  
    if Alpha < 255                         // Alpha Intensity overlays Image, need to blank it out first
      // RE-DRAWD Orig First (with offsets) - Side by Side
      davinci.drawPixmap(imageOffsetX,imageOffsetY,oPixMap) 
    ok
    
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
  
    // MCOrig as per FRACTION of SLIDER Values
    DrawRGBAImagePixels(MCOrig,imageOffsetX+imageStock.Width()+10,imageOffsetY,nNewAlpha)  

    label2.setText(" Fin ....")
    btnOpenFile.setEnabled(True)
    btnChangeColors.setEnabled(True)
    
return

//====================================================

Func DrawRGBAImagePixels(MCImage,nXStart,nYStart,nNewAlpha)
 
   #=====================================================================#
   See "DrawRBGAImagePixels: "
   t1 = clock()
   #=====================================================================#
   
   daVinci.drawBytes(nXStart,nYStart,MCImage,nImageWidth,nImageHeight,nImageChannels)    

   Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               

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

    oScroll.resize(WinWidth,WinHeight-40)

return

###=========================================================
###=========================================================
### Window Moved
### Window Moved: xPos: 99 yPos: 98
### Window Resize   LT 107-99: 

Func WhereMoved()

    xPos = win.x() //  +8     ### <<< QT FIX because of Win Title
    yPos = win.y() +30        ### <<< QT FIX because of Win Title

    fX = myfilter.getx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.gety()
    
return


###=====================================================================================================
### ImageFile = PictureFL = "Flower.png"
//  ring/extensions/ringstbimage/stbimage.cf 
//  ring/samples/UsingStbImage/test3.ring
//--------------------------------------------

Func ExtractImageRGB(ImageFile)

   # Image Information
   nImageWidth=0 nImageHeight=0 nImageChannels=0
    
   stbi_info(ImageFile,:nImageWidth,:nImageHeight,:nImageChannels)

   # Ring will Free cImageData automatically in the end of the program
   if nImageChannels = 3
       cImageData = stbi_load(ImageFile,:nImageWidth,:nImageHeight,:nImageChannels,STBI_rgb)
   else
       cImageData = stbi_load(ImageFile,:nImageWidth,:nImageHeight,:nImageChannels,STBI_rgb_alpha)
   ok
    
   # Display the output
   ? "Size (bytes): " + len(cImageData)
   ? "Width : "       + nImageWidth
   ? "Height: "       + nImageHeight
   ? "Channels: "     + nImageChannels

   if nImageChannels = 3
	cImageData = addBytesColumn(cImageData,nImageChannels,nImageWidth*nImageHeight)
	nImageChannels = 4
   ok
    

return  

//============================================
