# Form/Window Controller - Source Code File

load "manylistitemsView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:manylistitemsController)
		exec()
	}
}

class manylistitemsController from windowsControllerParent

	oView = new manylistitemsView

	func Start 
		super.start()
		oView {
			nClock = clock()
			listwidget1 {
				for x = 1 to 20000
					additem("Item " + x)
				next	
			}
			win.setWindowtitle("Adding 20000 items in " +
				(clock()-nClock)/clockspersecond() + " seconds")
		}		
		
