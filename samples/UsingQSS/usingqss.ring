load "guilib.ring"


C_COFFEE_STYLE = read("coffee.qss")

new QApp {

	win = new QWidget() {
		setWindowTitle("Using QSS File")
		setStyleSheet(C_COFFEE_STYLE)
		resize(600,600)
		for t = 1 to 10
			new QPushbutton(win) {
				setText("Test" + t) move(10,40*t) resize(200,30)
			}
			new QLineEdit(win) {
				setText("Test" + t) move(250,40*t) resize(200,30)
			}
		next
		show()
	}
	exec()
}
