load "lightguilib.ring"

new QApp {

	winmain = new QMainWindow() {

		setWindowTitle("Using QPainter & Drawing Text")
		resize(500,500)

		win1 = new QWidget() {
	    		setWindowTitle("Drawing")
			setGeometry(100,100,2000,30100)	  
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

	p1 = new QPixMap2(2024,768*90)

	color  = new QColor() { setRGB(0,0,255,255)          }
	pen    = new QPen()   { setColor(color) setWidth(3)  }

	color2 = new QColor() { setRGB(0,255,0,255)          }
	pen2   = new QPen()   { setColor(color2) setWidth(3) }

	color3 = new QColor() { setRGB(255,128,255,255)      }
	pen3   = new QPen()   { setColor(color3) setWidth(3) }

	aPens = [pen,pen2,pen3,pen2,pen,pen3,pen,pen2,pen3,pen2,pen,pen2,pen3]

	painter = new QPainter() {

		begin(p1)

		oFont = font()
		oFont.setpointsize(16)
		setFont(oFont)

		for m=1 to 1000
			for t=1 to 12
				setpen(aPens[t])
				drawText(145*t,30*m,"Hello " + m) 
			next	
		next	

	}

	label1 {
		resize(2024,768*90)
		setpixmap(p1)
		show() 
	}
