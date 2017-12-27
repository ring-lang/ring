/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.27
*/

func main
	aList = 1:10
	? mypurefunction(aList)
	? aList


func mypurefunction  aList 
	aList2 = aList		# Copy 
	aList2[1] = "one"
	aList2[10] = "ten"
	return aList2
