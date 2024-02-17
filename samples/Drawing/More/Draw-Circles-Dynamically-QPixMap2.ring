/*
 +------------------------------------------------------------
 +        Program Name : DrawCircles-Dynamic.ring
 +        Date         : 2017.02.27
 +        Author       : Bert Mariani
 +        Purpose      : Draw Circles - Non Overlapping
 +                     : Dynamically using QPixMap2
 +------------------------------------------------------------
*/

Load "guilib.ring"

nbrOfCircles = 12                   ### How many circles
CountMax     = 25                   ### Max loop count
CirclesDrawn = 0
Count        = 0

CanvasHorzSize = 500                ### Canvas size
CanvasVertSize = 500                ### Canvas size

DrawHorzSize   = 480                ### Draw size
DrawVertSize   = 400                ### Draw size

radSize    = 100                    ### Largest  Radius size
radSizeMin =   5                    ### Smallest Radius size

horz = 1
vert = 1
rad  = 1

arrayCol   = list(nbrOfCircles)     ### arrayOfCollisions
positionCollisionTable  = 1         ### Position in the array Collision table

    colorWhite  = new qcolor() { setrgb(255,255,255,255) }
    colorRed    = new qcolor() { setrgb(204,000,000,255) }
    colorGreen  = new qcolor() { setrgb(000,204,000,255) }
    colorBlue   = new qcolor() { setrgb(000,000,255,255) }

    colorGray   = new qcolor() { setrgb(128,128,128,255) }
    colorBrown  = new qcolor() { setrgb(153,076,000,255) }
    colorBlack  = new qcolor() { setrgb(000,000,000,255) }
    colorOrange = new qcolor() { setrgb(255,128,000,255) }

    colorYellow = new qcolor() { setrgb(255,255,000,255) }
    colorPurple = new qcolor() { setrgb(153,153,255,255) }
    colorPink   = new qcolor() { setrgb(255,051,255,255) }
    colorLime   = new qcolor() { setrgb(128,255,000,255) }

    colorMix    = new qcolor() { setrgb(128,064,032,255) }

$arrayColor  = [colorWhite,colorGray,colorRed,colorGreen,colorBlue,colorBrown,colorBlack,colorOrange,colorYellow,colorPurple,colorPink,colorLime]


    penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
    penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
    penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
    penGray     = new qpen() { setcolor(colorGray)   setwidth(1) }

    penBrown    = new qpen() { setcolor(colorBrown)  setwidth(1) }
    penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }
    penWhite    = new qpen() { setcolor(colorWhite)  setwidth(1) }
    penOrange   = new qpen() { setcolor(colorOrange) setwidth(1) }

    penYellow   = new qpen() { setcolor(colorYellow) setwidth(1) }
    penPurple   = new qpen() { setcolor(colorPurple) setwidth(1) }
    penPink     = new qpen() { setcolor(colorPink)   setwidth(1) }
    penLime     = new qpen() { setcolor(colorLime)   setwidth(1) }

$arrayPenColor  = [penRed,penGreen,penBlue,penGray,penBrown,penBlack,penWhite,penOrange,penYellow,penPurple,penPink,penLime]

    ### Brush style 0-Empty 1-Solid 2-Hatched 3-FineHatch
    brushE = new qbrush() { setstyle(0)  setcolor (colorGreen)}
    brushS = new qbrush() { setstyle(1)  setcolor (colorMix)  }
    brushH = new qbrush() { setstyle(2)  setcolor (colorGreen)}
    brushF = new qbrush() { setstyle(3)  setcolor (colorRed)  }

###-----------------------------------------------------------------


New qapp {
    win1 =  new qwidget()
    {
            setwindowtitle("Circle - Draw and Fill -- QPainter -- QPixMap2 -- Dynamic")
            setgeometry(100, 100, CanvasHorzSize, CanvasVertSize)

            label2 = new qlabel(win1)
            {
                setgeometry( (DrawHorzSize / 2) -80 , DrawVertSize +40, 70, 20 )
                settext("   #Circles")
            }

            lineEdit1 = new qlineedit(win1) {
                setGeometry( (DrawHorzSize / 2) -70 , DrawVertSize +60, 50, 20 )
                settext( "198" )                   ### <<<< Initial Value
            }

            new qpushbutton(win1)
            {
                setgeometry(DrawHorzSize / 2, DrawVertSize +60, 100, 20)
                settext("DrawStart")
                setclickevent("DrawStart()")       ###  ===>>> Func
            }

            Canvas = new qlabel(win1)
            {  
                ### daVinci paints the MonaLisa on the Canvas

                setgeometry(10, 20, DrawHorzSize, DrawVertSize)
                MonaLisa = new qPixMap2( DrawHorzSize, DrawVertSize)

                daVinci = new qpainter()
                {
                   begin(MonaLisa)
                   #endpaint()                     ### This will Stop the Painting
                }

                setpixmap(MonaLisa)
            }


            nCounter = 0
            oTimer = new qTimer(win1)
            {
                setinterval(1)                      ### 1 second = 1000
                settimeoutevent("DrawCounter()")
                #start()                            ### Do NOT start, It will be done by DrawStart Button
            }


	DrawStart()
        show()
    }
    exec()
}



###=====================================================
###=====================================================

Func DrawStart()

    nbrOfCircles = number(lineedit1.text() )    ### Read text field. How many circles
    if nbrOfCircles < 1 return ok

    arrayCol     = []
    arrayCol     = list(nbrOfCircles)   ### arrayOfCollisions


    for i = 1 to nbrOfCircles           ### Clear array
        arrayCol[i] = [0,0,0,0]
    next
    arrayCol[1] = [0,0,1,1]             ### Reserve first entry to prevent overlap of first circle


    positionCollisionTable = 1          ### Pointer to arrayOfCollisions[]
    Count  = 1                          ### Limit of iterations to calculated collisions.

    CirclesDrawn = 0                    ### Number of circles drawn so far

    daVinci.setBrush(brushS)            ### Brush - Solid, Blue
    daVinci.drawRect(0,0,500,400)       ### Draw Rectangle - To Empty -- clear Canvas

    oTimer.start()                      ### Start the Timer

return


###=======================================================

Func Draw(y)

    ### daVinci paints the MonaLisa on the Canvas

    penUse = new qpen() { setcolor($arrayColor[y]) setwidth(1) }    ### Pen color
    daVinci.setpen(penUse)                      ### Pen - random color

    brushS = new qbrush() { setstyle(1) setcolor ($arrayColor[y]) } ### Brush color
    daVinci.setBrush(brushS)                    ### Brush - Solid, random color

    daVinci.drawellipse(horz,vert,rad,rad)      ### Circle

    #endpaint()                                 ### This will Stop the Painting

    Canvas.setpixmap(MonaLisa)                  ### Need this setpixmap to display imageLabel
    win1.show()                                 ### Need this show      to display imageLabel


    ### ONLY Displays AFTER RETURN from sub-routine
    ###--------------------------------------------

return


###===================================================

Func DrawCounter()

    ReturnCode = CollisionDetection()       ### ==>>> FUNCTION

    if ReturnCode = 0                       ### RetCode 0 = No collision with previous circles
        CirclesDrawn++
        #See "CirclesDrawn: "+ CirclesDrawn +nl

        y = CirclesDrawn % 12 +1            ### y = next color

        Draw(y)                             ### ==>>> FUNCTION ... draw NEW circle

        if CirclesDrawn >= nbrOfCircles
            See "Finished nbrofCircles: "+ CirclesDrawn +nl
            oTimer.stop()
            return
        ok

    else                                    ### RetCode 1,2 = Collision 
        See "Overlap: RetCode: "+ ReturnCode +" Count "+ Count +" Position "+ positionCollisionTable +" "+ horz +" "+ vert +" "+ rad  +nl

        if Count >= CountMax
            See "Finished: " +nl
            oTimer.stop()
            return
        ok
    ok


return

###----------------------------------------------------

Func CollisionDetection ()

        # Check for no overlap with existing circle
        # Ellipse uses TopLeft and width and height
        # Circle Center is  Horz = (TopLeft + ( Width / 2) ), Vert =  (TopLeft + (Height / 2) )

    horz   = random(DrawVertSize)
    vert   = random(DrawVertSize)
    rad    = random(radSize)

    for i = 1 to nbrOfCircles
        if arrayCol[i][1] = 0                   ### Reach empty slot in Collision Table

            ### Empty slot
            HorzC  = (horz + ( rad / 2) )
            VertC  = (vert + ( rad / 2) )
            Radius =  rad / 2

            arrayCol[i] = [ positionCollisionTable, HorzC, VertC, Radius ]

            positionCollisionTable++
            #See "Collision Return 0:"+nl

            return 0

        else                                    ### Check if Collision with any circle in Collision Table

            HC  = (horz + ( rad / 2) )
            VC  = (vert + ( rad / 2) )
            RC  =  rad / 2

            oHC  = arrayCol[i][2]
            oVC  = arrayCol[i][3];
            oRC  = arrayCol[i][4]

            DeltaH   = (HC - oHC)
            DeltaV   = (VC - oVC)
            DeltaR   = (RC + oRC)

            HypothRR = (DeltaR * DeltaR)
            HypothHV = ( (DeltaH * DeltaH) + (DeltaV * DeltaV) )

            if HypothHV >= HypothRR
                Overlap  = 0
                #See "Collision Overlap 0: "+ i +nl

            else
                Overlap  = 1

                Count++                 ### Max iteration exit limit
                #See "Collision Return 1: "+ Count +nl

                horz   = random(DrawHorzSize)
                vert   = random(DrawVertSize)
                rad    = random(radSize)
                i      = 1

            ok

        ok

    next

See "Collision Return 2:"+nl
return  2

###--------------------------------------------
