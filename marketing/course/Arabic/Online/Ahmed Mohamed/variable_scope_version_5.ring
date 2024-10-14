/*
	Application	: Variable Scope Version 5
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

# Conflict between the global variable and Class Attribute


x = 100

new point {
	x = 10
	y = 20
	? self
}
	
class point x y 	# We Expect x, y to be object attribute

