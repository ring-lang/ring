/*
	Application	: OOP Part 2 Version 1
	Author		: Ahmed Mohamed
	Date		: 2019/10/28
*/

new test

new test2 { ? name }

o1 = new test3("Mahmoud")
o1.print()

new test4("Ring") {
	print()
}

o4 = new test4("Walled")

o4 {
	# We Are Inside The Object
	print()
	name = "Ali"
	print()
}

class test
	# Class Region
	? "Hello World"

class test2
	# Any New Variable ----> Attribute (Object)
	name = "Ahmed"

class test3
	name
	func init cName
		name = cName
	func print()
		? name
class test4
	name
	func init cName
		name = cName
		return self
	func print()
		? name
