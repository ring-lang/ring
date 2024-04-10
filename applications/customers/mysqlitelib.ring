#==================================#
# Customers Application
# Chokri <printhiver@gmail.com>
#==================================#

load "sqlitelib.ring"

oSQLite = null
 
# a list where the customers will be added (rows of table)
aCusts = [] 
# a list where the columns will be added (columns of tables)
aCols =[]
# return true if oSQLite not null
lConnected = false

func check_con

	if not lConnected
		see aLANGUAGE[:ERROR]+nl+
		aLANGUAGE[:USE] + " 'sqlite_connect_now()' in file main.ring"
		return 0
	ok

	return 1
	
func sqlite_run sql_statement
	return sqlite_execute(oSQLite, sql_statement)

# db_name is defined in main.ring file
# lConnected, set to false at the beginning of this file
# If we're connected, it'll be true 
func sqlite_connect_now

	if isnull(oSQLite)
		oSQLite = sqlite_init()
		sqlite_run("SET CHARACTER SET utf8")
		sqlite_open(oSQLite, db_name+".db")
	
		lConnected = true
	ok

	return lConnected

# get columns from a database table, and fill a list
func sqlite_get_cols select_stat

	stmt = sqlite_run(select_stat)

	if not isNull(stmt) and isList(stmt)
		for c in stmt
			for r in c
				add(aCols, r[1])
			next
			exit
		next

		return aCols

	ok

	return 0

# Execute any sqlite statement and return result if not null
func sqlite_get select_stat

	stmt = sqlite_run(select_stat)

	if not isNull(stmt) and isList(stmt)
		return stmt
	ok

	return 0
	
func sqlite_gener_id
	return sqlite_get("SELECT MAX(clid)+1 FROM clients")[1][1][2]

func getClCount
	return sqlite_get("SELECT COUNT(*) FROM clients")[1][1][2]

# fill the current table from a database table and initialize current row to 0
func sqlite_fill_table oTable,select

	if not check_con() bye ok

	if not isobject(oTable)
		msgBox(aLANGUAGE[:ERROR],
			aLANGUAGE[:OBJECT_IS_REQUIRED],"red")
		playSound("sound/warning-beep-1.wav")

		return 0
	ok
	if lower(classname(oTable)) != "qtablewidget" and
		lower(classname(oTable)) != "tablewidget"
		msgBox(aLANGUAGE[:ERROR],aLangUAGE[:USE_QTABLE],"red")
		playSound("sound/warning-beep-1.wav")

		return 0
	ok

	nRowIndex = 0
	aCusts =[] aCols =[]
	lEditMode = false
	lAdd      = false

	aCols = sqlite_get_cols(select) 
	aCusts = sqlite_get(select)

	oTable {
		setColumnCount(len(aCols))
		setRowcount(len(aCusts))
	
		for col=1 to columnCount()
			cell = new qTableWidgetItem(aCols[col])
			setHorizontalheaderitem(col-1, cell)
		next
		for row=1 to rowCount()
			for col=1 to columncount()
				cell = new qTableWidgetItem(aCusts[row][col][2])
				setItem(row-1, col-1, cell)
			next
		next
		if not isColumnHidden(columnCount()-1)
			hideColumn(columnCount()-1) ok
		if not isColumnHidden(columnCount()-2)
			hideColumn(columnCount()-2) ok
		# resizeColumnsToContents()
		# resizeRowsToContents()
		nSize1 = 90; nSize2=300
		nCol1 = 25; nCol2 = 25
		nUsed = (nSize1+nSize2)+(nCol1+nCol2)

		nVscroll = verticalscrollbar().height()
		nColWidth = ( (width()-nUsed)/(columnCount()-4) )+nVscroll

		setColumnwidth( 0, nSize1)
		setColumnwidth( 1, nSize2)
		setColumnwidth( 2, nColWidth)
		setColumnwidth( 3, nColWidth)
		setColumnwidth( 4, nCol1)
		setColumnwidth( 5, nCol2) 
		
		for x=0 to rowCount()
			setRowheight(x, 34)
		next

		setVerticalScrollBarPolicy(1)
		setHorizontalscrollbarpolicy(1)

		setCurrentCell(nRowIndex , 0)
		nRowIndex = currentRow()
	}

	lblCount.show()
	setTableHeader()

	return 1
	
func searchCl oTable

	cSearch = trim(txtSearch.text())
	if comboBox1.currentIndex() < 1 return ok
	cFilter = aComboCols[comboBox1.currentIndex()]
	
	if cSearch != ""
		if cFilter = aLANGUAGE[:FILTER]
			cSelect = "
			SELECT * FROM clients WHERE 
			clid LIKE '%"+cSearch+"%' OR 
			nom LIKE '%"+cSearch+"%' OR 
			adresse LIKE '%"+cSearch+"%' OR
			email LIKE '%"+cSearch+"%'
			"
		else 
			cSelect = "SELECT * FROM clients WHERE " + 
			cFilter + " LIKE '%"+cSearch+"%' "
		ok
		if len(sqlite_get(cSelect)) = 0 
			txtSearch.setStylesheet("background-color:none;color:black")
			if not checkAutoSearch.isChecked()
				msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:SEACH_NOT_FOUND],"red")
				playSound("sound/warning-beep-1.wav")
			ok

			return 0
		ok

		txtSearch.setStylesheet("background-color:green;color:white")
		sqlite_fill_table(oTable, cSelect)
		get_data(oTable) getCount()
		disableBtns(aControls)

		return 1
	else 
		txtSearch.setStylesheet("background-color:none;color:black")

		if not checkAutoSearch.isChecked()
			msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:SEACH_FIELD_EMPTY],"red")
			playSound("sound/warning-beep-1.wav")
		ok

		return 0
		
	ok
	
func searchCl2 oTable

	cSearch = trim(txtSearch.text())
	
	if checkAutoSearch.isChecked()

		disableBtns(aControls)

		if cSearch != ""

			if searchCl(oTable)
				txtSearch.setStylesheet("background-color:green;color:white")
				return 1
			else
				txtSearch.setStylesheet("background-color:none;color:black")
				return 0
			ok
	
			return 1 
		else
			txtSearch.setStylesheet("background-color:none;color:black")
			fill_data(oTable)
			disableBtns(aControls)

			return 0
		ok
	ok

func sqlite_close_now

	sqlite_close(oSQLite)

	oSQLite = null
