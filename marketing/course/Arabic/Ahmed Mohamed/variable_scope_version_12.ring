/*
	Application	: Variable Scope Version 12
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
	# undefined variable ---> new attributes
	
	# We global scope
	# We object scope (self.)
	# We have local scope is the same object scope

	name address phone

	mypoint = new point {	# Braces change object scope
		x = 10 y = 10
		salary = "xxxx"
		? self
	}
	


	func test
		# We Have global, Object Scope & Local Scope

class point x y
