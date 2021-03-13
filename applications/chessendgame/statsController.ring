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
