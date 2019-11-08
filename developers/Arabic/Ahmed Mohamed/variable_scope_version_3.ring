/*
	Application	: Variable Scope Version 3
	Author		: Ahmed Mohamed
	Date		: 2019/11/6
*/

/*
	Variables Scope
		Three Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope 
*/

# Conflict between the global variable and local scope

# First to way to solve this conflict using the main function

func main
	x = 10 y = 20		# x, y are local variables
	nSum = x + y		# nSum is local 
	? sum(5, 6)
	? nSum

func sum x, y		# x, y are local variable
	nSum = x + y	# nSum is expected to be local !
	return nSum
