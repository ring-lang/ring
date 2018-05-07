/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 06/05/2018
*/

load "stdlib.ring"

/*
	Reflection & Metaprogramming
*/

mergemethods(:list,:mylist)

oList = new list([1,2,3])
oList.print()
? "Size : " + oList.size()
? "Size : " + oList.count()

class MyList
	func count 
		return len(vValue)
