load "guilib.ring"

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QCalendar")
		move(100,100) resize(400,400)
		new qCalendarwidget(w) {
			move(20,20) resize(350,350)
		}

		show()
	}
	exec()
}
