# Form/Window Controller - Source Code File

load "desktopscreenshotView.ring"

import System.GUI

if IsMainSourceFile() {
	oApp = new App {
		StyleFusion()
		openWindow(:desktopscreenshotController)
		exec()
	}
}

class desktopscreenshotController from windowsControllerParent

	oView = new desktopscreenshotView
	cStartupFolder = CurrentDir() + "/shots"

	func ScreenShot
		oView.win {
			x = x()	y = y()
			move(-500,-500)
			screen = windowhandle().screen()
		}
        	pixmap = screen.grabwindow(0,0,0,-1,-1)
        	image = pixmap.toimage()
		cFile = cStartupFolder+"/screenshot_"+substr(date(),"/","_")+
					"_"+substr(time(),":","_")+".png"
		image.save(cFile,"png",100)
		oView.win.move(x,y)

	func OpenFolder
		new QDesktopServices {
			OpenURL(new qURL("file:///"+this.cStartupFolder))
		}

	func CloseApp
		oView.win.close()
