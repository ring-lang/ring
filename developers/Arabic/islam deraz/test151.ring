/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.14
*/

/*

	Variables Scope 
		Three scopes
			[1] Global scope
			[2] Object scope
			[3] Local scope	

*/

/*

	when we write the variable name 
		(search)   -----> found(use)
		not found
		assignment = ---> define
		expression = ---> error

*/

/*

	search for variables
		[1] search in the local scope
		[2] search in the object scope
		[3] search in the global scope
*/

x=10 		# we have the global scope only
test()
new person { test() }
func test 
		# we have global & local
class person 
	# undefined variables ---> new attributes

	# we have global scope
	# we have object scope(self.)
	# we have local scope is the same as object scope

	mypoint= new point {	# braces change object scope
		salary="xxxxx"
}

	name address phone 

	func test 
		# we have global, local & object scope

class point x y
