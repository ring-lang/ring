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
		Expression = ----> Error
*/
/*
	Search For Variables
		[1] Search in The Local Scope .
		[2] Search in The Object Scope .
		[3] Search in The Global Scope
*/
x = 10 		# We Have Global Scope Only .
test()
new person { test() }
Func test
			# We have Global & Local .
Class person
	# Undefined Variables	---> New Attributes .
	# We Have Global Scope 
	# We Have Object Scope
	# We Have Local Scope is The Same as Object Scope
	myPoint = new point { # Braces Change Object Scope
			salary = 10000
			 }
	name address phone
	Func test
			# We Have Global , Object Scope & Local Scope .
Class point x y
