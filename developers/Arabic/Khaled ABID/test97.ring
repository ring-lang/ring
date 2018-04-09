/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 09/04/2018
*/

new person { 
	name    = "khaled"
	address = "Algeria"
	phone   = "1234567890"
	print()
}

? new person { name = "omar"
	     address = "algiers" 
		phone = "1230" }

myobj = new person { name = "med"
	     address = "algiers" 
		phone = "1230" }

? myobj



class Person name address phone
	func print
		see "Name    : " + name + nl +
		    "Address : " + address + nl +
		    "phone   : " + phone + nl
