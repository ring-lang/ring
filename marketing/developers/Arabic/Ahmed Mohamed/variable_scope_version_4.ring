/*
	Application	: Variable Scope Version 4
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

# Conflict between the global variable and local scope

# The second way is using special mark with global variables
# $global	g_

x = 10 y = 20		# x, y are local variables
$nSum = x + y		# nSum is local 
? sum(5, 6)
? $nSum

func sum x, y		# x, y are local variable
	nSum = x + y	# nSum is expected to be local !
	return nSum
