# Form/Window Controller - Source Code File

load "frmTestTableView.ring"
load "mysql_hassouna.ring"
db_name="mydbfromring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmTestTableController)
		exec()
	}
}

class frmTestTableController from windowsControllerParent

	oView = new frmTestTableView

	func my()
		mysql_connect_now()
		mysql_fill_table( oView.Tablewidget1 , "select * from employee" )
		mysql_fill_combobox( oView.ComboBox1 , "employee" , "empname" )
