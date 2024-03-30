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

	func ClickSound()
		new qMediaPlayer() {
			SetMedia( new qURL("click.mp3") )
			Play()
		}

	func welcome() ClickSound() msgInfo( "info" , "Welcome" )

	func hello() ClickSound() msgInfo( "info" , "Hello" )

	func hi() ClickSound() msgInfo( "info" , "Hi" )
