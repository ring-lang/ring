# Form/Window Controller - Source Code File

load "videowidgetView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:videowidgetController)
		exec()
	}
}

class videowidgetController from windowsControllerParent

	oView = new videowidgetView

	func PlayVideo
		oView.playerVideoWidget1.play()
