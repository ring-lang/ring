/*
**	Application	: Ring lessons - Functional Programming - Pure Functions.
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

func main
	aList = 1:10
	? myPureFunc(aList)
	? aList
func myPureFunc aList
	aList2 = aList			# Deep Copy
	aList2[1]   = "One"
	aList2[10] = "Ten"
	return aList2
