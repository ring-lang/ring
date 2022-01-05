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
			predict().oView.txtAuthors.setText(aDataList[nRow][1])
			predict().oView.txtTitle.setText(aDataList[nRow][2])
			predict().oView.txtAbstract.setText(aDataList[nRow][3])
			predict().oView.txtOutput.setText("")
		oView.win.close()
	} 

	func Close  { 
		oView {
			win.close()
		}
	} 

	func loadData
		nMax = len(aDataList)
		oView {
			TableWidget1.setrowcount(nMax-1)
			for t = 1 to nMax step 1 { 
				nRow = t-1
				aRecord = aDataList[t]
				# check values
					for m = 1 to 4 step 1 { 
						if aRecord[m] = 0 { 
							aRecord[m] = ""
						}
					}
				# Add Record
					oAuthorsItem = new QTableWidgetItem(aRecord[1])
					oTitleItem = new QTableWidgetItem(aRecord[2])
					oAbstractItem = new QTableWidgetItem(aRecord[3])
					oTCItem = new QTableWidgetItem(""+aRecord[4])
					TableWidget1.setitem(nRow,1,oTitleItem)
					TableWidget1.setitem(nRow,2,oAuthorsItem)
					TableWidget1.setitem(nRow,3,oAbstractItem)
					TableWidget1.setitem(nRow,4,oTCItem)
			}
			TableWidget1.setcurrentcell(1,1)
		}
