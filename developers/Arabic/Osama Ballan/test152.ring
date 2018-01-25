/*
**	Application	: Ring lessons - Scope .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 25 .
*/

/*
	When We Write The Variable Name .
		(Search) ----> Found ( Use ) .
			Not Found	
		Assignment = ----> Define
		Class Region  ----> Define
		Expression  = ----> Error
*/
/*
	Search For Variables
		[1] Search in The Local Scope .
		[2] Search in The Object Scope .
				Inside Braces {}
				Inside Method
				Inside Class Region
		[3] Search in The Global Scope
*/
new person { test() }
Class person
	# Undefined Variables	---> New Attributes .
	# We Have Global Scope 
	# We Have Object Scope
	# We Have Local Scope is The Same as Object Scope
	name address phone
	myPoint = new point { # Braces Change Object Scope
			x = 15 y = 20
			salary = 10000
			? self
			 }
	Func test
			# We Have Global , Object Scope & Local Scope .
Class point x y
