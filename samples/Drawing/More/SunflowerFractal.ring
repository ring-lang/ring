# Project : Sunflower fractal
# Date    : 2018/07/24
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com
 
load "guilib.ring"
 
paint = null
 
new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Sunflower fractal")
                  setgeometry(100,100,320,500)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,400,400)
                              settext("")
                  }
                  new qpushbutton(win1) {
                          setgeometry(100,400,100,30)
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
 
        c = (sqrt(5) + 1) / 2
        numberofseeds = 3000
        for i = 0 to numberofseeds
              r = pow(i, c ) / (numberofseeds)
              angle = 2 * 3.14 * c * i
              x = r * sin(angle) + 100
              y = r * cos(angle) + 100
             drawellipse(x, y, i / (numberofseeds / 10), i / (numberofseeds / 10))
        next
 
        endpaint()
        }
        label1 { setpicture(p1) show() }
