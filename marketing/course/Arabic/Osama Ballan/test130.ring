/*
**	Application	: Ring lessons - Functional Programming - value() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

load "stdlib.ring"

aList = 1:10

aListCopy = test(value(aList))

? aListCopy
? aList

func test aList
	for x = 1 to len(aList)
		aList[x] = aList[x] + 1
	next
	return aList
