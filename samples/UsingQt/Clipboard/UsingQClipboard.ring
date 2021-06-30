load "guilib.ring"

oApp = new qapp {
	w = new qWidget() {
		setWindowTitle("Using Clipboard - Press CTRL+V")
		resize(400,100)
		new qlineedit(w) {
			move(10,10)
			resize(200,30)
		}
		show()
	}
	oApp.clipboard().setText("I Love Ring Programming!",0)
	exec()
}
