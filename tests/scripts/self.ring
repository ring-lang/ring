o1 = new Person { name = "mahmoud" address = "egypt" phone = "123456" }

o1.print()


func printobj c1
	see c1


Class Person
	name address phone
	func print
		see "name " + name + " address " + address + " phone " + phone
		see " my name is " + self.name
		printobj(self)

