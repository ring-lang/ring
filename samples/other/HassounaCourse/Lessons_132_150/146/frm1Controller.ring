# Form/Window Controller - Source Code File

load "frm1View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:frm1Controller)
		exec()
	}
}

class frm1Controller from windowsControllerParent

	oView = new frm1View

	func f2()
		load "frm2Controller.ring"
		open_window(:frm2Controller)

	func f3()
		load "frm3Controller.ring"
		open_window(:frm3Controller)

