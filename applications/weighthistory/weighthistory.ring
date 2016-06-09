load "guilib.ring"

cDir = currentdir() + "/"
oCon = NULL

pOpenDatabase() 

MyApp = new qApp
{
	win1 = new qWidget()
	{
		setWindowTitle("Weight History")
		resize(600,600)
		layoutAdd = new qhboxlayout(win1)
		{
			label1 = new qLabel(win1) { setText("Weight") }
			text1 = new qlineedit(win1) 
			btn1 = new qpushbutton(win1) { setText("Add") setClickEvent("pAddWeight()") }
			addwidget(label1)
			addwidget(text1)
			addwidget(btn1)
		}
		layoutData  = new qhboxlayout(win1)
		{
			Table1 = new qTableWidget(win1) {
				setrowcount(0)
				setcolumncount(3)
				setselectionbehavior(QAbstractItemView_SelectRows)
				setHorizontalHeaderItem(0, new QTableWidgetItem("Date"))
				setHorizontalHeaderItem(1, new QTableWidgetItem("Time"))
				setHorizontalHeaderItem(2, new QTableWidgetItem("Weight"))
                		}
			addWidget(Table1)
		}
		layoutClose = new qhboxlayout(win1)
		{
			btnclose = new qpushbutton(win1) { setText("Close") setClickEvent("MyApp.Quit()") }
			addwidget(btnClose)
		}
		layoutMain = new qvboxlayout(win1)
		{
			addlayout(layoutAdd)
			addLayout(LayoutData)
			addLayout(layoutClose)
		}
		setlayout(layoutMain)				
		pShowRecords()
		show()

	}		
	exec()
}

pCloseDatabase()

Func pOpenDatabase
	lCreate = False
	if not fexists(cDir + "weighthistory.db")
		lCreate = True
	ok
	oCon = new QSqlDatabase()
	oCon = oCon.addDatabase("QSQLITE")
	oCon.setDatabaseName("weighthistory.db")
 	oCon.open()
	if lCreate
		query = new QSqlQuery( )
		query.exec("create table weighthistory (id integer primary key, f_date varchar(10), f_time varchar(8), f_weight integer)")
	ok

Func pCloseDatabase
	oCon.Close()

Func pAddWeight
	cWeight = text1.text()
	pAddRecord(cWeight)

Func pAddRecord cWeight
	query = new QSqlQuery( )
	cStr = "insert into weighthistory (f_date,f_time,f_weight) values ('%f1','%f2',%f3)"
	cDate = Date()
	cTime = Time()
	cStr = substr(cStr,"%f1",cDate)
	cStr = substr(cStr,"%f2",cTime)
	cStr = substr(cStr,"%f3",cWeight)
	query.exec(cStr)
	pShowRecord (cDate,cTime,cWeight)

Func pShowRecord cDate,cTime,cWeight
	Table1 { 
		nRows = rowCount()-1
		insertRow(nRows)
		item = new qTableWidgetItem(cDate)
		setItem(nRows,0,item)
		item = new qTableWidgetItem(cTime)
		setItem(nRows,1,item)
		item = new qTableWidgetItem(cWeight)
		setItem(nRows,2,item)
	}
	
Func pShowRecords	
	query = new QSqlQuery( )
	query.exec("select * from weighthistory")
	nRows = 0
	Table1.setrowcount(0)
	while query.movenext()
		Table1 { 
			insertRow(nRows)
			for x = 1 to 3
				cStr = query.value(x).tostring()
				item = new qTableWidgetItem(cStr)
				setItem(nRows,x-1,item)
			next	
		}
		nRows++
	end
