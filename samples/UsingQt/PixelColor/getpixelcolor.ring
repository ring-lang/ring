load "guilib.ring"

oApp = new QApp {
	w = new QWidget() {
		setWindowTitle("Get Pixel Color")
		resize(400,400) 
		move(0,0)
		setStyleSheet("background-color:red;")
		btn = new QPushButton(w) {
			setClickEvent("pixelColor()")
		}
                show()
	}
	exec()
}

func pixelColor
	oApp {
 		screen = w.windowHandle().screen()
  		pixmap = screen.grabWindow(0,0,0,-1,-1)
		image = pixmap.toImage()
		color = image.pixel(100,100)
		oColor = new QColor()
		oColor.setRGBA(color)
		? "red : " + oColor.red() 
		? "green : " + oColor.green() 
		? "blue : " + oColor.blue() 
	}
