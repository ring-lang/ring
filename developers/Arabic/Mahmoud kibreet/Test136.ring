/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.02
*/

load "stdlib.ring"

/*
Reflection Metaprogramming
*/

mergemethods(:list,:mylist)

oList = new list([1,2,3])
oList.print()
? "Size :" + oList.size()
? "Size :" + oList.count()

class mylist 
	func count
	return Len(vValue)
