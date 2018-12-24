# no problem

load "guilib.ring"

o1 = new test  { go() }
#o1.go()

class test

	
	func go

	myobj = new QSqlDatabase()
	myobj = myobj.addDatabase("QSQLITE") 

# problem
/*

load "guilib.ring"

new test 

class test

	go()
	
	func go

		myobj = new QSqlDatabase()
		myobj = myobj.addDatabase("QSQLITE") 


*/	