/*
**	Application Name : Functional programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/

func main 
	aList = 1:10
	? pureFunc(aList)
	? aList

func pureFunc aList
	aList2 = aList
	aList2[1] = "one"
	aList2[10] = "ten"
	return aList2
	
