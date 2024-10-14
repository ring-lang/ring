/*
**	Application Name : class from stdlib;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/
load "stdlib.ring"
mergemethods(:list,:myList)
oList = new list([1,2,3,4])
? oList.print()
? "size : " + oList.count()
class myList
	func count
		return len(vValue)
