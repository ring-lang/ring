# Just a simple program to test Ring2EXE Tool!
# Using RingQt

load "guilib.ring"

new qApp {
	new qWidget() {
		setwindowtitle("Hello, World!")
		resize(400,400)
		show()
	}
	exec()
}
