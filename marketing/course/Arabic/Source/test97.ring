/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.20
*/

new person {
	name 	= "Mahmoud"
	address = "Egypt"
	phone   = "12143653263"
	print()
}

? new person { name = "Ahmed" address = "Egypt" phone   = "1214" }

myobj = new person { name = "Ibrahim" address = "Egypt" phone   = "1214" }

? myobj


class Person name address phone 
	func print 
		see 	"Name    : " + name + nl +
			"Address : " + address + nl +
			"Phone   : " + phone + nl
