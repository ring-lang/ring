load "guilib.ring"

new qapp {
        win1 = new qwidget() {
                setwindowtitle("Drawing Pixels")
                setgeometry(100,100,500,500)
                label1 = new qlabel(win1) {
                        setgeometry(10,10,400,400)
                        settext("")
                }
                new qpushbutton(win1) {
                        setgeometry(200,400,100,30)
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
	                for x = 1 to 100
	                       drawpoint(x,x)
	                next                      
                        endpaint()
                }
                label1 { setpicture(p1) show() }
