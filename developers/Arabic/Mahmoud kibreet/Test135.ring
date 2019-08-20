/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.02
*/

load "stdlib.ring"

/*
Reflection Metaprogramming
*/

oList = new mylist([1,2,3])
oList.print()
? "Size :" + oList.size()
? "Size :" + oList.count()

class mylist from list
	func count
	return Len(vValue)
