# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView

	func test(){
		msg = new qMessageBox(oView.win){
			setWindowTitle("Title")
			setText("My Text")
			setInformativeText("My More Information Text")
			setStandardButtons( QMessageBox_yes | QMessageBox_no | QMessageBox_cancel | QMessageBox_close | QMessageBox_save | QMessageBox_open | QMessageBox_ignore | QMessageBox_abort )
			Show()
		}
	}
