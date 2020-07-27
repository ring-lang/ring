# Project : Julia set
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "guilib.ring"

paint = null

new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Cantor set")
                  setgeometry(100,100,500,400)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,400,400)
                              settext("")
                  }
                  new qpushbutton(win1) {
                          setgeometry(150,300,100,30)
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
                 setwidth(3)
        }
        paint = new qpainter() {
                  begin(p1)
                  setpen(pen)

        cantor(10, 10, 400)

        endpaint()
        }
        label1 { setpicture(p1) show() }

func cantor (x, y, len)
        if (len >= 1) 
            paint.drawline(x, y, x+len, y)
            y += 20
           cantor(x, y, len/3)
           cantor(x+len*2/3, y, len/3)
       ok
