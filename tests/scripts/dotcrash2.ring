/*
	Bug ID : 192
	Description : Using .. in events code (syntax error)
	Status : Fixed
*/

load "guilib.ring"

new qApp {
	win  = new qWidget() {
		resize(400,400)
		new qPushButton (win) {
			settext("close")
			setClickevent("win..close()")
			
		}
		show()
	}

	exec()
}