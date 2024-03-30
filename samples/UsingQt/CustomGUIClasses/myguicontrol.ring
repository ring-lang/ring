load "guilib.ring"

new qApp {
	MyWindow = new qWidget() {
		setWindowTitle("My Control") move(100,100) resize(500,500) show()
	}
	openWindowNoShow(:MyControl)
	Last_Window().oView.win.setParent(MyWindow)
	Last_Window().oView.win.move(10,10)
	Last_Window().Start()
	openWindowNoShow(:MyControl)
	Last_Window().oView.win.setParent(MyWindow)
	Last_Window().oView.win.move(10,100)
	Last_Window().Start()
	exec()
}

class myControl from WindowsControllerParent
	oView = new myView

class myView from WindowsViewParent 
	win = new qWidget() {
		lbl1 = new qLabel(win) { setText("My Control!") }
	}
