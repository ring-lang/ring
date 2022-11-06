#=====================================================#
# Citations Prediction Application
# 2022, Mahmoud Fayed <msfclipper@yahoo.com>
#=====================================================#

load "datasetView.ring"
load "stdlibcore.ring"
load "sysdata.ring"

import System.GUI

if isMainSourceFile() { 
	new App
	{
		StyleFusion()
		open_window(:datasetController)
		exec()
	}
}

class datasetController from WindowsControllerParent

	oView = new datasetView
	loadData()

	func Select  { 
		if ! isMethod(self,:predict) { 
			return 
		}
		oView {
			nRow  = TableWidget1.currentrow()
			nRow++
		}
		# set Values
			predict().oView.txtAuthors.setText(""+aDataList[nRow][1])
			predict().oView.txtTitle.setText(""+aDataList[nRow][2])
			predict().oView.txtAbstract.setText(""+aDataList[nRow][3])
			predict().oView.txtOutput.setText("")
		oView.win.close()
	} 

	func Close  { 
		oView {
			win.close()
		}
	} 

	func loadData
		aRecords = aDataList 
		del(aRecords,1)
		oView.TableWidget1.addList(aRecords)
