###-----------------------------------------
### Analog Clock - Ring
### Use QPixMap2, Translate, Rotate, Scale
### 2017-03-28  Bert Mariani
###-----------------------------------------

Load "lightguilib.ring"

colorRed     = new qcolor() { setrgb( 255,0,0,255 ) }
penRed       = new qpen()   { setcolor(colorRed)  setwidth(2) }

colorGreen   = new qcolor() { setrgb( 0,255,0,255 ) }
penGreen     = new qpen()   { setcolor(colorGreen)  setwidth(2) }

colorBlue    = new qcolor() { setrgb( 0,0,255,255 ) }
penBlue      = new qpen()   { setcolor(colorBlue)  setwidth(2) }


penArray     = [penRed, penGreen, penBlue]
penNbr       = 1
penNbrOld    = 1

colorGray    = new qcolor() { setrgb( 238,238,200,255 ) }
penGray      = new qpen()   { setcolor(colorGray)  setwidth(2) }

colorHour    = new qcolor() { setrgb(000, 255, 255 ,255) }  ### Yellow
colorMinute  = new qcolor() { setrgb(255, 255, 000, 255) }  ### Yellow

brushSHour   = new qbrush() { setstyle(1)  setcolor (colorHour)  }     ### Violet
brushSMinute = new qbrush() { setstyle(1)  setcolor (colorMinute)  }   ### Mauve
brushSGray   = new qbrush() { setstyle(1)  setcolor (colorGray)  }     ### Gray
brushE       = new qbrush() { setstyle(0)  setcolor (colorHour)  }     ### Empty

side   = 1
width  = 1
height = 1
scale  = 1   ### <<<== Magnify Clock

Hour   = 0  oldHour   = 99
Minute = 0  oldMinute = 99
Second = 0  oldSecond = 99   ### 99 - First Draw, there is NO OLD Draw to Erase

oScaledImage = NULL

###-------------------------------
### Window Size
    WinLeft   = 40                  ###   80  Window position on screen
    WinTop    = 40                  ###   80  Window position on screen
    WinWidth  = 600                 ### 1000  Window Size - Horizontal-X WinWidth
    WinHeight = 600                 ###  750  Window Size - Vertical-Y WinHeight
    
    WinRight  = WinLeft + WinWidth  ### 1080
    WinBottom = WinTop  + WinHeight ###  830
 
##--------------------------------------------
###-------------------------------------------

New qapp
{
   win =  new qwidget()
    {
        setwindowtitle("Analog Clock")
	setWinIcon(self,"HermleClock.jpg")
	setwindowflags(Qt_WindowStaysOnTopHint)
        setgeometry(WinLeft, WinTop, WinWidth, WinHeight)


            imageClock = new qlabel(win) 
            {
               image = new qPixMap("HermleClock.jpg")        ### CLOCK FACE
               
               AspectRatio = image.width() / image.height()
               imageW = winWidth               ### 600     
               imageH = imageW / AspectRatio
               image  = image.scaled(imageW , imageH , 0, 0)
               
 
               daVinci   = new qpainter()
               {
                    begin(image)                        ### Start painting the image

                    setPen(penRed)
                    drawRect(0,0,WinWidth, WinHeight)
                    #endpaint()                         ### Do NOT endpaint()


                    ###--------------------------
                    Magnify = 2
                    Side    = winHeight  if  WinWidth < winHeight  Side = winWidth  ok
 
                    transXpos = WinWidth  / 2  -5
                    transYpos = WinHeight / 2 -13

                    translate(transXpos, transYpos )                        ### Co-Ordinate System moves. CENTER of Label Box is x, y
                    rotate(0)                                                             ### NO ROTATION at Start
                    scale( Magnify * Side / winWidth, Magnify * Side / winHeight);        ### SCALE: Draw Hands in Proportion Size

                    setCompositionMode(29)     ###  THIS is the MAGIC - 26, 29 Erase Old Line when Redrawn
               }
                
                   
               setpixmap(image)
               PosLeft = 0  
               PosTop  = 0  
               setGeometry(PosLeft,PosTop,imageW,imageH)                                                
            }
        
        
        ###-----------------------------------
        ### Font Type and Size

            oFont = new qfont("Vivaldi",12,0,0)
            setfont(oFont)

        ###-----------------------------------
        ### Timer Pops every 1 second

            nCounter = 0
            oTimer = new qTimer(win)
            {
                setinterval(1000)
                settimeoutevent("DrawCounter()")    ### >>>== Function
                start()
            }

        ###------------------------------------------
        ### ReSizeEvent ... Call WindowSizeChanged function

            myfilter = new qallevents(win)
            myfilter.setResizeEvent("WindowSizeChanged()")
            installeventfilter(myfilter)

            
       show()
    }

    exec()
}

DrawCounter()

###-------------------------------
### Called by oTimer

func DrawCounter()

       penNbrOld = penNbr
       penNbr++

       if penNbr > 3  penNbr = 1  ok

       Draw(penArray[penNbr])

return

###-------------------------------
### DRAW ANALOG CLOCK

Func Draw(pen1)   ### <<<=== Called by Timer

        Hour   = TimeList()[8]
        Minute = TimeList()[11]
        Second = TimeList()[13]
        
        #See "Time: Hour: "+ Hour +" Min: "+ Minute +" Sec: "+ Second +nl

            ###-----------------------------------------------------
            ### RE-Draw Old Position to erase it.
            ### On very first startup, there is Nothing to Erase.


            if oldSecond != 99
                daVinci.save()
                daVinci.setpen(penArray[penNbrOld])
                daVinci.rotate(6 * oldSecond  )
                daVinci.drawLine( 0, 0, 0, -110)
                daVinci.restore()

                daVinci.save()
                daVinci.rotate(6 * oldMinute + ( 6 * oldSecond / 60) )
                daVinci.setBrush(brushSMinute)
                daVinci.drawPolygon( [ [7, 8], [-7, 8 ], [0, -90 ] ], 0)
                daVinci.restore()

                daVinci.save()
                daVinci.rotate( (30 * oldHour) + ( 6 * oldMinute / 12) )
                daVinci.setBrush(brushSHour)
                daVinci.drawPolygon( [ [7, 8], [-7, 8 ], [0, -60 ] ], 0)
                daVinci.restore()
            ok

            ###------------------------------------------------------------------
            ### DRAW ANALOG HANDS: 1 Second = 6 Degrees,  5 Minutes = 30 Degrees
            ###------------------------------------------------------------------
            ### Second Hand -- Line Vertical

                daVinci.save()
                daVinci.rotate(6 * Second  )
                daVinci.setpen(penArray[penNbr])
                daVinci.drawLine( 0, 0, 0, -110)
                daVinci.restore()

            ###-------------------------------
            ### Minute Hand -- Polygon long

                daVinci.save()
                daVinci.rotate(6 * Minute + ( 6 * Second / 60) )
                daVinci.setBrush(brushSMinute)
                daVinci.drawPolygon( [ [7, 8], [-7, 8 ], [0, -90 ] ], 0)
                daVinci.restore()

            ###---------------------------
            ### Hour Hand -- Polygon short

                daVinci.save()
                daVinci.rotate( (30 * Hour) + ( 6 * Minute / 12)  )
                daVinci.setBrush(brushSHour)
                daVinci.drawPolygon( [ [7, 8], [-7, 8 ], [0, -60 ] ], 0)
                daVinci.restore()

            ###-----------------------

        oldHour   = Hour
        oldMinute = Minute
        oldSecond = Second

        penNbrOld = penNbr

        analogClock()

        win.show()
return

###-----------------------------------------
###-----------------------------------------
### FUNCTION  WindowSizeChanged
###----------------------------------------

Func WindowSizeChanged()
        
    Rec = win.framegeometry()

    WinWidth  = Rec.width()             ### 1000 Current Values
    WinHeight = Rec.height()            ### 750
        
    WinLeft   = Rec.left()    ## +8     ### <<< QT FIX because of Win Title
    WinTop    = Rec.top()     ## +30    ### <<< QT FIX because of Win Title
    WinRight  = Rec.right()
    WinBottom = Rec.bottom()
    
    #PosLeft = (WinWidth  - imageW) / 2  -8                              ### Center the Clock in the Window
    #PosTop  = (WinHeight - imageH) / 2 -24                              ### Center the Clock in the Window

    #image  = image.scaled(WinWidth , WinHeight , 0, 0)                  ### Distorts Image ???
            
    #imageClock.setpixmap(image.scaled(imageW , imageH ,0,0))            ### Image NOT distorted
    #imageClock.setGeometry(PosLeft,PosTop,imageW,imageH)                ### Centers the Clock Image in the Window
                    
    analogClock()

    imageClock.setGeometry(0,0,WinWidth, WinHeight-38)    

return


func analogClock
        oScaledImage = image.scaled(WinWidth , WinHeight-38 ,0,0)
        imageClock.setpixmap(oScaledImage)   ### Size-H, Size-V, Aspect, Transform
return
