###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           :01.02.2018                  
###################################

/*
	Variables Scope 

		Three Scopes 
			[1] ------Global Scope 
			[2]------ Object Scope 
			[3] ------Local Scope 

*/

/*	
	When we write the variable name 

		(Search) ----------> Found (Use) 

			Not Found 
		Assignment = ----> Define 
		class region -------> Define 
		Expression = -----> Error 
*/

/*
	Search for variables 

		[1] -----Search in the local scope 

		[2] -----Search in the object scope 
				Inside braces { }
				Inside method 
				Inside class region 
		[3]------ Search in the global scope 
*/


new person { test() }

class person 
	# ------undefined variables ---> new attributes 

	# ------We global scope 
	# ------We object scope (self.)
	# ------We have local scope is the same as object scope 

	mypoint = new point {	#----- braces change object scope 
		x=10 y=10
		salary = "xxxx"
		? self
	}

	name address phone 


	func test 
		              #------- we have global, object scope & local scope 

class point x y
