load "guilib.ring"

new qApp {
	win = new qWidget() { 
		move(800,500)
		resize(400,400)
		setWindowTitle("Form1")
		setstylesheet("background-color:purple;") 
		setWindowFlags(Qt_SplashScreen)
		show()
	}
	exec()
}
