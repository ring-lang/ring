# trying to discover a bug!

mylist = ["v1","v2","v3","v4","v5"]

test()
func test 
	o1 = new myclass
	{
		myobj = point()  {
			x = 10
			y = 20
			v1 = 50	
			type ="3d"
			t = getattribute(self,"type")
		}
	}

class myclass
	myobjs = []
	func point
		myobjs + new point
		return myobjs[len(myobjs)]

class objsbase
	test1 test2
	addattribute(self,mylist)

	func checkattribute cValue
		r = getattribute(self,cValue)
		if r != Null AND R != "NULL"
			cCode += r
		ok

class point from objsbase
	x y z 
	src type 
	ccode = ""
	func setx
		see "nice" + nl
	
	func settype cValue
		ccode += cValue

	func braceend
		see " braceend!" + nl
		 checkattribute(:gooo)
