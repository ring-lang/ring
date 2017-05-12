# Form/Window Controller - Source Code File

load "treewidgetView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:treewidgetController)
		exec()
	}
}

class treewidgetController from windowsControllerParent

	oView = new treewidgetView
