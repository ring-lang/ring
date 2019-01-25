/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

func main 

	aList = 1: 10 
	? myPureFunction(aList)
	? aList

func myPureFunction aList
	aList2     = aList	          # Deep copy
	aList2[1]  = "One"
	aList2[10] = "Ten"
	return aList2
