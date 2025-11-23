# Author: Ilir Liburn

/*
	Description by Fayed

	aList is a List
	aList2 is another copy of aList (i.e. different variable)

	After using Add(), ref(aList2)
	We have
	aList = [ 0  , reference to aList2, RC=2 ]

	Using aList2 = aList
	requires that aList content must be copied first 
	because in some case, a sub list could be assigned to it's parent

	The copy operation means 
	[ 0,  reference to aList2, RC=2 ] will becomes [ 0  , reference to aList2, RC=3 ]

	Assigning this to aList2, i.e. replacing old aList2 value,  means RC decrement

	So we have 
	aList2 = [ 0  , reference to aList2, RC=3-1=2 ]

	It's a circular reference now 

*/


aList = []

add(ref(aList),0)

aList2 = aList

count = 10

do

	add(ref(aList),ref(aList2))

	aList2 = aList

	? copy("*",20)
	? refcount(aList)
	? refcount(aList2)
	? refcount(aList[2])
	? refcount(aList2[2])
	? aList
again count--

? copy("*",20)
? aList
? copy("*",20)
? aList2
