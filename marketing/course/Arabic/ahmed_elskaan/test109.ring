/*
**	Application Name : Scope;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-31;		
*/
# problem: conflict between local variables and class attribute


new test {
	myTest()
	test2("ahmed")
	? @name
}

class test
	@name = "mohamed"
	func myTest 
		? @name
	func test2 p1
		name = "Mr. " + p1
		? "Hello " + name
