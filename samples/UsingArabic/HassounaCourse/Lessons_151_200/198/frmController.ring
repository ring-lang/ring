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
	oview.dial1.setNotchesvisible(true)
	oView.button2.setEnabled(false)
	oView.button3.setEnabled(false)
	oView.button4.setEnabled(false)
	player

	func setVideo()
		player = new qMediaPlayer()
		player.setMedia( new qURL("drop.avi") )
		player.setVideoOutput( oView.videowidget1 )
		oView.button2.setEnabled(true)
		oView.button3.setEnabled(true)
		oView.button4.setEnabled(true)
	
	func play() player.play()

	func pause() player.pause()

	func stop() player.stop()

	func setVol() player.setVolume( oView.Dial1.value() )

