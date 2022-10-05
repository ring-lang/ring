#================================================================
/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

new person {
	name    = "Mahmoud"
	address = "Egypt"
	phone   = "1231313"
	print()
}

? new person { name = "Ahmed" address = "Egypt" phone = "22344" }	

myobj = new person { name = "ibrahim" address = "Egypt" phone = "22344" }

? myobj

class person name address phone
	func print
		see "Name    :" + name    + nl +
	 	    "Address :" + address + nl +
		    "Phone   :" + phone   + nl
