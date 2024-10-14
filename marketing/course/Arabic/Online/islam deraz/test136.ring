/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.13
*/

load "stdlib.ring"
/*

	Reflection & Meta-programming

*/

mergemethods(:list,:mylist)
olist = new list( [1,2,3] )
olist.print()
? "Size: " + olist.size()
? "Size: " + olist.count()


class mylist 
	func count	
		return len(vValue)



