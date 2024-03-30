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
	pb
	func f1()
		//oView.statusbar1.showMessage("New Message",0)
		this.pb = new ProgressBar(oView.win)
		oView.statusbar1.AddWidget(this.pb,0)

	func f2()
		this.pb.setValue(50)
