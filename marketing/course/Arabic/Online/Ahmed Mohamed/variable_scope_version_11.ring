/*
	Application	: Variable Scope Version 11
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
		Assignment = ----> Define
		Expression = ----> Error
*/

/*
	Search For Variables
		[1] Search In The Local Scope
		[2] Search In The Object Scope
		[3] Search In The Global Scope	

*/

x = 10 	# We have the global scope
test()
new person { test() }

func test
	# We have global & local

class person
	# undefined variable ---> new attributes
	
	# We global scope
	# We object scope (self.)
	# We have local scope is the same object scope

	mypoint = new point {	# Braces change object scope
		salary = "xxxx"
	}
	
	name address phone

	func test
		# We Have global, Object Scope & Local Scope

class point
