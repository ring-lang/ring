#=============================================#
# Form/Window Controller - Source Code File
# 2021, Mahmoud Fayed <msfclipper@yahoo.com>
#=============================================#

load "frmView.ring"
load "data/dataset.ring"

import System.GUI

if IsMainSourceFile() {
	oApp = new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView

	oView.Win.showMaximized()

	hidePieces()

	oView.statusbar1.showmessage("Loading the data...",0)
	oView.chessTableWidget.setEditTriggers(False)
	loadTheData()
	oView.statusbar1.showmessage("Records Count: " + (len(aList)-1),0)

func hidePieces
	oView.WKWB.hide()
	oView.WKBB.hide()
	oView.WRWB.hide()
	oView.WRBB.hide()
	oView.BKWB.hide()
	oView.BKBB.hide()

func loadTheData

	oView.win.blocksignals(True)
	nMax = len(aList)
	for t=2 to nMax
		for m=1 to 7
			oView.ChessTableWidget.setItem(t-1,m, QTableWidgetItem_new(""+aList[t][m]) )
		next 
		if t % 1000 = 0 
			oApp.processevents()
		ok
	next  		
	oView.win.blocksignals(False)

func closeApp
	oApp.Quit()
