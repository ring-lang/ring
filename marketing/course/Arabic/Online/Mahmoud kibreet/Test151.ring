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

/*
	When are write the variable name
		(Search)----> Found (Use)
			Not Found
		Assignment = ----> Define
		Expression = ---- Error
*/

/*
	Search for variables
		[1] Search in the local scope
		[2] Search in the object scope
		[3] Search in the global scope 
*/
x = 10		# we have the global scope
test()
new person { test() }

func test

		# we have global & local

class person 
	# undefined variables ---- > new attributes

	# we global scope
	# we object scope (self.)
	# we have local scope is the same as object scope

mypoint = new point { 	# braces change object scope
	salary = "xxxxx"
} 
	name address phone
	func test
		# we have global, object scope & Local scope




class point x y
