load "guilib.ring"

new qApp {
	new qWidget() {
		setwindowtitle("Hello, World!")
		resize(400,400)
		show()
	}
	exec()
}