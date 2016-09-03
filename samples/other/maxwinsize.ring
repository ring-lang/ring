load "guilib.ring"
new qApp {

	win1 = new qWidget() {
		new qPushButton(win1) {
			resize(200,200)
			settext("Info")
			setclickevent(' win1 { setwindowtitle("Width: " +  width() + " Height : " +  height() ) }   ')
		}
		showMaximized()
	}

	exec()
}
