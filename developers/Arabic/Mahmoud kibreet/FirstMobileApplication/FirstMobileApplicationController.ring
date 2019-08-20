# Form/Window Controller - Source Code File

load "FirstMobileApplicationView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:FirstMobileApplicationController)
		exec()
	}
}

class FirstMobileApplicationController from windowsControllerParent

	oView = new FirstMobileApplicationView

func SayHello
	msginfo("MyApp","Hello,World!")

func CloseApp
	oView.win.close()
