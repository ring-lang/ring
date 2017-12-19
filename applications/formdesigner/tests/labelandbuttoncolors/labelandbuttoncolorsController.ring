# Form/Window Controller - Source Code File

load "labelandbuttoncolorsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:labelandbuttoncolorsController)
		exec()
	}
}

class labelandbuttoncolorsController from windowsControllerParent

	oView = new labelandbuttoncolorsView

	func CloseWindow
		oView.win.Close()
