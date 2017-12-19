# Form/Window Controller - Source Code File

load "dialView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:dialController)
		exec()
	}
}

class dialController from windowsControllerParent

	oView = new dialView
