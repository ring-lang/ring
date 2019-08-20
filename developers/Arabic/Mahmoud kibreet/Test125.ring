/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.02
*/

func main 
	aList = 1:10
	? mypurefunction(aList)
	? aList


func mypurefunction  aList        # Deep Copy
	aList2 = aList
	aList2[1]  = "One"
	aList2[10] = "Ten"
	return aList2
