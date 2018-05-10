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

	name="ring" address phone 

	func test 
		new point {
			x=10 y=20
			this.hello()
			? self
		}
		new local {
			name = "Test"
			? name
		}
		? name	
		? self.name

	func hello
		? "Hello"

class point x y

class local 
