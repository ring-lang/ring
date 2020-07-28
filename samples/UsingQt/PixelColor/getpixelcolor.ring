load "guilib.ring"

new qApp {
	w = new qWidget() {
		setwindowtitle("Get Pixel Color")
		resize(400,400) 
		move(0,0)
		setstylesheet("background-color:red;")
		btn = new qpushbutton(w) {
			setclickevent("pixelcolor()")
		}
                show()
	}
	exec()
}

func PixelColor
	oapp = new qapp(0,null)  {
 		screen = w.windowhandle().screen()
  		pixmap = screen.grabwindow(0,0,0,-1,-1)
		image = pixmap.toimage()
		color = image.pixel(100,100)
		mycolor = new qcolor()
		mycolor.setrgba(color)
		see nl+"red : " + mycolor.red() + nl
		see "green : " + mycolor.green() + nl
		see "blue : " + mycolor.blue() + nl
	}
