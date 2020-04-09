/*
	Application	: Variable Scope Version 2
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

# Conflict between the global variable and local variable

x = 10 y = 20		# x, y are global variables
nSum = x + y		# nSum is global 
? sum(5, 6)
? nSum

func sum x, y		# x, y are local variable
	nSum = x + y	# nSum is expected tp be local !
	return nSum
