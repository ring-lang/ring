# Form/Window Controller - Source Code File

load "frameView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:frameController)
		exec()
	}
}

class frameController from windowsControllerParent

	oView = new frameView
