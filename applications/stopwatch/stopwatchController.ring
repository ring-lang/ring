# Form/Window Controller - Source Code File

# StopWatch Application
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

load "stopwatchView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:stopwatchController)
		exec()
	}
}

class stopwatchController from windowsControllerParent

	oView = new stopwatchView {
		WatchTimer.stop()
		ButtonPause.setEnabled(False)
	}

	lStart = False
	lStop  = False 

	func StartWatch
		oView {
			if ! this.lStart
				this.lStart = True 
				WatchTimer.start()
				ButtonStart.setText("Restart")
				ButtonPause.setEnabled(True)
			else
				WatchTimer.stop()
				watch.display(0)
				WatchTimer.start()
			ok
		}
	
	func PauseWatch
		oView {
			if ! this.lStop 
				this.lStop = True 
				watchTimer.stop()
				ButtonPause.SetText("Continue")
			else 
				this.lStop = False 
				watchTimer.Start()
				ButtonPause.SetText("Pause")

			ok
		}

	func ExitWatch
		oView.win.close()
	
	func WatchTimerEvent
		oView.watch { display( value() + 1 ) }
