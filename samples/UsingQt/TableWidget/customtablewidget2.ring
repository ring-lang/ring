#=========================================================================#
# Update to the sample CustomTableWidget.ring
# This update requires at least Ring 1.13
# Improvements: 
# 	(1) No need for the start() method in CustomTable() class  
#	(2) We create the object using the CreateObject() function 
#	    CreateObject() is a function defined in ObjectsLib.ring 
#	    And ObjectsLib.ring is called automatically by guilib.ring 
#=========================================================================#

load "guilib.ring"

app = new QApp {
	win = new QWidget() {
		resize(800,600)
		setWindowTitle("Custom Table")
		table = CreateObject(:CustomTable,win) 
		show()
	}
	exec()
}

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
