Load "guilib.ring"
new qApp
{
	win1 = new qWidget()
	{
		resize(400,400)
		SetWindowTitle("Create SQLite Database")
		new qPushButton(win1)
		{
			resize(100,30)
			setText("Create")
			setClickEvent("pCreate()")

		}
		show()
	}

	exec()
}

Func pCreate
	cDir = currentdir() + "\"
	oCon = new QSqlDatabase()
	see ocon.isDriverAvailable('QSQLITE') + nl
	oCon = oCon.addDatabase("QSQLITE")
	see oCon.DriverName() + nl
	oCon.setDatabaseName("test.db")
 	SEE oCon.open() + NL
	see ocon.isopen() + nl
	see ocon.lasterror().text() + nl	 
	oCon.exec("create table person (id integer primary key, firstname varchar(20), lastname varchar(30), age integer)")
	
