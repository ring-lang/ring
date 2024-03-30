# Form/Window Controller - Source Code File

load "frmProgramView.ring"
load "hassounalib.ring"
load "frmDepartmentController.ring"
load "frmEmployeeController.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmProgramController)
		exec()
	}
}

class frmProgramController from windowsControllerParent

	oView = new frmProgramView
	t = new FormTools(oView.win)
	t.center()
	t.icon("red_ring.png")

	func dept()
		openWindow("frmDepartmentController")

	func emp()
		openWindow(:frmEmployeeController)
