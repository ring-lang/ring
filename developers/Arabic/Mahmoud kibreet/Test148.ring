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

# Conflict between the class|object attribute and local varaible

sayhello("Mahmoud Kibreet")
new test {mytest()}


func sayhello p1
name = ".Mr " + p1
? "Hello" + name

class test
	name = "Ring"

func mytest
	? name
