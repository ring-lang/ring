/*
**	Application		: Functions .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 07 .
*/

# Functions	-	Scope	-	Pass By Value	-	Pass By Reference
# Ring
# Number | String -----> Pass By Value
# List	 | Object	   -----> Pass By Reference

func main
	aList = 1:10
	aList_Copy = aList

	aList[1] = :one
	? aList[1]
	? aList_Copy[1]
