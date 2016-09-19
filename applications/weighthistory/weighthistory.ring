# Application  : Weight History
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

Load "guilib.ring"


MyApp = new qApp
{	
	$ApplicationObject = "oApp"   # To be used when calling events
	oApp = new App
	exec()
	oApp.CloseDatabase()
}

class App

	cDir = currentdir() + "/"
	oCon 
	OpenDatabase()

	win1 = new qWidget()
	{
		setWindowTitle("Weight History")
		resize(600,600)
		layoutAdd = new qhboxlayout(win1)
		{
			label1 = new qLabel(win1) { setText("Weight") }
			text1 = new qlineedit(win1)
			btn1 = new qpushbutton(win1) { 
					setText("Add") 
					setClickEvent($ApplicationObject+".AddWeight()") 
			}
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
		self.ShowRecords()				
		show()	
	}
		
	Func OpenDatabase
		lCreate = False
		if not fexists(cDir + "weighthistory.db")
			lCreate = True
		ok
		oCon = new QSqlDatabase() 
		oCon = oCon.addDatabase("QSQLITE") {
			setDatabaseName("weighthistory.db")
			Open()			
		}
		if lCreate
			new QSqlQuery( ) {
				exec("create table weighthistory (id integer primary key, f_date varchar(10), f_time varchar(8), f_weight integer)")
				delete()
			}
		ok


	Func CloseDatabase
		oCon.Close()

	Func AddWeight
		cWeight = text1.text()
		AddRecord(cWeight)

	Func AddRecord cWeight
		new QSqlQuery( ) {
			cStr = "insert into weighthistory (f_date,f_time,f_weight) values ('%f1','%f2',%f3)"
			cDate = Date()
			cTime = Time()
			cStr = substr(cStr,"%f1",cDate)
			cStr = substr(cStr,"%f2",cTime)
			cStr = substr(cStr,"%f3",cWeight)
			exec(cStr)
			delete()
		}
		ShowRecord (cDate,cTime,cWeight)


	Func ShowRecord cDate,cTime,cWeight
		Table1 {
			nRows = rowCount()
			insertRow(nRows)
			item = new qTableWidgetItem(cDate)
			setItem(nRows,0,item)
			item = new qTableWidgetItem(cTime)
			setItem(nRows,1,item)
			item = new qTableWidgetItem(cWeight)
			setItem(nRows,2,item)
		}

	Func ShowRecords
		localTable = Table1    # copy attribute to use it when we uses braces { }	
		query = new QSqlQuery( ) {
			exec("select * from weighthistory")
			nRows = 0
			localTable.setrowcount(0)
			while movenext()
				localTable {
					insertRow(nRows)
					for x = 1 to 3
						cStr = query.value(x).tostring()
						item = new qTableWidgetItem(cStr)
						setItem(nRows,x-1,item)
					next
				}
				nRows++
			end
			delete()
		}
