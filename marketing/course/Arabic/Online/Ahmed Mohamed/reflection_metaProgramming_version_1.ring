/*
	Application 	: Reflection And Meta Programming Version 1
	Author		: Ahmed Mohamed
	Date		: 2019/11/02
*/

load "stdlib.ring"

/*
	Reflection & Meta Programming
*/

oList = new myList( [1, 2, 3] )

oList.print()

? "Size : " + oList.size()
? "Size : " + oList.count()


class myList from list
	func count
		return len(vValue)
