load "guilib.ring"

app = new QApp {
	win = new QWidget() {
		setWindowTitle("Show SVG File")
		resize(400,300)
		s = new QSvgWidget(win) {
			setStyleSheet("background-color:white;")
			loadFile("shapes.svg")
		}
		show()
	}
	exec()
}
