# Form/Window Controller - Source Code File

load "helloworldView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:helloworldController)
		exec()
	}
}

class helloworldController from windowsControllerParent

	oView = new helloworldView
