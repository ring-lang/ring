/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.29
*/

/*
	Variables Scope 
		Three Scopes 
			[1] Global Scope 
			[2] Object Scope 
			[3] Local Scope 

*/

/*	
	When we write the variable name 
		(Search) ----> Found (Use) 
			Not Found 
		Assignment = ----> Define 
		class region ----> Define 
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

	name address phone 

	func test 
		new point {
			x=10 y=20
			this.hello()
			? self
		}

	
	func hello
		? "Hello"

class point x y
