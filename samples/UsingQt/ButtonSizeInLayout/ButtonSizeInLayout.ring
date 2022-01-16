load "guilib.ring"


app = new QApp {
	desktop = new QDesktopWidget()
	win = new QWidget() {
		setWindowTitle("Button Size")
		resize(800,600)
		btn = new QPushButton(win) {
			setText("Close")
			setClickEvent("win.close()")
			setMinimumWidth(desktop.Width() * 0.1)
			setMinimumHeight(desktop.Height() * 0.1)
		}
		layout = new QVBoxLayout() {
			addWidget(btn)
		}
		setLayout(layout)
		show()
	}
	exec()
}
