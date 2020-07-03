# Form/Window Controller - Source Code File

load "statusbarView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:statusbarController)
		exec()
	}
}

class statusbarController from windowsControllerParent

	oView = new statusbarView
