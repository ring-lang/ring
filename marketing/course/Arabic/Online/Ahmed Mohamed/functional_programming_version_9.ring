/*
	Application	: Functional Programming Version 9
	Author		: Ahmed Mohamed
	Date		: 2019/11/1
*/


load "stdlib.ring"

aList = 1:10

map(aList, func x {

	? x	
})

aList2 =  filter(aList, func x {

	if x % 2 = 0
		return true
	else
		return false
	ok	

})

? aList2
