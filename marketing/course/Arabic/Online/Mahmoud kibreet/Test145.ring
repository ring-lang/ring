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

# Conflict between the global variable and class attribute 

x = 100

new point {
x = 10 y =20 ? self
}


class point 
	x y		# we expect x,y to be object attributes
