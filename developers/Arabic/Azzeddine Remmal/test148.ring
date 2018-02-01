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

#------------- Conflict between the class|object attribute and local variable 

sayhello("Mahmoud")
new test { mytest() }


func sayhello p1
	name = "Mr. " + p1
	? "Hello " + name 


class test 
	name = "ring"

	func mytest 
		? name 
