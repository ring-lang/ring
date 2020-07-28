Load "guilib.ring"
New qapp {
        win1 = new qwidget() {
                setwindowtitle("Draw Circle")
                setgeometry(100,100,500,500)
                label1 = new qlabel(win1) {
                        setgeometry(0,0,800,600)
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
	painter = new qpainter() {
		begin(p1)		
			setpen(pen)
			drawEllipse(150,100,200,200)                      
		endpaint()
	}
	label1 {
		setpicture(p1)  
		show() 
	}
