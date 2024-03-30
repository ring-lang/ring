# Form/Window Controller - Source Code File

load "frm3View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frm3Controller)
		exec()
	}
}

class frm3Controller from windowsControllerParent

	oView = new frm3View

	func btnClose_click()
		oView.win.close()
