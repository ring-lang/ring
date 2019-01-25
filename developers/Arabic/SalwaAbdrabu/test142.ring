/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

/*
	Variables Scopes
		Three Scopes
		(1) Global Scope
		(2) Object Scope 
		(3) Local Scope 
*/
# Conflict between the global variable and local variable 

x= 10   y = 20                 // x,y are Global variables

nSum = x + y
		               // nSum is Global
?  sum(5,6)
? nSum 

func sum x,y                  // x,y are Local variables

	nSum = x + y          // nSum is expected to be Local !
	
	return nSum

