# Form/Window Controller - Source Code File

load "webviewView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:webviewController)
		exec()
	}
}

class webviewController from windowsControllerParent

	oView = new webviewView
