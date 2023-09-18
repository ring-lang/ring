# Form/Window Controller - Source Code File

load "mainView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:mainController)
		exec()
	}
}

class mainController from windowsControllerParent

	oView = new mainView

	aData 

	Reset() 

	func AddHours
		oView {
			nIndex = tableType.currentRow()
			nHours = 0 + txtHours.text()
			this.aData[nIndex][2] += 1
			this.aData[nIndex][3] += nHours 
			tableType.item(nIndex,2).setText(""+this.aData[nIndex][2])
			tableType.item(nIndex,3).setText(""+this.aData[nIndex][3])
			txtSum.setText(""+(this.aData[1][3]+this.aData[2][3]+this.aData[3][3]))
			nTotal=0
			for aRecord in this.aData  nTotal += aRecord[3] next 
			txtTotal.setText(""+nTotal)
		}


	func SelectedHoursChanged
		oView {
			txtHours.setText(listHours.item(listHours.currentrow()).text())

		}


	func Reset

		aData = [
			["Undergraduate - Lecture",0,0],
			["Undergraduate - Exercise",0,0],
			["Undergraduate - Lab",0,0],
			["Undergraduate - Project 1",0,0],
			["Undergraduate - Project 2",0,0],
			["Master - Lecture",0,0],
			["Master - Project 1",0,0],
			["Master - Project 2",0,0],
			["Master - Research Plan",0,0],
			["Master - Thesis",0,0],
			["PhD - Lecture",0,0],
			["PhD - Independent Study 1",0,0],
			["PhD - Independent Study 2",0,0],
			["PhD - Research Plan",0,0],
			["PhD - Thesis",0,0]
		]
	
		oView { 
			tableType { 
				setSelectionMode(QAbstractItemView_SingleSelection)
				setRowCount(0)
				addList(this.aData)
			}
			txtHours {
				setinputmask("99.99")
				setText("0")
			}
			txtSum { 
				setText("0")
				setEnabled(False)
			}
			txtTotal { 
				setText("0")
				setEnabled(False)
			}
		}


	func CloseApplication
		oView {
			win.close() 
		}
