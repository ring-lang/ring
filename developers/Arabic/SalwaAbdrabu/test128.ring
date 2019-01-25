/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

load "stdlib.ring"

aList = 1:10

map(aList,func x { ? x })

aList2 = filter(aList,func x {

		if x % 2 = 0
			return true
	else
		return false
	ok 
})

? "====="
? aList2
