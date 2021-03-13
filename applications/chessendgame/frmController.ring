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

	aFile2Rank = [
		:a = 1,
		:b = 2,
		:c = 3,
		:d = 4,
		:e = 5,
		:f = 6,
		:g = 7,
		:h = 8
	]

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

func newSelection 
	nIndex = oView.ChessTableWidget.currentrow() + 1
	WKFile = aFile2Rank[aList[nIndex][1]]
	WKRank = aList[nIndex][2]
	WRFile = aFile2Rank[aList[nIndex][3]]
	WRRank = aList[nIndex][4]
	BKFile = aFile2Rank[aList[nIndex][5]]
	BKRank = aList[nIndex][6]

	oView.Board {
		nBoardX = x() 
		nBoardY = y() + height()
	}

	# Even (Black Cell) - Odd (White Cell)
		nSum = WKFile + WKRank 
		if nSum % 2 = 0 
			BoxColor = "BB" 
		else 
			BoxColor = "WB"
		ok

func closeApp
	oApp.Quit()
