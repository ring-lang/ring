/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 06/05/2018
*/

load "stdlib.ring"

/*
	Reflection & Metaprogramming
*/

oList = new mylist([1,2,3])
oList.print()
? "Size : " + oList.size()
? "Size : " + oList.count()

class MyList from list
	func count 
		return len(vValue)
