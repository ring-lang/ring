Load "guilib.ring"
New qapp {
	winmain = new qmainwindow() {
		setWindowTitle("Using QPainter & Drawing Images")
		resize(500,500)
	        win1 = new qwidget() {
	                setwindowtitle("Drawing")
	                setgeometry(100,100,1000,1000)	  
	                label1 = new qlabel(win1) {
				move(0,0)
				setAttribute(Qt_WA_TransparentForMouseEvents,True)
	                }	
		}
		 scroll = new qScrollArea(winmain) {
			resize(800,600)
			setwidget(win1)
		 }
		draw()
		setCentralWidget(scroll)
	        show()
	}
        exec()
}

Func draw
		image = new qpixmap("thering.bmp")
		p1 = new qPixMap2(1024,768)
                color = new qcolor() {
                        setrgb(0,0,255,255)
                }
                pen = new qpen() {
                        setcolor(color)
                        setwidth(10)
                }
                painter = new qpainter() {
			begin(p1)
			drawpixmap(0,100,image)		
			setpen(pen)
			oFont = font()
			oFont.setpointsize(20)
			setfont(oFont)
			rotate(30)
			drawtext(200,50,"welcome") 	
			path = new qPainterpath()
			path.moveTo(20, 80);
			path.lineTo(120, 130);
			path.cubicTo(80, 0, 150, 250, 280, 80);
			drawPath(path); 
                }
                label1 {
			resize(1024,768)
			setpixmap(p1)
			show() 
	      	}
