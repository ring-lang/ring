# Form/Window Controller - Source Code File

load "addRingListView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:addRingListController)
		exec()
	}
}

class addRingListController from windowsControllerParent

	oView = new addRingListView

	aList = [["one","two"],
		     ["three","four"],
			 ["five","six"],
			 [7,8],
			 ["I","Love","Ring","Programming"]]
	
	oView.tablewidget1.addList(aList)

	aList = [["Number","Square"]]
	for t = 1 to 10
		aList + [ t, t*t]
	next

	oView.tablewidget1.addList(aList)
