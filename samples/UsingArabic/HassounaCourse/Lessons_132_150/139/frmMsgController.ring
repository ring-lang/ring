# Form/Window Controller - Source Code File

load "frmMsgView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmMsgController)
		exec()
	}
}

class frmMsgController from windowsControllerParent

	oView = new frmMsgView

func showmsg()
	new MessageBox(oView.win) {
		setwindowtitle("My Title")
		settext("Hello... This is my message box")
		show()
	}
