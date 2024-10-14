/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.30
*/

new person {
	name 	= "Mahmoud"
	address = "Lebanon"
	Phone 	= "+961 71309876"
	print()
}

? new person {name = "Kibreet" address = "Lebanon" Phone = "+961 71309876"}

myobj = new person {name = "Ibrahim" address = "Lebanon" Phone = "+961 71309876"}

? myobj

class person name address phone
	func print
		see "Name    : " + name + nl +
		    "Address : " + address + nl +
		    "Phone   : " + phone

