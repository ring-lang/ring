/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.04
*/

/*
	Varaible Scopes
		Three Scops
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope

*/

# Conflict between the global varaible and local varaible

# The first way to solve this conflict is using the main function

func main 
	x = 10 y = 20		# x,y are local varaibles
	nSum = x + y		# nSum is local
	? Sum(5,6)
	? nSum

func sum x,y		# x,y are local varaible
	nSum = x + y	# nSum is expected to be local !
	return nSum
