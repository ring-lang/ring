load "guilib.ring"

oApp = new QApp {
	oWin = new QWidget() {
		setWindowTitle("Testing QLineEdit")
		move(100,100) resize(600,400)
		oLineEdit = new QLineEdit(oWin) {
			setInputMask("9999")
		}
		show()
	}
	exec()
}
