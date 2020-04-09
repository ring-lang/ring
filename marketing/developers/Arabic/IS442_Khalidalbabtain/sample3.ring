/*
	IS442 - khalid al-babtain
*/

Load "guilib.ring"
New qapp {
        win1 = new qwidget() {
                setwindowtitle("Drawing using QPainter")
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

Func draw
                p1 = new qpicture()
                color = new qcolor() {
                        setrgb(0,0,255,255)
                }
                pen = new qpen() {
                        setcolor(color)
                        setwidth(10)
                }
                new qpainter() {
                        begin(p1)
                        setpen(pen)
                        drawline(500,150,950,450)
                        drawline(950,550,500,150)
                        endpaint()
                }
                label1 { setpicture(p1) show() }
