# Form/Window Controller - Source Code File

load "frm2View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frm2Controller)
		exec()
	}
}

class frm2Controller from windowsControllerParent

	oView = new frm2View

	func btnClose_click()
		oView.win.close()
