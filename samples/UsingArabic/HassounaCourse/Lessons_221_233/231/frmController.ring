# Form/Window Controller - Source Code File

load "frmView.ring"
load "hassounaLib.ring"

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
	oView.Timer1.stop()

	func MoveUp()
		oView.imgRocket{ 
			move( x() , y()-getRandom(1,10) ) 
		}
		oView.imgRocket2{ 
			move( x() , y()-getRandom(1,10) ) 
		}
		oView.imgRocket3{ 
			move( x() , y()-getRandom(1,10) ) 
		}
		if oView.imgRocket.y()<=0 and oView.imgRocket2.y()<=0 and oView.imgRocket3.y()<=0
			oView.Timer1.stop()
			oView.lblWin.SetText("No Win")
		but oView.imgRocket.y()<=0
			oView.Timer1.stop()
			oView.lblWin.SetText("Red Rocket Win")
			oView.lblWin.setStylesheet("color:red")
		but oView.imgRocket2.y()<=0
			oView.Timer1.stop()
			oView.lblWin.SetText("Blue Rocket Win")
			oView.lblWin.setStylesheet("color:blue")
		but oView.imgRocket3.y()<=0
			oView.Timer1.stop()
			oView.lblWin.SetText("Green Rocket Win")
			oView.lblWin.setStylesheet("color:darkgreen")
		ok  

	func StartMove() 
		oView {
			imgRocket.move( imgRocket.x() , 370 )
			imgRocket2.move( imgRocket2.x() , 370 )
			imgRocket3.move( imgRocket3.x() , 370 )
			lblWin.SetText("? Win")
			lblWin.setStylesheet("color:#000")
			Timer1.start() 
		}

