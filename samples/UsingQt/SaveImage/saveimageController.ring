# Form/Window Controller - Source Code File

load "saveimageView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:saveimageController)
		exec()
	}
}

class saveimageController from windowsControllerParent

	oView = new saveimageView

func save 
	oView {
		oRect = new QRect()
		oRect.Adjust(0,0,win.width(),win.height())
		win.grab(oRect).toImage().save("test.png","PNG",100)
		oRect = new QRect()
		oRect.Adjust(0,0,label1.width(),label1.height())
		label1.grab(oRect).toImage().save("test2.png","PNG",100)
	}
