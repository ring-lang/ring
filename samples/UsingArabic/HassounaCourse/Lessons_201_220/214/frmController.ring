# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView
	oView.HyperLink1.SetOpenExternalLinks(true)
	oView.HyperLink2.SetOpenExternalLinks(true)
