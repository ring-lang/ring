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
	load "hassounaLib.ring"
	t = new FormTools(oView.win)

	func btnGet_Click(){
		t.MsgBox( oView.textedit1.toHTML() )
	}

	func btnSet_Click(){
		myHTML = "<h1 style='color:red'>Welcome to egypt</h1><img src='ahmed.jpg' width='300' height='200'><hr><h2 style='color:blue'>Hello</h2>"
		oView.TextEdit1.setHTML(myHTML)
	}



