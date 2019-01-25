/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

new test
new test2 { ? name }

o1 = new test3("Fatma")
o1.print()

new test4("Ring") {
	print()

}  

o4 = new test4("Ahmed")
o4 {
#		We Are Inside The Object
	print()
	name = "Mohamed"
	print()

}
class test
	# class Region

	? "Hello World!"

class test2
	# Any Variable is ----> Attribute (in object(class))
	name = "Salwa"

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

