#===========================================================================================#
# Sample : Custom QTableWidget that uses Method() to define custom events
# This sample is written to work in Ring 1.12
# We have a better version (Requires Ring 1.13) 
# URL : https://github.com/ring-lang/ring/blob/master/samples/other/customtablewidget2.ring
#===========================================================================================#

load "guilib.ring"

app = new QApp {
	win = new QWidget() {
		resize(800,600)
		setWindowTitle("Custom Table")
		table = CreateTable(win) 
		show()
	}
	exec()
}

func CreateTable oParent
	# We use openWindow() to be able to use the Method() function for events
		openWindow(:CustomTable)
		last_window().init(oParent)
	return last_window()

class CustomTable from QTableWidget 

	func init oParent
		super.init(oParent)
		resize(600,500)
		setrowcount(10) 
		setcolumncount(10)
		for x = 1 to 10
			for y = 1 to 10
				item1 = new qtablewidgetitem("R"+X+"C"+Y)
				setitem(x-1,y-1,item1)
			next
		next
		setitemchangedevent(Method(:change))

	func change 
		nRow = currentRow()
		nCol = currentColumn()	
		nMaxRow = rowCount()-1
		nMaXCol = columnCount()-1
		nCol++
		if nCol > nMaxCol
			nCol = 0
			nRow++
		ok
		if nRow > nMaxRow 
			nRow = 0
		ok
		setCurrentcell(nRow,nCol)

	func start
		# Keep this method empty
		# called by openWindow() before creating the GUI object
