/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.27
*/

load "stdlib.ring" 

aList = 1:10

aList2 = map(aList,func x {
	return x * x
})

? aList 
? aList2
