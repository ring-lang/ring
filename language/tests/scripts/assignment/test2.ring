load "guilib.ring"

new test

? :done

class test

	myobj = new QSqlDatabase()
	myobj = myobj.addDatabase("QSQLITE") 
	myobj.close()