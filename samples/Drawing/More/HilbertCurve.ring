# Project : Hilbert curve
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "guilib.ring"

paint = null
x1 = 0
y1 = 0

new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Hilbert curve")
                  setgeometry(100,100,400,500)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,400,400)
                              settext("")
                  }
                  new qpushbutton(win1) {
                          setgeometry(150,400,100,30)
                          settext("draw")
                          setclickevent("draw()")
                  }
                  show()
        }
        exec()
        }

func draw
        p1 = new qpicture()
               color = new qcolor() {
               setrgb(0,0,255,255)
        }
        pen = new qpen() {
                 setcolor(color)
                 setwidth(1)
        }
        paint = new qpainter() {
                  begin(p1)
                  setpen(pen)

        x1 = 0.5
        y1 = 0.5 
        hilbert(0, 0, 100,  0,  0,  100,  4)

        endpaint()
        }
        label1 { setpicture(p1) show() }

func hilbert (x, y, xi, xj, yi, yj, n)
        if (n <= 0)
           drawtoline(x + (xi + yi)/2, y + (xj + yj)/2)
       else
           hilbert(x, y, yi/2, yj/2,  xi/2,  xj/2, n-1)
           hilbert(x+xi/2,  y+xj/2 , xi/2, xj/2,  yi/2,  yj/2, n-1)
           hilbert(x+xi/2+yi/2, y+xj/2+yj/2, xi/2, xj/2,  yi/2,  yj/2, n-1);
           hilbert(x+xi/2+yi, y+xj/2+yj,  -yi/2,-yj/2, -xi/2, -xj/2, n-1)
       ok

func drawtoline x2, y2
        paint.drawline(x1, y1, x2, y2)
        x1 = x2
        y1 = y2
