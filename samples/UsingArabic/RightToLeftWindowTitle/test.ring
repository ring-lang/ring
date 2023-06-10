load "winlib.ring"	# Contains RightToLeft() function
load "guilib.ring" 
new QApp {
	new qWidget() {
		setwindowtitle("السلام عليكم ورحمة الله وبركاته")
		resize(800,600)
		righttoleft( winid() )
		show()
	}
	exec()
}
