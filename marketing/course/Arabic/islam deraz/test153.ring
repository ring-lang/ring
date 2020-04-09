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
	
	name address phone 

	func test 
		new point  { 
			x=10 y=20
			this.hello()		
			? self 
		}

	func hello 
		? "Hello"

class point x y
