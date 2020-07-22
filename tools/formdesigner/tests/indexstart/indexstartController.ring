# Form/Window Controller - Source Code File

load "indexstartView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:indexstartController)
		exec()
	}
}

class indexstartController from windowsControllerParent

	oView = new indexstartView

	func GetIndex
		oView {
			lineedit1.setText( ""+ listwidget1.currentRow() )
			lineedit2.setText( ""+ combobox1.currentindex() )
		}

	func SelectFirst 
		oView {
			listwidget1.setcurrentrow(1,3)
			combobox1.setcurrentindex(1)
		}
