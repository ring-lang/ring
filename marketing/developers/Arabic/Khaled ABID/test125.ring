/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 03/05/2018
*/

func main 
	aList = 1:10
	? myPureFunction(aList)
	? aList




func myPureFunction aList
	alist2 = alist		# Deep Copy
	aList2[1] = "one"
	aList2[10]= "ten"
	return alist2
