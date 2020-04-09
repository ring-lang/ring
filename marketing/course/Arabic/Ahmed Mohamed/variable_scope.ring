/*
	Application	: Variable Scope
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

# Lexical Scoping (Scope Of Variable Is Based On Location)

x = 10			# Global Variable

func main
	y = 20 		# Local Variable
	? x
	test()
	? y
	new Person {	# Inside Object The Object Scope
		name = "MaNa"
		address = "Egypt"
		phone = "01115252857"
		? self
	}


func test
	? x




class Person
	name address phone
