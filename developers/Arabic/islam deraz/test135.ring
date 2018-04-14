/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.13
*/

load "stdlib.ring"
/*

	Reflection & Metaprograming

*/

olist = new mylist( [1,2,3] )
olist.print()
? "Size: " + olist.size()
? "Size: " + olist.count()


class mylist from list
	func count	
		return len(vValue)



