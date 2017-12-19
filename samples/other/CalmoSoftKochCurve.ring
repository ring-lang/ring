# Project : Koch curve
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "guilib.ring"

paint = null

new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Archimedean spiral")
                  setgeometry(100,100,500,600)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,400,400)
                              settext("")
                  }
                  new qpushbutton(win1) {
                          setgeometry(150,500,100,30)
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

        koch(100, 100, 400, 400, 4)

        endpaint()
        }
        label1 { setpicture(p1) show() }

func koch x1, y1, x2, y2, it

        angle = 60*3.14/180
        x3 = (2*x1+x2)/3
        y3 = (2*y1+y2)/3

        x4 = (x1+2*x2)/3
        y4 = (y1+2*y2)/3

        x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle)
        y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle)

       if(it > 0)
          koch(x1, y1, x3, y3, it-1)
          koch(x3, y3, x, y, it-1)
          koch(x, y, x4, y4, it-1)
          koch(x4, y4, x2, y2, it-1)
       else
          paint.drawline(x1, y1, x3, y3)
          paint.drawline(x3, y3, x, y)
          paint.drawline(x, y, x4, y4)
          paint.drawline(x4, y4, x2, y2)
      ok
