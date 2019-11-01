/*
	Application	: Functional Programming Version 10
	Author		: Ahmed Mohamed
	Date		: 2019/11/1
*/


load "stdlib.ring"

aList = 1:10

aList2 = map(aList, func x {
	return x * x	
})


? aList
? aList2
