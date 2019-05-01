load "guilib.ring"

new qApp {
	win = new qWidget() { 
		move(20,20)
		resize(400,400)
		setWindowTitle("Form1")
		setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_CustomizeWindowHint) 
		show()
	}
	exec()
}
