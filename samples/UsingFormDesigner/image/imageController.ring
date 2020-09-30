# Form/Window Controller - Source Code File

load "imageView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:imageController)
		exec()
	}
}

class imageController from windowsControllerParent

	oView = new imageView
