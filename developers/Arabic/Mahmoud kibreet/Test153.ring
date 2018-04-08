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

	name address phone

	func test
		new point {
			x = 10 y = 20
			this.hello()
			? self
		} 		

func hello
	? "Hello"

class point x y
