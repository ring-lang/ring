load "guilib.ring"
new qApp {

	oDesktop = new qDesktopWidget()

	new qWidget() {
		resize(400,400)
		setwindowtitle("Desktop Width:" + oDesktop.width() + 
			         " Desktop Height : " + oDesktop.height() )
		show()
	}

	exec()
}
