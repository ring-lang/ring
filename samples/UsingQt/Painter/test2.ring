load "guilib.ring"

new QApp {

	winmain = new QMainWindow() {

		setWindowTitle("Using QPainter to draw an image many times!")
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

	image = new QPixmap("thering2.bmp")
	p1 = new QPixMap2(1024,768)
	painter = new QPainter() {
		begin(p1)
		for t=1 to 4
			for t2=1 to 3
				drawPixmap((t2-1)*image.width(),(t-1)*image.height(),image)		
			next
		next
	}

	label1 {
		resize(1024,768)
		setPixmap(p1)
		show() 
	}
