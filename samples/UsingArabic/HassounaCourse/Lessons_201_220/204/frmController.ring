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
			setText("Question")
			setInformativeText("Do you want to delete?")
			setStandardButtons( QMessageBox_yes | QMessageBox_no | QMessageBox_close )
			r = exec()
			if r=QMessageBox_yes
				this.oView.lbl.setText("Yes")
			but r=QMessageBox_No 
				this.oView.lbl.setText("No")
			but r=QMessageBox_close
				this.oView.lbl.setText("Cancel")
			ok
		}
	}
