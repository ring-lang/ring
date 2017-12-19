# Project : Julia set
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "guilib.ring"

new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("Julia set")
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
                 setwidth(1)
        }
        paint = new qpainter() {
                  begin(p1)
                  setpen(pen)

        creal=-0.8
        cimag=0.156
        for v=-16 to 16
             for h=-64 to 64
                   x=h/40
                   y=v/20
                   for i=1 to 50
                         flag = 1
                         zreal=x*x-y*y+creal
                         zimag=x*y*2+cimag
                         if zreal*zreal>1000 flag = 0 loop ok
                         x=zreal
                         y=zimag
                  next 
                  if flag = 1
                     drawpoint(h+100,150-v)
                  ok
             next
        next

        endpaint()
        }
        label1 { setpicture(p1) show() }
