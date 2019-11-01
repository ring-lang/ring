/*
	Application	: Functional Programming Version 11
	Author		: Ahmed Mohamed
	Date		: 2019/11/1
*/

load "stdlib.ring"

aList = 1:10

test(value(aList))	

? aList

func test aList
	for x = 1 to len(aList)
		aList[x] += 1
	next

