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

sayHello("Salwa")
new test{  myTest()}

func sayHello p1
	name = "Hello,"+ p1
	? name

class test 
	name = "Ring"
	func myTest
		? name
