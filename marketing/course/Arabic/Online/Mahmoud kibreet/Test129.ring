/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.02
*/

load "stdlib.ring"     

aList = 1:10

aList2 = map(aList,func x {
	return x * x
})

? aList
? aList2
