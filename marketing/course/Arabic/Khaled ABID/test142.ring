/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 08/05/2018
*/

/*
	Varaibles Scope
		Three (3) Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope
*/

# Conflict between global variable and local variable

x=10 y=20		# x,y are global variable
nSum = x + y		# nSum is global variable
? sum(5,6)
? nSum

func sum x,y		# x,y are local variable
	nSum = x+y	# nSum is expected to be local !
	return nSum
