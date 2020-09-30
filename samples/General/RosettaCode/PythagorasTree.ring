# Project : Pythagoras tree
# Date    : 2018/01/30
# Author : Gal Zsolt [~ CalmoSoft ~]
# Email   : <calmosoft@gmail.com>

load "guilib.ring"

paint = null

new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Pythagoras tree")
                  setgeometry(100,100,800,600)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,800,600)
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

        w = 800
        h = floor(w*11/16)
        w2 = floor(w/2)
        diff = floor(w/12)
 
        pythagorastree(w2 - diff,h -10,w2 + diff ,h -10 ,0)

        endpaint()
        }
        label1 { setpicture(p1) show() }
        return


func pythagorastree(x1,y1,x2,y2,depth) 
        if depth > 10 
           return
        ok 
        dx = x2 - x1
        dy = y1 - y2
        x3 = x2 - dy
        y3 = y2 - dx
        x4 = x1 - dy
        y4 = y1 - dx
        x5 = x4 + floor((dx - dy) / 2)
        y5 = y4 - floor((dx + dy) / 2)
        paint.drawline(x1,y1,x2,y2)
        paint.drawline(x2,y2,x3,y3)
        paint.drawline(x4,y4,x1,y1) 
        pythagorastree(x4, y4, x5, y5, depth +1)
        pythagorastree(x5, y5, x3, y3, depth +1)
