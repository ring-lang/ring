###  2019-02-23  Bert Mariani
###  Modulo Times Table Circle
###
###  https://www.youtube.com/watch?v=qhbuKbxJsk8
###  Times Tables, Mandelbrot and the Heart of Mathematics
###
###  Mathologer
###  Published on Nov 6, 2015
###  The good old times tables lead a very exciting secret life
###  involving the infamous Mandelbrot set,
###  the ubiquitous cardioid and
###  a myriad of hidden beautiful patterns.
###  Time for the Mathologer to go on a serious fact-finding mission.
###

Load "guilib.ring"
load "stdlib.ring"

WinX     = 850
WinY     = 950

ButtonX  = 870
ButtonW  = 100
ButtonH  =  30

LabelX   = 830
LabelY   = 830

MonaX    = 830
MonaY    = 830

gSleepDelay = 0.1           
gSpace = 2                  ### Space between bars drawn

### Setup Random Values --------------------

width    = 400          ### Array Size =  400
height   = 800
values   = list(width)  ### Global

###-----------------------------------------

colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }

penUseR = new qpen() { setcolor(colorRed)   setwidth(1) }
penUseG = new qpen() { setcolor(colorGreen) setwidth(1) }
penUseB = new qpen() { setcolor(colorBlue)  setwidth(1) }
penUseK = new qpen() { setcolor(colorBlack) setwidth(1) }

penArray = [penUseR, penUseG, penUseB]

###===========================================

MyApp = New qapp
{
   win1 =  new qwidget()
    {
        setwindowtitle("Draw Modulo Multiply Tables: ")
        setgeometry(100,50,WinX, WinY)      ### On Screen

        oAllEvents = new QAllEvents(win1) {
              setCloseEvent("MyApp.Quit()")
	}
        installeventfilter(oAllEvents)

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
               setpen(penUseR)
               #endpaint()      ### This will Stop the Painting
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
###### Draw from Circle Center H-V, and Radius =  Diameter / 2

Func Circle(H,V,Diameter)

    Radius = Diameter / 2
    daVinci.drawEllipse(H - (Radius), V - (Radius), Diameter, Diameter)

return

###----------------------------------------------
###----------------------------------------------
### Ellipse => Circle => TopLeft corner Diameter
### 1Deg × π/180 = 0.0174533 Rad
### 1Deg = 0.0174533 Rad  57.29575495 Deg

Func Draw()

diameter = 800              # 800
radius   = diameter / 2     # 400
H        = diameter / 4     # 200
V        = diameter / 4     # 200

Rad      = 0.0174533
offset   = 20               # do not touch edge of window


    for dots = 720 to 810 step 90
        for multiply = 2 to 12 step 1

            win1.setwindowtitle("Dots: "+dots +" Multiply: "+ multiply)


            penToUse = penArray[ multiply % 3 +1]
            daVinci.setpen(penToUse)

            H = radius + offset
            V = radius + offset
            Circle(H, V, diameter)

            inc  = 360 / dots                   ### Point on circle of 360 degrees

            for i = 0 to dots

                xi = radius * cos(i*inc*Rad)
                yi = radius * sin(i*inc*Rad)

                j = i * multiply                ### MULTIPLY
                    xj = radius * cos(j*inc*Rad)
                    yj = radius * sin(j*inc*Rad)

                    daVinci.drawLine(xi+H, yi+V, xj+H, yj+V)
                    DrawUpdate()

            next


            DrawUpdate()

            Sleep(0.5)
            if ( dots =810 and  multiply =2 )  exit 2 ok
            MonaLisa.fill(colorBlack)

        next
    next

return


