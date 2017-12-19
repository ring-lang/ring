Load "guilib.ring"
New qapp {
        win1 = new qwidget() {
                setwindowtitle("Label and Button - Rotate Text")
                setgeometry(100,100,500,500)
                btn1 = new qPushButton(win1) {
			setgeometry(100,100,400,400)
			settext("")
                }
                label1 = new qlabel(win1) {
			setgeometry(100,100,400,400)
			settext("")
			setAttribute(Qt_WA_TransparentForMouseEvents,True)
                }

	draw()

                showMaximized()
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
			oFont = font()
			oFont.setpointsize(20)
			setfont(oFont)
			rotate(30)
			drawtext(0,0,"welcome") 		 
		endpaint()
                }
                label1 {
		setpicture(p1)  
		show() 
	      }
