/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.27
*/

load "stdlib.ring" 

aList = 1:10

map(aList,func x {
	? x
})

aList2 = filter(aList,func x {
	if x % 2 = 0 
		return True
	else 
		return False
	ok
})

? aList2

