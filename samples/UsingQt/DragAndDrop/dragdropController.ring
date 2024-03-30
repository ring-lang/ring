# Form/Window Controller - Source Code File

load "dragdropView.ring"

import System.GUI

QAbstractItemView_NoDragDrop	= 0
QAbstractItemView_DragOnly	= 1	
QAbstractItemView_DropOnly	= 2
QAbstractItemView_DragDrop 	= 3
QAbstractItemView_InternalMove	= 4

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:dragdropController)
		exec()
	}
}

class dragdropController from windowsControllerParent

	oView = new dragdropView
	
	oView {
		listwidget1 {
			setmousetracking(True)
			setdragenabled(True)
			setacceptdrops(True)
			setdropindicatorshown(True)
			setdragdropmode(QAbstractItemView_InternalMove)
		}
		listwidget2 {
			setmousetracking(True)
			setdragenabled(True)
			setacceptdrops(True)
			setdropindicatorshown(True)
			setdragdropmode(QAbstractItemView_DropOnly)
		}
	}
