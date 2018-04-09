/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 08/04/2018
*/

new test

new test2 {? name}

o1 = new test3("Khaled")
o1.print()

new test4("Ring") {
	print()
}

o4 = new test4("Ahmed") 

o4 {
	# we are inside the object
	print()
	name = "ali"
	print()
}


class test 
	# class region
	? "Hello, World!"

class test2
	# Any new variable ----> Attribute (Object)
	name = "khaled"

class test3
	name
	func init cName		# /func init (cName)
		name = cName
	func print
		? name

class test4
	name
	func init cName		# /func init (cName)
		name = cName
		return self
	func print
		? name
