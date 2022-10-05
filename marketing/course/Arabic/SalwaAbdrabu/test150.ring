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

# Conflict between Local variable and class attribute|object

/*
			(1) Use the main function
			(2) Try to avoid global variables
			(3) Start global variables with $ or g_

	To be more save
			(4) Use the self. in the class region
			(5) Or use @

*/


new test{  
		myTest()
		sayHello("Salwa")
		? @name

	}

class test 
	@name = "ring"
	func myTest
		? @name

	func sayHello p1
		name = "Hello,"+ p1
		? name
