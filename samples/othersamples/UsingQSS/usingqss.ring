load "guilib.ring"


C_COFFEE_STYLE = read("coffee.qss")

new qApp {

	win = new qWidget() {
		setWindowtitle("Using QSS File")
		setStylesheet(C_COFFEE_STYLE)
		resize(600,600)
		for t = 1 to 10
			new qPushbutton(win) {
				setText("Test" + t) move(10,40*t) resize(200,30)
			}
			new qLineEdit(win) {
				setText("Test" + t) move(250,40*t) resize(200,30)
			}
		next
		show()
	}
	exec()
}
