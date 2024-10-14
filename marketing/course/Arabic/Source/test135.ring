/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.27
*/

load "stdlib.ring"

/*
	Reflection & Metaprogramming
*/

oList = new mylist( [1,2,3] )
oList.print()
? "Size : " + oList.size()
? "Size : " + oList.count()

class mylist from list 
	func count 
		return len(vValue)
