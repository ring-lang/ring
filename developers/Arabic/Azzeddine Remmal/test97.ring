#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 20.01.2018                  
####################################


new person {
	name 	= "Azzeddine"
	address = "Algiria"
	phone   = "12143653263"
	print()
}

? new person { name = "Azzeddine" address = "Algiria" phone   = "1214" }

myobj = new person { name = "Ibrahim" address = "Egypt" phone   = "1214" }

? myobj


class Person name address phone 
	func print 
		see 	"Name    : " + name + nl +
			"Address : " + address + nl +
			"Phone   : " + phone + nl
