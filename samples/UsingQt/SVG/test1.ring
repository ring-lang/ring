load "guilib.ring"

app = new QApp {
	win = new QWidget() {
		setWindowTitle("Show SVG File")
		resize(800,600)
		s = new QSvgWidget(win) {
			setStyleSheet("background-color:white;")
			loadfile("shapes.svg")
		}
		show()
	}
	exec()
}