/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 07/05/2018
*/

/*
	Varaibles Scope
		Three (3) Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope
*/

# Lexical scoping (scope of variable is based on location)

x = 10 			# Global Scope

func main 
	y = 10		# Local Scope
	? x
	test()
	? y
	/*o1=*/ new person {	# Inside the Object Scope
		name 	= "kh"
		address = "Dz"
		phone	= "+213xxxx"
		? self
	}
	/*? o1 */

func test
	? x

class person
		name address phone
