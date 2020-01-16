load "guilib.ring"

see "one" + nl
new test

func create
	see "four" + nl
	return new point

class test

	see "two" + nl
	myobj = null

	myfunc()

	func myfunc
		lcreate = false
		if not fexists("test.dddd")
			lcreate = true
		ok
		see "three" + nl
		myobj = create()
		see "five" + nl	
		myobj = new point	
		myobj = myobj.go("test")
		myobj = new QSqlDatabase()
		myobj = myobj.addDatabase("QSQLITE") 
		myobj.close()

class point x y z

	func go cmsg
		return new point
