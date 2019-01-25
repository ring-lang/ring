/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

load "stdlib.ring"

aList = 1:10


test(value(aList))
? aList


func test aList
	for x = 1 to len(aList)
		aList[x] = aList[x] + 1
	next
	
