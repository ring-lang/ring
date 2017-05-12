# Form/Window Controller - Source Code File

load "hyperlinkView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:hyperlinkController)
		exec()
	}
}

class hyperlinkController from windowsControllerParent

	oView = new hyperlinkView
