# Form/Window Controller - Source Code File

load "thedateView.ring"

import System.GUI

if isMainSourceFile() {
	new App {
		styleFusion()
		openWindow(:thedateController)
		exec()
	}
}

class thedateController from windowsControllerParent

	oView = new thedateView
	oview.dt.setCalendarPopup(true)
	oView.dt.setDisplayFormat("dd-MM-yyyy")
	oView.dt.setDate( todayDate() )

	func TodayDate
                y = number( timelist()[19] )
                m = number( timelist()[10] )
                d = number( timelist()[6] )
                return new QDate() { setDate(y,m,d) }

