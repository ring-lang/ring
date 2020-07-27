# Project : Archimedean spiral
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "guilib.ring"

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
        new qpainter() {
                begin(p1)
                setpen(pen)

        deg2rad = atan(1) * 4 / 180  
        screensize = 600                 
        turns = 5                
        halfscrn = screensize / 2    
        sf = (turns * (screensize - 100)) / halfscrn 
 
        for r = 0 to turns * 360 step 0.05
             x = cos(r * deg2rad) * r / sf 
             y = sin(r * deg2rad) * r / sf
            drawpoint(halfscrn + x, halfscrn - y)  
        next

        endpaint()
        }
        label1 { setpicture(p1) show() }
