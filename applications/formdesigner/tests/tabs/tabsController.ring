# Form/Window Controller - Source Code File

load "tabsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:tabsController)
		exec()
	}
}

class tabsController from windowsControllerParent

	oView = new tabsView
