/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.27
*/

load "stdlib.ring"

/*
	Reflection & Metaprogramming
*/

mergemethods(:list,:mylist)

oList = new list( [1,2,3] )
oList.print()
? "Size : " + oList.size()
? "Size : " + oList.count()

class mylist 
	func count 
		return len(vValue)
