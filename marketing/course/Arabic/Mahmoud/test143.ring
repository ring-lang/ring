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

# The First way to solve this conflict is using the Main function

func main
	x=10 y=20			# x,y are local variables 
	nSum = x + y 			# nSum is local 
	? sum(5,6)
	? nSum 

func sum x,y			# x,y are local variable  
	nSum = x+y 		# nSum is expected to be Local !
	return nSum 
