/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.04
*/

/*
	Variable Scopes
		Three Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope

*/

# Lexical Scoping (Scope of variable is based on location)


x = 10                   # Global Variable

func main 
	y = 10		# Local Variable
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
