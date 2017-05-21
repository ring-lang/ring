# Form/Window Controller - Source Code File

load "frameView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:frameController)
		exec()
	}
}

class frameController from windowsControllerParent

	oView = new frameView
