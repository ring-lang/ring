mylist = new List
mylist.aList = [1,2,3,4,5]

mylist.each( "
see (x*x) + nl
 " )

mylist.inside (" 
	x = 10 
	y = 20
	print()
")

oPerson = new person
oPerson.inside ("
	cName = 'Mahmoud'
	cAddress = 'egypt'
	cPhone = '123456'
")

see "name : " + oPerson.cname + nl

inside(oPerson,"see cName + nl")

func inside obj,cCode
	obj.inside( cCode )

Class List

	aList = []
	x = 5
	y = 5

	func each	cCode
		for x in aList
			eval(cCode)
		next

	func inside cCode
		eval(cCode)

	func print
		see "x = " + x + nl
		see "y = " + y + nl

class Person
	cName = ""
	cAddress =""
	cPhone = ""
	func inside cCode
		eval(cCode)
