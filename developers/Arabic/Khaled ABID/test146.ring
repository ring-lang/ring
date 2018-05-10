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

# Conflict between global variable and class attribute

x=100

new point {
	self.x=10 y=20 ? self
}

class point 
	self.x self.y		# we expect x,y to be object attributes
