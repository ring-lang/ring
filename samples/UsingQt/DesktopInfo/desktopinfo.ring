load "guilib.ring"

new QApp {

	oDesktop = new QDesktopWidget()

	new QWidget() {
		resize(600,400)
		setwindowtitle( "Desktop Width:" + oDesktop.width() + 
				" Desktop Height : " + oDesktop.height() )
		show()
	}

	exec()

}
