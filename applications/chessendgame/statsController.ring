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

	C_RECORDSCOUNT = len(aDataSet)-1
 
	aStats = []

	# Window Properties 
		oView.statsTableWidget {
			setEditTriggers(False)
			selectRow(0)
			setSelectionMode(QAbstractItemView_SingleSelection)
		}

	# Load the Data 
		loadTheData()

	# Chart Control 
		oQuick = new qQuickWidget(oView.win) {
			move(450,10)
			engine().AddImportPath(exefolder()+"qml")
			setSource(new qURL("hello.qml") )
		}

func loadTheData

	# Count the Values 
		nMax = len(aDataSet)
		for t=2 to nMax
			aStats[aDataSet[t][7]] = 0 + aStats[aDataSet[t][7]] + 1
		next 
	# Add the data to the TableWidget 
		for t=1 to len(aStats)
			for m=1 to 2
				oView.statsTableWidget.setItem(t,m, QTableWidgetItem_new(""+aStats[t][m]) )
			next 
			oView.statsTableWidget.setItem(t,3, QTableWidgetItem_new(""+(aStats[t][2]/nMax*100)+"%") )
		next 

	writeQMLfile("Draw","Other",aStats["draw"],C_RECORDSCOUNT-aStats["draw"])

func WriteQMLfile cText,cText2,nValue,nValue2
	
	cFileContent = `
	
	import QtQuick 2.0
	import QtCharts 2.0
	
	ChartView {
	    width: 600
	    height: 600
	    antialiasing: true
	
	    PieSeries {
	        id: pieSeries
	        PieSlice { label: "#{f1}"; value: #{f3} }
	        PieSlice { label: "#{f2}"; value: #{f4} }
	    }
	}
	
	`
	cFileContent = substr(cFileContent,"#{f1}",cText)
	cFileContent = substr(cFileContent,"#{f2}",cText2)
	cFileContent = substr(cFileContent,"#{f3}",""+nValue)
	cFileContent = substr(cFileContent,"#{f4}",""+nValue2)

	write("hello.qml",cFileContent)
	

func NewSelection 
	oQuick.setupdatesenabled(False)
	nIndex = oView.statsTableWidget.currentrow() 
	writeQMLfile(aStats[nIndex][1],"Other",aStats[nIndex][2],C_RECORDSCOUNT-aStats[nIndex][2])
	oQuick.engine().clearcomponentcache()
	oQuick.setSource(new qURL("hello.qml") )
	oQuick.setupdatesenabled(True)
