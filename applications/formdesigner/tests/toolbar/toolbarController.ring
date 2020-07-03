# Form/Window Controller - Source Code File

load "toolbarView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:toolbarController)
		exec()
	}
}

class toolbarController from windowsControllerParent

	oView = new toolbarView
