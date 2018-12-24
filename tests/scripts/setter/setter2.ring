o1 = new test
o1.name = "Test"
see o1.name + nl
o1.name = 100
see o1.name + nl
o1.name = ["wow",2]
see o1.name 
o1.name = new point
see o1.name

class test
	name 
	func setname x
		see "Setter!" + nl
		name = x

class point x=10 y=20 z=30