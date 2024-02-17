# Form/Window Controller - Source Code File

load "randomimageview.ring"
load "stdlib.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:randomimageController)
		exec()
	}
}

class randomimageController from windowsControllerParent

	oView = new randomimageView

	aImages = listAllFiles("images","jpg")

	TimerEvent()

	func CloseApp
		oView.win.close()
	
	func TimerEvent 
		if len(aImages) < 1 return ok
		nIndex = random(len(aImages))
		if nIndex=0 nIndex=1 ok
		cFile = AppFile(aImages[nIndex])
		oView.Image1 {
			image = new qpixmap(cFile)
                        setpixmap(image)
			image.delete()
		}

