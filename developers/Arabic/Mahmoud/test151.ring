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
		Expression = ----> Error 
*/

/*
	Search for variables 
		[1] Search in the local scope 
		[2] Search in the object scope 
		[3] Search in the global scope 
*/

x = 10		# we have the global scope only 
test() 
new person { test() }

func test 
		# we have global & local 

class person 
	func test 
		# we have global, object scope & local scope 
