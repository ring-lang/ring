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
	
	aList2 = aList     # copy by value

	aList[1] = "one"

	? aList[1]
	? aList2[1]
