# no problem

load "guilib.ring"

o1 = new test  { go() }

? :done

class test

	
	func go

	myobj = new QSqlDatabase()
	myobj = myobj.addDatabase("QSQLITE") 
	myobj.close()