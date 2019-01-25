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

# Conflict between the global variable and class attribute

x = 100

new point { 
		self.x = 10  self.y = 20 ? self }

class point 
	self.x self.y    # we expect x,y to be object attribute
