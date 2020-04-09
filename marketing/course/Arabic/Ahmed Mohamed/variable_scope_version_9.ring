/*
	Application	: Variable Scope Version 9
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

# Conflict between the Class|Object attribute and local variable

new test { 
	myTest()
	sayHello("Ahmed")
	? @name
}


class test
	@name = "Ring"

	func myTest
		? @name

	func sayHello p1
		name = "Mr. " + p1
		? "Hello " + name
