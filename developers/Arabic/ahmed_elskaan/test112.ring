/*
**	Application Name : Scope;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-31;		
*/

? copy("hello ", 3)
new test {myTest()}
func copy str, nCount
	for t = 1 to nCount
		? str
	next
class test
	func myTest
		new local{
			copy("ahmed", 3)
		}
class local
