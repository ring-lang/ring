load "guilib.ring"

new test

class test

	// Problem
	myobj = new QSqlDatabase()
	myobj = myobj.addDatabase("QSQLITE") 

	// Solution
	/*
	new QSqlDatabase() {
		myobj = addDatabase("QSQLITE") 
	}	
	*/