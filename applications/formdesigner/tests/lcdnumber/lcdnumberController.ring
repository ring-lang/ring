# Form/Window Controller - Source Code File

load "lcdnumberView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:lcdnumberController)
		exec()
	}
}

class lcdnumberController from windowsControllerParent

	oView = new lcdnumberView
