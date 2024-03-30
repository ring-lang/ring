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
	t.center()


	func btnOpenWebsite_Click(){
		strURL = "https://www.hassouna-academy.com"
		oView.WebView1.loadPage( new qURL(strURL) )
	}

	func btnOpenGoogle_Click(){
		oView.WebView1.LoadPage( new qURL("http://www.google.com") )
	}

	func btnOpenHTML_Click(){
		strBrefixFiles = "file:///"
		strCurrentPath = CurrentDir()
		strCalc        = "/calc/HTML_Calc.html"
		strURL = strBrefixFiles + strCurrentPath + strCalc
		oView.webView1.LoadPage( new qURL( strURL ) )
	}


