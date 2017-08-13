# Project : Recursive Circles
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "guilib.ring"

paint = null
x1 = 0
y1 = 0

new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Recursive circles")
                  setgeometry(100,100,500,500)
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

        drawCircle(320, 180, 200)

        endpaint()
        }
        label1 { setpicture(p1) show() }
  
func drawCircle(x, y, radius) 
     paint.drawellipse(x, y, radius, radius)
     if radius > 2
        drawCircle(x + radius/2, y, radius/2)
        drawCircle(x - radius/2, y, radius/2)
     ok

