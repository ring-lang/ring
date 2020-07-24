# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView
	load "hassounaLib.ring"
	t = new FormTools(oView.win)
	t.center()
	oView.dt2.setDisplayformat("dd/MM/yyyy")
	oView.dt3.setDisplayformat("hh:mm:ss AP")
	oView.dt2.setCalendarpopup(true)
	oView.dt1.setDate( t.qDate_Now() )
	oView.dt1.setTime( t.qTime_Now() )



