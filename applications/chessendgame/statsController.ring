#=============================================#
# Form/Window Controller - Source Code File
# 2021, Mahmoud Fayed <msfclipper@yahoo.com>
#=============================================#

load "statsView.ring"
load "data/dataset.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:statsController)
		exec()
	}
}

class statsController from windowsControllerParent

	oView = new statsView

	aStats = []

	# Window Properties 
		oView.statsTableWidget {
			setEditTriggers(False)
			selectRow(0)
			setSelectionMode(QAbstractItemView_SingleSelection)
		}

	# Load the Data 
		loadTheData()


func loadTheData

	# Count the Values 
		nMax = len(aList)
		for t=2 to nMax
			aStats[aList[t][7]] = 0 + aStats[aList[t][7]] + 1
		next 
	# Add the data to the TableWidget 
		for t=1 to len(aStats)
			for m=1 to 2
				oView.statsTableWidget.setItem(t,m, QTableWidgetItem_new(""+aStats[t][m]) )
			next 
			oView.statsTableWidget.setItem(t,3, QTableWidgetItem_new(""+(aStats[t][2]/nMax*100)+"%") )
		next 
