/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 10/05/2018
*/

/*
	Varaibles Scope
		Three (3) Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope
*/

/*	
	When we write the variable name 
		(Search) ----> Found (Use) 
			Not Found 
		Assignment = ----> Define 
		Expression = ----> Error 
*/

/*	
	When we write the variable name 
		(Search) ----> Found (Use) 
			Not Found 
		Assignment = ----> Define 
		Expression = ----> Error 
*/

/*
	Search for variables 
		[1] Search in the local scope 
		[2] Search in the object scope 
				Inside braces { }
				Inside method 
				Inside class region 
		[3] Search in the global scope 
*/

new person { test() }

class person 
	# undefined variables ---> new attributes 

	# We have global scope 
	# We have object scope (self.)
	# We have local scope is the same as object scope 

	mypoint = new point {	# braces change object scope 
		x=10 y=10
		salary = "xxxx"
		? self
	}

	name address phone 

	func test 
		# we have global, object scope & local scope 

class point x y
