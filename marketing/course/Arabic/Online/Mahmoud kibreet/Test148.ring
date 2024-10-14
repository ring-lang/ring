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

# Conflict between the class|object attribute and local variable

sayhello("Mahmoud Kibreet")
new test {mytest()}


func sayhello p1
name = ".Mr " + p1
? "Hello" + name

class test
	name = "Ring"

func mytest
	? name
