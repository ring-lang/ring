/*
**	Application	: Ring lessons - Object Oriented Programming ( OOP )- Class Region .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 16 .
*/
? "----- Test1 -----"
new test1
o1 = new test1
# ---------
? "----- Test2 -----"
new test2 { ? name }
o2 = new test2
? o2.name
# ---------
? "----- Test3 -----"
new test3 { init("Kinan") print() }
o3 = new test3("Yazan")
o3.print()
o3 = new test3
o3.print()
# ---------
? "----- Test4 -----"
new test4("Firas") { print() }
o4 = new test4("Ring")
{	# We are Inside The object
	print()
	name = "Ring is Good"
	print()
}
# ---------
class test1
	# Class Region
	? "Hello World !"
class test2
	# Any New Variable ----> Attribute(Object)
	name = "Osama"

class test3
	name = "Mahmoud"
	func init cName
		name = cName
	func print
		? name

class test4
	name 
	func init cName
		name = cName
		return self
	func print
		? name
