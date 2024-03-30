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
	myLoad()
	oView{
		win.move(450,200)
	}

func myLoad()
	oview.lblmsg.settext("Ring Form Is Loaded ")

func sayHello()
	oView{
		lblMsg.setText( "Hello " + txtName.Text() )
	}

func myCenter()
	load "myLib.ring"
	myTool = new formTools( oView.win )
	myTool.center()
