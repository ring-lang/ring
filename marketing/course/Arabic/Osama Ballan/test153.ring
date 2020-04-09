/*
**	Application	: Ring lessons - Scope .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 25 .
*/

/*
	When We Write The Variable Name .
		(Search) ----> Found ( Use ) .
			Not Found	
		Assignment = ----> Define
		Class Region  ----> Define
		Expression  = ----> Error
*/
/*
	Search For Variables
		[1] Search in The Local Scope .
		[2] Search in The Object Scope .
				Inside Braces {}
				Inside Method
				Inside Class Region
		[3] Search in The Global Scope
*/
new person { test() }
Class person
	name address phone
	Func test
		new point {
			x =10 y =20
			this.hello()
			? self
		}
	Func hello
		? "Hello"
Class point x y
