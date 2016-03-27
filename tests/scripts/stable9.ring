test()
test()

func test
	o2 = new Person 
	o2.name = "ahmed"
	o2.address = "Egypt"
	o2.phone = "123456"
	o2.print()
	
Class Person 
	name address phone
	func print
		see "before print()" + nl
		see name + nl + address + nl + phone + nl
		see "after print()" + nl

