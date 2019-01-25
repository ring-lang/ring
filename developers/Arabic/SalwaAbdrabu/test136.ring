/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

Load "stdlib.ring"

/*

		Reflection & Metaprogramming 

*/

mergemethods(:list,:myList)      # Or ("list","myList") 

oList = new List([1,2,3])
oList.print()

? "Size :" + oList.size()
? "Size :" + oList.Count()

class myList 

	func Count 
		return len(vValue)
