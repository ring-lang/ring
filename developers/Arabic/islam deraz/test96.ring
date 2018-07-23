/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.28
*/
new test

new test2 { ? name }

o1 = new test3("Mahmoud")
o1.print()

new test4("Ahmed"){
print()
}

o4 = new test4("Belal")
o4 {
	# We are inside the object
	print()
	name = "Mostafa"
	print()
}

class test 
	# class region 
	? "Hello, World!"

class test2
	# any new variables ----> Attributes (object)
	name = "Hamza"

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

