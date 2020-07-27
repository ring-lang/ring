# Form/Window Controller - Source Code File

load "hyperlinkView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:hyperlinkController)
		exec()
	}
}

class hyperlinkController from windowsControllerParent

	oView = new hyperlinkView
