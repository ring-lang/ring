/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

new person {
	name   = "Mahmoud"
	adress ="Egypt"
	phone  = "1231313"
	print()
}

? new person { name = "Ahmed" adress = "Egypt" phone = "22344"}	

myobj = new person { name = "ibrahim" adress = "Egypt" phone = "22344"}

? myobj

class person name adress phone
	func print
		see "Name   :" + name + nl+
	 	    "Adress :" + adress + nl+
		    "Phone  :" + phone + nl
