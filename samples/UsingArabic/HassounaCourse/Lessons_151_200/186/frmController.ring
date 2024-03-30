# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView
	load "hassounaLib.ring"
	t = new FormTools( oView.win )
	t.center()


	func btnShow_Click()
		oView.tbl.setColumnCount(2)
		oView.tbl.setRowCount(5)
		oView.tbl.SetSelectionBehavior(1)
		colHeader1 = new qTableWidgetItem("Number")
		colHeader2 = new qTableWidgetItem("Name")
		oView.tbl.setHorizontalHeaderItem(1, colHeader1)
		oView.tbl.setHorizontalHeaderItem(2, colHeader2)
		oView.tbl.setColumnWidth(1,200)
		oView.tbl.setColumnWidth(2,200)
		spaces = new qTableWidgetItem("1           ")
		oView.tbl.setVerticalHeaderItem(1, spaces)
		oView.tbl.setEditTriggers(0)

		r1c1 = new qTableWidgetItem("111")
		r1c2 = new qTableWidgetItem("Ahmed")

		r2c1 = new qTableWidgetItem("222")
		r2c2 = new qTableWidgetItem("Adel")

		r3c1 = new qTableWidgetItem("333")
		r3c2 = new qTableWidgetItem("Amr")

		r4c1 = new qTableWidgetItem("444")
		r4c2 = new qTableWidgetItem("Ehab")

		r5c1 = new qTableWidgetItem("555")
		r5c2 = new qTableWidgetItem("Omar")

		oView.tbl.setItem( 1 , 1 , r1c1 )
		oView.tbl.setItem( 1 , 2 , r1c2 )
		oView.tbl.setItem( 2 , 1 , r2c1 )
		oView.tbl.setItem( 2 , 2 , r2c2 )
		oView.tbl.setItem( 3 , 1 , r3c1 )
		oView.tbl.setItem( 3 , 2 , r3c2 )
		oView.tbl.setItem( 4 , 1 , r4c1 )
		oView.tbl.setItem( 4 , 2 , r4c2 )
		oView.tbl.setItem( 5 , 1 , r5c1 )
		oView.tbl.setItem( 5 , 2 , r5c2 )




	func btnShow2_Click()
		tbl = new DataTable()
		
		tbl.AddColumn("Employee_Number")
		tbl.AddColumn("Employee_Name")

		tbl.AddRow(["1","Ahmed"])
		tbl.AddRow(["1","Adel"])
		tbl.AddRow(["3","Mahmoud"])
		tbl.AddRow(["4","Amr"])
		tbl.AddRow(["5","Ehab"])

		tbl.LoadInto(oView.tbl)

