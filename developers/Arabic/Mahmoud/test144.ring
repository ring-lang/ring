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

# Conflict between the global variable and local variable 

# The second way is special mark with global variables 
# $global   g_   

x=10 y=20			# x,y are local variables 
$nSum = x + y 			# nSum is local 
? sum(5,6)
? $nSum 

func sum x,y			# x,y are local variable  
	nSum = x+y 		# nSum is expected to be Local !
	return nSum 
