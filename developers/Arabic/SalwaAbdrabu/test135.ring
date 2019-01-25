/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

Load "stdlib.ring"

/*

		Reflection & Metaprogramming 

*/

oList = new myList([1,2,3])
oList.print()
? "Size :" + oList.size()
? "Size :" + oList.Count()

class myList from list

	func Count 
		return len(vValue)
