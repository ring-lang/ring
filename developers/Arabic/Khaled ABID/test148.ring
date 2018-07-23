/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 09/05/2018
*/

/*
	Varaibles Scope
		Three (3) Scopes
			[1] Global Scope
			[2] Object Scope
			[3] Local Scope
*/

# Conflict between class|object attribute and Local variable

sayhello("khaled")

new test { mytest() }

func sayhello p1
	name = "Mr. " + p1
	? "Hello " + name

class test 
	name = "Ring"

	func mytest
	? name
