/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.30
*/

new test

new test2 { ? name }

ol = new test3("Mahmoud")
ol.print()

new test4("Ring") { 
	print()
}

o4 = new test4("Ahmad") 

o4 {
# we are inside the object
	print()
	name = "Ali"
	print()
}

class test
	# class region
	? "Hello , World!"


class test2
	# Any new variable ---->Attribute (object) 
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
