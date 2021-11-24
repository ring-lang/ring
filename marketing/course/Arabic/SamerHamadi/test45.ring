/*
**	Application    : functions
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

# Ring
# string | number ----> pass by value 
# list   | object ----> pass by reference

func main
	aList = 1:10
	test(aList)
	? aList

func test aList
	aList[1] = :one
