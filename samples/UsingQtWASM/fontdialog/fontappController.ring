# Form/Window Controller - Source Code File

load "fontappView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:fontappController)
		exec()
	}
}

class fontappController from windowsControllerParent

	oView = new fontappView

	oFont = new QFontDialog() {
		setFontSelectedEvent(Method(:NewFont))
	}

	func SelectFont 

		oFont.show()

	func NewFont 

		cFont = oFont.selectedfont().tostring()

		oNewFont = new QFont("",0,0,0)
		oNewFont.fromstring(cFont)
		oView.Label1.setfont(oNewFont)

