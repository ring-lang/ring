o = new myclass

o.getObject().x = 1000
o.getObject().y = 2000
o.getObject().z = 3000

? o.aList


class myclass

	aList = [ new point {x=10  y=20  z=30 },
		  new point {x=100 y=200 z=300}  ]

	func getObject
		return mymethod()

	func mymethod
		return aList[myindex()]
	
	func myindex
		return 2

class point x y z