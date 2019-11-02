/*
	Application 	: Reflection And Meta Programming Version 2
	Author		: Ahmed Mohamed
	Date		: 2019/11/02
*/

load "stdlib.ring"

/*
	Reflection & Meta Programming
*/

mergemethods("list", "myList")

oList = new List( [1, 2, 3] )

oList.print()

? "Size : " + oList.size()
? "Size : " + oList.count()


class myList
	func count
		return len(vValue)
