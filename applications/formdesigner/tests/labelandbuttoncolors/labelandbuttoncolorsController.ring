# Form/Window Controller - Source Code File

load "labelandbuttoncolorsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:labelandbuttoncolorsController)
		exec()
	}
}

class labelandbuttoncolorsController from windowsControllerParent

	oView = new labelandbuttoncolorsView

	func CloseWindow
		oView.win.Close()
