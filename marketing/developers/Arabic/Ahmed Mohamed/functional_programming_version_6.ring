/*
	Application	: Functional Programming Version 6
	Author		: Ahmed Mohamed
	Date		: 2019/11/1
*/

func main
	aList = 1:10
	? myPureFunction(aList)
	? aList

func myPureFunction aList
	aList2 = aList		# Deep Copy
	aList2[1] = "One"
	aList2[10] = "Ten"
	return aList2
