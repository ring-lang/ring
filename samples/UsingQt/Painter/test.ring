load "guilib.ring"

new QApp {

	winmain = new QMainWindow() {

		setWindowTitle("Using QPainter & Drawing Images")
		resize(500,500)

	        win1 = new QWidget() {
	                setWindowTitle("Drawing")
	                setGeometry(100,100,1000,1000)	  
	                label1 = new QLabel(win1) {
				move(0,0)
				setAttribute(Qt_WA_TransparentForMouseEvents,True)
	                }	
		}

		scroll = new QScrollArea(winmain) {
			resize(800,600)
			setWidget(win1)
		 }

		draw()

		setCentralWidget(scroll)
	        show()

	}

        exec()

}

func draw

	image = new QPixmap("thering.bmp")
	p1 = new QPixMap2(1024,768)
	color = new QColor() {
		setRGB(0,0,255,255)
	}
	pen = new QPen() {
		setColor(color)
		setWidth(10)
	}
	painter = new QPainter() {
		begin(p1)
		drawpixmap(0,100,image)		
		setpen(pen)
		oFont = font()
		oFont.setpointsize(20)
		setFont(oFont)
		rotate(30)
		drawText(200,50,"welcome") 	
		path = new QPainterPath()
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
