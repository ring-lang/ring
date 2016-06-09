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
		show()
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
				setrowcount(0) setcolumncount(4)
				setselectionbehavior(QAbstractItemView_SelectRows)
				setHorizontalHeaderItem(0, new QTableWidgetItem("ID"))
				setHorizontalHeaderItem(1, new QTableWidgetItem("Date"))
				setHorizontalHeaderItem(2, new QTableWidgetItem("Time"))
				setHorizontalHeaderItem(3, new QTableWidgetItem("Weight"))
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
	}		
	exec()
}

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
		oCon.exec("create table weighthistory (id integer primary key, f_date varchar(10), f_time varchar(8), f_weight integer)")
	else
		See "We Already have the database" + nl
	ok

Func pAddWeight
	cWeight = text1.text()
	pAddRecord(cWeight)
	See "Record Added!" + nl

Func pAddRecord cWeight
	query = new QSqlQuery( )
	cStr = "insert into weighthisotry (if_date,f_time,f_weight) values ('%f1','%f2',%f3)"
	cStr = substr(cStr,"%f1",date())
	cStr = substr(cStr,"%f2",time())
	cStr = substr(cStr,"%f3",cWeight)
	oCon.exec(cStr)
	
	
