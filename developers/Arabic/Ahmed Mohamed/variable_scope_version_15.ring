/*
	Application	: Variable Scope Version 15
	Author		: Ahmed Mohamed
	Date		: 2019/11/7
*/

/*
	Variables Scope
		Three Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope 
*/

/*
	When We Write the variable name
		(Search) ----> found (Use)
			Not Found
		Assignment 	= ----> Define
		Class region 	= ----> Define
		Expression 	= ----> Error
*/

/*
	Search For Variables
		[1] Search In The Local Scope
		[2] Search In The Object Scope
				Inside braces 	{ }
				Inside methods
				Inside class region
		[3] Search In The Global Scope	

*/

new person { test() }


class person

	name = "ring" address phone
	
	func test
		new point {
			x = 10 y = 20
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
