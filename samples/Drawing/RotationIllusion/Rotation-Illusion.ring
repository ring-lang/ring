### Rotation-Illusion
### 8 Balls moving in Straingh Lines a Clock Direction
### Bert Mariani 2025-02-10
###
### Circle or straight line? You be the judge!
### The dots’ velocity is sinusoidal,and
### each dot’s period is offset by pi/n of the dots on the lines adjacent to it. 
### Different velocity functions would produce different shapes ### if any shapes at all).
### 
### Cornicus Theorm:     
### If a small circle with a radious R2 is perfectly rolling 
### in a larger circlewiyj a radius of R,
### a Point on the smaller circle's circumference  racws 
### a Sraight Line Segment exactly Equak to the larger circl'e circumference
###
###=============================================================

load "stdlibcore.ring"
load "lightguilib.ring"

//================================================

decimals(6)  // 4
PI         = 3.14159265
Radius     = 300       // Size of Display

ImageScale = 4         // 4 Reduce Image by the Factor Scal
ImageSize  = Radius    // Size of Image PNG file || ImageC1.imageSize = image.width()

SleepDelay = 0.001     // 0.001
MoveInc    = 0.010     // 0.010
aShowBa    = [0,0,0,0,  0,0,0,0,  1,0,0,0,  1,0,0,0]   // Array=0  Ring=1  1..8   9..15


xPos    = 100        ### Canvas position on Screen
yPos    = 25
xWidth  = 1600       ### Canvas size on Screen
yHeight = 1000


// Need to define variable when using Func StartApp()
MonaLisa = null
daVinci  = null
Canvas   = null
myApp    = null



###-------------------------------
### Define Colours, Pens, Brushes

colorGreen   = new qcolor() { setrgb(000,255,000,128) }  ### faint
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ###  64 faint  line
colorWhite2  = new qcolor() { setrgb(255,255,255,255) }  ### 255 bright line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ###
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave
colorAqua    = new qcolor() { setrgb(000,255,255,255) }  ### 255 full

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(2) }  //
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(2) }
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(1) }
penWhite2   = new qpen() { setcolor(colorWhite2)  setwidth(2) }  //
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(1) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(1) }
penAqua     = new qpen() { setcolor(colorAqua)    setwidth(1) }
penBlue4    = new qpen() { setcolor(colorBlue)    setwidth(4) }  //

brushSR     = new qbrush() { setstyle(1)  setcolor (colorRed)}      ### Red
brushSG     = new qbrush() { setstyle(1)  setcolor (colorGreen)}    ### Green
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlue)}     ### Blue
brushSY     = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSGR    = new qbrush() { setstyle(1)  setcolor (colorGray)}     ###
brushSW     = new qbrush() { setstyle(1)  setcolor (colorWhite)}    ###
brushSM     = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  ###

brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty

//=========================================
// START the APP

 myApp = new qApp
 {
    win = new qWidget()
    {
        setWindowTitle("   Rotation Illusion")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        oFilter = new QAllevents(win)
        oFilter.setCloseEvent("myApp.Quit()")
        installeventfilter(oFilter)

        Canvas = new qlabel(win)
        {
            ### daVinci Paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)

            daVinci = new qpainter()
            {
               begin(MonaLisa)                       ### Canvas: xWidth=1800  yHeight=1000
               translate(xWidth/2 , yHeight/2)       ### TRANSLATE CO-ORD x,y 0,0 Maps Center OFFSET  TO 900,500
               //setCompositionMode(26)              ###  THIS is the MAGIC - Erase Old Line when Redrawn
               //endpaint()                          ### This will Stop the Painting

            }

            //================================================
            // IMAGES - red,black,blue,green,orange

            imageC1 = new qlabel(win)
            {
                image1 = new qPixMap("aRed.png")
                setpixmap( image1.scaled(image1.width()/ImageScale, image1.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image1.Width(), image1.Height())
                xPos = (xWidth  - image1.width()  ) / 2
                yPos = (yHeight - image1.height() ) / 2
                imageSize = image1.width()
            }


            imageC2 = new qlabel(win)
            {
                image2 = new qPixMap("aBlu.png")
                setpixmap( image2.scaled(image2.width()/ImageScale, image2.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image2.Width(), image2.Height())
            }

            imageC3 = new qlabel(win)
            {
                image3 = new qPixMap("aOra.png")
                setpixmap( image3.scaled(image3.width()/ImageScale, image3.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image3.Width(), image3.Height())
            }


            imageC4 = new qlabel(win)
            {
                image4 = new qPixMap("aGre.png")
                setpixmap( image4.scaled(image4.width()/ImageScale, image4.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image4.Width(), image4.Height())
            }

            //-----

              imageC5 = new qlabel(win)
            {
                image5 = new qPixMap("aRed.png")
                setpixmap( image5.scaled(image5.width()/ImageScale, image5.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image5.Width(), image5.Height())
            }

             imageC6 = new qlabel(win)
            {
                image6 = new qPixMap("aBlu.png")
                setpixmap( image6.scaled(image6.width()/ImageScale, image6.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image6.Width(), image6.Height())
            }

            imageC7 = new qlabel(win)
            {
                image7 = new qPixMap("aOra.png")
                setpixmap( image7.scaled(image7.width()/ImageScale, image7.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image7.Width(), image7.Height())
            }


            imageC8 = new qlabel(win)
            {
                image8 = new qPixMap("aGre.png")
                setpixmap( image8.scaled(image8.width()/ImageScale, image8.height()/ImageScale , 0, 0) )
                setGeometry( -900, -900, image8.Width(), image8.Height())
            }

            //-------------------------------
            setPixMap(MonaLisa)    // Draw It - Black
        }

        //======================================================
        //======================================================


        //==============================

        eCheckBal1s  =  new qCheckBox(win)  { setgeometry( 120, 2, 140, 20)
                            settext(" Show Balls") setStyleSheet("background-color: yellow")}

        eCheckBa1  =  new qCheckBox(win)  { setgeometry( 120, 24, 100, 20)
                          settext(" 1") setStyleSheet("background-color: yellow")}

        eCheckBa2  =  new qCheckBox(win)  { setgeometry( 120, 46, 100, 20)
                          settext(" 2") setStyleSheet("background-color: yellow")}

        eCheckBa3  =  new qCheckBox(win)  { setgeometry( 120, 68, 100, 20)
                          settext(" 3") setStyleSheet("background-color: yellow")}

        eCheckBa4  =  new qCheckBox(win)  { setgeometry( 120, 90, 100, 20)
                          settext(" 4") setStyleSheet("background-color: yellow")}
						  
        eCheckBa5  =  new qCheckBox(win)  { setgeometry( 120, 112, 100, 20)
                          settext(" 5") setStyleSheet("background-color: yellow")}

        eCheckBa6  =  new qCheckBox(win)  { setgeometry( 120, 134, 100, 20)
                          settext(" 6") setStyleSheet("background-color: yellow")}

        eCheckBa7  =  new qCheckBox(win)  { setgeometry( 120, 156, 100, 20)
                            settext(" 7") setStyleSheet("background-color: yellow")}

        eCheckBa8  =  new qCheckBox(win)  { setgeometry( 120, 178, 100, 20)
                            settext(" 8") setStyleSheet("background-color: yellow")}

        //==============================

        eCheckLines  =  new qCheckBox(win)  { setgeometry( 270, 2, 140, 20)
                            settext(" Show Lines")    setStyleSheet("background-color: yellow")}
							
		//==============================

        btnGo  = new qPushButton(win) { setGeometry( 2, 2, 110, 20)
                                        setText(" GoBalls")
                                        setStyleSheet("background-color: aqua")
                                        setClickEvent("GoBalls()")
                                      }

        //==============================
       ###=================================
	   
        lImage  =  new qLabel(win) { setgeometry( 420, 2 , 100, 20)  
                                       settext(" Image-Siize")  
                                       setStyleSheet("background-color: yellow")
                                   }	   
	   
	    SliderImage = new qSlider(win)
        {
          //setgeometry(620,btnVertPos+3,140,btnSize-6)
	  	    setgeometry( 420, 22 , 100, 20)
            setOrientation(1)
            setstylesheet("color:red;background-color:white;")
            setMinimum(1)
            setMaximum(10)
            setValue(4)
            setsliderReleasedEvent("pSliderImageReleased()")    ### Released - on Drag -
            //setvalueChangedEvent("pSliderImageReleased()")   ### Changed  - on Click -
        }

        //------------------------------------

        lSpeed  =  new qLabel(win) { setgeometry( 530, 2 , 100, 20)  
                                       settext("Move-Speed")  
                                       setStyleSheet("background-color: yellow")
                                   }

	    SliderSpeed = new qSlider(win)
        {
          //setgeometry(620,btnVertPos+3,140,btnSize-6)
	  	    setgeometry( 530, 22 , 100, 20)
            setOrientation(1)
            setstylesheet("color:red;background-color:white;")
            setMinimum(1)
            setMaximum(20)
            setValue(5)
            setsliderReleasedEvent("pSliderSpeedReleased()")    ### Released - on Drag -
            //setvalueChangedEvent("pSliderSpeedReleased()")   ### Changed  - on Click -
        }	

        //-------------------------------

        lRadius  =  new qLabel(win) { setgeometry( 640, 2 , 100, 20)  
                                       settext("Circle-Radius")  
                                       setStyleSheet("background-color: yellow")
                                   }		
		
	    SliderRadius = new qSlider(win)
        {
          //setgeometry(620,btnVertPos+3,140,btnSize-6)
	  	    setgeometry( 640, 22 , 100, 20)
            setOrientation(1)
            setstylesheet("color:red;background-color:white;")
            setMinimum(100)
            setMaximum(600)
            setValue(300)
            setsliderReleasedEvent("pSliderRadiusReleased()")    ### Released - on Drag -
            //setvalueChangedEvent("pSliderRadiusReleased()")   ### Changed  - on Click -
        }			
		

       ###-----------------------------------
       ### Font Type and Size

           oFont = new qfont("Calibri",10,0,0)
           setfont(oFont)

       //------------------------------

      show()
    }
    exec()
 }

return

###==============================================================
###==============================================================

###==========================================================================
// Clear Images
Func  ClearImages()

    See "ClearImages() "+nl

   imageC1.setGeometry( -900, -900, 200, 200 )  // Move Off Screen
   imageC2.setGeometry( -900, -900, 200, 200 )  //
   imageC3.setGeometry( -900, -900, 200, 200 )  //
   imageC4.setGeometry(- 900, -900, 200, 200 )  //
   imageC5.setGeometry( -900, -900, 200, 200 )  // Move Off Screen
   imageC6.setGeometry( -900, -900, 200, 200 )  //
   imageC7.setGeometry( -900, -900, 200, 200 )  //
   imageC8.setGeometry( -900, -900, 200, 200 )  //


    //-------------------------
    // Draw Axis

    daVinci.setpen(penWhite)
    daVinci.drawLine(  -500,   0 , 500,   0 )  // Horz
    daVinci.drawLine(     0,-500 ,   0, 500 )  //   Vert

    MonaLisa.fill(colorBlack)      // ===<<< BLANK OUT OLD IMAGE !!!
    Canvas.setPixMap(MonaLisa)     ### Need this setPixMap to display imageLabel
    MyApp.ProcessEvents()          ### <<< EXEC the Draw

return

###==========================================================================

###==============================================================
###==============================================================
// xPos = (xWidth  - image.width()  ) / 2
// yPos = (yHeight - image.height() ) / 2

Func GoBalls()

   ClearImages()

   xPos = (xWidth  / 2 )           // Balls are 400 pix
   yPos = (yHeight / 2 )
   iS   = imageSize / ImageScale   // 400 / 8 = 50
   hIS  = iS / 2                   // HalfImageScale = 25

    //------------------------
    // Draw Axis
    daVinci.setpen(penWhite)
    daVinci.drawLine(  -500,   0 , 500,   0 )  // Horz
    daVinci.drawLine(     0,-500 ,   0, 500 )  //   Vert

    Canvas.setPixMap(MonaLisa)    ### Need this setPixMap imageLabel
    MyApp.ProcessEvents()         ### <<< EXEC the Draw

   //---------------------------------
   //----------------------------------

     PI     = 3.14159265358979323846
     Circle = pi * 2 // 2PI Radians = Circle of 360 degrees
     len  = 16       // Number of Lines Division of Circle
     hlen = len / 2  // Half len = Number of Balls  b
     cx   =  0       // Center-X
     cy   =  0       // Center-Y
     w    =  Radius  // Width
     h    =  Radius  // Height
    stepN =  0.01    // Increment of Movement of Balls

    //------------------------------

    while (1)
        for i = 0 to len-1

             angleRad = (i / len) * circle  // Slice of Circle = 2PI Rags
             a = angleRad

             x = cx + ( cos(a) * w)  // x-coord
             y = cy + ( sin(a) * h)  // y-coord

            if (i < hlen)   continue  ok   // Calc 1-8

            //-------------------
            // Do Rest 9-16

            stepN -= MoveInc       // Neede again for motion Inc smoothness
            range = cos(a + stepN)
                x = cx + ( cos(a) * (w - 1) * range)
                y = cy + ( sin(a) * (h - 1) * range)

                x1 = x
                y1 = y

            if i = 8   and aShowBa[ 9] = 1  imageC1.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok
            if i = 9   and aShowBa[10] = 1  imageC2.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok
            if i = 10  and aShowBa[11] = 1  imageC3.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok
            if i = 11  and aShowBa[12] = 1  imageC4.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok

            if i = 12  and aShowBa[13] = 1  imageC5.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok
            if i = 13  and aShowBa[14] = 1  imageC6.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok
            if i = 14  and aShowBa[15] = 1  imageC7.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok
            if i = 15  and aShowBa[16] = 1  imageC8.setGeometry( xPos-hIS +x1, yPos-hIS -y1, iS,iS) ok


            // Show Circle and Lines
            if eCheckLines.isChecked() = 1

               daVinci.setPen(penYellow)
               if i = 8   and aShowBa[ 9] = 1  daVinci.drawPoint(x1, -y1)  ok  //  oClock
               if i = 9   and aShowBa[10] = 1  daVinci.drawPoint(x1, -y1)  ok  //  oClock
               if i = 10  and aShowBa[11] = 1  daVinci.drawPoint(x1, -y1)  ok  //  oC;ock
               if i = 11  and aShowBa[12] = 1  daVinci.drawPoint(x1, -y1)  ok  //  oClock

               if i = 12  and aShowBa[13] = 1  daVinci.drawPoint(x1, -y1)  ok
               if i = 13  and aShowBa[14] = 1  daVinci.drawPoint(x1, -y1)  ok
               if i = 14  and aShowBa[15] = 1  daVinci.drawPoint(x1, -y1)  ok
               if i = 15  and aShowBa[16] = 1  daVinci.drawPoint(x1, -y1)  ok

               daVinci.setpen(penBlue4)
               DrawCircle(0, 0, Radius)

            else
               MonaLisa.fill(colorBlack)   // ===<<< BLANK OUT OLD IMAGE !!!

            ok
			
			//============================================
			if eCheckBal1s.isChecked() = 1
	
			   if eCheckBa1.isChecked() = 1  aShowBa[9]  = 1  else  aShowBa[9]  = 0  imageC1.setGeometry( -900, -900, 200, 200 ) ok			  
			   if eCheckBa2.isChecked() = 1  aShowBa[10] = 1  else  aShowBa[10] = 0  imageC2.setGeometry( -900, -900, 200, 200 ) ok			   
			   if eCheckBa3.isChecked() = 1  aShowBa[11] = 1  else  aShowBa[11] = 0  imageC3.setGeometry( -900, -900, 200, 200 ) ok			  
			   if eCheckBa4.isChecked() = 1  aShowBa[12] = 1  else  aShowBa[12] = 0  imageC4.setGeometry(- 900, -900, 200, 200 ) ok
			   if eCheckBa5.isChecked() = 1  aShowBa[13] = 1  else  aShowBa[13] = 0  imageC5.setGeometry( -900, -900, 200, 200 ) ok
			   if eCheckBa6.isChecked() = 1  aShowBa[14] = 1  else  aShowBa[14] = 0  imageC6.setGeometry( -900, -900, 200, 200 ) ok			  
			   if eCheckBa7.isChecked() = 1  aShowBa[15] = 1  else  aShowBa[15] = 0  imageC7.setGeometry( -900, -900, 200, 200 ) ok
			   if eCheckBa8.isChecked() = 1  aShowBa[16] = 1  else  aShowBa[16] = 0  imageC8.setGeometry( -900, -900, 200, 200 ) ok			   
			   
		    else	   
			   aShowBa  = [0,0,0,0, 0,0,0,0, 1,1,1,1, 1,1,1,1]   // ALL
			ok

            //------------------------
            // Re-Draw Axis
            daVinci.setpen(penWhite)
            daVinci.drawLine(  -500,   0 , 500,   0 )  // Horz
            daVinci.drawLine(     0,-500 ,   0, 500 )  //   Vert

            Canvas.setPixMap(MonaLisa)    ### Need this setPixMap imageLabel
            MyApp.ProcessEvents()         ### <<< EXEC the Draw


        next

        Sleep(SleepDelay)
    end

Return

//==========================================================
//==========================================================
###-----------------------------
### Slider Dragged and Released
### ImageScale = 4 // 4 Reduce Image by the Factor Sca
Func pSliderImageReleased()

  number = SliderImage.value()
  See "SliderImageReleased: "+ SliderImage.value() +nl

  ImageScale = number
    
  imageC1.setpixmap( image1.scaled(image1.width()/ImageScale, image1.height()/ImageScale , 0, 0) )   
  imageC2.setpixmap( image2.scaled(image2.width()/ImageScale, image2.height()/ImageScale , 0, 0) ) 
  imageC3.setpixmap( image3.scaled(image3.width()/ImageScale, image3.height()/ImageScale , 0, 0) )  
  imageC4.setpixmap( image4.scaled(image4.width()/ImageScale, image4.height()/ImageScale , 0, 0) )  
  imageC5.setpixmap( image5.scaled(image5.width()/ImageScale, image5.height()/ImageScale , 0, 0) )  
  imageC6.setpixmap( image6.scaled(image6.width()/ImageScale, image6.height()/ImageScale , 0, 0) )  
  imageC7.setpixmap( image7.scaled(image7.width()/ImageScale, image7.height()/ImageScale , 0, 0) )  
  imageC8.setpixmap( image8.scaled(image8.width()/ImageScale, image8.height()/ImageScale , 0, 0) )    
  
  GoBalls()

return


//==========================================================
//==========================================================
###-----------------------------
### Slider Dragged and Released
### MoveInc    = 0.010     // 0.010

Func pSliderSpeedReleased()

  number = SliderSpeed.value()
  See "SlideSpeedReleased: "+ SliderSpeed.value() +nl

   MoveInc = number / 1000    // 1..20  / 1000 
  
  GoBalls()

return


//==========================================================
//==========================================================
###-----------------------------
### Slider Dragged and Released
### Radius     = 300       // Size of Display

Func pSliderRadiusReleased()

  number = SliderRadius.value()
  See "SliderRadiusReleased: "+ SliderRadius.value() +nl

  Radius = number
  
  GoBalls()

return


//============================================
//============================================

Func DrawCircle(x,y,radius)

//See "DrawCircle: x:"+x +" y:"+y +" rad:"+radius +nl

    HCenter = x
    VCenter = y
    HWidth  = 2 * radius
    VHeight = 2 * radius

    HCorner = HCenter - (HWidth  /2)
    VCorner = VCenter - (VHeight /2)

    daVinci.drawEllipse(HCorner, VCorner, HWidth, VHeight)  // LeftCorner, HWidth, VHeight

return

###====================================================================
###====================================================================



###=====================================================================
###=====================================================================

###==============================================================
###==============================================================


