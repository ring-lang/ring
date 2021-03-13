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

	# We need this to support closing the Application during data loading.
		oFilter = new QAllEvents(oView.win)
		oFilter.setCloseevent(Method(:CloseApp))
		oView.win.installeventfilter(oFilter)

	# Window Properties 
		oView.chessTableWidget.setEditTriggers(False)
		oView.chessTableWidget.selectRow(0)
		hidePieces()
		oView.Win.showMaximized()

	# Load the Data
		oView.statusbar1.showmessage("Loading the data...",0)
		loadTheData()
		oView.statusbar1.showmessage("Records Count: " + (len(aList)-1),0)

func hidePieces

	oView.WK.hide()
	oView.WR.hide()
	oView.BK.hide()

func loadTheData

	nMax = len(aList)
	for t=2 to nMax
		for m=1 to 7
			oView.ChessTableWidget.setItem(t-1,m, QTableWidgetItem_new(""+aList[t][m]) )
		next 
		if t % 100 = 0 
			oApp.processevents()
		ok
		if t=2 newSelection() ok
	next  		

func newSelection 

	nIndex = oView.ChessTableWidget.currentrow() + 1

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

	# Draw the White King
		oView.WK { 
			WKX = nBoardX + ( (WKFile-1) * 50)
			WKY = nBoardY - ( WKRank * 50)
			move(WKX,WKY)
			show()
		}

	# Draw the White Rock
		oView.WR { 
			WRX = nBoardX + ( (WRFile-1) * 50)
			WRY = nBoardY - ( WRRank * 50)
			move(WRX,WRY)
			show()
		}

	# Draw the Black King
		oView.BK { 
			BKX = nBoardX + ( (BKFile-1) * 50)
			BKY = nBoardY - ( BKRank * 50)
			move(BKX,BKY)
			show()
		}

func closeApp

	oApp.Quit()
