==========
RingWinLib
==========

A simple extension contains the RightToLeft(HWND) function
That can be used to have Right To Left window on Microsoft Windows

Example
=======

load "winlib.ring"	# Contains RightToLeft() function
load "guilib.ring" 
new QApp {
	new qWidget() {
		setwindowtitle("السلام عليكم ورحمة الله وبركاته")
		resize(800,600)
		if isWindows()
			righttoleft( winid() )
		ok
		show()
	}
	exec()
}


