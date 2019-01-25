/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

load "stdlib.ring"

aList = 1:10


aList2 = map(aList,func x {
			return x*x
})

? aList
? "====="
? aList2
