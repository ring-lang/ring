# Form/Window Controller - Source Code File

load "sliderView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:sliderController)
		exec()
	}
}

class sliderController from windowsControllerParent

	oView = new sliderView
