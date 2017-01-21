Load "guilib.ring"

New qapp {
	win1 = new qwidget() {
		setwindowtitle("Rotate Text")
		setgeometry(100,100,500,500)
		label1 = new qlabel(win1) {
			setgeometry(0,0,800,600)
			settext("")
			myfilter = new qallevents(win1)
			myfilter.setMouseButtonPressevent("pClick()")
			installeventfilter(myfilter)
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
			myfont = font()
			myfont.setpointsize(20)
			setfont(myfont)
			rotate(x)
			drawtext(100,0,"welcome") 		 
		endpaint()
          }
	label1 {
		setpicture(p1)  
		show() 
	}

Func pClick
	win1 { setwindowtitle("Click Event") } 
