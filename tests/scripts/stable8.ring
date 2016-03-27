test()
test()

func test
	o2 = new Person {
		name = "ahmed"
		address = "Egypt"
		phone = "123456"
		print()
	}
	

Class Person 
	name address phone
	func print
		see "before print()" + nl
		see name + nl + address + nl + phone + nl
		see "after print()" + nl

