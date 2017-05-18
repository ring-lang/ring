###-----------------------------------------
### Analog Clock - Ring
### Use QPixMap2, Translate, Rotate, Scale
### 2017-03-28  Bert Mariani
###-----------------------------------------

Load "guilib.ring"

colorRed     = new qcolor() { setrgb( 255,0,0,255 ) }
penRed       = new qpen()   { setcolor(colorRed)  setwidth(2) }

colorGreen   = new qcolor() { setrgb( 0,255,0,255 ) }
penGreen     = new qpen()   { setcolor(colorGreen)  setwidth(2) }

colorBlue    = new qcolor() { setrgb( 0,0,255,255 ) }
penBlue      = new qpen()   { setcolor(colorBlue)  setwidth(2) }


penArray  = [penRed, penGreen, penBlue]
penNbr    = 1
penNbrOld = 1

colorGray    = new qcolor() { setrgb( 238,238,238,255 ) }
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

##--------------------------------------------
###-------------------------------------------

New qapp
{
   win =  new qwidget()
    {
        setwindowtitle("Analog Clock : Draw using QPixMap : Translate : Rotate : Scale :")
        setgeometry(100, 100, 500, 500)

        Canvas = new qlabel(win)
        {
            MonaLisa = new qPixMap2( 500, 500)

            daVinci  = new qpainter()
            {
                begin(MonaLisa)

                setBrush(brushSGray)
                drawRect( 0, 0, 500, 500)

                ###--------------------------

                width  = win.width()
                height = win.height()
                side   = height  if  width < height  side width  ok

                # See "Side: "+ side +" width: "+ width +" height: "+ height +nl

                translate( width / 2, height / 2);               ### CENTER of Label Box is 250 x 240
                rotate(0)                                        ### NO ROTATION at Start
                scale( 2*side / width, 2*side / height);         ### SCALE: Draw Hands in Proportion Size


                ###----------------------------
                ### 1 Minute Marks - 6 degrees

                    for j = 0 to 60
                        if j = 0  rotate(0)  else  rotate(6)  ok
                        daVinci.drawLine(0, -114, 0, -118)
                    next

                ###----------------------------
                ### 5 Minute Marks - 30 degrees

                    for i = 0 to 12
                        if i = 0  rotate(0)  else rotate(30)  ok
                        daVinci.drawLine(0, -110, 0, -118)
                    next

                ###-----------------------

                setCompositionMode(29)                           ###  THIS is the MAGIC - 26, 29 Erase Old Line when Redrawn

            }

            setpixmap(MonaLisa)
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

        ###-----------------------------------
        ### Clock Dial numbers

        label1 = new QLabel(win){
                    setgeometry(350, 50, 50, 50)
                    settext("1")}

        label2 = new QLabel(win){
                    setgeometry(420, 120, 50, 50)
                    settext("2")}

        label3 = new QLabel(win){
                    setgeometry(450, 225, 50, 50)
                    settext("3")}

        label4 = new QLabel(win){
                    setgeometry(425, 330, 50, 50)
                    settext("4")}

        label5 = new QLabel(win){
                    setgeometry(350, 400, 50, 50)
                    settext("5")}

        label6 = new QLabel(win){
                    setgeometry(250, 430, 50, 50)
                    settext("6")}

        label7 = new QLabel(win){
                    setgeometry(145, 405, 50, 50)
                    settext("7")}

        label8 = new QLabel(win){
                    setgeometry(65, 330, 50, 50)
                    settext("8")}

        label9 = new QLabel(win){
                     setgeometry(40, 225, 50, 50)
                     settext("9")}

        label10 = new QLabel(win){
                     setgeometry(65, 120, 50, 50)
                     settext("10")}

        label11 = new QLabel(win){
                    setgeometry(145, 40, 50, 50)
                    settext("11")}

        label12 = new QLabel(win){
                    setgeometry(245, 20, 50, 50)
                    settext("12")}

        label13 = new QLabel(win){
                    setgeometry(220, 60, 60, 50)

                    ###------------------------------------------
                    ### Set a New Font. Increase the Font Size
                    ### Clock Dial maker = Ring

                    oFont = new qfont("Vivaldi",20,0,0)
                    setfont(oFont)

                     # myfont = font()
                     # myfont.setPointSize(20)
                     # myfont.setItalic(true)
                     # myfont.setBold(true)
                     # setfont(myfont)

                    settext("Ring")}

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

Func Draw(pen1)

        Hour   = TimeList()[8]
        Minute = TimeList()[11]
        Second = TimeList()[13]
        #See "Time: Hour: "+ Hour +" Min: "+ Minute +" Sec: "+ Second +nl

            ###-----------------------------------------------------
            ### RE-Draw Old Position to erase it.
            ### On very first startup, there is Nothing to Erase.
            ###------------------------------------------------------

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
            ###
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

        Canvas.setpixmap(MonaLisa)
        win.show()
return

###----------------------------
