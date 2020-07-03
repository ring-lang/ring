# Form/Window Controller - Source Code File

load "sliderView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:sliderController)
		exec()
	}
}

class sliderController from windowsControllerParent

	oView = new sliderView
