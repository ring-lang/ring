/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

new test

new test2 {? name}

o1 = new test3("Mahmoud")
o1.print()

new test4("Ring") {
	print()
}

o4 = new test4("Ahmed")
o4 {
	# we are inside the object
	print()
	name = "Ali"
	print()
}

class test
	# class region
	? "Hello, World!"
	
class test2
	# Any new variable ----> Attribute (object)
	name = "Mahmoud"

class test3
	name
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
