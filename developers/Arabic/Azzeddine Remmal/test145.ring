###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 28.01.2018                  
###################################


/*
	Variables Scope 
		Three Scopes 
			[1] ------Global Scope 
			[2] ------Object Scope 
			[3] ------Local Scope 

*/

#----------- Conflict between the global variable and class attribute 

x = 100

new point {
	x=10 y=20 ? self
}


class point x y 			# ------We expect x,y to be object attributes 


