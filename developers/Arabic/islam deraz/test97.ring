/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.28
*/
new person { 
	name    = "Hamza"
	address = "Egypt"
	phone   = "26102017"
	print()
}


? new person 
{name = "Belal" address = "Egypt" phone = "26102017"}

myobj =new person {name = "ABDALLA" address = "Egypt" phone = "26102017"}
? myobj

class person name address phone 
	func print 
	see 	"Name    : " + name + nl +
		"Address : " + address + nl +
		"Phone   : " + phone + nl
