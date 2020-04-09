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

/*
	When are write the varaible name
		(Search)----> Found (Use)
			Not Found
		Assigment = ----> Define
		Class region ----> Define
		Expression = ---- Error
*/

/*
	Search for varaibles
		[1] Search in the local scope
		[2] Search in the object scope
				Inside brases {}
				Inside methods
				Inside class region
		[3] Search in the global scope 
*/


new person { test() }

class person 
	# undefined varsibles ---- > new attributes

	# we global scope
	# we object scope (self.)
	# we have local scope is the same as object scope

mypoint = new point { 	# brases change object scope
	x = 10 y = 10
	salary = "xxxxx"
	? self
} 
	name address phone
	func test
		# we have global, object scope & Local scope




class point x y
