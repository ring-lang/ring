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
	test(aList)
	? aList

func test aL
	aL[1] = "One"
