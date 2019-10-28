/*
	Application	: OOP Part 2 Version 2
	Author		: Ahmed Mohamed
	Date		: 2019/10/28
*/

new Person {
	name 	= "Ahmed"
	address = "Egypt"
	phone 	= "01208047712"
	print()
}

? new Person {name = "Mahmoud" address = "Egypt" phone = "01219158823"}

myObj = new Person {name = "Ibrahim" address = "Egypt" phone = "01219158823"}

? myObj

class Person name address phone
	func print
		see 	"Name 	: " + name + nl + 
			"Address : " + address + nl +
			"Phone 	: " + phone + nl 
