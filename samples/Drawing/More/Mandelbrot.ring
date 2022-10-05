### Project : CalmoSoft Mandelbrot Set
### Date    : 2019/02/25-04:00:00
### Update  : 2019/02/25-04:21:08
### Author  : Gal Zsolt 

###  Mandelbrot - Colorized and Animated
###  2019-02-25  Bert Mariani
###
###  MyApp.ProcessEvents()  ###<<< EXEC the Draw MonaLisa between each step of array sorting

Load "guilib.ring"
load "stdlib.ring"

WinX     = 620
WinY     = 650

ButtonX  = 620
ButtonW  = 100
ButtonH  =  30

LabelX   = 600
LabelY   = 600

MonaX    = 600
MonaY    = 600

gSleepDelay = 0.1           ### Set SleepDelay for Visual display of sort array steps
gSpace = 2                  ### Space between bars drawn

### Setup Random Values --------------------

width    = 500          ### Array Size =  400
height   = 400
values   = list(width)  ### Global

###-----------------------------------------

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

penUseW = new qpen() { setcolor(colorWhite )  setwidth(1) }
penUseR = new qpen() { setcolor(colorRed   )  setwidth(1) }
penUseG = new qpen() { setcolor(colorGreen )  setwidth(1) }
penUseB = new qpen() { setcolor(colorBlue  )  setwidth(1) }

penUseGr = new qpen() { setcolor(colorGray  )  setwidth(1) }
penUseBr = new qpen() { setcolor(colorBrown )  setwidth(1) }
penUseBk = new qpen() { setcolor(colorBlack )  setwidth(1) }
penUseOr = new qpen() { setcolor(colorOrange)  setwidth(1) }

penUseYe = new qpen() { setcolor(colorYellow)  setwidth(1) }
penUsePu = new qpen() { setcolor(colorPurple)  setwidth(1) }
penUsePi = new qpen() { setcolor(colorPink  )  setwidth(1) }
penUseLi = new qpen() { setcolor(colorLime  )  setwidth(1) }



penArray =   [penUseW, penUseR, penUseG, penUseB, PenUseGr, penUseBr, penUseBk, penUseOr, penUseYe, penUsePu, penUsePi, penUseLi]

###===========================================

MyApp = New qapp
{
   win1 =  new qwidget()
    {
        setwindowtitle("Draw Mandelbrot: ")
        setgeometry(100,50,WinX, WinY)      ### On Screen

        new qpushbutton(win1)
        {
              setgeometry(50,ButtonX, ButtonW, ButtonH)
              settext("Draw")
              setclickevent("Draw()")
        }


        ###==================================

        Canvas = new qlabel(win1)
        {
            setgeometry(10,10,LabelX, LabelY)  ### In Window

            MonaLisa = new qPixMap2( MonaX, MonaY)

            daVinci  = new qpainter()
            {
               begin(MonaLisa)
               setpen(penUseB)
               #endpaint()                      ### This will Stop the Painting
            }

            setpixmap(MonaLisa)
        }

        ###==================================


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
    offset = 50

    x1 = width
    y1 = height

    i1 = -1  i2 = 1  r1 = -2 r2 = 1

    s1 = (r2 - r1) / x1
    s2 = (i2 - i1) / y1

    for y = 0 to y1
         i3 = i1 + s2 * y

        for x = 0 to x1
              r3 = r1 + s1 * x
              z1 = r3
              z2 = i3

            for n = 0 to 30
                   a = z1 * z1
                   b = z2 * z2

                   if a+b > 4 exit ok

                   z2 = 2 * z1 * z2 + i3
                   z1 = a-b+r3

            next

            if N > 2 and N < 32   ### n != 31
                penToUse = penArray[ N % 12 +1]
                daVinci.setpen(penToUse)
                daVinci.drawPoint(x+offset, y+offset)
              
            ok

        next
	if y%3 = 0 
	  	DrawUpdate()
	ok
    next
    DrawUpdate()
    See "FINISHED: "+ nl
    win1.setwindowtitle("FINISHED ")


return


