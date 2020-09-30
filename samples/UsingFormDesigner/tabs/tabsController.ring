# Form/Window Controller - Source Code File

load "tabsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:tabsController)
		exec()
	}
}

class tabsController from windowsControllerParent

	oView = new tabsView
