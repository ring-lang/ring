# Form/Window Controller - Source Code File

load "lcdnumberView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:lcdnumberController)
		exec()
	}
}

class lcdnumberController from windowsControllerParent

	oView = new lcdnumberView
