# Form/Window Controller - Source Code File

load "app1View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:app1Controller)
		exec()
	}
}

class app1Controller from windowsControllerParent

	oView = new app1View

	func SayHello
		msgInfo("Titre","Salut tous le monde")
	
	func CloseApp
		oview.win.close()
