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
		class region ---> define
		expression = ---> error

*/

/*

	search for variables
		[1] search in the local scope
		[2] search in the object scope
				inside braces { }
				inside method		
				inside class region
		[3] search in the global scope
*/

new person { test() }

class person 
	# undefined variables ---> new attributes

	# we have global scope
	# we have object scope(self.)
	# we have local scope is the same as object scope

	mypoint= new point {	# braces change object scope
		x=10 y=20
		salary="xxxxx"
		? self
}

	name address phone 

	func test 
		# we have global, local & object scope

class point x y
