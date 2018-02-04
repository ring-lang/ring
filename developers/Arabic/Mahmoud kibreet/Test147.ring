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

# Conflict between the global varaible and clas attribute 

$x = 100

new point {
	x = 10 y =20 ? self
}


class point 
	x y		# we expect x,y to be object attributes
