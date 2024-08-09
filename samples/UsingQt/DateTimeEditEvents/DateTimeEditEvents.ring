load "guilib.ring"

a = new QApp {

	w = new QWidget() {
		resize(400,400)
		setWindowTitle("QDateTimeEdit Events")
		d = new QDateTimeEdit(w) {
			move(150,150)
			setDateChangedEvent("? :DateChanged")
			setDateTimeChangedEvent("? :DateTimeChanged")
			setTimeChangedEvent("? :TimeChanged")
		}

		show()
	}
	exec()
}	
