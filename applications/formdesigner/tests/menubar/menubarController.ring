# Form/Window Controller - Source Code File

load "menubarView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:menubarController)
		exec()
	}
}

class menubarController from windowsControllerParent

	oView = new menubarView

	func CloseWindow 
		oView.win.Close()
