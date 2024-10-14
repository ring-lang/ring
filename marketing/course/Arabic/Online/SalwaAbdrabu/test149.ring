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
