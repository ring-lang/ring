# testing multiline comments

/* 
 o1 = new Person  {
	name = "mahmoud"
	address = "Egypt"
	phone = "123456"
	see "before test()" + nl
	test()
	see "after test()" + nl 
	print()
}

*/

test()
# test()

func test
	o2 = new Person {
		name = "ahmed"
		address = "Egypt"
		phone = "123456"
		print()
		return
	}
	

Class Person 
	name address phone
	func print
/*		see "before print()" + nl */
		see name + nl + address + nl + phone + nl
/*		see "after print()" + nl */

 