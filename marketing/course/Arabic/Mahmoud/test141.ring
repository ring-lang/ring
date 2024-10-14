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

# Lexical Scoping (Scope of variable is based on location)

x = 10			# Global Variable 

func main 
	y = 10		# Local variable 
	? x
	test()
	? y
	new Person {	# Inside the Object Scope 
		name = "Mahmoud"
		address = "Egypt"
		phone = "xxxxxxxx"
		? self
	}
	

func test 
	? x

class person 
	name address phone 

	
