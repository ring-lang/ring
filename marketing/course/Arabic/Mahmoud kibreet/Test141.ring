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

# Lexical Scoping (Scope of varaible is based on location)


x = 10                   # Global Varaible

func main 
	y = 10		# Local Varaible
	? 10
	test()
	? y
new person {		# Inside the object scope
	name    = "Mahmoud"
	country = "Lebanon"
	Phone   = "+96171309876"
	? self	
	}

func test
	? x

class person
name address phone
