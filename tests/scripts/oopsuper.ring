myobj = new Manager
see "Welcome" + nl

see myobj.one()
see myobj.two()
see myobj.three()
see myobj.four()
see myobj.test()

Class Human
	color gender
	func one see "one" + nl
	func test 
		# super.test() # USING THIS LEAD TO Runtime Error
		see "test from human" + nl

Class Person from Human
	name 
	func two see "two" + nl
	func test 
		super.test()
		see "test from person" + nl
	
Class Employee from Person
	Job
	func three see "three" + nl
	func test 
		super.test()
		see "test from employee" + nl
	
Class Manager from Employee
 	Department
 	func four see "four" + nl
 	func test 
 		super.test()
 		see "test from manager" + nl
 		
	