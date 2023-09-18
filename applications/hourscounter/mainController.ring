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

	aData = [
		["Undergraduate Lecture",0,0],
		["Undergraduate Exercise",0,0],
		["Undergraduate Lab",0,0],
		["Undergraduate Project 1",0,0],
		["Undergraduate Project 2",0,0],
		["Master Lecture",0,0],
		["Master Project 1",0,0],
		["Master Project 2",0,0],
		["Master Research Plan",0,0],
		["Master Thesis",0,0],
		["PhD Lecture",0,0],
		["PhD Independent Study 1",0,0],
		["PhD Independent Study 2",0,0],
		["PhD Research Plan",0,0],
		["PhD Thesis",0,0]
	]

	oView.TableWidget1.addList(aData)

	func AddHours
		oView {
			
		SelectedHoursChanged}


	func SelectedHoursChanged
		oView {
			txtHours.setText(listHours.item(listHours.currentrow()).text())

		}
