# Form/Window Controller - Source Code File

load "frmHelloView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmHelloController)
		exec()
	}
}

class frmHelloController from windowsControllerParent

	oView = new frmHelloView

	oView{
		win.move(450,200)
	}

func sayHello()
	oView{
		lblMsg.setText( "Hello " + txtName.Text() )
	}
